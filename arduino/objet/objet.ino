#include "signal.h"
#include "donne.h"
#include "angle.h"

//#define DEBUG

void setup() {
  Serial.begin(9600);
  
}

/*table des puissances signaux */
int tab[3] = {0,0,0};

/*table des distances de  obj à tag*/
double distTag1 = 1;
double distTag2 = 1;
double distTag3 = 1;

/* angle entre les différents points  */
double a12 = 0;
double a23 = 0;
double a31 = 0;

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

void loop() {

  /*recuperer puissance 1eme balise */
  
  /*recuperer puissance 2eme balise */
  /*Serial.write('2');
  delay(2000);
  tab[1] = puissance();
  Serial.print("tab[1] : ");
  Serial.println(tab[1]);
  delay(1500);
  */
  /*recuperer puissance 3eme balise */


  /* calcul distance */
  /*  distTag1 = convert_p_distance (tab[0]);
  distTag2 = convert_p_distance (tab[1]);
  distTag3 = convert_p_distance (tab[2]);
  */
  
  /* calcul angle  */
  a12 = calcul_angle (distTag1, distTag2, calcul_c (X1, Y1, X2, Y2));
  a23 = calcul_angle (distTag2, distTag3, calcul_c (X2, Y2, X3, Y3));
  a31 = calcul_angle (distTag3, distTag1, calcul_c (X3, Y3, X1, Y1));
						    
  
  
  /* debut de l'algorithme  */

  /* 1) compute the modified beacon coordinates  */
  xq1 = X1 - X2;
  yq1 = Y1 - Y2;
  xq3 = X3 - X2;
  yq3 = Y3 - Y2;

  /* 2) compute the 3 cot(.)   */
  T12 = cot (a12);
  T23 = cot (a23);
  T31 = (1 - (T12 * T23)) / (T12 + T23);

  /* 3) compute the modified circle center coordinates x'ij, y'ij  */
  xq12 = xq1 + (T12 * yq1);
  yq12 = yq1 - (T12 * xq1);

  xq23 = xq3 - (T23 * yq3);
  yq23 = yq3 + (T23 * xq3);
  
  xq31 = (xq3 + xq1) + (T31 * (yq3 - yq1));
  xq31 = (yq3 + yq1) - (T31 * (xq3 - xq1));

  /* 4) compute k'31 */
  kq31 =
    (xq1 * xq3) +
    (yq1 * yq3) +
    (T31 * (xq1*yq3 - xq3*yq1));

  /* 5) compute the denominator D (if D = 0, return with an error) */
  D = (xq12 - xq23)*(yq23 - yq31) - (yq12 - yq23)*(xq23 - xq31);

  if (D == 0) {
    Serial.println ("ERROR, D = 0");
    return ;
  }
  
  /* 6) compute the robot position */
  xr = X2 + ((kq31 * (yq12 - yq23)) / D );
  yr = Y2 + ((kq31 * (xq23 - xq12)) / D );

  
  Serial.print (" Coordonée du robot :");
  Serial.print (xr);
  Serial.print (" ");
  Serial.println (yr);
  

  delay (2000);
}

