#include "iGraphics.h"
#include "gl.h"
#include <stdlib.h>

int x = 0, y = 0, w = 0, h = 0 ;
double  x2=0, y2 = 0;
int j, i=0, p=0;
int cx = 0, cy = 0;
int dice=1;
int rd, gn, bl, qw;
int yl1=0, yl2=0, yl4=0, yl3=0;
int bl1=0, bl2=0, bl4=0, bl3=0;
int rd1=0, rd2=0, rd4=0, rd3=0;
int gr1=0, gr2=0, gr4=0, gr3=0;
int r = 17;
int turn = 0;
int turndq=0, turndw=0, turnde=0;
int gameplay = 0;
int win =0;
int count;

int cir[4][13] = {{1, 0, 92, 167, 0, 167, 167, 0, 92, 92, 0, 167, 92},
{2, 0, 92, 607, 0, 167, 607, 0, 92, 532, 0, 167, 532},
{3, 0, 532, 607, 0, 607, 607, 0, 532, 532, 0, 607, 532},
{4, 0, 532, 167, 0, 607, 167, 0, 532, 92, 0, 607, 92}};


int cir_x[4][57] = {{290, 290, 290, 290, 290, 237, 194, 151, 108, 65, 22, 22, 22, 65, 108, 151, 194, 237, 290, 290, 290, 290, 290, 290,350, 410, 410, 410,
	410, 410, 410, 462, 505, 548, 591, 634, 677, 677, 677, 634, 591, 548, 505, 462, 410, 410, 410, 410, 410, 410, 350, 350, 350, 350, 350, 350, 350},
{65, 108, 151, 194, 237, 290, 290, 290, 290, 290, 290,350, 410, 410, 410, 410, 410, 410, 462, 505, 548, 591,634, 677, 677, 677, 634,
591, 548, 505, 462, 410, 410, 410, 410, 410, 410, 350, 290,290, 290, 290, 290, 290, 237, 194, 151, 108, 65, 22, 22, 65, 108, 151, 194, 237, 290 },
{410, 410, 410, 410, 410, 462, 505, 548, 591, 634, 677, 677, 677, 634, 591, 548, 505, 462, 410, 410, 410, 410, 410, 410, 350,
290, 290, 290, 290, 290, 290, 237, 194, 151, 108, 65, 22, 22, 22, 65, 108, 151, 194, 237, 290, 290, 290, 290, 290, 290, 350, 350, 350, 350, 350, 350, 350},
{634, 591, 548, 505, 462, 410, 410, 410, 410, 410, 410, 350, 290, 290, 290, 290, 290, 290, 237, 194, 151, 108, 65, 22, 22, 22, 65,
108, 151, 194, 237, 290, 290, 290, 290, 290, 290,350, 410, 410, 410, 410, 410, 410, 462, 505, 548, 591, 634, 677, 677, 634, 591, 548, 505, 462, 410}};

int cir_y[4][57] = {{65, 108, 151, 194, 237, 290, 290, 290, 290, 290, 290, 350, 410, 410, 410, 410, 410, 410, 462, 505, 548, 591, 634, 677, 677, 677, 634,
	591, 548, 505, 462, 410, 410, 410, 410, 410, 410, 350, 290, 290, 290, 290, 290, 290, 237, 194, 151, 108, 65, 22, 22, 65, 108, 151, 194, 237, 290},
{410, 410, 410, 410, 410, 462, 505, 548, 591, 634, 677, 677, 677, 634, 591, 548, 505, 462, 410, 410, 410, 410, 410, 410, 350, 290,
290, 290, 290, 290, 290, 237, 194, 151, 108, 65, 22, 22, 22, 65, 108, 151, 194, 237, 290, 290, 290, 290, 290, 290, 350, 350, 350, 350, 350, 350, 350},
{634,591, 548, 505, 462, 410, 410, 410, 410, 410, 410, 350, 290, 290, 290, 290, 290, 290, 237, 194, 151, 108, 65, 22, 22, 22,65, 108,
151, 194, 237, 290, 290, 290, 290, 290, 290, 350, 410, 410, 410, 410, 410, 410, 462, 505, 548, 591, 634, 677, 677, 634,591, 548, 505, 462, 410},
{ 290, 290, 290, 290, 290, 237, 194, 151, 108, 65, 22, 22, 22, 65, 108, 151, 194, 237, 290, 290, 290, 290, 290, 290, 350, 410,
410, 410, 410, 410, 410, 462, 505, 548, 591, 634, 677, 677, 677, 634, 591, 548, 505, 462, 410, 410, 410, 410, 410, 410, 350, 350, 350, 350, 350, 350, 350}};

int player_turn=0;
int turndx = 0, turndy=0;
int turn1=0, turn2=0, turn3 =0, turn4=0;

int xx, yy, cxx, cyy, yl;

int countMainMenu=1,countMainGame,PlayNow,countBack2MainMenu,countInstructions,countHighScore;





int random()
{
	time_t t;
	srand((unsigned) time(&t));
	dice = rand() % 6 + 1;
	return dice;

}

void DrawBoard()
{
	iSetColor(500,500,500);
	iFilledRectangle(x, y, 1000, 700);

	iSetColor(500,500,0);
	iFilledRectangle(x, y, 260, 260);//1

	iSetColor(0, 500, 0);
	iFilledRectangle(440, y, 260, 260);//4

	iSetColor(0, 100, 500);
	iFilledRectangle(x, y + 440, 260, 260);//2

	iSetColor(500, 0, 0);
	iFilledRectangle(440, y+ 440, 260, 260);//3

	iSetColor(500,500,500);
	iFilledRectangle(40, 40, 180, 180);//1s
	iFilledRectangle(440 + 40, y + 40, 180, 180);//4s
	iFilledRectangle(x + 40, y + 440 + 40, 180, 180);//2s
	iFilledRectangle(x + 440 + 40, y + 440 + 40, 180, 180);//3s

	iSetColor(500,500,0);
	iFilledRectangle(40 + 30, 40 + 30, 45, 45);//1ss1
	iFilledRectangle(40 + 30 + 75, 40 + 30, 45, 45);//1ss3
	iFilledRectangle(40 + 30, 40 + 30 + 75, 45, 45);//1ss2
	iFilledRectangle(40 + 30 + 75, 40 + 30 + 75, 45, 45);//1ss4

	iSetColor(0,500,0);
	iFilledRectangle(440 + 40 + 30, y + 40 + 30, 45, 45);//4ss1
	iFilledRectangle(440 + 40 + 30 + 75, y + 40 + 30, 45, 45);//4ss3
	iFilledRectangle(440 + 40 + 30, y + 40 + 30 + 75, 45, 45);//4ss2
	iFilledRectangle(440 + 40 + 30 + 75, y + 40 + 30 + 75, 45, 45);//4ss4

	iSetColor(0,100,500);
	iFilledRectangle(x + 40 + 30, y + 440 + 40 + 30, 45, 45);//2ss1
	iFilledRectangle(x + 40 + 30 + 75, y + 440 + 40 + 30, 45, 45);//2ss3
	iFilledRectangle(x + 40 + 30, y + 440 + 40 + 30 + 75, 45, 45);//2ss2
	iFilledRectangle(x + 40 + 30 + 75, y + 440 + 40 + 30 + 75, 45, 45);//2ss4

	iSetColor(500,0,0);
	iFilledRectangle(x + 440 + 40 + 30, y + 440 + 40 + 30, 45, 45);//3ss1
	iFilledRectangle(x + 440 + 40 + 30 + 75, y + 440 + 40 + 30, 45, 45);//3ss3
	iFilledRectangle(x + 440 + 40 + 30, y + 440 + 40 + 30 + 45 + 30, 45, 45);//3ss2
	iFilledRectangle(x + 440 + 40 + 30 + 75, y + 440 + 40 + 30 + 45 + 30, 45, 45);//3ss4

	iSetColor(0, 100, 500);
	iFilledRectangle(43, y + 260 + 60, 217, 60);//1-2lcol
	iFilledRectangle(43, y + 260 + 120, 44, 60);//1-2scol

	iSetColor(500, 500, 0);
	iFilledRectangle(260 + 60, y + 43 , 60, 217);//1-4lcol
	iFilledRectangle(260, y + 43 , 60, 43);//1-4scol

	iSetColor(500, 0, 0);
	iFilledRectangle(260 + 60, y + 440, 60, 217);//2-3lcol
	iFilledRectangle(260 + 120, y + 440 + 173, 60, 44);//2-3scol

	iSetColor(0, 500, 0);
	iFilledRectangle(440, y + 260 + 60, 217, 60);//4-3lcol
	iFilledRectangle(440 + 173, y + 260, 44, 60);//4-3scol

	iSetColor(0, 0, 0);
	iFilledRectangle(x, y + 260, 260, 3);//1-2w
	iFilledRectangle(x, y + 260 + 60, 260, 3);//1-2w
	iFilledRectangle(x, y + 260 + 120, 260, 3);//1-2w
	iFilledRectangle(x, y + 260 + 180, 260, 3);//1-2w

	iFilledRectangle(x, y, 6, 700);//1-2h
	iFilledRectangle(x + 43, y + 260, 3, 180);//1-2h
	iFilledRectangle(x + 43 + 44, y + 260, 3, 180);//1-2h
	iFilledRectangle(x +130 , y + 260, 3, 180);//1-2h
	iFilledRectangle(x + 173, y + 260, 3, 180);//1-2h
	iFilledRectangle(x + 216, y + 260, 3, 180);//1-2h

	iFilledRectangle(x + 440, y + 260, 260, 3);//3-4w
	iFilledRectangle(x + 440, y + 260 + 60, 260, 3);//3-4w
	iFilledRectangle(x + 440, y + 260 + 120, 260, 3);//3-4w
	iFilledRectangle(x + 440, y + 260 + 180, 260, 3);//3-4w

	iFilledRectangle(x + 440, y + 260, 3, 180);//3-4h
	iFilledRectangle(x + 440 + 44, y + 260, 3, 180);//3-4h
	iFilledRectangle(x + 440 + 44 + 43, y + 260, 3, 180);//3-4h
	iFilledRectangle(x + 440 + 130, y + 260, 3, 180);//3-4h
	iFilledRectangle(x + 440 + 173, y + 260, 3, 180);//3-4h
	iFilledRectangle(x + 440 + 217 ,  y + 260, 3, 180);//3-4h
	iFilledRectangle(x + 440 + 260, y, 6, 700);//3-4h

	iFilledRectangle(x + 260, y, 3, 260);//1-4h
	iFilledRectangle(x + 260 + 60, y, 3, 260);//1-4h
	iFilledRectangle(x + 260 + 120, y, 3, 260);//1-4h
	iFilledRectangle(x + 260 + 180, y, 3, 260);//1-4h

	iFilledRectangle(x, y, 700, 6);//1-4w
	iFilledRectangle(x + 260, y + 43, 180, 3);//1-4w
	iFilledRectangle(x + 260, y + 86, 180, 3);//1-4w
	iFilledRectangle(x + 260, y + 130, 180, 3);//1-4w
	iFilledRectangle(x + 260, y + 173, 180, 3);//1-4w
	iFilledRectangle(x + 260, y + 216, 180, 3);//1-4w

	iFilledRectangle(x + 260, y + 440, 3, 260);//2-3h
	iFilledRectangle(x + 260 + 60, y + 440, 3, 260);//2-3h
	iFilledRectangle(x + 260 + 120, y + 440, 3, 260);//2-3h
	iFilledRectangle(x + 260 + 180, y + 440, 3, 260);//2-3h

	iFilledRectangle(x + 260, y + 440, 180, 3);//2-3w
	iFilledRectangle(x + 260, y + 440 + 44, 180, 3);//2-3h
	iFilledRectangle(x + 260, y + 440 + 87, 180, 3);//2-3w
	iFilledRectangle(x + 260, y + 440 + 130, 180, 3);//2-3w
	iFilledRectangle(x + 260, y + 440 + 173, 180, 3);//2-3w
	iFilledRectangle(x + 260, y + 440 + 217, 180, 3);//2-3w
	iFilledRectangle(x, y + 440 + 254, 700, 6);//2-3w

	//draw inner square
	double d[3] = {263, 260, 350};
	double s[3] = {263, 440, 350};
	iSetColor(0,100,500);
	iFilledPolygon(d, s,3);

	double dd[3] = {260, 440, 350};
	double ss[3] = {440, 440, 350};
	iSetColor(500,0,0);
	iFilledPolygon(dd,ss,3);

	double ddd[3] = {440, 440, 350};
	double sss[3] = {440, 260, 350};
	iSetColor(0,500,0);
	iFilledPolygon(ddd,sss,3);

	double dddd[3] = {440, 263, 350};
	double ssss[3] = {260, 263, 350};
	iSetColor(500,500,0);
	iFilledPolygon(dddd,ssss,3);

	iSetColor(0,0,0);
	iFilledRectangle(x + 260, y + 260, 3, 180);//1-2h
	iFilledRectangle(x + 260, y + 260 ,  180, 3);//1-4w

	double ddddd[4] = {260, 262, 438, 440};
	double sssss[4] = {438, 440, 260, 262};
	iFilledPolygon(ddddd,sssss,4);

	double dddddd[4] = {260, 262, 438, 440};
	double ssssss[4] = {262, 260, 440, 438};
	iFilledPolygon(dddddd,ssssss,4);
}

void Draw_dice_base()
{
	//iSetColor(200,200,200);
	iFilledRectangle(x +  800, 300, 80, 80);
	iSetColor(0,0,0);
	iRectangle(x +  800, 300, 80, 80);
}

void Draw_dice_base1()
{
	//iSetColor(200,200,200);
	iFilledRectangle(880, 300, 80, 80);
	iSetColor(0,0,0);
	iRectangle(880, 300, 80, 80);
}

void Draw_dice_circle()

{
	iSetColor(0,0,0);
	if(dice == 1){
		iFilledCircle(840 , 340, 7);
		PlaySound((LPCSTR)"1.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	

	else if(dice == 2){
		iFilledCircle(860-5, 320 + 5, 7);
		iFilledCircle(820 + 5, 360 + -5, 7);
		PlaySound((LPCSTR)"2.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

	else if(dice == 3){
		iFilledCircle(840, 340, 7);
		iFilledCircle(860, 320, 7);
		iFilledCircle(820, 360, 7);
		PlaySound((LPCSTR)"3.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

	else if(dice == 4){
		for(i=0; i<2; i++){
			for(j=0; j<2; j++){
				iFilledCircle(800 + 20 + 40*j, 300 + 60 - 40*i,   7);
			}
		}
		PlaySound((LPCSTR)"4.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

	else if(dice == 5){
		for(i=0; i<2; i++){
			for(j=0; j<2; j++){
				iFilledCircle(800 + 20 + 40*j, 300 + 60 - 40*i,   7);
			}
		}

		iFilledCircle(840, 340, 7);
		PlaySound((LPCSTR)"5.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

	else if(dice == 6){
		for(i=0; i<2; i++){
			for(j=0; j<3; j++){
				iFilledCircle(800 + 20 + 20*j, 300 + 60 - 40*i,   7);
			}
		}
		PlaySound((LPCSTR)"6.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

}

void Draw_dice_circle1()

{
	iSetColor(0,0,0);
	if(dice == 1){
		iFilledCircle(840 + 80 , 340, 7);
		PlaySound((LPCSTR)"1.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

	else if(dice == 2){
		iFilledCircle(860-5 + 80, 320 + 5, 7);
		iFilledCircle(820 + 5 + 80, 360 + -5, 7);
		PlaySound((LPCSTR)"2.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

	else if(dice == 3){
		iFilledCircle(840 + 80, 340, 7);
		iFilledCircle(860 + 80, 320, 7);
		iFilledCircle(820 + 80, 360, 7);
		PlaySound((LPCSTR)"3.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

	else if(dice == 4){
		for(i=0; i<2; i++){
			for(j=0; j<2; j++){
				iFilledCircle(800 + 20 + 40*j + 80, 300 + 60 - 40*i,   7);
			}
		}
		PlaySound((LPCSTR)"4.wav", NULL, SND_FILENAME | SND_ASYNC);

	}

	else if(dice == 5){
		for(i=0; i<2; i++){
			for(j=0; j<2; j++){
				iFilledCircle(800 + 20 + 40*j + 80, 300 + 60 - 40*i,   7);
			}
		}

		iFilledCircle(840 + 80, 340, 7);
		PlaySound((LPCSTR)"5.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

	else if(dice == 6){
		for(i=0; i<2; i++){
			for(j=0; j<3; j++){
				iFilledCircle(800 + 20 + 20*j + 80, 300 + 60 - 40*i,   7);
			}
		}
		PlaySound((LPCSTR)"6.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

}

void DrawCircles()
{
	//yellow
	iSetColor(550,150,0);

	iFilledCircle(cir[0][2], cir[0][3], 17);
	iFilledCircle(cir[0][5], cir[0][6], 17);
	iFilledCircle(cir[0][8], cir[0][9], 17);
	iFilledCircle(cir[0][11], cir[0][12], 17);

	//blue
	iSetColor(0,0,170);

	iFilledCircle(cir[1][2], cir[1][3], 17);
	iFilledCircle(cir[1][5], cir[1][6], 17);
	iFilledCircle(cir[1][8], cir[1][9], 17);
	iFilledCircle(cir[1][11], cir[1][12], 17);

	//red
	iSetColor(170,0,0);

	iFilledCircle(cir[2][2], cir[2][3], 17);
	iFilledCircle(cir[2][5], cir[2][6], 17);
	iFilledCircle(cir[2][8], cir[2][9], 17);
	iFilledCircle(cir[2][11], cir[2][12], 17);

	//green
	iSetColor(0,150,0);
	iFilledCircle(cir[3][2], cir[3][3], 17);
	iFilledCircle(cir[3][5], cir[3][6], 17);
	iFilledCircle(cir[3][8], cir[3][9], 17);
	iFilledCircle(cir[3][11], cir[3][12], 17);
}

void player()
{
	iSetColor(0,0,0);

	if(player_turn==0)
	{
		iText(800, 450, "Player 1 yellow turn",GLUT_BITMAP_HELVETICA_18 );

		iSetColor(500,500,0);
		Draw_dice_base();

		iSetColor(0,0,0);
		Draw_dice_circle();
	}

	if(player_turn==1)
	{
		iSetColor(0,100,500);
		Draw_dice_base1();

		iSetColor(0,0,0);
		Draw_dice_circle1();

		iSetColor(0,0,0);
		iText(800, 450, "Player 2 blue turn",GLUT_BITMAP_HELVETICA_18);
	}

	if(player_turn==2)
	{
		iSetColor(500,0,0);
		Draw_dice_base();

		iSetColor(0,0,0);
		Draw_dice_circle();

		iSetColor(0,0,0);
		iText(800, 450, "Player 3 red turn",GLUT_BITMAP_HELVETICA_18);
	}

	if(player_turn==3)
	{
		iSetColor(0,500,50);
		Draw_dice_base1();

		iSetColor(0,0,0);
		Draw_dice_circle1();

		iSetColor(0,0,0);
		iText(800, 450, "Player 4 green turn",GLUT_BITMAP_HELVETICA_18);
	}
}

void yellow_power(int xx, int yy)
{
	if(cir[0][xx] == cir_x[1][0] && cir[0][yy]==cir_y[1][0]){
		printf("will not go in");

	}

	else if(cir[0][xx] == cir_x[2][0] && cir[0][yy]==cir_y[2][0]){
		printf("will not go in");

	}

	else if(cir[0][xx] == cir_x[3][0] && cir[0][yy]==cir_y[3][0]){
		printf("will not go in");

	}

	else if(cir[0][xx]==cir[1][2] && cir[0][yy]==cir[1][3]){
		cir[1][2] = 92;
		cir[1][3] = 607;
		cir[1][1]= 0;
		bl1=0;
		//return 1;
	}

	else if(cir[0][xx]==cir[1][5] && cir[0][yy]==cir[1][6]){
		cir[1][5] = 167;
		cir[1][6] = 607;
		cir[1][4]= 0;
		bl2=0;
		//return 2;
	}

	else if(cir[0][xx]==cir[1][8] && cir[0][yy]==cir[1][9]){
		cir[1][8] = 92;
		cir[1][9] = 532;
		cir[1][7]= 0;
		bl3=0;
		//return 3;
	}

	else if(cir[0][xx]==cir[1][11] && cir[0][yy]==cir[1][12]){
		cir[1][11] = 167;
		cir[1][12] = 532;
		cir[1][10]= 0;
		bl4=0;
		//return 4;
	}

	else if(cir[0][xx]==cir[2][2] && cir[0][yy]==cir[2][3]){
		cir[2][2] = 532;
		cir[2][3] = 607;
		cir[2][1]= 0;
		rd1=0;
		//return 5;
	}

	else if(cir[0][xx]==cir[2][5] && cir[0][yy]==cir[2][6]){
		cir[2][5] = 607;
		cir[2][6] = 607;
		cir[2][4]= 0;
		rd2=0;
		//return 6;
	}

	else if(cir[0][xx]==cir[2][8] && cir[0][yy]==cir[2][9]){
		cir[2][8] = 532;
		cir[2][9] = 532;
		cir[2][7]= 0;
		rd3=0;
		//return 7;
	}

	else if(cir[0][xx]==cir[2][11] && cir[0][yy]==cir[2][12]){
		cir[2][11] = 607;
		cir[2][12] = 532;
		cir[2][10]= 0;
		rd4=0;
		//return 8;
	}
	else if(cir[0][xx]==cir[3][2] && cir[0][yy]==cir[3][3]){
		cir[3][2] = 532;
		cir[3][3] = 167;
		cir[3][1]= 0;
		gr1=0;
		//return 9;
	}

	else if(cir[0][xx]==cir[3][5] && cir[0][yy]==cir[3][6]){
		cir[3][5] = 607;
		cir[3][6] = 167;
		cir[3][4]= 0;
		gr2=0;
		//return 10;
	}

	else if(cir[0][xx]==cir[3][8] && cir[0][yy]==cir[3][9]){
		cir[3][8] = 532;
		cir[3][9] = 92;
		cir[3][7]= 0;
		gr3=0;
		//return 11;
	}

	else if(cir[0][xx]==cir[3][11] && cir[0][yy]==cir[3][12]){
		cir[3][11] = 607;
		cir[3][12] = 92;
		cir[3][10]= 0;
		gr4=0;
		//return 12;
	}

	//else
	//return 0;


}

void blue_power(int xx, int yy)
{
	if(cir[1][xx] == cir_x[0][0] && cir[1][yy]==cir_y[0][0]){
		printf("will not go in");
	}

	else if(cir[1][xx] == cir_x[2][0] && cir[1][yy]==cir_y[2][0]){
		printf("will not go in");
	}

	else if(cir[1][xx] == cir_x[3][0] && cir[1][yy]==cir_y[3][0]){
		printf("will not go in");
	}


	else if(cir[1][xx]==cir[0][2] && cir[1][yy]==cir[0][3]){
		cir[0][2] = 92;
		cir[0][3] = 167;
		cir[0][1]= 0;
		yl1=0;
		//return 1;
	}

	else if(cir[1][xx]==cir[0][5] && cir[1][yy]==cir[0][6]){
		cir[0][5] = 167;
		cir[0][6] = 167;
		cir[0][4]= 0;
		yl2=0;
		//return 2;
	}

	else if(cir[1][xx]==cir[0][8] && cir[1][yy]==cir[0][9]){
		cir[0][8] = 92;
		cir[0][9] = 92;
		cir[0][7]= 0;
		yl3=0;
		//return 3;
	}

	else if(cir[1][xx]==cir[0][11] && cir[1][yy]==cir[0][12]){
		cir[0][11] = 167;
		cir[0][12] = 92;
		cir[0][10]= 0;
		yl4=0;
		//return 4;
	}

	else if(cir[1][xx]==cir[2][2] && cir[1][yy]==cir[2][3]){
		cir[2][2] = 532;
		cir[2][3] = 607;
		cir[2][1]= 0;
		rd1=0;
		//return 5;
	}

	else if(cir[1][xx]==cir[2][5] && cir[1][yy]==cir[2][6]){
		cir[2][5] = 607;
		cir[2][6] = 607;
		cir[2][4]= 0;
		rd2=0;
		//return 6;
	}

	else if(cir[1][xx]==cir[2][8] && cir[1][yy]==cir[2][9]){
		cir[2][8] = 532;
		cir[2][9] = 532;
		cir[2][7]= 0;
		rd3=0;
		//return 7;
	}

	else if(cir[1][xx]==cir[2][11] && cir[1][yy]==cir[2][12]){
		cir[2][11] = 607;
		cir[2][12] = 532;
		cir[2][10]= 0;
		rd4=0;
		//return 8;
	}
	else if(cir[1][xx]==cir[3][2] && cir[1][yy]==cir[3][3]){
		cir[3][2] = 532;
		cir[3][3] = 167;
		cir[3][1]= 0;
		gr1=0;
		//return 9;
	}

	else if(cir[1][xx]==cir[3][5] && cir[1][yy]==cir[3][6]){
		cir[3][5] = 607;
		cir[3][6] = 167;
		cir[3][4]= 0;
		gr2=0;
		//return 10;
	}

	else if(cir[1][xx]==cir[3][8] && cir[1][yy]==cir[3][9]){
		cir[3][8] = 532;
		cir[3][9] = 92;
		cir[3][7]= 0;
		gr3=0;
		//return 11;
	}

	else if(cir[1][xx]==cir[3][11] && cir[1][yy]==cir[3][12]){
		cir[3][11] = 607;
		cir[3][12] = 92;
		cir[3][10]= 0;
		gr4=0;
		//return 12;
	}
	//else
	//return 0;

}

void red_power(int xx, int yy)
{
	if(cir[2][xx] == cir_x[1][0] && cir[2][yy]==cir_y[1][0]){
		printf("will not go in");
	}

	else if(cir[2][xx] == cir_x[0][0] && cir[2][yy]==cir_y[0][0]){
		printf("will not go in");
	}

	else if(cir[2][xx] == cir_x[3][0] && cir[2][yy]==cir_y[3][0]){
		printf("will not go in");
	}

	else if(cir[2][xx]==cir[1][2] && cir[2][yy]==cir[1][3]){
		cir[1][2] = 92;
		cir[1][3] = 607;
		cir[1][1]= 0;
		bl1=0;
		//return 1;
	}

	else if(cir[2][xx]==cir[1][5] && cir[2][yy]==cir[1][6]){
		cir[1][5] = 167;
		cir[1][6] = 607;
		cir[1][4]= 0;
		bl2=0;
		//return 2;
	}

	else if(cir[2][xx]==cir[1][8] && cir[2][yy]==cir[1][9]){
		cir[1][8] = 92;
		cir[1][9] = 532;
		cir[1][7]= 0;
		bl3=0;
		//return 3;
	}

	else if(cir[2][xx]==cir[1][11] && cir[2][yy]==cir[1][12]){
		cir[1][11] = 167;
		cir[1][12] = 532;
		cir[1][10]= 0;
		bl4=0;
		//return 4;
	}

	else if(cir[2][xx]==cir[0][2] && cir[2][yy]==cir[0][3]){
		cir[0][2] = 92;
		cir[0][3] = 167;
		cir[0][1]= 0;
		yl1=0;
		//return 5;
	}

	else if(cir[2][xx]==cir[0][5] && cir[2][yy]==cir[0][6]){
		cir[0][5] = 167;
		cir[0][6] = 167;
		cir[0][4]= 0;
		yl2=0;
		//return 6;
	}

	else if(cir[2][xx]==cir[0][8] && cir[2][yy]==cir[0][9]){
		cir[0][8] = 92;
		cir[0][9] = 92;
		cir[0][7]= 0;
		yl3=0;
		//return 7;
	}

	else if(cir[2][xx]==cir[0][11] && cir[2][yy]==cir[0][12]){
		cir[0][11] = 167;
		cir[0][12] = 92;
		cir[0][10]= 0;
		yl4=0;
		//return 8;
	}
	else if(cir[2][xx]==cir[3][2] && cir[2][yy]==cir[3][3]){
		cir[3][2] = 532;
		cir[3][3] = 167;
		cir[3][1]= 0;
		gr1=0;
		//return 9;
	}

	else if(cir[2][xx]==cir[3][5] && cir[2][yy]==cir[3][6]){
		cir[3][5] = 607;
		cir[3][6] = 167;
		cir[3][4]= 0;
		gr2=0;
		//return 10;
	}

	else if(cir[2][xx]==cir[3][8] && cir[2][yy]==cir[3][9]){
		cir[3][8] = 532;
		cir[3][9] = 92;
		cir[3][7]= 0;
		gr3=0;
		//return 11;
	}

	else if(cir[2][xx]==cir[3][11] && cir[2][yy]==cir[3][12]){
		cir[3][11] = 607;
		cir[3][12] = 92;
		cir[3][10]= 0;
		gr4=0;
		//return 12;
	}

	//else
	//return 0;

}

void green_power(int xx, int yy)
{

	if(cir[3][xx] == cir_x[0][0] && cir[3][yy]==cir_y[0][0]){
		printf("will not go in");
	}

	else if(cir[3][xx] == cir_x[1][0] && cir[3][yy]==cir_y[1][0]){
		printf("will not go in");
	}

	else if(cir[3][xx] == cir_x[2][0] && cir[3][yy]==cir_y[2][0]){
		printf("will not go in");
	}


	else if(cir[3][xx]==cir[1][2] && cir[3][yy]==cir[1][3]){
		cir[1][2] = 92;
		cir[1][3] = 607;
		cir[1][1]= 0;
		bl1=0;
		//return 1;

	}

	else if(cir[3][xx]==cir[1][5] && cir[3][yy]==cir[1][6]){
		cir[1][5] = 167;
		cir[1][6] = 607;
		cir[1][4]= 0;
		bl2=0;
		//return 2;
	}

	else if(cir[3][xx]==cir[1][8] && cir[3][yy]==cir[1][9]){
		cir[1][8] = 92;
		cir[1][9] = 532;
		cir[1][7]= 0;
		bl3=0;
		//return 3;
	}

	else if(cir[3][xx]==cir[1][11] && cir[3][yy]==cir[1][12]){
		cir[1][11] = 167;
		cir[1][12] = 532;
		cir[1][10]= 0;
		bl4=0;
		//return 4;
	}

	else if(cir[3][xx]==cir[2][2] && cir[3][yy]==cir[2][3]){
		cir[2][2] = 532;
		cir[2][3] = 607;
		cir[2][1]= 0;
		rd1=0;
		//return 5;
	}

	else if(cir[3][xx]==cir[2][5] && cir[3][yy]==cir[2][6]){
		cir[2][5] = 607;
		cir[2][6] = 607;
		cir[2][4]= 0;
		rd2=0;
		//return 6;
	}

	else if(cir[3][xx]==cir[2][8] && cir[3][yy]==cir[2][9]){
		cir[2][8] = 532;
		cir[2][9] = 532;
		cir[2][7]= 0;
		rd3=0;
		//return 7;
	}

	else if(cir[3][xx]==cir[2][11] && cir[3][yy]==cir[2][12]){
		cir[2][11] = 607;
		cir[2][12] = 532;
		cir[2][10]= 0;
		rd4=0;
		//return 8;
	}
	else if(cir[3][xx]==cir[0][2] && cir[3][yy]==cir[0][3]){
		cir[0][2] = 92;
		cir[0][3] = 167;
		cir[0][1]= 0;
		yl1=0;
		//return 9;
	}

	else if(cir[3][xx]==cir[0][5] && cir[3][yy]==cir[0][6]){
		cir[0][5] = 167;
		cir[0][6] = 167;
		cir[0][4]= 0;
		yl2=0;
		//return 10;
	}

	else if(cir[3][xx]==cir[0][8] && cir[3][yy]==cir[0][9]){
		cir[0][8] = 92;
		cir[0][9] = 92;
		cir[0][7]= 0;
		yl3=0;
		//return 11;
	}

	else if(cir[3][xx]==cir[0][11] && cir[3][yy]==cir[0][12]){
		cir[0][11] = 167;
		cir[0][12] = 92;
		cir[0][10]= 0;
		yl4=0;
		//return 12;
	}

	//else
	//return 0;
}

int condit(int i, int xx, int yy)
{
	if(cir[i][xx] == cir_x[i][51] && cir[i][yy] == cir_y[i][51]){
		if(dice!=6){
			cir[i][xx] = cir_x[i][51 + dice];
			cir[i][yy] = cir_y[i][51 + dice];
		}
		return 1;
	}

	else if(cir[i][xx] == cir_x[i][52] && cir[i][yy] == cir_y[i][52]){
		if(dice!=6 && dice!=5){
			cir[i][xx] = cir_x[i][52 + dice];
			cir[i][yy] = cir_y[i][52 + dice];
		}
		return 1;
	}

	else if(cir[i][xx] == cir_x[i][53] && cir[i][yy] == cir_y[i][53]){
		if(dice!=6 && dice!=5 && dice!=4){
			cir[i][xx] = cir_x[i][53 + dice];
			cir[i][yy] = cir_y[i][53 + dice];
		}
		return 1;
	}

	else if(cir[i][xx] == cir_x[i][54] && cir[i][yy] == cir_y[i][54]){
		if(dice!=6 && dice!=5 && dice!=4 && dice!=3){
			cir[i][xx] = cir_x[i][54 + dice];
			cir[i][yy] = cir_y[i][54 + dice];
		}
		return 1;
	}

	else if(cir[i][xx] == cir_x[i][55] && cir[i][yy] == cir_y[i][55]){
		if(dice!=6 && dice!=5 && dice!=4 && dice!=3 && dice!=2){
			cir[i][xx] = cir_x[i][55 + dice];
			cir[i][yy] = cir_y[i][55 + dice];
		}
		return 1;
	}

}

int condit1(int i, int xx, int yy)
{
	if(cir[i][xx] == cir_x[i][51] && cir[i][yy] == cir_y[i][51] && dice!=6){
		return 1;
	}

	else if(cir[i][xx] == cir_x[i][52] && cir[i][yy] == cir_y[i][52] && dice!=6 && dice!=5){
		return 1;
	}

	else if(cir[i][xx] == cir_x[i][53] && cir[i][yy] == cir_y[i][53] && dice!=6 && dice!=5 && dice!=4){
		return 1;
	}

	else if(cir[i][xx] == cir_x[i][54] && cir[i][yy] == cir_y[i][54] && dice!=6 && dice!=5 && dice!=4 && dice!=3 ){
		return 1;
	}

	else if(cir[i][xx] == cir_x[i][55] && cir[i][yy] == cir_y[i][55] && dice == 1){
		return 1;
	}

}

void Takeout(int i, int j, int xx, int yy, int cxx, int cyy)
{
	cir[i][xx] = cxx;
	cir[i][yy] = cyy;
	iFilledCircle(cir[i][xx], cir[i][yy], 17);
	cir[i][j]=1;
}

void movecoin(int i, int xx, int yy, int yl)
{
	cir[i][xx] = cir_x[i][yl + dice];
	cir[i][yy] = cir_y[i][yl + dice];
}

int Gamewin(int win)
{
	if(cir[win][1] == -1 && cir[win][4] == -1 && cir[win][7] == -1 && cir[win][11] == -1)
	return 1;
}

void DrawMainMenu()
{
	iShowBMP(0,0,"qw.bmp");

	iSetColor(100,100,100);
	iFilledRectangle(750,150,200,70);
	iFilledRectangle(750,300,200,70);
	iFilledRectangle(750,450,200,70);

	iSetColor(255,255,255);
	iText(780,480,"PLAY NOW",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(765,328,"INSTRUCTIONS",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(820,180,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

}

void DrawInstructions()
{

	iRectangle(20,20,960,660);
	iSetColor(500,500,500);
	iText(240,620,"Ludo is a very Popluar Board Game !");
	iText(41*4,600,"Special areas of the Ludo board are typically coloured bright yellow, green, red, and blue. ");
	iText(35*4,580,"Each player is assigned a colour and has four tokens of matching colour");
	iText(31*4,560,"At the beginning of the game, each player's tokens are out of play and ");
	iText(30*4,540,"staged in one of the large corner areas of the board in the player's colour");
	iText(30*4,520,"When able to, the players will enter their tokens one per time on their respective starting squares, ");
	iText(31*4,500,"and proceed to race them clockwise around the board along the game track");
	iText(30*4,480,"The rolls of 6 on the dice control the swiftness of the tokens");
	iText(26*4,460,"entry to the finishing square requires a precise roll from the player");
	iText(29*4,440,"The first to bring all their tokens to the finish wins the game. ");
	iText(37*4,420,"If the player has no tokens yet in play and does not roll a 6, the turn passes to the next player");
	iText(39*4,400,"Once a player has one or more tokens in play, he selects a token ");
	iText(39*4,380,"and moves it forward along the track the number of squares indicated by the die roll.");
	iText(39*4,360,"When a player rolls a 6 he may choose to advance a token already in play");
	iText(39*4,340,"or alternatively, he may enter another staged token to its starting square. ");
	iText(39*4,320,"The rolling of a 6 earns the player an additional  roll in that turn");
	iText(39*4,300,"If the additional roll results in a 6 again, the player earns an additional bonus roll.");
	iText(110,280," If the advance of a token ends on a square occupied by an opponent's token, the opponent token is returned ");
	iText(39*4,260,"  the opponent token is returned to its owner's yard.");
}

void DrawBack2MainMenu()
{   //iClear();
    iSetColor(500,500,500);
    iRectangle(800,20,150,50);
    iText(800,50,"Back To MAIN MENU");

}

int Count3sixes(int count)
{
	if (count==6)
		return 1;

	else 
		return 0;
}

void work3sixes(int i, int j, int xx, int yy, int cxx, int cyy, int yl, int rd)
{
	if(player_turn==i){
	if(Count3sixes){
	yl = rd;
	movecoin(i, xx, yy, rd);
	if(rd > yl)
	{
		rd = yl;
	}
	
	if(cir[i][j]==0){
		Takeout(i, j, xx, yy, cxx, cyy);
		if(cir[i][j] == 1)
		{
			cir[i][j]=0;
		}

	}

	}
	}

}

void Winmsg()
{
	if(Gamewin(0)){
	iSetColor(0,0,0);
	iText(800,600,"Player A Wins !!! Congrats", GLUT_BITMAP_HELVETICA_18);
	}

	else if(Gamewin(1)){
	iSetColor(0,0,0);
	iText(800,600,"Player B Wins !!! Congrats",GLUT_BITMAP_HELVETICA_18);
	}

	else if(Gamewin(2)){
	iSetColor(0,0,0);
	iText(800,600,"Player C Wins !!! Congrats",GLUT_BITMAP_HELVETICA_18);
	}

	else if(Gamewin(3)){
	iSetColor(0,0,0);
	iText(800,600,"Player D Wins !!! Congrats",GLUT_BITMAP_HELVETICA_18);
	}
}

void GameScreen()
{
	DrawBoard();

	iSetColor(150,150,150);
	iFilledRectangle(706, 0, 300, 700);

	
	player();
	//Draw_dice_circle();
	//Draw_dice_circle1();
	DrawCircles();
	if(dice==1)
	PlaySound((LPCSTR)"1.wav", NULL, SND_FILENAME | SND_ASYNC);

	if(dice==2)
	PlaySound((LPCSTR)"2.wav", NULL, SND_FILENAME | SND_ASYNC);

	if(dice==3)
	PlaySound((LPCSTR)"3.wav", NULL, SND_FILENAME | SND_ASYNC);

//	Winmsg();
}



void iDraw()
{
	iClear();

	iSetColor(200,200,200);
	if(countMainMenu)
	{
		DrawMainMenu();
		iSetColor(80,80,80);
		iFilledRectangle(375,0,250,80);
		iSetColor(500,500,500);
		iText(460,65,"Devloped By");
		iText(430,40,"SAURAV GUPTA",GLUT_BITMAP_HELVETICA_18);
		iText(490,10,"DX",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(PlayNow) 
	{
		GameScreen();
		gameplay= 1;
	}

	else if(countInstructions)
		DrawInstructions();

	if(countBack2MainMenu) 
		DrawBack2MainMenu();

}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)

{
	if(countBack2MainMenu)
        {
            
            if(mx>=800 && mx<=900 && my>=20 && my <= 70)
            {
                countBack2MainMenu=0;
                countMainMenu=1;
                countInstructions=0;
                countMainGame=0;
                PlayNow=0;
               
            }
        }

	//
	if(countMainMenu)
	{
		if(mx>=750 && mx<=950 && my>=450 && my<=520)
		{
			countMainMenu=0;
			PlayNow=1;

		}
		if(mx>=750 && mx<=950 && my>=300 && my<=370)
		{
			countMainMenu=0;
			countInstructions=1;
			countBack2MainMenu=1;
		}

		if(mx>=750 && mx<=950 && my>=150 && my<=220)
		{
			exit(0);
		}
	}

	///////////////
	if(gameplay == 1){
		int static turn = 0;
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
			if(dice == 6){
				if(player_turn == 0){
					if (turn == 1){
						if(turndx==1){
							turn= 2;
						}

						else
						{
							if(mx >= 800 && my >= 300 && mx <= 880 && my <= 380){
								random();

								printf("Yellow 6 ");
								if(dice==6){
									turn = 2;
									count++;
								}
								else
									turn=11;
							}
						}
						turndx=0;
					}


					if(turn == 2){
						turndy=1;
						if(yl1 <= 50){
							if(mx >= cir[0][2] - 17 && my >= cir[0][3] - 17 && mx <= cir[0][2] + 17 && my<= cir[0][3] + 17){
								if(turndy==1){
									if(dice==6){
										if(cir[0][1]==0){
											Takeout(0, 1, 2, 3, 290, 65);
											yellow_power(2,3);
										}

										else if(cir[0][1]==1 && yl1 <=50) {
											movecoin(0, 2, 3, yl1);
											yl1 = yl1 + dice;
											yellow_power(2,3);
										}
										printf("Yellow 1st coin ");
										turn =1;
									}


									else{
										turn=11;
									}
								}
								turndy=0;
							}
						}
						if(yl2 <= 50){
							if(mx >= cir[0][5] - 17 && my >= cir[0][6] - 17 && mx <= cir[0][5] + 17 && my<= cir[0][6] + 17){
								if(turndy==1){
									if(dice==6){
										if(cir[0][4]==0){
											Takeout(0, 4, 5, 6, 290, 65);
											yellow_power(5,6);
										}

										else if(cir[0][4]==1){
											movecoin(0, 5, 6, yl2);
											yl2 = yl2 + dice;
											yellow_power(5,6);
										}
										turn =1;
									}


									else{
										turn=11;
									}
								}
								turndy=0;
							}
						}

						if(yl3 <= 50){
							if(mx >= cir[0][8] - 17 && my >= cir[0][9] - 17 && mx <= cir[0][8] + 17 && my<= cir[0][9] + 17){
								if(turndy==1){
									if(dice==6){
										if(cir[0][7]==0){
											Takeout(0, 7, 8, 9, 290, 65);
											yellow_power(8,9);
										}

										else if(cir[0][7]==1){
											movecoin(0, 8, 9, yl3);
											yl3 = yl3 + dice;
											yellow_power(8,9);
										}
										turn = 1;
									}

									else{
										turn =11;
									}
								}
								turndy=0;
							}
						}

						if(yl4 <= 50){
							if(mx >= cir[0][11] - 17 && my >= cir[0][12] - 17 && mx <= cir[0][11] + 17 && my<= cir[0][12] + 17){
								if(turndy==1){
									if(dice==6){
										if(cir[0][10]==0){
											Takeout(0, 10, 11, 12, 290, 65);
											yellow_power(11,12);
										}

										else if(cir[0][10]==1){
											movecoin(0, 11, 12, yl4);
											yl4 = yl4 + dice;
											yellow_power(11,12);
										}
										turn = 1;
									}

									else
									{
										turn=11;
									}
								}
								turndy = 0;
							}
						}

					}//turn ends
				}//player turn ends here

				if(player_turn == 1){
					if(turn == 3){
						if(turndx==2){
							turn = 4;
						}

						else
						{
							if(mx >= 880 && my >= 300 && mx <= 960 && my <= 380){

								random();
								printf(" Blue 6 ");
								if(dice==6)
									turn = 4;

								else
									turn = 13;
							}
						}
						turndx=0;
					}
					if(turn ==4){
						turndq=1;
						if(bl1 <= 50){
							if(mx >= cir[1][2] - 17 && my >= cir[1][3] - 17 && mx <= cir[1][2] + 17 && my<= cir[1][3] + 17){
								if(turndq==1){
									if(dice==6){

										if(cir[1][1]==0){
											Takeout(1, 1, 2, 3, 65, 410);
											blue_power(2,3);
										}

										else if(cir[1][1]==1){
											movecoin(1, 2, 3, bl1);
											bl1 = bl1 + dice;
											blue_power(2,3);
										}
										turn = 3;
									}

									else{
										turn=13;
									}
								}
								turndq=0;
							}
						}

						if(bl2 <= 50){
							if(mx >= cir[1][5] - 17 && my >= cir[1][6] - 17 && mx <= cir[1][5] + 17 && my<= cir[1][6] + 17){
								if(turndq==1){
									if(dice==6){
										if(cir[1][4]==0){
											Takeout(1, 4, 5, 6, 65, 410);
											blue_power(5,6);
										}

										else if(cir[1][4]==1){
											movecoin(1, 5, 6, bl2);
											bl2 = bl2 + dice;
											blue_power(5,6);
										}
										turn = 3;
									}

									else{
										turn=13;
									}
								}
								turndq=0;
							}
						}

						if(bl3 <= 50){
							if(mx >= cir[1][8] - 17 && my >= cir[1][9] - 17 && mx <= cir[1][8] + 17 && my<= cir[1][9] + 17){
								if(turndq==1){
									if(dice==6){
										//if 3rd circle is clicked
										if(cir[1][7]==0){
											Takeout(1, 7, 8, 9, 65, 410);
											blue_power(8,9);
										}

										else if(cir[1][7]==1){
											movecoin(1, 8, 9, bl3);
											bl3 = bl3 + dice;
											blue_power(8,9);
										}
										turn = 3;
									}
									else{
										turn = 13;
									}
								}
								turndq=0;
							}
						}

						if(bl4 <= 50){
							if(mx >= cir[1][11] - 17 && my >= cir[1][12] - 17 && mx <= cir[1][11] + 17 && my<= cir[1][12] + 17){
								if(turndq==1){
									if(dice==6){
										if(cir[1][10]==0){
											Takeout(1, 10, 11, 12, 65, 410);
											blue_power(11,12);
										}

										else if(cir[1][10]==1){
											movecoin(1, 11, 12, bl4);
											bl4 = bl4 + dice;
											blue_power(11,12);
										}
										turn = 3;
									}
									else{
										turn=13;
									}
								}
								turndq=0;
							}
						}
					} //turn ends here
				} //player turn ends here

				//}
				if(player_turn == 2){
					if(turn == 5){
						if(turndx==3){
							turn = 6;
						}
						else
						{
							if(mx >= 800 && my >= 300 && mx <= 880 && my <= 380){

								random();
								printf(" Red 6 ");
								if(dice==6)
									turn = 6;

								else 
									turn = 15;
							}
						}
						turndx=0;
					}
					if(turn ==6){
						turndw=1;
						if(rd1 <= 50){
							if(mx >= cir[2][2] - 17 && my >= cir[2][3] - 17 && mx <= cir[2][2] + 17 && my<= cir[2][3] + 17){
								if(turndw==1){
									if(dice==6){
										if(cir[2][1]==0){
											Takeout(2, 1, 2, 3, 410, 634);
											red_power(2,3);
										}

										else if(cir[2][1]==1){
											movecoin(2, 2, 3, rd1);
											rd1 = rd1 + dice;
											red_power(2,3);
										}
										turn = 5;
									}
									else{
										turn = 15;
									}
								}
								turndw=0;
							}
						}

						if(rd2 <= 50){
							if(mx >= cir[2][5] - 17 && my >= cir[2][6] - 17 && mx <= cir[2][5] + 17 && my<= cir[2][6] + 17){
								if(turndw==1){
									if(dice==6){
										if(cir[2][4]==0){
											Takeout(2, 4, 5, 6, 410, 634);
											red_power(5,6);
										}

										else if(cir[2][4]==1){
											movecoin(2, 5, 6, rd2);
											rd2 = rd2 + dice;
											red_power(5,6);
										}
										turn = 5;
									}
									else{
										turn =15;
									}
								}
								turndw=0;
							}
						}

						if(rd3 <= 50){
							if(mx >= cir[2][8] - 17 && my >= cir[2][9] - 17 && mx <= cir[2][8] + 17 && my<= cir[2][9] + 17){
								if(turndw==1){
									if(dice==6){
										if(cir[2][7]==0){
											Takeout(2, 7, 8, 9, 410, 634);
											red_power(8,9);
										}

										else if(cir[2][7]==1){
											movecoin(2, 8, 9, rd3);
											rd3 = rd3 + dice;
											red_power(8,9);
										}
										turn = 5;
									}
									else{
										turn=15;
									}
								}
								turndw=0;
							}
						}

						if(rd4 <= 50){
							if(mx >= cir[2][11] - 17 && my >= cir[2][12] - 17 && mx <= cir[2][11] + 17 && my<= cir[2][12] + 17){
								if(turndw==1){
									if(dice==6){
										if(cir[2][10]==0){
											Takeout(2, 10, 11, 12, 410, 634);
											red_power(11,12);
										}

										else if(cir[2][10]==1){
											movecoin(2, 11, 12, rd4);
											rd4 = rd4 + dice;
											red_power(11,12);
										}
										turn = 5;
									}
									else{
										turn=15;
									}
								}
								turndw=0;
							}
						}

					}//turn ends here
				}//player turns end here

				if(player_turn == 3){
					if(turn == 7){
						if(turndx==4){
							turn = 8;
						}
						else
						{
							if(mx >= 880 && my >= 300 && mx <= 960 && my <= 380){

								random();
								printf(" Green 6 ");
								if(dice==6)
									turn = 8;

								else
									turn = 17;
							}
						}
						turndx=0;
					}
					if(turn == 8){
						turnde = 1;
						if(gr1 <= 50){
							if(mx >= cir[3][2] - 17 && my >= cir[3][3] - 17 && mx <= cir[3][2] + 17 && my<= cir[3][3] + 17){
								if(turnde==1){
									if(dice==6){
										if(cir[3][1]==0){
											Takeout(3, 1, 2, 3, 634, 290);
											green_power(2,3);
										}

										else if(cir[3][1]==1){
											movecoin(3, 2, 3, gr1);
											gr1 = gr1 + dice;
											green_power(2,3);
										}
										turn = 7;
									}
									else{
										turn =17;
									}
								}
								turnde=0;
							}
						}

						if(gr2 <= 50){
							if(mx >= cir[3][5] - 17 && my >= cir[3][6] - 17 && mx <= cir[3][5] + 17 && my<= cir[3][6] + 17){
								if(turnde==1){
									if(dice==6){
										if(cir[3][4]==0){
											Takeout(3, 4, 5, 6, 634, 290);
											green_power(5,6);
										}

										else if(cir[3][4]==1){
											movecoin(3, 5, 6, gr2);
											gr2 = gr2 + dice;
											green_power(5,6);
										}
										turn = 7;
									}
									else{
										turn =17;
									}
								}
								turnde=0;
							}
						}

						if(gr3 <= 50){
							if(mx >= cir[3][8] - 17 && my >= cir[3][9] - 17 && mx <= cir[3][8] + 17 && my<= cir[3][9] + 17){
								if(turnde==1){
									if(dice==6){
										if(cir[3][7]==0){
											Takeout(3, 7, 8, 9, 634, 290);
											green_power(8,9);
										}

										else if(cir[3][7]==1){
											movecoin(3, 8, 9, gr3);
											gr3 = gr3 + dice;
											green_power(8,9);
										}
										turn = 7;
									}
									else{
										turn =17;
									}
								}
								turnde=0;
							}
						}

						if(gr4 <= 50){
							if(mx >= cir[3][11] - 17 && my >= cir[3][12] - 17 && mx <= cir[3][11] + 17 && my<= cir[3][12] + 17){
								if(turnde==1){
									if(dice==6){
										if(cir[3][10]==0){
											Takeout(3, 10, 11, 12, 634, 290);
											green_power(11,12);
										}

										else if(cir[3][10]==1){
											movecoin(3, 11, 12, gr4);
											gr4 = gr4 + dice;
											green_power(11,12);
										}
										turn = 7;
									}
								}
								turnde=0;
							}
						}
					}// turn ends here

				}// player turn ends here

			}//dice values ends here

			else{

				if(player_turn==0){

					if(turn == 0){
						if(mx >= 800 && my >= 300 && mx <= 880 && my <= 380){

							random();

							PlaySound((LPCSTR)"1.wav", NULL, SND_FILENAME | SND_ASYNC);
							PlaySound((LPCSTR)"2.wav", NULL, SND_FILENAME | SND_ASYNC);
							PlaySound((LPCSTR)"3.wav", NULL, SND_FILENAME | SND_ASYNC);
							PlaySound((LPCSTR)"4.wav", NULL, SND_FILENAME | SND_ASYNC);
							PlaySound((LPCSTR)"5.wav", NULL, SND_FILENAME | SND_ASYNC);
							PlaySound((LPCSTR)"6.wav", NULL, SND_FILENAME | SND_ASYNC);
							printf(" Yellow Odd has been clicked \n");
							if(dice==6){
								player_turn = 0;
								turn = 1;
								turndx=1;

							}

							else{
								if(((cir[0][1]==1 && yl1 <=50) || (cir[0][1]==1 && condit1(0, 2, 3)==1) )  || ((cir[0][4]==1 && yl2 <=50) || (cir[0][4]==1 && condit1(0, 5, 6)==1)) || ((cir[0][7]==1 && yl3 <=50) || (cir[0][7]==1 && condit1(0, 8, 9)==1) ) || ((cir[0][10]==1 && yl4 <=50) || (cir[0][10]==1 && condit1(0, 11, 12)==1)))
								{
									turn = 11;
								}

								else{
									player_turn = 1;
									turn = 12;
								}
							}
						}
					}
					if(turn == 11){
						turndy = 1;
						if((cir[0][1]==1 && yl1 <=50) || (cir[0][1]==1 && condit1(0, 2, 3)==1) ){

							if(mx >= cir[0][2] - 17 && my >= cir[0][3] - 17 && mx <= cir[0][2] + 17 && my<= cir[0][3] + 17){
								if(turndy==1){
									if(cir[0][1]==1 && yl1 <=50){
										movecoin(0, 2, 3, yl1);
										yl1 = yl1 + dice;
										yellow_power(2,3);
									}
									else
										condit(0, 2, 3);

									if(cir[0][2] == cir_x[0][56] && cir[0][3] == cir_y[0][56]){
										cir[0][1] = -1;
									}

									turn = 12;
									player_turn = 1;
								}
								turndy = 0;
							}
						}

						if((cir[0][4]==1 && yl2 <=50) || (cir[0][4]==1 && condit1(0, 5, 6)==1) ){

							if(mx >= cir[0][5] - 17 && my >= cir[0][6] - 17 && mx <= cir[0][5] + 17 && my<= cir[0][6] + 17){
								if(turndy==1){
									if(cir[0][4]==1 && yl2 <=50){
										movecoin(0, 5, 6, yl2);
										yl2 = yl2 + dice;
										yellow_power(5,6);
									}
									else
										condit(0, 5, 6);

									if(cir[0][5] == cir_x[0][56] && cir[0][6] == cir_y[0][56]){
										cir[0][4] = -1;
									}

									turn = 12;
									player_turn = 1;
								}
								turndy=0;
							}
						}
						if((cir[0][7]==1 && yl3 <=50) || (cir[0][7]==1 && condit1(0, 8, 9)==1) ){
							printf("THis condit");
							if(mx >= cir[0][8] - 17 && my >= cir[0][9] - 17 && mx <= cir[0][8] + 17 && my<= cir[0][9] + 17){
								if(turndy==1){
									printf("Butnotcondit");
									if(cir[0][7]==1 && yl3 <=50){
										movecoin(0, 8, 9, yl3);
										yl3 = yl3 + dice;
										yellow_power(8,9);
									}
									else
										condit(0, 8, 9);

									if(cir[0][8] == cir_x[0][56] && cir[0][9] == cir_y[0][56]){
										cir[0][7] = -1;
									}

									turn = 12;
									player_turn = 1;
								}
								turndy=0;
							}
						}

						if((cir[0][10]==1 && yl4 <=50) || (cir[0][10]==1 && condit1(0, 11, 12)==1) ){

							if(mx >= cir[0][11] - 17 && my >= cir[0][12] - 17 && mx <= cir[0][11] + 17 && my<= cir[0][12] + 17){
								if(turndy==1){
									if(cir[0][10]==1 && yl4 <=50){
										movecoin(0, 11, 12, yl4);
										yl4 = yl4 + dice;
										yellow_power(11,12);
									}
									else
										condit(0, 11, 12);

									if(cir[0][11] == cir_x[0][56] && cir[0][12] == cir_y[0][56]){
										cir[0][10] = -1;
									}

									turn = 12;
									player_turn = 1;
								}
								turndy=0;
							}
						}
					}// turn ends here

				}//player turn ends here

				if(player_turn == 1){

					if(turn == 12){
						if(mx >= 880 && my >= 300 && mx <= 960 && my <= 380){

							random();
							printf(" Blue Odd has been clicked \n");

							if(dice==6){
								player_turn = 1;
								turn = 3;
								turndx=2;

							}

							else{
								if(((cir[1][1]==1 && bl1 <=50) || (cir[1][1]==1 && condit1(1, 2, 3)==1) )  || ((cir[1][4]==1 && bl2 <=50) || (cir[1][4]==1 && condit1(1, 5, 6)==1)) || ((cir[1][7]==1 && bl3 <=50) || (cir[1][7]==1 && condit1(1, 8, 9)==1) ) || ((cir[1][10]==1 && bl4 <=50) || (cir[1][10]==1 && condit1(1, 11, 12)==1)))
								{
									turn = 13;
								}

								else{
									player_turn = 2;
									turn = 14;
								}
							}
						}
					}

					if(turn == 13){
						turndq = 1;
						if((cir[1][1]==1 && bl1 <=50) || (cir[1][1]==1 && condit1(1, 2, 3)==1) ){

							if(mx >= cir[1][2] - 17 && my >= cir[1][3] - 17 && mx <= cir[1][2] + 17 && my<= cir[1][3] + 17){
								if(turndq==1){
									if(cir[1][1]==1 && bl1 <=50){
										movecoin(1, 2, 3, bl1);
										bl1 = bl1 + dice;
										blue_power(2,3);

									}
									else
										condit(1, 2, 3);

									if(cir[1][2] == cir_x[1][56] && cir[1][3] == cir_y[1][56]){
										cir[1][1] = -1;
									}

									turn = 14;
									player_turn = 2;
								}
								turndq = 0;
							}
						}

						//if 2nd cir is clicked
						if((cir[1][4]==1 && bl2 <=50) || (cir[1][4]==1 && condit1(1, 5, 6)==1) ){
							if(mx >= cir[1][5] - 17 && my >= cir[1][6] - 17 && mx <= cir[1][5] + 17 && my<= cir[1][6] + 17){
								if(turndq==1){
									if(cir[1][4]==1 && bl2 <=50){
										movecoin(1, 5, 6, bl2);
										bl2 = bl2 + dice;
										blue_power(5,6);
									}
									else
										condit(1, 5, 6);

									if(cir[1][5] == cir_x[1][56] && cir[1][6] == cir_y[1][56]){
										cir[1][4] = -1;
									}

									turn = 14;
									player_turn = 2;
								}
								turndq=0;
							}
						}

						//if 3rd cir is clicked
						if((cir[1][7]==1 && bl3 <=50) || (cir[1][7]==1 && condit1(1, 8, 9)==1) ){
							if(mx >= cir[1][8] - 17 && my >= cir[1][9] - 17 && mx <= cir[1][8] + 17 && my<= cir[1][9] + 17){
								if(turndq==1){
									if(cir[1][7]==1 && bl3 <=50){
										movecoin(1, 8, 9, bl3);
										bl3 = bl3 + dice;
										blue_power(8,9);
									}
									else
										condit(1, 8, 9);

									if(cir[1][8] == cir_x[1][56] && cir[1][9] == cir_y[1][56]){
										cir[1][7] = -1;
									}

									turn = 14;
									player_turn = 2;
								}
								turndq=0;
							}
						}

						if((cir[1][10]==1 && bl4 <=50) || (cir[1][10]==1 && condit1(1, 11, 12)==1) ){
							if(mx >= cir[1][11] - 17 && my >= cir[1][12] - 17 && mx <= cir[1][11] + 17 && my<= cir[1][12] + 17){
								if(turndq==1){
									if(cir[1][10]==1 && bl4 <=50){
										movecoin(1, 11, 12, bl4);
										bl4 = bl4 + dice;
										blue_power(11,12);
									}

									else
										condit(1, 11, 12);

									if(cir[1][11] == cir_x[1][56] && cir[1][12] == cir_y[1][56]){
										cir[1][10] = -1;
									}

									turn = 14;
									player_turn = 2;

								}
								turndq=0;
							}
						}
					}// turn ends here
				}//player turn ends here


				if(player_turn == 2){

					if(turn == 14){
						if(mx >= 800 && my >= 300 && mx <= 880 && my <= 380){

							random();
							printf(" Red Odd has been clicked ");

							if(dice==6){
								player_turn = 2;
								turn = 5;
								turndx=3;
							}

							else{
								if(((cir[2][1]==1 && rd1 <=50) || (cir[2][1]==1 && condit1(2, 2, 3)==1) )  || ((cir[2][4]==1 && rd2 <=50) || (cir[2][4]==1 && condit1(2, 5, 6)==1) ) || ((cir[2][7]==1 && rd3 <=50) || (cir[2][7]==1 && condit1(2, 8, 9)==1) ) || ((cir[2][10]==1 && rd4 <=50) || (cir[2][10]==1 && condit1(2, 11, 12)==1)))
								{
									turn = 15;
								}

								else{
									player_turn = 3;
									turn = 16;
								}
							}
						}
					}

					if(turn == 15){
						turndw=1;
						if((cir[2][1]==1 && rd1 <=50) || (cir[2][1]==1 && condit1(2, 2, 3)==1) ){
							//if 1st cir is clicked
							if(mx >= cir[2][2] - 17 && my >= cir[2][3] - 17 && mx <= cir[2][2] + 17 && my<= cir[2][3] + 17){
								if(turndw==1){
									if(cir[2][1]==1 && rd1 <=50){
										movecoin(2, 2, 3, rd1);
										rd1 = rd1 + dice;
										red_power(2,3);
									}
									else
										condit(2, 2, 3);

									if(cir[2][2] == cir_x[2][56] && cir[2][3] == cir_y[2][56]){
										cir[2][1] = -1;
									}

									player_turn = 3;
									turn = 16;
								}
								turndw=0;
							}
						}

						//if 2nd cir is clicked
						if((cir[2][4]==1 && rd2 <=50) || (cir[2][4]==1 && condit1(2, 5, 6)==1) ){
							if(mx >= cir[2][5] - 17 && my >= cir[2][6] - 17 && mx <= cir[2][5] + 17 && my<= cir[2][6] + 17){
								if(turndw==1){
									if(cir[2][4]==1 && rd2 <=50){
										movecoin(2, 5, 6, rd2);
										rd2 = rd2 + dice;
										red_power(5,6);
									}
									else
										condit(2, 5, 6);

									if(cir[2][5] == cir_x[2][56] && cir[2][3] == cir_y[2][56]){
										cir[2][4] = -1;
									}


									player_turn = 3;
									turn = 16;
								}
								turndw=0;
							}
						}

						//if 3rd cir is clicked
						if((cir[2][7]==1 && rd3 <=50) || (cir[2][7]==1 && condit1(2, 8, 9)==1) ){
							if(mx >= cir[2][8] - 17 && my >= cir[2][9] - 17 && mx <= cir[2][8] + 17 && my<= cir[2][9] + 17){
								if(turndw==1){
									if(cir[2][7]==1 && rd3 <=50){
										movecoin(2, 8, 9, rd3);
										rd3 = rd3 + dice;
										red_power(8,9);
									}
									else
										condit(2, 8, 9);

									if(cir[2][8] == cir_x[2][56] && cir[2][9] == cir_y[2][56]){
										cir[2][7] = -1;
									}

									player_turn = 3;
									turn = 16;
								}
								turndw=0;
							}
						}

						if((cir[2][10]==1 && rd4 <=50) || (cir[2][10]==1 && condit1(2, 11, 12)==1) ){
							//if 4th cir is clicked
							if(mx >= cir[2][11] - 17 && my >= cir[2][12] - 17 && mx <= cir[2][11] + 17 && my<= cir[2][12] + 17){
								if(turndw==1){
									if(cir[2][10]==1 && rd4 <=50){
										movecoin(2, 11, 12, rd4);
										rd4 = rd4 + dice;
										red_power(11,12);
									}
									else
										condit(2, 11, 12);

									if(cir[2][11] == cir_x[2][56] && cir[2][12] == cir_y[2][56]){
										cir[2][10] = -1;
									}

									player_turn = 3;
									turn = 16;
								}
								turndw=0;
							}
						}
					}//turn ends here
				}//player turn ends here

				if(player_turn == 3){

					if(turn == 16){
						if(mx >= 880 && my >= 300 && mx <= 960 && my <= 380){

							random();
							printf(" Green Odd has been clicked ");

							if(dice==6){
								player_turn = 3;
								turn = 7;
								turndx = 4;
							}

							else{
								if(((cir[3][1]==1 && gr1 <=50) || (cir[3][1]==1 && condit1(3, 2, 3)==1) )  || ((cir[3][4]==1 && gr2 <=50) || (cir[3][4]==1 && condit1(3, 5, 6)==1))  || (((cir[3][7]==1 && gr3 <=50) || (cir[3][7]==1 && condit1(3, 8, 9)==1) )) || ((cir[3][10]==1 && gr4 <=50) || (cir[3][10]==1 && condit1(3, 11, 12)==1) ))
								{
									turn = 17;
								}

								else{
									player_turn = 0;
									turn = 0;
								}
							}
						}
					}

					if(turn == 17){
						turnde=1;
						if((cir[3][1]==1 && gr1 <=50) || (cir[3][1]==1 && condit1(3, 2, 3)==1) ){
							//if 1st cir is clicked
							if(mx >= cir[3][2] - 17 && my >= cir[3][3] - 17 && mx <= cir[3][2] + 17 && my<= cir[3][3] + 17){
								if(turnde==1){
									if(cir[3][1]==1 && gr1 <=50){
										movecoin(3, 2, 3, gr1);
										gr1 = gr1 + dice;
										green_power(2,3);
									}

									else
										condit(3, 2, 3);

									if(cir[3][2] == cir_x[3][56] && cir[3][3] == cir_y[3][56]){
										cir[3][1] = -1;
									}

									player_turn = 0;
									turn = 0;
								}
								turnde=0;
							}
						}

						if((cir[3][4]==1 && gr2 <=50) || (cir[3][4]==1 && condit1(3, 5, 6)==1) ){
							//if 2nd cir is clicked
							if(mx >= cir[3][5] - 17 && my >= cir[3][6] - 17 && mx <= cir[3][5] + 17 && my<= cir[3][6] + 17){
								if(turnde==1){
									if(cir[3][4]==1 && gr2 <=50){
										movecoin(3, 5, 6, gr2);
										gr2 = gr2 + dice;
										green_power(5,6);
									}
									else
										condit(3, 5, 6);

									if(cir[3][5] == cir_x[3][56] && cir[3][6] == cir_y[3][56]){
										cir[3][4] = -1;
									}

									player_turn = 0;
									turn = 0;
								}
								turnde=0;
							}
						}

						if((cir[3][7]==1 && gr3 <=50) || (cir[3][7]==1 && condit1(3, 8, 9)==1) ){
							//if 3rd cir is clicked
							if(mx >= cir[3][8] - 17 && my >= cir[3][9] - 17 && mx <= cir[3][8] + 17 && my<= cir[3][9] + 17){
								if(turnde==1){
									if(cir[3][7]==1 && gr3 <=50){
										movecoin(3, 8, 9, gr3);
										gr3 = gr3 + dice;
										green_power(8,9);
									}

									else
										condit(3, 8, 9);

									if(cir[3][8] == cir_x[3][56] && cir[3][9] == cir_y[3][56]){
										cir[3][7] = -1;
									}

									player_turn = 0;
									turn = 0;
								}
								turnde=0;
							}
						}

						if((cir[3][10]==1 && gr4 <=50) || (cir[3][10]==1 && condit1(3, 11, 12)==1) ){
							//if 4th cir is clicked
							if(mx >= cir[3][11] - 17 && my >= cir[3][12] - 17 && mx <= cir[3][11] + 17 && my<= cir[3][12] + 17){
								if(turnde==1){
									if(cir[3][10]==1 && gr4 <=50){
										movecoin(3, 11, 12, gr4);
										gr4 = gr4 + dice;
										green_power(11,12);
									}
									else
										condit(3, 11, 12);

									if(cir[3][11] == cir_x[3][56] && cir[3][12] == cir_y[3][56]){
										cir[3][10] = -1;
									}

									player_turn = 0;
									turn = 0;
								}
								turnde=0;
							}
						}

					}//turn ends here

				}//player turn ends here


			}//odd dice ends here

		}
	}
}

void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		exit(0);
	}
	//place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
}


int main()
{

	iInitialize(1000, 700, "demooo");
	return 0;
}
