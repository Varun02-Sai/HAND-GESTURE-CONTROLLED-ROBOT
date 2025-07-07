#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>




RF24 nrf(9, 8); // CE, CSN
const byte address[6] = {0xAB, 0xCD, 0xAB, 0xCD, 0x01, 0x00};  




// Structure to hold roll and pitch values
struct SensorData {
  float roll;
  float pitch;
  int motorSpeed;
};
const int motorLeftEnablePin = 9;
const int motorLeftForwardPin = 8;
const int motorLeftBackwardPin = 7;
const int motorRightEnablePin = 3;
const int motorRightForwardPin = 2;
const int motorRightBackwardPin = 4;




void setup() {
  Serial.begin(9600);
  nrf.begin();
  nrf.openReadingPipe(1, address);
  nrf.setPALevel(RF24_PA_MAX);
  nrf.startListening();


  pinMode(motorLeftEnablePin, OUTPUT);
  pinMode(motorLeftForwardPin, OUTPUT);
  pinMode(motorLeftBackwardPin, OUTPUT);
  pinMode(motorRightEnablePin, OUTPUT);
  pinMode(motorRightForwardPin, OUTPUT);
  pinMode(motorRightBackwardPin, OUTPUT);
}




void loop() {
  if (nrf.available()) {
    // Create an instance of the SensorData structure
    SensorData sensorData;




    // Read the structure from the radio
    nrf.read(&sensorData, sizeof(sensorData));  
    controlMotors(motorSpeed, roll);  


       // Print the received roll and pitch values
    Serial.print("Roll: ");
    Serial.print(sensorData.roll, 2);  // Display two decimal places
    Serial.print("°   Pitch: ");
    Serial.println(sensorData.pitch, 2);  // Display two decimal places
    Serial.print("motorSpeed : "); 
    Serial.println(motorSpeed); 


    delay(500); // Optional delay to control serial output rate
  }
}


void controlMotors(int speed, float roll ) {
  analogWrite(motorLeftEnablePin, speed);
  digitalWrite(motorLeftForwardPin, (roll > 0) ? HIGH : LOW);
  digitalWrite(motorLeftBackwardPin, (roll < 0) ? HIGH : LOW);


  analogWrite(motorRightEnablePin, speed);
  digitalWrite(motorRightForwardPin, (roll > 0) ? HIGH : LOW);
  digitalWrite(motorRightBackwardPin, (roll < 0) ? HIGH : LOW);
}
