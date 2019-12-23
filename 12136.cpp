#include<cstdio>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int s2n(string s) {
	s[2]=' ';
	stringstream ss(s);
	int h,m; ss>>h>>m;
	return h*60+m;
}

string eval(string a, string b, string c, string d) {
	vector<ii> cur={make_pair(s2n(a), s2n(b)), make_pair(s2n(c), s2n(d))};
	sort(cur.begin(), cur.end());
	if(cur[0].second>=cur[1].first) return "Mrs Meeting";
	else return "Hits Meeting";
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		string p,q,r,s; cin>>p>>q>>r>>s;
		cout << "Case " << c << ": " << eval(p,q,r,s) << endl;
	}
	return 0;
}
