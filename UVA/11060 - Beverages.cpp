#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef vector<int> vi;

int main(){

  int n, m, numCases = 0;
  while(cin >> n){

    vector<vi> AL(n, vi());
    unordered_map<string, int> mapper;
    unordered_map<int, string> reverseMapper;
    for(int i=0; i<n; i++){
        string B1; cin >> B1;
        mapper[B1] = i;
        reverseMapper[i] = B1;
    }

    vi in_degree(n, 0); cin >> m;
    for(int i=0; i<m; i++){
        string B1, B2; cin >> B1 >> B2;
        int a = mapper[B1], b = mapper[B2];
        AL[a].push_back(b);
        in_degree[b]++;
    }

    printf("Case #%d: Dilbert should drink beverages in this order:", ++numCases);

    priority_queue<int, vi, greater<int>> pq;
    for(int u=0; u<n; u++)
        if(in_degree[u] == 0)
          pq.push(u);

    while(!pq.empty()){
        int u = pq.top(); pq.pop();
        printf(" %s", reverseMapper[u].c_str());
        for(auto &v : AL[u]){
            --in_degree[v];
            if(in_degree[v] > 0) continue;
            pq.push(v);
        }
    }

    printf(".\n\n");
    getchar();
  }

  return 0;
}

