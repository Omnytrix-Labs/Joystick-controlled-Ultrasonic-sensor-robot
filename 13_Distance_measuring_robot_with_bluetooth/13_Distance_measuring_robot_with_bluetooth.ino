const int trigPin = 9;      // Connect trigger pin of ultrasonic sensor to 9 pin of UNO board
const int echoPin = 10;     // Connect echo pin of ultrasonic sensor to 10 pin of UNO board

int right_motor_1=2;        // Connect right side motor 1st wire to 2 pin of UNO board
int right_motor_2=3;        // Connect right side motor 2nd wire to 3 pin of UNO board
int left_motor_1=4;         // Connect left side motor 1st wire to 4 pin of UNO board
int left_motor_2=5;         /* Connect left side motor 2nd wire to 5 pin of UNO board*/
      //No need to declare Bluetooth pins connection, as UNO board 0 & 1 pins acts as Receiver and Tramistter
      //Connect Tx pin of Bluetooth to Rx pin (0 pin) of UNO board
      //Connect Rx pin of Bluetooth to Tx pin (1 pin) of UNO board
long duration;              // This is a variable to store the duration of ultrasonic signal
int distance;               // This is a variable to store the distance measured by ultrasonic sensor

void setup() 
{
  pinMode(trigPin, OUTPUT);         // Set the trigger pin of ultrasonic sensor as Output from UNO board to send signals out
  pinMode(echoPin, INPUT);          // Set the echo pin of ultrasonic sensor as input to UNO board to read the recieved signals
      //Set all motor pins as outputs to UNO board to send signals to run the motors
  pinMode(right_motor_1, OUTPUT);
  pinMode(right_motor_2, OUTPUT);
  pinMode(left_motor_1, OUTPUT);
  pinMode(left_motor_2, OUTPUT);
  Serial.begin(9600);               // Starts the serial communication with specified speed
}

void rest()
{
        //to hold robot in stop position by default
  digitalWrite(right_motor_1, LOW);
  digitalWrite(right_motor_2,LOW);
  digitalWrite(left_motor_1, LOW);
  digitalWrite(left_motor_2, LOW);
}

void loop() 
{
    //We have to send the signal sound out of ultrasonic sensor
  digitalWrite(trigPin, LOW);         // To make trigger pin clear from any values by making it to zero value
  delayMicroseconds(2);               // wait for 2 microseconds after making trigger pin zero
  digitalWrite(trigPin, HIGH);        // Sets the trigPin on HIGH state
  delayMicroseconds(10);              // Hold trigger pin on HIGH state for 10 Microseconds
  digitalWrite(trigPin, LOW);         // Stop the trigger pin or turn off the trigger pin HIGH state
    
                            //We have to read and calculate the distance based on reflected sound from obstacle
  duration = pulseIn(echoPin, HIGH);  // Read how much time HIGH value of signal received at echo pin and store it in DURATION variable
  distance = duration*0.034/2;        // Calculating the distance based on duration
    
                            //Write the distance value in display (either computer or send to mobile using bluetooth)
  Serial.print(distance);           // Prints the value of distance measured using ultrasonic sensor
  Serial.println(" cm");                // Prints the word "cm" on the Serial Monitor
  delay(50);
    
    //Now control the robot movement based on the signal received
   if(distance>30)                    // if distance of obstacle is more than 20 cm...
   {
      //Move robot forward
      digitalWrite(right_motor_1, HIGH);
      digitalWrite(right_motor_2,LOW);
      digitalWrite(left_motor_1, HIGH);
      digitalWrite(left_motor_2, LOW);
      delay(100);
   }
   if(distance<=30)                   // if distance of obstacle is less than or equal to 30 cm...
   {
              //stop robot for 1 second
      rest();
      Serial.println("Obstacle infront");
      delay(1000);
              //Turn robot right
      digitalWrite(right_motor_1, LOW);
      digitalWrite(right_motor_2,HIGH);
      digitalWrite(left_motor_1, HIGH);
      digitalWrite(left_motor_2, LOW);
      Serial.println("Turning Right");
      delay(500);
   }
}
