
#define pino_trigger 4
#define pino_echo 5
#define vibe_motor 3 

 
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode(vibe_motor,OUTPUT);
}

void primeiroRitmo() {
  digitalWrite(vibe_motor, HIGH);
  delay(180);
  digitalWrite(vibe_motor, LOW);
  delay(250);    
  }

void segundoRitmo() {
  digitalWrite(vibe_motor, HIGH);
  delay(250);
  digitalWrite(vibe_motor, LOW);
  delay(250);   
  }

void terceiroRitmo() {
  digitalWrite(vibe_motor, HIGH);
  delay(600);
  digitalWrite(vibe_motor, LOW);
  delay(250); 
  }
void ritmoInvasivo() {
    digitalWrite(vibe_motor,HIGH);
   }  
  
 
void loop() {
  
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
 
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print("Distancia em polegadas: ");
  Serial.println(inMsec);
  delay(10);


  if(cmMsec >= 31 && cmMsec <= 40) {
    primeiroRitmo();
    }
  else if (cmMsec >= 21 && cmMsec <= 30) {
    segundoRitmo();   
      }
  else if (cmMsec >= 11 && cmMsec <= 20) {
    terceiroRitmo();
    }   
  else if (cmMsec <= 10) {
    ritmoInvasivo();
    }
  else {
    digitalWrite(vibe_motor,LOW);
    }  
}
