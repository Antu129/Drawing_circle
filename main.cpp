#include<iostream>
#include<GL/glu.h>
#include<GL/glut.h>
using namespace std;

int pntx1,pnty1,r;


//for plotting a point in the graphics window
void plot(int x, int y)
{
    glBegin(GL_POINTS);
        glVertex2i(pntx1+x,pnty1+y);
    glEnd();
}


//function for circle(mid-point)
void midpoint_circle()
{
    int x=0;
    int y=r;

    //base case
    float decision = 5/4 - r;

    //first point
    plot(x,y);

    //iteration
    while(y>x)
    {
        //East operation
        if(decision<0.0)
        {
            x++;
            decision += 2*x+1;
        }
        //South-east operation
        else
        {
            y--;
            x++;
            decision += 2*(x-y)+1;
        }
        //as a circle is eight way symmetric
        //plotting the points of other quadrants
        plot(x,y);
        plot(x,-y);
        plot(-x,y);
        plot(-x,-y);
        plot(y,x);
        plot(-y,x);
        plot(y,-x);
        plot(-y,-x);
    }
}



void myInit()
{
        //background color
    glClearColor(0,0,0,1);
        //drawing color
    glColor3f(1.0,1.0,0.0);

    //clear the background
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(2);

    //specifying the current matrix
    //for applying subsequent matrix to the projection matrix
    glMatrixMode(GL_PROJECTION);

    //replacing the current matrix with the identity matrix/matrix reset
    glLoadIdentity();

    //setting up 2D orthographic viewing region
    gluOrtho2D(0.0,640.0,0.0,640);

}


//function for drawing in the window. should return nothing
void Draw()
{
    //plotting the circle using midpoint
    midpoint_circle();

    //push the code to the graphics window
    glFlush();
}



//main take two parameters- argument count and argument vector
int main(int argC, char *argV[])
{

    //console - for entering inputs for the drawing
    cout << "Enter the co-ordinate of the center: \n\n"<<endl;
    cout << "x co-ordinate: ";cin >> pntx1;
    cout << "y co-ordinate: ";cin >> pnty1;
    cout << "\nEnter the radius: ";cin >> r;

    //initialization function. parameter should be from main function
    glutInit(&argC,argV);

    //to create a window
        //mention the size and position
        //mention display mode and operation/buffer
        //create window
    glutInitWindowPosition(400,200);
    glutInitWindowSize(600,600);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Circle Drawing");

    myInit();

    //function inside the window(Display call back function)
    glutDisplayFunc(Draw);

    //starting point of the window operation. To keep on executing the window
    glutMainLoop();
   return 0;
}
