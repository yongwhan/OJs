#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
const int mx=150;

string proc(string &s) {
	string ret;
	for (auto ch : s)
		if(isalpha(ch)&&ch==toupper(ch))
			ret+=ch;
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string line;
	getline(cin,line);
	stringstream ss(line); int t; ss>>t;
	vector<ll> fibo(mx,0);
	fibo[0]=1;
	fibo[1]=2;
	for (int i=2; i<mx; i++)
		fibo[i]=fibo[i-1]+fibo[i-2];
	map<ll,int> mp;
	for (int i=0; i<mx; i++)
		mp[fibo[i]]=i;
	while(t--) {
		getline(cin,line);
		stringstream ss(line); int n; ss>>n;
		getline(cin,line);
		stringstream tt(line);
		int x;
		vector<int> p;
		while(tt>>x) p.push_back(x);
		getline(cin,line);
		line=proc(line);
		string ret=string(mx, ' ');
		int len=0;
		for (int i=0; i<n; i++) {
			int cur=mp[p[i]];
			ret[cur]=line[i];
			len=max(len,cur+1);
		}
		cout << ret.substr(0,len) << endl;
	}
	return 0;
}
