#include <stdio.h>
#include <math.h>


#define DEBUG

/* calcul la taille du segment [AB] avec leurs coordonées  */
double calcul_c (double x1, double y1 , double x2, double y2)
{
  return sqrt (((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))) ;
}

/* calcul l'angle l'angle en radian du croisement de (AC) et (AB)
   a longueur de AB
   b longueur de AC
   c longueur de BC
  */
double calcul_angle (double a, double b, double c) {
  double aq = a * a;
  double bq = b * b;
  double cq = c * c;
  double i = (aq + bq - cq);
  double j = (2 * a * b);
  double res = i / j ; 
#ifdef DEBUG
  printf ("\na = %lf b = %lf c = %lf\n", a, b, c) ;
  printf ("aq = %lf bq = %lf cq = %lf\n", aq, bq, cq) ;
  printf("i = %lf, j = %lf\n", i, j);
  printf("res = %lf\n", res);
#endif
  
  return acos (res);
}


#define COT_LIMIT (1000000.0)

/* calcul la cotangente de l'angle angle radian*/
double cot (double angle) {
  double c = cos (angle);
  double s = sin (angle);
  double res = (c / s);
  
#ifdef DEBUG
  printf ("\nc = %lf s = %lf\nres = %lf\n", c, s, res) ;
#endif

  return res;
}

/* converti un angle en radian en degré */
double convert_angle (double rad) {
  return (180.0 * rad) / M_PI ;
}
