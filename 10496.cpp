#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) {
		int xmax, ymax; cin>>xmax>>ymax;
		int x0, y0; cin>>x0>>y0;
		int n; cin>>n;
		vector<int> x(n), y(n), p(n);
		for (int i=0; i<n; i++) cin>>x[i]>>y[i], p[i]=i;
		int ret=1e9;
		do {
			int cur=abs(x[p[0]]-x0)+abs(y[p[0]]-y0) + abs(x[p[n-1]]-x0)+abs(y[p[n-1]]-y0);
			for (int i=1; i<n; i++) cur+=abs(x[p[i]]-x[p[i-1]])+abs(y[p[i]]-y[p[i-1]]);
			ret=min(ret,cur);
		} while(next_permutation(p.begin(), p.end()));
		cout << "The shortest path has length " << ret << endl;
	}
	return 0;
}
