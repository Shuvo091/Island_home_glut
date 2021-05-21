#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

#define PI 3.1415927

#include "func.h"

void sea()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(50,2,50);
    drawCube(0,0,0.80);
    glPopMatrix();

}

void sky()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,100,50);
    drawCube(0.1,0.1,0.70);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(50,100,1);
    drawCube(0.1,0.1,0.70);
    glPopMatrix();

}
