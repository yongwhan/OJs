#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string line;
	while(getline(cin,line)) {
		map<ii,char> mp;
		map<int,int> ct;
		int home=0, n=line.size(), cur=0;
		for (int i=0; i<n; i++) {
			char ch=line[i];
			if(ch=='[') {
				cur=--home;
			} else if(ch==']') {
				cur=0;
			} else {
				mp[{cur,ct[cur]++}]=ch;
			}
		}
		for (auto it : mp)
			cout << it.second;
		cout << endl;
	}
	return 0;
}
