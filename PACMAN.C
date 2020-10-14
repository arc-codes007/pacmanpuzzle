#include<graphics.h>
#include<dos.h>
#include<stdio.h>

int maxx,maxy;
int midx,midy;
int mycolor=1;
int tx,ty;
int dir;
int wallflag=0;

void wallcheck()
  {  if(midy<=10)  //htop
	wallflag=1;
     else if(midy>=470)  //hlast
	wallflag=1;
     else if((midy>=70&&midy<=80&&midx<=520&&midx>=0)||(midy>=70&&midy<=80&&midx>=630)) //h1 wall
	wallflag=1;
     else if(midy>=150&&midy<=160&&midx<=130)   //h2-1 wall
	wallflag=1;
     else if(midy>=150&&midy<=160&&midx>=190&&midx<=640)   //h2-2 wall
	wallflag=1;
     else if(midx>=70&&midx<=80&&midy>=230&&midy<=410)  //v1 wall
	wallflag=1;
     else if(midx>=70&&midx<=560&&midy>=230&&midy<=240)  //h3 wall
	wallflag=1;
     else if(midx>=0&&midx<=70&&midy>=310&&midy<=320) //h4-1
	wallflag=1;
     else if(midx>=150&&midx<=640&&midy>=310&&midy<=320)  //h4-2 wall
	wallflag=1;
     else if((midx>=70&&midx<=640&&midy>=400&&midy<=410)||(midy>=400&&midy<=410&&midx<=10))  //h5 wall
	wallflag=1;
     else if(midx>=550&&midx<=570&&midy>=410&&midy<=470) //v2
	wallflag=1;
     else
	wallflag=0;
  }

void printpac(char x)

 {
   setcolor(BLACK);

   if(x=='u')
     {
      setcolor(YELLOW);
      setfillstyle(1,YELLOW);
      pieslice(midx,midy,0,360,20);
      setcolor(BLACK);
      setfillstyle(1,BLACK);
      sector(midx,midy,65,115,20,20);
     }

  if(x=='l')
    {
     setcolor(YELLOW);
     setfillstyle(1,YELLOW);
     pieslice(midx,midy,0,360,20);
     setcolor(BLACK);
     setfillstyle(1,BLACK);
     sector(midx,midy,154,205,20,20);
    }

  if(x=='d')
    {
     setcolor(YELLOW);
     setfillstyle(1,YELLOW);
     pieslice(midx,midy,0,360,20);
     setcolor(BLACK);
     setfillstyle(1,BLACK);
     sector(midx,midy,245,296,20,20);
    }

  if(x=='r')
    {
     setcolor(BLACK);
     setfillstyle(1,BLACK);
     pieslice(midx,midy,0,360,20);
     setcolor(YELLOW);
     setfillstyle(1,YELLOW);
     pieslice(midx,midy,20,340,20);
    }

 }


void pacman(char x)
{
if(midx<0)midx=getmaxx()-40;
if(midy<0)midy=getmaxy()-40;
if(midx>=maxx)midx=40;
if(midy>=maxy)midy=40;

printpac(x);

setfillstyle(1,BLACK);
setcolor(BLACK);
pieslice(tx,ty,0,360,20);
tx=midx;
ty=midy;
sound(320);
delay(50);
nosound();
setcolor(RED);
rectangle(0,0,maxx,maxy);

}

void pacsame(char x)
{setcolor(BLACK);
printpac(x);

sound(120);
delay(100);
sound(270);
delay(100);
sound(230);
delay(100);
nosound();
setcolor(RED);
rectangle(0,0,maxx,maxy);


}



void up()
  {dir='u';
   midy-=40;
   wallcheck();
   if(wallflag==1)
     {
      midy+=40;
      pacsame(dir);
      wallflag=0;
     }

   else
      pacman(dir);
  }
void left()
  {dir='l';
   midx-=40;
   wallcheck();
   if(wallflag==1)
     {
      midx+=40;
      pacsame(dir);
      wallflag=0;
     }
   else
      pacman(dir);
  }
void down()
  {dir='d';
   midy+=40;
   wallcheck();
   if(wallflag==1)
     {
      midy-=40;
      pacsame(dir);
      wallflag=0;
     }
   else
      pacman(dir);
  }
void right()
  {dir='r';
   midx+=40;
   wallcheck();
   if(wallflag==1)
     {
      midx-=40;
      pacsame(dir);
      wallflag=0;
     }
   else
     pacman(dir);
  }



void main()
{
int gd=DETECT,gm;
char ch;

char mainch;

int checkx,checky;
int x=0,y=0,checkclr,score=0;
clrscr();
printf("\t\tWELCOME TO PACMAN MAZE BY UTKARSH BHATI!!");
printf("\n1.Start Game\n2.Quit\nEnter Choice - ");
start:
fflush(stdin);
scanf("%c",&mainch);

if(mainch!=49)
if(mainch!=50)
{printf("Please Choose Correctly - ");goto start;}
if(mainch==50)
goto quit;
printf("\nNote - You can QUIT anytime by pressing q or Q inside the game");
printf("\nPress Any Key to Continue...\nALL THE BEST");
getch();
initgraph(&gd,&gm,"c:\\turboc3\\bgi");

maxx=getmaxx();
maxy=getmaxy();
midx=40;
midy=40;
tx=midx;
ty=midy;
for(x=40;x<=maxx-39;x+=40)
{for(y=40;y<=maxy-39;y+=40)
 putpixel(x,y,WHITE);
}
putpixel(160,160,BLACK);
putpixel(600,80,BLACK);
putpixel(560,80,BLACK);
setcolor(GREEN);
outtextxy(590,420,"END");

setcolor(BLUE);
setfillstyle(1,BLUE);
bar(0,0,640,10); //htop
bar(0,70,520,80); //h1
bar(0,150,130,160); //h2-1
bar(200,150,640,160); //h2-2
bar(70,230,80,410); //v1
bar(70,230,560,240); //h3
bar(0,310,70,320); //h4-1
bar(150,310,640,320); //h4-2
bar(70,400,640,410); //h5
bar(560,410,570,470); //v2
bar(0,470,maxx,maxy); //hlast

setcolor(RED);
rectangle(0,0,maxx,maxy);
setfillstyle(1,YELLOW);
pieslice(midx,midy,20,340,20);


do
 {ch=getch();
  if(ch=='0')ch=getch();
  switch(ch)
  {
   case 'H' : up();
	      break;
   case 'K' : left();
	      break;

   case 'P' : down();
	      break;

   case 'M' : right();
	      break;

  }
  if(midx>570&&midx<640&&midy>410&&midy<480)
  break;
  if(ch=='Q')break;
 }while(ch!='q');
quit:
for(x=40;x<=maxx-39;x+=40)
{for(y=40;y<=maxy-39;y+=40)
 {checkclr=getpixel(x,y);
 if((x==160&&y==160)||(x==600&&y==80)||(x==560&&y==80))
 continue;
 if(checkclr==0)
 score=score+1;
}

}

closegraph();
clrscr();
printf("Your Score - %d out of 90",score);
getch();
}

