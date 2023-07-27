// passgen.c
// (c) 2023 Nate Eaton (basfunval)
// This code is licensed under GPL 3.0 (See LICENSE for details)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/random.h>

#include "passgen.h"

int chooseCustomPool(char* pool){
  if(strcmp(pool, "lower") == 0)
    return 0;
  if(strcmp(pool, "upper") == 0)
    return 1;
  if(strcmp(pool, "letter") == 0)
    return 2;
  if(strcmp(pool, "alphanum") == 0)
    return 3;
  if(strcmp(pool, "number") == 0)
    return 4;
  if(strcmp(pool, "symbol") == 0)
    return 5;
  return -1;
}

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
        switch(chooseCustomPool(optarg)){
          case 0: strcat(customPool, LOWER); break;
          case 1: strcat(customPool, UPPER); break;
          case 2: strcat(customPool, LETTER); break;
          case 3: strcat(customPool, LETTER); strcat(customPool, NUMBER); break;
          case 4: strcat(customPool, NUMBER); break;
          case 5: strcat(customPool, SYMBOL); break;
          default: printf("invalid charset: %s\nplease use \'-C\' to set explicit charset\n", optarg); return -1;
        }
        break;
      case 'C':
        strcpy(customPool, optarg);
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
