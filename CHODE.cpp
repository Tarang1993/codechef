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
 
bool fun(const std::pair<unsigned char, int>& firstElem, const std::pair<unsigned char, int>& secondElem) {
if(firstElem.second == secondElem.second)
	return false;
return firstElem.second < secondElem.second ;
}
 
int main(){
int t;
si(t);
while(t!=0){
string s,f;
cin >> s;
cin.ignore();
getline (cin,f);
map <unsigned char,int> m;
for(int i=0;i<f.length();i++){
	if(isalpha(f[i])){
		m[tolower(f[i])]++;
	}
}
 
vector < pair<unsigned char,int> > mapcopy(m.begin(),m.end());
 
int l = mapcopy.size();
for(int i=0;i<l;i++)
	for(int j=0;j<l-1-i;j++){
		if(mapcopy[j].second > mapcopy[j+1].second){
		pair <unsigned char, int>temp = mapcopy[j+1];
		mapcopy[j+1] = mapcopy[j];
		mapcopy[j] = temp;
		
		}
	
	}
 
map <unsigned char,unsigned char> c;
int j=0;
for(int i=26-l;i<26;i++){
c[mapcopy[j].first]=s[i];
j++;
}
for(int i=0;i<f.length();i++){
	if(!isalpha(f[i]))
	cout << f[i];
	else{
	if(isupper(f[i])){
		cout << (unsigned char)toupper(c[tolower(f[i])]);
	}
	else{
		cout << c[f[i]];
	}
 
	}
 
}
cout << endl;
t--;
}
return 0;
} 
