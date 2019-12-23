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

int main() {
	int n,m;
	while(cin>>n>>m) {
		int ret=0;
		for (int i=0; i<n; i++) {
			int rem=m;
			for (int j=0; j<m; j++) {
				int x; cin>>x;
				if(x) rem--;
			}
			if(!rem) ret++;
		}
		cout << ret << endl;
	}
	return 0;
}
