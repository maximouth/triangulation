#define tagNB 'p'

void setup() {
  Serial.begin(9600);
}

void loop() {
  char r;
  if ((r = Serial.read()) == '1') {
        Serial.print('!');
    }
 
  delay (150);
}
