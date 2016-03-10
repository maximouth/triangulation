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


#define EPSI (5)


/* calcul la cotangente de l'angle angle radian*/
double cot (double angle) {
  if ((angle > (1.56)) && (angle < (1.58))) {
#ifdef DEBUG
    printf("angle = %lf radians ~= 90 degres \n", angle);
#endif    
    return 0;
  }
  double t = tan(angle);

#ifdef DEBUG
  //  printf("\nangle : %lf t = %lf t mod = %lf \n ", angle, t, t_mod);
  printf("\nangle : %lf tangente = %lf \n\n ", angle, t);
#endif
  
  return (1 / t);
}


/* converti un angle en radian en degré */
double convert_angle (double rad) {
  return (180.0 * rad) / M_PI ;
}
