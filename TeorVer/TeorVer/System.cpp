#include "System.h"
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <Windows.h>

#define GLUT_KEY_TAB 9
#define _USE_MATH_DEFINES
#define CN 8
static double cof[CN] = {
       2.5066282746310005,
       1.0000000000190015,
       76.18009172947146,
      -86.50532032941677,
       24.01409824083091,
      -1.231739572450155,
       0.1208650973866179e-2,
      -0.5395239384953e-5,
};

font System::Times_New_Roman = GLUT_BITMAP_HELVETICA_12;

char* System::m_title = nullptr;
int System::m_width = 1, System::m_height = 1;
int System::m_graphic = 1;
float System::m_from_x = -1, System::m_to_x = 1;
float System::m_from_y = -1, System::m_to_y = 1;
float System::m_grid_percision = 1;
float System::m_var_a = 0.0f;
float System::m_sigma = 0.5f;
float System::m_freedom_power = 4;
float System::m_alpha = 1;
float System::m_norm_a = 1, System::m_norm_b = 5;

//Getting PI number from SYSTEM
double get_PI() {
    double pi;
    __asm
    {
        fldpi
        fstp pi
    }
    return pi;
}
double GammLn(double x) {
    double y, ser, * co;
    int j;
    /* calculate the series */
    ser = cof[1]; y = x; co = cof + 2;
    for (j = 2; j < CN; j++) {
        y += 1.; ser += (*co) / y; co++;
    }
    /* and the other parts of the function */
    y = x + 5.5;
    y -= (x + 0.5) * log(y);
    return(-y + log(cof[0] * ser / x));
}

/* the gamma-function itself */
double Gamma(double x) {
    return(exp(GammLn(x)));
}

bool System::InitGraphicSys(const int& _w, const int& _h, const char* _title, int& _argc, char** _argv) {
    System::m_width = _w;
    System::m_height = _h;
    glutInit(&_argc, _argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(System::m_width, System::m_height);

    System::m_title = (char*) malloc((strlen(_title) + 1) * sizeof(char));
    if(System::m_title != nullptr)
        strcpy_s(System::m_title, strlen(_title) + 1,  _title);
    else {
        throw "System::window_title is nullptr";
        return 0;
    }
    return 1;
}

bool System::CreateGraphicWindow(void) {
    glutCreateWindow(System::m_title);
    glutReshapeFunc(System::Reshape);
    glutDisplayFunc(System::Render);
    glutKeyboardFunc(System::KeyboardIvent);
    return 1;
}

void System::StartGraphics(void) {
    glutMainLoop();
}
void System::RenderBitmapString(const float& _x, const float& _y, font _font, char* _str) {
    char* c;
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos3f(_x, _y, 0);
    for (c = _str; *c != '\0'; c++) {
        glutBitmapCharacter(_font, *c);
    }
}
void System::Render(void) {
    System::Reshape(System::m_width, System::m_height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glLoadIdentity();
     
    System::DrawAxis();
    System::DrawGrid();
    System::DrawCooLimits();
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);

    switch (System::m_graphic) {
    case 1:
        for (float i = System::m_from_x; i < System::m_to_x; i += System::m_grid_percision / 10)
            glVertex2f(i, System::RavnomernoeRaspredelenieFunc(i));
        break;
    case 2:
        for (float i = System::m_from_x; i < System::m_to_x; i += System::m_grid_percision / 10) 
            glVertex2f(i, System::NormalnoeRaspredelenieFunc(i));
        break;
    case 3:
        for (float i = 0.0f; i < System::m_to_x; i += System::m_grid_percision / 10)
            glVertex3f(i, System::RaspredeleneReleya(i), 0.0f);
        break;
    case 4:
        break;
    case 5:
        for (float i = 0.0f; i < System::m_to_x; i += System::m_grid_percision / 10)
            glVertex3f(i, System::RaspredelenieXiKvadrat(i), 0.0f);
        break;
    case 6:
        for (float i = 0.0f; i < System::m_to_x; i += System::m_grid_percision / 10)
            glVertex3f(i, System::RaspredeleniePokazatelnoe(i), 0.0f);
        break;
    }

    glEnd();

    glutSwapBuffers();

}
void System::Reshape(int _w, int _h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(System::m_from_x, System::m_to_x, System::m_from_y, System::m_to_y, 0, 1);
    glMatrixMode(GL_MODELVIEW);
}
void System::KeyboardIvent(unsigned char _key, int _x, int _y) {
    if (_key == GLUT_KEY_TAB) {
        System::m_graphic++;
        if (System::m_graphic == 7)
            System::m_graphic = 1;
        System::Render();
        switch (System::m_graphic) {
        case 1:
            System::SetAxis(-1.0f, 6.0f, -1.0f, 1.0f, 0.1f);
            MessageBox(NULL, L"Funciya Ravnomernogo Raspredeleniya", L"Postavte 100 pogaluista", MB_ICONINFORMATION);
            break;
        case 2:
            System::SetAxis(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f);
            MessageBox(NULL, L"Funciya Normalnogo Raspredeleniya", L"Postavte 100 pogaluista", MB_ICONINFORMATION);
            break;
        case 3:
            System::SetAxis(-1.0f, 3.0f, -1.0f, 2.0f, 0.1f);
            MessageBox(NULL, L"Funciya Raspredeleniya Releya", L"Postavte 100 pogaluista", MB_ICONINFORMATION);
            break;
        case 4:
            System::SetAxis(-1.0f, 6.0f, -1.0f, 1.0f, 0.1f);
            MessageBox(NULL, L"Funciya Raspredeleniya Maksvella 404", L"Postavte 100 pogaluista", MB_ICONERROR);
            break;
        case 5:
            System::SetAxis(-1.0f, 10.0f, -1.0f, 1.0f, 0.1f);
            MessageBox(NULL, L"Funciya Raspredeleniya Xi Kvadrat", L"Postavte 100 pogaluista", MB_ICONINFORMATION);
            break;
        case 6:
            System::SetAxis(-1.0f, 10.0f, -0.5f, 1.0f, 0.1f);
            MessageBox(NULL, L"Funciya Pokazatelnogo Raspredeleniya", L"Postavte 100 pogaluista", MB_ICONINFORMATION);
            break;
        }
        System::Render();
    }
}

float System::RavnomernoeRaspredelenieFunc(const float& _x) {
    if (_x < System::m_norm_a || _x > System::m_norm_b)
        return 0;
    float temp = (float)1 / (float)(System::m_norm_b - System::m_norm_a);
    return temp; 
}
float System::NormalnoeRaspredelenieFunc(const float& _x) {
    //temp = ( e^( -(x-a)^2 / 2 * sig^2) ) / v/(2 * PI * sig)
    float temp = (-pow((_x - System::m_var_a), 2)) / (2 * pow(System::m_sigma, 2));
    temp = pow(exp(1.0f), temp);
    temp /= sqrt(2 * System::m_sigma * get_PI());
    return temp;
}
float System::RaspredeleneReleya(const float& _x) {
    if (_x < 0 || System::m_sigma < 0)
        return 0.0f;
    // temp = (x * e^(-(x^2)/(2*sig^2)) / sig^2
    float temp =  -(pow(_x, 2) / ( 2 * pow(System::m_sigma, 2 ) ));
    temp = pow(exp(1.0f), temp) * _x;
    temp = temp / (pow(System::m_sigma, 2));
    return temp;
}
float System::RaspredelenieXiKvadrat(const float& _x) {
    if (_x < 0)
        return 0;
    float temp = pow(_x, (System::m_freedom_power/2) - 1);
    temp *= pow(exp(1.0f), (-_x / 2));
    temp /= ((pow(2, System::m_freedom_power / 2) * Gamma(System::m_freedom_power / 2)));
    return temp;
}
float System::RaspredeleniePokazatelnoe(const float& _x) {
    if (_x < 0)
        return 0;
    float temp = pow(exp(1.0f), -System::m_alpha * _x);
    temp *= System::m_alpha;
    return temp;
}

void System::DrawAxis(void) {
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    // X axis
    glBegin(GL_LINES);
        glVertex2f(System::m_from_x, 0);
        glVertex2f(System::m_to_x, 0);
    glEnd();
    // Y axis
    glBegin(GL_LINES);
        glVertex2f( 0, System::m_from_y);
        glVertex2f( 0, System::m_to_y);
    glEnd();
    // X arrow
    glBegin(GL_LINES);
        glVertex2f(System::m_to_x, 0);
        glVertex2f(System::m_to_x - System::m_grid_percision,  System::m_grid_percision);
        glVertex2f(System::m_to_x, 0);
        glVertex2f(System::m_to_x - System::m_grid_percision, -System::m_grid_percision);
    glEnd();
    // Y arrow
    glBegin(GL_LINES);
        glVertex2f(0, System::m_to_y);
        glVertex2f(-System::m_grid_percision, System::m_to_y - System::m_grid_percision);
        glVertex2f( 0, System::m_to_y);
        glVertex2f(System::m_grid_percision, System::m_to_y - System::m_grid_percision);
    glEnd();
}
void System::DrawGrid(void) {
    glColor3f(0.8f, 0.8f, 0.8f);
    glLineWidth(1.0f);
    for (float i = 0; i < abs(long(System::m_to_x - System::m_from_x)); i += System::m_grid_percision) {
        glBegin(GL_LINES);
            glVertex2f(System::m_from_x + i, System::m_from_y);
            glVertex2f(System::m_from_x + i, System::m_to_y);
        glEnd();
    }
    for (float i = 0; i < abs(long(System::m_to_y - System::m_from_y)); i += System::m_grid_percision) {
        glBegin(GL_LINES);
        glVertex2f(System::m_from_x,System::m_from_y + i);
        glVertex2f(System::m_to_x,System::m_from_y + i);
        glEnd();
    }
}
void System::DrawCooLimits(void) {
    char* str = (char*)malloc(sizeof(char) * 8);
    sprintf_s(str, 8, "%d\0", (int)System::m_from_x);
    System::RenderBitmapString(System::m_from_x + System::m_grid_percision, 0 - System::m_grid_percision, System::Times_New_Roman, str);
    memset(str, 0, 8);
    sprintf_s(str, 8, "%d\0", (int)System::m_to_x);
    System::RenderBitmapString(System::m_to_x - System::m_grid_percision, 0 - System::m_grid_percision*2, System::Times_New_Roman, str);
    memset(str, 0, 8);
    sprintf_s(str, 8, "%d\0", (int)System::m_from_y);
    System::RenderBitmapString(0 + System::m_grid_percision , System::m_from_y + System::m_grid_percision , System::Times_New_Roman, str);
    memset(str, 0, 8);
    sprintf_s(str, 8, "%d\0", (int)System::m_to_y);
    System::RenderBitmapString( 0 + System::m_grid_percision , System::m_to_y - System::m_grid_percision*2, System::Times_New_Roman, str);

}

void System::SetAxis(const float& _from_x, const float& _to_x, const float& _from_y, const  float& _to_y, const float& _grid_percision) {
    System::m_from_x = _from_x;
    System::m_to_x = _to_x;
    System::m_from_y = _from_y;
    System::m_to_y = _to_y;
    System::m_grid_percision = _grid_percision;
}