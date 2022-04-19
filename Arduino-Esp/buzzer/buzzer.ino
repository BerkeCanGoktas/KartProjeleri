/* Arduino tutorial - Buzzer / Piezo Speaker
   More info and circuit: http://www.ardumotive.com/how-to-use-a-buzzer-en.html
   Dev: Michalis Vasilakis // Date: 9/6/2015 // www.ardumotive.com */

const int buzzer = 9; //buzzer to arduino pin 9

void setup(){
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}

void loop(){
   // Sounds the buzzer at the frequency relative to the note C in Hz
    tone(buzzer,261);    
    // Waits some time to turn off
    delay(400);
    //Turns the buzzer off
    noTone(buzzer); 
    // Sounds the buzzer at the frequency relative to the note D in Hz   
    tone(buzzer,293);             
    delay(800);    
    noTone(buzzer); 
    // Sounds the buzzer at the frequency relative to the note E in Hz
    tone(buzzer,329);      
    delay(1200);
    noTone(buzzer);     
    // Sounds the buzzer at the frequency relative to the note F in Hz
    tone(buzzer,349);    
    delay(100);    
    noTone(buzzer); 
    // Sounds the buzzer at the frequency relative to the note G in Hz
    tone(buzzer,392);            
    delay(200);
    noTone(buzzer); 
}
