#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

unordered_map<int,double> memo;

bool on(int bt,int i) {
	return bt&(1<<i);
}

double dist(int i, int j, vector<ii> &v) {
	int dx=v[i].first-v[j].first, dy=v[i].second-v[j].second;
	return sqrt(dx*dx+dy*dy);
}

double eval(int bt, vector<ii> &v) {
	int n=v.size();
	if(!bt) return 0;
	if(memo.find(bt)!=memo.end()) return memo[bt];
	double ret=1e9;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			if(on(bt,i)&&on(bt,j))
				ret=min(ret, dist(i,j,v)+eval(bt&~(1<<i)&~(1<<j), v));
	return memo[bt]=ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int c=0, n;
	while(cin>>n) {
		if(!n) break;
		memo.clear();
		vector<ii> v(2*n);
		string s; int x,y;
		for (int i=0; i<2*n; i++) {
			cin>>s>>x>>y;
			v[i]={x,y};
		}
		cout << "Case " << ++c << ": " << setprecision(2) << fixed << eval((1<<(2*n))-1, v) << endl;
	}
	return 0;
}
