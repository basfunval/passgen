#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(0));
  char pass[16];
  for(int i = 0; i < 16; i++){
    pass[i] = 33 + (rand()%93);
  }
  printf("%s\n",pass);
  return 0;
}
