#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

string fmt(string s) {
	while(1) {
		if(s[s.size()-1]!=' ') return s;
		s=s.substr(0,(int) (s.size())-1);
	}
}

void print(string &s) {
	while(s[0]==' ') s=s.substr(1);
	int n=s.size();
	if(s.size()<=60) {
		cout << fmt(s) << endl;
		return;
	}

	bool ok=false;
	for (int i=59; i>=0; i--) if(s[i]==' ') {
		ok=true;
		string t=fmt(s.substr(0,i));
		cout << t << endl,
		s=s.substr(i+1);
		print(s);
		return;
	}
	if(!ok) {
		string t=fmt(s.substr(0,min((int)s.size(),60)));
		cout << t << endl;
		s=s.substr(60);
		print(s);
		return;
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	set<string> dict;
	string line;
	while(getline(cin,line) && line!="#")
		dict.insert(line);
	string s=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	map<int,char> itoc;
	map<char,int> ctoi;
	for (int i=0; i<27; i++)
		itoc[i]=s[i], ctoi[s[i]]=i;
	while(getline(cin,line)) {
		map<int, string> ret;
		for (int i=0; i<27; i++) {	
			string cur;
			for (int j=0; j<line.size(); j++)
				cur+=itoc[(ctoi[line[j]]+27-i)%27];
			stringstream ss(cur);
			int score=0;
			string tmp;
			while(ss>>tmp)
				if(dict.find(tmp)!=dict.end())
					score++;
			ret[score]=cur;
		}
		auto it=ret.rbegin();
		string tmp=it->second;
		print(tmp);
	}
	return 0;
}
