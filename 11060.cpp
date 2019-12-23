#include<bits/stdc++.h>
using namespace std;

typedef pair<int,string> is;
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m,c=0;
	while(cin>>n) {
		vector<string> lst(n);
		map<string,int> idx;
		for (int i=0; i<n; i++) cin>>lst[i], idx[lst[i]]=n-i;
		int m; cin>>m;
		map<string,set<string>> adj, adj2;
		map<string,int> indeg;
		for (int i=0; i<m; i++) {
			string x,y; cin>>x>>y;
			adj[x].insert(y);
			adj2[y].insert(x);
		}
		for (auto it : adj2) indeg[it.first]=it.second.size();
		priority_queue<is> pq;
		for (auto x : lst) if(!indeg[x]) pq.push({idx[x],x});
		vector<string> ret;
		while(!pq.empty()) {
			is cur=pq.top(); pq.pop();
			string x=cur.second;
			ret.push_back(x);
			for (auto y : adj[x]) {
				indeg[y]--;
				if(!indeg[y]) pq.push({idx[y],y});
			}
		}
		cout << "Case #" << ++c << ": Dilbert should drink beverages in this order:";
		for (auto x : ret)
			cout << " " << x;
		cout << "." << endl << endl;
	}
	return 0;
}
