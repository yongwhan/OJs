#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=2e4+50, inf=1e9;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		int p,n,x,ret=0,ct=inf; cin>>p>>n;
		vector<int> poss(mx,inf);
		poss[0]=0;
		for (int j=0; j<n; j++) {
			cin>>x;
			for (int i=mx-1; i>=x; i--)
				if(i==x||poss[i-x]!=inf)
					poss[i]=min(poss[i], poss[i-x]+1);
		}
		for (int i=p; i<mx; i++) {
			x=poss[i];
			if(x!=inf) {
				ret=i; ct=x; break;
			}
		}
		cout << ret << " " << ct << endl;
	}
	return 0;
}
