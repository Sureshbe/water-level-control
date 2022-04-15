void setup() {
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(9,LOW);
  delayMicroseconds(2);
  digitalWrite(9,HIGH);
  delayMicroseconds(10);
  digitalWrite(9,LOW);

  int t=pulseIn(8,HIGH);
  Serial.println("WATER EVAPORATING.............");
  Serial.println("");

  int d=(0.0001)*(t/2)*343;
  delay(1000);
  if(d<=3){
    digitalWrite(13,LOW);
    Serial.println("Low level of water in the container");
    Serial.println("Motor turn ON");
    Serial.println("");
  }
  if(d>=50){
    digitalWrite(13,HIGH);
    Serial.println("Container is full");
    Serial.println("Motor turn OFF");
    Serial.println("Desalination started");
    Serial.println("");
  }
}
