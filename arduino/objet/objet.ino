#include "signal.h"
#include "donne.h"
#include "angle.h"

#define DEBUG

void setup() {
  Serial.begin(9600);
  
}

/*table des puissances signaux */
int tab[3] = {0,0,0};

/*table des distances de  obj à tag*/
float distTag1 = 7.07;
float distTag2 = 5;
float distTag3 = 5;

/* angle entre les différents points  */
float angle102 = 0;
float angle203 = 0;
float angle301 = 0;

/* robot position */
float xr = 0;
float yr = 0;

void loop() {

  /*recuperer puissance 1eme balise */
  
  /*recuperer puissance 2eme balise */
  /*  Serial.write('2');
  delay(2000);
  tab[0] = puissance();
  Serial.println(tab[0]);
  delay(1500);
  */
  /*recuperer puissance 3eme balise */

  /*convertir puissance en distance*/
  /*distTag2 = convert (tab[0]);
  Serial.println(tab[0]);
  */
  /* calculer les angles 102 203 301 */
  angle102 = calcul_angle (distTag1, distTag2, (calcul_c (X1, Y1, X2, Y2)));
  angle203 = calcul_angle (distTag2, distTag3, (calcul_c (X2, Y2, X3, Y3)));
  angle301 = calcul_angle (distTag3, distTag1, (calcul_c (X3, Y3, X1, Y1)));


#ifdef DEBUG
  Serial.print ("angle :");
  Serial.print (angle102);
  Serial.print (" ");
  Serial.print (angle203);
  Serial.print (" ");
  Serial.println (angle301);
#endif

  /* debut de l'algorithme  */
  Serial.print (" Coordonée du robot :");
  Serial.print (xr);
  Serial.print (" ");
  Serial.println (yr);


  delay (2000);
}

