#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include "func.h"
#include "BmpLoader.h"


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <iostream>


#define PI 3.1415927


double Txval=0,Tyval=0,Tzval=0;
double windowHeight=1500, windowWidth=750;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = 1, uRotate = false;
bool light1= true, light2 = true, light3 =false;
bool amb =true, dif = true, spec = true;
bool l_amb=true,l_dif=true, l_spec = false;
unsigned int ID;
unsigned int ID1[100];
GLuint *textures;
bool ship_view = false;
int ship_view_up=50, ship_view_down =0, ship_view_right = 0, ship_view_left = 30;

///------------------------------------------------------------------------------------------------------------
float eyeX =60,eyeY=50,eyeZ=50, lookX=15,lookY=5,lookZ=15;
///float eyeX =40,eyeY=17,eyeZ=70, lookX=40,lookY=6.5,lookZ=20;
///------------------------------------------------------------------------------------------------------------

float car1_X = 0,car2_X = 0,car3_X = 0, car1_Z,car2_Y,car3_Y;
bool move_forward1 = true, move_forward2= true, move_forward3 = true;

float boat_X = 0, boat_Z = 0;
bool boat_forward = 1, boat_sideways = 1;
bool day=1;
int sky_texture = 1, sky_texture2 = 21;
int sun_pos_x=-1, sun_pos_z=20;

int water_texture = 0;


int anglex= 0, angley = 0, anglez = 0;          //rotation angles
int windows;
int wired=0;
int shcpt=0;
int animat = 0;
const int L=20;
const int dgre=3;
int ncpt=L+1;
int clikd=0;
const int nt = 40;				//number of slices along x-direction
const int ntheta = 20;
float sea_c = 1;
/**
GLfloat ctrlpoints[L+1][3] =
{
    { 0.0, 0.0, 0.0}, { -0.3, 0.5, 0.0},
    { 0.1, 1.7, 0.0},{ 0.5, 1.5, 0.0},
    {1.0, 1.5, 0.0}, {1.4, 1.4, 0.0},
    {1.8, 0.4, 0.0},{2.2, 0.4, 0.0},
    {2.6, 1.5, 0.0}, {3.0, 1.4, 0.0},
    {3.4, 1.4, 0.0},{3.8, 1.4, 0.0},
    {4.2, 1.0, 0.0},{4.6, 1.0, 0.0},
    {5.0, 1.0, 0.0},{5.4, 1.0, 0.0},
    {5.8, 0.5, 0.0},{6.2, 0.5, 0.0},
    {6.6, 0.5, 0.0},{7.2, 0.2, 0.0},
    {6.8, 0.52, 0.0}
};
**/
GLfloat ctrlpoints[L+1][3] =
{
    { 0.0, 0.0, 0.0}, { -0.3, 0.5, 0.0},
    { 0.1, 25, 0.0},{ 0.5, 9, 0.0},
    {1.0, 8, 0.0}, {1.4, 7, 0.0},
    {1.8, 6.5, 0.0},{2.2, 6.2, 0.0},
    {2.6, 6, 0.0}, {3.0, 5.6, 0.0},
    {3.4, 5.2, 0.0},{3.8, 4.4, 0.0},
    {4.2, 4.0, 0.0},{4.6, 3.5, 0.0},
    {5.0, 3.0, 0.0},{5.4, 3.0, 0.0},
    {5.8, 2.5, 0.0},{6.2, 2.5, 0.0},
    {6.6, 0.5, 0.0},{7.2, 0.2, 0.0},
    {6.8, 0, 0.0}
};



double ex=0, ey=0, ez=15, lx=0,ly=0,lz=0, hx=0,hy=1,hz=0;

float wcsClkDn[3],wcsClkUp[3];


class point1
{
public:
    point1()
    {
        x=0;
        y=0;
    }
    int x;
    int y;
} clkpt[2];
int flag=0;
GLint viewport[4]; //var to hold the viewport info
GLdouble modelview[16]; //var to hold the modelview info
GLdouble projection[16]; //var to hold the projection matrix info


///////////////////////////
void scsToWcs(float sx,float sy, float wcsv[3] );
void processMouse(int button, int state, int x, int y);
void matColor(float kdr, float kdg, float kdb,  float shiny, int frnt_Back=0, float ambFactor=1.0, float specFactor=1.0);
////////////////////////////

void scsToWcs(float sx,float sy, float wcsv[3] )
{

    GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
    GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

    //glGetDoublev( GL_MODELVIEW_MATRIX, modelview ); //get the modelview info
    glGetDoublev( GL_PROJECTION_MATRIX, projection ); //get the projection matrix info
    glGetIntegerv( GL_VIEWPORT, viewport ); //get the viewport info

    winX = sx;
    winY = (float)viewport[3] - (float)sy;
    winZ = 0;

    //get the world coordinates from the screen coordinates
    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);
    wcsv[0]=worldX;
    wcsv[1]=worldY;
    wcsv[2]=worldZ;


}


void processMouse(int button, int state, int x, int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(flag!=1)
        {
            flag=1;
            clkpt[0].x=x;
            clkpt[0].y=y;
        }


        scsToWcs(clkpt[0].x,clkpt[0].y,wcsClkDn);
        std::cout<<"\nD: "<<x<<" "<<y<<" wcs: "<<wcsClkDn[0]<<" "<<wcsClkDn[1];
    }
    else if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
    {
        if (flag==1)
        {
            clkpt[1].x=x;
            clkpt[1].y=y;
            flag=0;
        }
        float wcs[3];
        scsToWcs(clkpt[1].x,clkpt[1].y,wcsClkUp);
        std::cout<<"\nU: "<<x<<" "<<y<<" wcs: "<<wcsClkUp[0]<<" "<<wcsClkUp[1];

        clikd=!clikd;
    }
}


long long nCr(int n, int r)
{
    if(r > n / 2)
        r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void BezierCurve ( double t,  float xy[2])
{
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=L; i++)
    {
        int ncr=nCr(L,i);
        double oneMinusTpow=pow(1-t,double(L-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*ctrlpoints[i][0];
        y+=coef*ctrlpoints[i][1];

    }
    xy[0] = float(x);
    xy[1] = float(y);

    //return y;
}

void setNormal(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
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

    glNormal3f(-Nx,-Ny,-Nz);
}



void bottleBezier()
{
    int i, j;
    float x, y, z, r;				//current coordinates
    float x1, y1, z1, r1;			//next coordinates
    float theta;

    const float startx = 0, endx = ctrlpoints[L][0];
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xy[2];
    BezierCurve( t,  xy);
    x = xy[0];
    r = xy[1];
    //rotate about z-axis
    float p1x,p1y,p1z,p2x,p2y,p2z;
    for ( i = 0; i < nt; ++i )  			//step through x
    {
        theta = 0;
        t+=dt;
        BezierCurve( t,  xy);
        x1 = xy[0];
        r1 = xy[1];

        //draw the surface composed of quadrilaterals by sweeping theta
        glBegin( GL_QUAD_STRIP );
        for ( j = 0; j <= ntheta; ++j )
        {
            theta += dtheta;
            double cosa = cos( theta );
            double sina = sin ( theta );
            y = r * cosa;
            y1 = r1 * cosa;	//current and next y
            z = r * sina;
            z1 = r1 * sina;	//current and next z

            //edge from point at x to point at next x
            glVertex3f (x, y, z);

            if(j>0)
            {
                setNormal(p1x,p1y,p1z,p2x,p2y,p2z,x, y, z);
            }
            else
            {
                p1x=x;
                p1y=y;
                p1z=z;
                p2x=x1;
                p2y=y1;
                p2z=z1;

            }
            glVertex3f (x1, y1, z1);

            //forms quad with next pair of points with incremented theta value
        }
        glEnd();
        x = x1;
        r = r1;
    } //for i

}


static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    // gluPerspective(60,ar, 2.0, 100.0);

    glOrtho(-8.0, 8.0, -8.0*(GLfloat)height/(GLfloat)width, 8.0*(GLfloat)height/(GLfloat)width, 2.0, 25.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    gluLookAt(ex,ey,ez,lx,ly,lz,hx,hy,hz);

}

void showControlPoints()
{
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for (int i = 0; i <=L; i++)
        glVertex3fv(&ctrlpoints[i][0]);
    glEnd();
}




///float eyeX =60,eyeY=20,eyeZ=50, lookX=15,lookY=5,lookZ=15;
///float eyeX =70,eyeY=20,eyeZ=50, lookX=0,lookY=0,lookZ=0;



///float eyeX =45,eyeY=15,eyeZ=35, lookX=45,lookY=12,lookZ=20;
///float eyeX =55,eyeY=15,eyeZ=20, lookX=45,lookY=8,lookZ=20;

///float eyeX =70,eyeY=5,eyeZ=10, lookX=45,lookY=8,lookZ=20;

void matColor(float kdr, float kdg, float kdb,  float shiny, int frnt_Back, float ambFactor, float specFactor)
{

    const GLfloat mat_ambient[]    = { kdr*ambFactor, kdg*ambFactor, kdb*ambFactor, 1.0f };
    const GLfloat mat_diffuse[]    = { kdr, kdg, kdb, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f*specFactor, 1.0f*specFactor, 1.0f*specFactor, 1.0f };
    const GLfloat high_shininess[] = { shiny };
    if(frnt_Back==0)
    {
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    }
    else if(frnt_Back==1)
    {
        glMaterialfv(GL_BACK, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_BACK, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_BACK, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_BACK, GL_SHININESS, high_shininess);
    }
    else if(frnt_Back==2)
    {
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, high_shininess);
    }

}



void display(void)
{

    const double t = glutGet(GLUT_ELAPSED_TIME) / 5000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(60,1,5,100);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, windowHeight, windowWidth);



    sea();
    island_shape();
    road_network();
    forest();
    lake();
    house();
    skyy();
    simulate_cars();
    simulate_boats();
    building_network();
    sun();
    ship();







    if(wired)
    {
        glPolygonMode( GL_FRONT, GL_LINE ) ;
        glPolygonMode( GL_BACK, GL_LINE ) ;

    }
    else
    {
        glPolygonMode( GL_FRONT,GL_FILL ) ;
        glPolygonMode( GL_BACK, GL_FILL ) ;
    }

    glPushMatrix();

    if(animat)
        glRotated(a,0,0,1);

    glRotatef( anglex, 1.0, 0.0, 0.0);
    glRotatef( angley, 0.0, 1.0, 0.0);         	//rotate about y-axis
    glRotatef( anglez, 0.0, 0.0, 1.0);

    glRotatef( 90, 0.0, 0.0, 1.0);
    glTranslated(-3.5,0,0);
    glGetDoublev( GL_MODELVIEW_MATRIX, modelview ); //get the modelview info

    matColor(0.52,0.35,0.05,20);   // front face color
    matColor(0.0,0.5,0.8,20,1);  // back face color

    glTranslatef(7,-30,35);
    glScalef(1.5,0.5,0.5);





    bottleBezier();


    if(shcpt)
    {
        matColor(0.0,0.0,0.9,20);
        ///showControlPoints();
    }

    glPopMatrix();



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
    printf("8. View position toggle               : 0 = ship view on/off\n");
    printf("9. Navigate Ship                      : [ = up, ] = down, . = right, , = left\n");
    printf("8.Day/Night toggle                    : 2 = Day view on/off\n");

    printf("---------------------------------------------------------------------------\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Island Home");



    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMouseFunc(processMouse);
    glutInitDisplayMode(GLUT_DOUBLE);

    glClearColor(0,0,0,1);

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    textures = new GLuint[22];
    glGenTextures(22, textures);

    ///Please change the address accordingly for proper output

    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\sea.bmp", textures[0]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\sky3.bmp", textures[1]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\grass.bmp", textures[2]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\stone3.bmp", textures[3]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\road.bmp", textures[4]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\slope.bmp", textures[5]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\building1.bmp", textures[6]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\lake2.bmp", textures[7]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\pavement.bmp", textures[8]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall2.bmp", textures[9]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall3.bmp", textures[10]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\roof1.bmp", textures[11]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall2.bmp", textures[12]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall3.bmp", textures[13]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\wall6.bmp", textures[14]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\flow1.bmp", textures[15]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\flow2.bmp", textures[16]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\flow3.bmp", textures[17]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\flow4.bmp", textures[18]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\flow5.bmp", textures[19]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\nsky.bmp", textures[20]);
    LoadTexture("C:\\Users\\HP\\Desktop\\GLUT_project\\Island_home\\sky4.bmp", textures[21]);

    light();

    glutMainLoop();

    return 0;
}






