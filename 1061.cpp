#include<bits/stdc++.h>
using namespace std;

void convert(string &s) {
	if(s.size()==2)
		s="O"+s;
}

string convert2(string &s) {
	if(s!="AB")
		s=s.substr(0,1);
	return s;
}

set<string> combi(string s, string t) {
	set<string> ret;
	for (auto it : s) for (auto it2 : t) {
		string cur;
		cur+=it; cur+=it2;
		sort(cur.begin(),cur.end());
		ret.insert(convert2(cur));
	}
	return ret;
}

int order(string &s) {
	if(s[0]=='O') return 0;
	else if(s[0]=='A'&&s[1]=='B') return 1;
	else if(s[0]=='B') return 2;
	return 3;
}

int sign(string s) {
	char sgn=s[s.size()-1];
	if(sgn=='-') return -1;
	else return 1;
}

bool cmp(string s, string t) {
	int n=order(s), m=order(t);
	if(n==m)
		return sign(s)<sign(t);
	return n<m;
}

string print(set<string> &st) {
	if(st.empty())
		return "IMPOSSIBLE";
	vector<string> v(st.begin(), st.end());
	sort(v.begin(),v.end(), cmp);
	if(v.size()==1)
		return v[0];
	bool first=true;
	string ret="{";
	for (auto it : v) {
		if(!first) ret+=", ";
		ret+=it;
		first=false;
	}
	ret+="}";
	return ret;
}

set<string> get_child(string a, string b) {
	convert(a);
	convert(b);
	string s1=a.substr(0,2), sgn1=a.substr(2);
	string s2=b.substr(0,2), sgn2=b.substr(2);
	set<string> st=combi(s1,s2);
	set<string> st2={"-"};
	if(sgn1=="+"||sgn2=="+") st2.insert("+");
	set<string> ret;
	for (auto it : st) for (auto it2 : st2)
		ret.insert(it+it2);
	return ret;
}

bool ok(string s, string t, string u) {
	set<string> st=get_child(s,t);
	return (st.find(u)!=st.end());
}

string parent(string a, string b) {
	set<string> ret;
	for (auto it : {"A", "AB", "B", "O"}) {
		for (auto it2 : {"+", "-"}) {
			string cur=it; cur+=it2;
			if(ok(a,cur,b))
				ret.insert(cur);
		}
	}
	return print(ret);
}

string child(string a, string b) {
	set<string> cur=get_child(a,b);
	return print(cur);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string a,b,c;
	int t=0;
	while(cin>>a>>b>>c, !(a=="E"&&b=="N"&&c=="D")) {
		if(a=="?") a=parent(b,c);
		else if(b=="?") b=parent(a,c);
		else c=child(a,b);
		cout << "Case " <<  ++t << ": " << a << " " << b << " " << c << endl;
	}
	return 0;
}
