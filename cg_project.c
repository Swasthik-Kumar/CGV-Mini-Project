#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
int maxy=600;
int count=0;
int maxx=500;
int view=0;
int n=1;
int m=3;
int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0;
int x=25, y=50;
char str [10];
void id1();
void id();
void draw_target();



/*based on count display no of arrows and result of game*/
void counting()
{
	sprintf(str,"No of Arrows:%d",count);
	display_string(40,40,str,2);
	if(count1==1&&count2==1&&count3==1&&count4==1&&count5==1&&count6==1&&count7==1&&count8==1&&count9==1&&count10==1)
	{
		display_string(5,300,"CONGRATULATION U WON",1);
		display_string(5,100,"PRESS n TO PLAY AGAIN",2);
		display_string(5,80,"PRESS q TO EXIT",2);

		glutIdleFunc(NULL);
	}
	else if(count>=15)
	{
		display_string(5,300," GAME OVER YOU LOSE",1);
		display_string(5,100,"PRESS n TO PLAY AGAIN",2);
		display_string(5,80,"PRESS q TO EXIT",2);


		glutIdleFunc(NULL);
	}
}


/*TO CHECK WHETHER ARROW HITS TARGET*/
void disa()
{

	if((x+110==300)&&(y>=435&&y<=465)&&(!count1))
	{
		count1=1;
		x=25;
		y=0;
		count++;

		glutIdleFunc(id);
	}
	else if ((x+110==375)&&(y>=385&&y<=415)&&(!count2))
	{
		count2=1;
		x=25;
		y=0;
		count++;
		glutIdleFunc(id);
	}
	else if ((x+110==399) &&(y>=465&&y<=495) &&(!count3))
	{
		count3=1;
		x=25;
		y=0;
		count++;
		glutIdleFunc(id);
	}
	else if((x+110==249)&&(y>=355&&y<=385)&&(!count4))
	{
		count4=1;
		x=25;
		y=0;
		count++;
		glutIdleFunc(id);
	}
	else if((x+110==351)&&(y>=315&&y<=345)&&(!count5))
	{
		count5=1;
		x=25;
		y=0;
		count++;
		glutIdleFunc(id);
	}
	else if((x+110==450)&&(y>=275&&y<=305)&&(!count6))
	{
		count6=1;
		x=25;
		y=0;
		count++;
		glutIdleFunc(id);
	}
	else if((x+110==330)&&(y>=230&&y<=260)&&(!count7))
	{
		count7=1;
		x=25;
		y=0;
		count++;
		glutIdleFunc (id);
	}
	else if((x+110==201)&&(y>=185&&y<=215)&&(!count8))
	{
		count8=1;
		x=25;
		y=0;
		count++;
		glutIdleFunc(id);
	}
	else if((x+110==399)&&(y>=135&&y<=165)&&(!count9))
	{
		count9=1;
		x=25;
		y=0;
		count++;
		glutIdleFunc(id);
	}
	else if((x+110==300)&&(y>=85&&y<=115)&&(!count10))
	{
		count10=1;
		x=25;
		y=0;
		count++;
		glutIdleFunc(id);
	}

}


/*to move arrow up*/
void id()
{	
	n=1;
	if(view==1)
	{
		y+=n;
		disa();
		if(y>maxy)
		{
			y=0;
			count++;
		}
	}
	glutPostRedisplay();
}

/*to display bitmap char (strings)*/
void display_string(int x, int y, char *string, int font)
{
    int len,i;
	glColor3f(0.8,0.52,1.0);
	glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
    if(font==1)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	if(font==2)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	if(font==3)
	        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
	if(font==4)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
	}

}

void display1(void)
{

	glClearColor(0.0,0.0,0.0,1.0);
	display_string(180,350,"VCET",1);
	display_string(215,300,"ARCHERY GAME",1);
	display_string(100,250,"MOUSE",2);
	display_string(150,230,"PRESS RIGHT BUTTON FOR MENU",3);
	display_string(100,210,"KEYBOARD",2);
	display_string(150,190,"PRESS 'r' TO RELEASE ARROWS",3);
	display_string(150,180," PRESS 'q' TO EXIT",3);
	display_string(100,150,"PRESS SPACE BAR TO START GAME",2);
	glutPostRedisplay();
	glutSwapBuffers();

}



/*to clear screen & set projection mode*/
void init()
{
	glClearColor(0,0.5,0.5,1);
	glColor3f(1,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}

/*to draw the arrow*/
void disp()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	if(view==0)
	{
		init();
		display1();
	}

	else
	{
		glLoadIdentity();
		glColor3f(1,1,0);
		display_string(150,450,"ARCHERY GAME",1);
		counting();
// Drawing of arrow
		glColor3f(0,1,1);
		glBegin(GL_LINES);
		glVertex2d(x,y);
		glVertex2d(x+100,y);
		glEnd();
		glLineWidth(2);
		glBegin(GL_LINES);
		glVertex2d(x,y+2);
		glVertex2d(x+100,y+2);
		glEnd();
		glBegin(GL_LINES);
		glVertex2d(x,y-2);
		glVertex2d(x+100,y-2);
		glEnd();
		glBegin(GL_TRIANGLES);
		glColor3f(1,0,0);//color of tip
		glVertex2d(x+100,y+3);
		glVertex2d(x+110,y);
		glVertex2d(x+100,y-3);
		glEnd();
		glBegin(GL_QUADS);
		glVertex2d(x,y+3);
		glVertex2d(x,y-3);
		glVertex2d(x-10,y-5);
		glVertex2d(x-10,y+5);
		glEnd();
		draw_target();
		// Drawing of target
		glFlush();
		glutSwapBuffers();
	}
}


/*to draw the target inside line loop*/
void draw_target()
{
if(count1==0)
{
glColor3f(1,0,1);
glPointSize(30);
glBegin(GL_POINTS);
glVertex2d(300,450);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(285,465);
glVertex2d(315,465);
glVertex2d(315,435);
glVertex2d(285,435);
glEnd();
}
else
{
glColor3f(1,1,1);
glPointSize(20);
glBegin(GL_POINTS);
glVertex2d(300,450);
glEnd();
}
if(count2==0)
{
glColor3f(1,0,1);
glPointSize(30);
glBegin(GL_POINTS);
glVertex2d(375,400);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(360,415);
glVertex2d(390,415);
glVertex2d(390,385);
glVertex2d(360,385);
glEnd();
}
else
{
glColor3f(1,1,1);
glPointSize(20);
glBegin(GL_POINTS);
glVertex2d(375,400);
glEnd();
}
if(count3==0)
{
glColor3f(1,0,1);
glPointSize(30);
glBegin(GL_POINTS);
glVertex2d(400,480);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(385,495);
glVertex2d(415,495);
glVertex2d(415,465);
glVertex2d(385,465);
glEnd();
}else
{
glColor3f(1,1,1);
glPointSize(20);
glBegin(GL_POINTS);
glVertex2d(400,480);
glEnd();
}
if(count4==0)
{
glColor3f(1,0,1);
glPointSize(30);
glBegin(GL_POINTS);
glVertex2d(250,370);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(235,385);
glVertex2d(265,385);
glVertex2d(265,355);
glVertex2d(235,355);
glEnd();
}else
{
glColor3f(1,1,1);
glPointSize(20);
glBegin(GL_POINTS);
glVertex2d(250,370);
glEnd();
}
if(count5==0)
{
glColor3f(1,0,1);
glPointSize(30);
glBegin(GL_POINTS);
glVertex2d(350,330);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(335,345);
glVertex2d(365,345);
glVertex2d(365,315);
glVertex2d(335,315);
glEnd();
}else
{
glColor3f(1,1,1);
glPointSize(20);
glBegin(GL_POINTS);
glVertex2d(350,330);
glEnd();
}
if(count6==0)
{
glColor3f(1,0,1);
glPointSize(30);
glBegin(GL_POINTS);
glVertex2d(450,290);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(435,305);
glVertex2d(465,305);
glVertex2d(465,275);
glVertex2d(435,275);
glEnd();
}else
{
glColor3f(1,1,1);
glPointSize(20);
glBegin(GL_POINTS);
glVertex2d(450,290);
glEnd();
}
if(count7==0)
{
glColor3f(1,0,1);
glPointSize(30);
glBegin(GL_POINTS);
glVertex2d(330,245);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(315,260);
glVertex2d(345,260);
glVertex2d(345,230);
glVertex2d(315,230);
glEnd();
}
else
{
glColor3f(1,1,1);
glPointSize(20);
glBegin(GL_POINTS);
glVertex2d(330,245);
glEnd();
}
if(count8==0)
{
glColor3f(1,0,1);
glPointSize(30);
glBegin(GL_POINTS);
glVertex2d(200,200);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(185,215);
glVertex2d(215,215);
glVertex2d(215,185);
glVertex2d(185,185);
glEnd();
}
else {
glColor3f(1,1,1);
glPointSize(20);
glBegin(GL_POINTS);
glVertex2d(200,200);
glEnd();
}
if(count9==0)
{
glColor3f(1,0,1);
glPointSize(30);
glBegin(GL_POINTS);
glVertex2d(400,150);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(385,165);
glVertex2d(415,165);
glVertex2d(415,135);
glVertex2d(385,135);
glEnd();
}
else
{
glColor3f(1,1,1);
glPointSize(20);
glBegin(GL_POINTS);
glVertex2d(400,150);
glEnd();
}
if(count10==0)
{
glColor3f(1,0,1);
glPointSize(30);
glBegin(GL_POINTS);
glVertex2d(300,100);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(285,115);
glVertex2d(315,115);
glVertex2d(315,85);
glVertex2d(285,85);
glEnd();
}
else
{
glColor3f(1,1,1);
glPointSize(20);
glBegin(GL_POINTS);
glVertex2d(300,100);
glEnd();
}
glFlush();

}
/* to move the arrow left when 'r' pressed*/
void id1()
{
x+=m;
disa();
if(x+110>maxx)
{
x=25;
y=0;
count++;
glutIdleFunc(id);
}
glutPostRedisplay();
}
/*set key to perform desired operation*/
void keys(unsigned char k,int x,int y)
{
	switch(k){

	case ' ':
			disp();
			view=1;
			break;
	case 'r': glutIdleFunc(id1);
	break;
	case 'n': /* new game */
		maxy=600;
		 count=0;
		 maxx=500;
		 view=1;
		 n=3;
		 m=3;
		count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0;
		 x=25, y=50;

		disp();
		glutIdleFunc(id);

	break;
	case 'q':		/* quit game */
	exit(0);
	}



}
/*sub menu to display instructions*/
void demo_menu(int i)
{

	switch(i)
{
case 5:
case 6:
case 7:
case 8:break;
}
}
/*sub menu to display designer names*/
void demo(int i)
{
switch(i)
{
case 9:
case 10:
case 11:break;
}
}
void game(int id)
{
switch(id)
{
}
}
/*main to call display,keyboard and idle func*/
int main(int argc,char **argv)
{
int sub_menu,submenu;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(900,900);
glutCreateWindow("ARCHERY GAME");
sub_menu=glutCreateMenu(demo_menu);
glutAddMenuEntry("r to release arrow",5);
glutAddMenuEntry("15 arrows and 10 blocks present",6);
glutAddMenuEntry("lost if arrow count exceeds blocks",7);
glutAddMenuEntry("otherwise win",8);
submenu=glutCreateMenu(demo);
glutAddMenuEntry("Ravi",9);
glutAddMenuEntry("Swasthik",10);
glutCreateMenu(game);
glutAddSubMenu("INSTRUCTION",sub_menu);
glutAddSubMenu("ABOUT",submenu);
glutAddMenuEntry("QUIT",2);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutDisplayFunc(disp);
glutIdleFunc(id);
glutKeyboardFunc(keys);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}

