/*
  FNW Solutions
  Florian Waldmann
  18.04.2015
  
  Angellight Rev 1.0
  ATmega328p
  
  # Nachtlicht mit IR-Sensor und Dämmerungssensor
  gewidmet meiner Frau Nicole
 */
 
 

int led1 = 5;      // Dunkel() Optokoppler zündet LED-Strip; PWM-Fähig!
int ldr0 = 5;      // Analog-Input für LDR Abfrage
int motion = 0;    // Bewegugnsmelder Pin 3

int del = 15;
int pause = 50;



void setup() {                

  pinMode(led1, OUTPUT);   
  pinMode(ldr0, INPUT); 
  pinMode(motion, INPUT);
}




void dunkel() {              

    for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) 
      {
      analogWrite(led1, fadeValue);        
      delay(50);                            
      }
    
    delay(6000);

    for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) 
      {
      analogWrite(led1, fadeValue);          
      delay(30); 
      }   
}


void ldrcheckup() {
  
  if ( analogRead(motion) >= 100 )    // während der Bewegungsmelder durchschaltet..
    {                                    
      if ( analogRead(ldr0) <= 1 )      // wird geprüft ob der Dämmerungsschalter zündet
        {
        dunkel();                         // Optokoppler kommt!
        } 
    }  
}


void loop() 
{
ldrcheckup();
}



