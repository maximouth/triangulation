#include "signal.h"


void setup() {
  Serial.begin(9600);
  
}

/*table des puissances signaux/distances  */
int tab[3] = {0,45,62};


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
  tab [0] = convert (tab[0]);
  Serial.println(tab[0]);


}

