#include <graphics.h>
int cx=200,cy=300;
void ppx(int x,int y){

    putpixel(cx+x,cy+y,RED);
    putpixel(cx+y,cy+x,RED);
    putpixel(cx-x,cy-y,RED);
    putpixel(cx-y,cy-x,RED);

    putpixel(cx+x,cy-y,RED);
    putpixel(cx+y,cy-x,RED);
    putpixel(cx-x,cy+y,RED);
    putpixel(cx-y,cy+x,RED);


}
void dcr(int r)
{
    int x=r,y=0,xc,yc=1,re=0;
    xc=1-2*r;
    while(x>=y){
        ppx(x,y);
        y++;
        re+=yc;
        yc+=2;
        if(2*re+xc>=0){
            x--;
            re+=xc;
            xc+=2;
        }
    }
}

int main() {
    int gd=DETECT,gm= DETECT;
    initgraph(&gd,&gm,"");
    setbkcolor(WHITE);
    setcolor(BLACK);
    dcr(100);
    delay(3000);
    closegraph();
    return 0;
}
