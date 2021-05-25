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
    glScalef(1,80,40);
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
    glScalef(40,80,1);
    glClearColor(0,0,0,1);
    drawCube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



}

void island_shape()
{



    glPushMatrix();
    LoadTexture_surface("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\grass.bmp", ID);


    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
    GLfloat mat_specular[] = {1,0,1, 1.0 };
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

    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(20,0,5);


    //glRotatef(90,0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(30,5,30);
    glTexCoord2f(1,1);

    glVertex3f(20,5,35);
    glTexCoord2f(1,0);

    glVertex3f(0,5,40);
    glTexCoord2f(0,0);

    glVertex3f(10,5,25);
    glTexCoord2f(0,1);

    glVertex3f(15,5,20);
    glTexCoord2f(1,1);

    glVertex3f(5,5,10);
    glTexCoord2f(1,0);

   // glVertex3f(10,5,10);
    //glTexCoord2f(0.75,0);


    glVertex3f(10,5,5);
    glTexCoord2f(0,0);

    glVertex3f(4,5,0);
    glTexCoord2f(0,1);

    glVertex3f(10,5,0);
    glTexCoord2f(1,1);

    glVertex3f(20,5,7);
    glTexCoord2f(0.25,0);

    glVertex3f(30,5,9);
    glTexCoord2f(0.5,0);



    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();




    glPushMatrix();
    LoadTexture_surface("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\stone3.bmp", ID);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(20,0,5);

    glBegin(GL_QUADS);

    glVertex3f(30,0,30);
    glTexCoord2f(1,1);
    glVertex3f(30,0,9);
    glTexCoord2f(1,0);
    glVertex3f(30,5,9);
    glTexCoord2f(0,0);
    glVertex3f(30,5,30);
    glTexCoord2f(0,1);

    glEnd();




    glBegin(GL_QUADS);

    glVertex3f(30,0,30);
    glTexCoord2f(1,1);
    glVertex3f(20,0,35);
    glTexCoord2f(1,0);
    glVertex3f(20,5,35);
    glTexCoord2f(0,0);
    glVertex3f(30,5,30);
    glTexCoord2f(0,1);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(0,0,40);
    glTexCoord2f(1,1);
    glVertex3f(20,0,35);
    glTexCoord2f(1,0);
    glVertex3f(20,5,35);
    glTexCoord2f(0,0);
    glVertex3f(0,5,40);
    glTexCoord2f(0,1);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(15,0,20);
    glTexCoord2f(1,1);
    glVertex3f(5,0,10);
    glTexCoord2f(1,0);
    glVertex3f(5,5,10);
    glTexCoord2f(0,0);
    glVertex3f(15,5,20);
    glTexCoord2f(0,1);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(10,0,5);
    glTexCoord2f(1,1);
    glVertex3f(4,0,0);
    glTexCoord2f(1,0);
    glVertex3f(4,5,0);
    glTexCoord2f(0,0);
    glVertex3f(10,5,5);
    glTexCoord2f(0,1);

    glEnd();



    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();





}
