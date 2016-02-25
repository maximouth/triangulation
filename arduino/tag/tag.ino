#define tagNB 'p'

void setup() {
  Serial.begin(9600);
}

void loop() {
  char r;

  /* si il y a quelque chose à lire */
  while (Serial.available() >= 1) {
    if ((r = Serial.read()) == '?') {
      Serial.print('!');
    }
  }

  delay (1000);
}
