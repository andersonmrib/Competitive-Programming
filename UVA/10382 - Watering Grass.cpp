#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct sp{
  int x, r;                                          // position and radius
  double x_l, x_r;                                   // left and right variation
};

sp sprinkler[10010];

bool comp(sp a, sp b){
  if(fabs(a.x_l - b.x_l) > EPS) return a.x_l < b.x_l;
                                return a.x_r > b.x_r;
}                                                    // sort based on smallest xl
                                                     // and then larger x_r
int main(){

  int n, l, w;
  while(scanf("%d %d %d", &n, &l, &w) != EOF){
    for(int i=0; i<n; i++){
      scanf("%d %d", &sprinkler[i].x, &sprinkler[i].r);
      if(2*sprinkler[i].r >= w){
        double dx = sqrt((double)sprinkler[i].r * sprinkler[i].r - (w/2.0)*(w/2.0));
        sprinkler[i].x_l = sprinkler[i].x - dx;
        sprinkler[i].x_r = sprinkler[i].x + dx;
      }
      else
        sprinkler[i].x_l = sprinkler[i].x_r = sprinkler[i].x;
    }

    sort(sprinkler, sprinkler+n, comp);
    bool possible = true;
    double covered = 0.0;
    int ans = 0;
    for(int i=0; (i<n) && possible; i++){
      if(covered > l) break;                         // done
      if(sprinkler[i].x_r < covered + EPS) continue; // inside previous interval
      if(sprinkler[i].x_l < covered + EPS){          // can cover
        double max_r = -1.0;
        int max_id;
        for(int j=i; (j<n) && (sprinkler[j].x_l < covered + EPS); j++)
        if(sprinkler[j].x_r > max_r){                // go to right to find
          max_r = sprinkler[j].x_r;                  // interval with
          max_id = j;                                // the largest coverage
        }
        ans++;
        covered = max_r;                             // jump here
        i = max_id;
      }
      else
        possible = false;
    }
    if(!possible || (covered < l)) printf("-1\n");
    else                           printf("%d\n", ans);
  }

  return 0;
}
