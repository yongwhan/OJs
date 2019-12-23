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
	return n2s(d.y,4)+":"+n2s(d.m,2)+":"+n2s(d.d,2);
}

int main() {
	dat cur=dat(0,1,1), end=dat(399,12,31);
	int idx=0;
	map<string,int> date_to_idx;
	map<int,string> idx_to_date;
	while(1) {
		string tmp=d2s(cur);
		idx_to_date[idx]=tmp;
		date_to_idx[tmp]=idx++;
		if(equal(cur,end)) break;
		cur=next(cur);
	}

	int sz=idx_to_date.size(), k,d,m,y;
	while(cin>>k>>d>>m>>y) {
		if(!k&&!d&&!m&&!y) return 0;
		dat pivot=dat(y%400,m,d);
		int iter=date_to_idx[d2s(pivot)] + y/400 * sz + k;
		int skip=iter/sz;
		dat ret=s2d(idx_to_date[iter%sz]);
		ret.y+=skip*400;
		cout << ret.d << " " << ret.m << " " << ret.y << endl;
	}
	return 0;
}
