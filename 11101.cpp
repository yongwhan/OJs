#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int mx=1e5+77;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n;
	while(cin>>n) {
		if(!n) return 0;
		vector<ii> a(n);
		for (int i=0; i<n; i++) cin>>a[i].first>>a[i].second;
		int m; cin>>m;
		vector<ii> b(m);
		for (int i=0; i<m; i++) cin>>b[i].first>>b[i].second;
		int ret=1e9+77;
		if(n*m<mx) {
			for (int i=0; i<n; i++) for (int j=0; j<m; j++)
				ret=min(ret,abs(a[i].first-b[j].first)+abs(a[i].second-b[j].second));
		} else {
			for (int k=0; k<mx; k++) {
				int i=rand()%n, j=rand()%m;
				ret=min(ret,abs(a[i].first-b[j].first)+abs(a[i].second-b[j].second));
			}
		}
		cout << ret << endl;
	}
}
