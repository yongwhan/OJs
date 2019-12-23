#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int mx=2e5;
const int UNVISITED=-1;
vector<int> dfs_low,dfs_num,dfs_parent,articulation_vertex;
vector<vector<ii>> AdjList(mx);
int dfsNumberCounter, dfsRoot, rootChildren;
vector<ii> ret;

void articulationPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (dfs_num[v.first] == UNVISITED) { // a tree edge
			dfs_parent[v.first] = u;
			if (u == dfsRoot) rootChildren++; // special case if u is a root
			articulationPointAndBridge(v.first);
			if (dfs_low[v.first] >= dfs_num[u]) // for articulation point
				articulation_vertex[u] = true; // store this information first
			if (dfs_low[v.first] > dfs_num[u]) { // for bridge
				int a=u, b=v.first;
				if(a>b) swap(a,b);
				ret.push_back({a,b});
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); // update dfs_low[u]
		}
		else if (v.first != dfs_parent[u]) // a back edge and not direct cycle
		dfs_low[u] = min(dfs_low[u], dfs_num[v.first]); // update dfs_low[u]
	}
}

int main() {
	int V;
	while(cin>>V) {
		ret.clear();
		for (int i=0; i<V; i++) AdjList[i].clear();
		for (int j=0; j<V; j++) {
			int x,y; cin>>x;
			char ch; int n; cin>>ch>>n>>ch;
			for (int i=0; i<n; i++) {
				cin>>y;
				AdjList[x].push_back({y,1});
				AdjList[y].push_back({x,1});
			}
		}
		dfsNumberCounter = 0; dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0);
		dfs_parent.assign(V, 0); articulation_vertex.assign(V, 0);
		for (int i = 0; i < V; i++)
			if (dfs_num[i] == UNVISITED) {
				dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		sort(ret.begin(),ret.end());
		cout << ret.size() << " critical links" << endl;
		for (auto e : ret)
			cout << e.first << " - " << e.second << endl;
		cout << endl;
	}
}
