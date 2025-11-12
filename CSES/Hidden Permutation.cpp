#include <bits/stdc++.h>
using namespace std;

bool cmp(int i, int j){

  cout << "? " << i << " " << j << endl;

  string judge; cin >> judge;
  return judge == "YES";
}

int main(){

  int n; cin >> n;
  vector<int> idx(n+1);
  for(int i=1; i<=n; i++)
    idx[i] = i;

  stable_sort(idx.begin() + 1, idx.end(), cmp);
  vector<int> a(n+1);
  for(int i=1; i<=n; i++)
    a[idx[i]] = i;

  cout << " !";
  for(int i=1; i<=n; i++)
    cout << a[i] << (i == n ? "" : " ");

  cout << endl;

  return 0;
}
