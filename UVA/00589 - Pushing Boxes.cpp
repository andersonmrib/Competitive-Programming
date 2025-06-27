#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<int, int> ii;

const int MAX = 25;
char maze[MAX][MAX];
int r, c;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
char push_dir[] = {'S', 'E', 'N', 'W'};
char move_dir[] = {'s', 'e', 'n', 'w'};

struct state{
  int bx, by, px, py, pushes;
  string path;

  bool operator<(const state &other) const{
    if(pushes != other.pushes) return pushes > other.pushes;
    return path.size() > other.path.size();
  }
};

bool inside(int x, int y){
  return x >= 0 && x < r && y >= 0 && y < c && maze[x][y] != '#';
}

bool can_walk(int sx, int sy, int ex, int ey, int bx, int by){
  queue<ii> q;
  bool visited[MAX][MAX] = {};
  visited[sx][sy] = true;
  q.push({sx, sy});

  while(!q.empty()){
    auto [x, y] = q.front(); q.pop();

    if(x == ex && y == ey) return true;

    for(int d=0; d<4; d++){
      int nx = x + dr[d], ny = y + dc[d];
      if(inside(nx, ny) && !visited[nx][ny] && !(nx == bx && ny == by)){
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
  return false;
}

string pathRec(int sx, int sy, int ex, int ey,int bx, int by){
  queue<ii> q;
  bool visited[MAX][MAX] = {};
  visited[sx][sy] = true;
  map<ii, ii> parent;
  map<ii, char> move;
  q.push({sx, sy});

  while(!q.empty()){
    auto [x, y] = q.front(); q.pop();

    if(x == ex && y == ey) break;

    for(int d=0; d<4; d++){
      int nx = x + dr[d], ny = y + dc[d];
      if(inside(nx, ny) && !visited[nx][ny] && !(nx == bx && ny == by)){
        visited[nx][ny] = true;
        parent[{nx, ny}] = {x, y};
        move[{nx, ny}] = move_dir[d];
        q.push({nx, ny});
      }
    }
  }

    string res = "";
    ii cur = {ex, ey};
    while(cur != make_pair(sx, sy)){
      res = move[cur] + res;
      cur = parent[cur];
    }

  return res;
}

void solve(int NC){
  int sx, sy, bx, by, tx, ty;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      if(maze[i][j] == 'S') sx = i, sy = j;
      if(maze[i][j] == 'B') bx = i, by = j;
      if(maze[i][j] == 'T') tx = i, ty = j;
    }
  }

  priority_queue<state> pq;
  map<tuple<int, int, int, int>, bool> visited;

  pq.push({bx, by, sx, sy, 0, ""});

  while(!pq.empty()){
    state cur = pq.top(); pq.pop();

    if(cur.bx == tx && cur.by == ty){
      cout << "Maze #" << NC << "\n" << cur.path << "\n\n";
      return;
    }

    if(visited[{cur.bx, cur.by, cur.px, cur.py}]) continue;
    visited[{cur.bx, cur.by, cur.px, cur.py}] = true;

    for(int d=0; d<4; d++){
      int nbx = cur.bx + dr[d];
      int nby = cur.by + dc[d];
      int px = cur.bx - dr[d];
      int py = cur.by - dc[d];

      if(!inside(nbx, nby) || !inside(px, py)) continue;
      if(can_walk(cur.px, cur.py, px, py, cur.bx, cur.by)){
        string walkPath = pathRec(cur.px, cur.py, px, py, cur.bx, cur.by);
        string newPath = cur.path + walkPath + push_dir[d];
        pq.push({nbx, nby, cur.bx, cur.by, cur.pushes+1, newPath});
      }
    }
  }
  cout << "Maze #" << NC << "\nImpossible.\n\n";
}

int main(){

  speedBoost;
  int NC = 1;
  string line;
  while((cin >> r >> c), (r || c)){
    getline(cin, line);
    for(int i=0; i<r; i++){
      getline(cin, line);
      for(int j=0; j<c; j++) maze[i][j] = line[j];
    }
    solve(NC++);
  }

  return 0;
}
