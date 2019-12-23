#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=105;
const ll inf=1LL<<50;
ll grid[mx][mx], aux[mx][mx];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		int n,m,k; cin>>n>>m>>k;
		for (int i=0; i<mx; i++)
			for (int j=0; j<mx; j++)
				grid[i][j]=aux[i][j]=0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				cin>>grid[i][j];
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				aux[i][j]=grid[i][j]+aux[i-1][j]+aux[i][j-1]-aux[i-1][j-1];
		ll s=0, p=0;
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
			for (int a=i; a<=n; a++) for (int b=j; b<=m; b++) {
				ll area=(a-i+1)*(b-j+1), price=aux[a][b]-aux[a][j-1]-aux[i-1][b]+aux[i-1][j-1];
				if(price<=k) {
					if(s<area) s=area, p=price;
					else if(s==area) p=min(p,price);
				}
			}
		cout << "Case #" << c << ": " << s << " " << p << endl;
	}
	return 0;
}
