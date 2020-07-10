#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void size(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);


float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void awal()
{
       glLoadIdentity();
       gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
       glRotatef(xrot, 1.0f,0.0f, 0.0f);
       glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}


void init(void)
{
   glClearColor(135/255.0f, 206/255.0f, 250/255.0f,0/255.0f);
   glMatrixMode(GL_PROJECTION);
   glEnable(GL_DEPTH_TEST);
   is_depth=1;
   glMatrixMode(GL_MODELVIEW);
   glPointSize(9.0);
   glLineWidth(5.0);
}


   void tampil(void)
{
        if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        else
        glClear(GL_COLOR_BUFFER_BIT);

        //ALAS HALAMAN
    //halaman
    glBegin(GL_QUADS);
    glColor3f(63/255.0f, 255/255.0f, 128/255.0f);
    glVertex3f(-120,-30.5,60);
    glVertex3f(-120,-30.5,-150);
    glVertex3f(120,-30.5,-150);
    glVertex3f(120,-30.5,60);
    glEnd();

        //RUMAH
    //ALAS rumah
    glBegin(GL_QUADS);
    glColor3f(128/255.0f, 4/255.0f, 0/255.0f);
    glVertex3f(-80,-29.5,10);
    glVertex3f(-80,-29.5,-101);
    glVertex3f(20,-29.5,-101);
    glVertex3f(20,-29.5,10);
    glEnd();
    //tembok depan
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(-78,-29,-30);
    glVertex3f(18,-29,-30);
    glVertex3f(18,40,-30);
    glVertex3f(-78,40,-30);
    glEnd();
    //tembok belakang
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(-78,-29,-98);
    glVertex3f(18,-29,-98);
    glVertex3f(18,40,-98);
    glVertex3f(-78,40,-98);
    glEnd();
    //tembok kanan
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(18,-29,-98);
    glVertex3f(18,-29,-30);
    glVertex3f(18,40,-30);
    glVertex3f(18,40,-98);
    glEnd();
    //tembok kiri
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(-78,-29,-98);
    glVertex3f(-78,-29,-30);
    glVertex3f(-78,40,-30);
    glVertex3f(-78,40,-98);
    glEnd();


        //INTERNIT DAN ATAP
    //INTERNIT rumah
    glBegin(GL_QUADS);
    glColor3f(128/255.0f, 128/255.0f, 128/255.0f);
    glVertex3f(-80,40,10);
    glVertex3f(-80,40,-100);
    glVertex3f(20,40,-100);
    glVertex3f(20,40,10);
    glEnd();
    // LIST INTERNIT rumah
    glBegin(GL_LINE_LOOP);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-80,40,10);
    glVertex3f(-80,40,-100);
    glVertex3f(20,40,-100);
    glVertex3f(20,40,10);
    glEnd();
    //ATAP rumah DEPAN
    glBegin(GL_POLYGON);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(-80,40,10);
    glVertex3f(-30,80,10);
    glVertex3f(20,40,10);
    glEnd();
    // LIST ATAP DEPAN
    glBegin(GL_LINES);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-80,40,10);
    glVertex3f(20,40,10);
    glEnd();
    //ATAP rumah BELAKANG
    glBegin(GL_POLYGON);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(-80,40,-100);
    glVertex3f(-30,80,-100);
    glVertex3f(20,40,-100);
    glEnd();
    // LIST ATAP BELAKANG
    glBegin(GL_LINES);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-80,40,-100);
    glVertex3f(20,40,-100);
    glEnd();
    //ATAP rumah kanan
    glBegin(GL_QUADS);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-30,80,12);
    glVertex3f(20,40,12);
    glVertex3f(20,40,-107);
    glVertex3f(-30,80,-107);
    glEnd();
    //ATAP rumah kiri
    glBegin(GL_QUADS);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-30,80,12);
    glVertex3f(-80,40,12);
    glVertex3f(-80,40,-107);
    glVertex3f(-30,80,-107);
    glEnd();
    //ATAP list
    glBegin(GL_LINE_LOOP);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(20,40,12);
    glVertex3f(20,40,-107);
    glVertex3f(-30,80,-107);
    glVertex3f(-80,40,-107);
    glVertex3f(-80,40,12);
    glVertex3f(-30,80,12);
    glEnd();

        //GARASI
    //dasar garasi
    glBegin(GL_QUADS);
    glColor3f(128/255.0f, 4/255.0f, 0/255.0f);
    glVertex3f(20.5,-29,30);
    glVertex3f(20.5,-29,-101);
    glVertex3f(81.5,-29,-101);
    glVertex3f(81.5,-29,30);
    glEnd();
    //tembok kanan garasi
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(76.5,-29,-38);
    glVertex3f(76.5,-29,-100);
    glVertex3f(76.5,40,-100);
    glVertex3f(76.5,40,-38);
    glEnd();
    //tembok kiri garasi
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(23.5,-29,-38);
    glVertex3f(23.5,-29,-100);
    glVertex3f(23.5,40,-100);
    glVertex3f(23.5,40,-38);
    glEnd();
    //tembok belakang garasi
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(23.5,-29,-100);
    glVertex3f(76.5,-29,-100);
    glVertex3f(76.5,40,-100);
    glVertex3f(23.5,40,-100);
    glEnd();
     //ATAP garasi
    glBegin(GL_QUADS);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(20.5,40,-25);
    glVertex3f(20.5,40,-105);
    glVertex3f(85.5,40,-105);
    glVertex3f(85.5,40,-25);
    glEnd();
    //LIST ATAP GARASI
    glBegin(GL_LINE_LOOP);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(20.5,40,-25);
    glVertex3f(20.5,40,-105);
    glVertex3f(85.5,40,-105);
    glVertex3f(85.5,40,-25);
    glEnd();

        //OBJECT BENDA

        // LAMPU RUMAH
    //DASAR LAMPU ATAS
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 245/255.0f, 238/255.0f);
    glVertex3f(-32,39.5,-45);
    glVertex3f(-32,39.5,-90);
    glVertex3f(-28,39.5,-90);
    glVertex3f(-28,39.5,-45);
    glEnd();
    //LIST LAMPU ATAS
    glBegin(GL_LINE_LOOP);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(-32,39.5,-45);
    glVertex3f(-32,39.5,-90);
    glVertex3f(-28,39.5,-90);
    glVertex3f(-28,39.5,-45);
    glEnd();
         // LAMPU GARASI
     glBegin(GL_QUADS);
    glColor3f(255/255.0f, 245/255.0f, 238/255.0f);
    glVertex3f(46.5,39,-35);
    glVertex3f(46.5,39,-95);
    glVertex3f(50.5,39,-95);
    glVertex3f(50.5,39,-35);
    glEnd();
    //LIST LAMPU ATAS
    glBegin(GL_LINE_LOOP);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(46.5,39,-35);
    glVertex3f(46.5,39,-95);
    glVertex3f(50.5,39,-95);
    glVertex3f(50.5,39,-35);
    glEnd();
        //KESET
    //KESET
    glBegin(GL_QUADS);
    glColor3f(252/255.0f, 192/255.0f, 203/255.0f);
    glVertex3f(-60,-29,-33.5);
    glVertex3f(-60,-29,-48.5);
    glVertex3f(0,-29,-48.5);
    glVertex3f(0,-29,-33.5);
    glEnd();
    //LIST KESET
    glBegin(GL_LINE_LOOP);
    glColor3f(219/255.0f, 112/255.0f, 147/255.0f);
    glVertex3f(-60,-29,-33.5);
    glVertex3f(-60,-29,-48.5);
    glVertex3f(0,-29,-48.5);
    glVertex3f(0,-29,-33.5);
    glEnd();

        // PINTU RUMAH
    //DASAR PINTU BLKNG TEMBOK DEPAN
    glBegin(GL_QUADS);
    glColor3f(160/255.0f, 82/255.0f, 45/255.0f);
    glVertex3f(-60,-29,-30.5);
    glVertex3f(0,-29,-30.5);
    glVertex3f(0,20,-30.5);
    glVertex3f(-60,20,-30.5);
    glEnd();
    //GAGANG PINTU BLKNG
    glBegin(GL_LINES);
    glColor3f(139/255.0f, 69/255.0f, 19/255.0f);
    glVertex3f(-30,-20,-31);
    glVertex3f(-30,11,-31);
    glEnd();
    //DASAR PINTU DEPAN
    glBegin(GL_QUADS);
    glColor3f(160/255.0f, 82/255.0f, 45/255.0f);
    glVertex3f(-60,-29,-29.5);
    glVertex3f(0,-29,-29.5);
    glVertex3f(0,20,-29.5);
    glVertex3f(-60,20,-29.5);
    glEnd();
    //GAGANG PINTU DEPAN
    glBegin(GL_LINES);
    glColor3f(139/255.0f, 69/255.0f, 19/255.0f);
    glVertex3f(-30,-20,-29);
    glVertex3f(-30,11,-29);
    glEnd();
    //DASAR PINTU ATAS
    glBegin(GL_QUADS);
    glColor3f(139/255.0f, 69/255.0f, 19/255.0f);
    glVertex3f(-60,20,-32.5);
    glVertex3f(-60,20,-27.5);
    glVertex3f(0,20,-27.5);
    glVertex3f(0,20,-32.5);
    glEnd();
    //DASAR PINTU BAWAH
    glBegin(GL_QUADS);
    glColor3f(139/255.0f, 69/255.0f, 19/255.0f);
    glVertex3f(-60,-29,-32.5);
    glVertex3f(-60,-29,-27.5);
    glVertex3f(0,-29,-27.5);
    glVertex3f(0,-29,-32.5);
    glEnd();
    //DASAR PINTU KANAN
    glBegin(GL_QUADS);
    glColor3f(139/255.0f, 69/255.0f, 19/255.0f);
    glVertex3f(0,-29,-27.5);
    glVertex3f(0,-29,-32.5);
    glVertex3f(0,20,-32.5);
    glVertex3f(0,20,-27.5);
    glEnd();
    //DASAR PINTU KIRI
    glBegin(GL_QUADS);
    glColor3f(139/255.0f, 69/255.0f, 19/255.0f);
    glVertex3f(-60,-29,-27.5);
    glVertex3f(-60,-29,-32.5);
    glVertex3f(-60,20,-32.5);
    glVertex3f(-60,20,-27.5);
    glEnd();

        //AC
    //DASAR BAWAH AC
    glBegin(GL_QUADS);
    glColor3f(220/255.0f, 220/255.0f, 220/255.0f);
    glVertex3f(-45,25,-97.5);
    glVertex3f(-18,25,-97.5);
    glVertex3f(-18,25,-92.5);
    glVertex3f(-45,25,-92.5);
    glEnd();
    //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-45,25,-97.5);
    glVertex3f(-18,25,-97.5);
    glVertex3f(-18,25,-92.5);
    glVertex3f(-45,25,-92.5);
    glEnd();
    //DASAR ATAS AC
    glBegin(GL_QUADS);
    glColor3f(220/255.0f, 220/255.0f, 220/255.0f);
    glVertex3f(-45,35,-97.5);
    glVertex3f(-18,35,-97.5);
    glVertex3f(-18,35,-92.5);
    glVertex3f(-45,35,-92.5);
    glEnd();
     //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-45,35,-97.5);
    glVertex3f(-18,35,-97.5);
    glVertex3f(-18,35,-92.5);
    glVertex3f(-45,35,-92.5);
    glEnd();
    // DASAR BELAKANG AC
    glBegin(GL_QUADS);
    glColor3f(220/255.0f, 220/255.0f, 220/255.0f);
    glVertex3f(-45,35,-97.5);
    glVertex3f(-18,35,-97.5);
    glVertex3f(-18,25,-97.5);
    glVertex3f(-45,25,-97.5);
    glEnd();
    // DASAR DEPAN AC
    glBegin(GL_QUADS);
    glColor3f(220/255.0f, 220/255.0f, 220/255.0f);
    glVertex3f(-45,35,-92.5);
    glVertex3f(-18,35,-92.5);
    glVertex3f(-18,25,-92.5);
    glVertex3f(-45,25,-92.5);
    glEnd();
    // GARIS AC
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-40,30,-92);
    glVertex3f(-23,30,-92);
    glEnd();
    // DASAR KANAN AC
    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-18,35,-97.5);
    glVertex3f(-18,35,-92.5);
    glVertex3f(-18,25,-92.5);
    glVertex3f(-18,25,-97.5);
    glEnd();
    // DASAR KIRI AC
    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-45,35,-97.5);
    glVertex3f(-45,35,-92.5);
    glVertex3f(-45,25,-92.5);
    glVertex3f(-45,25,-97.5);
    glEnd();
        //LEMARI TV
    //DASAR BAWAH LEMARI TV
    glBegin(GL_QUADS);
    glColor3f(210/255.0f, 180/255.0f, 140/255.0f);
    glVertex3f(7.5,-29.5,-95);
    glVertex3f(17.5,-29.5,-95);
    glVertex3f(17.5,-29.5,-35);
    glVertex3f(7.5,-29.5,-35);
    glEnd();
    //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(7.5,-29.5,-95);
    glVertex3f(17.5,-29.5,-95);
    glVertex3f(17.5,-29.5,-35);
    glVertex3f(7.5,-29.5,-35);
    glEnd();
    //DASAR ATAS LEMARI TV
    glBegin(GL_QUADS);
    glColor3f(210/255.0f, 180/255.0f, 140/255.0f);
    glVertex3f(7.5,-2,-95);
    glVertex3f(17.5,-2,-95);
    glVertex3f(17.5,-2,-35);
    glVertex3f(7.5,-2,-35);
    glEnd();
    //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(7.5,-2,-95);
    glVertex3f(17.5,-2,-95);
    glVertex3f(17.5,-2,-35);
    glVertex3f(7.5,-2,-35);
    glEnd();
    //DASAR KANAN LEMARI TV
    glBegin(GL_QUADS);
    glColor3f(245/255.0f, 222/255.0f, 179/255.0f);
    glVertex3f(17.5,-29.5,-95);
    glVertex3f(17.5,-29.5,-35);
    glVertex3f(17.5,-2,-35);
    glVertex3f(17.5,-2,-95);
    glEnd();
    //DASAR KIRI LEMARI TV
    glBegin(GL_QUADS);
    glColor3f(245/255.0f, 222/255.0f, 179/255.0f);
    glVertex3f(7.5,-29.5,-95);
    glVertex3f(7.5,-29.5,-35);
    glVertex3f(7.5,-2,-35);
    glVertex3f(7.5,-2,-95);
    glEnd();
    //DASAR SAMPING KIRI LEMARI TV
    glBegin(GL_QUADS);
    glColor3f(210/255.0f, 180/255.0f, 140/255.0f);
    glVertex3f(7.5,-2,-95);
    glVertex3f(17.5,-2,-95);
    glVertex3f(17.5,-29.5,-95);
    glVertex3f(7.5,-29.5,-95);
    glEnd();
    //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(7.5,-2,-95);
    glVertex3f(17.5,-2,-95);
    glVertex3f(17.5,-29.5,-95);
    glVertex3f(7.5,-29.5,-95);
    glEnd();
    //DASAR SAMPING KANAN LEMARI TV
    glBegin(GL_QUADS);
    glColor3f(210/255.0f, 180/255.0f, 140/255.0f);
    glVertex3f(7.5,-2,-35);
    glVertex3f(17.5,-2,-35);
    glVertex3f(17.5,-29.5,-35);
    glVertex3f(7.5,-29.5,-35);
    glEnd();
    //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(7.5,-2,-35);
    glVertex3f(17.5,-2,-35);
    glVertex3f(17.5,-29.5,-35);
    glVertex3f(7.5,-29.5,-35);
    glEnd();
        //TV LED
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(17.5,30,-90);
    glVertex3f(17.5,0,-90);
    glVertex3f(17.5,0,-40);
    glVertex3f(17.5,30,-40);
    glEnd();
    // LIST TV LED
    glBegin(GL_LINE_LOOP);
    glColor3f(119/255.0f, 136/255.0f, 153/255.0f);
    glVertex3f(17.5,30,-90);
    glVertex3f(17.5,0,-90);
    glVertex3f(17.5,0,-40);
    glVertex3f(17.5,30,-40);
    glEnd();
    //TV LED LAYAR
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 245/255.0f, 238/255.0f);
    glVertex3f(17,25,-85);
    glVertex3f(17,5,-85);
    glVertex3f(17,5,-45);
    glVertex3f(17,25,-45);
    glEnd();

        //KOLAM
    //kolam ikan
    glBegin(GL_QUADS);
    glColor3f(0, 255, 254);
    glVertex3f(-60,-29,-110);
    glVertex3f(-60,-29,-140);
    glVertex3f(0,-29,-140);
    glVertex3f(0,-29,-110);
    glEnd();
    // list kolam ikan
    glBegin(GL_LINE_LOOP);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(-60,-29,-110);
    glVertex3f(-60,-29,-140);
    glVertex3f(0,-29,-140);
    glVertex3f(0,-29,-110);
    glEnd();

        //JENDELA RUMAH
    //JENDELA TEMBOK BELAKANG
    //JENDELA BELAKANG KIRI
    //DASAR JENDELA BLKNG
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(-70,-10,-98.5);
    glVertex3f(-50,-10,-98.5);
    glVertex3f(-50,20,-98.5);
    glVertex3f(-70,20,-98.5);
    glEnd();
    //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-70,-10,-98.5);
    glVertex3f(-50,-10,-98.5);
    glVertex3f(-50,20,-98.5);
    glVertex3f(-70,20,-98.5);
    glEnd();
    //DASAR JENDELA DEPAN
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(-70,-10,-97.5);
    glVertex3f(-50,-10,-97.5);
    glVertex3f(-50,20,-97.5);
    glVertex3f(-70,20,-97.5);
    glEnd();
    //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-70,-10,-97.5);
    glVertex3f(-50,-10,-97.5);
    glVertex3f(-50,20,-97.5);
    glVertex3f(-70,20,-97.5);
    glEnd();
    //JENDELA BELAKANG KANAN
    //DASAR JENDELA BELAKANG
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(-10,-10,-98.5);
    glVertex3f(10,-10,-98.5);
    glVertex3f(10,20,-98.5);
    glVertex3f(-10,20,-98.5);
    glEnd();
    //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-10,-10,-98.5);
    glVertex3f(10,-10,-98.5);
    glVertex3f(10,20,-98.5);
    glVertex3f(-10,20,-98.5);
    glEnd();
    //DASAR JENDELA DEPAN
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(-10,-10,-97.5);
    glVertex3f(10,-10,-97.5);
    glVertex3f(10,20,-97.5);
    glVertex3f(-10,20,-97.5);
    glEnd();
    //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-10,-10,-97.5);
    glVertex3f(10,-10,-97.5);
    glVertex3f(10,20,-97.5);
    glVertex3f(-10,20,-97.5);
    glEnd();

        // JENDELA TEMBOK KIRI RUMAH
    //JENDELA KIRI
    //DASAR JENDELA DEPAN
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(-78.5,-10,-90);
    glVertex3f(-78.5,-10,-40);
    glVertex3f(-78.5,20,-40);
    glVertex3f(-78.5,20,-90);
    glEnd();
    //LIST JENDELA SILANG ATAS
    glBegin(GL_LINES);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-78.5,-10,-65);
    glVertex3f(-78.5,20,-65);
    glEnd();
    //DASAR JENDELA BLKNG
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(-77.5,-10,-90);
    glVertex3f(-77.5,-10,-40);
    glVertex3f(-77.5,20,-40);
    glVertex3f(-77.5,20,-90);
    glEnd();
     //LIST JENDELA BLKNG
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-77.5,-10,-90);
    glVertex3f(-77.5,-10,-40);
    glVertex3f(-77.5,20,-40);
    glVertex3f(-77.5,20,-90);
    glEnd();
     //LIST JENDELA SILANG ATAS BELAKANG
    glBegin(GL_LINES);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-77.5,-10,-65);
    glVertex3f(-77.5,20,-65);
    glEnd();
    //LIST JENDELA DEPAN
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-78.5,-10,-90);
    glVertex3f(-78.5,-10,-40);
    glVertex3f(-78.5,20,-40);
    glVertex3f(-78.5,20,-90);
    glEnd();

        //JENDELA GARASI
    //JENDELA KANAN
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(77,0,-48);
    glVertex3f(77,0,-90);
    glVertex3f(77,20,-90);
    glVertex3f(77,20,-48);
    glEnd();
    // LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(77,0,-48);
    glVertex3f(77,0,-90);
    glVertex3f(77,20,-90);
    glVertex3f(77,20,-48);
    glEnd();
    //LIST TENGAH
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(77,0,-70);
    glVertex3f(77,20,-70);
    glEnd();

    //JENDELA KIRI
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(76,0,-48);
    glVertex3f(76,0,-90);
    glVertex3f(76,20,-90);
    glVertex3f(76,20,-48);
    glEnd();
    //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(76,0,-48);
    glVertex3f(76,0,-90);
    glVertex3f(76,20,-90);
    glVertex3f(76,20,-48);
    glEnd();
    //LIST TENGAH
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(76,0,-70);
    glVertex3f(76,20,-70);
    glEnd();
    //JENDELA BELAKANG GARASI
    //JENDELA DEPAN
    glBegin(GL_QUADS);
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(30,0,-99.5);
    glVertex3f(70,0,-99.5);
    glVertex3f(70,20,-99.5);
    glVertex3f(30,20,-99.5);
    glEnd();
    //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(30,0,-99.5);
    glVertex3f(70,0,-99.5);
    glVertex3f(70,20,-99.5);
    glVertex3f(30,20,-99.5);
    glEnd();
    //JENDELA BELAKANG
    glBegin(GL_QUADS);
    glColor3f(224/255.0f, 255/255.0f, 255/255.0f);
    glVertex3f(30,0,-100.5);
    glVertex3f(70,0,-100.5);
    glVertex3f(70,20,-100.5);
    glVertex3f(30,20,-100.5);
    glEnd();
      //LIST
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
   glVertex3f(30,0,-100.5);
    glVertex3f(70,0,-100.5);
    glVertex3f(70,20,-100.5);
    glVertex3f(30,20,-100.5);
    glEnd();


        //PILAR RUMAH
    //dasar pilar rumah kiri(KIRI)
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(-78,-29,-5);
    glVertex3f(-78,-29,5);
    glVertex3f(-78,40,5);
    glVertex3f(-78,40,-5);
    glEnd();
    // dasar pilar rumah kanan
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(-70,-29,-5);
    glVertex3f(-70,-29,5);
    glVertex3f(-70,40,5);
    glVertex3f(-70,40,-5);
    glEnd();
    // dasar pilar rumah atas
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(-78,-29,-5);
    glVertex3f(-70,-29,-5);
    glVertex3f(-70,40,-5);
    glVertex3f(-78,40,-5);
    glEnd();
    // dasar pilar rumah bawah
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(-78,-29,5);
    glVertex3f(-70,-29,5);
    glVertex3f(-70,40,5);
    glVertex3f(-78,40,5);
    glEnd();
    //dasar pilar rumah kiri(KIRI) LUAR
    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-78.5,-29,-5.5);
    glVertex3f(-78.5,-29,5.5);
    glVertex3f(-78.5,0,5.5);
    glVertex3f(-78.5,0,-5.5);
    glEnd();
    // dasar pilar rumah kanan LUAR
    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(-69.5,-29,-5.5);
    glVertex3f(-69.5,-29,5.5);
    glVertex3f(-69.5,0,5.5);
    glVertex3f(-69.5,0,-5.5);
    glEnd();
    // dasar pilar rumah atas LUAR
    glBegin(GL_QUADS);
    glColor3f(128/255.0f, 128/255.0f, 128/255.0f);
    glVertex3f(-78.5,-29,-5.5);
    glVertex3f(-69.5,-29,-5.5);
    glVertex3f(-69.5,0,-5.5);
    glVertex3f(-78.5,0,-5.5);
    glEnd();
     // dasar pilar rumah bawah LUAR
    glBegin(GL_QUADS);
    glColor3f(128/255.0f, 128/255.0f, 128/255.0f);
    glVertex3f(-78.5,-29,5.5);
    glVertex3f(-69.5,-29,5.5);
    glVertex3f(-69.5,0,5.5);
    glVertex3f(-78.5,0,5.5);
    glEnd();

    //PILAR RUMAH
    //dasar pilar rumah kanan(KANAN)
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(18,-29,-5);
    glVertex3f(18,-29,5);
    glVertex3f(18,40,5);
    glVertex3f(18,40,-5);
    glEnd();
    //dasar pilar rumah kiri
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(10,-29,-5);
    glVertex3f(10,-29,5);
    glVertex3f(10,40,5);
    glVertex3f(10,40,-5);
    glEnd();
    // dasar pilar rumah atas
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(10,-29,5);
    glVertex3f(18,-29,5);
    glVertex3f(18,40,5);
    glVertex3f(10,40,5);
    glEnd();
    // dasar pilar rumah bawah
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(10,-29,-5);
    glVertex3f(18,-29,-5);
    glVertex3f(18,40,-5);
    glVertex3f(10,40,-5);
    glEnd();
    //dasar pilar rumah kanan(KANAN) LUAR
    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(18.5,-29,-5.5);
    glVertex3f(18.5,-29,5.5);
    glVertex3f(18.5,0,5.5);
    glVertex3f(18.5,0,-5.5);
    glEnd();
    //dasar pilar rumah kiri LUAR
    glBegin(GL_QUADS);
    glColor3f(105/255.0f, 105/255.0f, 105/255.0f);
    glVertex3f(9.5,-29,-5.5);
    glVertex3f(9.5,-29,5.5);
    glVertex3f(9.5,0,5.5);
    glVertex3f(9.5,0,-5.5);
    glEnd();
    // dasar pilar rumah atas LUAR
    glBegin(GL_QUADS);
    glColor3f(128/255.0f, 128/255.0f, 128/255.0f);
    glVertex3f(9.5,-29,5.5);
    glVertex3f(18.5,-29,5.5);
    glVertex3f(18.5,0,5.5);
    glVertex3f(9.5,0,5.5);
    glEnd();
    // dasar pilar rumah bawah LUAR
    glBegin(GL_QUADS);
    glColor3f(128/255.0f, 128/255.0f, 128/255.0f);
    glVertex3f(9.5,-29,-5.5);
    glVertex3f(18.5,-29,-5.5);
    glVertex3f(18.5,0,-5.5);
    glVertex3f(9.5,0,-5.5);
    glEnd();

    //list pondasi dasar
    glBegin(GL_LINE_LOOP);
    glColor3f(112/255.0f, 128/255.0f, 145/255.0f);
    glVertex3f(-80,-29,10);
    glVertex3f(-80,-29,-100);
    glVertex3f(20,-29,-100);
    glVertex3f(20,-29,10);
    glEnd();

        // PILAR GARASI
    //dasar pilar kiri(KIRI) GARASI
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(18.5,-29,-30);
    glVertex3f(18.5,-29,-38);
    glVertex3f(18.5,40,-38);
    glVertex3f(18.5,40,-30);
    glEnd();
    //dasar pilar kanan garasi
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(23.5,-29,-30);
    glVertex3f(23.5,-29,-38);
    glVertex3f(23.5,40,-38);
    glVertex3f(23.5,40,-30);
    glEnd();
    //dasar pilar  atas garasi
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(18.5,-29,-38);
    glVertex3f(23.5,-29,-38);
    glVertex3f(23.5,40,-38);
    glVertex3f(18.5,40,-38);
    glEnd();
    //dasar pilar  bawah garasi
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(18.5,-29,-30);
    glVertex3f(23.5,-29,-30);
    glVertex3f(23.5,40,-30);
    glVertex3f(18.5,40,-30);
    glEnd();
        //dasar pilar kiri(KIRI) GARASI
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(18.5,-29,-92);
    glVertex3f(18.5,-29,-100);
    glVertex3f(18.5,40,-100);
    glVertex3f(18.5,40,-92);
    glEnd();
    //dasar pilar kanan garasi
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(23.5,-29,-92);
    glVertex3f(23.5,-29,-100);
    glVertex3f(23.5,40,-100);
    glVertex3f(23.5,40,-92);
    glEnd();
    //dasar pilar  atas garasi
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(18.5,-29,-100);
    glVertex3f(23.5,-29,-100);
    glVertex3f(23.5,40,-100);
    glVertex3f(18.5,40,-100);
    glEnd();
    //dasar pilar  bawah garasi
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(18.5,-29,-92);
    glVertex3f(23.5,-29,-92);
    glVertex3f(23.5,40,-92);
    glVertex3f(18.5,40,-92);
    glEnd();
    //dasar pilar kanan(KANAN) GARASI
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(81.5,-29,-30);
    glVertex3f(81.5,-29,-38);
    glVertex3f(81.5,40,-38);
    glVertex3f(81.5,40,-30);
    glEnd();
    //dasar pilar kiri GARASI
    glBegin(GL_QUADS);
    glColor3f(192/255.0f, 192/255.0f, 192/255.0f);
    glVertex3f(76.5,-29,-30);
    glVertex3f(76.5,-29,-38);
    glVertex3f(76.5,40,-38);
    glVertex3f(76.5,40,-30);
    glEnd();
    //dasar pilar  atas garasi
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(81.5,-29,-38);
    glVertex3f(76.5,-29,-38);
    glVertex3f(76.5,40,-38);
    glVertex3f(81.5,40,-38);
    glEnd();
    //dasar pilar bawah garasi
    glBegin(GL_QUADS);
    glColor3f(255/255.0f, 255/255.0f, 224/255.0f);
    glVertex3f(81.5,-29,-30);
    glVertex3f(76.5,-29,-30);
    glVertex3f(76.5,40,-30);
    glVertex3f(81.5,40,-30);
    glEnd();



    glPopMatrix();
    glutSwapBuffers();
    }

    void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    awal();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void size(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi =1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, lebar / tinggi, 5, 500);
    glTranslated(0, 0, -200);
    glMatrixMode(GL_MODELVIEW);

}

void keyboard(unsigned char key, int x, int y)
{

    switch(key)
    {
        case 'w':
        case 'W':
            glTranslated(0,0,3);
            break;
        case 'a':
        case 'A':
            glTranslated(3,0,0);
            break;
        case 's':
        case 'S':
            glTranslated(0,0,-3);
            break;
        case 'd':
        case 'D':
            glTranslated(-3,0,0);
            break;
        case '6':
            glTranslated(0,3,0);
            break;
        case '7':
            glTranslated(0,-3,0);
            break;
        case '1':
            glRotated(2,1,0,0);
            break;
        case '2':
            glRotated(-2,1,0,0);
            break;
        case '8':
            glRotated(1,0,1,0);
            break;
        case '9':
            glRotated(-1,0,1,0);
            break;
        case '3':
            glRotated(2,0,0,1);
            break;
        case '4':
            glRotated(-2,0,0,1);
            break;
        case '5':
            if (is_depth)
            {
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    tampil();
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(250, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("PITER WIJAYA - 672018109");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(size);
    glutMainLoop();
    return 0;
}
