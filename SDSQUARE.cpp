#include<vector>
#include<iostream>
#include<stdio.h>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<climits>
#include<sstream>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<bitset>
#include <math.h>
 
#define FL(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) for(int i=0;i<n;i++)
#define SORTF(x) sort(x.begin(),x.end(),func);
#define SORT(x) sort(x.begin(),x.end())
#define pb(x) push_back(x)
#define ll long long
#define SET(v, val) memset(v, val, sizeof(v)) ;
#define RSORT(v) { SORT(v) ; REVERSE(v) ; }
#define ALL(v) v.begin(),v.end()
#define REVERSE(v) { reverse(ALL(v)) ; }
#define UNIQUE(v) unique((v).begin(), (v).end())
#define RUNIQUE(v) { SORT(v) ; (v).resize(UNIQUE(v) - (v).begin()) ; }
#define fill(x,n) memset(x,n,sizeof(x))
#define si(x) scanf("%d",&x)
#define si2(x,y) scanf("%d %d",&x,&y)
#define si3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define ss(x) scanf("%s",x)
#define sc(x) scanf("%c",&x)
#define sf(x) scanf("%f",&x)
#define sl(x) scanf("%lld",&x)
#define sl2(x,y) scanf("%lld %lld",&x,&y)
#define sl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ll long long
#define str string
#define lli long long int
#define ch char
#define fl float
#define out(x) cout << x << endl
#define out2(x,y) cout << x << " " << y << endl
#define out3(x,y,z) cout << x << " " << y << " " << z << endl
#define printi(x) printf("%lld\n",x)
#define printi2(x,y) printf("%lld %lld\n",x,y)
#define printi3(x,y,z) printf("%lld %lld %lld\n",x,y,z)
#define prints(x) printf("%s\n",x)
long long power (long long a, long long b);
using namespace std;
int main() {
	int t;
	si(t);
	ll a1,b,ans;
	ans=0;
	static ll a[100001];
	a[0]=0;
 
 
	for(int i=1;i<100001;i++){
		int flag=0;
		long long int temp=power(i,2);
		while(temp!=0){
			int m = temp%10;
			if(m!=1 && m!=0 && m!=4 && m!=9){
				flag=1;
				break;	
			}
			temp=temp/10;
		}
		if(flag==0){
			a[i]=a[i-1]+1;
		}
		else
			a[i]=a[i-1];
	
	}
	
	while(t!=0){
		sl2(a1,b);
		float t1 = sqrt(a1);
		if(t1==(ll)(sqrt(a1)))
			printi(a[(int)(sqrt(b))]-a[(int)(sqrt(a1))-1]);
		else
			printi(a[(int)(sqrt(b))]-a[(int)(sqrt(a1))]);
		t--;
	}
 
	return 0;
}
 
long long power (long long a, long long b)
{
if (a == 0)
return 0;
long long ans = 1;
while (b > 0)
{
if (b % 2)
ans = (ans * a) ;
b >>= 1;
a = (a * a) ;
}
return ans;
}
