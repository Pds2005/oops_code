#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;
int main(){
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int a[3][3];
	int d;
	cout<<"\nenter the value of x1,y1: "<<endl;
	cin>>a[0][0]>>a[0][1];
	cout<<"\nenter the value of x2,y2: "<<endl;
	cin>>a[1][0]>>a[1][1];
	cout<<"\nenter the value of x3,y3: "<<endl;
	cin>>a[2][0]>>a[2][1];
	a[0][2] = a[1][2] = a[2][2] = 1;
	line(a[0][0],a[0][1],a[1][0],a[1][1]);
	line(a[1][0],a[1][1],a[2][0],a[2][1]);
	line(a[2][0],a[2][1],a[0][0],a[0][1]);
	
	cout<<"\nenter your choice: "<<endl;
	cout<<"\n1.translation: ";
	cout<<"\n2.scaling: ";
	cout<<"\n3.rotating: ";
	cin>>d;
	
	switch(d){
		case 1:{
			int b[3][3],c[3][3];
			cout<<"\nenter the value of tx and ty: ";
			cin>>b[2][0]>>b[2][1];
			b[0][0] = b[1][1] = b[2][2] = 1;
			b[0][1] = b[0][2] = b[1][0] = b[1][2]=0;
			for(int i =0;i<3;i++){
				for(int j =0;j<3;j++){
					c[i][j] = 0;
					for(int k =0;k<3;k++){
						c[i][j] += a[i][k]*b[k][j];
					}
				}
			}
			setcolor(YELLOW);
			line(c[0][0],c[0][1],c[1][0],c[1][1]);
			line(c[1][0],c[1][1],c[2][0],c[2][1]);
			line(c[2][0],c[2][1],c[0][0],c[0][1]);
			delay(5000);	
		}break;
		
		case 2:{
			float b[3][3],c[3][3];
			cout<<"\nenter the value of sx and sy: ";
			cin>>b[0][0]>>b[1][1];
			b[2][2] = 1;
			b[0][1] = b[0][2] = b[1][0] = b[1][2] = b[2][0] = b[2][1] = 0;
			for(int i =0;i<3;i++){
				for(int j =0;j<3;j++){
					c[i][j] = 0;
					for(int k =0;k<3;k++){
						c[i][j] += a[i][k]*b[k][j];
					}
				}
			}
			setcolor(YELLOW);
			line(c[0][0],c[0][1],c[1][0],c[1][1]);
			line(c[1][0],c[1][1],c[2][0],c[2][1]);
			line(c[2][0],c[2][1],c[0][0],c[0][1]);
			delay(5000);	
		}break;
		
		case 3:{
			float z,A;
			cout<<"\nenter the value of angle z: ";
			cin>>z;
			A = z*M_PI/180;
			float b[3][3],c[3][3];
			
			b[2][2] = 1;
			b[0][0] = cos(A);
			b[1][1] = cos(A);
			b[0][1] = sin(A);
			b[1][0] = -sin(A);
			b[0][2] = b[1][2] = b[2][0] = b[2][1] =0;
			 
			for(int i =0;i<3;i++){
				for(int j =0;j<3;j++){
					c[i][j] = 0;
					for(int k =0;k<3;k++){
						c[i][j] += a[i][k]*b[k][j];
					}
				}
			}
			setcolor(YELLOW);
			line(c[0][0],c[0][1],c[1][0],c[1][1]);
			line(c[1][0],c[1][1],c[2][0],c[2][1]);
			line(c[2][0],c[2][1],c[0][0],c[0][1]);
			delay(5000);	
		}break;
	}
}
