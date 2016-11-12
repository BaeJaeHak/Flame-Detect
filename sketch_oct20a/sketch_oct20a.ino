int lPin = 13;
int iP = 2;
int value  = LOW;
int val = 0;           
int Speaker = 10;

void setup() {
  pinMode(lPin, OUTPUT);      
  pinMode(iP, INPUT);     
  pinMode(Speaker, OUTPUT); 
  Serial.begin(9600); 
}

void loop() {
  val = digitalRead(iP);  
  if (val == HIGH) {            
    digitalWrite(lPin, HIGH);  
    playTone(0, 0);
    delay(500);
    if (value == LOW) {
      Serial.println("Can't find Fire");
      value = HIGH;
            }
     }
    else {
    digitalWrite(lPin, LOW); 
    playTone(300, 150);
    delay(30);    
    if (value== HIGH) {
      Serial.println("It's burnning. Escape Hurry Up!!!");
      value = LOW;
    }
  }
}
 
void playTone(long d, int s) {
  d *= 1000;
  int period = (2.0 / s) * 10000;
  long gone_time = 0;
  while (gone_time < d) {
    digitalWrite(Speaker,HIGH);
    delay(period / 2);
    digitalWrite(Speaker, LOW);
    delay(period / 2);
    gone_time += (period);
  }
}
