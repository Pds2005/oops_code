#include<iostream>
#include<map>
#include<string>
//#include<utility>
using namespace std;
int main(){
	map<string,float> mp;
	mp.insert(make_pair("uttarpradesh",125.5));
	mp.insert(make_pair("up",125.5));
	mp.insert(make_pair("pradesh",12.5));
	mp.insert(make_pair("assam",1.5));
	mp.insert(make_pair("bihar",0.5));
	map<string,float>::iterator it ;
	//mp.erase(it);
	cout<<"all states: "<<endl;
	for(it = mp.begin();it != mp.end();++it){
		cout<<it->first<<" : "<<it->second<<" million"<<endl;
	}
	string state;
	cout<<"enter state name whose population you want: ";
	cin>>state;
	it = mp.find(state);
	if(it != mp.end()){
		cout<<state<<"'s population is: "<<it->second<<" million\n";
	}
	else{
		cout<<"state not found!!";
	}
	return 0;
}
