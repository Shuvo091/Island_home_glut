#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

#define PI 3.1415927

#include "func.h"
#include "BmpLoader.h"

void boundary()
{
    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\pavement.bmp", ID1);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glScalef(10,0.1,12);
    drawCube(1,1,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall2.bmp", ID1);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glScalef(0.2,2,12);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glScalef(10,2,0.2);
    drawCube(1,1,1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(20,0,0);
    glScalef(0.2,2,12);
    drawCube(1,1,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void house_skeleton()
{

    light_enable();

    glPushMatrix();

    glScalef(1.3,1.3,1.3);
    glTranslatef(-1,0,-3);


    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall3.bmp", ID1);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(5,0,18);
    glScalef(1,2,1);
    drawCube(1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall3.bmp", ID1);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(5,0,17);
    glScalef(2,2,1);
    drawCube(1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall3.bmp", ID1);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall3.bmp", ID1);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(5,0,14);
    glScalef(3,2,2);
    drawCube(1,1,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall3.bmp", ID1);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(5,0,13);
    glScalef(4,2,1);
    drawCube(1,1,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///--------------------------------------------wall shesh nich tolAY

    ///---- eita 1 tolar saad

    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\roof1.bmp", ID1);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(4.5,4,12.5);
    glScalef(4.5,0.2,2);
    drawCube(1,1,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\roof1.bmp", ID1);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(4.5,4,14.5);
    glScalef(2.5,0.2,3);
    drawCube(1,1,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\roof1.bmp", ID1);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(7,3.8,13.5);
    glScalef(2.5,0.17,3);
    drawCube(1,1,0);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall2.bmp", ID1);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(5,4,18.5);
    glScalef(1.5,2,0.5);
    drawCube(1,1,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,4,15.5);
    glScalef(1.5,2,1.5);
    drawCube(1,1,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8,4,15.5);
    glScalef(1,2,1);
    drawCube(0,1,1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(5,4,13);
    glScalef(3.75,2,1.25);
    drawCube(1,0,0);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    ///----------------------2nd tola shesh railing shuru

    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall3.bmp", ID1);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(5,8,13);
    glScalef(.1,1,3);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,8,13);
    glScalef(3.5,1,0.1);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,8,19);
    glScalef(1.5,1,0.1);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.8,8,17);
    glScalef(.1,1,1);
    drawCube(1,1,1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(7.8,8,17);
    glScalef(1,1,.1);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.6,8,15.3);
    glScalef(.1,1,.9);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.5,8,15);
    glScalef(1.4,1,.1);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(12,8,13.2);
    glScalef(.1,1,.9);
    drawCube(1,1,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall6.bmp", ID1);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(6,8,14);
    glScalef(1,2,1);
    drawCube(1,1,1);
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


        glPopMatrix();



}
