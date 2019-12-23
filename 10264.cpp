#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n;
	while(cin>>n) {
		int m=1<<n;
		map<int,int> mp, val;
		for (int i=0; i<m; i++)
			cin>>mp[i];
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
				val[i]+=mp[i^(1<<j)];
		int ret=0;
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
				ret=max(ret,val[i]+val[i^(1<<j)]);
		cout << ret << endl;
	}
	return 0;
}
