#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int n; cin >> n;
  getchar();
  while(n--){
    string text;
    int frequency[26] = {0};
    int mostFrequent = 0;

    getline(cin, text);

    for(auto c : text){
        c = tolower(c);
        if(isalpha(c))
          frequency[c - 'a']++;
    }

    for(auto x : frequency)
        if(x > mostFrequent)
          mostFrequent = x;

    for(int i=0; i<26; i++)
        if(frequency[i] == mostFrequent)
          cout << char(i + 'a');
    cout << endl;

  }

  return 0;
}
