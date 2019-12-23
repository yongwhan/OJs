#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

string eval(int n, string &s) {
	map<string,int> mp;
	int mx=0;
	for (int i=0; i<=s.size()-n; i++)
		mx=max(mx, ++mp[s.substr(i,n)]);
	for (auto it : mp)
		if(it.second==mx)
			return it.first;
	return "";
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; string s;
	while(cin>>n>>s)
		cout << eval(n,s) << endl;
	return 0;
}
