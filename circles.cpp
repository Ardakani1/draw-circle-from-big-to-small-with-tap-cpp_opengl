#include <GL/glut.h>
#include <cmath>
#include <vector>

const double PI = 3.14;

int tedad_dayere = 48;
std::vector<int> kol_dayereha(48);
int avalin_dayere = 0;
int akharin_dayere = 47;
static float X = 50.0;
static float Y = 50.0;
int ghesmat = 85;

void drawCircle(float X, float Y, float shoa_dayere_bozorg, int ghesmat) {
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    for (int i = 0; i < ghesmat; i++) {
        float t = 2.0 * PI * i / ghesmat;
        glVertex3f(X + shoa_dayere_bozorg * cos(t), Y + shoa_dayere_bozorg * sin(t), 0.0);
    }
    glEnd();
}

void drawWhiteCircle(float X, float Y, float shoa_dayere_bozorg, int ghesmat) {
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < ghesmat; i++) {
        float t = 2.0 * PI * i / ghesmat;
        glVertex3f(X + shoa_dayere_bozorg * cos(t), Y + shoa_dayere_bozorg * sin(t), 0.0);
    }
    glEnd();
}

void circles() {
    glClear(GL_COLOR_BUFFER_BIT);

    // ترسیم دایره‌های سیاه قبلی
    for (int i = 0; i < 48; i++) {
        float shoa_dayere_bozorg = kol_dayereha[i];
        drawCircle(X, Y, shoa_dayere_bozorg, ghesmat);
    }

    // ترسیم دایره‌های سفید جدید
    for (int i = 1; i <= kol_dayereha[akharin_dayere]; ++i) {
        drawWhiteCircle(X, Y, i, ghesmat);
    }

    glutSwapBuffers();
    glFlush();
}

void setup() {
    glClearColor(0.1, 0.4, 0.5, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
}

void keyInput(unsigned char key, int x, int y) {
    if (key == ' ') {
        avalin_dayere++;
        kol_dayereha[avalin_dayere] = kol_dayereha[avalin_dayere - 1] - 1;

        if (kol_dayereha[avalin_dayere] == 1.0) {
            // اگر به دایره با شعاع 1 رسید، دوباره از ابتدا شروع کن
            avalin_dayere = 0;
            kol_dayereha[0] = tedad_dayere;
        }

        glutPostRedisplay();
    }
    else if (key == '-' && akharin_dayere >= 1) {
        akharin_dayere--;
        kol_dayereha[akharin_dayere] = kol_dayereha[akharin_dayere + 1] + 1.0;

        //if (kol_dayereha[akharin_dayere] == 48.0) {
        //    // اگر به دایره با شعاع 48 رسید، دوباره از ابتدا شروع کن
        //    avalin_dayere = 0;
        //    kol_dayereha[0] = tedad_dayere;
        //}

        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hey roozegar");

    glutDisplayFunc(circles);
    glutKeyboardFunc(keyInput);
    setup();

    kol_dayereha[0] = tedad_dayere;
    glutMainLoop();

    return 0;
}
