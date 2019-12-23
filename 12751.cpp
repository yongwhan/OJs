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

int main() {
	int t; cin>>t;
	for (int c=0; c<t; c++) {
		int n,k,x; cin>>n>>k>>x;
		cout << "Case " << c+1 << ": " << n*(n+1)/2 - (x + x+k-1)*k/2 << endl;
	}
	return 0;
}
