#include <iostream>
using namespace std;
long long mod=1000000007;
long long mod1(long long,long long);
long long pow1(long long, long long);
int main(){
	int t;
	cin >> t;
	while(t!=0){
		long long n,m,q,k,ans=0,i,c;
		cin >> n >> m >> q >> k;
		i=1;
		i+=q;
		if(i<=m){
			c=m-i+1;
		}
		else
			c=0;
		ans=c*((pow1(q+1,n)) - (2*(pow1(q,n))) + ((pow1(q-1,n))));
		//cout << pow1(q+1,n) << endl;
		//cout << 2*pow1(q,n) << endl;
		//cout << pow1(q-1,n) << endl;
		cout << mod1(ans,mod) << endl;
 
		t--;
	}
	return 0;
}
long long mod1(long long a, long long b)
{ return (a%b+b)%b; }
	
long long pow1 (long long a, long long b)
{
	if (a == 0)
		return 0;
	long long ans = 1;
	while (b > 0)
	{
		if (b % 2)
			ans = (ans * a)%mod;
		b >>= 1;
		a = (a * a)%mod;
	}
	return ans;
} 
