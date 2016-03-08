#include "Arduino.h"

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



float convert_p_distance (int n) {
  float res = -0.30228*(n-5.42495) + 0.006695* n*n; 
  if (res < 0) {
    return 0;
  }
  return res;
}
