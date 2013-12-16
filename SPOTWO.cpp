#include <iostream>
#include <stdio.h>
using namespace std;
unsigned long long bin(int );
unsigned long long power (unsigned long long a, unsigned long long b);
 
	unsigned long long mod = 1000000007;
	int main(){
		int t,n;
		unsigned long long x,ans;
		scanf("%d",&t);
		while(t!=0){
			scanf("%d",&n);
			x=bin(n);
			ans = power(power(2,x)%mod,2)%mod;
			printf("%llu\n",ans);
			t--;
		}
		return 0;
 
	}
 
unsigned long long bin(int dec){
	unsigned long long rem,i=1,sum=0;
	while(dec>0){
		rem=dec%2;
		sum=sum + (i*rem);
		dec=dec/2;
		i=i*10;
	}
	return sum;
}
 
unsigned long long power (unsigned long long a, unsigned long long b)
{
	if (a == 0)
		return 0;
	unsigned long long ans = 1;
	while (b > 0)
	{
		if (b % 2)
			ans = (ans * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans;
} 
