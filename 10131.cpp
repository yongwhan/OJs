#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	vector<tp> a;
	int w,s,i=0;
	while(cin>>w>>s)
		a.push_back(make_tuple(w,s,++i));
	sort(a.begin(),a.end());
	int n=a.size();
	map<int,int> par, len;
	len[0]=1;
	par[0]=-1;
	for (int i=1; i<n; i++) {
		len[i]=1;
		for (int j=0; j<i; j++) {
			if(get<0>(a[j])>=get<0>(a[i])) continue;
			if(get<1>(a[j])<=get<1>(a[i])) continue;
			int cur=len[j]+1;
			if(len[i]<cur) len[i]=cur, par[i]=j;
		}
	}
	int mx=0;
	for (int i=0; i<n; i++)
		mx=max(mx,len[i]);
	int cur=-1;
	for (int i=n-1; i>=0; i--)
		if(len[i]==mx) {
			cur=i; break;
		}
	vector<int> ret;
	while(par[cur]!=-1)
		ret.push_back(cur), cur=par[cur];
	cout<<mx<<"\n";
	reverse(ret.begin(),ret.end());
	for (int i=0; i<mx; i++)
		cout<<get<2>(a[ret[i]])<<"\n";
	return 0;
}
