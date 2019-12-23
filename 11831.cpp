#include<bits/stdc++.h>
using namespace std;

int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m,s,x,y,d;
	string dir="NSLO", instr;
	int idx[]={0,2,3,1};
	map<char,int> mp;
	for (int i=0; i<4; i++) mp[dir[i]]=idx[i];
	while(cin>>n>>m>>s) {
		if(!n&&!m&&!s) return 0;
		char grid[n][m], ch;
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++) {
				cin>>ch;
				grid[i][j]=ch;
				if(mp.find(ch)!=mp.end()) x=i, y=j, d=mp[ch], grid[i][j]='.';
			}
		int ret=0;
		cin>>instr;
		for (auto ch : instr) {
			int u=x, v=y;
			if(ch=='D') d=(d+3)%4;
			else if(ch=='E') d=(d+1)%4;
			else {
				u+=dx[d], v+=dy[d];
				if(0<=u&&u<n&&0<=v&&v<m) {
					char cur=grid[u][v];
					if(cur!='#') {
						x=u, y=v;
						if(cur=='*') grid[u][v]='.', ret++;
					}
				}
			}
		}
		cout << ret << endl;
	}
}
