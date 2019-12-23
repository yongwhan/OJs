#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mx=22;
map<char,int> c2i;
bool lesser[mx][mx];
vector<string> ret;
vector<int> dp(1<<mx);
int n;
string lst;

int s2n(string s) {
	stringstream ss(s); int ret; ss>>ret; return ret;
}

int eval(int mask) {
	int all=(1<<n)-1, todo=all&(~mask);
	if(mask==all) return 1;
	if(dp[mask]!=-1) return dp[mask];
	int ans=0;
	for (int i=0; i<n; i++) if(todo&(1<<i)) {
		bool can=true;
		for (int j=0; j<n; j++) if(mask&(1<<j)&&lesser[i][j]) {
			can=false; break;
		}
		if(can) ans+=eval(mask|(1<<i));
	}
	return dp[mask]=ans;
}

void eval2(int mask, string *cur) {
	int all=(1<<n)-1, todo=all&(~mask);
	if(mask==all) {
		ret.push_back(*cur);
		return;
	}
	if(!dp[mask]) return;
	for (int i=0; i<n; i++) if(todo&(1<<i)) {
		bool can=true;
		for (int j=0; j<n; j++) if(mask&(1<<j)&&lesser[i][j]) {
			can=false; break;
		}
		if(can)
			cur->push_back(lst[i]),
			eval2(mask|(1<<i),cur),
			cur->pop_back();
	}
		
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string line;
	getline(cin,line);
	int t=s2n(line);
	for (int c=0; c<t; c++) {
		if(c) cout << endl;
		for (int i=0; i<mx; i++) for (int j=0; j<mx; j++) lesser[i][j]=false;
		getline(cin,line);
		getline(cin,line);
		stringstream ss(line);
		char ch;
		n=0;
		lst.clear();
		while(ss>>ch) c2i[ch]=n++, lst+=ch;
		getline(cin,line);
		stringstream tt(line);
		string cur;
		while(tt>>cur) lesser[c2i[cur[0]]][c2i[cur[2]]]=true;
		cur.clear();
		ret.clear();
		for (int i=0; i<(1<<mx); i++) dp[i]=-1;
		int ct=eval(0);
		if(!ct) cout << "NO" << endl;
		else {
			eval2(0,&cur);
			sort(ret.begin(),ret.end());
			for (auto x : ret) {
				int l=x.size();
				for (int i=0; i<l; i++) {
					if(i) cout << " ";
					cout << x[i];
				}
				cout << endl;
			}
		}
	}
	return 0;
}
