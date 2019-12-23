#include<bits/stdc++.h>
using namespace std;

const int mx=77;
int c[mx], dp[mx][mx];

int eval(int left, int right) {
	if(dp[left][right]!=-1)
		return dp[left][right];
	int ret=INT_MAX;
	for(int i=left+1; i<right; i++)
		ret=min(ret,eval(left,i)+eval(i,right)+c[right]-c[left]);
	return dp[left][right]=ret;
}

int main() {
	int l;
	while(cin>>l && l) {
		int n; cin>>n;
		for(int i=1; i<=n; i++)
			cin>>c[i];
		c[0]=0; c[n+1]=l;
		for (int i=0; i<mx; i++)
			for (int j=0; j<mx; j++)
				dp[i][j]=-1;
		for (int i=0; i<mx-1; i++)
			dp[i][i+1]=0;
		cout<<"The minimum cutting is "<<eval(0,n+1)<<".\n";
	}
}
