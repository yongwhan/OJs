#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

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

const int MAX_V=1e5+5;
int V;
vector<set<ii>> adj, adj2;

int kruskal(vector<pair<ll,ll> > &selected) {
	int ret=0;
	selected.clear();
	vector<pair<ll,pair<ll,ll> > > edges;
	for (int u=0; u<V; u++) {
		for (auto e : adj[u]) {
			int v=e.first, cost=e.second;
			edges.push_back(make_pair(cost,make_pair(u,v)));
		}
	}
	sort(edges.begin(),edges.end());

	DisjointSet sets(V);
	int num=0;
	for (int i=0; i<edges.size(); i++) {
		int cost=edges[i].first;
		int u=edges[i].second.first, v=edges[i].second.second;
		if(sets.find(u)==sets.find(v)) continue;
		sets.merge(u,v);
		selected.push_back(make_pair(u,v));
		ret+=cost;
		num++;
	}
	if(num!=V-1) return -1;
	return ret;
}

int main() {
	int T; cin>>T;
	for (int c=0; c<T; c++) {
		int E; cin>>V>>E;
		adj.assign(V, set<ii>());
		adj2.assign(V, set<ii>());
		for (int i=0; i<E; i++) {
			int a,b,c; cin>>a>>b>>c; a--; b--;
			adj[a].insert(make_pair(b,c));
			adj[b].insert(make_pair(a,c));
		}
		adj2=adj;
		vector<ii> selected, tmp;
		set<ii> chn;
		ll best=kruskal(selected), best2=-1;
		for (auto e : selected) {
			chn.clear();
			for (auto x : adj2[e.first]) if(x.first!=e.second) chn.insert(x);
			adj[e.first]=chn;
			chn.clear();
			for (auto x : adj2[e.second]) if(x.first!=e.first) chn.insert(x);
			adj[e.second]=chn;
			ll val=kruskal(tmp);
			if(val!=-1) {
				if(best2==-1) best2=val;
				else best2=min(best2,val);
			}
			adj=adj2;
		}
		cout << best << " " << best2 << endl;
	}
	return 0;
}
