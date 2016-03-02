#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#include "donne.h"



/* vecteur x0 y0  */
double *x1;


/* calcul la matrice  */
double ** calc_mat (double x0, double y0) {
  double a = -(2 * x0) - (2 * X1);
  double b = -(2 * y0) - (2 * Y1);
  double c = -(2 * x0) - (2 * X2);
  double d = -(2 * y0) - (2 * Y2); 
  double e = -(2 * x0) - (2 * X3);
  double f = -(2 * y0) - (2 * Y3); 

  double **mat = malloc (3 * sizeof(double*));

  int i = 0;
  for (i = 0 ; i < 2 ; i++) {
    mat[i] = malloc (2 * sizeof(double));
  }
  
  mat[0][0] =
    ((b * (-a*b - c*d - e*f))
    /
    (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +
     (a*a + c*c + e*e) * (b*b + d*d + f*f)))
    +
    ((a * (b*b + d*d + f*f))
     /
     (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +  
      (a*a + c*c + e*e) * (b*b + d*d + f*f)))
    ;

   mat[0][1] =
    ((d * (-a*b - c*d - e*f))
    /
    (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +
     (a*a + c*c + e*e) * (b*b + d*d + f*f)))
    +
    ((c * (b*b + d*d + f*f))
     /
     (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +  
      (a*a + c*c + e*e) * (b*b + d*d + f*f)))
    ;

   mat[0][2] =
    ((f * (-a*b - c*d - e*f))
    /
    (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +
     (a*a + c*c + e*e) * (b*b + d*d + f*f)))
    +
    ((e * (b*b + d*d + f*f))
     /
     (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +  
      (a*a + c*c + e*e) * (b*b + d*d + f*f)))
    ;

   mat[1][0] = 
     ((b * (a*a + c*c + e*e ))
       /
      (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +
       (a*a + c*c + e*e) * (b*b + d*d + f*f)))
      +
     ((a * (-a*b - c*d - e*f))
      /
      (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +
       (a*a + c*c + e*e) * (b*b + d*d + f*f)))
      ;

    mat[1][1] = 
     ((d * (a*a + c*c + e*e ))
       /
      (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +
       (a*a + c*c + e*e) * (b*b + d*d + f*f)))
      +
     ((c * (-a*b - c*d - e*f))
      /
      (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +
       (a*a + c*c + e*e) * (b*b + d*d + f*f)))
      ;

    mat[1][2] = 
     ((f * (a*a + c*c + e*e ))
       /
      (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +
       (a*a + c*c + e*e) * (b*b + d*d + f*f)))
      +
     ((e * (-a*b - c*d - e*f))
      /
      (-((a*b + c*d + e*f)*(a*b + c*d + e*f)) +
       (a*a + c*c + e*e) * (b*b + d*d + f*f)))
      ;
    
    return mat;
}


/* retourne la valeur le l'equation de cercle pour les coordonées:
   x0 y0 coordonées de notre objet
   x y   coordonées du tag
   d     distance de l'objet au tag
  */
double  vf (double x0,double y0,double x,double y,double d) {
  return (x0 - x)*(x0 - x) + (y0 - y)*(y0 - y) - d;
}


/* calcul le vecteur de F  */
double * calc_vf (double x0, double y0, double d1, double d2, double d3) {

  double *F = malloc (3 * sizeof(double));
  
  F[0] = vf (x0, y0, X1, Y1, d1);
  F[1] = vf (x0, y0, X2, Y2, d2);
  F[2] = vf (x0, y0, X3, Y3, d3);

  return F;
}


/* multiplication matrice vecteur  */
double* mult_vect_mat (double **mat , double *F ) {
  double *tab = malloc (2 * sizeof(double));

  tab[0] = (mat[0][0] * F[0]) + (mat[0][1] * F[1]) + (mat[0][2] * F[2]) ;
  tab[1] = (mat[1][0] * F[0]) + (mat[1][1] * F[1]) + (mat[1][2] * F[2]) ;
  
  return tab;
}


/* addition vecteur  */
double * add_vect_vect (double *vect1, double *vect2) {
  double *res = malloc (2 * sizeof(double));

  res[0] = vect1[0] + vect2[0];
  res[1] = vect1[1] + vect2[1];

  return res;
}


double *algo(double *x1, double d1, double d2, double d3) {
  double *x0 = malloc (2 * sizeof(double));
  
  int i = 0;

  /* point de depart  */
  x0[0] = 5;
  x0[1] = 5;

  for (i = 0 ; i < 100 ; i++) {

    /* empecher de sortir du cadre */
    if (x1[0] < 0) x1[0] = 0;
    if (x1[1] < 0) x1[1] = 0;
   
    
    /* calculer le xn suivant */
    x1 = add_vect_vect (x0,
			mult_vect_mat (
				       calc_mat(x0[0],x0[1]) ,
				       calc_vf (x0[0],x0[1],d1,d2,d3))); 


    printf ("x0 : ");
    printf ("%lf ", x0[0]);
    printf ("%lf \n", x0[1]); 
    printf ("x1 : ");
    printf ("%lf ", x1[0]);
    printf ("%lf \n\n", x1[1]);


    /* regarder si l'on est assez precis */
    if ( (fabs(x1[0] - x0[0]) < EPSILON) &&  (fabs(x1[1] - x0[1]) < EPSILON)) {
      printf ("%lf ", x0[0]);
      printf ("%lf \n", x0[1]); 
      printf ("%lf ", x1[0]);
      printf ("%lf \n\n", x1[1]);
     
      printf ("fini en %d itérations\n" , i);
      return x1;
    }
    
    /* le courant devient l'ancien  */
    x0 = x1;
    
  }
  printf (" iteration fini\n");
  x1[0] = fabs(x1[0]);
  x1[1] = fabs(x1[1]);
  return x1;
}



int main () {
  x1 = malloc ( 2 * sizeof(double));

  
  x1 = algo (x1, 2.828427, 2.236067 ,2);
  printf ("%lf ", x1[0]);
  printf ("%lf \n", x1[1]);
  
  
  return 0;
}
