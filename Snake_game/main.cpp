



#define _CRT_NONSTDC_NO_DEPRECATE
#include<Windows.h>
#include <stdlib.h>    
#include <GL/glut.h>   
#include "game.h"



#define CULOMNS 40
#define ROWS 40
#define FPS 10

extern short sDirection;
bool gameOver = false;
int score = 0;

void display();
void reshape(int ,int);
void timer(int);
void keyboard(int, int, int);
void init ()
{
	glClearColor(0.94, 0.85, 0.94, 0.0);

	initGrid(CULOMNS, ROWS);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Snake");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	glutSpecialFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
	}
void reshape(int w,int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,CULOMNS, 0.0,ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}
int index = 0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
	drawFood();
	glutSwapBuffers();
	if (gameOver)
	{
		char Score[10];
		
		_itoa_s(score, Score, size_t (10), 10);
		char text[50] = "your score is ";
		strcat_s(text,rsize_t(50),Score);
		MessageBox(NULL,text,"GAME OVER",0);
		exit(EXIT_SUCCESS);
		
	}
}
void timer(int x)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);
}
void keyboard(int key,int,int)
{
	switch (key)
	{
	 case GLUT_KEY_UP:
		 if(sDirection != DOWN)
			 sDirection = UP;
		break;
	 case GLUT_KEY_DOWN:
		 if (sDirection != UP)
			 sDirection = DOWN;
		 break;
	 case GLUT_KEY_RIGHT:
		 if (sDirection != LEFT)
			 sDirection = RIGHT;
		 break;
	 case GLUT_KEY_LEFT:
		 if (sDirection != RIGHT)
			 sDirection = LEFT;
		 break;
	}
}