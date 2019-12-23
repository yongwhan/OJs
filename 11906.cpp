#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
bool ok(int x, int l) {
	return 0<=x&&x<l;
}
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int cs=1; cs<=t; cs++) {
		int r,c,m,n,w,x,y,e=0,o=0; cin>>r>>c>>m>>n;
		vector<int> dx, dy;
		for (int i=0; i<2; i++) {
			for (int j=0; j<2; j++) for (int k=0; k<2; k++)
				dx.push_back(n*(j*2-1)), dy.push_back(m*(k*2-1));
			swap(n,m);
		}
		bool water[r][c];
		for (int i=0; i<r; i++) for (int j=0; j<c; j++) water[i][j]=false;
		cin>>w;
		for (int i=0; i<w; i++)
			cin>>x>>y, water[x][y]=true;
		set<ii> vis;
		ii init={0,0};
		queue<ii> q; q.push(init); vis.insert(init);
		while(!q.empty()) {
			ii cur=q.front(); q.pop();
			int val=0;
			set<ii> dup;
			for (int i=0; i<8; i++) {
				ii nxt=cur; nxt.first+=dx[i]; nxt.second+=dy[i];
				if(dup.find(nxt)==dup.end()) {
					dup.insert(nxt);
					if(ok(nxt.first,r)&&ok(nxt.second,c)&&!water[nxt.first][nxt.second]) {
						val++;
						if(vis.find(nxt)==vis.end()) vis.insert(nxt), q.push(nxt);
					}
				}
			}
			if(val%2) o++;
			else e++;
		}
		cout << "Case " << cs << ": " << e << " " << o << endl;
	}
	return 0;
}
