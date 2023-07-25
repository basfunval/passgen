#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/random.h>

int main(int argc, char **argv){
  //set default length
  int len = 16;
  //handle command line args
  int opt;
  while((opt = getopt(argc, argv, "hl:")) != -1){
    switch(opt){
      case 'h':
        printf("help menu\n");
        return 0;
      case 'l':
        sscanf(optarg, "%d", &len);
        break;
      case ':':
        printf("option needs a value\n");
        break;
      case '?':
        printf("unknown option: %c\n", optopt);
        break;
    }
  }
  unsigned char pass[len+1];
  int check = getrandom(pass, len, GRND_RANDOM);
  if(check != len){
    perror("Failed to access random values\n");
    return -1;
  }
  for(int i = 0; i < len; i++){
    pass[i] = 33 + ((pass[i])%93);
  }
  pass[len] = '\0';
  printf("%s\n",pass);
  return 0;
}
