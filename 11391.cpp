#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int save[1<<16][4][4];
int dp[1<<16], idx[4][4], r, c;
int eval(int bt) {
	if(dp[bt]!=-1)
		return dp[bt];
	int ret=0;
	for (int i=0; i<r; i++)
	for (int j=0; j<c; j++)
	if(bt&(1<<idx[i][j])) {
		for (int x=-1; x<=1; x++)
		for (int y=-1; y<=1; y++)
		if(abs(x)+abs(y)) {
			int ii=i+x, jj=j+y;
			int iii=ii+x, jjj=jj+y;
			if(0<=ii&&ii<r && 0<=jj&&jj<c && 0<=iii&&iii<r && 0<=jjj&&jjj<c)
			if((bt&(1<<idx[ii][jj]))==0 && (bt&(1<<idx[iii][jjj]))==0) {
				int bt2=bt;
				bt2&=~(1<<idx[i][j]);
				bt2|=1<<idx[ii][jj];
				bt2|=1<<idx[iii][jjj];
				dp[bt2]=eval(bt2);
				ret+=dp[bt2];
			}
		}
	}
	return dp[bt]=ret;
}

int rotate(int bt) {
	int x[4][4], y[4][4];
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			x[i][j]=((bt&(1<<idx[i][j]))!=0);
	for (int i=0; i<c; i++)
		for (int j=0; j<r; j++)
			y[c-1-i][j]=x[j][i];
	int ret=0, iter=0;
	for (int i=0; i<c; i++)
		for (int j=0; j<r; j++) {
			if(y[i][j])
					ret|=1<<iter;
			iter++;
		}
	return ret;
}

void fill() {
	int iter=0;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			idx[i][j]=iter++;
}

int main() {
	int t; scanf("%d", &t);
	for (int i=0; i<(1<<16); i++)
		for (int j=0; j<4; j++)
			for (int k=0; k<4; k++)
				save[i][j][k]=-1;
	for (int iter=0; iter<t; iter++) {
		memset(dp, -1, sizeof(dp));
		int n,init=0,tmp=0; scanf("%d %d %d", &r, &c, &n);
		fill();
		for (int i=0; i<n; i++) {
			int x,y; scanf("%d %d", &x, &y); x--; y--;
			init|=(1<<idx[x][y]);
		}
		int ans=0;
		if(save[init][r][c]!=-1)
			ans=save[init][r][c];
		else {
			dp[init]=1;
			for (int i=0; i<r; i++)
				for (int j=0; j<c; j++)
					ans+=eval(1<<idx[i][j]);
			for (int i=0; i<4; i++) {
				save[init][r][c]=ans;
				init=rotate(init);
				swap(r,c);
				fill();
			}
		}
		printf("Case %d: %d\n", iter+1, ans);
	}
	return 0;
}
