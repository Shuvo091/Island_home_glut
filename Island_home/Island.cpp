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

void sea()
{
    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\sea.bmp", ID1);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(50,2,50);
    glClearColor(0,0,0,1);
    drawCube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


}

void sky()
{
    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\sky.bmp", ID2);
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,100,50);
    glClearColor(0,0,0,1);
    drawCube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\sky.bmp", ID2);
     glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(50,100,1);
    glClearColor(0,0,0,1);
    drawCube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
     glPopMatrix();



}

void island_shape()
{

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0, 1, 0, 1.0 };
    GLfloat mat_diffuse[] = { 0, 1, 0, 1.0 };
    GLfloat mat_specular[] = {1,1,1, 1.0 };
    GLfloat mat_shininess[] = {60};
     if(amb)
    {
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);

    }
    else
    {
        glMaterialfv( GL_FRONT, GL_AMBIENT, no_mat);
    }

    if(dif)
    {
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);

    }
    else
    {
        glMaterialfv( GL_FRONT, GL_DIFFUSE, no_mat);
    }

    if(spec)
    {
        glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    }
    else
    {
        glMaterialfv( GL_FRONT, GL_SPECULAR, no_mat);
    }



    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);


    glPushMatrix();
    glRotatef(10,0,1,0);

    glBegin(GL_TRIANGLES);
        glVertex3f(20,0,20);
        glVertex3f(20,0,30);
        glVertex3f(30,0,30);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex3f(20,5,20);
        glVertex3f(20,5,30);
        glVertex3f(30,5,30);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(20,0,20);
        glVertex3f(20,0,30);
         glVertex3f(20,5,30);
        glVertex3f(20,5,20);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(20,0,20);
        glVertex3f(30,0,30);
         glVertex3f(30,5,30);
        glVertex3f(20,5,20);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(20,0,30);
        glVertex3f(30,0,30);
         glVertex3f(30,5,30);
        glVertex3f(20,5,30);
    glEnd();

    glPushMatrix();
    ///glTranslatef(15,0,8);
    ///glScalef(0.5,1,0.5);
    ///glRotatef(20,0,1,0);
    glBegin(GL_TRIANGLES);
        glVertex3f(24,0,30);
        glVertex3f(24,0,37);
        glVertex3f(30,0,37);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex3f(24,5,30);
        glVertex3f(24,5,37);
        glVertex3f(30,5,37);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(20,0,20);
        glVertex3f(20,0,30);
         glVertex3f(20,5,30);
        glVertex3f(20,5,20);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(20,0,20);
        glVertex3f(30,0,30);
         glVertex3f(30,5,30);
        glVertex3f(20,5,20);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(20,0,30);
        glVertex3f(30,0,30);
         glVertex3f(30,5,30);
        glVertex3f(20,5,30);
    glEnd();

    glPopMatrix();
    glPopMatrix();


}
