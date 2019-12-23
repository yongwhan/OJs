#include<bits/stdc++.h>
using namespace std;

string eval(int x) {
	if(!x) return "*";
	stringstream ss; ss<<x;
	return ss.str();
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,q;
	while(cin>>n>>q&&(n||q)) {
		map<int,int> left, right;
		for (int i=1; i<=n-1; i++) right[i]=i+1;
		for (int i=n; i>=2; i--) left[i]=i-1;
		for (int i=0; i<q; i++) {
			int l,r; cin>>l>>r;
			right[left[l]]=right[r];
			left[right[r]]=left[l];
			cout << eval(left[right[r]]) << " " << eval(right[left[l]]) << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}
