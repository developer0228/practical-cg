/*Implement animation principles for any object*/
// By Onkar Shirke - S190538711
#include<windows.h>
#include <GL/glut.h>
#include <cmath>

// Global variables
GLfloat ballRadius = 0.2f; 
GLfloat ballX = 0.0f;      
GLfloat ballY = 0.0f;      
GLfloat ballXSpeed = 0.02f; 
GLfloat ballYSpeed = 0.0f;  
GLfloat gravity = -0.001f; 

// Initialize OpenGL
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();           

    glTranslatef(ballX, ballY, 0.0f);

    // Draw the ball
    glColor3f(1.0f, 0.0f, 0.0f); 
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180;
        glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
    }
    glEnd();

    glutSwapBuffers(); 
}

// Update function for animation
void update(int value) {
    ballX += ballXSpeed;
    ballY += ballYSpeed;

    ballYSpeed += gravity;

    if (ballX + ballRadius > 1.0f || ballX - ballRadius < -1.0f) {
        ballXSpeed = -ballXSpeed; 
    }
    if (ballY + ballRadius > 1.0f || ballY - ballRadius < -1.0f) {
        ballYSpeed = -ballYSpeed; 
    }

    glutPostRedisplay(); 
    glutTimerFunc(16, update, 0); 
}

// Reshape callback function
void reshape(int w, int h) {
    glViewport(0, 0, w, h); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(-1, 1, -1, 1, -1, 1); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(500, 500); 
    glutCreateWindow("Bouncing Ball Animation"); 
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape); 
    glutTimerFunc(16, update, 0); 
    initGL(); 
    glutMainLoop(); 
    return 0;
}
