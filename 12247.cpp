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
	int a,b,c,x,y;
	while(cin>>a>>b>>c>>x>>y) {
		if(!a&&!b&&!c&&!x&&!y) return 0;
		set<int> st={a,b,c,x,y};

		int ret=-1;
		for (int z=1; z<=52; z++) {
			if(st.find(z)==st.end()) {
				vector<int> v={a,b,c}, w={x,y,z};
				sort(v.begin(),v.end());
				sort(w.begin(),w.end());
				bool ok=true;
				do {
					int diff=0;
					for (int i=0; i<3; i++)
						if(v[i]<w[i]) diff++;
						else diff--;
					if(diff<0) ok=false;
				} while(next_permutation(w.begin(), w.end()));
				if(ok) { ret=z; break; }
			}
		}
		cout << ret << endl;
	}
}
