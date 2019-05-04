#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
 
 
// You should get Auth Token in the Blynk App. 
// Go to the Project Settings (nut icon). 
char auth[] = "2db60c0a67cf41bea7915bb6e04b0d41"; 
 
 
// Your WiFi credentials. 
// Set password to "" for open networks. 
char ssid[] = "AndroidAP47A9"; 
char pass[] = "dyqz4659"; 
 
 
#define trigPin D6
#define echoPin D7
 
int PWMA=5;//Right side 
int PWMB=4;//Left side 
int DA=0;//Right reverse 
int DB=2;//Left reverse 
 
 
void setup(){ 
 Serial.println("Setup started...");
 // Debug console 
 Serial.begin(9600); 
 
  Serial.println("Setting up Blynk...");

 Blynk.begin(auth, ssid, pass); 

 pinMode(PWMA, OUTPUT); 
 pinMode(PWMB, OUTPUT); 
 pinMode(DA, OUTPUT); 
 pinMode(DB, OUTPUT); 

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

  Serial.println("Setup ended...");
 
} 
 
 
 
void loop(){ 
Blynk.run(); 


    long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance <50)
  {
   digitalWrite(PWMA, HIGH); 
   digitalWrite(DA, HIGH);   
   digitalWrite(PWMB, HIGH); 
   digitalWrite(DB, HIGH);
   delayMicroseconds(500);
     digitalWrite(PWMA, LOW); 
  digitalWrite(DA, LOW); 
     
  digitalWrite(PWMB, LOW); 
  digitalWrite(DB, LOW); 
  }
  
Serial.print("Distance: ");
 Serial.println(distance);
} 
 
 
 
// Handling Joystick data 
BLYNK_WRITE(V1){ 
int x = param[0].asInt(); 
int y = param[1].asInt();  


if(x==-1 && y==-1){             //BackWard and Left     
  digitalWrite(PWMA, LOW); 
  digitalWrite(DA, LOW); 
     
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, HIGH); 
 
}else if(x==-1 && y==0){        //Left Turn 
  digitalWrite(PWMA, 450); 
  digitalWrite(DA, HIGH); 
    
  digitalWrite(PWMB, 450); 
  digitalWrite(DB, LOW); 
 
}else if(x==-1 && y==1){        //Forward and Left     
  digitalWrite(PWMA, LOW); 
  digitalWrite(DA, LOW); 
    
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, LOW); 
 
}else if(x==0 && y==-1){        //BackWard     
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, HIGH); 
     
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, HIGH);
}else if(x==0 && y==0){        //Stay 
  digitalWrite(PWMA, LOW); 
  digitalWrite(DA, LOW); 
     
  digitalWrite(PWMB, LOW); 
  digitalWrite(DB, LOW); 
 
}else if(x==0 && y==1){        //Forward 
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, LOW); 
    
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, LOW); 
 
}else if(x==1 && y==-1){        //Backward and Right     
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, HIGH); 
     
  digitalWrite(PWMB, LOW); 
  digitalWrite(DB, LOW); 
 
}else if(x==1 && y==0){        //Right turn 
   digitalWrite(PWMA, 450); 
  digitalWrite(DA, LOW); 
   
  digitalWrite(PWMB, 450); 
  digitalWrite(DB, HIGH); 
 
}else if(x==1 && y==1){        //Forward and Right 
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, LOW); 
   
  digitalWrite(PWMB, LOW); 
  digitalWrite(DB, LOW);
 } 
 
}  
