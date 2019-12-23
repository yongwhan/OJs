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
	int t; cin>>t;
	for (int c=0; c<t; c++) {
//		if(c) cout << " ";
		int b=0, w=0, a=0, t=0, n; cin>>n;
		for (int i=0; i<n; i++) {
			char ch; cin>>ch;
			if(ch=='B') b++;
			else if(ch=='W') w++;
			else if(ch=='A') a++;
			else t++;
		}

		cout << "Case " << c+1 << ": ";
		if(a==n) cout << "ABANDONED";
		else if(b+a==n) cout << "BANGLAWASH";
		else if(w+a==n) cout << "WHITEWASH";
		else if(b==w) cout << "DRAW " << b << " " << t;
		else if(b>w) cout << "BANGLADESH " << b << " - " << w;
		else if(b<w) cout << "WWW " << w << " - " << b;
		else cout << "DRAW";
		cout << endl;
	}
	return 0;
}
