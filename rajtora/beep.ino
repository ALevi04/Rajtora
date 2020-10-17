int beep = 0;
int jackInput =A0;
int freq = 500;
int freqJack = 2500;
int isJack =A1;
void beepInit() {
  pinMode(beep, OUTPUT);
  noTone(beep);
  digitalWrite(beep,LOW);
  pinMode(jackInput,OUTPUT);
  pinMode(isJack, INPUT_PULLUP);
}

void beepShort() {
int courFreq;
int courPort;
if(digitalRead(isJack)== 0){
 courFreq =freq;
 courPort = beep; 
  }
  else{
 courFreq =freqJack;
 courPort = jackInput;    
    }
 tone(courPort,courFreq);
delay(300);
noTone(courPort);
}

void beepLong() {
int courFreq;
int courPort;
if(digitalRead(isJack)== 0){
 courFreq =freq;
 courPort = beep; 
  }
  else{
 courFreq =freqJack;
 courPort = jackInput;    
    }
 tone(courPort,courFreq);
delay(800);
noTone(courPort);}

void beepBtn(){
   tone(beep,500);
delay(100);
noTone(beep);
  }
