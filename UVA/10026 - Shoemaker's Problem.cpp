#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

struct job{

  int time, fine;
  int id;
};

bool compare(const job &a, const job &b){

  int cost_a = a.time * b.fine;
  int cost_b = b.time * a.fine;

  if(cost_a != cost_b)
    return cost_a < cost_b;
  else
    return a.id < b.id;
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    vector<job> jobs(n);
    for(int i=0; i<n; i++){
      cin >> jobs[i].time >> jobs[i].fine;
      jobs[i].id = i+1;
    }

    sort(jobs.begin(), jobs.end(), compare);

    for(int i=0; i<n; i++){
      if(i > 0) cout << " ";
      cout << jobs[i].id;
    }

    cout << endl;
    if(t) cout << endl;

  }

  return 0;
}
