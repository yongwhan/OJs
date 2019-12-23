#include<bits/stdc++.h>
using namespace std;

string fmt(int x) {
	if(!x) return "Blank";
	stringstream ss; ss<<x;
	return ss.str();
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n;
	while(cin>>n, n) {
		int num=(n+3)/4; num<<=1;
		vector<vector<int>> grid(num, vector<int>(2, 0));
		int toggle=1;
		for (int i=0; i<min(n,num); i++) grid[i][toggle]=i+1, toggle=1-toggle;
		for (int i=0; i<n-num; i++) grid[num-1-i][toggle]=i+1+num, toggle=1-toggle;
		cout << "Printing order for " << n << " pages:" << endl;
		for (int i=0; i<num/2; i++) {
			for (int j=0; j<2; j++) {
				int x=grid[2*i+j][0], y=grid[2*i+j][1];
				if(x||y) {
					if(j) cout << "Sheet " << i+1 << ", back : ";
					else cout << "Sheet " << i+1 << ", front: ";
					cout << fmt(x) << ", " << fmt(y) << endl;
				}
			}
		}
	}
	return 0;
}
