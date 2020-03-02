#include <graphics.h>

int dwl(int x0,int y0,int x1,int y1){
    int dx,dy,x,y,d;
    dx=x1-x0;
    dy=y1-y0;
    d=0;
    for(x=x0;x<=x1;x++){
        putpixel(x,y,BLUE);
        d+=dy;
        if(d*2>=dx){
            y++;
            d-=dx;
        }
    }
}

int main() {
    int gd=DETECT,gm= DETECT;
    initgraph(&gd,&gm,"");
    setbkcolor(WHITE);
    setcolor(BLACK);
    dwl(10,20,333,444);
    line(10,20,333,444);

    delay(3000);
    closegraph();
    return 0;
}
