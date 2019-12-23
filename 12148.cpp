#include<bits/stdc++.h>
using namespace std;

string month[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

map<string,int> month_to_number;

struct dat {
	int y,m,d,c;
	dat(int y_, int m_, int d_, int c_) {
		y=y_, m=m_, d=d_, c=c_;
	}
};

int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int x) {
	return (x%400==0)||((x%100)&&(x%4==0));
}

dat next(dat x) {
	x.d++;
	int day=days[x.m-1];
	if(leap(x.y) && x.m==2) day++;
	if(x.d>day)
		x.d-=day, x.m++;
	if(x.m>12)
		x.m-=12, x.y++;
	return x;
}

int s2n(string &s) {
	stringstream ss(s); int ret; ss>>ret; return ret;
}

string n2s(int x, int l) {
	stringstream ss; ss<<x;
	string ret=ss.str();
	while(ret.size()<l) ret='0'+ret;
	return ret;
}

bool equal(dat &a, dat &b) {
	return a.y==b.y&&a.m==b.m&&a.d==b.d; 
}

bool later(dat &s, dat &t) {
	if(s.y==t.y) {
		if(s.m==t.m) return s.d>t.d;
		else return s.m>t.m;
	} else return s.y>t.y;
}

int main() {
	for (int i=0; i<12; i++) month_to_number[month[i]]=i+1;

	int n;
	while(cin>>n) {
		if(!n) return 0;
		vector<dat> v;
		for (int i=0; i<n; i++) {
			int d,m,y,c; cin>>d>>m>>y>>c;
			v.push_back(dat(y,m,d,c));
		}
		int ct=0, sum=0;
		for (int i=0; i<n-1; i++) {
			dat base=next(v[i]);
			if(equal(v[i+1], base)) ct++, sum+=v[i+1].c-v[i].c;
		}
		cout << ct << " " << sum << endl;
	}
	return 0;
}
