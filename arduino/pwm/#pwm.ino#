#include "signal.h"
#include "donne.h"
#include "angle.h"

//#define DEBUG
#define PIN (6)
void setup() {
  pinMode (PIN, INPUT);
  Serial.begin(9600);
  
}

int rssi = 0;

/*table des puissances signaux */
int tab1[3] = {0,0,0};
int tab2[3] = {0,0,0};
int tab3[3] = {0,0,0};
double tab[3] = {0,0,0}; 

/*table des distances de  obj à tag*/
double distTag1 = 5;
double distTag2 = 4.242640;
double distTag3 = 3;

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

  while (Serial.available() > 0) {
    Serial.read();
  }
  
  /*recuperer puissance 1eme balise */
  Serial.write('1');
  Serial.write('\r');
  delay(500);
  tab1[0] = pulseIn(PIN, LOW, 200);
  Serial.write('1');
  Serial.write('\r');
  delay(500);
  tab1[1] = pulseIn(PIN, LOW, 200);
  Serial.write('1');
  Serial.write('\r');
  delay(500);
  tab1[2] = pulseIn(PIN, LOW, 200);
  tab[0] = (tab1[0] + tab1[1] + tab1[2]) / 3;
  //Serial.print("tab[0] : ");
  Serial.println(tab[0]);

    /*recuperer puissance 2eme balise */
  Serial.write('2');
  Serial.write('\r');
  delay(250);
  tab2[0] = pulseIn(PIN, LOW, 200);
  Serial.write('2');
  Serial.write('\r');
  delay(250);
  tab2[1] = pulseIn(PIN, LOW, 200);
  Serial.write('2');
  Serial.write('\r');
  delay(250);
  tab2[2] = pulseIn(PIN, LOW, 200);
  tab[1] = (tab2[0] + tab2[1] + tab2[2]) / 3;
  //Serial.print("tab[1] : ");
  Serial.println(tab[1]);

    /*recuperer puissance 3eme balise */
  Serial.write('3');
  Serial.write('\r');
  delay(500);
  tab3[0] = pulseIn(PIN, LOW, 200);
  Serial.write('3');
  Serial.write('\r');
  delay(250);
  tab3[1] = pulseIn(PIN, LOW, 200);
  Serial.write('3');
  Serial.write('\r');
  delay(250);
  tab3[2] = pulseIn(PIN, LOW, 200);
  tab[2] = (tab3[0] + tab3[1] + tab3[2]) / 3;
  //Serial.print("tab[2] : ");
  Serial.println(tab[2]);


  /* calcul distance */
  distTag1 = convert_p_distance (tab[0]);
  distTag2 = convert_p_distance (tab[1]);
  distTag3 = convert_p_distance (tab[2]);
  
  
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
#ifdef DEBUG
  Serial.print ("xq1 = %lf yq1 = %lf xq3 = %lf yq3 = %lf\n", xq1, yq1, xq3, yq3) ;
#endif

  /* 2) compute the 3 cot(.)   */
  T12 = cot (a12);
  T23 = cot (a23);  
  T31 = cot (a31); 
  
#ifdef DEBUG
  Serial.print ("T12 = %lf T23 = %lf T31 = %lf \n", T12, T23, T31) ;
#endif
  
  /* 3) compute the modified circle center coordinates x'ij, y'ij  */
  xq12 = xq1 + (T12 * yq1);
  yq12 = yq1 - (T12 * xq1);

#ifdef DEBUG
  Serial.printf ("xq12 = %lf yq12 = %lf \n", xq12, yq12);
#endif
  
  xq23 = xq3 - (T23 * yq3);
  yq23 = yq3 + (T23 * xq3);

#ifdef DEBUG
  Serial.print ("xq23 = %lf yq23 = %lf \n", xq23, yq23);
#endif

  xq31 = (xq3 + xq1) + (T31 * (yq3 - yq1));
  yq31 = (yq3 + yq1) - (T31 * (xq3 - xq1));
  
#ifdef DEBUG
  Serial.print ("xq31 = %lf yq31 = %lf \n\n", xq31, yq31);
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
  D = (xq12 - xq23)*(yq23 - yq31) - (yq12 - yq23)*(xq23 - xq31);

#ifdef DEBUG
  Serial
    Serial.print ("D = %lf\n", D) ;
#endif
  
  if (D == 0) {
    printf ("ERROR, D = 0\n");
    exit (1);
  }

  /* 6) compute the robot position */
  xr = (kq31*(1/D)) * (yq12 - yq23) + X2 ;
  yr = (kq31*(1/D)) * (xq23 - xq12) + Y2 ;

#ifdef DEBUG
  Serial.print ("Coordonnees du robot calculée : %lf %lf\nCordonnées réelle : %lf %lf\n" , xr, yr , x0, y0);
  Serial.print ("position error ~= %lf\n", 1/D) ;
#endif
  
  //Serial.print (" Coordonée du robot :");
  Serial.print (xr);
  delay (20);
  Serial.print (" ");
  delay (20);
  Serial.println (yr);
  

  delay (2000);
}

