#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

bool ok(int x, int y, vector<string> &grid, string &s) {
	int n=grid.size(), m=grid[0].size(), k=s.size();
	for (int dx=-1; dx<=1; dx++) for (int dy=-1; dy<=1; dy++) {
		if(dx||dy) {
			bool ok=true;
			for (int t=0; t<k; t++) {
				int xx=x+dx*t, yy=y+dy*t;
				if(0<=xx&&xx<n&&0<=yy&&yy<m) {
					if(tolower(grid[xx][yy])!=tolower(s[t])) {
						ok=false; break;
					}
				} else { ok=false; break; }
			}
			if(ok) return true;
		}
	}
	return false;
}

ii eval(string &s, vector<string> &grid) {
	int n=grid.size(), m=grid[0].size(), k=s.size();
	for (int i=0; i<n; i++) for (int j=0; j<m; j++)
		if(ok(i,j,grid,s))
			return {i+1,j+1};
	return {-1,-1};
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		if(c) cout << endl;
		int n,m; cin>>n>>m;
		vector<string> grid(n);
		for (int i=0; i<n; i++) cin>>grid[i];
		int k; cin>>k;
		while(k--) {
			string cur; cin>>cur;
			ii ret=eval(cur,grid);
			cout << ret.first << " " << ret.second << endl;
		}
	}
	return 0;
}
