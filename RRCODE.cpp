#include <iostream>
using namespace std;

int main(){
	int t,n,k;
	long long ans,ans1,ans2;
	cin >> t;
	while(t!=0){
		cin >> n >> k >> ans;
		long long a[n];
		long long ar;
		string s;
		for (int i=0;i<n;i++)
			cin >> a[i];
		cin >> s;
		ar=a[0];
		if(k==0){
			cout << ans << endl;
			continue;
		}
		if(s=="XOR"){
			for(int i=1;i<n;i++)
				ar=ar^a[i];

			if(k%2==0)
				cout << ans << endl;
			else
				cout << (ans^ar) << endl;

		}
		if(s=="OR"){

			for(int i=1;i<n;i++)
				ar=ar|a[i];
			ans1=ans|ar;
			cout << ans1 << endl;
		}
		if(s=="AND"){
			for(int i=1;i<n;i++)
				ar=ar&a[i];
			ans1=ans&ar;
			cout << ans1 << endl;
		}
		t--;
	}
	return 0;
} 

