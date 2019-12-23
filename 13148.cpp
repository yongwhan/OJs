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

const int mx=100000000+1024;

int main() {
	map<int,int> mp;
	for (int i=1; i*i<mx; i++)
		mp[i*i]++;
	for (int i=1; i*i*i<mx; i++)
		mp[i*i*i]++;

	set<int> st;
	for (map<int,int>::iterator it=mp.begin(); it!=mp.end(); it++)
		if((*it).second==2) st.insert((*it).first);

	int x;
	while(cin>>x) {
		if(!x) break;
		if(st.find(x)==st.end()) cout << "Ordinary";
		else cout << "Special";
		cout << endl;
	}
	return 0;
}
