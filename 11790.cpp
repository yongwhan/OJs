#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

string n2s(int x) {
	stringstream ss; ss<<x; return ss.str();
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		int n; cin>>n;
		vector<int> a(n), b(n);
		for (int i=0; i<n; i++)
			cin>>a[i];
		for (int i=0; i<n; i++)
			cin>>b[i];

		vector<int> inc(n,0), dec(n,0);
		inc[0]=b[0]; dec[0]=b[0];
		for (int i=1; i<n; i++) {
			inc[i]=b[i];
			dec[i]=b[i];
			for (int j=0; j<i; j++) {
				if(a[j]<a[i])
					inc[i]=max(inc[i],b[i]+inc[j]);
				if(a[j]>a[i])
					dec[i]=max(dec[i],b[i]+dec[j]);
			}
		}
		int x=0, y=0;
		for (int i=0; i<n; i++)
			x=max(x,inc[i]), y=max(y,dec[i]);
		string u="Increasing ("+n2s(x)+").", v="Decreasing ("+n2s(y)+").";
		cout << "Case " << c << ". ";
		if(x>=y) cout << u << " " << v << endl;
		else cout << v << " " << u << endl;
	}
	return 0;
}
