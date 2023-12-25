#include<stdio.h>
#include<graphics.h>

void drawCircle(int xc, int yc, int radius,int color) 
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x <= y) 
	{
        putpixel(xc + x, yc - y, color); //top
        putpixel(xc - x, yc - y, color); //top
        putpixel(xc + y, yc - x, color); //top to center
        putpixel(xc - y, yc - x, color); //top to center
        putpixel(xc + y, yc + x, color); //bottom to center
        putpixel(xc - y, yc + x, color); //bottom to center
        putpixel(xc + x, yc + y, color); //bottom
        putpixel(xc - x, yc + y, color); //bottom
        
        if (p < 0) 
		{
            p += 2 * x + 3;
        } 
		else 
		{
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
        delay(2); // Adjust the delay as needed
    }
}

int main()
{
	int gd=DETECT,gm;
	int i;
	initgraph(&gd,&gm,(char*)"");
		
	for(i=0;i<100;i++)
	{
		setfillstyle(SOLID_FILL,YELLOW);
		drawCircle(300+i,300,100,14);
		floodfill(300+i,300,YELLOW);
	//eyes
	//	left
		setfillstyle(SOLID_FILL,BLACK); 
		circle(250+i,270,10);
		floodfill(250+i,270,WHITE);
		
	//	right
		setfillstyle(SOLID_FILL,BLACK); 
		circle(340+i,270,10);
		floodfill(340+i,270,WHITE);
		
	//	smile
		setfillstyle(SOLID_FILL,BLACK);
		line(249+i,321,352+i,321);
		arc(299+i,320,-180,0,50);
		floodfill(320+i,325,WHITE);
		delay(100);
		cleardevice();
	}	
	getch();
	closegraph();
	return 0;
}
