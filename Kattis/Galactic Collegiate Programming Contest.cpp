#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

class Score{

public:
  int teamID = 0;
  int solved = 0;
  int penalty = 0;

  bool operator<(const Score &other) const{
    if(solved != other.solved)
      return solved > other.solved;
    else if(penalty != other.penalty)
      return penalty < other.penalty;
    else
      return teamID < other.teamID;
  }
};

typedef tree<Score, null_type, less<Score>, rb_tree_tag,
             tree_order_statistics_node_update> ost;

int main(){

  int n, m; scanf("%d %d", &n, &m);

  ost tree;
  unordered_map<int, Score> umap;

  // use this guy for keep tracking the team with id '1'
  Score trackThis;

  for(int i=0; i<n; i++){
    Score s;
    s.teamID = i+1;
    umap[i] = s;
    tree.insert(s);
  }

  for(int i=0; i<m; i++){
    int t, p; scanf("%d %d", &t, &p);
    t--;               // going to work with 0 indexing style

    Score s = umap[t];
    tree.erase(s);     // just clear...
    umap.erase(t);

    s.solved++;
    s.penalty += p;

    umap[t] = s;       // now insert
    tree.insert(s);

    if(t == 0) trackThis = s;

    printf("%d\n", tree.order_of_key(trackThis) + 1);
  }

  return 0;
}
