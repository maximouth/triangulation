
void setup() {
  Serial.begin(9600);
  
}


int tab[3] = {0,0,0};


void loop() {

  //chercher tag 1
     Serial.write('1');
    delay(2000);
    tab[0] = puissance();
     Serial.println(tab[0]);
    delay(1500);
  
  /*//chercher tag 2
  Serial.write('2');
  delay(2000);
  while (t[1] = 0) {
    tab[1] = puissance();
  }
  Serial.println(tab[2]);
  delay(1500);

    //chercher tag 3
  Serial.write('3');
  delay(2000);
  while (t[2] = 0) {
    tab[2] = puissance();
  }
  Serial.println(tab[2]);
  delay(1500);
  */
  
}

int puissance() {
  char byte =0;
  int hex1 = 0, hex2 = 0;
  Serial.flush();
  
  Serial.write('+++');
  Serial.write('+++');
  Serial.write('+++');
  delay(3000);

  Serial.write('a');
  Serial.write('t');
  Serial.write('d');
  Serial.write('b');
  Serial.write('\r');
  delay(3000);
 
  delay(1000);
  
  while (Serial.available() > 0) {
    hex1 = Serial.read();
    hex2 = Serial.read();
    Serial.read();
  }

  Serial.print(" hex1 ");
  Serial.println(hex1);
  Serial.print(" hex2 ");
  Serial.println(hex2);
  
  return asci_to_int(hex1, hex2);
}

int asci_to_int(char a, char b) {
  int c = asci(a);
  int d = asci(b);

  Serial.print(" hex1 ");
  Serial.println(c);
  Serial.print(" hex2 ");
  Serial.println(d);

  
  return (16 * c)+ d;
  
}

int asci (char c) {
  switch (c) {
  case 49 :
    return 1;
    break;
  case 50 :
    return 2;
    break;
  case 51 :
    return 3;
    break;
  case 52 :
    return 4;
    break;
  case 53 :
    return 5;
    break;
  case 54 :
    return 6;
    break;
  case 55 :
    return 7;
    break;
  case 56 :
    return 8;
    break;
  case 57 :
    return 9;
    break;
  case 65 :
    return 10;
    break;
  case 66 :
    return 11;
    break;
  case 67 :
    return 12;
    break;
  case 68 :
    return 13;
    break;
  case 69 :
    return 14;
    break;
  case 70 :
    return 15;
    break;
    
  default :
    return 0;
    
  }
    

}
