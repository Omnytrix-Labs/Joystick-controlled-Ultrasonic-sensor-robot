                            //assign UNO board pins to sensor, motors and other devices for robot working
const int trigPin = 9;      // Connect trigger pin of ultrasonic sensor to 9 pin of UNO board
const int echoPin = 10;     // Connect echo pin of ultrasonic sensor to 10 pin of UNO board

int left_motor_1=2;         // Connect right side motor 1st wire to 2 pin of UNO board
int left_motor_2=3;        // Connect right side motor 2nd wire to 3 pin of UNO board
int right_motor_1=4;         // Connect left side motor 1st wire to 4 pin of UNO board
int right_motor_2=5;         // Connect left side motor 2nd wire to 5 pin of UNO board
                            //No need to declare Bluetooth pins connection, as UNO board 0 & 1 pins acts as Receiver and Tramistter
                            //Connect Tx pin of Bluetooth to Rx pin (0 pin) of UNO board
                            //Connect Rx pin of Bluetooth to Tx pin (1 pin) of UNO board
long duration;              // This is a variable to store the duration of ultrasonic signal
int distance;               // This is a variable to store the distance measured by ultrasonic sensor

void setup() 
{
                                    //setup ultrasonic sensor and motors as Output or input devices
  pinMode(trigPin, OUTPUT);         // Set the trigger pin of ultrasonic sensor as Output from UNO board to send signals out
  pinMode(echoPin, INPUT);          // Set the echo pin of ultrasonic sensor as input to UNO board to read the recieved signals
                                    //Set all motor pins as outputs to UNO board to send signals to run the motors
  pinMode(right_motor_1, OUTPUT);
  pinMode(right_motor_2, OUTPUT);
  pinMode(left_motor_1, OUTPUT);
  pinMode(left_motor_2, OUTPUT);
  Serial.begin(9600);               // Starts the serial communication with specified speed
}

//set the default position of robot as stop

void rest()
{
  digitalWrite(right_motor_1, LOW);
  digitalWrite(right_motor_2,LOW);
  digitalWrite(left_motor_1, LOW);
  digitalWrite(left_motor_2, LOW);
}

void loop() 
{
                                      // run the ultrasonic sensor
                                      //We have to send the signal sound out of ultrasonic sensor
  digitalWrite(trigPin, LOW);         // To make trigger pin clear from any values by making it to zero value
  delayMicroseconds(2);               // wait for 2 microseconds after making trigger pin zero
  digitalWrite(trigPin, HIGH);        // Sets the trigPin on HIGH state
  delayMicroseconds(10);              // Hold trigger pin on HIGH state for 10 Microseconds
  digitalWrite(trigPin, LOW);         // Stop the trigger pin or turn off the trigger pin HIGH state
  
                                      //calculate the distance measured by sensor
  duration = pulseIn(echoPin, HIGH);  // Read how much time HIGH value of signal received at echo pin and store it in DURATION variable
  distance = duration*0.034/2;        // Calculating the distance based on duration

      Serial.println(distance);
      delay(50);
      if(distance <=30)
      rest();
  if(Serial.available()>0) 
  { 
    char command = Serial.read();
    {
     if(command=='f' && distance>30)    // Double "&" function makes the operation to read both conditions...
     {                                  // robot will go forward if distance is less than 30 cm and press 'f'
       forward();                     // you can write simple function and define it anywhere in the code
       Serial.println("Going forward");
       delay(50);
       
     }
     if(command=='r')     //right turn same as bluetooth controlled robot
     {
       right();
       Serial.println("Right turn");
       delay(100);
       rest();
     }
     if(command=='l')
     {
       left();
       Serial.println("Left turn");
       delay(100);
       rest();
     }
     if(command=='b')
     {
        back();
        Serial.println("Backward");
        delay(100);
        rest();
     }
        if(command=='s')
     {
        rest();
        Serial.println("STOP");
        delay(100);
     }
      if(command == 'f' && distance<=30)   //stop and turn robot to right if distance is less than or equal to 30 cm
      {
        Serial.println("Obstacle infront");
        delay(50);
        Serial.println("Turn me");
        rest();
        delay(100);     
      }
    }
  }
}

void forward()
{
     digitalWrite(right_motor_1, HIGH);
     digitalWrite(right_motor_2,LOW);
     digitalWrite(left_motor_1, HIGH);
     digitalWrite(left_motor_2, LOW);
}

void right()
{
    digitalWrite(right_motor_1, LOW);
    digitalWrite(right_motor_2, HIGH);
    digitalWrite(left_motor_1, HIGH);
    digitalWrite(left_motor_2, LOW);
}

void left()
{
    digitalWrite(right_motor_1, HIGH);
    digitalWrite(right_motor_2, LOW);
    digitalWrite(left_motor_1, LOW);
    digitalWrite(left_motor_2, HIGH);
}

void back()
{
    digitalWrite(right_motor_1, LOW);
    digitalWrite(right_motor_2, HIGH);
    digitalWrite(left_motor_1, LOW);
    digitalWrite(left_motor_2, HIGH);
}
