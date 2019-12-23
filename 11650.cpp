#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

string fmt(int n, int l) {
	stringstream ss; ss<<n;
	string ret=ss.str();
	while(ret.size()<l) ret='0'+ret;
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) {
		string s; cin>>s;
		s[2]=' ';
		stringstream ss(s);
		int h,m; ss>>h>>m;
		int cur=60*24-h*60-m;
		int hh=(cur/60)%12, mm=cur%60;
		if(!hh) hh=12;
		cout << fmt(hh,2) << ":" << fmt(mm,2) << endl;
	}
	return 0;
}
