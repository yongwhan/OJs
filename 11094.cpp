#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

bool ok(int x, int l) {
	return 0<=x&&x<l;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m;
	while(cin>>n>>m) {
		int ret=0;
		char grid[n][m];
		for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>grid[i][j];
		int x,y; cin>>x>>y; ii king={x,y};
		char sym=grid[x][y];
		char rst='a';
		if(sym==rst) rst++;
		for (int i=0; i<n; i++) for (int j=0; j<m; j++) if(grid[i][j]==sym) {
			queue<ii> q; q.push({i,j});
			bool flag=true;
			int val=1; grid[i][j]=rst;
			while(!q.empty()) {
				ii cur=q.front(); q.pop();
				if(cur==king) flag=false;
				for (int k=0; k<4; k++) {
					ii nxt=cur; nxt.first+=dx[k]; nxt.second=(nxt.second+m+dy[k])%m;
					if(ok(nxt.first,n)&&grid[nxt.first][nxt.second]==sym)
						val++, grid[nxt.first][nxt.second]=rst, q.push(nxt);
				}
			}
			if(flag) ret=max(ret,val);
		}
		cout << ret << endl;
	}
	return 0;
}
