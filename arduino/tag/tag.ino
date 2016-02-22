#define tagNB '1'

void setup() {
  Serial.begin(9600);
}

void loop() {
  /* si il y a quelque chose à lire */
  if (Serial.available() > 1) {
    char r = Serial.read();
    /* si on s'adresse bien à nous */
    if (r == tagNB)
      Serial.println(tagNB);
  }
  
}
