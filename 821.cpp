#include<bits/stdc++.h>
using namespace std;

const int mx=107, inf=1e9;
int cost[mx][mx];
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int a,b;
	vector<ii> cur;
	set<int> st;
	int iter=0;
	while(cin>>a>>b) {
		if(!a&&!b) {
			if(cur.empty()) return 0;
			int n=st.size();
			vector<int> v(st.begin(),st.end());
			map<int,int> idx;
			for (int i=0; i<n; i++) idx[v[i]]=i;
			for (int i=0; i<n; i++) for (int j=0; j<n; j++) cost[i][j]=inf;
			for (auto x : cur) cost[idx[x.first]][idx[x.second]]=1;
			for (int k=0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
			double ret=0, ct=0;
			for (int i=0; i<n; i++) for (int j=0; j<n; j++)
				if(i!=j) ret+=cost[i][j], ct++;
			cout << "Case " << ++iter << ": average length between pages = " << setprecision(3) << fixed << ret/ct << " clicks" << endl;
			cur.clear(); st.clear(); n=0;
		} else cur.push_back({a-1,b-1}), st.insert(a-1), st.insert(b-1);
	}
}
