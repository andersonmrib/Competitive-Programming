#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string tag, text, ans;
  int number;

  while(cin >> tag){

    cin >> number; cin.ignore();
    getline(cin, text);

    for(int i=0; i<text.size(); i++){

      while(i<text.size() && text[i] != '<')
        cout << text[i++];

      while(i<text.size() && text[i] != '>'){
        if(tolower(text[i]) == tolower(tag[0])){
          // found a probable match
          string substring = text.substr(i, tag.size());
          transform(substring.begin(), substring.end(), substring.begin(), ::tolower);
          transform(tag.begin(), tag.end(), tag.begin(), ::tolower);
          // checks if it' what we are looking for
          if(substring == tag){
            cout << number;
            i += tag.size(); // adjust the index properly
          }
          else cout << text[i++];
        }
        else cout << text[i++];
      }
      if(i<text.size())
        cout << text[i];
    }
    cout << "\n";
  }

  return 0;
}
