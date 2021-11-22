#include<gl/glut.h>
#include<stdio.h>
#include<math.h>

//const int steps = 10;
//const float angle = 3.1415926 * 1.f / steps;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f;
	//sets the size of the point
	glPointSize(2.0);
	//type of object
	glBegin(GL_QUADS);
	glVertex2f(4.0, 2.0);
	glVertex2f(4.0, 1.0);
	glVertex2f(-4.0, 1.0);
	glVertex2f(-4.0, 2.0);
	glEnd();


	glBegin(GL_QUADS);
	glVertex2f(3.0, 1.0);
	glVertex2f(3.0, -1.5);
	glVertex2f(-3.0, -1.5);
	glVertex2f(-3.0, 1.0);
	glEnd();

	//dome roof
	/*
	float xPos = 0;
	float yPos = 0;
	float radius = 1.0f;
	float prevX = xPos;
	float prevY = yPos - radius;

	for (int i = 0; i <= steps; i++) {
		float newX = radius * sin(angle*i);
		float newY = -radius * cos(angle*i);
		glBegin(GL_TRIANGLES);
		glVertex2f(-3.0f, 2.0f);
		glVertex2f(prevX, prevY);
		glVertex2f(newX, newY);
		glEnd();

		prevX = newX;
		prevY = newY;

	}

	*/
    //semicircular roof
		//fix variable naming
	float centerx = 0.0;//x axis center
	float centery = 0.0;//y axis center
	float roofr = 100;//radius
	float roofd = 200;//diameter
	float PI = 3.141592653589793238f;
	float semicircleangle = PI * 1.0f;
	int steps = 100;

	/*
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < steps; i++) {
		float theta = semicircleangle * float(i) / float(steps);//get the current angle 
		float x = roofr * cosf(theta);//calculate the x component 
		float y = roofr * sinf(theta);//calculate the y component 
		glVertex2f(x + centerx, y + centery);//output vertex 
	}
	glEnd();

	//door
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, -1.5);
	glVertex2f(-0.5, -1.5);
	glVertex2f(-0.5, 0.0);
	glEnd();

	//windows
	//partition 1
	glBegin(GL_QUADS);
	glColor3f(0.1, 0, 0);
	glVertex2f(-2.5, 0.5);
	glVertex2f(-2.0, 0.5);
	glVertex2f(-2.0, 0.0);
	glVertex2f(-2.5, 0.0);
	glEnd();

	//lines
	/*
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(-2.5, 0.5);
	glVertex2f(-2.0, 0.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-2.0, 0.5);
	glVertex2f(-2.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-2.5, 0.0);
	glVertex2f(-2.5, 0.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-2.5, 0.0);
	glVertex2f(-2.0, 0.0);
	glEnd();
	*/


	//partition 2
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(-2.0, 0.5);
	glVertex2f(-1.5, 0.5);
	glVertex2f(-1.5, 0.0);
	glVertex2f(-2.0, 0.0);
	glEnd();

	//partition 3
	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex2f(-1.5, 0.0);
	glVertex2f(-1.5, -0.5);
	glVertex2f(-2.0, -0.5);
	glVertex2f(-2.0, 0.0);
	glEnd();

	//partition 4
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex2f(-2.0, 0.0);
	glVertex2f(-2.0, -0.5);
	glVertex2f(-2.5, -0.5);
	glVertex2f(-2.5, 0.0);
	glEnd();

	

	//Window 2
	//partition 1
	glBegin(GL_QUADS);
	glColor3f(0.1, 0.0, 1.0);
	glVertex2f(2.0, 0.5);
	glVertex2f(2.0, 0.0);
	glVertex2f(1.5, 0.0);
	glVertex2f(1.5, 0.5);
	glEnd();

	//partition 2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(2.5, 0.5);
	glVertex2f(2.5, 0.0);
	glVertex2f(2.0, 0.0);
	glVertex2f(2.0, 0.5);
	glEnd();

	//partition 3
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(2.5, 0.0);
	glVertex2f(2.5, -0.5);
	glVertex2f(2.0, -0.5);
	glVertex2f(2.0, 0.0);
	glEnd();

	//partition 4
	glBegin(GL_QUADS);
	glColor3f(0.1, 0.0, 0.0);
	glVertex2f(2.0, 0.0);
	glVertex2f(2.0, -0.5);
	glVertex2f(1.5, -0.5);
	glVertex2f(1.5, 0.0);
	glEnd();

	glFlush();
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(800, 800);
	glutCreateWindow("HouseGL");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}