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

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N,k;
	while(cin>>N>>k) {
		if(!N&&!k) return 0;
		queue<ii> q;
		for (int i=1; i<=N; i++)
			q.push(make_pair(i,0));

		int x=0, y=1;
		vector<int> ret;
		while(!q.empty()) {
			ii cur=q.front(); q.pop();
			cur.second+=y;
			if(cur.second>=40) ret.push_back(cur.first), y=cur.second-40;
			else q.push(cur), y=0;
			if(y==0) x=(x+1)%k, y=x+1;
		}

		for (int i=0; i<N; i++)
			printf("%3d", ret[i]);
		printf("\n");
	}
}
