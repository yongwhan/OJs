#include<bits/stdc++.h>
using namespace std;

int score(char ch) {
	if(isdigit(ch)) return ch-'0';
	return 10;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string line;
	while(getline(cin,line), line!="Game Over") {
		stringstream ss(line);
		string s; char ch;
		while(ss>>ch) s+=ch;
		vector<string> lst;
		int n=s.size();
		bool prev=false;
		string cur;
		for (int i=0; i<n; i++) {
			char ch=s[i];
			if(isdigit(ch)) {
				if(!prev) prev=true, cur+=ch;
				else {
					cur+=ch;
					lst.push_back(cur); cur="";
					prev=false;
				}
			} else if(ch=='/') {
				cur+=ch;
				lst.push_back(cur);
				prev=false;
				cur="";
			} else {
				lst.push_back("X");
				prev=false;
				cur="";
			}
		}
		if(!cur.empty()) lst.push_back(cur), cur="";
	
		int ret=0;
		for (int i=0; i<10; i++) {
			string cur=lst[i];
			if(cur=="X") {
				ret+=10;
				string nxt=lst[i+1];
				if(nxt.size()==1) {
					string nxt2=lst[i+2];
					ret+=score(nxt[0])+score(nxt2[0]);
				} else {
					ret+=min(10,score(nxt[0])+score(nxt[1]));
				}
			} else {
				if(cur[1]=='/') {
					ret+=10+score(lst[i+1][0]);
				} else {
					ret+=score(cur[0])+score(cur[1]);
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}
