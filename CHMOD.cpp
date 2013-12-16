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
long long  exp(int ,int ,long long);
using namespace std;

int main() {
	int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	ll ans=1;
	int n,t;
	si(n);
	ll a[n];
	static int freq[100001][25];
	int sum[25];
	fill(freq,0);
	fill(sum,0);
	FOR(i,n)
		sl(a[i]);

	FOR(i,n){

		FOR(j,25){

			ll x = a[i];

			while(x%prime[j]==0){

				sum[j]++;
				x/=prime[j];
			}
			freq[i][j]=sum[j];
			//cout << freq[i][j] << endl;

		}
	}
	si(t);
	int l,r,x1=0;
	long long m;
	ll temp;
	while(t!=0){
		si2(l,r);
		sl(m);
		ans=1;
		FOR(i,25){
			if(l>=2){
				x1=freq[r-1][i]-freq[l-2][i];
			}
			else
				x1=freq[r-1][i];
			temp=exp(prime[i],x1,m);
			ans=(ans*temp)%m;
		}
		printf("%lld\n",ans);
		t--;
	}

	return 0;
}

long long  exp(int a,int b,long long m)
{
	if(b==0)
		return 1%m;

	long long int x=a,ans=1;

	while(b)
	{
		if(b&1)
		{
			ans=(ans*x)%m;
		}

		b>>=1;
		x=(x*x)%m;
	}

	return ans;
}
