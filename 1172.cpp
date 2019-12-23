#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=1050;
unordered_map<string,string> city_to_type;
unordered_map<string,int> city_to_value, city_to_index;
int total[mx][mx], req[mx][mx];

int di[]={-1,-1,0}, dj[]={-1,0,-1}, mul[]={1,0,0};

string n2s(int x) {
	stringstream ss; ss<<x; return ss.str();
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		city_to_type.clear();
		city_to_value.clear();
		city_to_index.clear();

		int n,m; cin>>n;
		vector<string> v(mx);
		string s;

		vector<int> p(mx*2);
		for (int i=0; i<mx*2; i++)
			p[i]=i;

		random_shuffle(p.begin(),p.end());

		for (int i=0; i<n; i++) {
			cin>>s;
			s+=n2s(p[i]);
			cin>>city_to_type[s]>>city_to_value[s];
			city_to_index[s]=i;
			v[i]=s;
		}
		cin>>m;
		vector<string> w(mx);
		for (int i=0; i<m; i++) {
			cin>>s;
			s+=n2s(p[n+i]);
			cin>>city_to_type[s]>>city_to_value[s];
			city_to_index[s]=i;
			w[i]=s;
		}
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				total[i][j]=req[i][j]=0;
		if(city_to_type[v[0]]==city_to_type[w[0]]) {
			total[0][0]=city_to_value[v[0]]+city_to_value[w[0]];
			req[0][0]=1;
		}
		for (int i=1; i<n; i++) {
			total[i][0]=total[i-1][0];
			req[i][0]=req[i-1][0];
			int cur=city_to_value[v[i]]+city_to_value[w[0]];
			if(city_to_type[v[i]]==city_to_type[w[0]] && total[i-1][0]<cur)
				total[i][0]=cur, req[i][0]=1;
		}
		for (int i=1; i<m; i++) {
			total[0][i]=total[0][i-1];
			req[0][i]=req[0][i-1];
			int cur=city_to_value[v[0]]+city_to_value[w[i]];
			if(city_to_type[v[0]]==city_to_type[w[i]] && total[0][i-1]<cur)
				total[0][i]=cur, req[0][i]=1;
		}
		for (int i=1; i<n; i++)
			for (int j=1; j<m; j++) {
				int add=(city_to_type[v[i]]==city_to_type[w[j]]) ? 1 : 0;
				int cur=add * (city_to_value[v[i]]+city_to_value[w[j]]);
				vector<ii> v;
				for (int k=0; k<3; k++) {
					int ii=i+di[k], jj=j+dj[k];
					v.push_back({total[ii][jj]+mul[k]*cur,req[ii][jj]+mul[k]*add});
				}
				sort(v.begin(), v.end(), greater<ii>());
				total[i][j]=v[0].first, req[i][j]=v[0].second;
				for (int k=0; k<3; k++)
					if(v[0].first==v[k].first)
						req[i][j]=min(req[i][j],v[k].second);
			}
		if(n>=1&&m>=1) cout << total[n-1][m-1] << " " << req[n-1][m-1] << endl;
		else cout << 0 << " " << 0 << endl;
	}
	return 0;
}
