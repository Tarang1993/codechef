#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
 
int main(){
int t,n,ans;
cin >> t;
while(t!=0){
cin >> n;
ans=0;
int p[n];
for(int i=0;i<n;i++)
cin >> p[i];
sort(p,p+n);
//cout << p[n/2] << endl;
for(int i=0;i<n;i++){
if(i!=n/2)
ans+=abs(p[n/2]-p[i]);
}
cout << ans << endl;
t--;
 
}
return 0;
}
 
