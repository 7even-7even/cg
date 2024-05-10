

// Bresenham's line drawing algorithm

#include <GL/glut.h>
#include <stdlib.h>
#include<iostream>
using namespace std;


void displayPoint(int x, int y)
{
   glColor3f(0, 1, 0);
   glPointSize(2);
   glBegin(GL_POINTS);
   glVertex2i(x, y);
   glEnd();
}

float x01, x2, y01, y2;
int ch;



void SimpleLine(float x1, float y1, float x2, float y2)
{
	float dx, dy, p;
	int i;
	float incx, incy, inc1, inc2;
	float x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
    {
        dx = -dx;
    }
	if (dy < 0)
    {
        dy = -dy;
    }
	incx = 1;
	if (x2 < x1)
    {
        incx = -1;
    }
	incy = 1;
	if (y2 < y1)
    {
        incy = -1;
	}
	x = x1;
	y = y1;
	if (dx > dy) {
		displayPoint(x, y);
		p = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++)
		{
			if (p >= 0)
			{
                x =x+incx;
				y = y+ incy;
				p =p+ inc1;
			}
			else
            {
                 x =x+incx;
                p =p+ inc2;

            }


			displayPoint(x, y);
		}
	}
	else
	{
		displayPoint(x, y);
		p = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++)
		{
			if (p >= 0)
			{
				x =x+ incx;
				y =y+ incy;
				p =p+ inc1;
			}
			else
            {
                p=p+inc2;
                y =y+ incy;
            }

			displayPoint(x, y);

		}
	}

glFlush();
}

void DottedLine(float x1, float y1, float x2, float y2)
{
   float dx, dy, p;
	int i;
	float incx, incy, inc1, inc2;
	float x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
    {
        dx = -dx;
    }
	if (dy < 0)
    {
        dy = -dy;
    }
	incx = 1;
	if (x2 < x1)
    {
        incx = -1;
    }
	incy = 1;
	if (y2 < y1)
    {
        incy = -1;
	}
	x = x1;
	y = y1;
	if (dx > dy) {
		displayPoint(x, y);
		p = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++)
		{
		    if(i%4==0)
            {

			if (p >= 0)
			{
                x =x+incx;
				y = y+ incy;
				p =p+ inc1;
			}
			else
            {
                 x =x+incx;
                p =p+ inc2;

            }


			displayPoint(x, y);
            }
            else
            {
               if (p >= 0)
			{
                x =x+incx;
				y = y+ incy;
				p =p+ inc1;
			}
			else
            {
                 x =x+incx;
                p =p+ inc2;

            }

            }
		}
	}
	else
	{
		displayPoint(x, y);
		p = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++)
		{
		    if(i%4==0)
            {

			if (p >= 0)
			{
				x =x+ incx;
				y =y+ incy;
				p =p+ inc1;
			}
			else
            {
                p=p+inc2;
                y =y+ incy;
            }

			displayPoint(x, y);
            }
            else
            {
              if (p >= 0)
			{
				x =x+ incx;
				y =y+ incy;
				p =p+ inc1;
			}
			else
            {
                p=p+inc2;
                y =y+ incy;
            }
            }

		}
	}
   glFlush();
}

void DashedLine(float x1, float y1, float x2, float y2)
{
   float dx, dy, p;
	int i;
	float incx, incy, inc1, inc2;
	float x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	int count=0;
	if (dx < 0)
    {
        dx = -dx;
    }
	if (dy < 0)
    {
        dy = -dy;
    }
	incx = 1;
	if (x2 < x1)
    {
        incx = -1;
    }
	incy = 1;
	if (y2 < y1)
    {
        incy = -1;
	}
	x = x1;
	y = y1;
	if (dx > dy)
    {
		displayPoint(x, y);
		p = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++)
		{
		    count++;
		    if(count<=7)
            {

                if (p >= 0)
                {
                    x =x+incx;
                    y = y+ incy;
                    p =p+ inc1;
                }
                else
                {
                    x =x+incx;
                    p =p+ inc2;

                }


                displayPoint(x, y);
            }
            else if(count<=10 && count>7)
            {
               if (p >= 0)
                {
                    x =x+incx;
                    y = y+ incy;
                    p =p+ inc1;
                }
                else
                {
                    x =x+incx;
                    p =p+ inc2;

                }


            }
            else
            {
                count=0;
                if (p >= 0)
                {
                    x =x+incx;
                    y = y+ incy;
                    p =p+ inc1;
                }
                else
                {
                    x =x+incx;
                    p =p+ inc2;

                }
            }

		}
	}
	else
	{
		displayPoint(x, y);
		p = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++)
		{
		    count++;
		    if(count<=7)
            {
                if (p >= 0)
                {
                    x =x+ incx;
                    y =y+ incy;
                    p =p+ inc1;
                }
                else
                {
                    p=p+inc2;
                    y =y+ incy;
                }

			displayPoint(x, y);
            }
            else if(count<=10 && count>7)
            {
               if (p >= 0)
                {
                    x =x+ incx;
                    y =y+ incy;
                    p =p+ inc1;
                }
                else
                {
                    p=p+inc2;
                    y =y+ incy;
                }

            }
            else
            {
                count=0;
                 if (p >= 0)
                {
                    x =x+ incx;
                    y =y+ incy;
                    p =p+ inc1;
                }
                else
                {
                    p=p+inc2;
                    y =y+ incy;
                }
            }

		}
	}

   glFlush();
}
void SolidLine(float x1, float y1, float x2, float y2)
{
  float dx, dy, p;
	int i;
	float incx, incy, inc1, inc2;
	float x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
    {
        dx = -dx;
    }
	if (dy < 0)
    {
        dy = -dy;
    }
	incx = 1;
	if (x2 < x1)
    {
        incx = -1;
    }
	incy = 1;
	if (y2 < y1)
    {
        incy = -1;
	}
	x = x1;
	y = y1;
	if (dx > dy) {
		glPointSize(5);
		glBegin(GL_POINTS);
                glVertex2i(x,y);
        glEnd();
		p = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++)
		{
			if (p >= 0)
			{
                x =x+incx;
				y = y+ incy;
				p =p+ inc1;
			}
			else
            {
                 x =x+incx;
                p =p+ inc2;

            }
            glPointSize(5);
		    glBegin(GL_POINTS);
                glVertex2i(x,y);
             glEnd();
		}
	}
	else
	{
		glPointSize(5);
		glBegin(GL_POINTS);
                glVertex2i(x,y);
        glEnd();
		p = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++)
		{
			if (p >= 0)
			{
				x =x+ incx;
				y =y+ incy;
				p =p+ inc1;
			}
			else
            {
                p=p+inc2;
                y =y+ incy;
            }

			glPointSize(5);
		     glBegin(GL_POINTS);
                glVertex2i(x,y);
             glEnd();

		}
	}

   glFlush();
}
void myMouse(int button, int state, int x, int y)
{
   static int xst, yst, pt = 0;
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
   {
      if (pt == 0)
      {
         xst = x;
         yst = y;
         x01 = xst;
         y01 = yst;
         pt = pt + 1;
      }
      else
      {
         x2 = x;
         y2 = y;
         if (ch == 1)
         {
            SimpleLine(xst, yst, x, y);
         }
         else if (ch == 2)
         {
            DottedLine(xst, yst, x, y);
         }
         else if (ch == 3)
         {
            DashedLine(xst, yst, x, y);
         }
         else if(ch==4)
         {

           SolidLine(xst,yst,x,y);
         }
         xst = x;
         yst = y;
      }
   }
   else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
      pt = 0;
   //Clear Screen
   glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 's':

      ch = 1;
      glutMouseFunc(myMouse);
      break;

   case 'd':

      ch = 2;
      glutMouseFunc(myMouse);
      break;

   case 'D':

      ch = 3;
      glutMouseFunc(myMouse);
      break;
   case 'S':
      ch=4;
      glutMouseFunc(myMouse);
      break;

   }
   glutPostRedisplay();
}
void initialize(void)
{
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT);
   // gluOrtho2D(l,r,b,t)
   gluOrtho2D(0, 600, 600, 0);
}
void primitives(void)
{
   //glClearColor(1.0, 1.0, 1.0, 1.0);
   //glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1, 0, 0);
   SimpleLine(0, 300, 600, 300);
   SimpleLine(300, 0, 300, 600);
   glutKeyboardFunc(keyboard);
}
int main(int argc,char **argv)
{

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE);
   glutInitWindowPosition(0, 0);
   glutInitWindowSize(600, 600);
   glutCreateWindow("Bresenham's LDA");
   initialize();
   cout<<"--------------------";
   cout<<"\ns. Simple Line";
   cout<<"\nd. Dotted Line";
  cout<<"\nD. Dashed Line";
  cout<<"\nS. Solid Line";
   cout<<"\n--------------------\n";
   glutDisplayFunc(primitives);
   glutMainLoop();
   return 0;
}

