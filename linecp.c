#include <graphics.h>
#include <math.h>
int top=8,bottom=4,right=2,left=1,xmin,xmax,ymax,ymin;
int outcd(double x,double y){
    int cd=0;
    if(x<xmin)cd|=left;
    if(x>xmax)cd|=right;
    if(y<ymin)cd|=bottom;
    if(y>ymax)cd|=top;
    return cd;
}
void clpline(double x0,double y0,double x1,double y1){
    double x,y,m;
    int flag=0,c1,c0,ct;
    c1=outcd(x1,y1);
    c0=outcd(x0,y0);
    while(1){
        if(!(c1|c0)){
            flag=1;
            break;
        }
        else if(c1&c0)break;
        m=(y1-y0)/(x1-x0);
        if(c0>c1)ct=c0;
        else ct=c1;
        if(ct&top){
            y=ymax;
            x=x0+(y-y0)/m;
        }
        else if(ct&bottom){
            y=ymin;
            x=x0+(y-y0)/m;
        }
        else if(ct&left){
            x=xmin;
            y=y0+m*(x-x0);
        }
        else if(ct&right){
            x=xmax;
            y=y0+m*(x-x0);
        }
        if(ct==c0){
            x0=x;
            y0=y;
            c0=outcd(x0,y0);
        }
        else {
            x1=x;
            y1=y;
            c1=outcd(x1,y1);
        }
    }
    if(flag){
        setcolor(RED);
rectangle(xmin, ymin, xmax, ymax);
setcolor(BLUE);
line(x0, y0, x1, y1);
    }
}

int main() {
    int gd=DETECT,gm= DETECT;
    initgraph(&gd,&gm,"");
    setbkcolor(WHITE);
    setcolor(BLACK);
    double x0, y0, x1, y1;
    xmin = 100;
    xmax = 500;
    ymin = 10;
    ymax = 300;
    x0 = 50, y0 = 50, x1 = 600, y1 = 90;
    line(x0, y0, x1, y1);
    clpline(x0, y0, x1, y1);
    delay(5000);
    closegraph();
    return 0;
}
