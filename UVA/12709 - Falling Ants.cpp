#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const double g = 9.8;

struct ant{

  int L, W, H;
  ant(int _l, int _w, int _h) : L(_l), W(_w), H(_h) {}
  int volume = L * W * H;
  double downwardAcc = g - (g/(2*H));

  bool operator <(const ant &other) const{
    if(downwardAcc != other.downwardAcc)
      return downwardAcc > other.downwardAcc;
    return volume > other.volume;
  }
};

int main(){

  speedBoost;
  int t;
  while(cin >> t, t){

    vector<ant> vec;
    for(int i=0; i<t; i++){
      int L, W, H;
      cin >> L >> W >> H;
      vec.push_back({L, W, H});
    }

    sort(vec.begin(), vec.end());

    cout << vec[0].volume << "\n";
  }

  return 0;
}


