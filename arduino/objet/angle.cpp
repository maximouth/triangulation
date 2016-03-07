#include <math.h>
#include "donne.h"

/* calcul la taille du segment [AB] avec leurs coordonées  */
float calcul_c (int x1,int y1 , int x2, int y2) {
  return sqrt (pow ((x2 - x1) ,2) +
	       pow ((y2 - y1) ,2));
}

/* calcul l'angle l'angle en radian du croisement de (AC) et (AB)
   a longueur de AB
   b longueur de AC
   c longueur de BC
  */
float calcul_angle (float a, float b, float c) {
  return acos (((pow(a,2))+(pow(b,2))-(pow(c,2)))
	       / (2 * a * b));
}

/* calcul la cotangente de l'angle angle radian*/
float cot (float angle) {
  return (cos(angle) / sin(angle)); 
}

/* converti un angle en radian en degré */
float convert_angle (float rad) {
  return 180 * rad / M_PI;
}
