#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int L,U,R, iter=0;
	while(cin>>L>>U>>R) {
		if(!L&&!U&&!R) return 0;
		vector<int> RV(R);
		for (int i=0; i<R; i++) cin>>RV[i];
		map<int,int> dist;
		queue<int> q; q.push(L); dist[L]=0;
		int ret=-1;
		while(!q.empty()) {
			int cur=q.front(); q.pop();
			if(cur==U) { ret=dist[cur]; break; }
			for (auto rv : RV) {
				int nxt=(cur+rv)%10000;
				if(dist.find(nxt)==dist.end()) dist[nxt]=dist[cur]+1, q.push(nxt);
			}
		}
		cout << "Case " << ++iter << ": ";
		if(ret==-1) cout << "Permanently Locked";
		else cout << ret;
		cout << endl;
	}
}
