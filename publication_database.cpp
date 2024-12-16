#include<iostream>
#include<stdio.h>
using namespace std;
class publication{
	string title;
	float price;
	public:
		void add(){
			cout<<"enter Title: ";
			cin.ignore();
			getline(cin,title);
			cout<<"enter Price: ";
			cin>>price;
		}
		void disp(){
			cout<<"title of publication: "<<title<<endl;
			cout<<"price of publication: "<<price<<endl;
		}
};

class book:public publication{
	int pagecount;
	public:
		addbook(){
			try{
				add();
				cout<<"enter pagecount of book: ";
				cin>>pagecount;
				if(pagecount<=0){
					throw pagecount;
				}
			}
			catch(...){
				cout<<"\ninvalid pagecount!!!";
				pagecount = 0;
			}
		}
		dispbook(){
			disp();
			cout<<"pagecount of book is: "<<pagecount;
		}
};

class tape:public publication{
	float minutes;
	public:
		void addtape(){
			add();
			cout<<"enter the playtime: ";
			cin>>minutes;
			try{
				if(minutes<=0){
					throw minutes;
				}
			}
			catch(...){
				cout<<"\ninvalid playtime!!!";
				minutes = 0;
			}
		}
		void disptape(){
			disp();
			cout<<"playtime of tape: "<<minutes<<" min";
		}
};

int main(){
	book b1[10];
	tape t1[10];
	int ch,b_count =0,t_count = 0;
	do{
		cout<<"\n*******PUBLICATION DATABASE SYSTEM*********";
		cout<<"\n----------------MENU-----------------------";
		cout<<"\n1.add book";
		cout<<"\n2.add tape";
		cout<<"\n3.display book";
		cout<<"\n4.display tape";
		cout<<"\n5.EXIT()";
		cout<<"\nenter your choice: ";
		cin>>ch;
		
		switch(ch){
			case 1: 
			b1[b_count].addbook();
			b_count++;
			break;
			case 2: 
			t1[t_count].addtape();
			t_count++;
			break;
			case 3: 
			cout<<"\n********BOOK PUBLICATION SYSTEM**********\n";
			for(int i =0;i<b_count;i++){
				b1[i].dispbook();
			}
			break;
			case 4: 
			cout<<"\n********TAPE PUBLICATION SYSTEM**********\n";
			for(int i =0;i<t_count;i++){
				t1[i].disptape();
			}
			break;
			case 5:
				exit(0);
				break;
		}
	}while(ch!=5);
	return 0;
}
