#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		int x; cin>>x; x/=100;
		int grid[10][x];
		for (int i=0; i<10; i++)
			for (int j=0; j<x; j++)
				cin>>grid[9-i][j];

		int fuel[]={20,30,60}, dp[10][x+1];
		for (int i=0; i<10; i++)
			for (int j=0; j<x+1; j++)
				dp[i][j]=1e9;
		dp[0][0]=0;

		for (int i=0; i<x; i++)
			for (int j=0; j<10; j++)
				for (int k=-1; k<=1; k++) {
					int t=j+k;
					if(0<=t&&t<10)
						dp[t][i+1]=min(dp[t][i+1], dp[j][i] + fuel[k+1]-grid[j][i]);
				}
		cout << dp[0][x] << endl << endl;
	}
	return 0;
}
