#include "Arduino.h"

char get_byte_ignore ()
{
  char c = '!' ;
  while (c == '!' | c == '\r' | c == 'O' | c == 'K' | c == '\n'){
    c = Serial.read();
  }
  return (c) ;
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
    //    Serial.write ("lu : ");
    //    Serial.write (c);
    return 0;
    
  }
}


int puissance() {
  int hex1 = 0, hex2 = 0;

  /*Enter to command mode*/
  Serial.write('+');
  Serial.write('+');
  Serial.write('+');
  delay(2000);

  /*Ignore response*/
  get_byte_ignore ();
  get_byte_ignore ();
  get_byte_ignore ();  
  
  
  /*Ask for signal power*/
  Serial.write('a');
  Serial.write('t');
  Serial.write('d');
  Serial.write('b');
  Serial.write('\r');
  delay(2000);
  
  /*Read response*/
  hex1 = get_byte_ignore ();  
  hex2 = get_byte_ignore ();  
  //get_byte_ignore (); 
  
  /*Exit command mode*/
  Serial.write('a');
  Serial.write('t');
  Serial.write('c');
  Serial.write('n');
  Serial.write('\r');
  delay(2000);
  
  /*Ignore response*/
  get_byte_ignore ();
  get_byte_ignore ();
  get_byte_ignore ();  
  
  return (16 * asci(hex1)) + asci(hex2);
}


float convert_p_distance (int n) {
   float res = (0.7844938) * (n - 17.630182) + (- 0.0086405 * n * n);


  if (res < 0) {
    return 0;
  }
  return res;
}
