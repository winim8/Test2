int GreenLed_Pin = 2;
int RedLed_Pin = 3; 
int Btn_Pin =11; 
int Buzzer_Pin = 13;

int hand_Pin = A1;
int hand_Val;
int hand_Now;
void setup() {
  pinMode(GreenLed_Pin,OUTPUT);
  pinMode(RedLed_Pin,OUTPUT);
  pinMode(Buzzer_Pin,OUTPUT);
  pinMode(Btn_Pin,INPUT);
  Serial.begin(9600);
}
//판단대기 시간동안 LED및 대기음 발생시키는 함수
void sign(int num){ 
  for(int i = 0;i<num; i++){
        digitalWrite(RedLed_Pin,LOW);
        digitalWrite(GreenLed_Pin,HIGH);
        tone(Buzzer_Pin,300*i);
          delay(500);
        noTone(Buzzer_Pin);
        digitalWrite(RedLed_Pin,HIGH);
        digitalWrite(GreenLed_Pin,LOW);
         delay(500);
  }
}
void loop() {
     if(digitalRead(Btn_Pin) != 0){ //질문하고 버튼을 누름.
        hand_Val = analogRead(A1); 
        digitalWrite(RedLed_Pin,HIGH);
        digitalWrite(GreenLed_Pin,HIGH);
        Serial.print("Check!! handVal: ");
        Serial.println(hand_Val);
          delay(500);
        sign(5); //5초동안 판단
        digitalWrite(RedLed_Pin,LOW);
        digitalWrite(GreenLed_Pin,LOW);
          delay(500);
         hand_Now = analogRead(A1);
      if(hand_Val >  hand_Now+10){ //거짓(기준치에서 10이상으로 떨어지면)
        digitalWrite(RedLed_Pin,HIGH);
        Serial.print("Lier!! handNow: ");
        Serial.println( hand_Now);
        tone(Buzzer_Pin,1000);
      }else{ //진실
        digitalWrite(GreenLed_Pin,HIGH);
        Serial.print("TRUE!! handNow: ");
        Serial.println( hand_Now);
        delay(1000);
      }
       delay(1000);
    }           
        digitalWrite(RedLed_Pin,LOW);
        digitalWrite(GreenLed_Pin,LOW);
        noTone(Buzzer_Pin);  
}


  

