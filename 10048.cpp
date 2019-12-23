#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=107, inf=1e9+7;
int conn[mx][mx];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int c,s,q,iter=0,c1,c2,d;
	while(cin>>c>>s>>q) {
		if(!c&&!s&&!q) return 0;
		if(iter) cout << endl;
		for (int i=0; i<mx; i++) for (int j=0; j<mx; j++) conn[i][j]=inf;
		for (int i=0; i<s; i++)
			cin>>c1>>c2>>d,c1--,c2--,conn[c1][c2]=conn[c2][c1]=d;
		for (int k=0; k<c; k++)
			for (int i=0; i<c; i++)
				for (int j=0; j<c; j++)
					conn[i][j]=min(conn[i][j],max(conn[i][k],conn[k][j]));
		cout << "Case #" << ++iter << endl;
		for (int t=0; t<q; t++) {
			cin>>c1>>c2; c1--; c2--;
			int cur=conn[c1][c2];
			if(cur==inf) cout << "no path";
			else cout << cur;
			cout << endl;
		}
	}
	return 0;
}
