#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int dx[]={1, -1, 0, 0}, dy[]={0, 0, 1, -1};

int getnext(int x) {
	vector<string> grid(3);
	int k=9;
	for (int i=0; i<3; i++) {
		string cur;
		for (int j=0; j<3; j++)
			if(1<<(--k)&x) cur+='1';
			else cur+='0';
		grid[i]=cur;
	}

	vector<string> next=grid;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			int cur=0;
			for (k=0; k<4; k++) {
				int ii=i+dx[k], jj=j+dy[k];
				if(0<=ii&ii<3&&0<=jj&&jj<3) {
					cur=(cur+(grid[ii][jj]-'0'))%2;
				}
			}
			next[i][j]='0'+cur;
		}
	}

	int ret=0;
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			ret<<=1,
			ret+=next[i][j]-'0';
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		map<int,int> mp;
		char ch;
		int cur=0, idx=0;
		for (int i=0; i<9; i++) {
			cin>>ch;
			cur<<=1;
			cur+=ch-'0';
		}
		mp[cur]=idx++;
		int ret=-(1<<10);
		while(1) {
			cur=getnext(cur);
			if(mp.find(cur)!=mp.end()) { ret=mp[cur]-1; break; }
			else mp[cur]=idx++;
		}
		cout << ret << endl;
	}
	return 0;
}
