/********************
 * ACTUATOR
 *******************/




int leds[9]={
  13,12,8,7,5,4,3,2,6};
const int RED_PIN=11;
const int  GREEN_PIN=9;
const int  BLUE_PIN=10;
boolean locked=true;
int RGB[3]={
  0,0,0};





void setup() {
  initActuators();
  checkup();

}

void loop() {
  if (Serial.available() > 0) {

    // read the oldest byte in the serial buffer:
    int incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if(locked)
    {
      switch(incomingByte)
      {
      case 'A':
        digitalWrite(leds[0],HIGH);
        break;
      case 'B':
        digitalWrite(leds[1],HIGH);
        break;
      case 'C':
        digitalWrite(leds[2],HIGH);
        break;
      case 'D':
        digitalWrite(leds[3],HIGH);
        break;
      case 'E':
        digitalWrite(leds[4],HIGH);
        break;
      case 'F':
        digitalWrite(leds[5],HIGH);
        break;
      case 'G':
        digitalWrite(leds[6],HIGH);
        break;
      case 'H':
        digitalWrite(leds[7],HIGH);
        break;
      case 'I':
        digitalWrite(leds[8],HIGH);
        break;
        //SPECIAL COMMANDS LOCK STATE TO UNLOCK
      case 'R':
        resetLocked();
        break;
      case 'U':
        for(int i=0;i<9;i++)
        {
          digitalWrite(leds[i],LOW);
        }
        locked=false;
        break;
      }
    }
    else
    {
      switch(incomingByte){
      case 'A':
        if(RGB[0]==0)
        {
          RGB[0]=1;
          digitalWrite(leds[0],HIGH);
          digitalWrite(leds[1],HIGH);
          digitalWrite(leds[2],HIGH);
        }
        else
        {
          RGB[0]=0;
          digitalWrite(leds[0],LOW);
          digitalWrite(leds[1],LOW);
          digitalWrite(leds[2],LOW);
        }
        break;
      case 'B':
        if(RGB[0]==0)
        {
          RGB[0]=1;
          digitalWrite(leds[0],HIGH);
          digitalWrite(leds[1],HIGH);
          digitalWrite(leds[2],HIGH);
        }
        else
        {
          RGB[0]=0;
          digitalWrite(leds[0],LOW);
          digitalWrite(leds[1],LOW);
          digitalWrite(leds[2],LOW);
        }
        break;
      case 'C':
        if(RGB[0]==0)
        {
          RGB[0]=1;
          digitalWrite(leds[0],HIGH);
          digitalWrite(leds[1],HIGH);
          digitalWrite(leds[2],HIGH);
        }
        else
        {
          RGB[0]=0;
          digitalWrite(leds[0],LOW);
          digitalWrite(leds[1],LOW);
          digitalWrite(leds[2],LOW);
        }
        break;
      case 'D':
        if(RGB[1]==0)
        {
          RGB[1]=1;
          digitalWrite(leds[3],HIGH);
          digitalWrite(leds[4],HIGH);
          digitalWrite(leds[5],HIGH);
        }
        else
        {
          RGB[1]=0;
          digitalWrite(leds[3],LOW);
          digitalWrite(leds[4],LOW);
          digitalWrite(leds[5],LOW);
        }
        break;
      case 'E':
        if(RGB[1]==0)
        {
          RGB[1]=1;
          digitalWrite(leds[3],HIGH);
          digitalWrite(leds[4],HIGH);
          digitalWrite(leds[5],HIGH);
        }
        else
        {
          RGB[1]=0;
          digitalWrite(leds[3],LOW);
          digitalWrite(leds[4],LOW);
          digitalWrite(leds[5],LOW);
        }
        break;
      case 'F':
        if(RGB[1]==0)
        {
          RGB[1]=1;
          digitalWrite(leds[3],HIGH);
          digitalWrite(leds[4],HIGH);
          digitalWrite(leds[5],HIGH);
        }
        else
        {
          RGB[1]=0;
          digitalWrite(leds[3],LOW);
          digitalWrite(leds[4],LOW);
          digitalWrite(leds[5],LOW);
        }
        break;
      case 'G':
        if(RGB[2]==0)
        {
          RGB[2]=1;
          digitalWrite(leds[6],HIGH);
          digitalWrite(leds[7],HIGH);
          digitalWrite(leds[8],HIGH);
        }
        else
        {
          RGB[2]=0;
          digitalWrite(leds[6],LOW);
          digitalWrite(leds[7],LOW);
          digitalWrite(leds[8],LOW);
        }
        break;
      case 'H':
        if(RGB[2]==0)
        {
          RGB[2]=1;
          digitalWrite(leds[6],HIGH);
          digitalWrite(leds[7],HIGH);
          digitalWrite(leds[8],HIGH);
        }
        else
        {
          RGB[2]=0;
          digitalWrite(leds[6],LOW);
          digitalWrite(leds[7],LOW);
          digitalWrite(leds[8],LOW);
        }
        break;
      case 'I':
        if(RGB[2]==0)
        {
          RGB[2]=1;
          digitalWrite(leds[6],HIGH);
          digitalWrite(leds[7],HIGH);
          digitalWrite(leds[8],HIGH);
        }
        else
        {
          RGB[2]=0;
          digitalWrite(leds[6],LOW);
          digitalWrite(leds[7],LOW);
          digitalWrite(leds[8],LOW);
        }
        break;
      case 'O':
        locked=true;
        off();
        break;
      }
      analogWrite(RED_PIN,RGB[0]*255);
      analogWrite(GREEN_PIN,RGB[1]*255);
      analogWrite(BLUE_PIN,RGB[2]*255);

    }
  }
}

void resetLocked()
{
  for(int h=0;h<3;h++){

    for(int i=0;i<9;i++)
    {
      digitalWrite(leds[i],HIGH);
    }
    delay(300);
    for(int i=0;i<9;i++)
    {
      digitalWrite(leds[i],LOW);
    }
    delay(300);
  }


}


void initActuators()
{
  Serial.begin(9600);

  for(int i=0;i<9;i++)
  {
    pinMode(leds[i],OUTPUT);
  }
  analogWrite(RED_PIN,0);
  analogWrite(GREEN_PIN,0);
  analogWrite(BLUE_PIN,0);

}

void off()
{

  for(int i=0;i<9;i++)
  {
    digitalWrite(leds[i],LOW);
    delay(10);
  }
  RGB[0]=0;
  RGB[1]=0;
  RGB[2]=0;
  analogWrite(RED_PIN,0);
  analogWrite(GREEN_PIN,0);
  analogWrite(BLUE_PIN,0);
  delay(10);
}

void checkup()
{
  digitalWrite(leds[0],HIGH);
  delay(2500);
  for(int i=0;i<9;i++)
  {
    digitalWrite(leds[i],HIGH);
    delay(250);
    digitalWrite(leds[i],LOW);
    delay(10);
  }



  analogWrite(RED_PIN,255);
  delay(1000);
  analogWrite(RED_PIN,0);
  analogWrite(GREEN_PIN,255);
  delay(1000);
  analogWrite(GREEN_PIN,0);
  analogWrite(BLUE_PIN,255);
  delay(1000);
  analogWrite(BLUE_PIN,0);


}











