#include<bits/stdc++.h>
using namespace std;

struct dat {
	int y,m,d;
	dat(int y_, int m_, int d_) {
		y=y_, m=m_, d=d_;
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

dat prev(dat x) {
	x.d--;
	if(x.d==0) {
		int month=x.m-1;
		if(month==0) {
			month=12;
			int year=x.y-1;
			int day=days[month-1];
			if(leap(year)&&month==2) day++;
			return dat(year,month,day);
		} else {
			int day=days[month-1];
			if(leap(x.y)&&month==2) day++;
			return dat(x.y,month,day);
		}
	} else return x;
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

dat s2d(string &s) {
	string y=s.substr(0,4), m=s.substr(5,2), d=s.substr(8,2);
	return dat(s2n(y),s2n(m),s2n(d));
}

string d2s(dat &d) {
	return n2s(d.m,2)+"/"+n2s(d.d,2)+"/"+n2s(d.y,4);
}

bool later(dat &s, dat &t) {
	if(s.y==t.y) {
		if(s.m==t.m) return s.d>t.d;
		else return s.m>t.m;
	} else return s.y>t.y;
}

string signs[]={"aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn"};
int offset[]={21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23};

string sign(dat &d) {
	for (int i=0; i<12; i++) {
		if(d.m==i+1) {
			if(offset[i]<=d.d) return signs[i];
			else return signs[(i+11)%12];
		}
	}
	return "";
}

int main() {
	int n; cin>>n;
	for (int c=1; c<=n; c++) {
		string s; cin>>s;
		string date=s.substr(4)+":"+s.substr(0,2)+":"+s.substr(2,2);
		dat cur=s2d(date);
		for (int i=0; i<280; i++) {
			cur=next(cur);
		}
		cout << c << " " << d2s(cur) << " " << sign(cur) << endl;
	}
	return 0;
}
