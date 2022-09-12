/*
/ William Abbot
/ prove 90 degrees.cpp 
/
/ Say you have 2 parallel lines and a tansversal through them, 
/ then two more parallel lines intersecting those @ 90 
/ degrees. I want to prove that those second pair of parallel 
/ lines will always form 90 degree angles with first set of 
/ parallel lines on whatever angle not influenced by the 
/ tansversal.
*/

#include <windows.h>  // For MS Windows
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h

typedef int angle;


 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
}