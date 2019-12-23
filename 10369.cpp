#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=1e6+5;

vector<int> par(mx), rnk(mx);

void init(int n) {
	for (int i=0; i<n; i++)
		par[i]=i, rnk[i]=0;
}

int find(int x) {
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);
}

void unite(int x, int y) {
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rnk[x]<rnk[y]) par[x]=y;
	else {
		par[y]=x;
		if(rnk[x]==rnk[y]) rnk[x]++;
	}
}

bool same(int x, int y) {
	return find(x)==find(y);
}

struct dat {
	int x,y,d;
	dat(int x_, int y_, int d_) {
		x=x_; y=y_; d=d_;
	}
};

bool cmp(dat a, dat b) {
	return a.d<b.d;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) {
		int S,P; cin>>S>>P;
		vector<int> x(P), y(P);
		vector<dat> data;
		for (int i=0; i<P; i++) {
			cin>>x[i]>>y[i];
			for (int j=i-1; j>=0; j--)
				data.push_back(dat(i,j,pow(x[i]-x[j],2)+pow(y[i]-y[j],2)));
		}
		sort(data.begin(),data.end(),cmp);
		init(P);
		int ct=0, sz=data.size();
		for (int i=0; i<sz; i++) {
			if(!same(data[i].x,data[i].y)) unite(data[i].x,data[i].y), ct++;
			if(ct==P-S) {
				cout << setprecision(2) << fixed << sqrt(data[i].d) << endl;
				break;
			}
		}
	}
	return 0;
}
