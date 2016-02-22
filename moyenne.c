#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>





int asci (int c) {
  switch (c) {
  case 49 :
    return 1;
    break;
  case 50 :
    return 2;
    break;
  case 51 :
    return 3;
    break;
  case 52 :
    return 4;
    break;
  case 53 :
    return 5;
    break;
  case 54 :
    return 6;
    break;
  case 55 :
    return 7;
    break;
  case 56 :
    return 8;
    break;
  case 57 :
    return 9;
    break;
  case 65 :
    return 10;
    break;
  case 66 :
    return 11;
    break;
  case 67 :
    return 12;
    break;
  case 68 :
    return 13;
    break;
  case 69 :
    return 14;
    break;
  case 70 :
    return 15;
    break;
    
  default :
    return 0;
    
  }
}
    
int asci_to_int(int a, int b) {
  int c = asci(a);
  int d = asci(b);

  
  return (16 * c)+ d;
  
}




int main(int argc, char* argv[]) {
  if ((argc < 4)|(argc > 4)) {
    printf ("utilisation : \"fichier entrée\" \"fichier sortie\" \"distance\" \n");
    exit(0);
  }

  int c,d;
  int nb = atoi(argv[3]);
  FILE* fichier = NULL;
  FILE* sortie = NULL;
  int cpt = 0, moy = 0;
  
  sortie = fopen(argv[2], "a");
  fichier = fopen(argv[1], "r");
  
  if (fichier == NULL) {
    printf ("impossible d'ouvrir le fichier %s\n", argv[3]);
    exit(0);
  }

  while ((c = fgetc(fichier)) != EOF) {
    cpt++;
    d = fgetc(fichier);
    printf ("c : %d, d: %d\n", c , d);
    moy += asci_to_int (c, d);
    printf ("moy : %d\n", moy);
    fgetc(fichier);
  }

  moy = moy / cpt;
  c = (moy / 10) % 10;
  d = moy % 10;

  printf ("c : %d, d: %d\n", c , d);

  fprintf(sortie , "%d %d%d\n", nb, c, d);
  
  fclose (fichier);
  fclose (sortie);
  
    
    return 0;
}

