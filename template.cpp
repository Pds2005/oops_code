#include<iostream>
using namespace std;
template<typename T>
void sel_sort(T arr[],int n){
	for(int i =0;i<n;i++){
		int mini = i;
		for(int j =i+1;j<n;j++){
			if(arr[mini]>arr[j]){
				mini = j;	
			}
		}
		T temp = arr[mini];
		arr[mini] = arr[i];
		arr[i] = temp;
	}
}
template<typename T>
void display(T arr[],int n){
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int iarr[] = {64,34,25,99,1,2};
	float farr[] = {64.7,34.6,25.0,99.1,1.9,2.0};
	cout<<"original Array: "<<endl;
	display(iarr,6);
	sel_sort(iarr,6);
	cout<<"sorted Array: "<<endl;
	display(iarr,6);
	
	cout<<"original Array: "<<endl;
	display(farr,6);
	sel_sort(farr,6);
	cout<<"sorted Array: "<<endl;
	display(farr,6);
}
