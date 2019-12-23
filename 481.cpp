#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int n;

int GetCeilIndex(vector<int> &T, int l, int r, int key) {
	while (r-l>1) {
		int m=l+(r-l)/2;
		if(arr[T[m]]>=key) r = m;
		else l = m;
	}
	return r;
}
 
vector<int> LIS() {
	vector<int> tailIndices(n,0), prevIndices(n,-1);
	int len=1;
	for (int i=1; i<n; i++) {
		if (arr[i]<arr[tailIndices[0]]) tailIndices[0] = i;
		else if (arr[i]>arr[tailIndices[len-1]]) prevIndices[i] = tailIndices[len-1], tailIndices[len++] = i;
		else {
			int pos = GetCeilIndex(tailIndices, -1, len-1, arr[i]);
			prevIndices[i] = tailIndices[pos-1];
			tailIndices[pos] = i;
		}
	}
 
	vector<int> ret;
	for (int i=tailIndices[len-1]; i>=0; i=prevIndices[i]) ret.push_back(arr[i]);
	int sz=ret.size();
	for (int i=0; i<sz/2; i++) swap(ret[i], ret[sz-1-i]);
	return ret;
}
 
int main() {
	int x;
	while(cin>>x)
		arr.push_back(x);
	n=arr.size();
  vector<int> cur=LIS();
	cout << cur.size() << endl << "-" << endl;
	for (int x : cur)
		cout << x << endl;
	return 0;
}
