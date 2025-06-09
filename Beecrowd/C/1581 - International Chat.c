#include <stdio.h>
#include <string.h>

int main(){

  int n; scanf("%d", &n);

  while(n--){
    int flag = 0; //Everyone speaks the same language
    char language[21], languageCopy[21];

    int k; scanf("%d", &k); getchar(); /*Important getchar!*/

    scanf("%s", language);
    strcpy(languageCopy, language);

    for(int i=1; i<k; i++) //Starts from the second person
    {
        scanf("%s", language);
        if(!strcmp(language, languageCopy)) //Both speaks the same language until now
            strcpy(languageCopy, language);
        else flag = 1; //There's at least one person who does not speak the same language
    }

    if (flag) printf("ingles\n");
    else      printf("%s\n", language);
  }

  return 0;
}
