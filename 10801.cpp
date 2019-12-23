#include<bits/stdc++.h>
using namespace std;

struct dat {
	int index, from, to, cost;
	dat(int i_, int f_, int t_, int c_) {
		index=i_; from=f_; to=t_; cost=c_;
	}
	bool operator>(const dat &d) const {
		return cost>d.cost;
	}
};

const int mx=177, mx2=7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,k;
	while(cin>>n>>k) {
		vector<vector<dat>> lst(mx);
		vector<int> t(mx2);
		for (int i=1; i<=n; i++) cin>>t[i];
		cin.ignore();
		for (int i=1; i<=n; i++) {
			string s;
			vector<int> v;
			int cur;
			getline(cin,s);
			stringstream ss(s);
			while(ss>>cur) v.push_back(cur);
			int sz=v.size();
			for (int j=0; j<sz; j++) for (int k=j+1; k<sz; k++)
				lst[v[j]].push_back(dat(i,v[j],v[k],0)),
				lst[v[k]].push_back(dat(i,v[k],v[j],0));
		}
		priority_queue<dat,vector<dat>,greater<dat>> pq;
		vector<int> dist(mx,-1), index(mx,-1);
		pq.push(dat(0,0,0,0)); dist[0]=0;
		while(!pq.empty()) {
			dat cur=pq.top(); pq.pop();
			if(dist[cur.to]!=cur.cost) continue;
			for (auto e : lst[cur.to]) {
				int val=dist[e.from]+abs(e.to-e.from)*t[e.index];
				if(index[e.from]!=-1&&index[e.from]!=e.index) val+=60;
				if(dist[e.to]==-1||val<dist[e.to]) dist[e.to]=val, e.cost=val, index[e.to]=e.index, pq.push(e);
			}
		}
		if(dist[k]==-1) cout << "IMPOSSIBLE" << endl;
		else cout << dist[k] << endl;
	}
	return 0;
}
