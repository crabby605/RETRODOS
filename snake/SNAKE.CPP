/* w/W --> Up
   s/S --> Down
   a/A --> Left
   d/D --> Right
   q/Q --> Exit
*/

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

int end,d=2,x=13,y=13,x1=0,x2=0,y1=0,y2=0,ta[51],tb[51],fx=0,fy=0,sx=0,sy=0,ox[31],oy[31],a=1,score=0,spec=0,timer=0;
//end for checking end of session, d for direction, (x,y) for coordinates of head, (x1,x2,y1,y2) for new coordinates of head(next move),
//l for length, (ta,tb) for storing coordinates of trailing parts, (fx,fy) for food coordinates, (sx,sy) for special coordinates,
//(ox,oy) for obstacle coordinates, a for checking food status, speed for snake speed, score for recording total score,
//special for setting time interval between each special food.

//Funtion Prototype for Snake
void intro();						 //Introduction
void difficulty();      				 //For Difficulty Levels
void snake(int l,int speed);			       	 //Main Snake Functions
void move(int key);    					 //Snake Movement
void slide();         				         //Snake Movement when No key is Pressed
void bodystore(int l);  				 //Storing Coordinates of Trailing Parts of Snake's Body
void bodydraw(int l);   				 //Drawing Trailing Parts of Snake's Body
void food(int b);       				 //Food Randomization
void obstacles();      					 //Obstacles Randomization
void obstaclesdraw();				         //Obstacles Drawing
void border();         					 //To make Snake come from the other side, to avoid it fleding of off-screen!
void collision(int);      					 //Detect Collision with Obstacles
void special();						 //To Randomize Specials at Regular Intervals
void result(int,int);                                           //To Print Final Result
void printer(int num,int posx,int posy,int color);       //To Print The Details like Score,Life,Lenght and Speed.

void main()
{
randomize();
clrscr();
int gdriver=DETECT,gmode,cho;
initgraph(&gdriver,&gmode,"graphics");
intro();
setcolor(15);
do
{
	score=end=x1=x2=y1=y2=0;
	d=2;
	x=y=13;
	for(int i=0;i<50;i++)
		ta[i]=tb[i]=0;
	cleardevice();
	setcolor(WHITE);
	rectangle(1,1,638,478);
	setcolor(GREEN);
	settextstyle(4,0,5);
	outtextxy(250,15,"Snake!!!");
	settextstyle(2,0,6);
	outtextxy(250,150,"1: Play!!!");
	outtextxy(250,200,"2: Instructions");
	outtextxy(250,250,"3: Credits");
	outtextxy(250,300,"4: Exit");
	setcolor(WHITE);
	switch(getch())
	{
	case '1':
		cho=1;
		difficulty();
		break;
	case '2':
		cho=2;
		cleardevice();
		rectangle(1,1,638,478);
		settextstyle(2,0,10);
		outtextxy(200,10,"Instructions");
		line(195,57,470,57);
		line(195,60,470,60);
		settextstyle(2,0,5);
		outtextxy(20,70,"Welcome to Snake!!!. This Game has been an All time classic for all Ages. ");
		outtextxy(20,82,"The Controls are very Simple. Use 'W' for going up, 'S' for Going down, 'D' for");
		outtextxy(20,94,"Going Left and 'A' for Going Right. Use 'Q' to Quit in Between the Game.");
		outtextxy(20,116,"The Following are the Different Stuff you will encounter during the game :");
		setcolor(GREEN);
		rectangle(30,140,50,160);
		setcolor(RED);
		rectangle(150,140,170,160);
		setcolor(BROWN);
		rectangle(270,140,290,160);
		setcolor(YELLOW);
		rectangle(390,140,410,160);
		line(390,140,410,160);
		line(410,140,390,160);
		setcolor(WHITE);
		outtextxy(20,170,"Thats Your");
		outtextxy(20,182,"body Part,");
		outtextxy(20,194,"Dont Eat it!");

		outtextxy(140,170,"Thats Your");
		outtextxy(140,182,"food. Go");
		outtextxy(140,194,"Grab it!");
		outtextxy(140,206,"1 Point");

		outtextxy(240,170,"Thats a Special,");
		outtextxy(240,182,"Grab it before");
		outtextxy(240,194,"time runs out.");
		outtextxy(240,206,"5 Point");

		outtextxy(380,170,"Thats an Obstacle");
		outtextxy(380,182,"Collision will ");
		outtextxy(380,194,"mean Death!");

		outtextxy(20,220,"Apart from all this You can also see your Score, Current Length, Speed and ");
		outtextxy(20,232,"Level on the bottom side of the screen. Also when a Special is Present on the");
		outtextxy(20,244,"screen, a Gauge will Tell you the Amount of time you have before the Special");
		outtextxy(20,256,"will dissappear. The Time is Purely based on Random Calculations, so its ");
		outtextxy(20,268,"different for every special. ");
		outtextxy(50,288,"Enjoy the Game Folks!!!");
		getch();
		break;
	case '3':
		cho=3;
		cleardevice();
		settextstyle(2,0,5);
		for(int i=500;i>-100;i--)
		{
			setcolor(15);
			outtextxy(300,i,"Credits");
			line(300,i+15,350,i+15);
			line(300,i+17,350,i+17);
			outtextxy(280,i+22,"Programmers");
			line(280,i+37,366,i+37);
			outtextxy(260,i+42,"Fahim Imaduddin Dalvi");
			outtextxy(260,i+54,"  Nitin John James");
			outtextxy(200,i+70,"This Program was Made Using Turbo C++");
			outtextxy(260,i+82,"All Rights Reserved 2008");
			delay(10);
			setcolor(0);
			outtextxy(300,i,"Credits");
			line(300,i+15,350,i+15);
			line(300,i+17,350,i+17);
			outtextxy(280,i+22,"Programmers");
			line(280,i+37,366,i+37);
			outtextxy(260,i+42,"Fahim Imaduddin Dalvi");
			outtextxy(260,i+54,"  Nitin John James");
			outtextxy(200,i+70,"This Program was Made Using Turbo C++");
			outtextxy(260,i+82,"All Rights Reserved 2008");

		}
		break;
	case '4':
		cho=4;
		cleardevice();
		setcolor(GREEN);
		settextstyle(2,0,10);
		outtextxy(150,200,"Hope You Enjoyed!");
		getch();
	}
}
while(cho<4);
getch();
}

//Function Definition
void intro()
{
	int i,a,b,c,d;
	for(i=680;i>=200;i--)
	{
		setcolor(GREEN);
		settextstyle(4,0,5);
		outtextxy(i+50,200,"Snake!!!");
		delay(1);
		setcolor(0);
		settextstyle(4,0,5);
		outtextxy(i+51,200,"Snake!!!");
		delay(1);
		setcolor(4);
		line(0,i-201,0,i-200);
		delay(1);
		setcolor(2);
		line(i-1,0,i-200,0);
		delay(1);
		setcolor(3);
		line(639,i-201,639,i-200);
		delay(1);
		setcolor(1);
		line(i-1,479,i-200,479);
		delay(1);
	}
	setcolor(3);
	line(639,0,639,480);
	setcolor(GREEN);
	settextstyle(4,0,5);
	outtextxy(250,200,"Snake!!!");
	for(i=1;i<=200;i++)
	{
		a=random(15)+1;
		b=random(15)+1;
		c=random(15)+1;
		d=random(15)+1;
		setcolor(a);
		line(0,0,0,479);
		delay(1);
		setcolor(b);
		line(0,0,639,0);
		delay(1);
		setcolor(c);
		line(639,0,639,480);
		delay(1);
		setcolor(d);
		line(0,479,639,479);
		delay(1);
	}
	for(i=1;i<=200;i++)
	{
		a=random(15)+1;
		b=random(15)+1;
		c=random(15)+1;
		d=random(15)+1;
		setcolor(a);
		line(1,1,1,478);
		delay(1);
		setcolor(b);
		line(1,1,638,1);
		delay(1);
		setcolor(c);
		line(638,0,638,478);
		delay(1);
		setcolor(d);
		line(0,478,638,478);
		delay(1);
	}
	for(i=200;i>=15;i--)
	{
		setcolor(GREEN);
		settextstyle(4,0,5);
		outtextxy(250,i,"Snake!!!");
		delay(1);
		setcolor(0);
		settextstyle(4,0,5);
		outtextxy(250,i+1,"Snake!!!");
		delay(1);
	}
}

void difficulty()
{
	setcolor(0);
	settextstyle(4,0,5);
	outtextxy(250,15,"Snake!!!");
	settextstyle(2,0,6);
	outtextxy(250,150,"1: Play!!!");
	outtextxy(250,200,"2: Instructions");
	outtextxy(250,250,"3: Credits");
	outtextxy(250,300,"4: Exit");
	setcolor(WHITE);
	setcolor(GREEN);
	settextstyle(2,0,6);
	outtextxy(250,150,"1: Easy");
	setcolor(YELLOW);
	outtextxy(250,200,"2: Medium");
	setcolor(RED);
	outtextxy(250,250,"3: Hard");
	switch(getch())
	{
	case '1':
		cleardevice();
		setcolor(WHITE);
		settextstyle(2,0,5);
		outtextxy(70,455,"Easy");
		outtextxy(600,455,"0");
		outtextxy(287,455,"2");
		outtextxy(440,455,"1");
		snake(2,1);
		break;
	case '2':
		cleardevice();
		setcolor(WHITE);
		settextstyle(2,0,5);
		outtextxy(70,455,"Medium");
		outtextxy(600,455,"0");
		outtextxy(287,455,"5");
		outtextxy(440,455,"3");
		snake(5,3);
		break;
	case '3':
		cleardevice();
		setcolor(WHITE);
		settextstyle(2,0,5);
		outtextxy(70,455,"Hard");
		outtextxy(600,455,"0");
		outtextxy(287,455,"10");
		outtextxy(440,455,"5");
		snake(10,5);
		break;
	}
}

void move(int key)
{
	if((key==65||key==97)&&(d!=2))
	{
		::x2=10;
		::d=4;
	}
	else
	if((key==68||key==100)&&(d!=4))
	{
		::x1=10;
		::d=2;
	}
	else
	if((key==87||key==119)&&(d!=3))
	{
		::y1=10;
		::d=1;
	}
	else
	if((key==83||key==115)&&(d!=1))
	{
		::y2=10;
		::d=3;
	}
	else
	if(key==81||key==113)
	{
		::end=1;
	}
}

void slide()
{
	if(d==1)
		y1=10;
	else
	if(d==2)
		x1=10;
	else
	if(d==3)
		y2=10;
	else
	if(d==4)
		x2=10;
}

void bodysave(int l)
{
	for(int i=l-1;i>=1;i--)
	{
		ta[i]=ta[i-1];
		tb[i]=tb[i-1];
	}
}
void bodydraw(int l)
{
	for(int i=0;i<l;i++)
	{
		rectangle(ta[i],tb[i],ta[i]+10,tb[i]+10);
		circle(ta[i]+5,tb[i]+5,5);
	}
}


void food(int b)
{
	if(b==1)
	{
		setcolor(0);
		rectangle(fx+1,fy+1,fx+11,fy+11);
		fx=random(62);
		fy=random(40);
		fx*=10;
		fy*=10;
		::a=0;
		for(int i=0;i<30;i++)
			if(ox[i]==fx+3&&oy[i]==fy+3)
				::a=1;
	}
}

void special()
{
	spec++;
	if(spec==100)
	{
		sx=random(62);
		sy=random(40);
		sx*=10;
		sy*=10;
		timer=random(50);
		for(int i=0;i<30;i++)
			if(ox[i]==sx+3&&oy[i]==sy+3)
				spec=90;
	}
	else
	if(spec>100)
	{
		timer--;
		setcolor(0);
		rectangle(10,429,((timer+1)*12)+10,448);
		setcolor(GREEN);
		if(timer>1);
				rectangle(10,429,(timer*12)+10,448);
		if(timer==0)
		{
			spec=0;
			setcolor(0);
			rectangle(sx+3,sy+3,sx+13,sy+13);
			setcolor(0);
			rectangle(10,429,((timer+1)*12)+10,448);

		}

	}
}

void obstacles()
{
	for(int i=0;i<30;i++)
	{
		ox[i]=random(62);
		oy[i]=random(40);
		ox[i]*=10;
		oy[i]*=10;
		ox[i]+=3;
		oy[i]+=3;
	}
}

void obstaclesdraw()
{
	for(int i=0;i<30;i++)
	{
		setcolor(YELLOW);
		rectangle(ox[i],oy[i],ox[i]+10,oy[i]+10);
		line(ox[i],oy[i],ox[i]+10,oy[i]+10);
		line(ox[i]+10,oy[i],ox[i],oy[i]+10);
	}
}

void border()
{
	if(y==3&&d==1)
		y=423;
	else
	if(y==413&&d==3)
		y=-7;
	else
	if(x==3&&d==4)
		x=633;
	else
	if(x==623&&d==2)
		x=-7;
}

void collision(int l)
{
	for(int i=0;i<30;i++)
		if(ox[i]==x&&oy[i]==y)
			end=1;
	for(int j=3;j<l;j++)
		if(ta[j]==x&&tb[j]==y)
			end=1;
}

void snake(int l,int speed)
{
	d=2;
	end=0;
	rectangle(2,426,634,478);
	line(2,450,634,450);
	line(160,450,160,478);
	line(320,450,320,478);
	line(480,450,480,478);
	settextstyle(2,0,5);
	outtextxy(10,455,"Level : ");
	outtextxy(170,455,"Snake Length : ");
	outtextxy(330,455,"Snake Speed : ");
	outtextxy(490,455,"Total Score : ");
	obstacles();
	while(end!=1)
	{
		obstaclesdraw();
		setcolor(15);
		rectangle(2,2,634,424);
		x+=x1;
		x-=x2;
		y-=y1;
		y+=y2;
		x1=x2=y1=y2=0;
		ta[0]=x;
		tb[0]=y;
		setcolor(10);
		bodydraw(l);
		delay(int(500/speed));
		collision(l);
		setcolor(0);
		bodydraw(l);
		if(kbhit())
			move(getch());
		else
			slide();
		bodysave(l);

		food(::a);
		setcolor(RED);
		rectangle(fx+3,fy+3,fx+13,fy+13);
		if(x==(fx+3)&&y==(fy+3))
		{
			a=1;
			setcolor(0);
			outtextxy(600,455,"0");
			printer(score,600,455,0);
			score+=1;
			sound(100);
			delay(50);
			nosound();
			printer(score,600,455,15);
			for(int i=1;i<18;i++)
			if(score>(i*4))
			{
				setcolor(0);
				outtextxy(295,455,"0");
				printer(l,287,455,0);
				if(l<=50)
					l++;
				printer(l,287,455,15);
			}
			for(i=1;i<40;i++)
				if(score>(i*8))
				{
					setcolor(0);
					printer(speed,440,455,0);
					if(speed<=25)
						speed++;
					printer(speed,440,455,15);
				}
		}

		special();
		if(spec>100)
		{
			setcolor(BROWN);
			rectangle(sx+3,sy+3,sx+13,sy+13);
			if(x==(sx+3)&&y==(sy+3))
			{
				setcolor(0);
				outtextxy(600,455,"0");
				printer(score,600,455,0);
				score+=5;
				sound(100);
				delay(50);
				nosound();
				printer(score,600,455,15);
				spec=0;
				setcolor(0);
				rectangle(sx+3,sy+3,sx+13,sy+13);
				setcolor(0);
				rectangle(10,429,((timer)*12)+10,448);

			}
		}
		border();

	}
	result(l,speed);
}

void result(int l,int speed)
{
cleardevice();
setcolor(WHITE);
rectangle(1,1,638,478);
settextstyle(2,0,10);
outtextxy(200,20," RESULT ");
line(210,60,370,60);
line(210,62,370,62);
settextstyle(2,0,5);
outtextxy(100,100," Final Length : ");
printer(l,400,100,15);
outtextxy(100,170," Final Speed : ");
printer(speed,400,170,15);
outtextxy(100,240," Score : ");
if(score==0)
	outtextxy(400,240,"0");
else
	printer(score,400,240,15);
line(10,280,600,280);
outtextxy(100,310," Total Score : ");
printer((score+(l*10)+(speed*10)),400,310,15);
getch();
cleardevice();
}

void printer(int num,int posx,int posy,int color)
{
	int d,i=-7;
	settextstyle(2,0,5);
	setcolor(color);
	while(num!=0)
	{
		i+=7;
		d=num%10;
		if(d==1)
			outtextxy(posx-i,posy,"1");
		else
		if(d==2)
			outtextxy(posx-i,posy,"2");
		else
		if(d==3)
			outtextxy(posx-i,posy,"3");
		else
		if(d==4)
			outtextxy(posx-i,posy,"4");
		else
		if(d==5)
			outtextxy(posx-i,posy,"5");
		else
		if(d==6)
			outtextxy(posx-i,posy,"6");
		else
		if(d==7)
			outtextxy(posx-i,posy,"7");
		else
		if(d==8)
			outtextxy(posx-i,posy,"8");
		else
		if(d==9)
			outtextxy(posx-i,posy,"9");
		else
		if(d==0)
			outtextxy(posx-i,posy,"0");
		num=num/10;
	}
}