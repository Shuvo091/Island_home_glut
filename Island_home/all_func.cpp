#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include<iostream>

#define PI 3.1415927

#include "func.h"
#include "BmpLoader.h"



void light_enable()
{
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
}

void LoadTexture(const char*filename, GLuint texture)
{

    glBindTexture(GL_TEXTURE_2D, texture);
    ///glPixelStorei(GL_UNPACK_ALIGNMENT, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
    //std::cout << texture <<std::endl;
}


static void getNormal3p(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}


void drawCube(float col_a,float col_b,float col_c, float shininess)
{

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { col_a, col_b, col_c, 1.0 };
    GLfloat mat_diffuse[] = { col_a, col_b, col_c, 1.0 };
    GLfloat mat_specular[] = {1,0,1, 1.0 };
    GLfloat mat_shininess[] = {shininess};

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


    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        ///glColor3f(col_a - i*0.03, col_b - i*0.03, col_c - i*0.03);

        getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
                    v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
                    v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]);


        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glTexCoord2f(1,1);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glTexCoord2f(1,0);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glTexCoord2f(0,0);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
        glTexCoord2f(0,1);
    }
    glEnd();
}

void draw_cylinder(GLfloat radius, GLfloat height, GLubyte col_a, GLubyte col_b, GLubyte col_c)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;


    ///glColor3ub(R-40,G-40,B-40);
    ///glColor4f(col_a,col_b,col_c,0);
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { col_a, col_b, col_c, 1.0 };
    GLfloat mat_diffuse[] = { col_a, col_b, col_c, 1.0 };
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


    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while( angle < 2*PI )
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    ///glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while( angle < 2*PI )
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}

void light()
{


    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };

    GLfloat light_ambient[]  = {0.7, 0.7, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0-0.3, 1.0-0.3, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 41,20,33, 1.0 };

    GLfloat light_ambient4[]  = {1, 0.2, 0.2, 1.0};
    GLfloat light_diffuse4[]  = { 0, 0, 0, 1.0 };
    GLfloat light_specular4[] = { 0, 0, 0, 1.0 };
    GLfloat light_position4[] = { sun_pos_x,30,sun_pos_z, 1.0 };

    GLfloat light_ambient2[]  = {1,1,1, 1.0};
    GLfloat light_diffuse2[]  = { .2, .2, .2, 1.0 };
    GLfloat light_specular2[] = { 1.0, 1.0, 1, 1.0 };
    GLfloat light_position2[] = { 7, 50.0, 7, 1.0 };

    GLfloat light_ambient3[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse3[]  = { 1.0 - 0.3, 1, 1 - 0.3, 1.0 };
    GLfloat light_specular3[] = { 1.0, 0, 1, 1.0 };
    GLfloat light_position3[] = { 2, 60.0, -4, 1.0 };


    if(l_amb)
    {
        glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv( GL_LIGHT3, GL_AMBIENT, light_ambient4);
        glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient2);
        glLightfv( GL_LIGHT2, GL_AMBIENT, light_ambient3);
        glLightfv( GL_LIGHT0, GL_POSITION, light_position);

        GLfloat spot_direction[] = {0,-1,0};
        GLfloat spot_direction2[] = {0,-1,0};
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
        glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 5);
        glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction2);
        glLightf( GL_LIGHT3, GL_SPOT_CUTOFF, 100);

    }
    else
    {
        glLightfv( GL_LIGHT0, GL_AMBIENT, no_light);
        glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);
        glLightfv( GL_LIGHT2, GL_AMBIENT, no_light);
        glLightfv( GL_LIGHT0, GL_POSITION, light_position);

        GLfloat spot_direction[] = {39,16,26};
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
        glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 7);

    }

    if(l_dif)
    {
        glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse2);
        glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse3);
        glLightfv( GL_LIGHT3, GL_DIFFUSE, light_diffuse4);


    }
    else
    {
        glLightfv( GL_LIGHT0, GL_DIFFUSE, no_light);
        glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);
        glLightfv( GL_LIGHT2, GL_DIFFUSE, no_light);
        glLightfv( GL_LIGHT3, GL_DIFFUSE, no_light);

    }

    if(l_spec)
    {
        glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular2);
        glLightfv( GL_LIGHT2, GL_SPECULAR, light_specular3);
        glLightfv( GL_LIGHT3, GL_SPECULAR, light_specular4);


    }
    else
    {
        glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);
        glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);
        glLightfv( GL_LIGHT2, GL_SPECULAR, no_light);
        glLightfv( GL_LIGHT3, GL_SPECULAR, no_light);


    }



    glLightfv( GL_LIGHT1, GL_POSITION, light_position2);

    glLightfv( GL_LIGHT2, GL_POSITION, light_position3);

    if(light1)
    {
        glEnable(GL_LIGHT0);


    }

    else
    {
        glDisable(GL_LIGHT0);

    }

    if(light2)
    {
        glEnable(GL_LIGHT1);

    }

    else
    {
        glDisable(GL_LIGHT1);

    }

    if(light3)
    {
        glEnable(GL_LIGHT2);

    }

    else
    {
        glDisable(GL_LIGHT2);

    }


}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case '1':
        light1 = !light1;
        break;
    case '2':
        light2 = !light2;
        day = !day;
        break;
    case '3':
        light3 = !light3;
        break;

    case '0':
        if(ship_view)
        {
            eyeX =ship_view_left;
            eyeY=17;
            eyeZ=10+ship_view_up;
            lookX=ship_view_left;
            lookY=6.5;
            lookZ=20;
        }
        else
        {
            eyeX =60;
            eyeY=50;
            eyeZ=50;
            lookX=15;
            lookY=5;
            lookZ=5;
        }
        ship_view = !ship_view;
        break;
    case '[':
        ship_view_up++;
        eyeZ=10+ship_view_up;
        break;
    case ']':
        ship_view_up--;
        eyeZ=10+ship_view_up;
        break;

    case ',':
        ship_view_up--;
        ship_view_left--;
        eyeZ=10+ship_view_up;
        eyeX = ship_view_left;
        lookX--;
        break;
    case '.':
        ship_view_up--;
        ship_view_left++;
        eyeZ=10+ship_view_up;
        eyeX = ship_view_left;
        lookX++;
        break;






    case 'w':
        eyeY += 2.5;
        break;
    case 's':
        eyeY -= 2.5;
        break;
    case 'a':
        eyeX += 2.5;
        break;
    case 'd':
        eyeX -= 2.5;
        break;
    case 'q':
        eyeZ += 2.5;
        break;
    case 'e':
        eyeZ -= 2.5;
        break;

    case 'i':
        lookY += 2.5;
        break;
    case 'k':
        lookY -= 2.5;
        break;
    case 'j':
        lookX += 2.5;
        break;
    case 'l':
        lookX -= 2.5;
        break;
    case 'u':
        lookZ += 2.5;
        break;
    case 'o':
        lookZ -= 2.5;
        break;

    case 'z':
        bRotate = !bRotate;
        break;
    case 'x':
        uRotate = !uRotate;
        break;

    case 'b':
        amb = !amb;
        break;
    case 'n':
        dif = !dif;
        break;
    case 'm':
        spec = !spec;
        break;

    case '4':
        l_amb = !l_amb;
        break;
    case '5':
        l_dif = !l_dif;
        break;
    case '6':
        l_spec = !l_spec;
        break;





    case 27:	// Escape key
        exit(1);
    }
}
bool water_flag=1;

void animate()
{
    if (bRotate == true)
    {
        theta += 2;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        theta -= 2;
        if(theta < 0)
            theta = 360;
    }


    if(move_forward1 && car1_X<12)
    {
        car1_X = car1_X+1;
        ///std::cout<<"car moved forward\n";
    }
    else
    {
        move_forward1 = false;
    }

    if(!move_forward1 && car1_X>0)
    {
        car1_X = car1_X-1;

    }
    else
    {
        move_forward1 = true;
    }

    if(move_forward3 && car3_X<12)
    {
        car3_X = car3_X+0.2;

    }
    else
    {
        move_forward3 = false;
    }

    if(!move_forward3 && car3_X>0)
    {
        car3_X = car3_X-0.3;

    }
    else
    {
        move_forward3 = true;
    }
    /**
        if(car1_X>=37)
        {
            car1_X = car1_X+1;
            std::cout<<"car moved backward\n";
        } **/

    if(move_forward2 && car2_X<9)
    {
        car2_X = car2_X+0.5;

    }
    else
    {
        move_forward2 = false;
    }

    if(!move_forward2 && car2_X>0)
    {
        car2_X = car2_X-0.3;

    }
    else
    {
        move_forward2 = true;
    }
///-------------------------------------------------------------
    if(boat_forward && boat_X<15)
    {
        boat_X = boat_X+0.9;

    }
    else
    {
        boat_forward = false;
    }

    if(!boat_forward && boat_X>0)
    {
        boat_X = boat_X-0.5;

    }
    else
    {
        boat_forward = true;
    }
    ///------------------------------

    if(boat_sideways && boat_Z<12)
    {
        boat_Z = boat_Z+0.7;

    }
    else
    {
        boat_sideways = false;
    }

    if(!boat_sideways && boat_Z>0)
    {
        boat_Z = boat_Z-0.5;

    }
    else
    {
        boat_sideways = true;
    }
    if(water_flag)
    {
        water_texture++;
        if(water_texture==4)
        {
            water_flag = 0;
        }

    }
    else
    {
        water_texture--;
        if(water_texture==0)
        {
            water_flag = 1;
        }
    }
    if(day)
    {

        glEnable(GL_LIGHT3);
        sky_texture = 1;
        sea_c = 1;
        sky_texture2 = 21;
        sun_pos_x=-1;
        sun_pos_z=20;

    }
    else
    {
        sky_texture = 20;
        sea_c = 0.5;
        sky_texture2 = 20;
        sun_pos_x=20;
        sun_pos_z=-1;
        glDisable(GL_LIGHT3);
    }


    /**
    if(ship_view)
    {

    }
    else
    {

    }
    **/



    light();
    glutPostRedisplay();

}








