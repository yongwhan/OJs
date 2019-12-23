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
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		vector<int> a(5);
		bool ok=true;
		for (int j=0; j<5; j++) cin>>a[j];
		for (int j=0; j<4; j++)
			if(a[j]+1!=a[j+1]) ok=false;
		if(ok) cout << 'Y';
		else cout << 'N';
		cout << endl;
	}
	return 0;
}
