#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

string fmt(int n, int l) {
	stringstream ss; ss<<n;
	string s=ss.str();
	while(s.size()<l) s='0'+s;
	return s;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string lst="A23456789TJQK";
	map<char,int> mp;
	for (int i=0; i<lst.size(); i++) mp[lst[i]]=i;

	while(1) {
		vector<stack<string> > v(13);
		string cur;
		stack<string> stk;
		for (int i=0; i<52; i++) {
			cin>>cur;
			if(cur=="#") return 0;
			stk.push(cur);
		}

		int iter=0;
		while(!stk.empty()) {
			cur=stk.top(); stk.pop();
			v[(iter++)%13].push(cur);
		}

		int ct=0,idx=12; string ret;
		while(1) {
			if(v[idx].empty()) break;
			ct++;
			string cur=v[idx].top();
			ret=cur;
			v[idx].pop();
			idx=mp[cur[0]];
		}
		cout << fmt(ct,2) << "," << ret << endl;
	}
	return 0;
}
