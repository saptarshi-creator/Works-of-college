//#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int x,y;
    int i=0;
    int gd= DETECT, gm;
    initgraph(&gd,&gm, "");

    while(i<1000)
    {
        x=rand()%644;
        y=rand()%479;
        putpixel(x,y,15);
        setcolor(random(16));
        i++;
    }
    getch();
    closegraph();
}