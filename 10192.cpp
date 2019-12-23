#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int eval(string &s, string &t) {
	int n=s.size(), m=t.size();
	vector<vector<int>> lcs(n+1, vector<int>(m+1,0));
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
		lcs[i+1][j+1]=max(lcs[i+1][j], lcs[i][j+1]);
		if(s[i]==t[j]) lcs[i+1][j+1]=max(lcs[i+1][j+1], lcs[i][j]+1);
	}
	return lcs[n][m];
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s,t;
	int c=0;
	while(getline(cin,s)) {
		if(s[0]=='#') break;
		getline(cin,t);
		cout << "Case #" << ++c << ": you can visit at most " << eval(s,t) << " cities." << endl;
	}
	return 0;
}
