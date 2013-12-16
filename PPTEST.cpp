
#include <iostream>
#include <algorithm>
using namespace std;

int KnapSack(int,int[],int[],int);

int main()
{
	int t,n,w1;
	cin >> t;
	while(t!=0){
		cin >>n >> w1;
		int c[n],p1[n],w[n],v[n];
		for(int i=0;i<n;i++){
			cin >> c[i] >> p1[i] >> w[i];
			v[i]=c[i]*p1[i];
		}


		cout << KnapSack(w1,w,v,n) << endl;


		t--;
	}
	return 0;
}

int KnapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n+1][W+1];

	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i==0 || w==0)
				K[i][w] = 0;
			else if (wt[i-1] <= w)
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}

	return K[n][W];
} 
