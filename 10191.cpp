#include<bits/stdc++.h>
using namespace std;

int s2n(string &s) {
	stringstream ss(s);
	int ret; ss>>ret;
	return ret;
}

int eval(string &s) {
	string hh,mm;
	if(s.size()>=2)
		hh=s.substr(0,2);
	if(s.size()>=5)
		mm=s.substr(3);
	return s2n(hh)*60+s2n(mm);
}

string n2t(int x) {
	string hh=to_string(x/60), mm=to_string(x%60);
	while(hh.size()<2) hh='0'+hh;
	while(mm.size()<2) mm='0'+mm;
	return hh+":"+mm;
}

string n2d(int x) {
	int h=x/60, m=x%60;
	stringstream ss;
	if(h) ss<<h<<" hours and ";
	ss<<m<<" minutes";
	return ss.str();
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string line;
	int c=0;
	while(getline(cin,line)) {
		int n=s2n(line);
		vector<bool> good(24*60,true);
		good[18*60]=false;
		while(n--) {
			getline(cin,line);
			string s,t;
			stringstream ss(line); ss>>s>>t;
			int x=eval(s), y=eval(t);
			for (int i=x; i<y; i++)
				good[i]=false;
		}
		int time=-1, ret=-1, cur=0;
		for (int i=10*60; i<=18*60; i++) {
			if(!good[i]) {
				if(ret<cur) ret=cur, time=i-cur;
				cur=0;
			} else cur++;
		}
		cout<<"Day #"<<++c<<": the longest nap starts at "<<n2t(time)<<" and will last for " << n2d(ret)<<".\n";
	}
	return 0;
}
