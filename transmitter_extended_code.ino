
#include <RH_ASK.h> // Include RadioHead Amplitude Shift Keying Library
#include <SPI.h> // Include dependant SPI Library

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;


//const int ledPin = 9;   
int flexPin1 = A0;
int flexPin2 = A1;
int flexPin3 = A2;
int flexPin4 = A3;
int value1; 
int value2;
int value3;
int value4;

void setup(){
  
   Serial.begin(9600);       //Begin serial communication
  Serial.begin(9600);   //Initialise serial to communicate with GSM Modem
  rf_driver.init();
Serial.begin(9600);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
}

void loop(){
  
  value1 = analogRead(flexPin1);        
  value2 = analogRead(flexPin2); 
  value3 = analogRead(flexPin3);  
  value4 = analogRead(flexPin4);  
  Serial.println(value1);               //Print value
  //value = map(value, 700, 930, 0, 255);//Map value 0-1023 to 0-255 (PWM)
 // analogWrite(ledPin, value);          //Send PWM value to led
  delay(100);
           //Read and save analog value from potentiometer
  Serial.println(value2); 
  delay(100);
  Serial.println(value3); 
  delay(100);
  Serial.println(value4); 
  //Small delay
  delay(1000);
  if(value1 < 1000 && value2 >860 && value3 >880 && value4 >930 )
  {
  SendSMS1();
  }
  if(value1 > 1000 && value2 >860 && value3 <880 && value4 >930 )
  {
    SendSMS2();
  }
  if(value1 > 1000 && value2 >860 && value3 >880 && value4 <930 )
  {
   SendSMS3();
  }
  if(value1 > 1000 && value2 <860 && value3 >880 && value4 >930 )
  {
   SendSMS4();
  }
  if(value1 > 1000 && value2 <860 && value3 <880 && value4 >930 )
  {
   SendSMS5();
  }
  if(value1 < 1000 && value2 >860 && value3 >880 && value4 <930 )
  {
   SendSMS6();
  }
 if(value1 < 1000 && value2 <860 && value3 >880 && value4 >930 )
  {
   SendSMS7();
  }
  if(value1 > 1000 && value2 >860 && value3 <880 && value4 <930 )
  {
   SendSMS8();
  }
  if(value1 < 1000 && value2 >860 && value3 <880 && value4 >930 )
  {
   SendSMS9();
  }
  if(value1 > 1000 && value2 <860 && value3 >880 && value4 <930 )
  {
   SendSMS10();
  }
  if(value1 < 1000 && value2 <860 && value3 <880 && value4 >930 )
  {
   SendSMS11();
  }
  if(value1 > 1000 && value2 <860 && value3 <880 && value4 <930 )
  {
   SendSMS12();
  }
  if(value1 < 1000 && value2 <860 && value3 >880 && value4 <930 )
  {
   SendSMS13();
  }
  if(value1 < 1000 && value2 <860 && value3 <880 && value4 <930 )
  {
   SendSMS14();
  }
 // if(value1 > 1000 && value2 >860 && value3 >880 && value4 >930 )
 // {
 //  SendSMS15();
 // }
  

}

 
void SendSMS1()
{
  digitalWrite(9,HIGH);
  Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(1000);
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("water required  ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200);  
  digitalWrite(9,LOW);
    const char *msg = "water required  ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS2()
{
  digitalWrite(9,HIGH);
  
  //Give enough time for GSM to register on Network
        Serial.println("AT+CMGF=1"); 
         delay(1000);//To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("coffee required ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    // while(1);     //Wait forever
  digitalWrite(9, LOW);
       const char *msg = "coffee required ";
   rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS3()
{ digitalWrite(9,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("tea             ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "tea             ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS4()
{ digitalWrite(9,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("medicine        ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "medicine        ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS5()
{ digitalWrite(9,HIGH);
digitalWrite(8,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("light is ON     ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "light is ON     ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS6()
{ digitalWrite(9,HIGH);
digitalWrite(8,LOW);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("light is OFF    ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "light is OFF    ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}

void SendSMS7()
{ digitalWrite(9,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("driving         ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "driving         ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS8()
{ digitalWrite(9,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("reach in 5 min  ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "reach in 5 min  ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS9()
{ digitalWrite(9,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("call you later  ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "call you later  ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS10()
{ digitalWrite(9,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("call me         ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "call me         ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS11()
{ digitalWrite(9,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("accident occurred");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "accident!       ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS12()
{ digitalWrite(9,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("help! in problem");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "help! in problem";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS13()
{ digitalWrite(9,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("washroom        ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "washroom        ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
void SendSMS14()
{ digitalWrite(9,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("come at home    ");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(200); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "come at home    ";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(500);
}
}
/*void SendSMS15()
{ digitalWrite(9,HIGH);
     //Give enough time for GSM to register on Network
      Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  Serial.println("AT+CMGS=\"+917016457155\"\r"); //Change to destination phone number 
  delay(1000);
  Serial.println("no message");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(1000); //Send one SMS
    //while(1);     //Wait forever
   digitalWrite(9, LOW);
       const char *msg = "no message";
rf_driver.send((uint8_t *)msg, strlen(msg));rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(1000);
}
}
*/
