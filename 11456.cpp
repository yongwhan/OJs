#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<int> a(n);
		for (int i=0; i<n; i++) cin>>a[i];
		if(n<=2) {
			cout << n << endl;
			continue;
		}
		vector<int> inc(n,1), dec(n,1);
		for (int i=n-2; i>=0; i--) {
			int mx=0, mx2=0;
			for (int j=i+1; j<n; j++) {
				if(a[i]<a[j]) mx=max(mx,inc[j]);
				if(a[i]>a[j]) mx2=max(mx2,dec[j]);
			}
			inc[i]=mx+1;
			dec[i]=mx2+1;
		}
		int ret=0;
		for (int i=0; i<n; i++)
			ret=max(ret,inc[i]+dec[i]-1);
		cout << ret << endl;
	}
	return 0;
}
