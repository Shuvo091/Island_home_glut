#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>

#define PI 3.1415927

#include "func.h"
#include "BmpLoader.h"


void LoadTexture(const char*filename, unsigned int ID_)
{
    ID = ID_;
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}

void LoadTexture_surface(const char*filename, unsigned int ID_)
{
    ID = ID_;
    glGenTextures(1, &ID);
    ///glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    ///glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    ///glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    ///glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    ///glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
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
    GLfloat light_position[] = { 0, 70.0, 0, 1.0 };

    GLfloat light_ambient2[]  = {1, 1, 1, 1.0};
    GLfloat light_diffuse2[]  = { 1.0, 1.0, 1, 1.0 };
    GLfloat light_specular2[] = { 1.0, 1.0, 1, 1.0 };
    GLfloat light_position2[] = { 7, 50.0, 7, 1.0 };

    GLfloat light_ambient3[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse3[]  = { 1.0 - 0.3, 1, 1 - 0.3, 1.0 };
    GLfloat light_specular3[] = { 1.0, 0, 1, 1.0 };
    GLfloat light_position3[] = { 2, 60.0, -4, 1.0 };

    if(l_amb)
    {
        glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient2);
        glLightfv( GL_LIGHT2, GL_AMBIENT, light_ambient3);
        glLightfv( GL_LIGHT0, GL_POSITION, light_position);

         GLfloat spot_direction[] = {-2,-4,0};
         glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
         glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 25);

    }
    else
    {
        glLightfv( GL_LIGHT0, GL_AMBIENT, no_light);
        glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);
        glLightfv( GL_LIGHT2, GL_AMBIENT, no_light);
        glLightfv( GL_LIGHT0, GL_POSITION, light_position);

         GLfloat spot_direction[] = {-2,-4,0};
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 25);

    }

    if(l_dif)
    {
        glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse2);
        glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse3);


    }
    else
    {
        glLightfv( GL_LIGHT0, GL_DIFFUSE, no_light);
        glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);
        glLightfv( GL_LIGHT2, GL_DIFFUSE, no_light);

    }

    if(l_spec)
    {
        glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular2);
        glLightfv( GL_LIGHT2, GL_SPECULAR, light_specular3);


    }
    else
    {
        glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);
        glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);
        glLightfv( GL_LIGHT2, GL_SPECULAR, no_light);


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
        break;
    case '3':
        light3 = !light3;
        break;


    case 'w':
        eyeY += 0.1;
        break;
    case 's':
        eyeY -= 0.1;
        break;
    case 'a':
        eyeX += 0.1;
        break;
    case 'd':
        eyeX -= 0.1;
        break;
    case 'q':
        eyeZ += 0.1;
        break;
    case 'e':
        eyeZ -= 0.1;
        break;

    case 'i':
        lookY += 0.1;
        break;
    case 'k':
        lookY -= 0.1;
        break;
    case 'j':
        lookX += 0.1;
        break;
    case 'l':
        lookX -= 0.1;
        break;
    case 'u':
        lookZ += 0.1;
        break;
    case 'o':
        lookZ -= 0.1;
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

    light();
    glutPostRedisplay();

}








