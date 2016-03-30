#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if ((argc < 3)|(argc > 3)) {
    printf ("utilisation : ./xbee port \"numero du tag\"\n");
    exit(0);
  }

  char c = '!';
  FILE *fd = fopen( argv[1] , "r+");
  char tag = argv[2][0];
  
  while (1) {
    c = '!';

    //lecture du caractere reçu
    while (c == '!' || c == '\n' || c == '\r') {
      fread( &c, (sizeof (char)), 1, fd);;
    }

     printf("Read byte %c\n", c);
    
    //si il est pour nous repondre
    if (c == '2') {
      fwrite (&c, sizeof (char), 1, fd);
    }
  }
    
    return 0;
}
