#include <graphics.h>
#include <math.h>
double clcp(double t,int ar[]){
    double p,a=1-t;
    p=pow(a,3)*ar[0] + 3*pow(a,2)*t*ar[1] + 3*a*pow(t,2)*ar[2] + pow(t,3)*ar[3];
    //p=pow(2,3);
    return p;
}
int main() {
    int gd=DETECT,gm= DETECT;
    initgraph(&gd,&gm,"");
    setbkcolor(WHITE);
    setcolor(BLACK);
    int x[4], y[4];
    x[0] = 10, y[0] = 10;
    x[1] = 100, y[1] = 150;
    x[2] = 20, y[2] = 40;
    x[3] = 400, y[3] = 100;
    double px,py;
    for(double t=0;t<=1;t+=.0005){
        px=clcp(t,x);
        py=clcp(t,y);
        putpixel(px,py,RED);
    }
    delay(5000);
    closegraph();
    return 0;
}
