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
#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
 
int main() {
	int n,c=0,c1=0;
	scanf("%d",&n);
	int a[n][n];
	static int f[1000][1000][6],f1[1000][1000][6];
	//memset(f,0,sizeof(f));
	FOR(i,n){
		FOR(j,n){
			scanf("%d",&a[i][j]);
			}
	}
	FOR(i,n)
		FOR(j,n){
			if(a[i][j]!=0 && f[i][j][5]!=1){
				f[i][j][0]=a[i][j];
				int x=i,y=j;
				while(x!=(n) && a[x][j]==a[i][j]){
				f[x][j][5]=1;
				f[i][j][2]=x+1;
				x++;
				}
				f[i][j][1]=i+1;
				
				f[i][j][3]=j+1;
				f[i][j][4]=j+1;
				f[i][j][5]=2;
				
				c++;
			}
			else{
				f[i][j][0]=-1;
			}
			
			if(a[i][j]!=0 && f1[i][j][5]!=1){
				f1[i][j][0]=a[i][j];
				int x=i,y=j;
				while(y!=(n) && a[i][y]==a[i][j]){
				f1[i][y][5]=1;
				f1[i][j][4]=y+1;
				y++;
				}
				f1[i][j][1]=i+1;
				f1[i][j][2]=i+1;
				f1[i][j][3]=j+1;
				f1[i][j][5]=2;
				c1++;
			}
			else{
				f1[i][j][0]=-1;
			}
 
		
		}
	printf("%d\n",min(c,c1));
	if(c<c1)
	FOR(i,n)
		FOR(j,n){
			if(f[i][j][0]!=-1 && f[i][j][5]==2)
				printf("%d %d %d %d %d\n",f[i][j][0],f[i][j][1],f[i][j][2],f[i][j][3],f[i][j][4]);
			
		}
	else{
	FOR(i,n)
		FOR(j,n){
			if(f1[i][j][0]!=-1 && f1[i][j][5]==2)
				printf("%d %d %d %d %d\n",f1[i][j][0],f1[i][j][1],f1[i][j][2],f1[i][j][3],f1[i][j][4]);
	}
	}
	return 0;
}    
