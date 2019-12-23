#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=26;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n, m;
	while(cin>>n>>m) {
		string init; cin>>init;
		map<char,bool> on;
		for (auto ch : init)
			on[ch]=true;
		set<char> lst;
		vector<vector<bool>> conn(mx, vector<bool>(mx,false));
		for (int i=0; i<m; i++) {
			string cur; cin>>cur;
			int x=cur[0]-'A', y=cur[1]-'A';
			conn[x][y]=conn[y][x]=true;
			lst.insert(cur[0]);
			lst.insert(cur[1]);
		}

		for (char ch : lst)
			if(on.find(ch)==on.end())
				on[ch]=false;

		int ret=-1;
		for (int i=0; i<30; i++) {
			int tot=0;
			for (char ch='A'; ch<='Z'; ch++)
				tot+=on[ch];
			if(tot>=n) {
				ret=i; break;
			}
			map<char,bool> on_nxt;
			for (auto it : lst) {
				on_nxt[it]=on[it];
				int deg=0;
				for (auto nbr : lst)
					if(conn[it-'A'][nbr-'A'])
						if(on[nbr])
							deg++;
				on_nxt[it]|=(deg>=3);
			}
			on=on_nxt;
		}

		if(ret!=-1) cout << "WAKE UP IN, " << ret << ", YEARS" << endl;
		else cout << "THIS BRAIN NEVER WAKES UP" << endl;
	}
	return 0;
}
