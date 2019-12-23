#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int s2n(string s) {
	stringstream ss(s); int ret; ss>>ret; return ret;
}

int eval(string s, string t, map<string,vector<string>> &adj) {
	map<string,int> dist; dist[s]=0;
	queue<string> q; q.push(s);
	while(!q.empty()) {
		string cur=q.front(); q.pop();
		if(cur==t) return dist[cur];
		for (auto nxt : adj[cur])
			if(dist.find(nxt)==dist.end())
				dist[nxt]=dist[cur]+1, q.push(nxt);
	}
	return -1;
}

int diff(string s, string t) {
	int n=s.size(), m=t.size();
	if(n!=m) return 0;
	int ret=0;
	for (int i=0; i<n; i++) if(s[i]!=t[i]) ret++;
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string line;
	getline(cin,line);
	int N=s2n(line);
	for (int i=0; i<N; i++) {
		if(!i) getline(cin,line);
		vector<string> list;
		while(getline(cin,line)) {
			if(line=="*") break;
			list.push_back(line);
		}
		int n=list.size();
		map<string,vector<string>> adj;
		for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) if(diff(list[i],list[j])==1)
			adj[list[i]].push_back(list[j]), adj[list[j]].push_back(list[i]);

		if(i) cout << endl;
		while(getline(cin,line)) {
			if(line.empty()) break;
			stringstream ss(line);
			string s,t; ss>>s>>t;
			cout << s << " " << t << " " << eval(s,t,adj) << endl;
		}
	}
	return 0;
}
