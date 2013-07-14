#include <Me_BaseShield.h>
#include <Me_BaseShieldMotorDriver.h>
#include <Me_InfraredReceiver.h>
Me_BaseShieldMotorDriver baseShieldMotorDriver;
Me_InfraredReceiver infraredReceiver;

void setup() {  
  infraredReceiver.begin();
  Serial.begin(9600);  
  baseShieldMotorDriver.begin();
}

void loop()
{
    int key = infraredReceiver.read();
    if(key>=0)
    {
        switch (key)
        {
            case IR_POWER_BUTTON: Serial.println("POWER_BUTTON");break;
            case IR_MENU_BUTTON: Serial.println("MENU_BUTTON");break;
            case IR_TEST_BUTTON: Serial.println("TEST_BUTTON"); measureMotorSpeed(); break;
            case IR_PLUS_BUTTON: Serial.println("PLUS_BUTTON");break;
            case IR_RETURN_BUTTON: Serial.println("RETURN_BUTTON");break;
            case IR_PREVIOUS_BUTTON: Serial.println("PREVIOUS_BUTTON");break;
            case IR_PLAY_BUTTON: Serial.println("PLAY_BUTTON");break;
            case IR_NEXT_BUTTON: Serial.println("NEXT_BUTTON");break;
            case IR_MINUS_BUTTON: Serial.println("MINUS_BUTTON");break;
            case IR_CLR_BUTTON: Serial.println("CLR_BUTTON");break;
            case IR_BUTTON_0: Serial.println("BUTTON_0"); drawCircle(); break;
            case IR_BUTTON_1: Serial.println("BUTTON_1");break;
            case IR_BUTTON_2: Serial.println("BUTTON_2");break;
            case IR_BUTTON_3: Serial.println("BUTTON_3");break;
            case IR_BUTTON_4: Serial.println("BUTTON_4"); drawSquare(); break;
            case IR_BUTTON_5: Serial.println("BUTTON_5");break;
            case IR_BUTTON_6: Serial.println("BUTTON_6");break;
            case IR_BUTTON_7: Serial.println("BUTTON_7");break;
            case IR_BUTTON_8: Serial.println("BUTTON_8"); drawHourGlass(); break;
            case IR_BUTTON_9: Serial.println("BUTTON_9");break;
            default:break;
        }
    }
}

void drawSquare() {
  baseShieldMotorDriver.runMotor1(255);
  delay(2000);
  baseShieldMotorDriver.stopMotor1();
  baseShieldMotorDriver.runMotor2(-100);
  delay(2000);
  baseShieldMotorDriver.stopMotor2();
  baseShieldMotorDriver.runMotor1( -255 );
  delay(1950);
  baseShieldMotorDriver.stopMotor1();
  baseShieldMotorDriver.runMotor2( 100 );
  delay(2000);  
  baseShieldMotorDriver.stopMotor2();
  baseShieldMotorDriver.runMotors( 255,-100 );
  delay( 2000 );
  baseShieldMotorDriver.stopMotors();
  baseShieldMotorDriver.runMotor2(100 );
  delay(2000);  
  baseShieldMotorDriver.stopMotor2();  
  baseShieldMotorDriver.runMotors( -255,-110 );
  delay( 1950 );
  baseShieldMotorDriver.stopMotors();
  baseShieldMotorDriver.runMotor2( 100 );
  delay(1950);  
  baseShieldMotorDriver.stopMotor2(); 
}

void drawHourGlass() {
  baseShieldMotorDriver.runMotors( 255,-100 );
  delay( 2000 );
  baseShieldMotorDriver.stopMotors();
  
  baseShieldMotorDriver.runMotor2(100 );
  delay(2000);  
  baseShieldMotorDriver.stopMotor2();  

  baseShieldMotorDriver.runMotors( -255,-100 );
  delay( 1950 );
  baseShieldMotorDriver.stopMotors();

  baseShieldMotorDriver.runMotor2( 100 );
  delay(1950);  
  baseShieldMotorDriver.stopMotor2();    
}

void drawCrossedSquare() 
{
  drawSquare();
  
}

void runBackAndForth( int velocity, int duration, int steps) {
  for ( int i = 0; i < steps; i++ ) {
     baseShieldMotorDriver.runMotor2( velocity );
     delay( duration / steps );
     baseShieldMotorDriver.stopMotor2();
     delay( 200 );
  }
 
  /*
  baseShieldMotorDriver.runMotor1( 64 );
  delay( 500 );
  baseShieldMotorDriver.runMotor1( -128 );
  delay( 500 );
  baseShieldMotorDriver.runMotor1( 64 );  
  delay( 500 );
  baseShieldMotorDriver.stopMotor1();  
  */
  for ( int j = 0; j < steps; j++ ) {
    baseShieldMotorDriver.runMotor2( -velocity );
    delay( duration / steps );  
    baseShieldMotorDriver.stopMotor2();
    delay( 200 );
  }
}

void oneStep() {
  baseShieldMotorDriver.runMotor1(255);
  delay( 200 );
  baseShieldMotorDriver.stopMotor1();  
}

void measureMotorSpeed() {
  runBackAndForth( -55, 1000, 2);
  oneStep(); 
  runBackAndForth( -80, 1000, 2 );
  oneStep(); 
  runBackAndForth( -105, 1000, 2 );
  oneStep(); 
  runBackAndForth( -130, 1000, 2 );
  oneStep(); 
  runBackAndForth( -155, 1000, 2 );
  oneStep(); 
  runBackAndForth( -180, 1000, 2 );
  oneStep(); 
  runBackAndForth( -205, 1000, 2 );
  oneStep(); 
  runBackAndForth( -230, 1000, 2 );
  oneStep(); 
  runBackAndForth( -255, 1000, 2 );
  
  baseShieldMotorDriver.runMotor1( -255 );
  delay( 1470 );
  baseShieldMotorDriver.stopMotor1(); 
  
}

void drawCircle() {
  int high = (int) 255 * sin( 0.25 * PI );
  int low =  (int) 255 * ( 1 - cos( 0.25 * PI ));
  int interval = 800;
  baseShieldMotorDriver.runMotor1( - high );
  baseShieldMotorDriver.runMotor2( low );
  delay( interval );
  baseShieldMotorDriver.runMotor1( - low );
  baseShieldMotorDriver.runMotor2( high );
  delay( interval );
  baseShieldMotorDriver.runMotor1( low );
  baseShieldMotorDriver.runMotor2( high );
  delay( interval );
  baseShieldMotorDriver.runMotor1( high );
  baseShieldMotorDriver.runMotor2( low );
  delay( interval );

  baseShieldMotorDriver.runMotor1( high );
  baseShieldMotorDriver.runMotor2( - low );
  delay( interval );
  baseShieldMotorDriver.runMotor1( low );
  baseShieldMotorDriver.runMotor2( - high );
  delay( interval );
  baseShieldMotorDriver.runMotor1( - low );
  baseShieldMotorDriver.runMotor2( - high );
  delay( interval );
  baseShieldMotorDriver.runMotor1( - high );
  baseShieldMotorDriver.runMotor2( - low );
  delay( interval );


  baseShieldMotorDriver.stopMotors();
}
