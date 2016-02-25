#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if ((argc < 4)|(argc > 4)) {
    printf ("utilisation : ./xbee port \"nombre itération\" \"fichier resultat\" \n");
    exit(0);
  }

  char c;
  int fd = open( argv[1] , O_RDWR);
  int nb = atoi(argv[2]) * 2;
  FILE* fichier = NULL;
  int cpt = 0;
  
  fichier = fopen(argv[3], "w");
  
  if (fichier == NULL) {
    printf ("impossible d'ouvrir le fichier %s\n", argv[3]);
    exit(0);
  }

  
  while (cpt < nb) {
    write(fd, "+++" , 1 );
    write(fd, "+++" , 1 );
    write(fd, "+++" , 1 );

    read(fd, &c, 1);
    printf("Read byte %c\n", c);

    read(fd, &c, 1);
    printf("Read byte %c\n", c);	

    read(fd, &c, 1);
    printf("Read byte %c\n", c);

    
    write(fd, "a" , 1 );
    write(fd, "t" , 1 );
    write(fd, "d" , 1 );
    write(fd, "b" , 1 );
    write(fd, "\r" , 1 );


    if ((cpt % 2) == 0) {

      read(fd, &c, 1);
      printf("Read byte %c\n", c);
      fputc(c,fichier);
      
      read(fd, &c, 1);
      fputc(c,fichier);
      printf("Read byte %c\n", c);	

      read(fd, &c, 1);
      printf("Read byte %c\n", c);	
    
      fputc('\r',fichier);

    }
    else {

      read(fd, &c, 1);
      printf("Read byte %c\n", c);	
      
      read(fd, &c, 1);
      printf("Read byte %c\n", c);	

      read(fd, &c, 1);
      printf("Read byte %c\n", c);	
    
    }
    
    cpt++;
    sleep(1);
      
  }
  fclose (fichier);
  
    
    return 0;
}
