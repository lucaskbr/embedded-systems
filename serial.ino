//Interrupts using Arduino - pull down on pins 2 and 3
//Led no pino 13

#include<LiquidCrystal.h>                        // Including lcd display library
LiquidCrystal lcd (12,11,7, 6, 5, 4);              // Define LCD display pins RS,E,D4,D5,D6,D7

void setup()   
{
  lcd.begin(16,2);                              //  setting LCD as 16x2 type
  lcd.setCursor(0,0);
  lcd.print(" Comun. Serial! ");                                    
  lcd.setCursor(0,1);
  lcd.print("protocolo serial");
  delay(3000);                                                     
  lcd.clear();  
  
  pinMode(13,OUTPUT);  
  
  Serial.begin(9600);
 
}

int i = 1;

void loop()                                                      
{  
  if(i == 1) {
   lcd.clear();                                                   
   lcd.print("Aguardando...");                                           
   i = 0;
  }

}

void serialEvent() {

  String cmd = Serial.readStringUntil('-');
  String val = Serial.readStringUntil('-');
  
  if(cmd == "led"){
    lcd.clear();
    lcd.print("Led acionado!");
  	if(val == "1") digitalWrite(13, HIGH);
    else           digitalWrite(13, LOW);    
  }
  if(cmd == "nome"){
    lcd.clear();
    lcd.print("Seu nome...");
    Serial.println("Edras");
  }
  if(cmd == "soma"){
    String val2 = Serial.readStringUntil('-');
    int a = val.toInt();
    int b = val2.toInt();
    lcd.clear();
    lcd.print("Soma "+val+"+"+val2+"="+String(a+b));
    Serial.println(a+b);
  }
  i = 1;
  delay(2000);
    
}
