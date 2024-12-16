#include<iostream>
#include<fstream>
using namespace std;
class student{
	public:
		int roll;
		string name;
		int marks;
		void get(){
			cout<<"enter Roll Number: ";
			cin>>roll;
			cout<<"enter Name: ";
			cin.ignore();
			getline(cin,name);
			cout<<"enter marks: ";
			cin>>marks;
		}
		void display(){
			cout<<"Roll Number: "<<roll<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Marks: "<<marks<<endl;
		}
};

int main(){
	int i,n;
	student s[10];
	fstream file;
	file.open("student.pdf",ios::out);
	cout<<"enter total number of students: ";
	cin>>n;
	for(i = 0;i<n;i++){
		s[i].get();
		file.write((char*)&s[i],sizeof(s[i]));
	}
	file.close();
	
	file.open("student.pdf",ios::in);
	cout<<"Reading from the file..........."<<endl;
	for(i =0;i<n;i++){
		file.read((char*)&s[i],sizeof(s[i]));
		s[i].display();
	}
	
	file.close();
	return 0;
}
