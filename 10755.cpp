#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=25;
const ll inf=1LL<<50;
ll grid[mx][mx][mx], aux[mx][mx][mx];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int u=0; u<t; u++) {
		if(u) cout << endl;
		int a,b,c; cin>>a>>b>>c;
		for (int i=1; i<=a; i++)
			for (int j=1; j<=b; j++)
				for (int k=1; k<=c; k++)
					cin>>grid[i][j][k], aux[i-1][j-1][k-1]=0, aux[i][j][k]=0;
		for (int i=1; i<=a; i++)
			for (int j=1; j<=b; j++)
				for (int k=1; k<=c; k++)
					aux[i][j][k]=aux[i-1][j][k]+aux[i][j-1][k]+aux[i][j][k-1]-aux[i-1][j-1][k]-aux[i-1][j][k-1]-aux[i][j-1][k-1]+aux[i-1][j-1][k-1]+grid[i][j][k];
		ll ret=-inf;
		for (int p=1; p<=a; p++) for (int q=1; q<=b; q++) for (int r=1; r<=c; r++)
			for (int i=p; i<=a; i++) for (int j=q; j<=b; j++) for (int k=r; k<=c; k++)
				ret=max(ret, aux[i][j][k]-aux[p-1][j][k]-aux[i][q-1][k]-aux[i][j][r-1]+aux[p-1][q-1][k]+aux[p-1][j][r-1]+aux[i][q-1][r-1]-aux[p-1][q-1][r-1]);
		cout << ret << endl;
	}
	return 0;
}
