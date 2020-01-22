#define trigPin1 5  //silver
#define echoPin1 4  //silver
#define trigPin2 7 //green
#define echoPin2 6 //green

//motor
const int ENA = 8;
const int IN1 = 11;
const int IN2 = 10;
const int IN3 = 12;
const int IN4 = 13;
const int ENB = 9;


long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;

void setup()
{
  
Serial.begin (9600);

//ultrasonic
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

//motor
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);

}

void loop() {

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
Serial.print(" check distance ok ");
}

 
SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;

  if(LeftSensor<10) {
    Serial.print(" aouch Left ");
    Serial.println(LeftSensor);
    Serial.print(" obstacole still present ");

       //control speed 
          analogWrite(ENA, 255);
          analogWrite(ENB, 255); 
       //control direction 
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
  }
               
  


  else if(RightSensor<10) {
    Serial.print(" aouch Right ");
    Serial.println(RightSensor);
    Serial.print(" obstacole still present ");

       //control speed 
          analogWrite(ENA, 255);
          analogWrite(ENB, 255); 
       //control direction 
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);

  }
  

  else{
      //control speed 
          analogWrite(ENA, 0);
          analogWrite(ENB, 0); 
      //control direction 
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          Serial.print(" no obstacoles ");

    }
    
}
