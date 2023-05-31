#include "Adafruit_VL53L0X.h"

#define vibe_motor 4

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
Serial.begin(9600);

// wait until serial port opens for native USB devices
while (! Serial) {
delay(1);
}

Serial.println("Adafruit VL53L0X test");
if (!lox.begin()) {
Serial.println(F("Failed to boot VL53L0X"));
while(1);
}
// power
Serial.println(F("VL53L0X API Simple Ranging example\n\n"));

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
delay(350);
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
VL53L0X_RangingMeasurementData_t measure;

Serial.print("Reading a measurement... ");
lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

if (measure.RangeStatus != 4) {  // phase failures have incorrect data
Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
} else {
Serial.println(" out of range ");
}

delay(100);

if(measure.RangeMilliMeter >= 750 && measure.RangeMilliMeter <= 1000) {
primeiroRitmo();
}
else if (measure.RangeMilliMeter >= 500 && measure.RangeMilliMeter <= 750) {
segundoRitmo();
}
else if (measure.RangeMilliMeter >= 250 && measure.RangeMilliMeter <= 500) {
terceiroRitmo();
}
else if (measure.RangeMilliMeter <= 250) {
ritmoInvasivo();
}
else {
digitalWrite(vibe_motor,LOW);
}
}
