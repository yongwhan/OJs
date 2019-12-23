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
vector<pair<ll,ll> > adj[MAX_V];

struct dat {
	int i,j;
	ll w;
	dat(int i_, int j_, ll w_) {
		i=i_; j=j_; w=w_;
	}
	bool operator < (const dat &d) const {
		return w<d.w;
	}
};

void kruskal(vector<dat> &edges, ll r) {
	int ret=V;
	double rail=0, roads=0;
	DisjointSet sets(V);
	for (int i=0; i<edges.size(); i++) {
		int cost=edges[i].w, u=edges[i].i, v=edges[i].j;
		if(sets.find(u)==sets.find(v)) continue;
		sets.merge(u,v);
		if(cost<=r*r) ret--, roads+=sqrt(cost);
		else rail+=sqrt(cost);
	}
	cout << setprecision(0) << fixed << ret << " " << roads << " " << rail << endl;
}

ll sq(ll x) {
	return x*x;
}

int main() {
	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		int r; cin>>V>>r;
		vector<ii> d(V);
		vector<dat> e;
		for (int i=0; i<V; i++) cin>>d[i].first>>d[i].second;
		for (int i=0; i<V; i++) for (int j=i+1; j<V; j++)
			e.push_back({i,j,sq(d[i].first-d[j].first)+sq(d[i].second-d[j].second)});
		sort(e.begin(),e.end());
		cout << "Case #" << c << ": ";
		kruskal(e,r);
	}
	return 0;
}
