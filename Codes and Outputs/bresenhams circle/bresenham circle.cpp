/*Problem Statement :
Implement Bresenham circle drawing algorithm to draw any object. The object should be
displayed in all the quadrants with respect to center and radius */
// By Onkar Shirke - S190538711

#include<windows.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <cmath>

using namespace std;

GLint xi, yi, r;

void setPixel(GLint x, GLint y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawCirclePoints(GLint x, GLint y) {
    setPixel(xi + x, yi + y);
    setPixel(xi - x, yi + y);
    setPixel(xi + x, yi - y);
    setPixel(xi - x, yi - y);
    setPixel(xi + y, yi + x);
    setPixel(xi - y, yi + x);
    setPixel(xi + y, yi - x);
    setPixel(xi - y, yi - x);
}

void drawCircle() {
    GLint x = 0;
    GLint y = r;
    GLint d = 3 - 2 * r;
    drawCirclePoints(x, y);
    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        drawCirclePoints(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red color
    drawCircle();
    glFlush();
}

void initialize() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    gluOrtho2D(0, 800, 0, 600); // Set the coordinate system
}

int main(int argc, char** argv) {
    cout << "Enter the center coordinates (x, y): ";
    cin >> xi >> yi;
    cout << "Enter the radius of the circle: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600); // Set the window size
    glutInitWindowPosition(100, 100); // Set the window position
    glutCreateWindow("Bresenham Circle Drawing");

    initialize();
    glutDisplayFunc(display); // Register display callback function

    glutMainLoop(); // Enter the event-processing loop

    return 0;
}
