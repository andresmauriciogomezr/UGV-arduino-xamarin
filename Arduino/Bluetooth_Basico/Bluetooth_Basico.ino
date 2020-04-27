#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
int led13=13; 
void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT que hemos creado
  Serial.begin(9600);   // Inicializamos  el puerto serie

  pinMode(led13,OUTPUT);
  digitalWrite(13,HIGH);
}
 
void loop()
{
  //Serial.write("probando");
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    digitalWrite(13,LOW);
    //Serial.write("sicas");
    Serial.write(BT.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
    digitalWrite(13,HIGH);
     BT.write(Serial.read());
  }
}
