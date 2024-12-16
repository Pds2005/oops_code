#include<iostream> 
#include<conio.h> 
#include<graphics.h> 
#include<stdlib.h> 
#include<dos.h> 
  
using namespace std; 
  
class WalkingMan { 
     int rhx, rhy; 
   
 public: 
     void draw(int i); 
     void drawRandom(int x, int y); 
 }; 
   
 void WalkingMan::draw(int i) { 
     line(20, 380, 580, 380); 
     if (i % 2) { 
         line(25 + i, 380, 35 + i, 340); 
         line(45 + i, 380, 35 + i, 340); 
         line(35 + i, 310, 25 + i, 330); 
         delay(20); 
     } else { 
         line(35 + i, 340, 35 + i, 310); 
         line(35 + i, 310, 40 + i, 330); 
         delay(20); 
     } 
     line(35 + i, 340, 35 + i, 310); 
     circle(35 + i, 300, 10); 
     line(35 + i, 310, 50 + i, 330); 
     line(50 + i, 330, 50 + i, 280); 
     line(15 + i, 280, 85 + i, 280); 
     arc(50 + i,  280, 0, 180, 35); 
     arc(55 + i, 330, 180, 360, 5); 
 } 
   
 void WalkingMan::drawRandom(int x, int y) { 
     for (int j = 0; j < 100; j++) { 
         outtextxy(rand() % x, rand() % (y - 50), "|"); 
         setcolor(WHITE); 
     } 
 } 
   
 int main() { 
     int gd = DETECT, gm; 
     WalkingMan obj; 
     initgraph(&gd, &gm, ""); 
     for (int i = 0; i < 500; i++) { 
         obj.draw(i); 
         int rhx = getmaxx(); 
         int rhy = getmaxy(); 
         obj.drawRandom(rhx, rhy); 
         delay(150); 
         cleardevice(); 
         if (kbhit()) { 
             char ch = getch(); 
             if (ch == 27) { 
                 break; 
             } 
         } 
     } 
     getch(); 
     closegraph(); 
     return 0; 
 }
