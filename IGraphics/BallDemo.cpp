/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
#include <stdio.h>
#include <string.h>
#define PI 3.14159265

#include <math.h>
int pic_x, pic_y, d = 0;
int criticalzone_for_house = 4;
double Angle = 0;
int timing_for_end_page_after_bombing_house = 0, poo = 0;
int position = 1, direction_of_fly = 2;
double v1 = 70, fly_1_x, fly_1_y, fly_1_degree = 0, initial_fly_1_x = 1700, initial_fly_1_y = 580, boom_x_ball_1 = 0, boom_y_ball_1 = 0;//950 500
double initial_fly_2_x = 1500, initial_fly_2_y = 500, fly_2_degree = 0, fly_2_x, fly_2_y;//1 for going up 800 200
double initial_fly_3_x = 1600, initial_fly_3_y = 600, fly_3_y_condition = 2, fly_3_y, fly_3_x, fly_3_t_y = 0, fly_3_t_x = 0;
double fly_4_x, fly_4_y, initial_fly_4_x = 1200, initial_fly_4_y = 400, fly_4_y_condition = 1, fly_4_y_subcondition, fly_4_degree = 0, fly_4_v = 70, fly_4_a = 1.5, fly_4_t = 0, initial_fly_4_y_2 = 470, initial_fly_4_x_2 = 700, initial_fly_y_4_3, initial_fly_x_4_3;
double g1, f1, g2, f2, g3, f3, g4, f4, boom_for_target_for_fly_1_for_ball_1, boom_for_target_for_fly_2_for_ball_1, boom_for_target_for_fly_3_for_ball_1, boom_for_target_for_fly_4_for_ball_1;
double boom_for_target_for_fly_1_for_ball_2, boom_for_target_for_fly_2_for_ball_2, boom_for_target_for_fly_3_for_ball_2, boom_for_target_for_fly_4_for_ball_2;
double boom_for_target_for_fly_1_for_ball_3, boom_for_target_for_fly_2_for_ball_3, boom_for_target_for_fly_3_for_ball_3, boom_for_target_for_fly_4_for_ball_3;
double boom_for_target_for_fly_1_for_ball_4, boom_for_target_for_fly_2_for_ball_4, boom_for_target_for_fly_3_for_ball_4, boom_for_target_for_fly_4_for_ball_4;
char time2[100], foo[90];
int hoise = 0, flag = 0;//flag 0 for continue,1 for pause
int score = 0, time_to_kill = 0, special_condition_for_fly_2 = 0, time_total = 180, min, sec, xo = 990, noo = 160, uff = 830;
char scores[10], hoo[20];
char maximum[10], nijerscore[10];
int maximumscore, amarscore;
int alive_person = 6, play_pain_sound = 0, gamepage = 10;
double initial_ball_1_x, initial_ball_1_y, initial_ball_2_x, initial_ball_2_y, initial_ball_3_x, initial_ball_3_y, initial_ball_4_x, initial_ball_4_y, ball_1_x, ball_1_y, ball_2_x, ball_2_y, ball_3_x, ball_3_y, ball_4_x, ball_4_y, start_for_ball_1 = 0, start_for_ball_2 = 0, start_for_ball_3 = 0, start_for_ball_4 = 0, time_for_ball_1 = 0, time_for_ball_2 = 0, time_for_ball_3 = 0, time_for_ball_4 = 0;
int bomb = 4, wow = 100;
char ko[] = "press end button to exit";
char victory[] = "congratulation you got new high score";
char scoretobeadded[];
double velocity = 100;
double angle1, angle2, angle3, angle4;
/*
	function iDraw() is called again and again by the system. gamepage 10 front page,1 game over,4 mainpage or selection page,5 for highscore showing page/akaimma pola,6 for rules
*/
void iDraw()
{
	//place your drawing codes here	
	iClear();
	printf("%d", gamepage);
	FILE *fp;
	fp = fopen("highscore.txt", "r");
	fscanf(fp, "%d", &maximumscore);
	fclose(fp);
	iSetColor(255, 0, 0);
	sprintf(time2, "Time:%d:%d", min, sec);
	sprintf(scores, "score %d", score);
	if (gamepage == 4) {

		iShowBMP(0, 0, "image//secondPage.bmp");
	}
	else if (gamepage == 10) {
		iShowBMP(0, 0, "image//firstPage.bmp");

	}
	else if (gamepage == 5) {
		iShowBMP(0, 0, "image//akaimmapolaa1.bmp");
		sprintf(hoo, "high score %d", maximumscore);
		iSetColor(255, 0, 0);
		iText(150, 100, hoo, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (gamepage == 6) {
		iShowBMP(0, 0, "image//niyom1.bmp");
	}
	if (time_total == 0) {
		gamepage = 1;
	}
	if (poo == 1 && timing_for_end_page_after_bombing_house == 2) {
		poo = 0;
		gamepage = 1;
	}
	if (gamepage == 8) {
		iShowBMP(0, 0, "image//pause.bmp");
	}
	else if (gamepage == 0) {
		iSetColor(255, 255, 255);
		switch (criticalzone_for_house) {
		case 4:
			iShowBMP(0, 0, "image//baaal.bmp");
			break;
		case 3:
			iShowBMP(0, 0, "image//fire 1.bmp");
			break;
		case 2:
			iShowBMP(0, 0, "image//fire 2.bmp");
			break;
		case 1:
			iShowBMP(0, 0, "image//fire 3.bmp");
			break;
		case 0:
			iShowBMP(0, 0, "image//fire 4.bmp");
			poo = 1;
			break;
		}
		iRotationStart(pic_x, pic_y, Angle);
		drawTexture(-64, -64, smurfTexture);
		iRotationStop(pic_x, pic_y);
		iSetColor(0, 0, 0);
		iText(500, 10, scores, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 10, time2, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 100, foo, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (play_pain_sound == 1 && gamepage == 0) {
		PlaySound("sound//pain", NULL, SND_ASYNC);
		score -= 10;
		alive_person--;
		play_pain_sound = 0;
		if (alive_person == 0 || time_total <= 0) {
			iShowBMP(0, 0, "image//eng game.bmp");
			gamepage = 1;
		}
	}
	if (gamepage == 1) {
		amarscore = score;
		if (amarscore > maximumscore) {
			d = 1;
		}
		if (d == 1)
		{
			iShowBMP(0, 0, "image//win.bmp");

		}
		else
		{
			iShowBMP(0, 0, "image//eng game.bmp");
		}


		if (d == 1) {
			iSetColor(0, 0, 0);

			iText(10, 200, victory, GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(255, 0, 0);
		}
		else {
			iSetColor(0, 0, 0);
			sprintf(hoo, "high score %d", maximumscore);
			iText(200, 120, hoo, GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(255, 0, 0);
		}
		//iText(150,100,scores,GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 0, 0);
		iText(1000, 220, ko, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 160, scores, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 0, 0);
	}
	if (gamepage == 0) {
		iSetColor(255, 255, 255);
		iShowBMP(fly_2_x, fly_2_y, "image/Fly2.BMP");
		iShowBMP(fly_1_x, fly_1_y, "image/Fly2.BMP");
		iShowBMP(fly_3_x, fly_3_y, "image/Fly2.BMP");
		iShowBMP(fly_4_x, fly_4_y, "image/Fly2.BMP");
		
		iSetColor(0, 100, 0);
		iFilledRectangle(900, 100, 400, 20);
		iSetColor(255, 0, 0);
		switch (criticalzone_for_house) {
		case 3:
			iFilledRectangle(1200, wow, wow, 20);
			break;
		case 2:
			iFilledRectangle(1100, wow, wow, 20);
			iFilledRectangle(1200, wow, wow, 20);
			break;
		case 1:
			iFilledRectangle(1100, wow, wow, 20);
			iFilledRectangle(1200, wow, wow, 20);
			iFilledRectangle(1000, wow, wow, 20);
			break;
		}
		if (score >= 20 && score <= 50) {
			bomb = 3;
		}
		else if (score >= 50 && score <= 100) {
			bomb = 2;
		}
		else if (score >= 100) {
			bomb = 1;
		}
		iSetColor(255, 255, 255);
		switch (bomb) {
		case 4:
			iShowBMP(xo, noo, "image//bomb.bmp");
			iShowBMP(xo + 80, noo, "image//bomb.bmp");
			iShowBMP(xo + 160, noo, "image//bomb.bmp");
			iShowBMP(xo + 240, noo, "image//bomb.bmp");
			break;
		case 3:
			iShowBMP(xo + 80, noo, "image//bomb.bmp");
			iShowBMP(xo + 160, noo, "image//bomb.bmp");
			iShowBMP(xo + 240, noo, "image//bomb.bmp");
			break;
		case 2:
			iShowBMP(xo + 160, noo, "image//bomb.bmp");
			iShowBMP(xo + 240, noo, "image//bomb.bmp");
			break;
		case 1:
			iShowBMP(xo + 240, noo, "image//bomb.bmp");
			break;
		}
		if (alive_person == 6) {
			iShowBMP(uff, 0, "image//fever.bmp");
			iShowBMP(uff + 80, 0, "image//fever.bmp");
			iShowBMP(uff + 160, 0, "image//fever.bmp");
			iShowBMP(uff + 240, 0, "image//fever.bmp");
			iShowBMP(uff + 320, 0, "image//fever.bmp");
			iShowBMP(uff + 400, 0, "image//fever.bmp");
		}
		else if (alive_person == 5) {
			iShowBMP(uff, 0, "image//grave.bmp");
			iShowBMP(uff + 80, 0, "image//fever.bmp");
			iShowBMP(uff + 160, 0, "image//fever.bmp");
			iShowBMP(uff + 240, 0, "image//fever.bmp");
			iShowBMP(uff + 320, 0, "image//fever.bmp");
			iShowBMP(uff + 400, 0, "image//fever.bmp");
		}
		else if (alive_person == 4) {
			iShowBMP(uff, 0, "image//grave.bmp");
			iShowBMP(uff + 80, 0, "image//grave.bmp");
			iShowBMP(uff + 160, 0, "image//fever.bmp");
			iShowBMP(uff + 240, 0, "image//fever.bmp");
			iShowBMP(uff + 320, 0, "image//fever.bmp");
			iShowBMP(uff + 400, 0, "image//fever.bmp");
		}
		else if (alive_person == 3) {
			iShowBMP(uff, 0, "image//grave.bmp");
			iShowBMP(uff + 80, 0, "image//grave.bmp");
			iShowBMP(uff + 160, 0, "image//grave.bmp");
			iShowBMP(uff + 240, 0, "image//fever.bmp");
			iShowBMP(uff + 320, 0, "image//fever.bmp");
			iShowBMP(uff + 400, 0, "image//fever.bmp");
		}
		else if (alive_person == 2) {
			iShowBMP(uff, 0, "image//grave.bmp");
			iShowBMP(uff + 80, 0, "image//grave.bmp");
			iShowBMP(uff + 160, 0, "image//grave.bmp");
			iShowBMP(uff + 240, 0, "image//grave.bmp");
			iShowBMP(uff + 320, 0, "image//fever.bmp");
			iShowBMP(uff + 400, 0, "image//fever.bmp");
		}
		else if (alive_person == 1) {
			iShowBMP(uff, 0, "image//grave.bmp");
			iShowBMP(uff + 80, 0, "image//grave.bmp");
			iShowBMP(uff + 160, 0, "image//grave.bmp");
			iShowBMP(uff + 240, 0, "image//grave.bmp");
			iShowBMP(uff + 320, 0, "image//grave.bmp");
			iShowBMP(uff + 400, 0, "image//fever.bmp");
		}
		g1 = fly_1_x + 32, f1 = fly_1_y + 26, g2 = fly_2_x + 32, f2 = fly_2_y + 26, g3 = fly_3_x + 32, f3 = fly_3_y + 26, g4 = fly_4_x + 32, f4 = fly_4_y + 26;
		if (start_for_ball_1 == 1) {
			iSetColor(0, 0, 0);
			iFilledCircle(ball_1_x, ball_1_y, 10);
			boom_for_target_for_fly_1_for_ball_1 = pow(ball_1_x - g1, 2) + pow(ball_1_y - f1, 2);
			boom_for_target_for_fly_1_for_ball_1 = sqrt(boom_for_target_for_fly_1_for_ball_1);
			boom_for_target_for_fly_2_for_ball_1 = pow(ball_1_x - g2, 2) + pow(ball_1_y - f2, 2);
			boom_for_target_for_fly_2_for_ball_1 = sqrt(boom_for_target_for_fly_2_for_ball_1);
			boom_for_target_for_fly_3_for_ball_1 = pow(ball_1_x - g3, 2) + pow(ball_1_y - f3, 2);
			boom_for_target_for_fly_3_for_ball_1 = sqrt(boom_for_target_for_fly_3_for_ball_1);
			boom_for_target_for_fly_4_for_ball_1 = pow(ball_1_x - g4, 2) + pow(ball_1_y - f4, 2);
			boom_for_target_for_fly_4_for_ball_1 = sqrt(boom_for_target_for_fly_4_for_ball_1);
			if (ball_1_x >= 100 && ball_1_x <= 210 && ball_1_y >= 330 && ball_1_y <= 430) {
				criticalzone_for_house--;
				PlaySound("sound//bombing", NULL, SND_ASYNC);
				start_for_ball_1 = 0;
				time_for_ball_1 = 0;
				ball_1_x = -90, ball_1_y = -80;
			}
			else if (ball_1_y >= 680 || (ball_1_x == 0 && (time_for_ball_1 >= 2) || ball_1_x >= 1300)) {
				start_for_ball_1 = 0;
				time_for_ball_1 = 0;
				ball_1_x = -90, ball_1_y = -80;
			}
			else if (boom_for_target_for_fly_1_for_ball_1 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g1, f1, "image//Boom.bmp");
				score += 5;
				start_for_ball_1 = 0, time_for_ball_1 = 0;
				ball_1_x = -90, ball_1_y = -80;
				fly_1_degree = 0;

			}
			else if (boom_for_target_for_fly_2_for_ball_1 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g2, f2, "image//Boom.bmp");
				score += 5;
				start_for_ball_1 = 0, time_for_ball_1 = 0;
				fly_2_degree = 0;
				ball_1_x = -90, ball_1_y = -80;
			}
			else if (boom_for_target_for_fly_3_for_ball_1 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g3, f3, "image//Boom.bmp");
				score += 5;
				start_for_ball_1 = 0, time_for_ball_1 = 0;
				fly_3_t_x = 0, fly_3_t_y = 0, fly_3_y_condition = 2;
				ball_1_x = -90, ball_1_y = -80;
			}
			else if (boom_for_target_for_fly_4_for_ball_1 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g4, f4, "image//Boom.bmp");
				start_for_ball_1 = 0, time_for_ball_1 = 0;
				score += 5;
				fly_4_y_condition = 1, fly_4_degree = 0, fly_4_t = 0;
				ball_1_x = -90, ball_1_y = -80;
			}
		}
		if (start_for_ball_2 == 1) {
			iSetColor(0, 0, 0);
			iFilledCircle(ball_2_x, ball_2_y, 10);
			boom_for_target_for_fly_1_for_ball_2 = pow(ball_2_x - g1, 2) + pow(ball_2_y - f1, 2);
			boom_for_target_for_fly_1_for_ball_2 = sqrt(boom_for_target_for_fly_1_for_ball_2);
			boom_for_target_for_fly_2_for_ball_2 = pow(ball_2_x - g2, 2) + pow(ball_2_y - f2, 2);
			boom_for_target_for_fly_2_for_ball_2 = sqrt(boom_for_target_for_fly_2_for_ball_2);
			boom_for_target_for_fly_3_for_ball_2 = pow(ball_2_x - g3, 2) + pow(ball_2_y - f3, 2);
			boom_for_target_for_fly_3_for_ball_2 = sqrt(boom_for_target_for_fly_3_for_ball_2);
			boom_for_target_for_fly_4_for_ball_2 = pow(ball_2_x - g4, 2) + pow(ball_2_y - f4, 2);
			boom_for_target_for_fly_4_for_ball_2 = sqrt(boom_for_target_for_fly_4_for_ball_2);
			if (ball_2_x >= 100 && ball_2_x <= 210 && ball_2_y >= 330 && ball_2_y <= 430) {
				criticalzone_for_house--;
				PlaySound("sound//bombing", NULL, SND_ASYNC);
				start_for_ball_2 = 0;
				time_for_ball_2 = 0;
				ball_2_x = -90, ball_2_y = -80;
			}
			else if (ball_2_y >= 680 || (ball_2_x == 0 && (time_for_ball_2 >= 2) || ball_2_x >= 1300)) {
				start_for_ball_2 = 0;
				time_for_ball_2 = 0;
				ball_2_x = -80, ball_2_y = -80;
			}
			else if (boom_for_target_for_fly_1_for_ball_2 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g1, f1, "image//Boom.bmp");
				score += 5;
				start_for_ball_2 = 0, time_for_ball_2 = 0;
				fly_1_degree = 0;
				ball_2_x = -80, ball_2_y = -80;
			}
			else if (boom_for_target_for_fly_2_for_ball_2 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g2, f2, "image//Boom.bmp");
				score += 5;
				start_for_ball_2 = 0, time_for_ball_2 = 0;
				fly_2_degree = 0;
				ball_2_x = -80, ball_2_y = -80;
			}
			else if (boom_for_target_for_fly_3_for_ball_2 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g3, f3, "image//Boom.bmp");
				score += 5;
				start_for_ball_2 = 0, time_for_ball_2 = 0;
				fly_3_t_x = 0, fly_3_t_y = 0, fly_3_y_condition = 2;
				ball_2_x = -80, ball_2_y = -80;
			}
			else if (boom_for_target_for_fly_4_for_ball_2 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g4, f4, "image//Boom.bmp");
				score += 5;
				start_for_ball_2 = 0, time_for_ball_2 = 0;
				fly_4_y_condition = 1, fly_4_degree = 0, fly_4_t = 0;
				ball_2_x = -80, ball_2_y = -80;
			}
		}

		if (start_for_ball_3 == 1) {
			iSetColor(0, 0, 0);
			iFilledCircle(ball_3_x, ball_3_y, 10);

			boom_for_target_for_fly_1_for_ball_3 = pow(ball_3_x - g1, 2) + pow(ball_3_y - f1, 2);
			boom_for_target_for_fly_1_for_ball_3 = sqrt(boom_for_target_for_fly_1_for_ball_3);
			boom_for_target_for_fly_2_for_ball_3 = pow(ball_3_x - g2, 2) + pow(ball_3_y - f2, 2);
			boom_for_target_for_fly_2_for_ball_3 = sqrt(boom_for_target_for_fly_2_for_ball_3);
			boom_for_target_for_fly_3_for_ball_3 = pow(ball_3_x - g3, 2) + pow(ball_3_y - f3, 2);
			boom_for_target_for_fly_3_for_ball_3 = sqrt(boom_for_target_for_fly_3_for_ball_3);
			boom_for_target_for_fly_4_for_ball_3 = pow(ball_3_x - g4, 2) + pow(ball_3_y - f4, 2);
			boom_for_target_for_fly_4_for_ball_3 = sqrt(boom_for_target_for_fly_4_for_ball_3);
			if (ball_3_x >= 100 && ball_3_x <= 210 && ball_3_y >= 330 && ball_3_y <= 430) {
				criticalzone_for_house--;
				PlaySound("sound//bombing", NULL, SND_ASYNC);
				start_for_ball_3 = 0;
				time_for_ball_3 = 0;
				ball_3_x = -90, ball_3_y = -80;
			}
			else if (ball_3_y >= 680 || (ball_3_x == 0 && (time_for_ball_3 >= 2) || ball_3_x >= 1300)) {
				start_for_ball_3 = 0;
				time_for_ball_3 = 0;
				ball_3_x = -80, ball_3_y = -80;
			}
			else if (boom_for_target_for_fly_1_for_ball_3 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g1, f1, "image//Boom.bmp");
				score += 5;
				start_for_ball_3 = 0, time_for_ball_3 = 0;
				fly_1_degree = 0;
				ball_3_x = -80, ball_3_y = -80;

			}
			else if (boom_for_target_for_fly_2_for_ball_3 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g2, f2, "image//Boom.bmp");
				score += 5;
				start_for_ball_3 = 0, time_for_ball_3 = 0;
				fly_2_degree = 0;
				ball_3_x = -80, ball_3_y = -80;
			}
			else if (boom_for_target_for_fly_3_for_ball_3 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g3, f3, "image//Boom.bmp");
				score += 5;
				start_for_ball_3 = 0, time_for_ball_3 = 0;
				fly_3_t_x = 0, fly_3_t_y = 0, fly_3_y_condition = 2;
				ball_3_x = -80, ball_3_y = -80;
			}
			else if (boom_for_target_for_fly_4_for_ball_3 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g4, f4, "image//Boom.bmp");
				score += 5;
				start_for_ball_3 = 0, time_for_ball_3 = 0;
				ball_3_x = -80, ball_3_y = -80;
				fly_4_y_condition = 1, fly_4_degree = 0, fly_4_t = 0;
			}
		}

		if (start_for_ball_4 == 1) {
			iSetColor(0, 0, 0);
			iFilledCircle(ball_4_x, ball_4_y, 10);

			boom_for_target_for_fly_1_for_ball_4 = pow(ball_4_x - g1, 2) + pow(ball_4_y - f1, 2);
			boom_for_target_for_fly_1_for_ball_4 = sqrt(boom_for_target_for_fly_1_for_ball_4);
			boom_for_target_for_fly_2_for_ball_4 = pow(ball_4_x - g2, 2) + pow(ball_4_y - f2, 2);
			boom_for_target_for_fly_2_for_ball_4 = sqrt(boom_for_target_for_fly_2_for_ball_4);
			boom_for_target_for_fly_3_for_ball_4 = pow(ball_4_x - g3, 2) + pow(ball_4_y - f3, 2);
			boom_for_target_for_fly_3_for_ball_4 = sqrt(boom_for_target_for_fly_3_for_ball_4);
			boom_for_target_for_fly_4_for_ball_4 = pow(ball_4_x - g4, 2) + pow(ball_4_y - f4, 2);
			boom_for_target_for_fly_4_for_ball_4 = sqrt(boom_for_target_for_fly_4_for_ball_4);
			if (ball_4_x >= 100 && ball_4_x <= 210 && ball_4_y >= 330 && ball_4_y <= 430) {
				criticalzone_for_house--;
				PlaySound("sound//bombing", NULL, SND_ASYNC);
				start_for_ball_4 = 0;
				time_for_ball_4 = 0;
				ball_4_x = -90, ball_4_y = -80;
			}
			else if (ball_4_y >= 680 || (ball_4_x == 0 && (time_for_ball_4 >= 2) || ball_4_x >= 1300)) {
				start_for_ball_4 = 0;
				time_for_ball_4 = 0;
				ball_4_x = -80, ball_4_y = -80;
			}
			else if (boom_for_target_for_fly_1_for_ball_4 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g1, f1, "image//Boom.bmp");
				score += 5;
				start_for_ball_4 = 0, time_for_ball_4 = 0;
				fly_1_degree = 0;
				ball_4_x = -80, ball_4_y = -80;

			}
			else if (boom_for_target_for_fly_2_for_ball_4 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g2, f2, "image//Boom.bmp");
				score += 5;
				start_for_ball_4 = 0, time_for_ball_4 = 0;
				fly_2_degree = 0;
				ball_4_x = -80, ball_4_y = -80;
			}
			else if (boom_for_target_for_fly_3_for_ball_4 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g3, f3, "image//Boom.bmp");
				score += 5;
				start_for_ball_4 = 0, time_for_ball_4 = 0;
				fly_3_t_x = 0, fly_3_t_y = 0, fly_3_y_condition = 2;
				ball_4_x = -80, ball_4_y = -80;
			}
			else if (boom_for_target_for_fly_4_for_ball_4 <= 35) {
				PlaySound("sound//Boomsound", NULL, SND_ASYNC);
				iShowBMP(g4, f4, "image//Boom.bmp");
				score += 5;
				start_for_ball_4 = 0, time_for_ball_4 = 0;
				fly_4_y_condition = 1, fly_4_degree = 0, fly_4_t = 0;
				ball_4_x = -80, ball_4_y = -80;
			}
		}

	}


}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gamepage == 10)
	{
		if (my >= 57 && my <= 271 && mx >= 49 && mx <= 263) {
			//gamepage=0;
			gamepage = 4;
			PlaySound("sound//click", NULL, SND_ASYNC);
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gamepage == 8) {
		if (my >= 158 && my <= 221 && mx >= 508 && mx <= 743) {
			exit(0);
		}
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gamepage == 5)
	{
		if (my >= 100 && my <= 210 && mx >= 780 && mx <= 1100) {
			//gamepage=0;
			gamepage = 4;
			PlaySound(0, 0, 0);

		}
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gamepage == 6)
	{
		if (my >= 30 && my <= 65 && mx >= 820 && mx <= 1200) {
			//gamepage=0;
			PlaySound(0, 0, 0);
			gamepage = 4;
		}
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gamepage == 4)
	{
		if (mx >= 420 && mx <= 883 & my >= 232 && my <= 312) {
			gamepage = 5;
			PlaySound("sound//highscore", NULL, SND_ASYNC);
		}
		else if (mx >= 420 && mx <= 883 && my >= 324 && my <= 407) {
			gamepage = 6;
			PlaySound("sound//voiceforniyom1", NULL, SND_ASYNC);

		}
		else if (mx >= 420 && mx <= 838 && my >= 420 && my <= 502) {
			gamepage = 0;
			PlaySound("sound//click", NULL, SND_ASYNC);
		}
		else if (mx >= 420 && mx <= 838 && my >= 138 && my <= 220) {

			exit(0);
		}
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gamepage == 0)
	{

		double dx = (double)(mx - pic_x);
		double dy = (double)(my - pic_y);

		double x = dy / dx;

		Angle = atan(x) * 180 / PI;


		double manginutde = sqrt(dx*dx + dy * dy);

		velocity = 0.25*manginutde;

		printf("%lf\n", manginutde);


		if (dx < 0 && dy>0)Angle = Angle + 180;
		else if (dx < 0 && dy < 0) Angle = Angle + 180;

		if (Angle > 360)Angle -= 360;

		printf("%lf\n", manginutde);




		if (start_for_ball_1 == 0) {
			angle1 = Angle;
			start_for_ball_1 = 1;
			time_for_ball_1 = 0;
			initial_ball_1_x = 164 + 210 * cos((angle1 + 1)*(PI / 180));
			initial_ball_1_y = 64 + 210 * sin((angle1 + 1)*(PI / 180));
		}
		else if (start_for_ball_2 == 0 && score <= 100) {
			angle2 = Angle;
			start_for_ball_2 = 1;
			time_for_ball_2 = 0;
			initial_ball_2_x = 164 + 210 * cos((Angle + 1)*(PI / 180));
			initial_ball_2_y = 64 + 210 * sin((Angle + 1)*(PI / 180));
		}
		else if (start_for_ball_3 == 0 && score <= 50) {
			angle3 = Angle;
			start_for_ball_3 = 1;
			time_for_ball_3 = 0;
			initial_ball_3_x = 164 + 210 * cos((Angle + 1)*(PI / 180));
			initial_ball_3_y = 64 + 210 * sin((Angle + 1)*(PI / 180));
		}
		else if (start_for_ball_4 == 0 && score <= 20) {
			angle4 = Angle;
			start_for_ball_4 = 1;
			time_for_ball_4 = 0;
			initial_ball_4_x = 164 + 210 * cos((Angle + 1)*(PI / 180));
			initial_ball_4_y = 64 + 210 * sin((Angle + 1)*(PI / 180));
		}
		//place your codes here	

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'p'&&gamepage == 0)
	{
		//flag=1;
		gamepage = 8;

		//do something with 'q'
	}
	if (key == 'r') {
		//flag=0;
		gamepage = 0;
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
void iMouseHover(int mx, int my)
{
	if (gamepage == 0) {
		double dx = (double)(mx - pic_x);
		double dy = (double)(my - pic_y);

		double x = dy / dx;

		Angle = atan(x) * 180 / PI;


		//double manginutde=sqrt(dx*dx+dy*dy);

		//velocity=0.2*manginutde;

		//printf("%lf\n",manginutde);


		if (dx < 0 && dy>0)Angle = Angle + 180;
		else if (dx < 0 && dy < 0) Angle = Angle + 180;

		if (Angle > 360)Angle -= 360;
	}

}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END && gamepage == 1)
	{
		if (d == 1) {
			FILE *fp;
			fp = fopen("highscore.txt", "w");
			fprintf(fp, "%d", score);
			fclose(fp);
			exit(0);
		}
		exit(0);
	}
	//place your codes for other keys here
}

void fly()
{
	if (gamepage == 0) {
		fly_1_degree += 20;
		fly_1_x = initial_fly_1_x - fly_1_degree;
		fly_1_y = initial_fly_1_y - 20 * sin(fly_1_degree);
		if (fly_1_x <= -1000) {
			fly_1_degree = 0;
		}
	}
}
void secondfly()
{
	if (gamepage == 0) {
		if (fly_2_x <= 200 && fly_2_x >= 10 && time_to_kill % 5 == 0 && special_condition_for_fly_2 == 0) {
			special_condition_for_fly_2 = 1;
			play_pain_sound = 0;
		}
		if (special_condition_for_fly_2 == 1) {
			fly_2_y -= 5;
			play_pain_sound = 0;
			if (fly_2_y <= 430) {
				play_pain_sound = 1;
				//alive_person--;
				special_condition_for_fly_2 = 0;
				fly_2_degree = 0;
				fly_2_x = initial_fly_2_x;
				fly_2_y = initial_fly_2_y;
			}
		}
		else if (special_condition_for_fly_2 == 0) {
			play_pain_sound = 0;
			fly_2_x = initial_fly_2_x - fly_2_degree;
			fly_2_y = initial_fly_2_y - 40 * sin(fly_2_degree);
			fly_2_degree += 40;
			if (fly_2_x <= -100) {
				play_pain_sound = 0;
				fly_2_degree = 0;
			}
		}
	}
}



void thirdfly()
{
	if (gamepage == 0) {

		if (fly_3_x <= -300) {
			fly_3_t_x = 0;
			fly_3_t_y = 0;
			fly_3_y_condition = 2;
		}
		fly_3_x = initial_fly_3_x - fly_3_t_x * 20;
		if (score > 30) {
			fly_3_t_x += 2;
		}
		else {
			fly_3_t_x++;
		}
		if (fly_3_y_condition == 2) {
			if (fly_3_y != 500) {
				fly_3_y = initial_fly_3_y - fly_3_t_y * 20;
				fly_3_t_y++;
			}
			else {
				fly_3_t_y = 0;
				fly_3_y_condition = 1;
			}
		}
		if (fly_3_y_condition == 1) {
			if (fly_3_y != 600) {
				fly_3_y = initial_fly_3_y + fly_3_t_y * 20;
				fly_3_t_y++;
			}
			else {
				fly_3_y_condition = 2;
				fly_3_t_y = 0;
			}
		}
	}
}

void fourthfly()
{
	if (gamepage == 0) {

		if (fly_4_y_condition == 1) {
			fly_4_x = initial_fly_4_x - fly_4_v * cos(45.0)*fly_4_t;
			fly_4_y = initial_fly_4_y + fly_4_v * sin(45.0)*fly_4_t - .5*fly_4_a*fly_4_t*fly_4_t;
			fly_4_t++;

		}
		if (fly_4_y > 600 && fly_4_y_condition == 1) {
			fly_4_y_condition = 2;
			fly_4_y_subcondition = 7;
			fly_4_t = 0;
		}
		if (fly_4_y_condition == 2) {
			if (fly_4_y_subcondition == 7) {
				fly_4_y = fly_4_y - 20;
				fly_4_x = fly_4_x - 20;
				if (fly_4_y <= 400) {
					fly_4_y_subcondition = 8;
				}
			}
			if (fly_4_y_subcondition == 8) {
				if (score > 30) {
					fly_4_y = fly_4_y + 20;
					fly_4_x = fly_4_x - 20;
				}
				else {
					fly_4_y = fly_4_y + 10;
					fly_4_x = fly_4_x - 10;
				}
				if (fly_4_y >= 500) {
					fly_4_y_condition = 3;
				}
			}
		}
		if (fly_4_y_condition == 3) {
			fly_4_y = initial_fly_4_y_2 + 20 * cos(fly_4_degree);
			fly_4_x = initial_fly_4_x_2 - fly_4_degree;
			fly_4_degree += 40;
			if (fly_4_x <= 270) {
				fly_4_y_condition = 5;
				initial_fly_y_4_3 = fly_4_y;
				initial_fly_x_4_3 = fly_4_x;
				fly_4_degree = 0;
			}
		}
		if (fly_4_y_condition == 5) {
			fly_4_y = initial_fly_y_4_3 + fly_4_v * sin(45.0)*fly_4_t + .5*fly_4_v*fly_4_t*fly_4_t;
			fly_4_x = initial_fly_x_4_3 - fly_4_v * cos(45.0)*fly_4_t;
			fly_4_t++;
			if (fly_4_x <= 250) {
				fly_4_y_condition = 6;
				fly_4_t = 0;
			}
		}
		if (fly_4_y_condition == 6) {
			if (score > 20) {
				fly_4_y = fly_4_y + 20;
			}
			else {
				fly_4_y = fly_4_y + 10;
			}
			fly_4_x = fly_4_x - 30;
			if (fly_4_x <= -200) {
				fly_4_y_condition = 1;
			}
		}
	}
}

void timer_for_enter_hospital()
{
	if (gamepage == 0) {
		time_to_kill++;
	}
}
void timing()
{
	if (gamepage == 0) {
		time_total--;
		min = time_total / 60;
		sec = time_total % 60;
	}
}
void ball1()
{
	if (gamepage == 0) {

		double decrement = 0.5;

		//printf("Velocity %lf\n",velocity);

		if (start_for_ball_1 == 1) {
			ball_1_x = initial_ball_1_x + velocity * time_for_ball_1*cos(angle1*(PI) / 180);
			ball_1_y = initial_ball_1_y + velocity * time_for_ball_1*sin(angle1*(PI) / 180) - .5 * 3 * pow(time_for_ball_1, 2);
			time_for_ball_1 += decrement;
		}
		if (start_for_ball_2 == 1) {
			ball_2_x = initial_ball_2_x + velocity * time_for_ball_2*cos(angle2*(PI) / 180);
			ball_2_y = initial_ball_2_y + velocity * time_for_ball_2*sin(angle2*(PI) / 180) - .5 * 3 * pow(time_for_ball_2, 2);
			time_for_ball_2 += decrement;
		}
		if (start_for_ball_3 == 1) {
			ball_3_x = initial_ball_3_x + velocity * time_for_ball_3*cos(angle3*(PI) / 180);
			ball_3_y = initial_ball_3_y + velocity * time_for_ball_3*sin(angle3*(PI) / 180) - .5 * 3 * pow(time_for_ball_3, 2);
			time_for_ball_3 += decrement;
		}
		if (start_for_ball_4 == 1) {
			ball_4_x = initial_ball_4_x + velocity * time_for_ball_4*cos(angle4*(PI) / 180);
			ball_4_y = initial_ball_4_y + velocity * time_for_ball_4*sin(angle4*(PI) / 180) - .5 * 3 * pow(time_for_ball_4, 2);
			time_for_ball_4 += decrement;
		}
	}
}
void timeforendpage()
{
	if (gamepage == 0) {
		if (poo == 1) {
			timing_for_end_page_after_bombing_house += 1;
		}
	}

}
int main()
{
	//place your own initialization codes here. 
	//textureInit();
	iSetTimer(30, fly);
	iSetTimer(1000, timer_for_enter_hospital);
	iSetTimer(200, secondfly);
	iSetTimer(300, thirdfly);
	iSetTimer(200, fourthfly);
	iSetTimer(1000, timing);
	iSetTimer(5, ball1);
	iSetTimer(1000, timeforendpage);
	pic_x = 164;
	pic_y = 64;

	iInitialize(1300, 650, "Mosha Marte kaman Daga");
	return 0;
}
