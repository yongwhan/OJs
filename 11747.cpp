#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n,1) {
		for (int i=0; i<n; i++)
			parent[i]=i;
	}

	int find(int u) {
		if(u==parent[u]) return u;
		return parent[u]=find(parent[u]);
	}

	void merge(int u, int v) {
		u=find(u); v=find(v);
		if(u==v) return;
		if(rank[u]>rank[v]) swap(u,v);
		parent[u]=v;
		if(rank[u]==rank[v]) rank[v]++;
	}
};

const int MAX_V=1e3+77;
int V;
vector<pair<ll,ll> > adj[MAX_V];

int kruskal(vector<pair<ll,ll> > &selected) {
	int ret=0;
	selected.clear();
	vector<pair<ll,pair<ll,ll> > > edges;
	for (int u=0; u<V; u++) {
		for (int i=0; i<adj[u].size(); i++) {
			int v=adj[u][i].first, cost=adj[u][i].second;
			edges.push_back(make_pair(cost,make_pair(u,v)));
		}
	}
	sort(edges.begin(),edges.end());

	DisjointSet sets(V);
	for (int i=0; i<edges.size(); i++) {
		int cost=edges[i].first;
		int u=edges[i].second.first, v=edges[i].second.second;
		if(sets.find(u)==sets.find(v)) continue;
		sets.merge(u,v);
		selected.push_back(make_pair(u,v));
		ret+=cost;
	}
	return ret;
}

typedef pair<int,int> ii;

int main() {
	int E;
	while(cin>>V>>E) {
		if(!V&&!E) return 0;
		for (int i=0; i<MAX_V; i++) adj[i].clear();
		for (int i=0; i<E; i++) {
			int a,b,c; cin>>a>>b>>c;
			adj[a].push_back(make_pair(b,c));
			adj[b].push_back(make_pair(a,c));
		}

		vector<pair<ll,ll> > selected;
		kruskal(selected);
		set<ii> st(selected.begin(), selected.end());
		set<int> ret;
		for (int i=0; i<V; i++)
			for (auto e : adj[i])
				if(st.find({i,e.first})==st.end()&&st.find({e.first,i})==st.end()) ret.insert(e.second);
		if(ret.empty()) cout << "forest";
		else {
			bool first=true;
			for (auto e : ret) {
				if(!first) cout << " ";
				cout << e;
				first=false;
			}
		}
		cout << endl;
	}
}
