int LeftMotorSpeedPin = 5;
int RightMotorSpeedPin = 6;
int LeftMotorDirectionPin = 4;
int RightMotorDirectionPin = 7;

void stop(void)
{
  digitalWrite(LeftMotorSpeedPin, 0);   
  digitalWrite(RightMotorSpeedPin, 0);      
}   

void forward(char leftMotorSpeed, char rightMotorSpeed)
{
  analogWrite(LeftMotorSpeedPin, leftMotorSpeed);
  digitalWrite(LeftMotorDirectionPin, HIGH);    
  analogWrite(RightMotorSpeedPin, rightMotorSpeed);    
  digitalWrite(RightMotorDirectionPin, HIGH);
}  

void backward(char leftMotorSpeed, char rightMotorSpeed)    
{
  analogWrite(LeftMotorSpeedPin, leftMotorSpeed);
  digitalWrite(LeftMotorDirectionPin, LOW);   
  analogWrite(RightMotorSpeedPin, rightMotorSpeed);    
  digitalWrite(RightMotorDirectionPin, LOW);
}

void left(char leftMotorSpeed, char rightMotorSpeed)
{
  analogWrite(LeftMotorSpeedPin, leftMotorSpeed);
  digitalWrite(LeftMotorDirectionPin, HIGH);   
  analogWrite(RightMotorSpeedPin, rightMotorSpeed);    
  digitalWrite(RightMotorDirectionPin, LOW);
}

void right(char leftMotorSpeed, char rightMotorSpeed)
{
  analogWrite(LeftMotorSpeedPin, leftMotorSpeed);
  digitalWrite(LeftMotorDirectionPin, LOW);   
  analogWrite(RightMotorSpeedPin, rightMotorSpeed);    
  digitalWrite(RightMotorDirectionPin, HIGH);
}

void setupMotors(void)
{
  pinMode(LeftMotorSpeedPin, OUTPUT);
  pinMode(LeftMotorDirectionPin, OUTPUT);
  pinMode(RightMotorSpeedPin, OUTPUT);
  pinMode(RightMotorDirectionPin, OUTPUT);
}

void setupLCD(void)
{
}

void setup(void) 
{ 
  setupMotors();
  setupLCD();
  Serial.begin(19200);      //Set Baud Rate
  Serial.println("Run keyboard control");
} 

void loop(void) 
{
  if(Serial.available()){
    char val = Serial.read();
    if(val != -1)
    {
      switch(val)
      {
      case 'w'://Move Forward
        forward(100,100);   //move forward in max speed
        break;
      case 's'://Move Backward
        backward(100,100);   //move back in max speed
        break;
      case 'a'://Turn Left
        left(100,100);
        break;       
      case 'd'://Turn Right
        right(100,100);
        break;
      case 'x':
        stop();
        break;
      }
    }
    else stop();  
  }
}

