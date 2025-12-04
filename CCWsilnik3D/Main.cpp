#include <GL/freeglut.h>
#include <iostream>
#include <vector>

class PrimitivesRenderer {
public:
    const std::vector<float> vertices = {
        0.0f, 0.0f, 0.0f,
        1.5f, 0.0f, 0.0f,
        1.0f, 1.5f, 0.0f,
        -1.0f, 1.5f, 0.0f,
        -1.5f, 0.0f, 0.0f
    };

    const std::vector<float> colors = {
        1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f
    };

    void Draw() {
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);

        glVertexPointer(3, GL_FLOAT, 0, vertices.data());
        glColorPointer(3, GL_FLOAT, 0, colors.data());

        glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size() / 3);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
    }
};

class IndexedCube {
private:
    static const float cube_vert[];
    static const float cube_norm[];
    static const float cube_cols[];
    static const unsigned char cube_ind[];
    static const int indices_count;

public:
    void Draw() {
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);

        glVertexPointer(3, GL_FLOAT, 0, cube_vert);
        glNormalPointer(GL_FLOAT, 0, cube_norm);
        glColorPointer(3, GL_FLOAT, 0, cube_cols);

        glDrawElements(GL_TRIANGLES, indices_count, GL_UNSIGNED_BYTE, cube_ind);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
    }
};

const float IndexedCube::cube_vert[] = {
    -1.0f, -1.0f,  1.0f,   1.0f, -1.0f,  1.0f,   1.0f,  1.0f,  1.0f,  -1.0f,  1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,  -1.0f,  1.0f, -1.0f,   1.0f,  1.0f, -1.0f,   1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,  -1.0f,  1.0f,  1.0f,   1.0f,  1.0f,  1.0f,   1.0f,  1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,   1.0f, -1.0f, -1.0f,   1.0f, -1.0f,  1.0f,  -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,   1.0f,  1.0f, -1.0f,   1.0f,  1.0f,  1.0f,   1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,  -1.0f, -1.0f,  1.0f,  -1.0f,  1.0f,  1.0f,  -1.0f,  1.0f, -1.0f
};

const float IndexedCube::cube_norm[] = {
     0.0f,  0.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  0.0f,  1.0f,
     0.0f,  0.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  0.0f, -1.0f,
     0.0f,  1.0f,  0.0f,   0.0f,  1.0f,  0.0f,   0.0f,  1.0f,  0.0f,   0.0f,  1.0f,  0.0f,
     0.0f, -1.0f,  0.0f,   0.0f, -1.0f,  0.0f,   0.0f, -1.0f,  0.0f,   0.0f, -1.0f,  0.0f,
     1.0f,  0.0f,  0.0f,   1.0f,  0.0f,  0.0f,   1.0f,  0.0f,  0.0f,   1.0f,  0.0f,  0.0f,
    -1.0f,  0.0f,  0.0f,  -1.0f,  0.0f,  0.0f,  -1.0f,  0.0f,  0.0f,  -1.0f,  0.0f,  0.0f
};

const float IndexedCube::cube_cols[] = {
    1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f,  1.0f, 0.0f, 1.0f,  1.0f, 0.0f, 1.0f,  1.0f, 0.0f, 1.0f
};

const unsigned char IndexedCube::cube_ind[] = {
    0, 1, 2,   2, 3, 0,
    4, 5, 6,   6, 7, 4,
    8, 9, 10,  10, 11, 8,
    12, 13, 14, 14, 15, 12,
    16, 17, 18, 18, 19, 16,
    20, 21, 22, 22, 23, 20
};

const int IndexedCube::indices_count = sizeof(IndexedCube::cube_ind) / sizeof(IndexedCube::cube_ind[0]);

class Engine {
private:
    int windowWidth, windowHeight;
    std::string windowTitle;
    int targetFPS;
    float currentRotation;
    bool isPerspective;
    int activeDemo;

    IndexedCube cube;
    PrimitivesRenderer primitiveTester;

    static Engine* instance;

public:
    Engine()
        : windowWidth(800), windowHeight(600), windowTitle("CCW Silnik 3D"),
        targetFPS(60), currentRotation(0.0f), isPerspective(true), activeDemo(0) {
        instance = this;
    }

    void Init(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(windowWidth, windowHeight);
        glutInitWindowPosition(100, 100);
        glutCreateWindow(windowTitle.c_str());

        InitLighting();

        glEnable(GL_DEPTH_TEST);
        SetClearColor(0.2f, 0.2f, 0.2f, 1.0f);

        glutDisplayFunc(DisplayWrapper);
        glutReshapeFunc(ReshapeWrapper);
        glutKeyboardFunc(KeyboardWrapper);
        glutTimerFunc(1000 / targetFPS, TimerWrapper, 0);

        glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    }

    void InitLighting() {
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        GLfloat light_pos[] = { 2.0f, 2.0f, 2.0f, 0.0f };
        GLfloat light_amb[] = { 0.3f, 0.3f, 0.3f, 1.0f };
        GLfloat light_dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };

        glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);

        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    }

    void SetClearColor(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
    }

    void Run() {
        glutMainLoop();
    }

private:
    void Update() {
        currentRotation += 1.0f;
        if (currentRotation > 360.0f) currentRotation -= 360.0f;
        glutPostRedisplay();
    }

    void Render() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        if (isPerspective) {
            gluLookAt(0, 3, 6, 0, 0, 0, 0, 1, 0);
        }

        glPushMatrix();
        glRotatef(currentRotation, 0.5f, 1.0f, 0.0f);

        if (activeDemo == 0) {
            cube.Draw();
        }
        else {
            glDisable(GL_LIGHTING);
            primitiveTester.Draw();
            glEnable(GL_LIGHTING);
        }

        glPopMatrix();
        glutSwapBuffers();
    }

    void HandleKeyboard(unsigned char key, int x, int y) {
        switch (key) {
        case 27: glutLeaveMainLoop(); break;
        case ' ':
            isPerspective = !isPerspective;
            SetupProjection(windowWidth, windowHeight);
            std::cout << "Zmiana rzutowania." << std::endl;
            break;
        case '1':
            activeDemo = 0;
            std::cout << "Tryb: Szescian (glDrawElements)" << std::endl;
            break;
        case '2':
            activeDemo = 1;
            std::cout << "Tryb: Prymitywy (glDrawArrays)" << std::endl;
            break;
        }
    }

    void SetupProjection(int w, int h) {
        if (h == 0) h = 1;
        float ratio = (float)w / h;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        if (isPerspective)
            gluPerspective(45.0f, ratio, 0.1f, 100.0f);
        else {
            if (w >= h) glOrtho(-3.0 * ratio, 3.0 * ratio, -3.0, 3.0, 0.1, 100.0);
            else glOrtho(-3.0, 3.0, -3.0 / ratio, 3.0 / ratio, 0.1, 100.0);
        }
        glMatrixMode(GL_MODELVIEW);
    }

    static void DisplayWrapper() { if (instance) instance->Render(); }
    static void ReshapeWrapper(int w, int h) {
        if (instance) {
            instance->windowWidth = w;
            instance->windowHeight = h;
            glViewport(0, 0, w, h);
            instance->SetupProjection(w, h);
        }
    }
    static void KeyboardWrapper(unsigned char k, int x, int y) { if (instance) instance->HandleKeyboard(k, x, y); }
    static void TimerWrapper(int v) {
        if (instance) {
            instance->Update();
            glutTimerFunc(1000 / instance->targetFPS, TimerWrapper, 0);
        }
    }
};

Engine* Engine::instance = nullptr;

int main(int argc, char** argv) {
    Engine gameEngine;
    gameEngine.Init(argc, argv);

    std::cout << "=== INSTRUKCJA ===" << std::endl;
    std::cout << "[1] - Pokaz szescian indeksowany" << std::endl;
    std::cout << "[2] - Pokaz prymitywy glDrawArrays" << std::endl;
    std::cout << "[SPACJA] - Zmiana rzutowania" << std::endl;
    std::cout << "[ESC] - Wyjscie" << std::endl;

    gameEngine.Run();
    return 0;
}