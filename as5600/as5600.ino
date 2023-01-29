#include <Wire.h>
#define AS5600_ADDR 0x36
#define AS5600_STATUS 0x0B
#define AS5600_ANGLE 0x0E
#define AS5600_GAIN 0x1A
 
void setup()
{
  Wire.begin();
  Serial.begin(115200);
}
 
 
void loop()
{
  /*Wire.beginTransmission(AS5600_ADDR);
  Wire.write(AS5600_STATUS);
  Wire.endTransmission();

  Wire.requestFrom(AS5600_ADDR, 1);
  Serial.println(Wire.read()>>3,BIN);
  Wire.endTransmission();

  Wire.beginTransmission(AS5600_ADDR);
  Wire.write(AS5600_GAIN);
  Wire.endTransmission();

  Wire.requestFrom(AS5600_ADDR, 1);
  Serial.println(Wire.read());
  Wire.endTransmission();*/

  Wire.beginTransmission(AS5600_ADDR);
  Wire.write(AS5600_ANGLE);
  Wire.endTransmission();

  Wire.requestFrom(AS5600_ADDR, 2);
  uint16_t ang = Wire.read()*256;
  ang+= Wire.read();
  Serial.println(ang/4096.0*360.0);
  Wire.endTransmission();

  delay(100);
}