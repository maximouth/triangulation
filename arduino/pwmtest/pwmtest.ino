#define PIN (10)

void setup() {
  pinMode (PIN, INPUT);
  Serial.begin(9600);
}

int rssi = 9;

void loop () {

  Serial.println (Serial.read());
  rssi = pulseIn(PIN, HIGH, 200);
  Serial.println(rssi);
  delay(3000);
  

}
