#include<bits/stdc++.h>
using namespace std;

char eval(string &s) {
	int ret=0, cur=1;
	for (int i=9; i>=1; i--)
		if(s[i]!='.') {
			if(s[i]=='o') ret+=cur;
			cur<<=1;
		}
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; getline(cin,s);
	while(getline(cin,s) && s[0]!='_')
		cout << eval(s);
	return 0;
}
