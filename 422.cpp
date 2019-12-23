#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int l; cin>>l;
	vector<string> grid(l);
	for (int i=0; i<l; i++)
		cin>>grid[i];
	string cur;
	while(cin>>cur&&cur!="0") {
		int n=cur.size();
		ii p, q;
		bool bad=true;
		for (int i=0; i<l; i++) for (int j=0; j<l; j++) {
			for (int di=-1; di<=1; di++) for (int dj=-1; dj<=1; dj++) if((di||dj)&&!(di==-1&&dj==0)) {
				if(!bad) continue;
				bool ok=true;
				for (int k=0; k<n; k++) {
					int ii=i+di*k, jj=j+dj*k;
					if(ii<0||ii>=l||jj<0||jj>=l) { ok=false; break; }
					if(cur[k]!=grid[ii][jj]) { ok=false; break; }
				}
				if(ok) {
					cout << i+1 << "," << j+1 << " " << i+1+di*(n-1) << "," << j+1+dj*(n-1) << endl;
					bad=false;
				}
			}
		}
		if(bad) cout << "Not found" << endl;
	}
	return 0;
}
