#include <iostream> 
#include <fstream> 
using namespace std; 
 
class Student { 
public: 
    int roll; 
    char name[30]; 
    int marks; 
 
    Student(){} 
 
    void getdata(); 
    void displaydata(); 
}; 
 
void Student :: getdata() { 
    cout<< "\nEnter Students Details-->"<<endl; 
    cout<< "Enter roll no : "; 
    cin >> roll; 
    cin.ignore(); 
    cout<< "Enter Student's name : "; 
    cin.getline(name, 30); 
    cout<< "Enter marks : "; 
    cin >> marks; 
} 
 
void Student :: displaydata(){ 
    cout<< "\nRoll No : " << roll << endl; 
    cout<< "Student's Name : " << name << endl; 
    cout<< "Student's marks : " << marks <<endl; 
} 
 
int main() 
{ 
    Student s[70]; 
    fstream file; 
    int i,n; 
 
    file.open("C:\\Huzaifa\\xyz.txt",ios::out); 
 
    cout<< "Enter Number of Students : "; 
    cin>> n; 
 
 
    for(int i=0; i<n; i++){ 
    s[i].getdata(); 
    file.write((char *)&s[i], sizeof(s[i])); 
    } 
 
    file.close(); 
 
    file.open("C:\\Huzaifa\\xyz.txt", ios::in); 
 
    cout<<"\n Reading Student information to the file..."<<endl; 
 
    for(int i=0; i<n; i++){ 
        file.read((char *)&s[i], sizeof(s[i])); 
        s[i].displaydata(); 
    } 
 
    file.close(); 
    return 0; 
}
