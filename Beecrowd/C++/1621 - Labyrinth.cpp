#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int N, M;
const int MAX = 500;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
char labyrinth[MAX][MAX];
char visited[MAX][MAX];

ii bfs(int sX, int sY, int &maxDist){
  memset(visited, false, sizeof(visited));
  queue<ii> q;
  q.push({sX, sY});
  visited[sX][sY] = true;

  ii farthestNode = {sX, sY};
  maxDist = 0;

  while(!q.empty()){
    int qSize = q.size();
    for(int i=0; i<qSize; i++){
      int r = q.front().first;
      int c = q.front().second;
      q.pop();
      for(int d=0; d<4; d++){
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr >= 0 && nr < N && nc >= 0 && nc < M &&
           labyrinth[nr][nc] == '.' && !visited[nr][nc]){
             visited[nr][nc] = true;
             q.push({nr, nc});
             farthestNode = {nr, nc};
          }
        }
      }
      if(!q.empty()) maxDist++;
  }
  return farthestNode;
}

int main(){

  while(scanf("%d %d", &N, &M), (N || M)){

    getchar();
    for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
        cin >> labyrinth[i][j];

    int startX = 0, startY = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(labyrinth[i][j] == '.'){
          startX = i;
          startY = j;
          break;
        }
      }
    }

    int maxDist;
    ii farthestNode = bfs(startX, startY, maxDist);
    // explores backwards the labyrinth, but now getting the
    // length of the whole path.
    // an interesting floodfill problem using BFS ideas.
    bfs(farthestNode.first, farthestNode.second, maxDist);
    printf("%d\n", maxDist);
  }

  return 0;
}
