#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED



#endif // FUNC_H_INCLUDED



extern double Txval,Tyval,Tzval;
extern double windowHeight, windowWidth;
extern GLfloat alpha, theta, axis_x, axis_y;
extern GLboolean bRotate, uRotate;
extern bool light1, light2, light3;
extern bool amb, dif, spec;
extern bool l_amb,l_dif, l_spec;
extern float eyeX,eyeY,eyeZ, lookX,lookY,lookZ;
extern unsigned int ID1[100];
extern unsigned int ID;
extern GLuint *textures;
extern float car1_X,car2_X,car3_X, car1_Z,car2_Y,car3_Y;
extern bool move_forward1, move_forward2, move_forward3;
extern int water_texture;
extern bool day;
extern int sky_texture, sky_texture2;
extern float sea_c;
extern int sun_pos_x, sun_pos_z;
extern bool ship_view;


extern float boat_X, boat_Z;
extern bool boat_forward, boat_sideways;
extern int ship_view_up, ship_view_down, ship_view_right, ship_view_left;





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



static void getNormal3p(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3);
void drawCube(float col_a,float col_b,float col_c, float shininess = 60);
void draw_cylinder(GLfloat radius, GLfloat height, GLubyte col_a, GLubyte col_b, GLubyte col_c);
void light();
void myKeyboardFunc( unsigned char key, int x, int y );
void animate();

///void display(void);
void LoadTexture(const char*filename, GLuint ID_);
void light_enable();


void ceilingNwall();
void window();
void window2();
void drawBox2();
void fan_blades();
void fan();
void drawFloor();
void drawBox1();
void drawBed();
void drawBox3();
void drawPicFrame2();
void drawPicFrame1();
void drawAC();
void drawSphere(float col_a,float col_b,float col_c);
void living_room();
void building_network();
void ship();


void sea();
void sky();
void island_shape();
void road_network();
void forest();
void buildings();
void lake();
void house();
void skyy();
void boat();
void car();
void simulate_cars();
void simulate_boats();
void custom_building();
void sun();

void boundary();
void house_skeleton();


