#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
const int mx=1007, inf=1e9+7;
int dist[mx][mx];

bool ok(int x, int l) {
	return 0<=x&&x<l;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int R,C;
	while(cin>>R>>C) {
		if(!R&&!C) return 0;
		int rows,row,num,col,grid[R][C]; cin>>rows;
		for (int i=0; i<R; i++) for (int j=0; j<C; j++) grid[i][j]=1, dist[i][j]=inf;
		for (int i=0; i<rows; i++) {
			cin>>row>>num;
			for (int j=0; j<num; j++) cin>>col, grid[row][col]=0;
		}
		ii start,dest; cin>>start.first>>start.second>>dest.first>>dest.second;
		queue<ii> q; q.push(start);
		dist[start.first][start.second]=0;
		int ret=0;
		while(!q.empty()) {
			ii cur=q.front(); q.pop();
			if(cur==dest) { ret=dist[cur.first][cur.second]; break; }
			for (int i=0; i<4; i++) {
				ii nxt=cur; nxt.first+=dx[i]; nxt.second+=dy[i];
				if(ok(nxt.first,R)&&ok(nxt.second,C)&&dist[nxt.first][nxt.second]==inf&&grid[nxt.first][nxt.second]) q.push(nxt), dist[nxt.first][nxt.second]=dist[cur.first][cur.second]+1;
			}
		}
		cout << ret << endl;
	}
}
