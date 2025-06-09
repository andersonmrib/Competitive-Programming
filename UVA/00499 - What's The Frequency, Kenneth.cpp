#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  string line;
  while(getline(cin, line)){

    int upper[26] = {0};
    int lower[26] = {0};

    int frequency = 0;
    for(auto c : line){
      if(isalpha(c)){
        if(c >= 'A' && c <= 'Z'){
          upper[c - 'A']++;
          frequency = max(frequency, upper[c - 'A']);
        }
        else{
          lower[c - 'a']++;
          frequency = max(frequency, lower[c - 'a']);
        }
      }
    }

    for(int i=0; i<26; i++){
      if(upper[i] == frequency)
        printf("%c", i + 'A');
    }

    for(int i=0; i<26; i++){
      if(lower[i] == frequency)
        printf("%c", i + 'a');
    }

    printf(" %d\n", frequency);
  }

  return 0;
}
