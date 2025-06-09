#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

// Number 1 MUST be considered to be a prime here!
bool isPrime(int n){
  for(int i=2; i*i<=n; i++)
    if(n%i == 0) return false;
  return true;
}

int main(){

  speedBoost;
  unordered_map<char, int> umap;

  for(int i='a'; i<='z'; i++)
    umap[i] = (i - 'a') + 1;

  for(int i='A'; i<='Z'; i++)
    umap[i] = (i - 'A') + 27;

  string str;
  while(cin >> str){

    int sum = 0;
    for(auto c : str) sum += umap[c];

    if(isPrime(sum)) cout << "It is a prime word.\n";
    else             cout << "It is not a prime word.\n";
  }

  return 0;
}
