#include<iostream>
#include<graphics.h>
using namespace std;
static int left_code = 1,right_code =2,bottom_code=4,top_code=8;
static int xmin,xmax,ymin,ymax;
int getcode(int x,int y){
	int code =0;
	if(y>ymax){
		code |= top_code;
	}
	if(y<ymin){
		code |= bottom_code;
	}
	if(x>xmax){
		code |= right_code;
	}
	if(x<xmin){
		code |= left_code;
	}
	return code;
}
int main(){
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	setcolor(BLUE);
	int x1,y1,x2,y2;
	cout<<"enter the coordinates of the line: "<<endl;
	cin>>x1>>y1>>x2>>y2;
	cout<<"enter the window elements: "<<endl;
	cin>>xmin>>ymin>>xmax>>ymax;
	//before clipping
	outtextxy(100,50,(char*)"before clipping");
	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	delay(5000);
	
	//after clipping
	int outcode1 = getcode(x1,y1);
	int outcode2 = getcode(x2,y2);
	int accept = 0;
	
	while(1){
		float m = (float)(y2-y1)/(x2-x1);
		if(outcode1 == 0 && outcode2 == 0){
			accept = 1;
			break;
		}
		else if((outcode1 & outcode2)!=0){
			break;
		}
		else{
			int x,y,temp;
			if(outcode1 != 0){
				temp = outcode1;
			}
			else{
				temp = outcode2;
			}
			
			if(temp & top_code){
				x = x1 + (ymax-y1)/m;
				y = ymax;
			}
			else if(temp & bottom_code){
				x = x1 + (ymin-y1)/m;
				y = ymin;
			}
			else if(temp & left_code){
				x = xmin;
				y = y1 + m*(xmin - x1);
			}
			else if(temp & right_code){
				x = xmax;
				y = y1 + m*(xmax - x1);
			}
			
			if(temp == outcode1){
				x1 =  x;
				y1 = y;
				outcode1 = getcode(x1,y1);
			}
			else{
				x2 =  x;
				y2 = y;
				outcode2 = getcode(x2,y2);
			}
			
		}
	}
	setcolor(YELLOW);
	cleardevice();
	if(accept){
		outtextxy(100,50,(char*)"after clipping ");
		rectangle(xmin,ymin,xmax,ymax);
		line(x1,y1,x2,y2);
	}
	else{
		outtextxy(100,50,(char*)"after clipping ");
		rectangle(xmin,ymin,xmax,ymax);	
	}
	getch();
	delay(5000);
	closegraph();
	
}
