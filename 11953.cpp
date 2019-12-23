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
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		int n; cin>>n;
		char grid[n][n];
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				cin>>grid[i][j];
		int ret=0;
		for (int i=0; i<n; i++) for (int j=0; j<n; j++) if(grid[i][j]=='x') {
			ret++;
			queue<ii> q; q.push({i,j}); grid[i][j]='.';
			while(!q.empty()) {
				ii cur=q.front(); q.pop();
				for (int k=0; k<4; k++) {
					ii nxt=cur; nxt.first+=dx[k]; nxt.second+=dy[k];
					if(ok(nxt.first,n)&&ok(nxt.second,n)) {
						char ch=grid[nxt.first][nxt.second];
						if(ch=='x'||ch=='@')
							grid[nxt.first][nxt.second]='.', q.push(nxt);
					}
				}
			}
		}
		cout << "Case " << c+1 << ": " << ret << endl;
	}
	return 0;
}
