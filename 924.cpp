#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=2577;
vector<set<int>> adj(mx);

void proc(int init) {
	vector<int> v;
	set<int> vis; vis.insert(init);
	queue<int> q; q.push(init);
	int mx=0, idx=-1;
	int iter=0;
	while(1) {
		if(q.empty()) break;
		++iter;
		int sz=q.size(), t=0;
		for (int i=0; i<sz; i++) {
			int cur=q.front(); q.pop();
			for (auto nxt : adj[cur])
				if(vis.find(nxt)==vis.end())
					vis.insert(nxt), q.push(nxt), t++;
		}
		v.push_back(t);
		if(mx<t) mx=t, idx=iter;
	}
	if(!mx) cout << 0;
	else cout << mx << " " << idx;
	cout << endl;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int E,N,f,T,init; cin>>E;
	for (int i=0; i<E; i++) {
		cin>>N;
		for (int j=0; j<N; j++) cin>>f, adj[i].insert(f);
	}
	cin>>T;
	while(T--) cin>>init, proc(init);
	return 0;
}
