#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define DFS_WHITE -1
#define DFS_BLACK 1

vector<vii> AdjList;
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, dfsRoot, rootChildren, numSCC;

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
		numSCC++;
		while (1) {
			int v = S.back(); S.pop_back(); visited[v] = 0;
			if (u == v) break;
		}
	}
}

int main() {
	int N,M;
	while(cin>>N>>M) {
		if(!N&&!M) return 0;
		AdjList.assign(N, vii());
		dfs_num.assign(N, DFS_WHITE); dfs_low.assign(N, 0); visited.assign(N, 0);
		dfsNumberCounter = numSCC = 0;
		for (int i=0; i<M; i++) {
			int V,W,P;
			cin>>V>>W>>P; V--; W--;
			AdjList[V].push_back({W,1});
			if(P==2) AdjList[W].push_back({V,1});
		}
		for (int i = 0; i < N; i++)
			if (dfs_num[i] == DFS_WHITE)
				tarjanSCC(i);
		cout << (numSCC==1) << endl;
	}
	return 0;
}
