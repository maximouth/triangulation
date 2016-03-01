#ifndef _ANGLE_H_
#define _ANGLE_H_


/* calcul la taille du segment [AB] avec leurs coordonées  */
float calcul_c (int x1,int y1 , int x2, int y2);

/* calcul l'angle l'angle du croisement de (AC) et (AB)
   a longueur de BC
   b longueur de AC
   c longueur de AB
  */
float calcul_angle (float a, float b, float c);

/* calcul la cotangente de l'angle angle*/
float cot (float angle);

/* converti un angle en radian en degré */
float convert (float rad);


#endif
