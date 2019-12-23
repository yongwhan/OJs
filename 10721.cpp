#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=55;
ll BC[mx][mx][mx];

ll eval(int n, int k, int m) {
	if(BC[n][k][m]!=-1)
		return BC[n][k][m];
	if(n==0&&k==0)
		return BC[n][k][m]=1;
	else if(n==0||k==0)
		return BC[n][k][m]=0;
	ll ret=0;
	for (int i=1; i<=min(m,n); i++)
		ret+=eval(n-i,k-1,m);
	return BC[n][k][m]=ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	for (int i=0; i<mx; i++)
		for (int j=0; j<mx; j++)
			for (int k=0; k<mx; k++)
				BC[i][j][k]=-1;
	int n,k,m;
	while(cin>>n>>k>>m)
		cout<<eval(n,k,m)<<endl;
	return 0;
}
