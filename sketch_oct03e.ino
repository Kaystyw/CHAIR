// DHT11 sensor

#include <DHT.h>
#define DHTPIN 7 // what digital pin we're connected to
#define DHTTYPE DHT11  //DHT 11
#define FORCE_SENSOR_PIN A0
#define buzzerPin 12  
const int pwm = 2 ; //initializing pin 2 as pwm
const int in_1 = 8 ;
const int in_2 = 9 ;
//For providing logic to L298 IC to choose the direction of the DC motor  

// LCD display

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DHT dht (DHTPIN, DHTTYPE); //Initialize DHT sensor.


void setup() {
  // put your setup code here, to run once:
pinMode(pwm,OUTPUT) ; //we have to set PWM pin as output
pinMode(in_1,OUTPUT) ; //Logic pins are also set as output
pinMode(in_2,OUTPUT) ;
pinMode(LED_BUILTIN, OUTPUT);
pinMode(buzzerPin, OUTPUT);
// Serial.begin(9600);


Serial.begin(9600);}


void loop(){
int analogReading = analogRead(FORCE_SENSOR_PIN);
if (analogReading < 500){
  digitalWrite(LED_BUILTIN, LOW);
  }
else{
  digitalWrite(LED_BUILTIN, HIGH);
  }
 

dht.begin();





float t = dht.readTemperature(); // Read temperature in *C (default)


/*Serial.print("Temerature: ");
Serial.print(t);
Serial.print("*C\t");
Serial.print("Humidity: ");
Serial.print(h);
Serial.print("%\t");
Serial.print("Heat index: ");
Serial.println(hic);
*/



// LCD display

lcd.begin(16, 2); // display diamensions
lcd.setCursor(0,0);
if(t<=34&&t>=32){
  lcd.print("Sleep deprived.Please take a 6 hour nap.");
  //For Clock wise motion , in_1 = High , in_2 = Low
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,LOW) ;
   analogWrite(pwm,255) ;
   /* setting pwm of the motor to 255 we can change the speed of rotation
   by changing pwm input but we are only using arduino so we are using highest
   value to driver the motor */
   //Clockwise for 3 secs
   delay(3000) ;
   //For brake
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,HIGH) ;
   delay(21600000);
   tone(buzzerPin, 2000);
   delay(60000);// Send 2000Hz sound signal..
   noTone(buzzerPin);
   //For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
   digitalWrite(in_1,LOW) ;
   digitalWrite(in_2,HIGH) ;
   delay(3000) ;
   //For brake
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,HIGH) ;
   
}
else if(t>34&&t<=36){
  lcd.print("Sleep deprived.Please take a 4 hour nap.");
  //For Clock wise motion , in_1 = High , in_2 = Low
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,LOW) ;
   analogWrite(pwm,255) ;
   /* setting pwm of the motor to 255 we can change the speed of rotation
   by changing pwm input but we are only using arduino so we are using highest
   value to driver the motor */
   //Clockwise for 3 secs
   delay(3000) ;
   //For brake
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,HIGH) ;
   delay(14400000);
   tone(buzzerPin, 2000);
   delay(60000);// Send 2000Hz sound signal..
   noTone(buzzerPin);
   //For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
   digitalWrite(in_1,LOW) ;
   digitalWrite(in_2,HIGH) ;
   delay(3000) ;
   //For brake
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,HIGH) ;
   
}
else if(t>=37.5&&t<=39.50){
  lcd.print("Sleep deprived.Please take a 4 hour nap.");
  //For Clock wise motion , in_1 = High , in_2 = Low
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,LOW) ;
   analogWrite(pwm,255) ;
   /* setting pwm of the motor to 255 we can change the speed of rotation
   by changing pwm input but we are only using arduino so we are using highest
   value to driver the motor */
   //Clockwise for 3 secs
   delay(3000) ;
   //For brake
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,HIGH) ;
   delay(14400000);
   tone(buzzerPin, 2000);
   delay(60000);// Send 2000Hz sound signal..
   noTone(buzzerPin);
   //For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
   digitalWrite(in_1,LOW) ;
   digitalWrite(in_2,HIGH) ;
   delay(3000) ;
   //For brake
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,HIGH) ;
   
}
else if(t>39.5&&t<=41){
  lcd.print("Sleep deprived.Please take a 6 hour nap.");
  //For Clock wise motion , in_1 = High , in_2 = Low
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,LOW) ;
   analogWrite(pwm,255) ;
   /* setting pwm of the motor to 255 we can change the speed of rotation
   by changing pwm input but we are only using arduino so we are using highest
   value to driver the motor */
   //Clockwise for 3 secs
   delay(3000) ;
   //For brake
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,HIGH) ;
   delay(21600000);
   tone(buzzerPin, 2000);
   delay(60000);// Send 2000Hz sound signal..
   noTone(buzzerPin);
   //For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
   digitalWrite(in_1,LOW) ;
   digitalWrite(in_2,HIGH) ;
   delay(3000) ;
   //For brake
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,HIGH) ;
   
}
else{
  lcd.print("Normal");
}
}
