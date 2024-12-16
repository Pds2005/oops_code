#include <gl glut.h=""> 
#include <iostream> 
  
float angleX = 0.0f, angleY = 0.0f, angleZ = 0.0f; // Rotation angles 
float scale = 1.0f; // Scaling factor 
float translateX = 0.0f, translateY = 0.0f, translateZ = -5.0f; // Translation values 
  
// Function to draw the cube with different colored faces 
void drawCube() { 
     glBegin(GL_QUADS); 
   
     // Front face (z = 1) 
     glColor3f(1.0f, 0.0f, 0.0f); // Red 
     glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom-left corner 
     glVertex3f(1.0f, -1.0f, 1.0f);  // Bottom-right corner 
     glVertex3f(1.0f, 1.0f, 1.0f);   // Top-right corner 
     glVertex3f(-1.0f, 1.0f, 1.0f);  // Top-left corner 
   
     // Back face (z = -1) 
     glColor3f(0.0f, 1.0f, 0.0f); // Green 
     glVertex3f(-1.0f, -1.0f, -1.0f); 
     glVertex3f(-1.0f, 1.0f, -1.0f); 
     glVertex3f(1.0f, 1.0f, -1.0f); 
     glVertex3f(1.0f, -1.0f, -1.0f); 
  
    // Left face (x = -1) 
    glColor3f(0.0f, 0.0f, 1.0f); // Blue 
    glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f(-1.0f, -1.0f, 1.0f); 
    glVertex3f(-1.0f, 1.0f, 1.0f); 
    glVertex3f(-1.0f, 1.0f, -1.0f); 
  
    // Right face (x = 1) 
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow 
    glVertex3f(1.0f, -1.0f, -1.0f); 
    glVertex3f(1.0f, 1.0f, -1.0f); 
    glVertex3f(1.0f, 1.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, 1.0f); 
  
    // Top face (y = 1) 
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta 
    glVertex3f(-1.0f, 1.0f, -1.0f); 
    glVertex3f(-1.0f, 1.0f, 1.0f); 
    glVertex3f(1.0f, 1.0f, 1.0f); 
    glVertex3f(1.0f, 1.0f, -1.0f); 
  
    // Bottom face (y = -1) 
     glColor3f(0.0f, 1.0f, 1.0f); // Cyan 
     glVertex3f(-1.0f, -1.0f, -1.0f); 
     glVertex3f(1.0f, -1.0f, -1.0f); 
     glVertex3f(1.0f, -1.0f, 1.0f); 
     glVertex3f(-1.0f, -1.0f, 1.0f); 
   
     glEnd(); 
 } 
   
 // Function to display the cube and apply transformations 
 void display() { 
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
     glLoadIdentity(); // Reset the modelview matrix 
   
     // Apply transformations 
     glTranslatef(translateX, translateY, translateZ); // Translation 
     glScalef(scale, scale, scale);                      // Scaling 
     glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Rotate around X-axis 
     glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotate around Y-axis 
     glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // Rotate around Z-axis 
   
     drawCube(); 
     glutSwapBuffers(); // Swap buffers for double buffering 
 } 
   
 // Timer function to update the cube's rotation 
 void timer(int value) { 
     angleX += 1.0f; 
     angleY += 1.0f; 
     angleZ += 1.0f; 
   
     glutPostRedisplay(); // Redraw the scene 
     glutTimerFunc(16, timer, 0); // Call timer again after 16 ms (60 FPS) 
 } 
   
 // Initialize OpenGL settings 
 void init() { 
     glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D effects 
     glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Set background color 
 } 
   
 // Main function to set up GLUT and OpenGL 
 int main(int argc, char** argv) { 
     glutInit(&argc, argv); 
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set display mode 
     glutInitWindowSize(800, 600); // Set window size 
   glutCreateWindow("3D Cube Transformations"); 
 
   init(); // Initialize OpenGL settings 
 
   glutDisplayFunc(display);  // Set the display function 
   glutTimerFunc(0, timer, 0); // Set the timer function 
      
    // Set up perspective projection 
    glMatrixMode(GL_PROJECTION); 
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f); // Field of view, aspect ratio, near/far planes 
    glMatrixMode(GL_MODELVIEW); // Switch back to modelview matrix 
  
    glutMainLoop(); // Enter the GLUT event loop 
    return 0; 
}
