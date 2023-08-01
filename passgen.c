// passgen.c
// (c) 2023 Nate Eaton (basfunval)
// This code is licensed under GPL 3.0 (See LICENSE for details)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/random.h>

#include "passgen.h"

int main(int argc, char **argv){
  //set default length
  int len = 16;
  char* pool = ASCII;
  //handle command line args
  int opt;
  char customPool[255] = "";
  while((opt = getopt(argc, argv, "hc:C:l:")) != -1){
    switch(opt){
      case 'h':
        printf("%s", HELP_TEXT);
        return 0;
      case 'c':
        if(strcmp(optarg, "lower") == 0){   strcat(customPool, LOWER); break;}
        if(strcmp(optarg, "upper") == 0){   strcat(customPool, UPPER); break;}
        if(strcmp(optarg, "letter") == 0){  strcat(customPool, LETTER); break;}
        if(strcmp(optarg, "alphanum") == 0){strcat(customPool, ALPHANUM); break;}
        if(strcmp(optarg, "number") == 0){  strcat(customPool, NUMBER); break;}
        if(strcmp(optarg, "symbol") == 0){  strcat(customPool, SYMBOL); break;}
        printf("invalid charset: %s\nplease use \'-C\' to set explicit charset\n", optarg);
        return -1;
        break;
      case 'C':
        strcat(customPool, optarg);
        break;
      case 'l':
        sscanf(optarg, "%d", &len);
        if(len < 0) len = 16;
        break;
      case ':':
        printf("option needs a value\n");
        break;
      case '?':
        return -1;
    }
  }
  if(strcmp(customPool, "") != 0){
    pool = customPool;
  }
  unsigned char pass[len+1];
  int check = getrandom(pass, len, GRND_RANDOM);
  if(check != len){
    perror("Failed to access random values\n");
    return -1;
  }
  for(int i = 0; i < len; i++){
    //pass[i] = 33 + ((pass[i])%93);
    pass[i] = pool[pass[i]%strlen(pool)];
  }
  pass[len] = '\0';
  printf("%s\n",pass);
  return 0;
}
