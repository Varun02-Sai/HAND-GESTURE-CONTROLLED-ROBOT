#include <SPI.h>
#include <RF24.h>
#include <Wire.h>
#include <MPU6050.h>


MPU6050 mpu;


RF24 radio(9, 8); // CE, CSN
const byte address[6] = {0xAB, 0xCD, 0xAB, 0xCD, 0x01, 0x00};


// Structure to hold roll and pitch values
struct SensorData {
  float roll;
  float pitch;
  int motorSpeed:
};


void setup() {
  Serial.begin(9600);
  Wire.begin();
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  mpu.initialize();
}


void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);


  // Convert raw values to degrees per second for gyroscope
  float gx_deg = gx / 131.0;
  float gy_deg = gy / 131.0;
  float gz_deg = gz / 131.0;


  // Convert raw values to G for accelerometer
  float ax_g = ax / 16384.0;
  float ay_g = ay / 16384.0;
  float az_g = az / 16384.0;


  // Calculate tilt angles using accelerometer data
  float roll = atan2(-ay_g, az_g) * 180.0 / PI;
  float pitch = atan2(ax_g, sqrt(ay_g * ay_g + az_g * az_g)) * 180.0 / PI;


  // Normalize angles to the range [-180, 180)
  roll = fmod(roll + 180, 360) - 180;
  pitch = fmod(pitch + 180, 360) - 180;


  // Reverse the direction of rotation for the roll angle
  roll *= -1;


  int motorSpeed: 


  if (abs(roll) < 0) {
   motorSpeed = map(abs(roll), 0, 80, 0, 255);
  }  else {
    motorSpeed = 255;
   }
  // Create a structure and populate it with roll and pitch values
  SensorData sensorData;
  sensorData.roll = roll;
  sensorData.pitch = pitch;
  sensorData.motorSpeed = motorSpeed;


  // Print the results
  Serial.print("Roll: ");
  Serial.print(roll, 2);  // Display two decimal places
  Serial.print("°   Pitch: ");
  Serial.print(pitch, 2);  // Display two decimal places
  Serial.println("°");
  Serial.print("motorSpeed : "); 
  Serial.println(motorSpeed);  // Display two decimal places
  


  // Transmit both roll and pitch values
  radio.write(&sensorData, sizeof(sensorData));


  delay(500); // Adjust the delay as needed
}
