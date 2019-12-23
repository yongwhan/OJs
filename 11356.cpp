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

string month[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

map<string,int> month_to_number;

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

dat s2d(string s) {
	for (int i=0; i<s.size(); i++)
		if(s[i]=='-') s[i]=' ';
	stringstream ss(s);
	string y,m,d; ss>>y>>m>>d;
	return dat(s2n(y),month_to_number[m],s2n(d));
}

string d2s(dat &d) {
	return n2s(d.y,4)+"-"+month[d.m-1]+"-"+n2s(d.d,2);
}

bool later(dat &s, dat &t) {
	if(s.y==t.y) {
		if(s.m==t.m) return s.d>t.d;
		else return s.m>t.m;
	} else return s.y>t.y;
}

int main() {
	for (int i=0; i<12; i++) month_to_number[month[i]]=i+1;

	int t,k; cin>>t;
	for (int c=1; c<=t; c++) {
		string s; cin>>s; cin>>k;
		dat cur=s2d(s);
		while(k--) cur=next(cur);
		cout << "Case " << c << ": " << d2s(cur) << endl;
	}
	return 0;
}
