#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
struct dat {
	int r,c,cost;
	dat(int _r, int _c, int _cost) {
		r=_r; c=_c; cost=_cost;
	};
  bool operator>(const dat &e) const { return this->cost > e.cost; }
};

int main() {    
	int t; scanf("%d", &t);
	while(t--) {
		int n,m; scanf("%d %d", &n, &m);
		int maze[n][m];
		for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", &maze[i][j]);
		priority_queue<dat, vector<dat>, greater<dat> > pq;
		vector<vector<int>> cost(n, vector<int>(m, -1));
		dat e(0,0,maze[0][0]);
		pq.push(e);
		cost[0][0]=e.cost;
		while (!pq.empty()) {
			dat cur=pq.top(); pq.pop(); 
			for (int i = 0; i < 4; ++i) {
				int r=cur.r+dx[i], c=cur.c+dy[i];
				if(r<0||r>=n||c<0||c>=m) continue;
				if(cost[r][c] == -1 || cost[cur.r][cur.c] + maze[r][c] < cost[r][c])
					cost[r][c]=cost[cur.r][cur.c]+maze[r][c], pq.push(dat(r,c,cost[r][c]));
			}
		}
		printf("%d\n", cost[n-1][m-1]);
	}
	return 0;
}
