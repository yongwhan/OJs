#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define DFS_WHITE -1

vector<vii> AdjList;
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC;
map<int,int> mp;

void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (dfs_num[v.first] == DFS_WHITE) tarjanSCC(v.first);
		if (visited[v.first]) dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
	}
	if (dfs_low[u] == dfs_num[u]) {
		while (1) {
			int v = S.back(); S.pop_back(); visited[v] = 0; mp[v]=numSCC;
			if (u == v) break;
		}
		numSCC++;
	}
}

int main() {
	int V, m, t, x, y; cin>>t;
	for (int c=0; c<t; c++) {
		cin>>V>>m;
		AdjList.assign(V,vii());
		dfs_num.assign(V, DFS_WHITE); dfs_low.assign(V, 0); visited.assign(V, 0);
		dfsNumberCounter = numSCC = 0;
		for (int i=0; i<m; i++) {
			cin>>x>>y;
			AdjList[x-1].push_back({y-1,1});
		}
		for (int i = 0; i < V; i++)
			if (dfs_num[i] == DFS_WHITE)
				tarjanSCC(i);
		vector<int> indeg(numSCC,0);
		vector<bool> vis(numSCC,false);
		vector<set<int>> adj;
		adj.assign(numSCC, set<int>());
		for (int i=0; i<V; i++)
			for (auto e : AdjList[i])
				if(mp.find(i)!=mp.end())
					if(mp[i]!=mp[e.first])
						adj[mp[i]].insert(mp[e.first]);
		for (int i=0; i<numSCC; i++)
			for (auto e : adj[i])
				indeg[e]++;
		int ret=0;
		for (int i=0; i<numSCC; i++) if(!indeg[i]) {
			ret++;
			queue<int> q; q.push(i); vis[i]=true;
			while(!q.empty()) {
				int cur=q.front(); q.pop();
				for (auto nxt : adj[cur])
					if(!vis[nxt]) vis[nxt]=true, q.push(nxt);
			}
		}
		cout << ret << endl;
	}
	return 0;
}
