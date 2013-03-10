#include <Servo.h>

/********************
 * SENSORS
 *******************/
 
 
Servo gecko;
const int sensors[9]={
  4,5,6,7,8,9,10,11,12};
const int comandos[9]={
  'A','B','C','D','E','F', 'G', 'H', 'I'};
int old_valueSensors[9];
int valueSensors = LOW;
const int ledTest = 13;
int counter = 0;
int offCounter = 0;

boolean lock = true;

int code[4] = {
  'C', 'I', 'H', 'D'};
int codeStore[4];

boolean correct = true;

int touchedCutoff = 30;



void setup(){
  Serial.begin(9600);
  initSensors();
  gecko.attach(3);
  gecko.write(0);
  delay(1000);
  gecko.write(90);
}

void loop(){

  for(int i=0; i<9; i++){
    valueSensors = readCapacitivePin(sensors[i]); 

    if(valueSensors>touchedCutoff)
    {
      valueSensors=HIGH;
    }
    else
    {
      valueSensors=LOW;
    }

    if((valueSensors == HIGH) && (!lock)){
      offCounter++;
    }
    if ((valueSensors == HIGH) && (old_valueSensors[i] == LOW)){
      digitalWrite(ledTest, HIGH);
      Serial.write(comandos[i]);


      if(lock){
        codeStore[counter] = comandos[i];
        counter++;
        if (counter == 4){
          old_valueSensors[i] = valueSensors;  
          break;
        }
      } 

    }  

    if ((valueSensors == LOW) && (old_valueSensors[i] == HIGH)){
      digitalWrite(ledTest, LOW);
    }
    old_valueSensors[i] = valueSensors;  
  }


  if (lock){
    if(counter == 4){
      correct = true;
      for (int i=0; i<4; i++){
        if(codeStore[i] != code[i]){
          correct = false;
          break;
        } 
      }

      if (correct){
        gecko.write(30);
        delay(50);
        gecko.write(0);
        delay(50);


        
        Serial.write('U');
        lock = false;
      }
      else{
        Serial.write('R');
      }

      counter = 0;
    }
  } 
  else{
    if (offCounter > 3){
      Serial.write('O');
      lock = true;
    }
    offCounter=0;

  }
  delay(500);


}

void initSensors(){

  for(int i=0; i<9; i++){
    //pinMode(sensors[i], INPUT);
    old_valueSensors[i] = LOW;
  }

  pinMode(ledTest, OUTPUT);


}

















