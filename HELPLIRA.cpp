#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
	float x1,x2,y1,y2,x3,y3,s,a,b,c;
	int n,x,y;
	cin >> n;
	int ar[n];
	for(int i=0;i<n;i++){
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
		s=(a+b+c)/2;
		ar[i]=sqrt(s*(s-a)*(s-b)*(s-c));
	}
	float min=INT_MAX,max=INT_MIN;
	for(int i=0;i<n;i++){
		if(ar[i]<=min){
			min=ar[i];
			x=i;
		}
		if(ar[i]>=max){
			max=ar[i];
			y=i;
		}
	}
	cout << x+1 << " " << y+1 << endl;
} 
