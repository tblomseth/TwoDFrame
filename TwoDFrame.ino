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
            case IR_BUTTON_1: Serial.println("BUTTON_1"); drawCircleWithSegments( 8 ); break;
            case IR_BUTTON_2: Serial.println("BUTTON_2"); drawSpiral(); break;
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

void drawCircleWithSegments(int noOfSegments) {
  int interval = 80; // in ms
  float radiansPerSegment = 2 * PI / noOfSegments;
  int mxSpeed;
  int mySpeed;
  for ( int i = 1; i <= noOfSegments; i++ ) {
    Serial.println( "i = " ); Serial.println( i );
    float currentPointX = cos( ( i - 1 ) * radiansPerSegment );
    Serial.println( "currentPointX = " ); Serial.println( currentPointX );
    float currentPointY = sin( ( i - 1 ) * radiansPerSegment );
    Serial.println( "currentPointY = " ); Serial.println( currentPointY );
    float nextPointX = cos( i * radiansPerSegment );
    Serial.println( "nextPointX = " ); Serial.println( nextPointX );
    float nextPointY = sin( i * radiansPerSegment );
    Serial.println( "nextPointY = " ); Serial.println( nextPointY );
    float deltaX = nextPointX - currentPointX;
    Serial.println( "deltaX = " ); Serial.println( deltaX );
    float deltaY = nextPointY - currentPointY;
    Serial.println( "deltaY = " ); Serial.println( deltaY );
    int mxDirection = deltaX / abs( deltaX );
    Serial.println( "mxDirection = " ); Serial.println( mxDirection );
    int myDirection = deltaY / abs( deltaY );
    Serial.println( "myDirection = " ); Serial.println( myDirection );
    if ( abs( deltaX ) >= abs( deltaY ) ) {
      mxSpeed = mxDirection * 255;
      Serial.println( "mxSpeed = " ); Serial.println( mxSpeed );      
      mySpeed = (int) myDirection * ( 255 * abs( deltaY ) ) / abs( deltaX );
      Serial.println( "mySpeed = " ); Serial.println( mySpeed );
    } else {
      mxSpeed = (int) mxDirection * ( 255 * abs( deltaX ) ) / abs( deltaY );
      Serial.println( "mxSpeed = " ); Serial.println( mxSpeed );
      mySpeed = myDirection * 255;
      Serial.println( "mySpeed = " ); Serial.println( mySpeed );
    }
    baseShieldMotorDriver.runMotor1( mxSpeed );
    baseShieldMotorDriver.runMotor2( mySpeed );
    delay( interval );
    baseShieldMotorDriver.stopMotors();
    //delay( 100 );
  }
  baseShieldMotorDriver.stopMotors();  
}

void drawSpiral() {
  drawCircleWithSegments( 96 );
  drawCircleWithSegments( 88 ); 
  drawCircleWithSegments( 80 );   
  drawCircleWithSegments( 72 ); 
  drawCircleWithSegments( 64 );   
  drawCircleWithSegments( 56 );   
  drawCircleWithSegments( 48 );   
  drawCircleWithSegments( 40 );
  drawCircleWithSegments( 32 );
  drawCircleWithSegments( 24 );
  drawCircleWithSegments( 16 );
  drawCircleWithSegments( 8 );  
}
