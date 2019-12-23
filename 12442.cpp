#include<bits/stdc++.h>
using namespace std;

const int mx=5e4+77;
vector<int> nxt(mx,-1), ct(mx,-1);
vector<bool> vis(mx,false);

int dfs(int cur) {
	vis[cur]=true;
	int ret=0, tmp=nxt[cur];
	if(tmp!=-1&&!vis[tmp]) ret+=dfs(tmp)+1;
	vis[cur]=false;
	return ct[cur]=ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t,n,x,y; cin>>t;
	for (int c=1; c<=t; c++) {
		cin>>n;
		nxt.assign(mx,-1); ct.assign(mx,-1); vis.assign(mx,false);
		for (int i=0; i<n; i++) cin>>x>>y, nxt[x]=y;
		int cur=0, ret=-1;
		for (int i=1; i<=n; i++) {
			if(ct[i]==-1) dfs(i);
			if(cur<ct[i]) cur=ct[i], ret=i;
		}
		cout << "Case " << c << ": " << ret << endl;
	}
	return 0;
}
