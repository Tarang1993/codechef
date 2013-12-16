#include <iostream>
#include <algorithm>
int maxSubArraySum(int a[], int);
using namespace std;
int maxSubArraySum(int a[],int size){
        int max_so_far = a[0],i;
        int curr_max = a[0];
        for (i=1;i<size;i++){
                curr_max = max(a[i],curr_max+a[i]);
                max_so_far = max(max_so_far,curr_max);
        }
        return max_so_far;
}
 
int main(){
        int n,ans,t;
        int a[250001];
        cin >> t;
        while(t!=0){
                cin >> n;
 
                for (int i=0;i<n;i++){
                        cin >> a[i];
                }
                ans = maxSubArraySum(a,n);
                cout << ans << endl;
                t--;
        }
        return 0;
}
