#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;
class algo{
	public:
		void dda(float x1,float y1,float x2,float y2){
			float dx,dy,len,x,y;
			float xic,yic;
			int i=1;
			
			x=x1;
			y=y1;
			putpixel(x,y,RED);
			dx=abs(x2-x1);
			dy=abs(y2-y1);
			if(dx>dy)
			{
			len=dx;
			}
			else
			{
			len=dy;
			}
			xic=(x2-x1)/len;
			yic=(y2-y1)/len;
			
			
			while(i<=len)
			{
				
				
				putpixel(x,y,RED);
				x=x+xic;
				y=y+yic;
				i++;
				//delay(2000);
		
			}
		}
		void draw_circle(int xc,int yc,int x,int y){
			putpixel(xc+x,yc+y,RED);
			putpixel(xc-x,yc+y,RED);
			putpixel(xc+x,yc-y,RED);
			putpixel(xc-x,yc-y,RED);
			
			putpixel(xc+y,yc+x,RED);
			putpixel(xc-y,yc+x,RED);
			putpixel(xc+y,yc-x,RED);
			putpixel(xc-y,yc-x,RED);
		}
		
		void b_circle(int xc,int yc,int r){
			int x =0,y=r;
			int d = 3 - 2*r;
			draw_circle(xc,yc,x,y);
			while(y>=x){
				if(d<0){
					x = x+1;
					y =y;
					d = d + 4*x+6;
				}
				else{
					x = x+1;
					y = y-1;
					d = d + 4*(x-y) +10;
				}
				draw_circle(xc,yc,x,y);
			}
		}
};
int main(){
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	algo a1;
//	//pattern 1 circle triangle
//	int x,y,r;
//	cout<<"enter the coordinates x,y&r :"<<endl;
//	cin>>x>>y>>r;
//	//triangle components
//	float len = (cos(60) + 0.08)*r;
//	a1.b_circle(x,y,r);
//	a1.b_circle(x,y,r/2);
//	line(x,y-r,x+len,y+(r/2));
//	line(x+len,y+(r/2),x-len,y+(r/2));
//	line(x-len,y+(r/2),x,y-r);
	
	//pattern 2 rectangle/square
	int x1,y1,x2,y2,x3,y3,x4,y4;
	int x5,y5,x6,y6,x7,y7,x8,y8;
	int D,d,r;
	
	cout<<"enter x1";
	cin>>x1;	
	
	cout<<"enter y1";
	cin>>y1;
	cout<<"enter x3";
	cin>>x3;	
	
	cout<<"enter y3";
	cin>>y3;	
	x2 = x3;
	y2 = y1;
	x4 = x1;
	y4 = y3;
	a1.dda(x1,y1,x2,y2);
	a1.dda(x2,y2,x3,y3);
	a1.dda(x3,y3,x4,y4);
	a1.dda(x4,y4,x1,y1);
	
	x5 = (x1+x2)/2;
	y5 = y1;
	x6 = x2;
	y6 = (y2+y3)/2;
	x7 = (x4+x3)/2;
	y7 = y3;
	x8 = x1;
	y8 = (y1+y4)/2;
	a1.dda(x5,y5,x6,y6);
	a1.dda(x6,y6,x7,y7);
	a1.dda(x7,y7,x8,y8);
	a1.dda(x8,y8,x5,y5);
	
	//circle
	D = x2-x1;
	d = y4-y1;
	r = (D*d)/(2*sqrt(D*D + d*d));
	a1.b_circle(D,d,r);
	
	delay(100000);
	getch();
}
