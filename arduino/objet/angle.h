#ifndef _ANGLE_H_
#define _ANGLE_H_


/* calcul la taille du segment [AB] avec leurs 
coordonées  */
double calcul_c (int x1,int y1 , int x2, int y2);

/* calcul l'angle l'angle du croisement de (AC) et (AB)
   a longueur de BC
   b longueur de AC
   c longueur de AB
  */
double calcul_angle (double a, double b, double c);

/* calcul la cotangente de l'angle angle*/
double cot (double angle);

/* converti un angle en radian en degré */
double convert_angle (double rad);


#endif
