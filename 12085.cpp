#include<bits/stdc++.h>
using namespace std;

typedef pair<string,string> ss;

int num(string &s) {
	stringstream ss(s);
	int ret; ss>>ret;
	return ret;
}

bool after(string &s, string &t) {
	return num(s)==num(t)+1;
}

string print(string &s, string &t) {
	if(s==t) return s;
	int n=min(s.size(),t.size()), idx=-1;
	string ret=s+"-";
	for (int i=0; i<n; i++) {
		if(s[i]!=t[i]) {
			ret+=t.substr(i);
			break;
		}
	}
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n, c=0;
	while(cin>>n && n) {
		vector<string> v(n+1);
		for (int i=0; i<n; i++) cin>>v[i];
		v[n]="2100000000";
		vector<ss> ret;
		string p=v[0], q=v[0], cur=p;
		for (int i=1; i<=n; i++) {
			string nxt=v[i];
			if(!after(nxt,cur)) {
				ret.push_back({p,q});
				p=nxt;
			}
			cur=nxt;
			q=cur;
		}

		cout << "Case " << ++c << ":" << endl;
		for (auto it : ret)
			cout << print(it.first, it.second) << endl;
		cout << endl;
	}
	return 0;
}
