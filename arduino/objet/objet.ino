#include "signal.h"
#include "donne.h"
#include "angle.h"

void setup() {
  Serial.begin(9600);
  
}

/*table des puissances signaux */
int tab[3] = {0,0,0};

/*table des distances de  obj à tag*/
float distTag1 = 0;
float distTag2 = 0;
float distTag3 = 0;

/* angle entre les différents points  */
float angle102 = 0;
float angle203 = 0;
float angle301 = 0;

/* modified beacon coordinate  */
int xq1;
int yq1;

int xq3;
int yq3;

/* the three cot(.)  */
float T12, T23, T31;


void loop() {

  /*recuperer puissance 1eme balise */
  
  /*recuperer puissance 2eme balise */
  Serial.write('2');
  delay(2000);
  tab[0] = puissance();
  Serial.println(tab[0]);
  delay(1500);

  /*recuperer puissance 3eme balise */

  /*convertir puissance en distance*/
  distTag2 = convert (tab[0]);
  Serial.println(tab[0]);

  /* calculer les angles 102 203 301 */
  angle102 = calcul_angle (distTag1, distTag2, (calcul_c (X1, Y1, X2, Y2)));
  angle203 = calcul_angle (distTag2, distTag2, (calcul_c (X2, Y2, X3, Y3)));
  angle301 = calcul_angle (distTag1, distTag2, (calcul_c (X3, Y3, X1, Y1)));
  

  /* debut de l'algorithme  */

  /* 1) compute the modified beacon coordinates: */

  xq1 = X1 - X2;
  yq1 = Y1 - Y2;
  
  xq3 = X3 - X2;
  yq3 = Y3 - Y2;

  /* 2) compute the three cot(.): */

  12 = cot (angle203 - angle102);
  T23 = cot (angle301 - angle203);
  T31 = (1 - (T12*T23)) / (T31 + T23);

  /* 3) compute the modified circle center coordinates {xqij , yqij}  */

  
  
}

