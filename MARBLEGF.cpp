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
int getMid(int l, int r) {  
return l + (r -l)/2;  
}
 
ll getSum(ll *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return getSum(st, ss, mid, qs, qe, 2*index+1) +
           getSum(st, mid+1, se, qs, qe, 2*index+2);
}
void updateValue(ll *st, int ss, int se, int i, int diff, int index)
{
    if (i < ss || i > se)
        return;
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValue(st, ss, mid, i, diff, 2*index + 1);
        updateValue(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 
ll makeTree(int arr[], int ss, int se, ll *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = makeTree(arr, ss, mid, st, si*2+1) +
              makeTree(arr, mid+1, se, st, si*2+2);
    return st[si];
}
ll *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); 
    ll max_size = 2*(int)pow(2, x) - 1;
    ll *st = new ll[max_size];
 
    makeTree(arr, 0, n-1, st, 0);
    return st;
}
 
int main(){
ll n,q;
sl2(n,q);
 int a[n];
FOR(i,n)
	si(a[i]);
ll *s = constructST(a,n);
char c;
int x,y;
while(q!=0){
cin >> c >> x >> y;
if(c=='G'){
updateValue(s,0,n-1,x,y,0);
}
if(c=='T'){
y=y*(-1);
updateValue(s,0,n-1,x,y,0);
}
if(c=='S'){
printf("%lld\n",getSum(s,0,n-1,x,y,0));
}
q--;
}
return 0;
} 
