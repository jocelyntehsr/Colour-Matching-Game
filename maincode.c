/*=================================================================

              EDB 1023/ EEB1043  Structured Programming and Interfacing

             Bachelor of Electrical and Electronic Engineering

                       Universiti Teknologi PETRONAS

-------------------------------------------------------------------------------

SEPTEMBER 2019

Project Title: Color and Shape Matching Game

-------------------------------------------------------------------------------

 Author 1:  JOCELYN TEH SHUANG RU (18000847)

-------------------------------------------------------------------------------

 Author 2:  NGAI TZE XING (17008088)

-------------------------------------------------------------------------------

  Levels Achieved: Level 1, Level 2, Level 3

------------------------------------------------------------------------------
====================================================*/

#include <stdio.h>
#include "gfx.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void level1(int *marks1);
int check1(int checking[10], int a, int i);
void level2(int *marks2);
int check2(int checking[12], int a, int i);
void level3(int *marks3);

int main()
{
	time_t start1, end1;
	time_t start2, end2;
	time_t start3, end3;
	double time1,time2,time3;
	int ysize=800;
	int xsize=800;
	int marks1,marks2,marks3,x,y,win=0;
	
	char tt1[5],tt2[5],tt3[5];
	char marksan1[40]="The marks scored in Level 1 was ";
	char marksan2[40]="The marks scored in Level 2 was ";
	char marksan3[40]="The marks scored in Level 3 was ";
	char m1[5],m2[5],m3[5];
	char t1[90]="The time taken (in seconds) to complete Level 1 was ";
	char t2[90]="The time taken (in seconds) to complete Level 2 was ";
	char t3[90]="The time taken (in seconds) to complete Level 3 was ";
	
	char c;
	char *text1="Welcome to Color Matching Game";
	char *text2="Click anywhere to Continue"; 

	
	
	gfx_open(xsize,ysize,"Color Matching Game");
	
	/*Introduction*/
	
	gfx_color(225, 190, 231);
	gfx_text(text1,350,200);
	gfx_color(255, 205, 210);
	gfx_text(text2,350,300);
	
	while (1) {
	
		if (gfx_event_waiting()){
	
			c=gfx_wait();
			
			if (c==0x01 || c==0x02 || c==0x03) {
				gfx_clear();	
				break; }
			else if (c=='q')
				exit(0);
		}
	}
	
	/*Level 1 Slide*/
	
	gfx_color(255,255,255);
	gfx_text("Level 1",100,100);
	gfx_color(255,0,0);
	gfx_text("Please click the shapes with the same color",100,150);
	gfx_color(255,255,0);
	gfx_text("COMPLETE WITHIN 10 SECONDS!!!!!!",100,175);
	gfx_color(0,255,0);
	gfx_text("Once finished, click the [NEXT] button immediately",100,200);
	gfx_color(0,0,255); 
	gfx_text("HAVE FUN !!!!! ^.^",100,250);
	gfx_color(77, 208, 225); 
	gfx_text("If you are ready, click to begin the game !",100,275);
	gfx_text("Press 'Q' to quit ",100,300); 
	gfx_flush();
	
	
	while(1){
	c=gfx_wait();
	if (c==0x01 || c==0x02 || c==0x03) {
		gfx_clear();
		break; }
	else if (c=='q') {
		exit(0);}

	} 
	
	/*Level 1 Game*/
	time(&start1);
	level1(&marks1);
	time(&end1);
	time1= (end1-start1);
	printf("time used in level 1 %lf in seconds\n",time1);
	
	
	/*Level 1 marks*/
	gfx_color(255,255,0);
	if (time1<=10 && marks1>=5)
	{
		gfx_text("Congratulations! You have succeed in Level 1!",100,100);
		win++;
	}
	else
	{
		gfx_text("Sorry you have failed Level 1 :(",100,100);
	}
		
	snprintf(m1,5,"%d",marks1);
	strcat(marksan1,m1);
	gfx_text(marksan1,100,125);
	snprintf(tt1,5,"%.2f",time1);
	strcat(t1,tt1);
	gfx_text(t1,100,150);
	gfx_color(0,255,0); 
	gfx_text("IS IT TOO EASY?!?!",100,175);
	gfx_color(0,255,0); 
    gfx_text("LEVEL 2 IS WAITING FOR YOU!!!!",100,200);
    gfx_color(255,255,255);
	gfx_text("COMPLETE LEVEL 2 WITHIN 15 SECONDS",100,225);
	gfx_color(255,0,0); 
	gfx_text("Click to start to Level 2",100,250);
	gfx_text("Press 'Q' to quit",100,275); 
	
	while(1){
	c=gfx_wait();
	if (c==0x01 || c==0x02 || c==0x03) {
		gfx_clear();
		break; }
	else if (c=='q') {
		exit(0);}
	}
		
	/*Level 2 Game*/
	time(&start2);
	level2(&marks2);
	time(&end2);
	time2= (end2 - start2);
	
	printf("time used in level 2 %lf in seconds\n",time2);
	
	/*Level 2 Marks*/
	gfx_color(255,0,0); 
	if (time2<=15 && marks2>=6)
	{
		gfx_text("Congratulations! You have succeed in Level 2!",100,100);
		win++;
	}
	else
	{
		gfx_text("Sorry you have failed Level 2 :(",100,100);
	}
	snprintf(m2,5,"%d",marks2);
	strcat(marksan2,m2);
	gfx_text(marksan2,100,125);
	snprintf(tt2,5,"%.2f",time2);
	strcat(t2,tt2);
	gfx_text(t2,100,150);
	gfx_color(0,0,255); 
	gfx_text("TOO EASY?!?!?!",100,175);
	gfx_color(156, 39, 176); 
	gfx_text("Let's go to LEVEL 3!!!!",100,200);
	gfx_color(255,255,255);
	gfx_text("COMPLETE LEVEL 3 WITHIN 20 SECONDS!!!!",100,225);
	gfx_color(255,255,255); 
	gfx_text("Click anywhere to continue to Level 3",100,250);
	gfx_text("Press 'Q' to quit",100,275);
	
	while(1){
	c=gfx_wait();
	if (c==0x01 || c==0x02 || c==0x03) {
		gfx_clear();
		break; }
	else if (c=='q') {
		exit(0);}
	}
	
	/*Level 3 Game*/
	time(&start3);
	level3(&marks3);
	time(&end3);
	time3= (end3 - start3);
	printf("time used in level 3 %lf in seconds\n",time3);
	
	/*Level 3 marks*/
	gfx_color( 255, 167, 38 );
	if (time3<=20 && marks3>=15)
	{
		gfx_text("Congratulations! You have succeed in Level 3!",100,100);
		win++;
	}
	else
	{
		gfx_text("Sorry you have failed Level 3 :(",100,100);
	}
	
	gfx_color( 255, 111, 0);
	snprintf(m3,5,"%d",marks3);
	strcat(marksan3,m3);
	gfx_text(marksan3,100,125);
	snprintf(tt3,5,"%.2f",time3);
	strcat(t3,tt3);
	gfx_text(t3,100,150);
	gfx_color(255,255,255);
	gfx_text("Click anywhere to see the summary of the game!",100,175);
	gfx_text("Press 'Q' to quit",100,700);
	
	
	while(1){
	c=gfx_wait();
	if (c==0x01 || c==0x02 || c==0x03) {
		gfx_clear();
		break; }
	else if (c=='q') {
		exit(0);}
	}
	
	gfx_flush();
	
	
	/*Conclusion*/ 
	
	gfx_color(255,0,0);
	if (win==3)
	{
		gfx_text("Congratulations! You have won three out of three in this game!",100,50);
	}
	if (win==2) 
	{	
		gfx_text("Well done! You have won two out of three in the game!",100,50);
	}
	if (win==1)
	{
		gfx_text("Not bad... You have won a game out of three! Good try!",100,50);
	}
	if (win==0)
	{
		gfx_text("Try again! You can do this!",100,50);
	}
	
	gfx_color(0,255,0);
	gfx_text("These are the marks and the time you have achieved in this game!",100,100);
	gfx_text(marksan1,100,125);
	gfx_text(marksan2,100,150);
	gfx_text(marksan3,100,175);
	gfx_color(173,216,230);
	gfx_text(t1,500,125);
	gfx_text(t2,500,150);
	gfx_text(t3,500,175);
	
	gfx_color(225,190,231);	
	gfx_text("Thanks for playing!",100,200);
	gfx_text("Click anywhere to quit",100,225); 
	
	while(1){
	c=gfx_wait();
	if (c==0x01 || c==0x02 || c==0x03) {
		exit(0);
	}
	}

	
	return 0;

}

void level1(int *m1) 
{
	
	int xpos[10]={100,200,300,400,500,100,200,300,400,500};
	int ypos[10]={100,100,100,100,100,200,200,200,200,200};
	int i,j,a,d,checking[10],r,g,b,x1,y1,x2,y2,e,xcoor,ycoor;
	int n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,marks=0;
	char c;
	
	/*Color randomization*/
	srand(time(NULL));
	
	/*Shapes and color fill*/
	
		/*Randomize numbers and get the numbers*/
	for (i=0;i<10;i++)
	{
		a=rand()%10;
		a=check1(checking,a,i);	
		printf("i=%d a=%d\n",i,a);
		checking[i]=a;
	}
	
	
	for (j=0;j<5;j++)
	{
		r=rand()%255+1;
		g=rand()%255+1;
		b=rand()%255+1;
		gfx_color(r,g,b);
		
		d=checking[j];
		x1=xpos[d];
		y1=ypos[d];
		printf("j=%d dx=%d dy=%d\n",j,x1,y1);
		gfx_fillrectangle(x1,y1,100,100);
		
		e=checking[j+5];
		x2=xpos[e];
		y2=ypos[e];
		printf("j+5=%d ex=%d ey=%d\n",j+5,x2,y2);
		gfx_fillrectangle(x2,y2,100,100);
	
	}
		/*Grid*/
	gfx_color(255,255,255);
	gfx_rectangle(100,100,500,200);
	gfx_line(200,100,200,300);
	gfx_line(300,100,300,300);
	gfx_line(400,100,400,300);
	gfx_line(500,100,500,300);
	gfx_line(100,200,600,200); 
	
	gfx_color(191, 201, 202);
	gfx_fillrectangle(500,350,100,25);
	gfx_color(0,0,0);
	gfx_text("Next",520,360);
	
	/*Quit and determine color*/ 
	
	while (1)
	{

		if (gfx_event_waiting) {
		c=gfx_wait();
		xcoor=gfx_xpos();
		ycoor=gfx_ypos();
		
		n0=checking[0];
		n1=checking[5];
		
		if ((xcoor>xpos[n0] && xcoor<xpos[n0]+100) && (ycoor>ypos[n0] && ycoor<ypos[n0]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n1] && xcoor<xpos[n1]+100) && (ycoor>ypos[n1] && ycoor<ypos[n1]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n0],ypos[n0],100,100);
						gfx_fillrectangle(xpos[n1],ypos[n1],100,100);
						marks=marks+1;
			}
			
		}
		
		if ((xcoor>xpos[n1] && xcoor<xpos[n1]+100) && (ycoor>ypos[n1] && ycoor<ypos[n1]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n0] && xcoor<xpos[n0]+100) && (ycoor>ypos[n0] && ycoor<ypos[n0]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n0],ypos[n0],100,100);
						gfx_fillrectangle(xpos[n1],ypos[n1],100,100);
						marks=marks+1;
			}
			
		}
		
		n2=checking[1];
		n3=checking[6];
		
		if ((xcoor>xpos[n2] && xcoor<xpos[n2]+100) && (ycoor>ypos[n2] && ycoor<ypos[n2]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n3] && xcoor<xpos[n3]+100) && (ycoor>ypos[n3] && ycoor<ypos[n3]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n2],ypos[n2],100,100);
						gfx_fillrectangle(xpos[n3],ypos[n3],100,100);
						marks=marks+1;
			}
			
		}
		
		if ((xcoor>xpos[n3] && xcoor<xpos[n3]+100) && (ycoor>ypos[n3] && ycoor<ypos[n3]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n2] && xcoor<xpos[n2]+100) && (ycoor>ypos[n2] && ycoor<ypos[n2]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n2],ypos[n2],100,100);
						gfx_fillrectangle(xpos[n3],ypos[n3],100,100);
						marks=marks+1;
			}
			
		}
		
		n4=checking[2];
		n5=checking[7];
		
		if ((xcoor>xpos[n4] && xcoor<xpos[n4]+100) && (ycoor>ypos[n4] && ycoor<ypos[n4]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n5] && xcoor<xpos[n5]+100) && (ycoor>ypos[n5] && ycoor<ypos[n5]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n4],ypos[n4],100,100);
						gfx_fillrectangle(xpos[n5],ypos[n5],100,100);
						marks=marks+1;
			}
			
		}
		
		if ((xcoor>xpos[n5] && xcoor<xpos[n5]+100) && (ycoor>ypos[n5] && ycoor<ypos[n5]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n4] && xcoor<xpos[n4]+100) && (ycoor>ypos[n4] && ycoor<ypos[n4]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n4],ypos[n4],100,100);
						gfx_fillrectangle(xpos[n5],ypos[n5],100,100);
						marks=marks+1;
			}
			
		}
		
		n6=checking[3];
		n7=checking[8];
		
		if ((xcoor>xpos[n6] && xcoor<xpos[n6]+100) && (ycoor>ypos[n6] && ycoor<ypos[n6]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n7] && xcoor<xpos[n7]+100) && (ycoor>ypos[n7] && ycoor<ypos[n7]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n6],ypos[n6],100,100);
						gfx_fillrectangle(xpos[n7],ypos[n7],100,100);
						marks=marks+1;
			}
			
		}
		
		if ((xcoor>xpos[n7] && xcoor<xpos[n7]+100) && (ycoor>ypos[n7] && ycoor<ypos[n7]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n6] && xcoor<xpos[n6]+100) && (ycoor>ypos[n6] && ycoor<ypos[n6]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n6],ypos[n6],100,100);
						gfx_fillrectangle(xpos[n7],ypos[n7],100,100);
						marks=marks+1;
			}
			
		}
		
		n8=checking[4];
		n9=checking[9];
		
		if ((xcoor>xpos[n8] && xcoor<xpos[n8]+100) && (ycoor>ypos[n8] && ycoor<ypos[n8]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n9] && xcoor<xpos[n9]+100) && (ycoor>ypos[n9] && ycoor<ypos[n9]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n8],ypos[n8],100,100);
						gfx_fillrectangle(xpos[n9],ypos[n9],100,100);
						marks=marks+1;
			}
			
		}
		
		if ((xcoor>xpos[n9] && xcoor<xpos[n9]+100) && (ycoor>ypos[n9] && ycoor<ypos[n9]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n8] && xcoor<xpos[n8]+100) && (ycoor>ypos[n8] && ycoor<ypos[n8]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n8],ypos[n8],100,100);
						gfx_fillrectangle(xpos[n9],ypos[n9],100,100);
						marks=marks+1;
			}
			
		}
		
		/*Grid*/
		gfx_color(255,255,255);
		gfx_rectangle(100,100,500,200);
		gfx_line(200,100,200,300);
		gfx_line(300,100,300,300);
		gfx_line(400,100,400,300);
		gfx_line(500,100,500,300);
		gfx_line(100,200,600,200); 
		
		if (marks>5)
			marks=5;
		printf("Marks: %d \n",marks);
	
		if (xcoor>500 && xcoor<600) 
		{
			if (ycoor>350 && ycoor<375)
			{
			gfx_clear();
			break;

			}
		}	
		
		if (c=='q')
			exit(0);
	}
	}	
	*m1=marks;
}

int check1(int checking[10], int a, int i)
{
	int j;
	
	for (j=0;j<i+1;j++)
	{
		if (checking[j]==a)
		{
			a=rand()%10;
			a=check1(checking,a,i);
		}
	
	}
	return a;
}

void level2(int *m2)
{
	int xpos[12]={100,200,300,400,100,200,300,400,100,200,300,400};
	int ypos[12]={100,100,100,100,200,200,200,200,300,300,300,300};
	int i,j,a,d,checking[12],r,g,b,x1,y1,x2,y2,e,xcoor,ycoor;
	int n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,marks=0;
	char c;

	
	/*Color randomization*/
	srand(time(NULL));
	
	/*Shapes and color fill*/
	
		/*Randomize numbers and get the numbers*/
	for (i=0;i<12;i++)
	{
		a=rand()%12;
		a=check2(checking,a,i);	
		printf("i=%d a=%d\n",i,a);
		checking[i]=a;
	}
	
	
	for (j=0;j<6;j++)
	{
		r=rand()%255+1;
		g=rand()%255+1;
		b=rand()%255+1;
		gfx_color(r,g,b);
		
		d=checking[j];
		x1=xpos[d];
		y1=ypos[d];
		printf("j=%d dx=%d dy=%d\n",j,x1,y1);
		gfx_fillcircle(x1+50,y1+50,70);
		
		e=checking[j+6];
		x2=xpos[e];
		y2=ypos[e];
		printf("j+5=%d ex=%d ey=%d\n",j+6,x2,y2);
		gfx_fillrectangle(x2+20,y2+20,50,50);
	
	}
	 
	gfx_color(255,255,255);
 	gfx_line(100,100,100,400); 
 	gfx_line(200,100,200,400); 
	gfx_line(300,100,300,400); 
	gfx_line(400,100,400,400); 
	gfx_line(500,100,500,400);
	gfx_line(100,100,500,100);
	gfx_line(100,200,500,200);
	gfx_line(100,300,500,300);
	gfx_line(100,400,500,400);  
	


	gfx_color(191, 201, 202);
	gfx_fillrectangle(400,450,100,25);
	gfx_color(0,0,0);
	gfx_text("Next",410,460);
	
 	while(1){
 		if(gfx_event_waiting()){
   		c=gfx_wait();
   		xcoor=gfx_xpos();//determine x coordinate
   		ycoor=gfx_ypos();//determine y coordinate
	
		n0=checking[0];
		n1=checking[6];
	
		if ((xcoor>xpos[n0] && xcoor<xpos[n0]+100) && (ycoor>ypos[n0] && ycoor<ypos[n0]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n1] && xcoor<xpos[n1]+100) && (ycoor>ypos[n1] && ycoor<ypos[n1]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n0],ypos[n0],100,100);
						gfx_fillrectangle(xpos[n1],ypos[n1],100,100);
						marks=marks+1;
			}
			
		}
		
		if ((xcoor>xpos[n1] && xcoor<xpos[n1]+100) && (ycoor>ypos[n1] && ycoor<ypos[n1]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n0] && xcoor<xpos[n0]+100) && (ycoor>ypos[n0] && ycoor<ypos[n0]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n0],ypos[n0],100,100);
						gfx_fillrectangle(xpos[n1],ypos[n1],100,100);
						marks=marks+1;
			}
			
		}
		
	
		n2=checking[1];
		n3=checking[7];
	
		if ((xcoor>xpos[n2] && xcoor<xpos[n2]+100) && (ycoor>ypos[n2] && ycoor<ypos[n2]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n3] && xcoor<xpos[n3]+100) && (ycoor>ypos[n3] && ycoor<ypos[n3]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n2],ypos[n2],100,100);
						gfx_fillrectangle(xpos[n3],ypos[n3],100,100);
						marks=marks+1;
			}
			
		}
		
		if ((xcoor>xpos[n3] && xcoor<xpos[n3]+100) && (ycoor>ypos[n3] && ycoor<ypos[n3]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n2] && xcoor<xpos[n2]+100) && (ycoor>ypos[n2] && ycoor<ypos[n2]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n2],ypos[n2],100,100);
						gfx_fillrectangle(xpos[n3],ypos[n3],100,100);
						marks=marks+1;
			}
			
		}
		
		n4=checking[2];
		n5=checking[8];
		
		if ((xcoor>xpos[n4] && xcoor<xpos[n4]+100) && (ycoor>ypos[n4] && ycoor<ypos[n4]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n5] && xcoor<xpos[n5]+100) && (ycoor>ypos[n5] && ycoor<ypos[n5]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n4],ypos[n4],100,100);
						gfx_fillrectangle(xpos[n5],ypos[n5],100,100);
						marks=marks+1;
			}
			
		}
		
		if ((xcoor>xpos[n5] && xcoor<xpos[n5]+100) && (ycoor>ypos[n5] && ycoor<ypos[n5]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n4] && xcoor<xpos[n4]+100) && (ycoor>ypos[n4] && ycoor<ypos[n4]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n4],ypos[n4],100,100);
						gfx_fillrectangle(xpos[n5],ypos[n5],100,100);
						marks=marks+1;
			}
			
		}
	
		n6=checking[3];
		n7=checking[9];
	
		if ((xcoor>xpos[n6] && xcoor<xpos[n6]+100) && (ycoor>ypos[n6] && ycoor<ypos[n6]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n7] && xcoor<xpos[n7]+100) && (ycoor>ypos[n7] && ycoor<ypos[n7]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n6],ypos[n6],100,100);
						gfx_fillrectangle(xpos[n7],ypos[n7],100,100);
						marks=marks+1;
			}
			
		}
		
		if ((xcoor>xpos[n7] && xcoor<xpos[n7]+100) && (ycoor>ypos[n7] && ycoor<ypos[n7]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n6] && xcoor<xpos[n6]+100) && (ycoor>ypos[n6] && ycoor<ypos[n6]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n6],ypos[n6],100,100);
						gfx_fillrectangle(xpos[n7],ypos[n7],100,100);
						marks=marks+1;
			}
			
		}
		
		n8=checking[4];
		n9=checking[10];
		
		if ((xcoor>xpos[n8] && xcoor<xpos[n8]+100) && (ycoor>ypos[n8] && ycoor<ypos[n8]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n9] && xcoor<xpos[n9]+100) && (ycoor>ypos[n9] && ycoor<ypos[n9]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n8],ypos[n8],100,100);
						gfx_fillrectangle(xpos[n9],ypos[n9],100,100);
						marks=marks+1;
			}
			
		}
		
		if ((xcoor>xpos[n9] && xcoor<xpos[n9]+100) && (ycoor>ypos[n9] && ycoor<ypos[n9]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n8] && xcoor<xpos[n8]+100) && (ycoor>ypos[n8] && ycoor<ypos[n8]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n8],ypos[n8],100,100);
						gfx_fillrectangle(xpos[n9],ypos[n9],100,100);
						marks=marks+1;
			}
			
		}
	
		n10=checking[5];
		n11=checking[11];
		
		if ((xcoor>xpos[n10] && xcoor<xpos[n10]+100) && (ycoor>ypos[n10] && ycoor<ypos[n10]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n11] && xcoor<xpos[n11]+100) && (ycoor>ypos[n11] && ycoor<ypos[n11]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n10],ypos[n10],100,100);
						gfx_fillrectangle(xpos[n11],ypos[n11],100,100);
						marks=marks+1;
			}
			
		}
		
		if ((xcoor>xpos[n11] && xcoor<xpos[n11]+100) && (ycoor>ypos[n11] && ycoor<ypos[n11]+100))
		{
			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			if ((xcoor>xpos[n10] && xcoor<xpos[n10]+100) && (ycoor>ypos[n10] && ycoor<ypos[n10]+100))
			{
						gfx_color(0,0,0);		
						gfx_fillrectangle(xpos[n10],ypos[n10],100,100);
						gfx_fillrectangle(xpos[n11],ypos[n11],100,100);
						marks=marks+1;
			}
			
		}
	
 	/*Grid*/
 	gfx_color(255,255,255);
 	gfx_line(100,100,100,400); 
 	gfx_line(200,100,200,400); 
	gfx_line(300,100,300,400); 
	gfx_line(400,100,400,400); 
	gfx_line(500,100,500,400);
	gfx_line(100,100,500,100);
	gfx_line(100,200,500,200);
	gfx_line(100,300,500,300);
	gfx_line(100,400,500,400);
	
	if (marks>6)
		marks=6;
 	printf("Marks is %d\n",marks);
  
  			c=gfx_wait();
			xcoor=gfx_xpos();
			ycoor=gfx_ypos();
			
			
	if (xcoor>400 && xcoor<500) {
		if (ycoor>450 && ycoor<475) {
			gfx_clear();
				break; 		
		}
	}
 	if(c =='q')
   	exit(0);
   	
   }
 }
 	*m2=marks;
}

int check2(int checking[12], int a, int i)
{
	int j;
	
	for (j=0;j<i+1;j++)
	{
		if (checking[j]==a)
		{
			a=rand()%12;
			a=check2(checking,a,i);
		}
	
	}
	return a;
}

void level3(int *m3)
{
 	int i,r,g,b,x,y,marks = 0;
  
 	char c;
 
 	gfx_color(255,255,255);


 	gfx_line(100,100,700,100);
 	gfx_line(100,200,700,200);
 	gfx_line(100,300,700,300);
 	gfx_line(100,400,700,400);
 	gfx_line(100,500,700,500);
 	gfx_line(100,600,700,600);
 	gfx_line(100,100,100,600);
 	gfx_line(200,100,200,600);
 	gfx_line(300,100,300,600);
 	gfx_line(400,100,400,600);
 	gfx_line(500,100,500,600);
 	gfx_line(600,100,600,600);
 	gfx_line(700,100,700,600);

	for (i=1;i<16;i++)
	{
 		r=rand()%255+1;
 		g=rand()%255+1;
 		b=rand()%255+1;
 
 		gfx_color(r,g,b);
 		
 	if (r!=0 && g!=0 && b!=0)
 	{
 
 	if (i==1) {
 		gfx_fillcircle(150,150,20);
 		gfx_fillcircle(150,170,20);
 		gfx_fillcircle(150,130,20);
 		gfx_fillcircle(170,150,20);
 		gfx_fillcircle(130,150,20);

	 	gfx_fillcircle(250,250,20);
	 	gfx_fillcircle(250,270,20);
	 	gfx_fillcircle(250,230,20);
	 	gfx_fillcircle(270,250,20);
 		gfx_fillcircle(230,250,20);
	}

	if (i==2) {
 		gfx_fillrectangle(140,320,20,60);
 		gfx_fillrectangle(120,340,60,20);

 		gfx_fillrectangle(340,420,20,60);
 		gfx_fillrectangle(320,440,60,20);
	}

	if (i==3) {
 		gfx_fillcircle(220,350,30);
 		gfx_fillcircle(280,350,30);
 		gfx_fillrectangle(220,340,50,15);

 		gfx_fillcircle(520,150,30);
 		gfx_fillcircle(580,150,30);
 		gfx_fillrectangle(520,140,50,15);
	}

 	if (i==4) {
 		gfx_fillcircle(335,230,20);
 		gfx_fillcircle(370,230,20);
 		gfx_fillrectangle(330,260,10,10);
 		gfx_fillrectangle(340,270,10,10);
 		gfx_fillrectangle(350,280,10,10);
 		gfx_fillrectangle(360,270,10,10);
 		gfx_fillrectangle(370,260,10,10);

 		gfx_fillcircle(535,530,20);
 		gfx_fillcircle(570,530,20);
 		gfx_fillrectangle(530,560,10,10);
 		gfx_fillrectangle(540,570,10,10);
 		gfx_fillrectangle(550,580,10,10);
 		gfx_fillrectangle(560,570,10,10);
 		gfx_fillrectangle(570,560,10,10);
	}
 
 	if (i==5) {
 		gfx_fillrectangle(120,520,20,60);
 		gfx_fillrectangle(160,520,20,60);
 		gfx_fillrectangle(120,540,60,20);

 		gfx_fillrectangle(420,320,20,60);
 		gfx_fillrectangle(460,320,20,60);
 		gfx_fillrectangle(420,340,60,20);
	}
 
 	if (i==6) {
 		gfx_fillrectangle(220,140,10,10);
 		gfx_fillrectangle(230,130,10,10);
 		gfx_fillrectangle(230,150,10,10);
 		gfx_fillrectangle(240,120,10,10);
 		gfx_fillrectangle(240,160,10,10);
 		gfx_fillrectangle(250,150,10,10);
 		gfx_fillrectangle(250,130,10,10);
 		gfx_fillrectangle(260,140,10,10); 

 		gfx_fillrectangle(420,240,10,10);
 		gfx_fillrectangle(430,230,10,10);
 		gfx_fillrectangle(430,250,10,10);
 		gfx_fillrectangle(440,220,10,10);
		gfx_fillrectangle(440,260,10,10);
 		gfx_fillrectangle(450,250,10,10);
 		gfx_fillrectangle(450,230,10,10);
 		gfx_fillrectangle(460,240,10,10);
	}
 
 	if (i==7) {
 		gfx_fillrectangle(420,520,60,20);
 		gfx_fillrectangle(420,560,60,20);
 		gfx_fillrectangle(440,520,20,60);

 		gfx_fillrectangle(620,320,60,20);
 		gfx_fillrectangle(620,360,60,20);
 		gfx_fillrectangle(640,320,20,60);
	} 
 
 	if (i==8) {
 		gfx_fillrectangle(640,120,20,60);
 		gfx_fillrectangle(620,140,60,20);
 		gfx_fillcircle(610,150,10);
 		gfx_fillcircle(650,190,10);
 		gfx_fillcircle(650,110,10);
 		gfx_fillcircle(690,150,10);
 
 		gfx_fillrectangle(340,520,20,60);
 		gfx_fillrectangle(320,540,60,20);
 		gfx_fillcircle(310,550,10);
 		gfx_fillcircle(350,590,10);
 		gfx_fillcircle(350,510,10);
 		gfx_fillcircle(390,550,10);
	}
 
 	if (i==9) {
 		gfx_fillcircle(530,250,10);
 		gfx_fillcircle(540,240,10);
 		gfx_fillcircle(540,260,10); 
 		gfx_fillcircle(550,230,10);
 		gfx_fillcircle(550,270,10);
 		gfx_fillcircle(560,240,10);
 		gfx_fillcircle(560,260,10);
 		gfx_fillcircle(570,250,10);

		gfx_fillcircle(530,350,10);
 		gfx_fillcircle(540,340,10);
 		gfx_fillcircle(540,360,10); 
 		gfx_fillcircle(550,330,10);
 		gfx_fillcircle(550,370,10);
 		gfx_fillcircle(560,340,10);
 		gfx_fillcircle(560,360,10);
 		gfx_fillcircle(570,350,10);
	}

	if (i==10) 
	{
 		gfx_fillcircle(430,130,20);
 		gfx_fillcircle(470,130,20);
 		gfx_fillrectangle(430,160,40,20);

 		gfx_fillcircle(230,530,20);
 		gfx_fillcircle(270,530,20);
 		gfx_fillrectangle(230,560,40,20);
	}

	if (i==11)
 	{
 		gfx_fillrectangle(120,420,20,20);
 		gfx_fillrectangle(160,420,20,20);
 		gfx_fillcircle(150,460,30);

 		gfx_fillrectangle(520,420,20,20);
 		gfx_fillrectangle(560,420,20,20);
 		gfx_fillcircle(550,460,30);
 	}

	if (i==12) {
 		gfx_fillcircle(250,450,30);
 		gfx_fillrectangle(210,440,20,20);
 		gfx_fillrectangle(240,410,20,20);
 		gfx_fillrectangle(270,440,20,20);
 		gfx_fillrectangle(240,470,20,20);

 		gfx_fillcircle(650,250,30);
 		gfx_fillrectangle(610,240,20,20);
 		gfx_fillrectangle(640,210,20,20);
 		gfx_fillrectangle(670,240,20,20);
 		gfx_fillrectangle(640,270,20,20); }

	if (i==13) {
 		gfx_fillrectangle(340,120,20,20);
 		gfx_fillrectangle(340,160,20,20);
 		gfx_fillcircle(320,150,20);
 		gfx_fillcircle(380,150,20);

 		gfx_fillrectangle(340,320,20,20);
 		gfx_fillrectangle(340,360,20,20);
 		gfx_fillcircle(320,350,20);
 		gfx_fillcircle(380,350,20);
	}

	if (i==14) {
 		gfx_fillrectangle(420,440,20,20);
 		gfx_fillrectangle(460,440,20,20);
 		gfx_fillcircle(450,420,20);
 		gfx_fillcircle(450,480,20);

 		gfx_fillrectangle(620,440,20,20);
 		gfx_fillrectangle(660,440,20,20);
 		gfx_fillcircle(650,420,20);
 		gfx_fillcircle(650,480,20);
	}

	if (i==15) 
	{
 		gfx_fillcircle(650,530,30);
 		gfx_fillcircle(650,580,30);
 		gfx_fillrectangle(645,520,15,50);

 		gfx_fillcircle(150,230,30);
 		gfx_fillcircle(150,280,30);
 		gfx_fillrectangle(145,220,15,50);
 	}
 	
 	}
	}
 

	
	gfx_color(191, 201, 202);
	gfx_fillrectangle(720,200,100,25);
	gfx_color(0,0,0);
	gfx_text("Next",730,210);


 	while(1){
 	if(gfx_event_waiting()){
 	c=gfx_wait();
  	x=gfx_xpos();
  	y=gfx_ypos();
 
 	//First set

 	//Condition 1
 	if((x>100 && x<200)&&(y>100 && y<200))
  	{
   	c=gfx_wait();
   	x=gfx_xpos();
   	y=gfx_ypos();
    	if((x>200 && x<300)&&(y>200 && y<300)){
       		gfx_color(0,0,0);
       		gfx_fillcircle(150,150,20);
       		gfx_fillcircle(150,170,20);
       		gfx_fillcircle(150,130,20);
       		gfx_fillcircle(170,150,20);
       		gfx_fillcircle(130,150,20);
       		gfx_fillcircle(250,250,20);
       		gfx_fillcircle(250,270,20);
       		gfx_fillcircle(250,230,20);
       		gfx_fillcircle(270,250,20);
       		gfx_fillcircle(230,250,20);
      		marks=marks+1; 
      	}
    }
    
 	//Condition 2
 	if((x>200 && x<300)&&(y>200 && y<300))
  	{
   	c=gfx_wait();
   	x=gfx_xpos();
   	y=gfx_ypos();
    	if((x>100 && x<200)&&(y>100 && y<200)){
       		gfx_color(0,0,0); 
       		gfx_fillcircle(150,150,20);
       		gfx_fillcircle(150,170,20);
       		gfx_fillcircle(150,130,20);
       		gfx_fillcircle(170,150,20);
       		gfx_fillcircle(130,150,20);
       		gfx_fillcircle(250,250,20);
       		gfx_fillcircle(250,270,20);
       		gfx_fillcircle(250,230,20);
       		gfx_fillcircle(270,250,20);
       		gfx_fillcircle(230,250,20);      
       		marks=marks+1;
      	}
   	}
 	//Second set
 
 	//condition 1
 	if((x>100 && x<200)&&(y>300 && y<400))
  	{
   		c=gfx_wait();
   		x=gfx_xpos();
   		y=gfx_ypos();
    	if((x>300 && x<400)&&(y>400 && y<500)){
       		gfx_color(0,0,0);
       		gfx_fillrectangle(140,320,20,60);
       		gfx_fillrectangle(120,340,60,20);

       		gfx_fillrectangle(340,420,20,60);
       		gfx_fillrectangle(320,440,60,20);
       		marks=marks+1;
      	}
    } 
 	//condition 2
 	if((x>300 && x<400)&&(y>400 && y<500))
  	{
   		c=gfx_wait();
   		x=gfx_xpos();
   		y=gfx_ypos();
    	if((x>100 && x<200)&&(y>300 && y<400)){
       		gfx_color(0,0,0);
       		gfx_fillrectangle(340,420,20,60);
       		gfx_fillrectangle(320,440,60,20);

       		gfx_fillrectangle(140,320,20,60);
       		gfx_fillrectangle(120,340,60,20);
       		marks=marks+1;
      }
    } 
 
 	//Third set

 	//condition 1 
 	if((x>200 && x<300)&&(y>300 && y<400))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>500 && x<600)&&(y>100 && y<200)){
       		gfx_color(0,0,0);
       		gfx_fillcircle(220,350,30);
       		gfx_fillcircle(280,350,30);
       		gfx_fillrectangle(220,340,50,15);

       		gfx_fillcircle(520,150,30);
       		gfx_fillcircle(580,150,30);
       		gfx_fillrectangle(520,140,50,15);
       		marks=marks+1;
      	}
    } 
 	//condition 2
 	if((x>500 && x<600)&&(y>100 && y<200))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>200 && x<300)&&(y>300 && y<400)){
       		gfx_color(0,0,0);
       		gfx_fillcircle(220,350,30);
       		gfx_fillcircle(280,350,30);
       		gfx_fillrectangle(220,340,50,15);
 
       		gfx_fillcircle(520,150,30);
       		gfx_fillcircle(580,150,30);
       		gfx_fillrectangle(520,140,50,15);
       		marks=marks+1;
      }
    } 

 	// Forth set

 	//condition 1 
 	if((x>300 && x<400)&&(y>200 && y<300))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>500 && x<600)&&(y>500 && y<600)){
       		gfx_color(0,0,0);
       		gfx_fillcircle(335,230,20);
       		gfx_fillcircle(370,230,20);
       		gfx_fillrectangle(330,260,10,10);
       		gfx_fillrectangle(340,270,10,10);
       		gfx_fillrectangle(350,280,10,10);
       		gfx_fillrectangle(360,270,10,10);
       		gfx_fillrectangle(370,260,10,10);

       		gfx_fillcircle(535,530,20);
       		gfx_fillcircle(570,530,20);
      		gfx_fillrectangle(530,560,10,10);
       		gfx_fillrectangle(540,570,10,10);
       		gfx_fillrectangle(550,580,10,10);
       		gfx_fillrectangle(560,570,10,10);
       		gfx_fillrectangle(570,560,10,10);
       		marks=marks+1;
      }
    } 
 	//condition 2
 	if((x>500 && x<600)&&(y>500 && y<600))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>300 && x<400)&&(y>200 && y<300)){
       		gfx_color(0,0,0);
       		gfx_fillcircle(335,230,20);
       		gfx_fillcircle(370,230,20);
       		gfx_fillrectangle(330,260,10,10);
       		gfx_fillrectangle(340,270,10,10);
       		gfx_fillrectangle(350,280,10,10);
       		gfx_fillrectangle(360,270,10,10);
       		gfx_fillrectangle(370,260,10,10);

       		gfx_fillcircle(535,530,20);
       		gfx_fillcircle(570,530,20);
       		gfx_fillrectangle(530,560,10,10);
       		gfx_fillrectangle(540,570,10,10);
       		gfx_fillrectangle(550,580,10,10);
       		gfx_fillrectangle(560,570,10,10);
       		gfx_fillrectangle(570,560,10,10);
       		marks=marks+1;
      }
    } 

 	//Fifth set

 	//condition 1
 	if((x>100 && x<200)&&(y>500 && y<600))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>400 && x<500)&&(y>300 && y<400)){
       		gfx_color(0,0,0);
       		gfx_fillrectangle(120,520,20,60);
       		gfx_fillrectangle(160,520,20,60);
       		gfx_fillrectangle(120,540,60,20);

       		gfx_fillrectangle(420,320,20,60);
       		gfx_fillrectangle(460,320,20,60);
       		gfx_fillrectangle(420,340,60,20);

       		marks=marks+1;
      }
    } 
 	//condition 2
 	if((x>400 && x<500)&&(y>300 && y<400))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>100 && x<200)&&(y>500 && y<600)){
       		gfx_color(0,0,0);
       		gfx_fillrectangle(120,520,20,60);
       		gfx_fillrectangle(160,520,20,60);
       		gfx_fillrectangle(120,540,60,20);

       		gfx_fillrectangle(420,320,20,60);
       		gfx_fillrectangle(460,320,20,60);
       		gfx_fillrectangle(420,340,60,20);

       		marks=marks+1;
      }
    } 

 	//Sixth set

 	//condition 1
 	if((x>200 && x<300)&&(y>100 && y<200))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>400 && x<500)&&(y>200 && y<300)){
       		gfx_color(0,0,0);
       		gfx_fillrectangle(220,140,10,10);
       		gfx_fillrectangle(230,130,10,10);
       		gfx_fillrectangle(230,150,10,10);
       		gfx_fillrectangle(240,120,10,10);
       		gfx_fillrectangle(240,160,10,10);
       		gfx_fillrectangle(250,150,10,10);
       		gfx_fillrectangle(250,130,10,10);
       		gfx_fillrectangle(260,140,10,10); 

       		gfx_fillrectangle(420,240,10,10);
       		gfx_fillrectangle(430,230,10,10);
       		gfx_fillrectangle(430,250,10,10);
       		gfx_fillrectangle(440,220,10,10);
       		gfx_fillrectangle(440,260,10,10);
       		gfx_fillrectangle(450,250,10,10);
       		gfx_fillrectangle(450,230,10,10);
       		gfx_fillrectangle(460,240,10,10);
       		marks=marks+1;
      }
    } 
 	//condition 2
 	if((x>400 && x<500)&&(y>200 && y<300))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>200 && x<300)&&(y>100 && y<200)){
       		gfx_color(0,0,0);
       		gfx_fillrectangle(220,140,10,10);
       		gfx_fillrectangle(230,130,10,10);
       		gfx_fillrectangle(230,150,10,10);
       		gfx_fillrectangle(240,120,10,10);
       		gfx_fillrectangle(240,160,10,10);
       		gfx_fillrectangle(250,150,10,10);
       		gfx_fillrectangle(250,130,10,10);
       		gfx_fillrectangle(260,140,10,10); 

       		gfx_fillrectangle(420,240,10,10);
       		gfx_fillrectangle(430,230,10,10);
       		gfx_fillrectangle(430,250,10,10);
       		gfx_fillrectangle(440,220,10,10);
       		gfx_fillrectangle(440,260,10,10);
       		gfx_fillrectangle(450,250,10,10);
       		gfx_fillrectangle(450,230,10,10);
       		gfx_fillrectangle(460,240,10,10);
       		marks=marks+1;
      }
    } 
 	//7th set

 	//condition 1
 	if((x>300 && x<400)&&(y>500 && y<600))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>600 && x<700)&&(y>100 && y<200)){
       		gfx_color(0,0,0);
       		gfx_fillrectangle(640,120,20,60);
       		gfx_fillrectangle(620,140,60,20);
       		gfx_fillcircle(610,150,10);
       		gfx_fillcircle(650,190,10);
       		gfx_fillcircle(650,110,10);
       		gfx_fillcircle(690,150,10);
 
       		gfx_fillrectangle(340,520,20,60);
       		gfx_fillrectangle(320,540,60,20);
       		gfx_fillcircle(310,550,10);
       		gfx_fillcircle(350,590,10);
      		gfx_fillcircle(350,510,10);
       		gfx_fillcircle(390,550,10);
       		marks=marks+1;
      }
    } 
 	//condition 2
 	if((x>600 && x<700)&&(y>100 && y<200))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>300 && x<400)&&(y>500 && y<600)){
       		gfx_color(0,0,0);
       		gfx_fillrectangle(640,120,20,60);
       		gfx_fillrectangle(620,140,60,20);
       		gfx_fillcircle(610,150,10);
       		gfx_fillcircle(650,190,10);
       		gfx_fillcircle(650,110,10);
       		gfx_fillcircle(690,150,10);
 
       		gfx_fillrectangle(340,520,20,60);
       		gfx_fillrectangle(320,540,60,20);
       		gfx_fillcircle(310,550,10);
       		gfx_fillcircle(350,590,10);
       		gfx_fillcircle(350,510,10);
       		gfx_fillcircle(390,550,10);
       		marks=marks+1;
      }
    } 
 
 	//8th set

 	//condition 1
 	if((x>500 && x<600)&&(y>200 && y<300))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>500 && x<600)&&(y>300 && y<400)){
       		gfx_color(0,0,0);
       		gfx_fillcircle(530,250,10);
       		gfx_fillcircle(540,240,10);
       		gfx_fillcircle(540,260,10); 
       		gfx_fillcircle(550,230,10);
       		gfx_fillcircle(550,270,10);
       		gfx_fillcircle(560,240,10);
       		gfx_fillcircle(560,260,10);
       		gfx_fillcircle(570,250,10);

       		gfx_fillcircle(530,350,10);
       		gfx_fillcircle(540,340,10);
       		gfx_fillcircle(540,360,10); 
       		gfx_fillcircle(550,330,10);
       		gfx_fillcircle(550,370,10);
       		gfx_fillcircle(560,340,10);
       		gfx_fillcircle(560,360,10);
       		gfx_fillcircle(570,350,10);

       		marks=marks+1;
      }
    } 
 		//condition 2
 	if((x>500 && x<600)&&(y>300 && y<400))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>500 && x<600)&&(y>200 && y<300)){
       		gfx_color(0,0,0);
       		gfx_fillcircle(530,250,10);
       		gfx_fillcircle(540,240,10);
       		gfx_fillcircle(540,260,10); 
       		gfx_fillcircle(550,230,10);
       		gfx_fillcircle(550,270,10);
       		gfx_fillcircle(560,240,10);
       		gfx_fillcircle(560,260,10);
       		gfx_fillcircle(570,250,10);

       		gfx_fillcircle(530,350,10);
       		gfx_fillcircle(540,340,10);
       		gfx_fillcircle(540,360,10); 
       		gfx_fillcircle(550,330,10);
       		gfx_fillcircle(550,370,10);
       		gfx_fillcircle(560,340,10);
       		gfx_fillcircle(560,360,10);
       		gfx_fillcircle(570,350,10);
       		marks=marks+1;
      }
    } 
 
 	//9th set

 	//condition 1
 	if((x>400 && x<500)&&(y>100 && y<200))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>200 && x<300)&&(y>500 && y<600)){
       		gfx_color(0,0,0);
       		gfx_fillcircle(430,130,20);
       		gfx_fillcircle(470,130,20);
       		gfx_fillrectangle(430,160,40,20);
 
       		gfx_fillcircle(230,530,20);
       		gfx_fillcircle(270,530,20);
       		gfx_fillrectangle(230,560,40,20);

       	marks=marks+1;
      }
    } 
 	//condition 2
 	if((x>200 && x<300)&&(y>500 && y<600))
  	{
  		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>400 && x<500)&&(y>100 && y<200)){
       		gfx_color(0,0,0);
       		gfx_fillcircle(430,130,20);
       		gfx_fillcircle(470,130,20);
       		gfx_fillrectangle(430,160,40,20);
 
       		gfx_fillcircle(230,530,20);
       		gfx_fillcircle(270,530,20);
       		gfx_fillrectangle(230,560,40,20);
       		marks=marks+1;
      	}
    } 

 	//10th set

 	//condition 1
 	if((x>100 && x<200)&&(y>400 && y<500))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>500 && x<600)&&(y>400 && y<500)){
       		gfx_color(0,0,0);
       		gfx_fillrectangle(120,420,20,20);
       		gfx_fillrectangle(160,420,20,20);
       		gfx_fillcircle(150,460,30);

       		gfx_fillrectangle(520,420,20,20);
       		gfx_fillrectangle(560,420,20,20);
       		gfx_fillcircle(550,460,30);
       		marks=marks+1;
      	}
    } 
 	//condition 2
 	if((500 && x<600)&&(y>400 && y<500))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>100 && x<200)&&(y>400 && y<500)){
       		gfx_color(0,0,0);
       		gfx_fillrectangle(120,420,20,20);
       		gfx_fillrectangle(160,420,20,20);
       		gfx_fillcircle(150,460,30);

       		gfx_fillrectangle(520,420,20,20);
       		gfx_fillrectangle(560,420,20,20);
       		gfx_fillcircle(550,460,30);
       		marks=marks+1;
      }
    } 

 	//11th set

 	//condition 1
 	if((x>200 && x<300)&&(y>400 && y<500))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>600 && x<700)&&(y>200 && y<300)){
       		gfx_color(0,0,0);
       		gfx_fillcircle(250,450,30);
       		gfx_fillrectangle(210,440,20,20);
       		gfx_fillrectangle(240,410,20,20);
       		gfx_fillrectangle(270,440,20,20);
       		gfx_fillrectangle(240,470,20,20);

       		gfx_fillcircle(650,250,30);
       		gfx_fillrectangle(610,240,20,20);
       		gfx_fillrectangle(640,210,20,20);
       		gfx_fillrectangle(670,240,20,20);
       		gfx_fillrectangle(640,270,20,20);

       		marks=marks+1;
      }
    } 
 	//condition 2
 	if((x>600 && x<700)&&(y>200 && y<300))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>200 && x<300)&&(y>400 && y<500)){
       		gfx_color(0,0,0);
       		gfx_fillcircle(250,450,30);
       		gfx_fillrectangle(210,440,20,20);
       		gfx_fillrectangle(240,410,20,20);
       		gfx_fillrectangle(270,440,20,20);
       		gfx_fillrectangle(240,470,20,20);

       		gfx_fillcircle(650,250,30);
       		gfx_fillrectangle(610,240,20,20);
       		gfx_fillrectangle(640,210,20,20);
       		gfx_fillrectangle(670,240,20,20);
       		gfx_fillrectangle(640,270,20,20);
        	marks=marks+1;
      }
    } 

 	//12th set

 	//condition 1
 	if((x>300 && x<400)&&(y>100 && y<200))
  	{
  		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>300 && x<400)&&(y>300 && y<400)){
       		gfx_color(0,0,0);
       		gfx_fillrectangle(340,120,20,20);
       		gfx_fillrectangle(340,160,20,20);
       		gfx_fillcircle(320,150,20);
       		gfx_fillcircle(380,150,20);

       		gfx_fillrectangle(340,320,20,20);
       		gfx_fillrectangle(340,360,20,20);
       		gfx_fillcircle(320,350,20);
       		gfx_fillcircle(380,350,20);

       		marks=marks+1;
      }
    } 
 	//condition 2
 	if((x>300 && x<400)&&(y>300 && y<400))
  	{
   		c = gfx_wait();
   		x = gfx_xpos();
   		y = gfx_ypos();
    	if((x>300 && x<400)&&(y>100 && y<200)){
       		gfx_color(0,0,0);

       		gfx_fillrectangle(340,120,20,20);
       		gfx_fillrectangle(340,160,20,20);
		   	gfx_fillcircle(320,150,20);
			gfx_fillcircle(380,150,20);

			gfx_fillrectangle(340,320,20,20);
			gfx_fillrectangle(340,360,20,20);
			gfx_fillcircle(320,350,20);
			gfx_fillcircle(380,350,20);
			marks=marks+1;
			  }
			} 

		 //13th set

		 //condition 1
		 if((x>400 && x<500)&&(y<400 && y<500))
		  {
		   c = gfx_wait();
		   x = gfx_xpos();
		   y = gfx_ypos();
			if((x>600 && x<700)&&(y>400 && y<500)){
			   gfx_color(0,0,0);
			   gfx_fillrectangle(420,440,20,20);
			   gfx_fillrectangle(460,440,20,20);
			   gfx_fillcircle(450,420,20);
			   gfx_fillcircle(450,480,20);

		   gfx_fillrectangle(620,440,20,20);
		   gfx_fillrectangle(660,440,20,20);
		   gfx_fillcircle(650,420,20);
		   gfx_fillcircle(650,480,20);

		   marks=marks+1;
		  }
		} 
	 //condition 2
	 if((x>600 && x<700)&&(y>400 && y<500))
	  {
	   c = gfx_wait();
	   x = gfx_xpos();
	   y = gfx_ypos();
		if((x>400 && x<500)&&(y>400 && y<500)){
		   gfx_color(0,0,0);
		   gfx_fillrectangle(420,440,20,20);
		   gfx_fillrectangle(460,440,20,20);
		   gfx_fillcircle(450,420,20);
		   gfx_fillcircle(450,480,20);

		   gfx_fillrectangle(620,440,20,20);
		   gfx_fillrectangle(660,440,20,20);
		   gfx_fillcircle(650,420,20);
		   gfx_fillcircle(650,480,20);

		   marks=marks+1;
		  }
		} 

	 //14th set

	 //condition 1
	 if((x>100 && x<200)&&(y>200 && y<300))
	  {
	   c = gfx_wait();
	   x = gfx_xpos();
	   y = gfx_ypos();
		if((x>600 && 700)&&(y>500 && y<600)){
		   gfx_color(0,0,0);
		   gfx_fillcircle(650,530,30);
		   gfx_fillcircle(650,580,30);
		   gfx_fillrectangle(645,520,15,50);

		   gfx_fillcircle(150,230,30);
		   gfx_fillcircle(150,280,30);
		   gfx_fillrectangle(145,220,15,50);

		   marks=marks+1;
		  }
		} 
	 //condition 2
	 if((x>600 && x<700)&&(y>500 && y<600))
	  {
	   c = gfx_wait();
	   x = gfx_xpos();
	   y = gfx_ypos();
		if((x>100 && x<200)&&(y>200 && y<300)){
		   gfx_color(0,0,0);
		   gfx_fillcircle(650,530,30);
		   gfx_fillcircle(650,580,30);
		   gfx_fillrectangle(645,520,15,50);

		   gfx_fillcircle(150,230,30);
		   gfx_fillcircle(150,280,30);
		   gfx_fillrectangle(145,220,15,50);

		   marks=marks+1;
		  }
		} 

	 //15th set

	 //condition 1
	 if((x>400 && x<500)&&(y>500 && y<600))
	  {
	   c = gfx_wait();
	   x = gfx_xpos();
	   y = gfx_ypos();
		if((x>600 && x<700)&&(y>300 && y<400)){
		   gfx_color(0,0,0);
		   gfx_fillrectangle(420,520,60,20);
		   gfx_fillrectangle(420,560,60,20);
		   gfx_fillrectangle(440,520,20,60);
	   
		   gfx_fillrectangle(620,320,60,20);
		   gfx_fillrectangle(620,360,60,20);
		   gfx_fillrectangle(640,320,20,60);

		   marks=marks+1;
		  }
		} 
	 //condition 2
	 if((x>600 && x<700)&&(y>300 && y<400))
	  {
	   c = gfx_wait();
	   x = gfx_xpos();
	   y = gfx_ypos();
		if((x>400 && x<500)&&(y>500 && y<600)){
		   gfx_color(0,0,0);
		   gfx_fillrectangle(420,520,60,20);
		   gfx_fillrectangle(420,560,60,20);
		   gfx_fillrectangle(440,520,20,60);
	   
		   gfx_fillrectangle(620,320,60,20);
		   gfx_fillrectangle(620,360,60,20);
		   gfx_fillrectangle(640,320,20,60);

		   marks=marks+1;
		  }
		} 
	 			printf("Marks is %d\n",marks);
				c=gfx_wait();
				x=gfx_xpos();
				y=gfx_ypos();
				
				if (x>720 && x<820) {
				 	if (y>200 && y<225) {
					gfx_clear();
					break; }}
	 
	 			if(c =='q')
	   			exit(0);
	   
	 }}
	 *m3=marks;
}

