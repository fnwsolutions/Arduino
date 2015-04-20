#define LED 13

int blinks = 0;
int LED1 = 4;
int LED2 = 5;
int LED3 = 6;
float celsius = 0;
float fahrenheit = 0;

void setup()
  {
    pinMode(LED, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    Serial.begin(9600);
  }

int checkTemp()
  {
    float voltage = 0;

    float hotTemp = 26;
    float coldTemp = 20;
    float sensor = 0;
    int result;
    
    // Liest den Temperatursensor ab und rechnet das Ergebnis
    // in Clesiuswerte um
    
    sensor = analogRead(0);
    voltage = (sensor*5000)/1024;
    voltage = voltage-500;
    celsius = voltage/10;
    fahrenheit = (1.8 * celsius) + 32;
    
    if (celsius < coldTemp)
      {
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED1, HIGH);

      }
     else if (celsius >= coldTemp && celsius <= hotTemp)
       {
         digitalWrite(LED1, LOW);
         digitalWrite(LED3, LOW);
         digitalWrite(LED2, HIGH);

       }
     else
       {
         digitalWrite(LED1, LOW);
         digitalWrite(LED2, LOW);
         digitalWrite(LED3, HIGH);

       }
     return result;
  }
  
  void blinkLED(int cycles, int del)
    {
      for ( int z = 0 ; z < cycles ; z++)
       {
         digitalWrite(LED, HIGH);
         delay(del);
         digitalWrite(LED, LOW);
         delay(del);
       }
    }
    
    void Output()
    {
      Serial.print("Temperatur ist ");
      Serial.print(celsius, 2);
      Serial.print(" deg. C / ");
      Serial.print(fahrenheit, 2);
      Serial.println(" deg, F");
    }
    
   void loop()
     {
       blinks = checkTemp();
       blinkLED(blinks, 500);
       delay(500);
       Output();
     }
