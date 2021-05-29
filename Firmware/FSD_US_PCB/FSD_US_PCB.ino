// This code is written by Jawwad Patel
// For more details reach us at www.jawwadpatel.com
// mail us at contact@jawwadpatel.com

int flag=0;
int trigpin=0;
int echopin=1;
int relay=8;
int buzzer =4;
int r=2;
int g=3;


void setup() 
{
   pinMode(trigpin, OUTPUT);
   pinMode(echopin, INPUT);
   pinMode(8,OUTPUT); //relay 
   pinMode(4,OUTPUT); // buzzer (on=high)
   pinMode(2,OUTPUT); //red led common cathode (on=high)
   pinMode(3,OUTPUT); //green led common cathode (on=high)
  // pinMode(LED_BUILTIN, OUTPUT);
  }

void loop(){
  
  long duration, distance;
  
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
 
  duration = pulseIn(echopin, HIGH);
  distance = duration/24/2;
 
  if (distance<=6)
  {
    flag = flag+1;
    delay(50) ; //500 flag
   }

if (flag ==3) 
{
      digitalWrite(relay,HIGH); // relay on
      digitalWrite(buzzer,HIGH);  // buzzer on
      digitalWrite(r,LOW); // red off
      digitalWrite(g,HIGH); // green on
      delay(400);
      digitalWrite(relay,LOW); // relay off
      digitalWrite(buzzer,LOW);  // buzzer off
      digitalWrite(r,HIGH); // red on
      digitalWrite(g,LOW); // green off     
flag=5;
}



  else if(distance>10)
  {      
  flag=0;
       digitalWrite(relay,LOW); // relay off
       digitalWrite(buzzer,LOW);  // buzzer off
       digitalWrite(r,HIGH); // red on
       digitalWrite(g,LOW); // green off
  }
  
}
