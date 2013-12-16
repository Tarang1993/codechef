#include <ctype.h>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<climits>
#include <limits.h>
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
 
#define ch char
#define fl float
 
#define out(x) cout << x << endl
#define out2(x,y) cout << x << " " << y << endl
#define out3(x,y,z) cout << x << " " << y << " " << z << endl
 
#define printi(x) printf("%lld\n",x)
#define printi2(x,y) printf("%lld %lld\n",x,y)
#define printi3(x,y,z) printf("%lld %lld %lld\n",x,y,z)
#define prints(x) printf("%s\n",x)
 
using namespace std;
 
int main(){
	int t;
	ll n,k,ans1,ans2;
	si(t);
	while(t!=0){
		sl2(n,k);
		ll a[n];
		FOR(i,n){
			sl(a[i]);
		}
		ll dp1[n],dp2[n];
		ll max_so_far_1 = a[0];
                ll curr_max = a[0];
               	dp1[0]=a[0];
                for (int i = 1; i < n-k-1; i++)
                {
                        curr_max = max(a[i], curr_max+a[i]);  
                        max_so_far_1 = max(max_so_far_1, curr_max);
			dp1[i]=max_so_far_1;
                }
		max_so_far_1 = a[n-1];
                curr_max = a[n-1];
                dp2[n-1]=a[n-1];
                for (int i = n-2; i > k; i--)
                {
                        curr_max = max(a[i], curr_max+a[i]);
                        max_so_far_1 = max(max_so_far_1, curr_max);
                        dp2[i]=max_so_far_1;
                }
	
		ll m=LONG_MIN;
		for(int i=0;i<n-k-1;i++){
 
			if(dp1[i]+dp2[i+k+1] > m){
				m=dp1[i]+dp2[i+k+1];
			}
 
		}
		//cout << dp1[2] << " " << dp2[3] << endl;
		printf("%lld\n",m);
	
		t--;
	}
	return 0;
} 
