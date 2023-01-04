#include <LiquidCrystal_I2C.h>
#include "DHT.h"
LiquidCrystal_I2C lcd(0x3f,16,2);
int IRSensor1 = 2; // connect ir sensor to arduino pin 2
int LED1 = 7; // connect Led to arduino pin 13

int IRSensor2 = 3; // connect ir sensor to arduino pin 2
int LED2 = 8; // connect Led to arduino pin 13

int IRSensor3 = 4; // 5connect ir sensor to arduino pin 2
int LED3 = 10; // 10connect Led to arduino pin 13

int LDRsensor = 5;//4
int LED4 = 9;//9
int val = 0;

#define DHTPIN 6 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup()
{

  Serial.begin(9600);
pinMode (IRSensor1, INPUT); // sensor pin INPUT
pinMode (LED1, OUTPUT); // Led pin OUTPUT

pinMode (IRSensor2, INPUT); // sensor pin INPUT
pinMode (LED2, OUTPUT); // Led pin OUTPUT

pinMode (IRSensor3, INPUT); // sensor pin INPUT
pinMode (LED3, OUTPUT); // Led pin OUTPUT

pinMode (LDRsensor, INPUT); // sensor pin INPUT
pinMode (LED4, OUTPUT); // Led pin OUTPUT





lcd.init();
lcd.clear();         
lcd.backlight();
  
  lcd.setCursor(2,0);
  lcd.print("Street Light");

Serial.println(F("DHTxx test!"));
dht.begin();

  
}

void sensor1()
{
int statusSensor1 = digitalRead (IRSensor1);

if (statusSensor1 == 1)
{
digitalWrite(LED1, HIGH); // LED LOW
lcd.setCursor(2,1);
lcd.print("  ");
}
else
{
digitalWrite(LED1, LOW); // LED High
lcd.setCursor(2,1);
lcd.print("  Sensor 1");

}
}

void sensor2()
{
int statusSensor2 = digitalRead (IRSensor2);

if (statusSensor2 == 1)
{
digitalWrite(LED2, HIGH); // LED LOW
lcd.setCursor(2,1);
lcd.print("");
}
else
{
digitalWrite(LED2, LOW); // LED High
lcd.setCursor(2,1);
lcd.print("  Sensor 2");

}
}


void sensor3()
{
int statusSensor3 = digitalRead (IRSensor3);

if (statusSensor3 == 1)
{
  
digitalWrite(LED3, HIGH); // LED LOW
lcd.setCursor(2,1);
lcd.print("");


}
else
{

digitalWrite(LED3, LOW); // LED High
lcd.setCursor(2,1);
lcd.print("  Sensor 3");

}
}


void sensor4() 
 {  
  val = digitalRead(LDRsensor); // LDR Sensor output pin connected  
  Serial.println(val); //  see the value in serial mpnitor in Arduino IDE  
  delay(10);  
  if(val == 0 )  
  {


   digitalWrite(LED4,HIGH); // LED ON  
  

  }  
  else 
  {  
   
     digitalWrite(LED4,LOW); // LED OFF  

     
  }
     

  }  
  


 /* void sensor5() 
 {  
  val = digitalRead(LDRsensor); // LDR Sensor output pin connected  
  Serial.println(val); //  see the value in serial mpnitor in Arduino IDE  
  delay(10);  
  if(val == 0 )  
  {
    
   digitalWrite(LED1,HIGH); // LED ON  
   digitalWrite(LED2,HIGH); // LED ON  
   digitalWrite(LED3,HIGH); // LED ON  
   

  }  
  else  
  {  
     digitalWrite(LED1,LOW); // LED OFF 
     digitalWrite(LED2,LOW); // LED OFF 
     digitalWrite(LED3,LOW); // LED OFF 
      
  }  
  }  */


void sensor6() 
{
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));
}



void loop()

{

sensor1();
sensor2();
sensor3();
sensor4();
//sensor5();
sensor6();


}