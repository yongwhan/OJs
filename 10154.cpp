#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int mx=7777;

int main() {
	vector<ii> a;
	int w,s;
	while(cin>>w>>s)
		a.push_back({s,w});
	sort(a.begin(),a.end());
	vector<int> dp(mx,INT_MAX);
	dp[0]=0;
	int ret=0;
	int n=a.size();
	for (int i=0; i<n; i++) {
		for (int j=ret; j>=0; j--) {
			int cur=dp[j]+a[i].second;
			if(a[i].first<cur) continue;
			if(cur>=dp[j+1]) continue;
			dp[j+1]=cur;
			ret=max(ret,j+1);
		}
	}
	cout<<ret<<"\n";
	return 0;
}
