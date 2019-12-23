#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int value(char ch) {
	return isdigit(ch) ? ch-'0' : ch-'A'+10;
}

ll backward(string s, int a) {
	ll ret=0;
	for (auto ch : s) ret=ret*a+value(ch);
	return ret;
}

char digit(int x) {
	return x<10 ? '0'+x : (x-10)+'A';
}

string forward(ll x, int b) {
	string ret;
	while(x) ret=digit(x%b)+ret, x/=b;
	if(ret.empty()) ret='0';
	while(ret.size()<7) ret=' '+ret;
	if(ret.size()>7) return "  ERROR";
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; int a,b;
	while(cin>>s>>a>>b)
		cout << forward(backward(s,a),b) << endl;
	return 0;
}
