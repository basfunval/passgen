#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>

int main(){
  int len = 16;
  char pass[len];
  int check = getrandom(pass, len, GRND_RANDOM);
  if(check != len){
    perror("Failed to access random values\n");
    return -1;
  }
  for(int i = 0; i < len; i++){
    pass[i] = 33 + (pass[i]%93);
  }
  printf("%s\n",pass);
  return 0;
}
