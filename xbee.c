#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if ((argc < 3)|(argc > 3)) {
    printf ("utilisation : ./xbee port \"numero du tag\"\n");
    exit(0);
  }

  char c;
  int fd = open( argv[1] , O_RDWR);
  char tag = argv[2][0];
  
  while (1) {
    //lecture du caractere reçu
    read(fd, &c, 1);
    printf("Read byte %c\n", c);
    
    //si il est pour nous repondre
    if (c == tag) {
      write(fd, "!" , 1 );
    }
    
  }
    
    return 0;
}
