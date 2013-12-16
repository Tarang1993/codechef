#include <iostream>
using namespace std;
 
int main(){
int t,h1,h2,m1,m2,t1,t2,sec;
cin >> t;
while(t!=0){
cin >> h1 >> m1 >> t1;
cin >> h2 >> m2 >> t2;
 
sec =(h2-h1)*3600 + (m2-m1)*60 + (t2-t1);
sec = sec/100;
 
if(sec%2==0)
cout << "S" << endl;
else
cout << "C" << endl;
t--;
}
return 0;
}
 
