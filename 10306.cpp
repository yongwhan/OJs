#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=305, inf=1e9;
int dp[mx][mx];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for (int c=0; c<n; c++) {
		int m,S; cin>>m>>S;
		for (int i=0; i<=S; i++)
			for (int j=0; j<=S; j++)
				dp[i][j]=inf;
		dp[0][0]=0;
		for (int t=0; t<m; t++) {
			int a,b; cin>>a>>b;
			for (int i=a; i<=S; i++)
				for (int j=b; j<=S; j++)
					dp[i][j]=min(dp[i][j],dp[i-a][j-b]+1);
		}
		int ret=inf;
		for (int x=0; x<=S; x++) {
			int y=int(sqrt(S*S-x*x)+1e-6);
			if(x*x+y*y==S*S)
				ret=min(ret,dp[x][y]);
		}
		if(ret==inf) cout << "not possible" << endl;
		else cout << ret << endl;
	}
	return 0;
}
