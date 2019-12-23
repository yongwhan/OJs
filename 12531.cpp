#include<cstdio>
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
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int h=0, m=0, x=0;
	set<int> st;
	while(1) {
		int angle=(h-m+360)%360;
		st.insert(min(angle, 360-angle));
		m=(m+6)%360;
		if(x%12==0) h=(h+30)%360;
		x=(x+1)%12;
		if(!h&&!m) break;
	}

	int cur;
	while(cin>>cur)
		if(st.find(cur)!=st.end()) cout << "Y" << endl;
		else cout << "N" << endl;
	return 0;
}
