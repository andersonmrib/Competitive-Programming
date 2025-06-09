#include <stdio.h>
#include <string.h>

int main(){

  int t; scanf("%d", &t);
  while(t--){
    int n; scanf("%d", &n); //n it is not being used
    int v, a; scanf("%d %d", &v, &a);

    int maze[v][v]; memset(maze, 0, sizeof(maze)); 

    for(int i=0; i<a; i++){
        int origin, destiny; scanf("%d %d", &origin, &destiny);

        maze[origin][destiny] = 1;
        maze[destiny][origin] = 1;
    }

    int answer = 0;
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
        if(maze[i][j] == 1) answer++;

    printf("%d\n", answer);
  }

  return 0;
}
