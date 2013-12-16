#include <iostream>
#include<math.h>
using namespace std;

int main(){
	long long t,n,x,y,ans=0,r;
	cin >> t;
	while(t!=0){
		cin >> n;
		ans=0;
		for(int i=1;i<=(int)sqrt(n);i++){
			if(n%i==0){
				y=n/i;
				x=i;
				while(x!=0){
					r=x%10;
					if(r==4 || r==7){
						ans++;	
						break;
					}
					x=x/10;
				}
				while(y!=0){
					r=y%10;
					if(r==4 || r==7){
						ans++;
						break;
					}
					y=y/10;
				}

			}
		}
		cout << ans << endl;
		t--;
	}
	return 0;
} 
