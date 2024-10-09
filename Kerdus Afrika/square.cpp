#include <GL/glew.h>
#include <GL/freeglut.h>

float angle = 0.0f;

void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -15.0f);

    glRotatef(angle, 0.0f, 1.0f, 0.0f); //rotasi

    glColor3f(0.2, 0.2, 0.2);

    glBegin(GL_POLYGON); // depan
    glVertex3f(-5.0, -1.0, 3.0);
    glVertex3f(5.0, -1.0, 3.0);
    glVertex3f(5.0, 1.0, 3.0);
    glVertex3f(-5.0, 1.0, 3.0);
    glEnd();

    glBegin(GL_POLYGON); // belakang
    glVertex3f(-5.0, -1.0, -3.0);
    glVertex3f(5.0, -1.0, -3.0);
    glVertex3f(5.0, 1.0, -3.0);
    glVertex3f(-5.0, 1.0, -3.0);
    glEnd();

    glBegin(GL_POLYGON); // kiri
    glVertex3f(-5.0, -1.0, 3.0);
    glVertex3f(-5.0, -1.0, -3.0);
    glVertex3f(-5.0, 1.0, -3.0);
    glVertex3f(-5.0, 1.0, 3.0);
    glEnd();

    glBegin(GL_POLYGON); // kanan
    glVertex3f(5.0, -1.0, 3.0);
    glVertex3f(5.0, -1.0, -3.0);
    glVertex3f(5.0, 1.0, -3.0);
    glVertex3f(5.0, 1.0, 3.0);
    glEnd();

    glBegin(GL_POLYGON); // atas
    glVertex3f(-5.0, 1.0, 3.0);
    glVertex3f(5.0, 1.0, 3.0);
    glVertex3f(5.0, 1.0, -3.0);
    glVertex3f(-5.0, 1.0, -3.0);
    glEnd();

    glBegin(GL_POLYGON); // bawah
    glVertex3f(-5.0, -1.0, 3.0);
    glVertex3f(5.0, -1.0, 3.0);
    glVertex3f(5.0, -1.0, -3.0);
    glVertex3f(-5.0, -1.0, -3.0);
    glEnd();


    glColor3f(0.3, 0.3, 0.3);

    // Bagian luar handle (persegi panjang besar)
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 0.0, 3.3);
    glVertex3f(2.0, 0.0, 3.3);
    glVertex3f(2.0, 1.0, 3.3);
    glVertex3f(-2.0, 1.0, 3.3);
    glEnd();

    // Lubang handle (persegi panjang lebih kecil)
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-1.5, 0.3, 3.31);
    glVertex3f(1.5, 0.3, 3.31);
    glVertex3f(1.5, 0.8, 3.31);
    glVertex3f(-1.5, 0.8, 3.31);
    glEnd();

    glutSwapBuffers();
}


void update(int value)
{

    angle += 1.0f;
    if (angle > 360) {
        angle -= 360;
    }

    glutPostRedisplay();

    glutTimerFunc(16, update, 0);
}

void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glEnable(GL_DEPTH_TEST);
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Suitcase Model with Depth Testing");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glewExperimental = GL_TRUE;
    glewInit();
    setup();

    //  rotasi 
    glutTimerFunc(16, update, 0);

    glutMainLoop();
}
