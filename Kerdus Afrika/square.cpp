#include <GL/glew.h>
#include <GL/freeglut.h>

// Variabel untuk mengatur sudut rotasi
float angle = 0.0f;

void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear depth buffer as well

    // Reset transformasi
    glLoadIdentity();

    // Geser objek sedikit ke belakang
    glTranslatef(0.0f, 0.0f, -15.0f);

    // Terapkan rotasi otomatis
    glRotatef(angle, 0.0f, 1.0f, 0.0f);  // Rotasi searah sumbu Y

    // Set kerdus body color (abu-abu lebih gelap)
    glColor3f(0.2, 0.2, 0.2);

    // Draw suitcase body as a rectangular prism
    glBegin(GL_POLYGON); // Front face
    glVertex3f(-5.0, -1.0, 3.0);
    glVertex3f(5.0, -1.0, 3.0);
    glVertex3f(5.0, 1.0, 3.0);
    glVertex3f(-5.0, 1.0, 3.0);
    glEnd();

    glBegin(GL_POLYGON); // Back face
    glVertex3f(-5.0, -1.0, -3.0);
    glVertex3f(5.0, -1.0, -3.0);
    glVertex3f(5.0, 1.0, -3.0);
    glVertex3f(-5.0, 1.0, -3.0);
    glEnd();

    glBegin(GL_POLYGON); // Left face
    glVertex3f(-5.0, -1.0, 3.0);
    glVertex3f(-5.0, -1.0, -3.0);
    glVertex3f(-5.0, 1.0, -3.0);
    glVertex3f(-5.0, 1.0, 3.0);
    glEnd();

    glBegin(GL_POLYGON); // Right face
    glVertex3f(5.0, -1.0, 3.0);
    glVertex3f(5.0, -1.0, -3.0);
    glVertex3f(5.0, 1.0, -3.0);
    glVertex3f(5.0, 1.0, 3.0);
    glEnd();

    glBegin(GL_POLYGON); // Top face
    glVertex3f(-5.0, 1.0, 3.0);
    glVertex3f(5.0, 1.0, 3.0);
    glVertex3f(5.0, 1.0, -3.0);
    glVertex3f(-5.0, 1.0, -3.0);
    glEnd();

    glBegin(GL_POLYGON); // Bottom face
    glVertex3f(-5.0, -1.0, 3.0);
    glVertex3f(5.0, -1.0, 3.0);
    glVertex3f(5.0, -1.0, -3.0);
    glVertex3f(-5.0, -1.0, -3.0);
    glEnd();

    // Draw handle
    glColor3f(0.3, 0.3, 0.3); // Warna handle (abu-abu gelap)

    // Bagian luar handle (persegi panjang besar)
    glBegin(GL_POLYGON); // Bagian depan handle luar
    glVertex3f(-2.0, 0.0, 3.3);
    glVertex3f(2.0, 0.0, 3.3);
    glVertex3f(2.0, 1.0, 3.3);
    glVertex3f(-2.0, 1.0, 3.3);
    glEnd();

    // Lubang handle (persegi panjang lebih kecil)
    glColor3f(0.5, 0.5, 0.5); // Warna lubang (abu-abu terang)
    glBegin(GL_POLYGON); // Bagian depan lubang
    glVertex3f(-1.5, 0.3, 3.31); // Posisi lubang lebih kecil
    glVertex3f(1.5, 0.3, 3.31);
    glVertex3f(1.5, 0.8, 3.31);
    glVertex3f(-1.5, 0.8, 3.31);
    glEnd();

    glutSwapBuffers(); // Swap buffers for smooth rendering (double buffering)
}

// Fungsi untuk update rotasi secara terus-menerus
void update(int value)
{
    // Tambahkan sudut rotasi
    angle += 1.0f;
    if (angle > 360) {
        angle -= 360;
    }

    // Re-draw scene
    glutPostRedisplay();

    // Panggil update lagi setelah 16 ms (~60 fps)
    glutTimerFunc(16, update, 0);
}

void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // White background

    // Mengaktifkan depth testing
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Enable double buffering and depth
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Suitcase Model with Depth Testing");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glewExperimental = GL_TRUE;
    glewInit();
    setup();

    // Mulai rotasi otomatis
    glutTimerFunc(16, update, 0);

    glutMainLoop();
}
