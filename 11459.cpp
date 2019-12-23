#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int T; cin>>T;
	for (int t=0; t<T; t++) {
		int a,b,c; cin>>a>>b>>c;
		vector<int> pos(a,1);
		map<int,int> mp;
		for (int i=0; i<b; i++) {
			int x,y; cin>>x>>y;
			mp[x]=y;
		}
		vector<int> move(c,0);
		for (int i=0; i<c; i++)
			cin>>move[i];
		if(!a) continue;
		for (int i=0; i<c; i++) {
			int cur=pos[i%a];
			int nxt=min(100,cur+move[i]);
			if(mp.find(nxt)!=mp.end())
				nxt=mp[nxt];
			pos[i%a]=nxt;
			if(pos[i%a]==100)
				break;
		}
		for (int i=0; i<a; i++)
			cout << "Position of player " << i+1 << " is " << pos[i] << "." << endl;
	}
	return 0;
}
