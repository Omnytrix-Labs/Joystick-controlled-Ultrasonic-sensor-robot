const int x_position=A0;
const int y_position=A1;

int left_motor_1=2;
int left_motor_2=3;
int right_motor_1=4;
int right_motor_2=5;

void setup()
{
  pinMode(x_position, INPUT);
  pinMode(y_position, INPUT);
  pinMode(right_motor_1, OUTPUT);
  pinMode(right_motor_2, OUTPUT);
  pinMode(left_motor_1, OUTPUT);
  pinMode(left_motor_2, OUTPUT);
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

    if(y_value >700)  // forward
    {
     digitalWrite(right_motor_1, HIGH);
     digitalWrite(right_motor_2,LOW);
     digitalWrite(left_motor_1, HIGH);
     digitalWrite(left_motor_2, LOW);
     delay(1000);
     rest();
    }
   if(y_value <300)
   {
    digitalWrite(right_motor_1, LOW);
    digitalWrite(right_motor_2, HIGH);
    digitalWrite(left_motor_1, LOW);
    digitalWrite(left_motor_2, HIGH);
    delay(1000);
    rest();
   }
   if(x_value > 700)
   {
    digitalWrite(right_motor_1, HIGH);
    digitalWrite(right_motor_2, LOW);
    digitalWrite(left_motor_1, LOW);
    digitalWrite(left_motor_2, HIGH);
    delay(1000);
    rest();
   }
   if(x_value <300)
   {
    digitalWrite(right_motor_1, LOW);
    digitalWrite(right_motor_2, HIGH);
    digitalWrite(left_motor_1, HIGH);
    digitalWrite(left_motor_2, LOW);
    delay(1000);
    rest();
   }
}
