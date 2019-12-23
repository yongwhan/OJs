#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define DFS_WHITE -1
vector<vii> AdjList;
vi dfs_num, dfs_parent, dfs_low, S, visited;
int dfsNumberCounter, dfsRoot, numSCC;
vector<vi> ret;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  S.push_back(u);
  visited[u] = 1;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      tarjanSCC(v.first);
    if (visited[v.first])
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
  }

  if (dfs_low[u] == dfs_num[u]) {
		vector<int> cur;
    while (1) {
      int v = S.back(); S.pop_back(); visited[v] = 0;
      cur.push_back(v);
      if (u == v) break;
    }
		ret.push_back(cur);
	}
}

map<string,int> s2i;
map<int,string> i2s;

int main() {
	int n,m,c=0;
	while(cin>>n>>m) {
		if(!n&&!m) return 0;
		if(c) cout << endl;
		ret.clear();
		S.clear();
		s2i.clear();
		i2s.clear();
		map<string,set<string>> adj;
	  AdjList.assign(n, vii());
		set<string> st;
	  for (int i = 0; i < m; i++) {
			string x,y; cin>>x>>y;
			adj[x].insert(y);
			st.insert(x);
			st.insert(y);
    }

		int idx=0;
		for (auto x : st) s2i[x]=idx, i2s[idx++]=x;
		for (auto it : adj)
			for (auto y : it.second)
				AdjList[s2i[it.first]].push_back({s2i[y],1});
	  dfs_num.assign(n, DFS_WHITE); dfs_low.assign(n, 0); visited.assign(n, 0);
		dfsNumberCounter = numSCC = 0;
		for (int i = 0; i < n; i++)
			if (dfs_num[i] == DFS_WHITE)
				tarjanSCC(i);
		cout << "Calling circles for data set " << ++c << ":" << endl;
		for (auto v : ret) {
			int sz=v.size();
			sort(v.begin(),v.end());
			for (int i=0; i<sz; i++) {
				if(i) cout << ", ";
				cout << i2s[v[i]];
			}
			cout << endl;
		}
	}
  return 0;
}
