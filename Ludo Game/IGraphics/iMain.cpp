#include "iGraphics.h"

int x = 300, y = 300, r =15;
int dd = 0;
int fu=0;
int c[3][3] = {{400, 500}, {500}};

int q, w;

/* 
	function iDraw() is called again and again by the system.
	
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	
	iSetColor(20,200,255);


	iFilledRectangle(c[0][0],y,50, 50);

	iFilledRectangle(c[1][0],y,50, 50);

	iFilledRectangle(300 + 300,y,50, 50);

	iFilledRectangle(300 + 400,y,50, 50);

	iFilledRectangle(300 + 500,y,50, 50);

	iFilledRectangle(300 + 200,y-100,50, 50);

	iFilledRectangle(300 + 300,y-100,50, 50);

	iFilledRectangle(300 + 400,y-100,50, 50);

	iFilledRectangle(300 + 500,y-100,50, 50);


}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)

{
	int static dd = 1;
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		dd=1;
		if(dd==1){
		if(mx >= c[0][0] && my >= 300 && mx <= c[0][0] + 100 && my <= 350){
		
			//x = x -100;
			c[0][0] = c[0][q + w];
			printf("done 1st click \n");
			q = q + w;
			w=1;
			//x=x+100;
			fu=0;
			dd=0;		
		}
	}
		else if(dd==1){
			//if(fu==0){

			if(mx >= 500 && my >= 300 && mx <= 550 && my <= 350){

				printf("Done 2nd click");
				fu = 1;
				dd=1;
				//fu=0;
			}
			}
		//}
		//}

			//if(dd==3){
	/*	if(mx >= 600 && my >= 300 && mx <= 650 && my <= 350){
		
			x = x -100;
			printf("done 3rd click \n");
			fu=2;
			dd=1;		
		}
	//}

		//if(dd==4){
			if(mx >= 700 && my >= 300 && mx <= 750 && my <= 350){

				printf("done 4th click");
				//fu = 1;
				dd=1;
				fu=0;
			}

			if(mx >= 800 && my >= 300 && mx <= 850 && my <= 350){

				printf("done 5thth click");
				//fu = 1;
				dd=3;
				fu=0;
			}
			}
		}

	/*if(dd==3){
		if(mx >= 400 && my >= 300 && mx <= 450 && my <= 350){
		
			//x = x -100;
			printf(" second done 1st click \n");
			fu=1;
			dd=2;		
		}
	}*/


	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}

	//dd++;
	//printf(" last click dd = %d\n", dd);
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.	
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}


int main()
{
	//place your own initialization codes here. 	
	iInitialize(1000, 500, "demooo");
	return 0;
}	