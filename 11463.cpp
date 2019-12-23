#include<bits/stdc++.h>
using namespace std;

const int inf=1e9+77;
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		int n,r,x,y,s,d,ret=0; cin>>n>>r;
		vector<vector<int>> cost(n, vector<int>(n,inf));
		for (int i=0; i<n; i++) cost[i][i]=0;
		for (int i=0; i<r; i++) cin>>x>>y, cost[x][y]=cost[y][x]=1;
		for (int k=0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
		cin>>s>>d;
		for (int i=0; i<n; i++) if(cost[s][i]!=inf&&cost[i][d]!=inf) ret=max(ret,cost[s][i]+cost[i][d]);
		cout << "Case " << c << ": " << ret << endl;
	}
	return 0;
}
