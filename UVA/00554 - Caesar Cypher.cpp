#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int INF = 1e9;

int charToVal(char c){
  if(c == ' ') return 0;
  else            return c - 'A' + 1;
}

char valToChar(int v){
  if(v == 0) return ' ';
  else       return v + 'A' - 1;
}

string translate(const string &cipher, int k){
  string str = "";
  for(auto c : cipher){
    int v = charToVal(c);
    int p = (v - k + 27) % 27;
    str += valToChar(p);
  }
  return str;
}

void smartPrint(const string &text){
  stringstream ss(text);
  string word;
  string curLine = "";

  while(ss >> word){
    if(curLine.empty())
      curLine = word;
    else if(curLine.size() + 1 + word.size() <= 60)
      curLine += " " + word;
    else{
      cout << curLine << endl;
      curLine = word;
    }
  }

  if(!curLine.empty()) cout << curLine << endl;
}

int32_t main(){

  speedBoost;
  string line;
  set<string> dictionary;
  while(getline(cin, line)){
    if(line == "#") break;
    dictionary.insert(line);
  }

  string encrypted; getline(cin, encrypted);

  int bestK = 0, maxMatches = -1;
  string bestAnswer = "";
  for(int k=0; k<27; k++){
    string decrypted = translate(encrypted, k);
    stringstream ss(decrypted);
    string word;
    int matches = 0;
    while(ss >> word)
      if(dictionary.count(word)) matches++;
    if(matches > maxMatches){
      maxMatches = matches;
      bestK = k;
      bestAnswer = decrypted;
    }
  }

  smartPrint(bestAnswer);

  return 0;
}
