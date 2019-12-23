#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=205;
const ll inf=1LL<<50;
ll grid[mx][mx], aux[mx][mx];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		int n; cin>>n;
		for (int i=0; i<mx; i++)
			for (int j=0; j<mx; j++)
				grid[i][j]=aux[i][j]=0;

		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++) {
				cin>>grid[i+1][j+1];
				for (int ii=0; ii<2; ii++)
					for (int jj=0; jj<2; jj++)
						grid[i+ii*n+1][j+jj*n+1]=grid[i+1][j+1];
			}

		for (int i=1; i<=2*n; i++)
			for (int j=1; j<=2*n; j++)
				aux[i][j]=grid[i][j]+aux[i-1][j]+aux[i][j-1]-aux[i-1][j-1];

		ll ret=-inf;
		for (int l=1; l<=n; l++) for (int w=1; w<=n; w++)
			for (int i=1; i<=2*n-l+1; i++) for (int j=1; j<=2*n-w+1; j++) {
				int a=i+l-1, b=j+w-1;
				ret=max(ret, aux[a][b]-aux[a][j-1]-aux[i-1][b]+aux[i-1][j-1]);
			}
		cout << ret << endl;
	}
	return 0;
}
