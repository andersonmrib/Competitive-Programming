#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

vector<int> numbers;

bool backtrack(int n, int total){
  if(n == 5)
    if(total == 23) return true;
    else return false;

  return backtrack(n+1, total + numbers[n]) ||
  backtrack(n+1, total - numbers[n]) ||
  backtrack(n+1, total * numbers[n]);
}

int main(){

  speedBoost;
  numbers.assign(5, 0);
  while(true){

    for(int i=0; i<5; i++)
      cin >> numbers[i];

    int sum = 0;
    for(int i=0; i<5; i++)
      sum += numbers[i];

    if(sum == 0) break;

    sort(numbers.begin(), numbers.end());
    bool hasSolution = false;
    do{
        if(backtrack(1, numbers[0])){
          hasSolution = true;
          break;
        }
    } while(next_permutation(numbers.begin(), numbers.end()));

    if(hasSolution) cout << "Possible\n";
    else            cout << "Impossible\n";
  }

  return 0;
}
