#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
  int c; cin>>c;
	while(c--) {
		int V, E, s=0, a, b, w;
		vector<vii> AdjList;
		cin>>V>>E;
	  AdjList.assign(V, vii());
		for (int i = 0; i < E; i++)
			cin>>a>>b>>w, AdjList[a].push_back(ii(b, w));
	  vi dist(V, INF); dist[s] = 0;
		for (int i = 0; i < V - 1; i++)
			for (int u = 0; u < V; u++) 
				for (int j = 0; j < (int)AdjList[u].size(); j++) {
					ii v = AdjList[u][j];
	        dist[v.first] = min(dist[v.first], dist[u] + v.second);
		    }

	  bool hasNegativeCycle = false;
		for (int u = 0; u < V; u++)
	    for (int j = 0; j < (int)AdjList[u].size(); j++) {
		    ii v = AdjList[u][j];
			  if (dist[v.first] > dist[u] + v.second)
				  hasNegativeCycle = true;
	    }
		cout << (hasNegativeCycle ? "possible" : "not possible") << endl;
	}
  return 0;
}
