int w = 10,x = 11,y = 12,z = 13;
void setup()  {
  pinMode(5, INPUT);//left sensor 1      
  pinMode(6, INPUT); //left sensor 2   
  pinMode(7, INPUT); //middle sensor3   
  pinMode(8, INPUT); //right sensor 4   
  pinMode(9, INPUT); //right  sensor5  
   
  pinMode(w, OUTPUT);  //LEFT MOTOR.   
  pinMode(x, OUTPUT);   
  pinMode(y, OUTPUT);  //RIGHT MOTOR.   
  pinMode(z, OUTPUT); 

  Serial.begin(9600);
}
  
  // put your setup code here, to run once 
  void loop() {   
    int a = !digitalRead(5);   
    int b = !digitalRead(6);
    int c = !digitalRead(7);   
    int d = !digitalRead(8);    
    int e = !digitalRead(9);

    if (
      (a == LOW && b == LOW && c == HIGH && d==LOW && e== LOW)
      ||(a == LOW && b == HIGH && c == HIGH && d==HIGH && e== LOW)
      ||(a == HIGH && b == HIGH && c == HIGH && d==HIGH && e== HIGH))//FORWARD 
      {
          digitalWrite(10,HIGH);
          digitalWrite(11,LOW);
          digitalWrite(12,HIGH);
          digitalWrite(13,LOW); 
//          Serial.println("Forword");
          
      } 
    if ((a == LOW && b == HIGH && c == LOW && d==LOW && e==LOW)
    ||(a==HIGH && b== HIGH && c==LOW &&d== LOW  &&e==LOW)
    ||(a==HIGH &&  b==  HIGH &&  c==HIGH &&d==  LOW &&e==LOW)
    ||(a==HIGH  &&  b== LOW  && c==LOW &&d== LOW &&e==LOW)
    ||(a==LOW && b== HIGH && c==HIGH &&d== LOW &&e==LOW)
    ||(a==HIGH && b== HIGH && c==HIGH && d==HIGH && e==LOW)) //LEFT TURN   
    {     
         
      digitalWrite(w, HIGH);     
      digitalWrite(x,  LOW);     
      digitalWrite(y, LOW);     
      digitalWrite(z, HIGH); 
//      Serial.println("left"); 
       

    } 
    if ((a == LOW && b == LOW && c == LOW && d==HIGH && e==LOW)
    ||(a==LOW && b== LOW && c==LOW &&d== HIGH &&e==HIGH)
    ||(a==LOW  && b==  LOW && c==HIGH  &&d== HIGH  &&e==HIGH)
    ||(a==LOW &&  b== LOW  && c==LOW &&d== LOW &&e==HIGH)
    ||(a==LOW && b== HIGH && c==HIGH &&d== HIGH &&e==HIGH)
    ||(a==LOW && b== LOW && c==HIGH &&d== HIGH &&e==LOW)) //RIGHT TURN    
    {     
      
      digitalWrite(w, LOW); 
      digitalWrite(x, HIGH);     
      digitalWrite(y, HIGH);     
      digitalWrite(z, LOW); 
//      Serial.println("write");
    } 
    if (a == LOW && b == LOW && c == LOW && d==LOW && e== LOW)  // BACK       
    {     
          digitalWrite(10,HIGH);
          digitalWrite(11,LOW);
          digitalWrite(12,HIGH);
          digitalWrite(13,LOW);   
//      Serial.println("back");

       
      } 
  }
