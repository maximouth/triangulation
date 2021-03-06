#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


void send_cmd (int fd, char *cmd)
{
  write(fd, cmd, 4) ;
  write(fd, "\r", 1) ;
  fsync (fd) ;
}
  

char get_byte_ignore_t (int fd)
{
  char c = 'p' ;
  int ret_code ;
  while (c == 'p') {
    ///printf("boucle\n");
    ret_code = read (fd, &c, sizeof (char)) ;
    if (ret_code <= 0) {
      printf ("Arrrrg!\n") ; exit (7) ;
    }
    //printf ("Got: %c\n", c) ;
  }
  return (c) ;
}


int main(int argc, char* argv[]) {
  char c;
  int fd ;
  int nb ;
  FILE* fichier = NULL ;
  int cpt = 0 ;

  if ((argc < 4)|(argc > 4)) {
    printf ("utilisation : ./xbee port \"nombre itérations\" \"fichier resultat\" \n");
    exit(0);
  }

  fd = open (argv[1], O_RDWR) ;
  if (fd < 0) {
    printf ("Unable to open '%s'\n", argv[1]) ;
    return (1) ;
  }
  nb = atoi (argv[2]);

  fichier = fopen(argv[3], "wb") ;

  if (fichier == NULL) {
    printf ("impossible d'ouvrir le fichier %s\n", argv[3]) ;
    return (1) ;
  }


  
  for (cpt = 0; cpt < nb; cpt ++) {

    printf ("send Ping\n");
    write (fd, "?" , 1) ;    /* Send ping. */
    sleep (2) ;
    read (fd, &c, 1) ;
    if (c != '!') {
      printf ("Unexpected '%c' instead of '!'.\n", c) ;
      return (1) ;
    }
   
    printf ("Entering command mode.\n") ;
    write (fd, "+++" , 3) ;    /* Enter command mode. */
    fsync (fd) ;  /* Force flushing on the /dev/ttyxxx. Seems needed O_o */
    sleep (1) ;
    
    printf("apres +++\n", c);
    read(fd, &c, 1);
      //get_byte_ignore_t (fd) ;
    printf("Read byte %c\n", c);
    read(fd, &c, 1);
    printf("Read byte %c\n", c);
    read(fd, &c, 1);
    printf("Read byte %c\n", c);
    // sleep (1) ;
    
    send_cmd (fd, "atdb") ;   /* Ask signal drop rate. */
    sleep (1) ;
    
    read(fd, &c, 1);
    printf("Read byte %c\n", c);
    fputc(c,fichier);
    read(fd, &c, 1);
    fputc(c,fichier);
    printf("Read byte %c\n", c);
        read(fd, &c, 1);
    printf("Read byte %c\n", c);
    fputc('\n',fichier);
    //    sleep (1) ;
    
    send_cmd (fd, "atcn") ;  /* Exit command mode. */
    sleep(1);
    read(fd, &c, 1);
      //get_byte_ignore_t (fd) ;
    printf("Read byte %c\n", c);
    read(fd, &c, 1);
    printf("Read byte %c\n", c);
    read(fd, &c, 1);
    printf("Read byte %c\n", c);

    sleep(1);
  }

  fclose (fichier);
  return 0;
}
