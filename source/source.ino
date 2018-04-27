    #define speed_motor_Left 5  //controls speed of the engine left;
    #define speed_motor_Right 3  //controls speed of the engine right;         
    #define e1 10  //controls the rotation direction of the engine left;
    #define e2 11  // controls the rotation direction of the engine left;
    #define d1 12  //controls sense of rotation of the engine right;
    #define d2 13  //controls sense of rotation of the engine right;
 
    int trigger_front = 6;
    int echo_front = 7;
    
    int trigger_Left = 8;
    int echo_Left = 9;
    
    int trigger_Right = 2;
    int echo_Right = 1;
    
     
    void setup()
    {
        pinMode(trigger_front, OUTPUT); 
        pinMode(echo_front, INPUT);
        
        pinMode(trigger_Left, OUTPUT);
        pinMode(echo_Left, INPUT);        
        
        pinMode(trigger_Right, OUTPUT);
        pinMode(echo_Right, INPUT);
       
        pinMode(speed_motor_Left, OUTPUT);
        pinMode(speed_motor_Right, OUTPUT);
    
        pinMode(e1, OUTPUT);
        pinMode(e2, OUTPUT);
        pinMode(d1, OUTPUT);
        pinMode(d2, OUTPUT);
        delay(5000);
    }
    
    // code in infinite project repetition
    void loop()
    {
     // declaration of variables used to control the project
     long duration_front, duration_Left, duration_Right, distance,left , front; 
     
     
     digitalWrite(trigger_front, LOW);  // the respective signal inputs and outputs of the
     delayMicroseconds(2);               // sensor and stored by the sensor variable
     digitalWrite(trigger_front, HIGH); //that converts to speed of som that is 340 m / s or
     delayMicroseconds(5);               // 29 microseconds per centimeter
     digitalWrite(trigger_front, LOW);  //this time is half being sensor = time / 29/2 ;
     duration_front = pulseIn(echo_front, HIGH); //so follow as well as other sensors.
     front = duration_front/29/2;
     //////////////////////////////////////////////////////
     front = 20;
         
     digitalWrite(trigger_Left, LOW);
     delayMicroseconds(2);
     digitalWrite(trigger_Left, HIGH);
     delayMicroseconds(5);
     digitalWrite(trigger_Left, LOW); 
     duration_Left = pulseIn(echo_Left, HIGH);
     left = duration_Left/29/2;
     //////////////////////////////////////////////////////
     left = 20;
    
     digitalWrite(trigger_Right, LOW);
     delayMicroseconds(2);
     digitalWrite(trigger_Right, HIGH);
     delayMicroseconds(5);
     digitalWrite(trigger_Right, LOW); 
     duration_Right = pulseIn(echo_Right, HIGH);
     distance = duration_Right/29/2; 
     //////////////////////////////////////////////////////
     distance = 20;

       
     analogWrite(speed_motor_Left, 0);  //block to initialize the inputs with pulse 0 or unlinked;
     analogWrite(speed_motor_Right, 0); //
     analogWrite(e1, 0);            //
     analogWrite(e2, 0);            //  
     analogWrite(d1, 0);            //
     analogWrite(d2, 0);            //
     
       if(front >8) 
         {  
 
           
           if(distance >7 && distance< 13) //
             {               
               analogWrite(speed_motor_Left, 120);
               analogWrite(speed_motor_Right, 150);
           
               analogWrite(e1, 255);
               analogWrite(e2, 0);
               analogWrite(d1, 0);
               analogWrite(d2, 255);
             }
         
           if(distance >=13)  //
             {
               analogWrite(speed_motor_Left, 255);
               analogWrite(speed_motor_Right, 60);
           
               digitalWrite(e1, HIGH);
               digitalWrite(e2, LOW);
               digitalWrite(d1, LOW);
               digitalWrite(d2, HIGH);                               
             }
             
                 
           if(distance <=7)  // 
             {
               analogWrite(speed_motor_Left, 60);
               analogWrite(speed_motor_Right, 255);
           
               analogWrite(e1, 255);
               analogWrite(e2, 0);
               analogWrite(d1, 0);
               analogWrite(d2, 255);                   
             }
         }
         
              
       if(left <=20 && distance>20 && front <=8) Right();// 
            
       if(left >20 && distance>20 && front <=8) Right();// 
       
       if(distance <=20 && left>20 && front <=8) Left(); //
       
       if(distance<=20 && left<=20 && front<=8) back(); // if the forward distance is less than or equal to 8 cm,                       
    
    }
       
    void Left() // function to make the robot rotate 90º to the left if there is no front and right exit;
      {
       
        analogWrite(speed_motor_Left, 120);
        analogWrite(speed_motor_Right, 120);
           
        digitalWrite(e1, LOW);
        digitalWrite(e2, HIGH);
        digitalWrite(d1, LOW);
        digitalWrite(d2, HIGH);
        delay(700);      
        
      }
    
    void Right() // function to make the robot rotate 180º if there is no forward, left and right exit;
      {
        
      
        analogWrite(speed_motor_Left, 120);
        analogWrite(speed_motor_Right, 120);
        
        digitalWrite(e1, HIGH);
        digitalWrite(e2, LOW);
        digitalWrite(d1, HIGH);
        digitalWrite(d2, LOW);             
        delay(800);
               
      }
    
    void back() // function to make the robot rotate 180º if there is no forward, left and right exit
      {
       
        analogWrite(speed_motor_Left, 120);
        analogWrite(speed_motor_Right, 120);
           
        digitalWrite(e1, HIGH);
        digitalWrite(e2, LOW);
        digitalWrite(d1, HIGH);
        digitalWrite(d2, LOW);
        delay(1200); 
         
      }   
  
