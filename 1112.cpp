#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX_V=1e5+5, INF=1e15;
typedef pair<ll,ll> ii;
int V;

vector<ii> adj[MAX_V];

map<ll,ll> pa;

vector<ll> dijkstra(ll src) {
	vector<ll> dist(V, INF);
	dist[src]=0;
	priority_queue<ii> pq;
	pq.push(make_pair(0,src));
	while(!pq.empty()) {
		ll cost=-pq.top().first, here=pq.top().second;
		pq.pop();
		if(dist[here]<cost) continue;
		for (int i=0; i<adj[here].size(); i++) {
			ll there=adj[here][i].first, nextDist=cost+adj[here][i].second;
			if(dist[there]>nextDist) {
				dist[there]=nextDist;
				pq.push(make_pair(-nextDist, there));
				pa[there]=here;
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		if(c) cout << endl;
		int N,E,T,M; cin>>N>>E>>T>>M; E--;
		for (int i=0; i<N; i++) adj[i].clear();
		for (int i=0; i<M; i++) {
			ll a,b,w; cin>>a>>b>>w; a--; b--;
			adj[b].push_back(make_pair(a,w));
		}
		V=N;
		vector<ll> dist=dijkstra(E);
		int ret=0;
		for (auto e : dist) if(e<=T) ret++;
		cout << ret << endl;
	}
	return 0;
}
