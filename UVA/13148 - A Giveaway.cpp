#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  string phrase = "1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,"
                   "1000000, 1771561, 2985984, 4826809, 7529536, 11390625,"
                   "16777216, 24137569, 34012224, 47045881, 64000000, 85766121";

  unordered_set<int> uset;
  stringstream ss(phrase);
  string data;
  while(getline(ss, data, ','))
    uset.insert(stoi(data));

  int n;
  while((cin >> n), n){
    if(uset.find(n) == uset.end())
      cout << "Ordinary\n";
    else
      cout << "Special\n";
  }

  return 0;
}
