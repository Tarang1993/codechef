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
 
using namespace std;
int minCut(string);  	  
int main(){
	int t,n,m,ans,m1;
	scanf("%d",&t);
	string s;
	while(t!=0){
		scanf("%d",&n);
		cin >> s;
		printf("%d\n",minCut(s)+1);
 		t--;
	}
	return 0;
}
  
int minCut(string str){
 
        int leng = str.length();
 
        int dp[leng+1];
        static bool palin[5000][5000];
 
      for(int i = 0; i <= leng; i++)
        dp[i] = leng-i;
        for(int i = 0; i < leng; i++)
            for(int j = 0; j < leng; j++)
                palin[i][j] = false;
 
      for(int i = leng-1; i >= 0; i--){
        for(int j = i; j < leng; j++){
          if(str[i] == str[j] && (j-i<2 || palin[i+1][j-1])){
            palin[i][j] = true;
            dp[i] = min(dp[i],dp[j+1]+1);
          }
        }
      }
      return dp[0]-1;
    } 
