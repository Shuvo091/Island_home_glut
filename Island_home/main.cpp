#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include "func.h"


#define PI 3.1415927


double Txval=0,Tyval=0,Tzval=0;
double windowHeight=1500, windowWidth=750;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = 1, uRotate = false;
bool light1= false, light2 = true, light3 =false;
bool amb =true, dif = true, spec = true;
bool l_amb=true,l_dif=true, l_spec = true;
float eyeX =70,eyeY=20,eyeZ=50, lookX=0,lookY=0,lookZ=0;


///float eyeX =6,eyeY=5,eyeZ=7, lookX=2,lookY=4,lookZ=1;





void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(60,1,5,100);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, windowHeight, windowWidth);



    ///Living room objects  here
    /**
    drawFloor();
    ceilingNwall();
    drawBox1();
    drawBox2();
    drawPicFrame1();
    drawPicFrame2();
    drawAC();
    drawBed();
    drawBox3();
    window();
    window2();
    //fanparts();

    glPushMatrix();
    glTranslatef(-2, 4,-3);
    drawSphere(1,1,0);
    glPopMatrix();
    fan();
    glPopMatrix();
    **/

    sea();
    sky();

    glFlush();
    glutSwapBuffers();
}




int main (int argc, char **argv)
{

    printf("---------------------------------------------------------------------------\n");
    printf("1. Navigate Camera angles(view-point)  : i = up, k = down, j = right, l = left\n");
    printf("2. Navigate Camera position(eye-point) : w = up, s = down, d = right, a = left\n");
    printf("3. Zoom                               : q = zoom out, e = zoom in\n");
    printf("4. Fan rotate toggle                  : z = anti-clockwise, x = clockwise\n");
    printf("5. Light on/off toggle                : 1 = Spotlight, 2 = light 1, 3 = light 2\n");
    printf("6. Light material properties toggle   : b = Ambient, n = diffuse, m = specular\n");
    printf("7. Light properties toggle            : 4 = Ambient, 5 = diffuse, 6 = specular\n");

    printf("---------------------------------------------------------------------------\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Island Home");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);


    glEnable(GL_LIGHTING);
    light();

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}






