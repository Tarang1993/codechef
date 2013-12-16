#include<iostream>
#include <stdio.h>
#define ll long long
using namespace std;
 
int main(){
int t;
ll n,k;
scanf("%d",&t);
while(t!=0){
scanf("%lld %lld",&n,&k);
ll v[n][k],a[k],q1=0;
ll q[100001]={0};
ll ans[100001]={0};
 
for(ll i=0;i<n;i++)
	for(ll j=0;j<k;j++)
		scanf("%lld",&v[i][j]);
int flag=0;
for(ll i=0;i<k;i++){
scanf("%lld",&a[i]);
 
if(v[0][i]>a[i])
	flag=1;
}
if(flag==0){
for(ll i=0;i<k;i++)
	ans[i]=v[0][i];
q1=1;
q[0]=1;
}
 
for(ll i=1;i<n;i++){
	int flag=0;
	for(ll j=0;j<k;j++){
		if(ans[j]+v[i][j] >a[j]){
		flag=1;
		break;
		}
	}
	if(flag==0){
	for(ll j=0;j<k;j++){
		ans[j]+=v[i][j];
	
	}
	q[q1] = i+1;
	q1++;
	}
}
	printf("%lld\n",q1);
	for(int i=0;i<q1;i++)
		printf("%lld ",q[i]);
 
	printf("\n");
	t--;		
}
} 
