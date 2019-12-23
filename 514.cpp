#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

bool ok(vector<int> &a) {
	int cur=0, n=a.size();
	stack<int> stk;
	int level=0;
	for (int i=0; i<n; i++) {
		int x=a[i];
		if(level>x) {
			if(!stk.empty()&&stk.top()==x) {
				stk.pop();
			} else return false;
		}
		for (int j=level+1; j<x; j++) {
			stk.push(j);
		}
		level=max(level,x);
	}
	return stk.empty();
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n;
	while(cin>>n&&n) {
		vector<int> a(n);
		while(cin>>a[0]&&a[0]) {
			for (int i=1; i<n; i++) cin>>a[i];
			if(ok(a)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		cout << endl;
	}
	return 0;
}
