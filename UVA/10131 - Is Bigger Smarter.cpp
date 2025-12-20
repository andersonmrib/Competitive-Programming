#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;

struct elephant{
  int w, iq, id;
};

bool cmp(const elephant &a, const elephant &b){
  if(a.w != b.w)
    return a.w < b.w;
  return a.iq > b.iq;
}

int main(){

  speedBoost;
  vector<elephant> vec;
  int w, iq;

  int id = 0;
  while(cin >> w >> iq)
    vec.push_back({w, iq, id++});

  int n = vec.size();
  sort(vec.begin(), vec.end(), cmp);

  vi L(n), L_id(n), p(n, -1);
  int k = 0, lis_end = 0;

  for(int i=0; i<n; i++){

    int val = -vec[i].iq;
    int pos = lower_bound(L.begin(), L.begin() + k, val) - L.begin();

    L[pos] = val;
    L_id[pos] = i;
    p[i] = (pos ? L_id[pos-1] : -1);

    if(pos == k){
      k = pos + 1;
      lis_end = i;
    }
  }

  vi ans;
  for(int i=lis_end; i!= -1; i = p[i])
    ans.push_back(vec[i].id);
  reverse(ans.begin(), ans.end());

  cout << k << endl;
  for(auto x : ans)
    cout << x+1 << endl;

  return 0;
}
