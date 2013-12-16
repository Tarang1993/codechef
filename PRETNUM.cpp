#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<math.h>
#include <map>
#define ll long long 
#define mod 1000000007
 
using namespace std;
ll power (ll a, ll b)
{
	if (a == 0)
		return 0;
	ll ans = 1;
	while (b > 0)
	{
		if (b % 2)
			ans = (ans * a);
		b >>= 1;
		a = (a * a);
	}
	return ans;
}
int main()
{
    int casen;
 
    scanf("%d", &casen);
    while(casen--)
    {
        ll n,m;
        ll ans=0,c=0;
        scanf("%lld %lld", &n, &m);
        ll * primes = new ll[m-n+1];
        for(ll i=0;i<m-n+1;++i)
        primes[i] = 0;
	
        for(ll p=2;p*p<=m;++p)
        {
            ll less = n / p;
            less *= p; 
 
            for(ll j=less;j<=m;j+=p) if(j != p && j >= n)
            primes[j - n] = 1;
        }
 
        for(ll i=0;i<m-n+1;++i)
        {
            if(primes[i] == 0 && (n+i)!=1){
            	c++;
            	
            	}
            
        }
        
        
        ll * prime = new ll[1000000];
        for(ll i=0;i<1000000;++i)
        prime[i] = 0;
	
        for(ll p=2;p*p<=1000000;++p)
        {
            ll less = 1 / p;
            less *= p; 
 
            for(ll j=less;j<=1000000;j+=p) if(j != p && j >= 1)
            prime[j - 1] = 1;
        }
 
        for(ll i=0;i<1000000;++i)
        {
            if(prime[i] == 0 && (1+i)!=1){
            int x=2;
        ll t1=power(i+1,x);
        if(t1>m)
        	break;
        while(t1<=m){
        	if(t1>=n && prime[x]==0){
        		ans++;
        		}
        	x++;
        	t1=power(i+1,x);
        }
         }   	
            
        }
	printf("%lld\n",ans+c);
        delete [] prime;
        delete [] primes;
    }
} 
