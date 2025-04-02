#include <IRremote.h>

//IR port
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

//Tlacitka
const int RECT_PIN_T_BY = 1;
const int RECT_PIN_T_KU = 2;
const int RECT_PIN_T_KN = 3;

//relatka
const int bylinkyPin = 10;
const int kuchynPin = 11;
const int knihovnaPin = 12;

volatile byte relayState = LOW;


void setup(){
  //IR setup
  irrecv.enableIRIn();
  irrecv.blink13(true);

  // RELE setup
  pinMode(bylinkyPin, OUTPUT);
  digitalWrite(bylinkyPin, LOW);
  
  pinMode(kuchynPin, OUTPUT);
  digitalWrite(kuchynPin, LOW);
  
  pinMode(knihovnaPin, OUTPUT);
  digitalWrite(knihovnaPin, LOW);

//tlacitka setup
  pinMode(RECT_PIN_T_BY, INPUT);
  //digitalWrite(RECT_PIN_T_BY, HIGH);

  pinMode(RECT_PIN_T_KU, INPUT);
  //digitalWrite(RECT_PIN_T_KU, HIGH);

  pinMode(RECT_PIN_T_KN, INPUT);
  //digitalWrite(RECT_PIN_T_KN, HIGH);
}

void loop(){
    if (irrecv.decode(&results)){

        switch(results.value){
          case 0xFF30CF: //Keypad button "1"
          //analogWrite(bylinkyPin, HIGH);
          //int currState = 
          //delay(2000);
          //digitalWrite(bylinkyPin, LOW);
          if (digitalRead(bylinkyPin) == LOW){
            digitalWrite(bylinkyPin, HIGH);
          } else {
            digitalWrite(bylinkyPin, LOW);
          }
          }

        switch(results.value){
          case 0xFF18E7: //Keypad button "2"
          //digitalWrite(kuchynPin, HIGH);
          //delay(2000);
          //digitalWrite(kuchynPin, LOW);
          if (digitalRead(kuchynPin) == LOW){
              digitalWrite(kuchynPin, HIGH);
          } else {
              digitalWrite(kuchynPin, LOW);
          }
          
          }

        switch(results.value){
          case 0xFF7A85: //Keypad button "3"
          //digitalWrite(knihovnaPin, HIGH);
          //delay(2000);
          //digitalWrite(knihovnaPin, LOW);
          if (digitalRead(knihovnaPin) == LOW){
              digitalWrite(knihovnaPin, HIGH);
          } else {
              digitalWrite(knihovnaPin, LOW);
          }
          }
                      irrecv.resume(); 
      }

  
      //tlacitka 
       //TbylStat = digitalRead(RECT_PIN_T_BY);
       //RbylStat = digitalRead(bylinkyPin);

      //  if (digitalRead(RECT_PIN_T_BY) == HIGH && digitalRead(bylinkyPin) == HIGH){
      //    digitalWrite(bylinkyPin, LOW);
      //  } else {
      //    digitalWrite(bylinkyPin, HIGH);
      //  }
      

      //TKuchStat = digitalRead(RECT_PIN_T_KU);
      //RKuchStat = digitalRead(kuchynPin);
       
      //  if (digitalRead(RECT_PIN_T_KU) == HIGH && digitalRead(kuchynPin) == HIGH){
      //    digitalWrite(kuchynPin, LOW);
      //  } else {
      //    digitalWrite(kuchynPin, HIGH);
      //  }
      

      //TKnihStat = digitalRead(RECT_PIN_T_KN);
      //RKnihStat = digitalRead(knihovnaPin);
      //  if (digitalRead(RECT_PIN_T_KN) == HIGH && digitalRead(knihovnaPin) == HIGH){
     //     digitalWrite(knihovnaPin, LOW);
     //   } else {
     //     digitalWrite(knihovnaPin, HIGH);
        }
      


//}
