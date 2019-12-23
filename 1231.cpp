#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=2005;
int acorn[mx][mx], dp[mx];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int c; cin>>c;
	for (int iter=0; iter<c; iter++) {
		for (int i=0; i<mx; i++) {
			for (int j=0; j<mx; j++)
				acorn[i][j]=0;
			dp[i]=0;
		}

		int t,h,f; cin>>t>>h>>f;
		for (int i=0; i<t; i++) {
			int a; cin>>a;
			for (int j=0; j<a; j++) {
				int x; cin>>x;
				acorn[i][x]++;
			}
		}

		for (int i=0; i<t; i++)
			dp[h]=max(dp[h],acorn[i][h]);
		for (int j=h-1; j>=0; j--)
			for (int i=0; i<t; i++)
				acorn[i][j]+=max(acorn[i][j+1], ((j+f<=h) ? dp[j+f] : 0)),
				dp[j]=max(dp[j], acorn[i][j]);
		cout << dp[0] << endl;
	}
	return 0;
}
