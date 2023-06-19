#include<iostream>
#include <list>
using namespace std;

int linearsearch(int a[],int n, int lb, int ub){
	
	int c;
	if(ub==lb){
		return 0;
	}
	
	else{
	
		if(a[lb]==n){
			return lb;
		}
		lb++;
			c=linearsearch(a,n,lb,ub);
	}
	
	return c;	
}

int main(){
	
list<int> obj;
 obj.pushfront(1);
	
//int a=searchlinkedlist(arr,7,0,10);
	

	cout<<a<<endl;
	
	
	
	return 0;
}
