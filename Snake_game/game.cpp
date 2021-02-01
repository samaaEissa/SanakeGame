#include <stdlib.h>    
#include <GL/glut.h>   
#include<ctime> 
#include <iostream>
#include <cstdlib>
#include "game.h"

extern int score;
int xgrid, ygrid;
int snake_length=5;
short sDirection = RIGHT;
extern bool gameOver;
bool food = true;
int foodx, foody;
int xpos[60] = { 20,20,20,20,20 };
int ypos[60] = { 20,19,18,17,16 };
void unit(int, int);

void initGrid(int x,int y)
{
	xgrid = x;
	ygrid = y;

}
void drawGrid()
{
	for(int x=0;x<xgrid;x++)
	{
	  for (int y=0;y<ygrid;y++)
	  {
		  unit(x,y);

	  }
	}
	
}
void unit(int x, int y)
{
	if (x == 0 || x == xgrid - 1 || y == 0 || y == ygrid - 1)
	{
		glLineWidth(3.0);
		glColor3f(0.56, 0.38, 0.56);

	}
	else {
		glLineWidth(1.0);
		glColor3f(0.66, 0.47, 0.85);
	}
						
	 glBegin(GL_LINE_LOOP); 
	 glVertex2f(x, y);
	 glVertex2f(x+1,y);
	 glVertex2f(x+1,y+1);
	 glVertex2f(x,y+1);
	 glEnd();
 }
void drawFood()
{
	if (food)
		random(foodx, foody);
	food = false;
	glColor3f(0.98, 0.76, 0.0);
	glRectf(foodx, foody, foodx+1, foody + 1);

}
void random(int &x, int &y)
{
	int mx = xgrid-2;
	int my = ygrid - 2;
	int n = 1;
	srand(time(NULL));
	x = n + rand() % (mx - n);
	y = n + rand() % (my - n);
	
}
void drawSnake()
{
	for (int i = snake_length; i > 0;i--)
	{ 
		xpos[i] = xpos[i - 1];
		ypos[i] = ypos[i - 1];
	}
	if (sDirection == UP)
		ypos[0]++;
	else if (sDirection == DOWN)
		ypos[0]--;
	else if (sDirection == LEFT)
		xpos[0]--;
	else if (sDirection == RIGHT)
		xpos[0]++;
	for (int i = 0; i < snake_length; i++)
	{
		if(i==0)
			glColor3f(0.89, 0.0, 0.89);
		else
			glColor3f(0.20, 0.78, 0.71);
		glRectd(xpos[i], ypos[i], xpos[i] + 1, ypos[i] + 1);
	}
	
	if (xpos[0] == 0 || xpos[0] == xgrid - 1 || ypos[0] == 0 || ypos[0] == ygrid - 1)
		gameOver = true;
	if (xpos[0] == foodx && ypos[0] == foody)
	{
		score++;
		snake_length++;
		if (snake_length > MAX)
			snake_length = MAX;
		food = true;
	}
		
}