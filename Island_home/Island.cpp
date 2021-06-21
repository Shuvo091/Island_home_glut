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
    //light_enable();
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[15+water_texture]);
    glPushMatrix();

    glTranslatef(0,0,0);
    glScalef(50,2,50);
    glClearColor(0,0,0,1);
    drawCube(sea_c,sea_c,sea_c);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


}

void sky()
{
    //light_enable();
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_BINDING_2D, textures[1]);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,120,40);
    glClearColor(0,0,0,1);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(40,120,1);
    glClearColor(0,0,0,1);
    drawCube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



}

void island_shape()
{


    //light_enable();

    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glEnable(GL_TEXTURE_2D);


    glPushMatrix();
    glTranslatef(20,0,5);

///-----------------------------------------------------
    glBegin(GL_QUADS);
    glVertex3f(30,5,30);
    glTexCoord2f(1,1);

    glVertex3f(20,5,35);
    glTexCoord2f(1,0);

    glVertex3f(0,5,40);
    glTexCoord2f(0,0);

    glVertex3f(10,5,25);
    glTexCoord2f(0,1);



    glEnd();

///------------------------------------------
    glBegin(GL_QUADS);

    glVertex3f(30,5,30);
    glTexCoord2f(1,1);

    glVertex3f(10,5,25);
    glTexCoord2f(1,0);

    glVertex3f(15,5,20);
    glTexCoord2f(0,0);

    glVertex3f(30,5,9);
    glTexCoord2f(0, 1);

    glEnd();


    glBegin(GL_QUADS);

    glVertex3f(15,5,20);
    glTexCoord2f(1,1);

    glVertex3f(5,5,10);
    glTexCoord2f(1,0);

    glVertex3f(20,5,7);
    glTexCoord2f(0,0);

    glVertex3f(30,5,9);
    glTexCoord2f(0, 1);


    glEnd();

    glBegin(GL_QUADS);


    glVertex3f(5,5,10);
    glTexCoord2f(1,1);

    glVertex3f(10,5,0);
    glTexCoord2f(1,0);

    glVertex3f(4,5,0);
    glTexCoord2f(0,0);

    glVertex3f(20,5,7);
    glTexCoord2f(0,1);


    glEnd();



    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();




    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[3]);

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

void skyy()
{

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[sky_texture2]);


    glBegin(GL_QUADS);

    glVertex3f(0,0,0);
    glTexCoord2f(1,1);
    glVertex3f(0,100,0);
    glTexCoord2f(1,0);
    glVertex3f(0,100,80);
    glTexCoord2f(0,0);
    glVertex3f(0,0,80);
    glTexCoord2f(0,1);
    glEnd();

    glPushMatrix();
    glTranslatef(0,0,80);
    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glTexCoord2f(1,1);
    glVertex3f(80,0,0);
    glTexCoord2f(1,0);
    glVertex3f(80,100,0);
    glTexCoord2f(0,0);
    glVertex3f(0,100,0);
    glTexCoord2f(0,1);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[sky_texture]);


    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glTexCoord2f(1,1);
    glVertex3f(80,0,0);
    glTexCoord2f(1,0);
    glVertex3f(80,100,0);
    glTexCoord2f(0,0);
    glVertex3f(0,100,0);
    glTexCoord2f(0,1);
    glEnd();


    glPushMatrix();
    glTranslatef(80,0,0);

    glBegin(GL_QUADS);

    glVertex3f(0,0,0);
    glTexCoord2f(1,1);
    glVertex3f(0,100,0);
    glTexCoord2f(1,0);
    glVertex3f(0,100,80);
    glTexCoord2f(0,0);
    glVertex3f(0,0,80);
    glTexCoord2f(0,1);

    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}


void road_network()
{

    //light_enable();
    glPushMatrix();
    glTranslatef(20,0,5);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[4]);

    glBegin(GL_QUADS);
    glVertex3f(17,5.001,20.4);
    glTexCoord2f(1,1);
    glVertex3f(17,5.001,19.6);
    glTexCoord2f(1,0);
    glVertex3f(30,5.001,19.6);
    glTexCoord2f(0,0);
    glVertex3f(30,5.001,20.4);
    glTexCoord2f(0,1);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(17,5.001,34);
    glTexCoord2f(1,1);
    glVertex3f(17.8,5.001,34);
    glTexCoord2f(1,0);
    glVertex3f(17.8,5.001,8);
    glTexCoord2f(0,0);
    glVertex3f(17,5.001,8);
    glTexCoord2f(0,1);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(23,5.001,31);
    glTexCoord2f(1,1);
    glVertex3f(23.8,5.001,31);
    glTexCoord2f(1,0);
    glVertex3f(23.8,5.001,20);
    glTexCoord2f(0,0);
    glVertex3f(23,5.001,20);
    glTexCoord2f(0,1);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(17,5.001,25.4);
    glTexCoord2f(1,1);
    glVertex3f(17,5.001,24.6);
    glTexCoord2f(1,0);
    glVertex3f(30,5.001,24.6);
    glTexCoord2f(0,0);
    glVertex3f(30,5.001,25.4);
    glTexCoord2f(0,1);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(17,5.001,31);
    glTexCoord2f(1,1);
    glVertex3f(17,5.001,30.2);
    glTexCoord2f(1,0);
    glVertex3f(30,5.001,30.2);
    glTexCoord2f(0,0);
    glVertex3f(30,5.001,31);
    glTexCoord2f(0,1);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();

}


void forest()
{
    //light_enable();
    glPushMatrix();
    glTranslatef(20,0,5);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[5]);

    glBegin(GL_QUADS);
    glVertex3f(0.5,5.001,39.8);
    glTexCoord2f(1,1);
    glVertex3f(16,5.001,36);
    glTexCoord2f(1,0);
    glVertex3f(16,5.001,22);
    glTexCoord2f(0,0);
    glVertex3f(13,5.001,22);
    glTexCoord2f(0,1);
    glEnd();



    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

void buildings()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[6]);

    light_enable();

    glPushMatrix();
    glTranslatef(40,0,32);
    glScalef(1,8,1);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(46.5,0,32);
    glScalef(1,8,1);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(46.5,0,27);
    glScalef(1,8,1);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40.5,0,27);
    glScalef(1,8,1);
    drawCube(1,1,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}


void lake()
{
    //light_enable();
    glPushMatrix();
    glTranslatef(20,0,5);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[7]);

    glBegin(GL_QUADS);
    glVertex3f(10,5.001,15);
    glTexCoord2f(1,1);
    glVertex3f(7,5.001,6);
    glTexCoord2f(1,0);
    glVertex3f(16,5.001,6);
    glTexCoord2f(0,0);
    glVertex3f(16,5.001,15);
    glTexCoord2f(0,1);
    glEnd();



    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void house()
{
    //light_enable();
    glPushMatrix();
    glTranslatef(40,5,15);
    glScalef(.4,.4,.4);
    boundary();
    house_skeleton();


    glPopMatrix();
}

GLUquadricObj *quadratic = gluNewQuadric();;

void boat()
{

    glPushMatrix();
    glScalef(.1,.2,.1);
    glTranslatef(100,20,100);

    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
    glScalef(1,1,2);
    glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,10);
    glutSolidCone(7,10,12,14);
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(0,0,9);
    glutSolidCone(7,10,12,14);
    glPopMatrix();

    glPopMatrix();
}


void car()
{

    glPushMatrix();

    glRotatef(180,0,0,1);

    glPushMatrix();
    glScalef(2,1.4,1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-1,0.8,0);
    gluCylinder(quadratic,0.3,0.3,0.1,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,0.8,0.6);
    gluCylinder(quadratic,0.3,0.3,0.1,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7,0.8,0.6);
    gluCylinder(quadratic,0.3,0.3,0.1,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7,0.8,0);
    gluCylinder(quadratic,0.3,0.3,0.1,20,20);
    glPopMatrix();

    glPopMatrix();


}

void car1()
{
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(37,6,30);
    glScalef(.5,.5,.5);
    car();
    glPopMatrix();
}

void car2()
{
    glPushMatrix();
    glTranslatef(37,6,35.5);
    glScalef(.5,.5,.5);
    car();
    glPopMatrix();
}

void car3()
{
    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(37,6,25);
    glScalef(.5,.5,.5);
    car();
    glPopMatrix();
}

void simulate_cars()
{
    glPushMatrix();
    glTranslatef(car1_X,0,0);
    car1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(car2_X,0,0);
    car2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(car3_X,0,0);
    car3();
    glPopMatrix();


}

void simulate_boats()
{
    glPushMatrix();
    glTranslatef(boat_X,0, boat_Z);
    boat();

    glPopMatrix();

}

void custom_building()
{

    glPushMatrix();
    /**
        glPushMatrix();
        glScalef(5,20,0.2);  ///border1
        drawCube(1,1,1);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.2,20,5);
        drawCube(1,0,1);   ///border2
        glPopMatrix();  **/

    glPushMatrix();
    glScalef(5,0.2,5);   ///floor1
    drawCube(0.7,0.7,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.1,0);   ///livingroom 1
    living_room();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,8.6,0);
    glScalef(5,0.2,5);   ///floor2
    drawCube(0.7,0.7,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,8.7,0);
    living_room();       ///livingroom 2
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,17.2,0);
    glScalef(5,0.2,5);    ///floor 3
    drawCube(0.7,0.7,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,17.3,0);
    living_room();      ///livingroom 3
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,25.8,0);
    glScalef(5,0.2,5);   ///floor4
    drawCube(0.7,0.7,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,26,0);
    living_room();   ///livingroom 4
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,34.4,0);
    glScalef(5,0.2,5);   ///roof
    drawCube(0.4,0.4,0.4);
    glPopMatrix();



    glPopMatrix();

}

void building_network()
{

    glPushMatrix();
    glTranslatef(39,6,26);
    glScalef(0.4,0.4,0.4);
    custom_building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(39,20,26);
    glScalef(0.4,0.4,0.4);
    custom_building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(45.5,6,26);
    glScalef(0.4,0.4,0.4);
    custom_building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(39,6,31);
    glScalef(0.4,0.4,0.4);
    custom_building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(45.5,6,31);
    glScalef(0.4,0.4,0.4);
    custom_building();
    glPopMatrix();



}


void sun()
{

    glPushMatrix();
    glClearColor(0,0,0,1);
    glColor3f(1,1,1);
    glTranslatef(sun_pos_x,30,sun_pos_z);
    glScalef(.2,.4,.2);
    glutSolidSphere(10,20,20);
    glPopMatrix();

}


void ship()
{

    glPushMatrix();
    glTranslatef(ship_view_left,5,ship_view_up);
    glScalef(0.2,0.2,0.2);
    glRotatef(90,0,1,0);

    glPushMatrix();
    glScalef(15,2,5);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glScalef(15,4,0.5);
    drawCube(1,0.4,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,10);
    glScalef(15,4,0.5);
    drawCube(1,0.4,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30,0,0);
    glScalef(0.5,4,5.5);
    drawCube(1,0.4,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2,0.2,0);
    glScalef(5,7,5);
    drawCube(0.6,0.4,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,14,0);
    glScalef(4.8,1,0.2);
    drawCube(1,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,14,10);
    glScalef(4.8,1,0.2);
    drawCube(1,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,14,0.4);
    glScalef(0.2,1,4.8);
    drawCube(1,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,14,0.4);
    glScalef(0.2,1,4.8);
    drawCube(1,0,0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex3f(15,5,0);

    glVertex3f(15,5,5);

    glVertex3f(15,5,2.5);


    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,1,5);
    glScalef(0.4,10,0.4);
    drawCube(1,1,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,1,5);
    glScalef(0.4,10,0.4);
    drawCube(1,1,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22,1,5);
    glScalef(0.4,10,0.4);
    drawCube(1,1,0);
    glPopMatrix();

    glPopMatrix();







}



