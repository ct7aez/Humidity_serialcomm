/* 
 
 Uses the SparkFunHTU21D library to display the current humidity and temperature
 
 Open serial monitor at 9600 baud to see readings. Errors 998 if not sensor is detected. Error 999 if CRC is bad.
 
 Hardware Connections (Breakoutboard to Arduino):
 -VCC = 3.3V
 -GND = GND
 -SDA = A4 (use inline 330 ohm resistor if your board is 5V)
 -SCL = A5 (use inline 330 ohm resistor if your board is 5V)
 
 Configuration and reading from the serial monitor
 
 */

#include <Wire.h>
#include "SparkFunHTU21D.h"

//Create an instance of the object
HTU21D myHumidity;
int resol = 1;
int atraso = 1000;

void setup()
{
  Serial.begin(9600);
  Serial.println("***************************************************");
  Serial.println("*HTU21D Example! serial comm, by CT7AEZ*");
  Serial.println("***************************************************");

  myHumidity.begin();
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
}

void loop()
{
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();

  Serial.print("Time (min.):");
  Serial.print(millis()/1000/60);
  Serial.print(" Temperature:");
  Serial.print(temp, resol);
  Serial.print("C");
  Serial.print(" Humidity:");
  Serial.print(humd, resol);
  Serial.print("%");

  Serial.println();
  Serial.print("Reading time ");
  Serial.print(atraso/1000);
  Serial.println(" seconds, please wait...");

  barra();

  console();

  Serial.println();
}

void console()

{
  if (Serial.available() > 0) {
    int inByte = Serial.read();

    switch (inByte) {
    case '?':
      Serial.println();
      Serial.println("Show options - ?");
      Serial.println("Resolution 1 or 2 digits decimal");
      Serial.println("Reading interval 3....0 seconds");
      Serial.println("reset - r");
      Serial.println();

      while(Serial.available() == 0) {
        delay(100);   
      } 

      break;

    case '1':
      resol=1;
      break;

    case '2':
      resol=2;
      break;

    case '3':
      atraso=3000;
      break;

    case '4':
      atraso=4000;
      break;

    case '5':
      atraso=5000;
      break;

    case '6':
      atraso=6000;
      break;

    case '7':
      atraso=7000;
      break;

    case '8':
      atraso=8000;
      break;

    case '9':
      atraso=9000;
      break;

    case '0':
      atraso=10000;
      break;

    case 'r':
      atraso=1000;
      resol=1;
      break;
    }

  }

}

void barra()

{

  for(int i=0;i<=10;i++)
  {
    digitalWrite(13, LOW);
    Serial.print(".");
    delay(atraso/10);
    digitalWrite(13, HIGH);
  }


}

