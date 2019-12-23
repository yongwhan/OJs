#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int V;
const int UNVISITED=-1;
vector<int> dfs_low,dfs_num,dfs_parent,articulation_vertex;
vector<set<ii>> AdjList(105);
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (auto v : AdjList[u]) {
		if (dfs_num[v.first] == UNVISITED) {
			dfs_parent[v.first] = u;
			if (u == dfsRoot) rootChildren++;
			articulationPointAndBridge(v.first);
			if (dfs_low[v.first] >= dfs_num[u])
				articulation_vertex[u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
		}
		else if (v.first != dfs_parent[u])
		dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
	}
}

int s2n(string s) {
	stringstream ss(s); int ret; ss>>ret; return ret;
}

int main() {
	string line;
	while(getline(cin,line)) {
		if(line=="0") return 0;
		V=s2n(line);
		dfsNumberCounter = 0; dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0);
		dfs_parent.assign(V, 0); articulation_vertex.assign(V, 0);
		for (int i=0; i<V; i++)
			AdjList[i].clear();
		while(getline(cin,line)) {
			if(line=="0") break;
			stringstream ss(line);
			int x,y; ss>>x; x--;
			while(ss>>y) {
				y--;
				AdjList[x].insert({y,1});
				AdjList[y].insert({x,1});
			}
		}
		for (int i = 0; i < V; i++)
			if (dfs_num[i] == UNVISITED) {
				dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
			articulation_vertex[dfsRoot] = (rootChildren > 1);
		}
		int ret=0;
		for (int i = 0; i < V; i++)
			if (articulation_vertex[i])
				ret++;
		cout << ret << endl;
	}
	return 0;
}
