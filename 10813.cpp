#include<bits/stdc++.h>
using namespace std;

void mark(vector<vector<int>> &grid, int x) {
	for (int i=0; i<5; i++) for (int j=0; j<5; j++)
		if(grid[i][j]==x)
			grid[i][j]=0;
}

bool bingo(vector<vector<int>> &grid) {
	bool ok;
	for (int i=0; i<5; i++) {
		ok=true;
		for (int j=0; j<5; j++)
			ok&=!grid[i][j];
		if(ok) return true;
		ok=true;
		for (int j=0; j<5; j++)
			ok&=!grid[j][i];
		if(ok) return true;
	}

	ok=true;
	for (int i=0; i<5; i++)
		ok&=!grid[i][i];
	if(ok) return true;
	ok=true;
	for (int i=0; i<5; i++)
		ok&=!grid[i][4-i];
	return ok;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		vector<vector<int>> grid(5, vector<int>(5,0));
		for (int i=0; i<5; i++) for (int j=0; j<5; j++) {
			if(i==2&&j==2) continue;
			cin>>grid[i][j];
		}
		int ret=-1,x;
		for (int i=0; i<75; i++) {
			cin>>x;
			mark(grid,x);
			if(bingo(grid))
				if(ret==-1)
					ret=i+1;
		}
		cout << "BINGO after " << ret << " numbers announced" << endl;
	}
	return 0;
}
