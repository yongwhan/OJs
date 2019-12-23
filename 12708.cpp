#include<iomanip>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;

typedef long long ll;

/*
int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a%b);
}

int main() {
	for (int n=1; n<=100; n++) {
		int ret=0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				if(i!=j) ret=max(ret, gcd(i,j));
		cout << n << ": " << ret << endl;
	}
	return 0;
}
*/

int main() {
	int t; cin>>t;
	while(t--) {
		ll x; cin>>x; cout << x/2 << endl;
	}
}
