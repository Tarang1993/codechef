#include<ctype.h>
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
#include<limits.h>
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
int main(){
	int t,n,p,m_s=0,m_c=0,ma_c=0;
	char a[64000],b[64000];
	int f[40][40][40];
	si(t);
	while(t!=0){
		si2(n,p);
		fill(f,0);
		ss(a);ss(b);
		FOR(i,n)
			FOR(j,n)
			FOR(k,n){
				if(i==0 &&j==0 && k==0){
					if(a[0]==b[0])
						f[i][j][k]=1;
					else
						f[i][j][k]=0;			
				}
				else if(j==0 && k==0){
					if(a[i*n*n+j*n+k]==b[i*n*n+j*n+k])
						f[i][j][k]=f[i-1][j][k]+1;
					else
						f[i][j][k]=f[i-1][j][k];
				}
				else if(i==0 && j==0){
					f[i][j][k]=f[i][j][k-1];
					if(a[i*n*n+j*n+k]==b[i*n*n+j*n+k])
						f[i][j][k]++;
				}
				else if(i==0 && k==0){
					f[i][j][k]=f[i][j-1][k];
					if(a[i*n*n+j*n+k]==b[i*n*n+j*n+k])
						f[i][j][k]++;
				}
				else if(i==0){
					f[i][j][k]=f[i][j-1][k]+f[i][j][k-1]-f[i][j-1][k-1];
					if(a[i*n*n+j*n+k]==b[i*n*n+j*n+k])
						f[i][j][k]++;
				}
				else if(j==0){
					f[i][j][k]=f[i-1][j][k]+f[i][j][k-1]-f[i-1][j][k-1];
					if(a[i*n*n+j*n+k]==b[i*n*n+j*n+k])
						f[i][j][k]++;
				}
				else if(k==0){
					f[i][j][k]=f[i-1][j][k]+f[i][j-1][k]-f[i-1][j-1][k];
					if(a[i*n*n+j*n+k]==b[i*n*n+j*n+k])
						f[i][j][k]++;
				}
				else{
					f[i][j][k]=f[i-1][j][k]+f[i][j-1][k]+f[i][j][k-1] - ( f[i-1][j-1][k]+f[i][j-1][k-1] + f[i-1][j][k-1]) + f[i-1][j-1][k-1];
					if(a[i*n*n+j*n+k]==b[i*n*n+j*n+k])
						f[i][j][k]++;
				}
			}
		/*FOR(i,n)
			FOR(j,n)
			FOR(k,n){
				cout <<"("<< i << "," << j << "," << k << ")" << "---" << f[i][j][k] << endl;
 
 
			}*/	
		int c;
		float exp;
		m_s=0;
		m_c=0;
		ma_c=0;
		for(int size=1;size<=n;size++){
			m_c=0;
			exp = ceil((float)(((size*size*size)*p)/100.0));
			for(int i=0;i<=(n-size);i++)
				for(int j=0;j<=(n-size);j++)
					for(int k=0;k<=(n-size);k++){
						if(i==0 && j==0 && k==0){
							if((f[i+size-1][j+size-1][k+size-1]) >= exp){
								if(size >= m_s){
									m_s=size;
									m_c++;
									ma_c=m_c;
								}
							}
						}
						else{
							if(i==0 && j==0 && k!=0){
									if((f[i+size-1][j+size-1][k+size-1] - f[i+size-1][j+size-1][k-1]) >=exp){
										if(size >= m_s){
											m_s=size;
											m_c++;
											ma_c=m_c;
										}
									}
								}
								if(i!=0 && j==0 && k==0){
									if((f[i+size-1][j+size-1][k+size-1] - f[i-1][j+size-1][k+size-1]) >=exp){
										if(size >= m_s){
											m_s=size;
											m_c++;
											ma_c=m_c;
										}
									}
								}
								if(i==0 && j!=0 && k==0){
									if(f[i+size-1][j+size-1][k+size-1] - f[i+size-1][j-1][k+size-1] >=exp){
										if(size >= m_s){
											m_s=size;
											m_c++;
											ma_c=m_c;
										}
									}
								}
								if(i==0 && j!=0 && k!=0){
									if((f[i+size-1][j+size-1][k+size-1] - f[i+size-1][j+size-1][k-1] - (f[i+size-1][j-1][k+size-1] - f[i+size-1][j-1][k-1])) >=exp){
										if(size >= m_s){
                                                                                        m_s=size;
                                                                                        m_c++;
                                                                                        ma_c=m_c;
                                                                                }
									}
								}
								if(i!=0 && j!=0 && k==0){
                                                                        if((f[i+size-1][j+size-1][k+size-1] - f[i+size-1][j-1][k+size-1] - (f[i-1][j+size-1][k+size-1] - f[i-1][j-1][k+size-1])) >=exp){
                                                                                if(size >= m_s){
                                                                                        m_s=size;
                                                                                        m_c++;
                                                                                        ma_c=m_c;
                                                                                }
                                                                        }
                                                                }
								if(i!=0 && j==0 && k!=0){
                                                                        if((f[i+size-1][j+size-1][k+size-1] - f[i+size-1][j+size-1][k-1] - f[i-1][j+size-1][k+size-1] + f[i-1][j+size-1][k-1]) >=exp){
                                                                                if(size >= m_s){
                                                                                        m_s=size;
                                                                                        m_c++;
                                                                                        ma_c=m_c;
                                                                                }
                                                                        }
                                                                }
								if(i!=0 && j!=0 && k!=0){
                                                                        if((f[i+size-1][j+size-1][k+size-1] - f[i+size-1][j+size-1][k-1] - f[i+size-1][j-1][k+size-1] + f[i+size-1][j-1][k-1] - f[i-1][j+size-1][k+size-1] + f[i-1][j-1][k+size-1] + f[i-1][j+size-1][k-1] - f[i-1][j-1][k-1]) >=exp){
                                                                                if(size >= m_s){
                                                                                        m_s=size;
                                                                                        m_c++;
                                                                                        ma_c=m_c;
                                                                                }
                                                                        }
                                                                }
							}	
						}	
					}
			 
			if(m_s==0 || ma_c==0)
				printf("-1\n");
			else
				printf("%d %d\n",m_s,ma_c);
			t--;
 
		}
 
		return 0;
	} 
