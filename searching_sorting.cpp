#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	vector<int> r(3);
	vector<string> n(100);
	vector<string> p(100);
	int z;
	cout<<"enter number of students: "<<endl;
	cin>>z;
	cout<<"roll numbers: "<<endl;
	for(int i =0;i<z;i++){
		cin>>r[i];
	}
	
	cout<<"name and phone number for corresponding phone number numbers: "<<endl;
	for(int i =0;i<z;i++){ 
		cin>>n[r[i]];
		cin>>p[r[i]];
	}
	
	for(int i = 0;i<z;i++){
		cout<<"roll no.: "<<r[i]<<" name: "<<n[r[i]]<<" ph no.: "<<p[r[i]]<<endl;
	}
	
	sort(r.begin(),r.end());
	cout<<"after sorting: ";
//	for(int i =0;i<z;i++){
//		cout<<r[i]<<" ";
//	}
	for(int i = 0;i<z;i++){
		cout<<"roll no.: "<<r[i]<<" name: "<<n[r[i]]<<" ph no.: "<<p[r[i]]<<endl;
	}
}
