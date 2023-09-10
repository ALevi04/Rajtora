void timeChipInit(){
  Wire.begin();
  pinMode(1,INPUT_PULLUP);

  Wire.beginTransmission(0x68); // address DS3231
  Wire.write(0x0E); // select register
  Wire.write(0b00000000); // write register 
  Wire.endTransmission();
  }
