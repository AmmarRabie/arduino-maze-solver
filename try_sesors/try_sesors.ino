#define PIN_TRIG 6
#define PIN_ECHO 7
#define SOUND_SPEED 0.034 // cm / micro secods
#define PIN_WHEEL_R0 10
#define PIN_WHEEL_R1 11
#define PIN_WHEEL_L0 12
#define PIN_WHEEL_L1 13
#define PIN_WHEEL_RSPEED 5
#define PIN_WHEEL_LSPEED 3
#define WHEEL_SPEED 150



long distance = 20;


void setup() {
  Serial.begin(9600);
  
  pinMode(PIN_WHEEL_L0, OUTPUT);
  pinMode(PIN_WHEEL_L1, OUTPUT);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
 
  pinMode(PIN_WHEEL_LSPEED, OUTPUT);

  
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
}

void loop() {
  if(shouldMove(getDistance()))
    moveForward();
  else
    stopMotor();
    
    
}



/*
 * get the distance of first obstacle from ultrasonic sensor.
 * function validate the output of the sensor and try to find it again while it is valid
 * The function now freeze the code if distance alwayes invalid
 */
int getDistance()
{  
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  
  long duration = pulseIn(PIN_ECHO, HIGH);
//  Serial.print(duration);
  long newDistance = (duration * SOUND_SPEED) / 2;
  Serial.println(newDistance); delay(1500);
  if (newDistance <= 350)
    distance = newDistance;
//  Serial.print(distance); Serial.print('\n');
  return distance;
}


boolean shouldMove(long distance)
{
//  Serial.print("shouldMove");
//  Serial.print(distance); Serial.print('\n');
  boolean _move =  distance >= 30;
//  Serial.print(_move); Serial.print('\n');
  return _move;
}


void moveForward()
{
  digitalWrite(PIN_WHEEL_L0, HIGH);
  digitalWrite(PIN_WHEEL_L1, LOW);
  
  analogWrite(PIN_WHEEL_LSPEED, 200);
}

void stopMotor()
{
  analogWrite(PIN_WHEEL_LSPEED, 0);
  // stop the second wheel
}
