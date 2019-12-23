#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string line;
	while(getline(cin,line)) {
		stringstream ss(line);
		vector<int> a;
		int x;
		while(ss>>x) a.push_back(x);
		int n=a.size();
		vector<ii> b(n);
		for (int i=0; i<n; i++)
			b[i]={a[i],i};
		sort(b.begin(),b.end());
		vector<int> p(n);
		for (int i=0; i<n; i++)
			p[b[i].second]=i;
		vector<int> ret;
		for (int i=n-1; i>=0; i--) {
			int k=-1;
			for (int j=0; j<n; j++) {
				if(p[j]==i) {
					k=j; break;
				}
			}
			if(k==i) continue;
			if(k) {
				ret.push_back(n-k);
				reverse(p.begin(),p.begin()+k+1);
				i++;
				continue;
			}
			ret.push_back(n-i);
			reverse(p.begin(),p.begin()+i+1);
		}
		cout<<line<<"\n";
		for (const int &x : ret)
			cout<<x<<" ";
		cout<<"0\n";
	}
	return 0;
}
