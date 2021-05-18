#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>

#define PI 3.1415927

#include "func.h"


void ceilingNwall()
{
    /// the walls
    glPushMatrix();
    glTranslatef(-5,0,-5);
    glScalef(0.25,4,7);
    drawCube(0.7,0.7,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,0,-5);
    glScalef(7,4,0.25);
    drawCube(0.5,0.5,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9,0,-5);
    glScalef(0.25,4,7);
    drawCube(0.7,0.7,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,0,9);
    glScalef(7,4,0.25);
    drawCube(0.5,0.5,0.5);
    glPopMatrix();

    ///ceiling
    glPushMatrix();
    glTranslatef(-5,7.5,-5);
    glScalef(7,0.5,7);
    drawCube(0.25,0.35,0.35);
    glPopMatrix();

}
void window()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,1,1);


    glPushMatrix();
    glTranslatef(-4.9,2.5,-1.5);
    glScalef(0.35,2,0.1);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.9,2.5,-4.2);
    glScalef(0.35,2,0.1);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.9,6.1,-4.2);
    glScalef(0.35,0.2,1.45);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.9,2.3,-4.2);
    glScalef(0.35,0.2,1.45);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.4,5.4,-4.2);
    glScalef(0.05,0.05,1.45);
    drawCube(.2,.2,.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.4,4.4,-4.2);
    glScalef(0.05,0.05,1.45);
    drawCube(.2,.2,.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.4,3.4,-4.2);
    glScalef(0.05,0.05,1.45);
    drawCube(.2,.2,.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.4,2.6,-2.9);
    glScalef(0.05,1.9,0.05);
    drawCube(.2,.2,.2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-4.9,2.5,-4);
    glScalef(0.25,2,1.3);
    drawCube(1,1,1);
    glPopMatrix();

    glPopMatrix();

}


void window2()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,1,1);


    glPushMatrix();
    glTranslatef(5,2,-4.9);
    glScalef(0.1,2,0.35);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.5,2,-4.9);
    glScalef(0.1,2,0.35);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,6,-4.9);
    glScalef(1.35,0.1,0.35);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,2,-4.9);
    glScalef(1.35,0.1,0.35);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,3,-4.9);
    glScalef(1.35,0.05,0.3);
    drawCube(0.2,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,4,-4.9);
    glScalef(1.35,0.05,0.3);
    drawCube(0.2,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,5,-4.9);
    glScalef(1.35,0.05,0.3);
    drawCube(0.2,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.25,2,-4.9);
    glScalef(0.07,2,0.3);
    drawCube(0.2,0.2,0.2);
    glPopMatrix();




    glPushMatrix();
    glTranslatef(5,2,-4.9);
    glScalef(1.3,2,0.25);
    drawCube(1,1,1);
    glPopMatrix();

    glPopMatrix();
}

void drawBox2()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,1,1);


    glPushMatrix();
    glTranslatef(-3,0,-4);
    glScalef(1.3,1.7,0.7);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.9,2.4,-4);
    glScalef(1.1,0.45,0.75);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,2.9,-4);
    glScalef(0.1,0.05,0.77);
    drawCube(0.99, 0.98, 0.95);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.9,1.4,-4);
    glScalef(1.1,0.45,0.75);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,1.9,-4);
    glScalef(0.1,0.05,0.77);
    drawCube(0.99, 0.98, 0.95);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.9,0.4,-4);
    glScalef(1.1,0.45,0.75);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,0.9,-4);
    glScalef(0.1,0.05,0.77);
    drawCube(0.99, 0.98, 0.95);
    glPopMatrix();

    glPopMatrix();


}


void fan_blades()
{
    glPushMatrix();
   glRotatef(theta,0,1,0);
    glTranslatef(5,0,-3);
    glScalef(15,0.4,3);
    drawCube(0.1,0.2,0.2);
   glPopMatrix();

   glPushMatrix();
   glRotatef(theta,0,1,0);
    glTranslatef(-5,0,-3);
    glScalef(15,0.4,3);
    glRotatef(90,0,0,1);
    drawCube(0.1,0.2,0.2);
   glPopMatrix();

   glPushMatrix();
   glRotatef(theta,0,1,0);
    glTranslatef(-3,0,5);
    glScalef(3,0.4,15);
    ///glRotatef(90,0,0,1);
    drawCube(0.1,0.2,0.2);
   glPopMatrix();

   glPushMatrix();
   glRotatef(theta,0,1,0);
   glTranslatef(-3,0,-5);
    glScalef(3,0.4,15);
    glRotatef(90,0,1,0);
    drawCube(0.1,0.2,0.2);
   glPopMatrix();
}

void fan()
{

    glPushMatrix();
    glScalef(.7,.7,.7);
    glTranslatef(0,6,0);

    glPushMatrix();
    glTranslatef(0,4,0);
    glScalef(0.1,0.1,0.1);

   glPushMatrix();
   glRotated(180,1,0,0);
   glPushMatrix();
   glRotatef(90,1,0,0);
   draw_cylinder(1,15,1,1,1);
   glPopMatrix();

   glPushMatrix();
   glRotatef(90,1,0,0);
   draw_cylinder(5,3,1,1,1);
   glPopMatrix();

   glPushMatrix();
   glRotated(theta,0,1,0);
   fan_blades();
   glPopMatrix();

   glPopMatrix();

   glPopMatrix();

   glPopMatrix();
}





void drawFloor()
{
    for(int i=-10; i<18; i++)
    {
        for(int j=-10; j<18; j++)
        {
            glPushMatrix();
            glTranslatef(0.5*j,0,0.5*i);
            glScalef(0.25,0.02,0.25);
            if((i+j)%2 == 0)
            {
                drawCube(1,1,1);
            }
            else
            {
                drawCube(0,0,0);
            }
            glPopMatrix();

        }

    }

}

void drawBox1()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,1,1);

    glPushMatrix();
    glTranslatef(-4,0,-1);
    glScalef(0.5,1,1.75);             ///base
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,0,-1);
    glScalef(0.52,0.94,0.5);             ///drawer
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,1.6,-0.2);
    glScalef(0.56,0.1,0.05);             ///drawer handle
    drawCube(0.99,.98,.97);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-4,0,0.2);
    glScalef(0.52,0.94,0.5);             ///drawer
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,1.6,1);
    glScalef(0.56,0.1,0.05);             ///drawer handle
    drawCube(0.99,.98,.97);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,0,1.4);
    glScalef(0.52,0.94,0.5);             ///drawer
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,1.6,2.2);
    glScalef(0.56,0.1,0.05);             ///drawer handle
    drawCube(0.99,.98,.97);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,1.75,0);
    glScalef(0.1,1.5,0.75);              ///ayna
    drawCube(0.98,0.98,0.96,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,1.75,-.2);
    glScalef(0.05,1.5,0.05);             ///ayna frame
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,1.75,1.5);
    glScalef(0.05,1.5,0.05);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,4.75,-0.23);
    glScalef(0.05,0.07,0.9);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPopMatrix();

}

void drawBed()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,1,1);

    glPushMatrix();
    glTranslatef(1,0.55,-3.75);
    glScalef(1.76,0.15,3.01);       ///matress
    glRotatef(-4,0,1,0);
    drawCube(0.99,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,0,-3.75);
    glScalef(1.75,0.4,3);
    glRotatef(-4,0,1,0);              ///base
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,0,-3.75);
    glScalef(1.75,1,0.05);
    glRotatef(-4,0,1,0);           ///head support
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1,0.9,-3);
    glScalef(0.7,0.06,0.6);
    glRotatef(-4,0,1,0);          ///balish1
    drawCube(1,0.5,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,0.9,-3);
    glScalef(0.7,0.06,0.6);
    glRotatef(-4,0,1,0);          ///balish2
    drawCube(1,0.5,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5,0.9,0);
    glScalef(1.2,0.03,0.6);
    glRotatef(-4,0,1,0);          ///katha
    drawCube(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.7,0.25,0);
    glScalef(0.4,0.01,1);
    glRotatef(-4,0,1,0);          ///paposh
    drawCube(0.4,0.8,0.3);
    glPopMatrix();

    glPopMatrix();

}

void drawBox3()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,1,1);


    glPushMatrix();
    glTranslatef(5,0,-3);
    glScalef(0.75,0.75,1);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,0.8,-3);
    glScalef(0.74,0.3,1.1);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.7,1,-3);
    glScalef(0.1,0.05,1.13);
    drawCube(0.99, 0.98, 0.97);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,0.1,-3);
    glScalef(0.74,0.3,1.1);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.7,0.4,-3);
    glScalef(0.1,0.05,1.13);
    drawCube(0.99, 0.98, 0.97);
    glPopMatrix();

    glPopMatrix();


}

void drawPicFrame2()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,1,1);


    glPushMatrix();
    glTranslatef(2.5,5,-4.6);
    glScalef(0.5,0.5,0.1);
    drawCube(0.2,0.6,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.4,5,-4.6);
    glScalef(0.05,0.5,0.1);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.4,4.9,-4.6);
    glScalef(0.6,0.05,0.1);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.4,6,-4.6);
    glScalef(0.6,0.05,0.1);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5,5,-4.6);
    glScalef(0.05,0.5,0.1);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPopMatrix();

}

void drawPicFrame1()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,1,1);


    glPushMatrix();
    glTranslatef(-1.25,4,-4.6);
    glScalef(0.5,0.5,0.1);
    drawCube(0.2,0.6,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.3,4,-4.6);
    glScalef(0.05,0.5,0.1);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.3,3.9,-4.6);
    glScalef(0.55,0.05,0.1);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.3,5,-4.6);
    glScalef(0.55,0.05,0.1);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.27,4,-4.6);
    glScalef(0.05,0.5,0.1);
    drawCube(0.545, 0.271, 0.075);
    glPopMatrix();

    glPopMatrix();
}

void drawAC()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,1,1);


    glPushMatrix();
    glTranslatef(-1,5.7,-4);
    glScalef(1.75,0.5,0.3);
    drawCube(0.902, 0.902, 0.980);
    glPopMatrix();

    glPopMatrix();
}



void drawSphere(float col_a,float col_b,float col_c)
{

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { col_a, col_b , col_c, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1, 0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {70};

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
    glutSolidSphere(0.5, 20, 16);
}




