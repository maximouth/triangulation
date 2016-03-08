#include <math.h>
#include "donne.h"

/* calcul la taille du segment [AB] avec leurs coordonées  */
double calcul_c (int x1,int y1 , int x2, int y2) {
return sqrt ((double) ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))) ;

}

/* calcul l'angle l'angle en radian du croisement de (AC) et (AB)
   a longueur de AB
   b longueur de AC
   c longueur de BC
  */
double calcul_angle (double a, double b, double c) {
  return acos (a * a + b * b - c * c) / (2 * a * b) ;
}


#define COT_LIMIT (1000000.0)

/* calcul la cotangente de l'angle angle radian*/
double cot (double angle) {
  double res = (cos(angle) / sin(angle));

   if (res > COT_LIMIT) {
     res = COT_LIMIT ;
  }
  else
    if (res > - COT_LIMIT) {
      res = - COT_LIMIT ;
    }

  return res;
}

/* converti un angle en radian en degré */
double convert_angle (double rad) {
  return (180.0 * rad) / M_PI ;
}
