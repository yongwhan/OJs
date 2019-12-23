#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int eval(string &s) {
	int ret=0;
	vector<stack<char>> v;
	for (auto ch : s) {
		int n=v.size(), idx=-1;
		char mn='Z';
		for (int i=0; i<n; i++) {
			char cmp=v[i].top();
			if(ch<=cmp) {
				if(idx==-1) mn=cmp, idx=i;
				else {
					if(mn>cmp)
						mn=cmp, idx=i;
				}
			}
		}
		if(idx!=-1) v[idx].push(ch);
		else {
			stack<char> stk; stk.push(ch);
			v.push_back(stk);
		}
	}
	return v.size();
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s;
	int c=0;
	while(cin>>s&&s!="end") {
		cout << "Case " << ++c << ": " << eval(s) << endl;
	}
	return 0;
}
