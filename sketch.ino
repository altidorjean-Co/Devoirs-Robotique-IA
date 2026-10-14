const int pinTrig = 12;
const int pinEcho = 13;
const int pinLed = 2;
const int pinBuzzer = 14;

// Seuil de décision intelligente : 50 cm
const int seuilDistance = 50; 

void setup() {
  Serial.begin(115200);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  
  Serial.println("Système de Décision IA Initialisé.");
}

void loop() {
  // Envoi de l'impulsion ultrason
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  
  // Calcul de la distance
  long duree = pulseIn(pinEcho, HIGH);
  int distance = duree * 0.034 / 2;
  
  Serial.print("Distance mesurée : ");
  Serial.print(distance);
  Serial.println(" cm");

  // Logique de décision intelligente (Seuil)
  if (distance > 0 && distance < seuilDistance) {
    Serial.println("🚨 ALERTE : Objet trop proche ! Décision -> Activation");
    digitalWrite(pinLed, HIGH);
    tone(pinBuzzer, 1000); // Sonne à 1kHz
  } else {
    digitalWrite(pinLed, LOW);
    noTone(pinBuzzer);
  }
  
  delay(200); // Scan toutes les 200ms
}