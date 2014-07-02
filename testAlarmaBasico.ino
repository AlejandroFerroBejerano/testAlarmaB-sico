#include <Process.h>
#include <Console.h>

Process date;                 // process used to get the date
String timeString;

byte orden;
boolean panicActivated = false;
boolean sound = true;
boolean repeat = false;

int ledgreen=13;
int ledred=12;
int ligth = 11;
int buzzer=10;
int btnpanic = 2;
//0-Listo,1-Armado,2-Alarma
byte estado = 0;

//Zonas
int z0;


void setup() {
  Bridge.begin();
  Console.begin();
  
  pinMode(ledgreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(btnpanic,INPUT);
  
  if (!date.running()) {
    date.begin("date");
    date.addParameter("+%d/%m/%Y - %T");
    date.run();
  }
  
  timeString = date.readString();
  // Wait for Console port to connect
  while (!Console);
  Console.println(timeString + ": SISTEMA LISTO" );
  attachInterrupt(0,Btnpanic,RISING);
  digitalWrite(ledgreen,HIGH);
  
}

void loop() {
  if (Console.available() > 0) {
   reedCommand(); 
  }
  //restart time process
  if (!date.running()) {
      date.begin("date");
      date.addParameter("+%d/%m/%Y - %T");
      date.run();
  }
  
  if (panicActivated == true){
        Console.println("ATRACO EN PROCESO "+timeString);
        alarm();
  }
  
   if (estado == 1 || estado == 2){
      systemarmed();
      checkA0();
      if (estado == 2 ){
        alarm();ligthOn();
        if (sound == true)alarmSound();
      }
  }
}

void checkA0(){
  z0= analogRead(A0);
  if ((820 <= z0 && z0 <= 840) || repeat == true){
    estado = 2; repeat = true;
    if (sound = true) Console.println("Alarma Caja Fuerte "+ timeString);
  }
  
}

void Btnpanic(){
  panicActivated = true;
  
}

void systemarmed(){
    digitalWrite(ledgreen,LOW);
    delay(800);
    digitalWrite(ledgreen,HIGH);  
    delay(800);
}

void alarm(){
  analogWrite(ledred,255);
  delay(500);
  analogWrite(ledred,0);  
  delay(500);
}

void alarmSound(){
   analogWrite(buzzer,255);
   delay(50);
   analogWrite(buzzer,50);
   delay(100);
}

void soundOff(){
  analogWrite(buzzer,0);
  sound= false;
}
void ligthOn(){
  analogWrite(ligth, 255);
}

void desarmar(){
   estado = 0;
   repeat = false;
   panicActivated = false;
   analogWrite(buzzer,0);
   digitalWrite(ledgreen,HIGH);
   digitalWrite(ledred,LOW);
   digitalWrite(ligth,LOW);
}
void armar(){
   estado = 1 ;  
}
void reedCommand(){
 timeString = date.readString();
 orden = Console.read(); 
 if (orden == 'D') {
   Console.println("*** Desarmado " +timeString+ " ***");
   desarmar();
 }
 if (orden == 'A') {
   Console.println("*** Armado " +timeString+ " ***");
   armar();
 }
 if (orden == 'S'){
   soundOff();
   repeat = false;
   panicActivated = false;
   Console.println("*** Silenciado " +timeString+ " ***");
 }
 if (orden == 'R'){
   Console.println("*** Rearmado " +timeString+ " ***");
   desarmar();
   armar();
 }
}
