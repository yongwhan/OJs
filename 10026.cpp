#include<bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> tp;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	while(t-->0) {
		int n; cin>>n;
		vector<tp> a(n);
		for (int i=0; i<n; i++) {
			int t,s; cin>>t>>s;
			a[i]=make_tuple(s,t,i+1);
		}
		sort(a.begin(),a.end(),[&](const tp &x, const tp &y) {
			int p=get<0>(x)*get<1>(y), q=get<1>(x)*get<0>(y);
			if(p==q) return get<2>(x)<get<2>(y);
			return p>q;
		});
		for (int i=0; i<n; i++) {
			if(i) cout<<" ";
			cout<<(get<2>(a[i]));
		}
		cout<<"\n";
		if(t) cout<<"\n";
	}
	return 0;
}
