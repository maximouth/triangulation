#define pwmA (3)
#define pwmB (11)

#define dirA (12)
#define dirB (13)

#define brkA (9)
#define brkB (8)

#define encoderA1 (48)
#define encoderA2 (49)
#define encoderB1 (30)
#define encoderB2 (31)

#define diametre (0.042*3.14)

volatile int cptA = 0;
volatile int cptB = 0;

int test = 0;

void setup () {
  cptA = 0;
  cptB = 0;
  test = 0;

  
  //Serial.begin (9600);
  
  /* Set pins for both directions and brakes as outputs. */
  pinMode (pwmA, OUTPUT) ;
  pinMode (pwmB, OUTPUT) ;
  pinMode (dirA, OUTPUT) ;
  pinMode (dirB, OUTPUT) ;
  pinMode (brkA, OUTPUT) ;
  pinMode (brkB, OUTPUT) ;

  /* Set the encoder wheel pins as inputs  */
  pinMode (encoderA1, INPUT) ;
  pinMode (encoderA2, INPUT) ;
  pinMode (encoderB1, INPUT) ;
  pinMode (encoderB2, INPUT) ;
  
  /* attacher interruptions aux encodeurs de s roues  */
  attachInterrupt(digitalPinToInterrupt(encoderA1), countA, RISING);
  attachInterrupt(digitalPinToInterrupt(encoderA2), countA, RISING); 
  attachInterrupt(digitalPinToInterrupt(encoderB1), countB, RISING);
  attachInterrupt(digitalPinToInterrupt(encoderB2), countB, RISING); 

  /* demarrer les moteurs */
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);

  /* lacher les freins  */
  digitalWrite(brkA, LOW);
  digitalWrite(brkB, LOW);

  /* laisser les moteurs a l'arret  */
  analogWrite (pwmA, 0);
  analogWrite (pwmB, 0);


}

/* fonction pour 'linterruprion de la roue gauche  */
void countA () {
  cptA ++;
  return;
}

/* fonction pour 'linterruprion de la roue droite  */
void countB () {
  cptB ++;
  return;
}


void loop () {
  /* distaznce parcouru par les roues droite et gauche  */
  double dl = 0, dr = 0;

  /* laisser 2 secondes avant de demarrer les moteurs  */
  if (test == 0) {
    delay(2000);
    analogWrite (pwmA, 250);
    analogWrite (pwmB, 250);
    test = 1;
  }

  /* calculer lse distances parcourus par les deux roues  */
  dl = (cptA/24) * diametre;
  dr = (cptB/24) * diametre;

  /* s'arreter si on à parcouru 1 metre  */
  if ( ((dl + dr)  / 2.0) >= 1.0) {
    analogWrite(pwmA, 0);
    analogWrite(pwmB, 0);
  }
  
}

