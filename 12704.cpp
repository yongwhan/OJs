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
	int t; cin>>t;
	while(t--) {
		double x,y,r; cin>>x>>y>>r;
		double z=sqrt(x*x+y*y);
		cout << setprecision(2) << fixed << r-z << " " << r+z << endl;
	}
	return 0;
}
