#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		vector<string> grid(10);
		for (int i=0; i<10; i++) cin>>grid[i];
		int m=grid[0].size();
		for (int i=1; i<m-1; i++) {
			int cur=0;
			for (int j=8; j>=1; j--)
				cur=cur*2+int(grid[j][i]!='/');
			cout << char(cur);
		}
		cout << endl;
	}
	return 0;
}
