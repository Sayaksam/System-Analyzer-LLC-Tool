#include <stdio.h>
#include <stdlib.h>

typedef struct commands {
  char* arr[3];
}cmd;

int main(){
    cmd* ptr;
    int i;
    ptr = (cmd*)malloc(sizeof(cmd));
    ptr->arr[0] = "gcc -o cgrps cache_groups.c array_divide.c -lm";
    ptr->arr[1] = "./cgrps > c_groups.txt";
    ptr->arr[2] = "gedit c_groups.txt &";

    for(i = 0; i < 3; i++)
      system(ptr->arr[i]);

    return 0;
}
