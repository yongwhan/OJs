#include<bits/stdc++.h>
using namespace std;

bool bipartite(vector<vector<int>> &adj, int n) {
	vector<int> col(n,0);
	for (int i=0; i<n; i++) {
		if(!col[i]) {
			col[i]=1;
			queue<int> q; q.push(i);
			while(!q.empty()) {
				int cur=q.front(); q.pop();
				for (auto nxt : adj[cur]) {
					if(!col[nxt]) col[nxt]=3-col[cur], q.push(nxt);
					else {
						if(col[cur]+col[nxt]!=3) return false;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int v;
	while(cin>>v) {
		if(!v) return 0;
		vector<vector<int>> adj(v);
		int a,b;
		while(cin>>a>>b) {
			if(!a&&!b) break;
			a--, b--,
			adj[a].push_back(b),
			adj[b].push_back(a);
		}
		if(bipartite(adj,v)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
