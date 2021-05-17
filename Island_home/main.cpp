#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>

double Txval=0,Tyval=0,Tzval=0;
double windowHeight=700, windowWidth=700;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = 1, uRotate = false;


#define PI 3.1415927



static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 2.0},
    {2.0, 0.0, 2.0},
    {2.0, 0.0, 0.0},
    {0,2,0},
    {0,2,2},
    {2,2,2},
    {2,2,0}

};

static GLubyte quadIndices[6][4] =
{
    {4,5,6,7},
    {1,2,6,5},
    {3,2,6,7},
    {0,3,7,4},
    {0,1,2,3},
    {0,1,5,4}
};


static GLfloat colors[7][3] =
{
    {0.0, 0.0, 1.0},
    {0.5, 0.0, 1.0},
    {0.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},
    {0.8, 0.0, 0.0},
    {0.0, 1.0, 0.8},
    {0.8, 0.8, 0.0}
};



static void getNormal3p
(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
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


bool light1= true, light2 = true, light3 =true;
bool amb =true, dif = true, spec = true;

void drawCube(float col_a,float col_b,float col_c, float shininess = 60)
{
    ///glColor4f(col_a,col_b,col_c,0);
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
        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
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


bool l_amb=true,l_dif=true, l_spec = true;
void light()
{


    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };

    GLfloat light_ambient[]  = {0.7, 0.7, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0-0.3, 1.0-0.3, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 0, 70.0, 0, 1.0 };

    GLfloat light_ambient2[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse2[]  = { 1.0-0.3, 1.0-0.3, 0, 1.0 };
    GLfloat light_specular2[] = { 1.0, 1.0, 0, 1.0 };
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


float eyeX =6,eyeY=5,eyeZ=7, lookX=2,lookY=4,lookZ=1;
///float eyeX =7,eyeY=-30,eyeZ=7, lookX=2,lookY=2.5,lookZ=1;
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


    glFlush();
    glutSwapBuffers();
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

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Living Room");

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






