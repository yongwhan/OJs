#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		int v,e,x,y; cin>>v>>e;
		vector<set<int>> adj(v);
		for (int i=0; i<e; i++)
			cin>>x>>y, adj[x].insert(y), adj[y].insert(x);
		int ret=0;
		vector<int> col(v,0);
		for (int i=0; i<v; i++) {
			if(!col[i]) {
				int blue=0, red=0;
				col[i]=1;
				queue<int> q; q.push(i);
				while(!q.empty()) {
					int cur=q.front(); q.pop();
					if(col[cur]==1) blue++;
					else red++;
					for (auto nxt : adj[cur]) {
						if(!col[nxt]) col[nxt]=3-col[cur], q.push(nxt);
						else {
							if(col[cur]+col[nxt]!=3) {
								ret=-1; break;
							}
						}
					}
				}
				if(ret!=-1) {
					if(blue&&red) ret+=min(blue,red);
					else ret+=max(blue,red);
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}
