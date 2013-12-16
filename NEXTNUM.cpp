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
 
long long gcd (long long a, long long b)
{
  if (b > a)
    return 1;
 
  if (a % b == 0)
    return b;
 
  return gcd (b, a % b);
}
 
ll num (vector < int >a)
{
 
  map < int, int >m;
  m.clear ();
  long long num = 1, den = 1, k;
 
  sort (a.begin (), a.end ());
  int i, j;
 
  for (i = 0; i < a.size (); i++)
    {
      m[a[i]]++;
    }
 
 
  for (i = a.size (); i >= 1; i--)
    {
      num = num * i;
      for (j = m[a[i]]; j >= 1; j--)
   den = den * j;
      m[a[i]] = 1;
 
      k = gcd (num, den);
      num = num / k;
      den = den / k;
    }
 
  return num;
 
}
 
 
int main ()
{
  char stra[20];
  int t;
  scanf("%d",&t);
 
  while (t!=0)
    {
    scanf("%s",stra);
 
      string str1, str;
      int arr[300];
      str1 = stra;
      int len = strlen (stra);
 
      sort (stra, stra + len);
      str = stra;
      int cnt = 1, i = 0;
      vector < int >v, v1;
 
      map < char, int >m;
      m.clear ();
 
      for (i = 0; i < len; i++)
   {
     if (m.count (stra[i]) == 0)
       m[stra[i]] = cnt++;
 
     v.push_back (m[stra[i]]);
   }
      for (i = 0; i < len; i++)
   {
     v1.push_back (m[str1[i]]);
   }
 
 
      int j = 0, prev = -1, idx = 0;
      ll offset=0;
      while (v.size () > 1)
   {
     if (prev != -1 && prev == v[j])
       {
         j++;
         continue;
       }
 
     swap (v[0], v[j]);
     vector < int >tmp = v;
     tmp.erase (tmp.begin ());
     ll p = num (tmp);
     prev = v[0];
 
     if (v[0] == v1[0])
       {
         v.erase (v.begin ());
         v1.erase (v1.begin ());
         j = 0;
         prev = -1;
     sort (v.begin (), v.end ());
       }
     else
       {
         offset += p;
         swap (v[j], v[0]);
         j++;
       }
 }
      printf ("%lld\n", offset + 1);
      t--;
    }
 
  return 0;
} 
