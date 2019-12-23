#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int m,n;
	while(cin>>m>>n) {
		int u=m;
		if(u>1800) u+=200;

		vector<int> mp(u+1,0);
		int p,f, ret=0;
		for (int i=0; i<n; i++) {
			cin>>p>>f;
			for (int j=u; j>=p; j--)
				if(mp[j-p]||j==p)
					mp[j]=max(mp[j], mp[j-p]+f);
		}
		if(m>=1801&&m<=2000) {
			ret=max(ret,*max_element(mp.begin(),mp.begin()+m));
			ret=max(ret,*max_element(mp.begin()+2001,mp.end()));
		} else {
			ret=max(ret,*max_element(mp.begin(),mp.end()));
		}
		cout << ret << endl;
	}
	return 0;
}
