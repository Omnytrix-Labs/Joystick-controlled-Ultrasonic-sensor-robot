const int x_position=A0;
const int y_position=A1;

const int trigPin = 9;
const int echoPin = 10; 

int right_motor_1=2;
int right_motor_2=3;
int left_motor_1=4;
int left_motor_2=5;
int buzzer = 6;

long duration;          
int distance; 

void setup()
{
  pinMode(x_position, INPUT);
  pinMode(y_position, INPUT);
  pinMode(trigPin, OUTPUT);       
  pinMode(echoPin, INPUT);
  pinMode(right_motor_1, OUTPUT);
  pinMode(right_motor_2, OUTPUT);
  pinMode(left_motor_1, OUTPUT);
  pinMode(left_motor_2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void rest()
{
  digitalWrite(right_motor_1, LOW);
  digitalWrite(right_motor_2,LOW);
  digitalWrite(left_motor_1, LOW);
  digitalWrite(left_motor_2, LOW);
}

void loop()
{  
  int x_value = analogRead(x_position);
  int y_value = analogRead(y_position);

  digitalWrite(trigPin, LOW);         
  delayMicroseconds(2);               
  digitalWrite(trigPin, HIGH);        
  delayMicroseconds(10);              
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);  
  distance = duration*0.034/2;

}
  
