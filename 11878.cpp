#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int valid(string &s) {
	int a,b;
	string x;
	char op,eq;
	stringstream ss(s);
	ss>>a>>op>>b>>eq>>x;
	if(x=="?") return 0;
	stringstream tt(x);
	int c; tt>>c;
	if(op=='+') return a+b==c;
	else return a-b==c;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s;
	int ret=0;
	while(cin>>s)
		ret+=valid(s);
	cout << ret << endl;
	return 0;
}
