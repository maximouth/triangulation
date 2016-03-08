#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "signal.h"
#include "angle.h"

#define DEBUG

/*table des puissances signaux */
int tab[3] = {0,0,0};

/*table des distances de  obj à tag*/
double distTag1 ;
double distTag2 ;
double distTag3 ;

/**/
double c1, c2, c3;

/* angle entre les différents points  */
double a12 = 0;
double a23 = 0;
double a31 = 0;

double a1,a2,a3;

/* robot position */
double xr = 0;
double yr = 0;

/* modified beacon coordinates  */
double xq1, yq1, xq3, yq3;

/* Three cot(.)  */
double T12, T23, T31;

/* modified circles coordinates  */
double xq12, yq12, xq23, yq23, xq31, yq31;

/* kq31  */
double kq31;

/* Denominator D  */
double D;

int main (int argc, char *argv[])
{
  /* Coordonnées en entrée */
  double x1,x2,x3,y1,y2,y3,x0,y0,xalpha,yalpha;
  
  if ((argc < 10) || (argc > 10)) {
    printf ("mauvaise utilisation\n./simu x1 y1 x2 y2 x3 y3 x0 y0 alpha \n");
    return 2;
  }
  
  x1 = atof (argv[1]);
  y1 = atof (argv[2]);
  x2 = atof (argv[3]);
  y2 = atof (argv[4]);
  x3 = atof (argv[5]);
  y3 = atof (argv[6]);
  x0 = atof (argv[7]);
  y0 = atof (argv[8]);
  xalpha = atof (argv[9]);
  //yalpha = atof (argv[10]);
  

#ifdef DEBUG
  printf ("x1 : %lf, y1 : %lf, x2 : %lf, y2 : %lf, x3 : %lf, y3 : %lf, x0 : %lf, y0 :%lf\n" ,x1 ,y1, x2, y2, x3, y3, x0, y0);
#endif
  
  distTag1 = calcul_c(x1, y1, x0, y0);
  distTag2 = calcul_c(x2, y2, x0, y0);
  distTag3 = calcul_c(x3, y3, x0, y0); 

#ifdef DEBUG
  printf ("dist1 : %lf, dist2 : %lf, dist3 : %lf\n", distTag1, distTag2, distTag3);
#endif
  
  /* calcul angle  */
  c1 = calcul_c (x1, y1, x2, y2);
  c2 = calcul_c (x2, y2, x3, y3);
  c3 = calcul_c (x3, y3, x1, y1);

  printf ("c1 = %lf, c2 : %lf, c3 : %lf\n", c1, c2 ,c3);
  /*
  a1 = calcul_angle (distTag1,calcul_c(xalpha,yalpha,x0,y0),calcul_c(xalpha,yalpha,x1,y1));
  a2 = calcul_angle (distTag2,calcul_c(xalpha,yalpha,x0,y0),calcul_c(xalpha,yalpha,x2,y2));
  a3 = calcul_angle (distTag3,calcul_c(xalpha,yalpha,x0,y0),calcul_c(xalpha,yalpha,x3,y3));
  */
  a12 = calcul_angle (distTag1, distTag2, c1) + xalpha;
  a23 = calcul_angle (distTag2, distTag3, c2) + xalpha;
  a31 = calcul_angle (distTag3, distTag1, c3) + xalpha;
  
#ifdef DEBUG
  printf ("\na12 = %lf a23 = %lf a31 = %lf\n", a1, a2, a3) ;
  /* debut de l'algorithme  */
#endif

  /* 1) compute the modified beacon coordinates  */
  xq1 = x1 - x2;
  yq1 = y1 - y2;
  xq3 = x3 - x2;
  yq3 = y3 - y2;
#ifdef DEBUG
  printf ("xq1 = %lf yq1 = %lf xq3 = %lf yq3 = %lf\n", xq1, yq1, xq3, yq3) ;
#endif

  /* 2) compute the 3 cot(.)   */
  /*
  T12 = (a2 - a1);
  T23 = (a3 - a2);
  */T12 = cot (a12);
  T23 = cot (a23);
  
  T31 = (1 - (T12 * T23)) / (T12 + T23);
  
#ifdef DEBUG
  printf ("T12 = %lf T23 = %lf T31 = %lf \n", T12, T23, T31) ;
#endif

  
  /* 3) compute the modified circle center coordinates x'ij, y'ij  */
  xq12 = xq1 + (T12 * yq1);
  yq12 = yq1 - (T12 * xq1);

#ifdef DEBUG
  printf ("xq12 = %lf yq12 = %lf \n", xq12, yq12);
#endif

  
  xq23 = xq3 - (T23 * yq3);
  yq23 = yq3 + (T23 * xq3);

#ifdef DEBUG
  printf ("xq23 = %lf yq23 = %lf \n", xq23, yq23);
#endif

  xq31 = (xq3 + xq1) + (T31 * (yq3 - yq1));
  yq31 = (yq3 + yq1) - (T31 * (xq3 - xq1));
  
#ifdef DEBUG
  printf ("xq31 = %lf yq31 = %lf \n\n", xq31, yq31);
#endif

  /* 4) compute k'31 */
  kq31 =
    (xq1 * xq3) +
    (yq1 * yq3) +
    (T31 * (xq1*yq3 - xq3*yq1));
#ifdef DEBUG
  printf ("kq31 = %lf\n", kq31) ;
#endif

  /* 5) compute the denominator D (if D = 0, return with an error) */
  D = fabs(((xq12 - xq23)*(yq23 - yq31)) - ((yq12 - yq23)*(xq23 - xq31)));
  //D = (xq12 - xq23)*(yq23 - yq31) - (yq12 - yq23)*(xq23 - xq31);

#ifdef DEBUG
  printf ("D = %lf\n", D) ;
#endif

  
  if (D < 1) {
    printf ("ERROR, D = 0\n");
    return 1;
  }

  /* 6) compute the robot position */
  xr = x2 + ((kq31 * (yq12 - yq23)) / D );
  yr = y2 + ((kq31 * (xq23 - xq12)) / D );

  printf ("Coordonnees du robot calculée : %lf %lf\nCordonnées réelle : %lf %lf\n" , xr, -(yr - 4), x0, y0);
  printf ("position error ~= %lf\n", 1/D) ;


  return (0) ;
}
