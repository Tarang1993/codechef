#include <iostream>
#include <math.h>
int num(long long);
using namespace std;

int main(){
	int t;
	cin >>t;
	long long l,r,sum;
	while(t!=0){
		sum=0;
		cin >> l >> r;
		int d=num(l);
		int f=num(r);
		//cout << d << f;
		long long x2,x1=l,n;
		if(d==f){
			n=r-l+1;
			//cout << d << endl;
			sum+=((n)*(2*l+n-1)*d)/2;
		}
		else{
			for(int i=d;i<f;i++){
				x2=pow(10,i)-1;
				//cout << x2 << endl;
				n=x2-x1+1;
				sum+=((n)*(2*x1+n-1)*i)/2;
				x1=pow(10,i);
				//cout << x1 << endl;
			}
			x1=pow(10,f-1);
			x2=r;
			n=x2-x1+1;
			sum+=((n)*(2*x1+n-1)*f)/2;
		}
		sum=sum%(1000000000+7);
		cout << sum << endl;
		t--;
	}
	return 0;
}

int num(long long l){
	int c=0;
	while(l!=0){
		l=l/10;
		c++;
	}
	return c;
} 
