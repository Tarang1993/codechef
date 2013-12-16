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
 
using namespace std;
int main(){
	int n,x1,y1,x2,y2;
	ll q;
	si(n);
	int a[n][n];
	int f[n][n][11];
	//fill(f[n][n],0);
	FOR(i,n){
		FOR(j,n){
			si(a[i][j]);
			for(int k=0;k<11;k++)
				f[i][j][k]=0;
 
			if(i==0 && j==0){
				f[i][j][a[i][j]]++;	
			}
			else if(j==0){
				for(int k=1;k<11;k++){
					f[i][j][k]=f[i-1][j][k];
				}
				f[i][j][a[i][j]]++;
			}
			else if(i==0){
				for(int k=1;k<11;k++){
                                        f[i][j][k]=f[i][j-1][k];
                                }
				f[i][j][a[i][j]]++;
			}
			else{
				for(int k=1;k<11;k++){
					f[i][j][k]=f[i][j-1][k]+f[i-1][j][k] - f[i-1][j-1][k];
				}
				f[i][j][a[i][j]]++;
//
			}
		}
	}
	sl(q);
	while(q!=0){
		si3(x1,y1,x2);
		si(y2);
		ll ans=0;
		if (x1==x2 && y1==y2)
			ans=1;
		
		else if((y1-1)==0 && (x1-1)!=0){
			for(int i=1;i<11;i++)
				ans+=(f[x2-1][y2-1][i] - f[x1-2][y2-1][i])>0 ?1:0;
		}
		else if((y1-1)!=0 && (x1-1)==0){
			for(int i=1;i<11;i++)
				ans+=(f[x2-1][y2-1][i] - f[x2-1][y1-2][i])>0 ? 1:0;
		}
		else if(x1-1==0 && y1-1==0){
			for(int i=1;i<11;i++)
				ans+=(f[x2-1][y2-1][i])>0 ? 1 : 0;
		}
		else{
			for(int i=1;i<11;i++)
				ans+=(f[x2-1][y2-1][i] - f[x2-1][y1-2][i] - (f[x1-2][y2-1][i]-f[x1-2][y1-2][i]))>0?1:0;
		} 
		
//		for(int i=1;i<11;i++)
//			cout << f[1][2][i] << endl;
		/*for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				for(int k=1;k<11;k++)
					cout <<"(" << i <<"," <<j << ")" << "-- "<< k << "--" << f[i][j][k] << endl;
			}*/
		printf("%lld\n",ans);
 
		q--;
	}
	return 0;
} 
