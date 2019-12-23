#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct dat {
	int i,j,d,w;
	dat(int i_, int j_, int d_, int w_) {
		i=i_; j=j_; d=d_; w=w_;
	}
};
int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};

const int mx=77;
int g[mx][mx], t[mx][mx], n,m;
bool v[mx][mx][4];

int eval(string &s) {
	char ch=s[0];
	if(ch=='n') return 0;
	else if(ch=='e') return 1;
	else if(ch=='s') return 2;
	else return 3;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	while(cin>>n>>m) {
		if(!n&&!m) return 0;
		for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>g[i][j];
		for (int i=0; i<=n; i++) for (int j=0; j<=m; j++)
			if(!i||!j||i==n||j==m) t[i][j]=0;
			else t[i][j] = !g[i-1][j-1]&&!g[i-1][j]&&!g[i][j-1]&&!g[i][j];
		ii b,e; string s;
		cin>>b.first>>b.second>>e.first>>e.second>>s;
		int dir=eval(s);
		bool ok=false;
		if(t[e.first][e.second]) {
			queue<dat> q;
			for (int i=0; i<mx; i++) for (int j=0; j<mx; j++) for (int k=0; k<4; k++) v[i][j][k]=0;
			q.push(dat(b.first,b.second,dir,0));
			while(!q.empty()) {
				dat cur=q.front(); q.pop();
				int i=cur.i, j=cur.j, d=cur.d, w=cur.w;
				if(i<0||i>n||j<0||j>m||!t[i][j]||v[i][j][d]) continue;
				if(i==e.first&&j==e.second) {
					cout << w << endl;
					ok=true;
					break;
				}
				v[i][j][d]=true;
				q.push(dat(i,j,(d+1)%4,w+1));
				q.push(dat(i,j,(d+3)%4,w+1));
				for (int k=1; k<=3; k++) {
					int x=i+k*dx[d], y=j+k*dy[d];
					if(x<0||x>n||y<0||y>m||!t[x][y]) break;
					q.push(dat(x,y,d,w+1));
				}
			}
		}
		if(!ok) cout << -1 << endl;
	}	
}
