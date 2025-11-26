#include <GL/freeglut.h> // G³ówny nag³ówek FreeGLUT

// Funkcja odpowiedzialna za rysowanie klatki
void display() {
    // Wyczyœæ bufor koloru (t³o)
    glClear(GL_COLOR_BUFFER_BIT);

    // Ustaw kolor rysowania na bia³y
    glColor3f(1.0, 1.0, 1.0);

    // Narysuj "druciany" czajniczek (funkcja specyficzna dla GLUT)
    // Rozmiar 0.5
    glutWireTeapot(0.5);

    // Wymuœ wykonanie poleceñ OpenGL (opró¿nij bufory)
    glFlush();
}

int main(int argc, char** argv) {
    // 1. Inicjalizacja biblioteki GLUT
    glutInit(&argc, argv);

    // 2. Ustawienia trybu wyœwietlania (pojedynczy bufor, kolory RGB)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // 3. Ustawienia okna
    glutInitWindowSize(500, 500);      // Rozmiar okna w pikselach
    glutInitWindowPosition(100, 100);  // Pozycja okna na ekranie
    glutCreateWindow("Test FreeGLUT 3.0.0"); // Tytu³ okna

    // 4. Rejestracja funkcji wyœwietlaj¹cej (callback)
    glutDisplayFunc(display);

    // 5. Opcjonalnie: Ustawienie koloru t³a (czarny)
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // 6. Wejœcie w pêtlê g³ówn¹ GLUT
    glutMainLoop();

    return 0;
}