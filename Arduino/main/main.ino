#include <SoftwareSerial.h>


// MOTOR TRASERO DERECHO
int tail_right_b = 13; 
int tail_right_a = 12;
int tail_right_velocity = 11;

// MOTOR DELANTERO DERECHO
int front_right_a = 8; 
int front_right_b = 9;
int front_right_velocity = 10;

// MOTOR TRASERO IZQUIERDO
int tail_left_a = 6; 
int tail_left_b = 7;
int tail_left_velocity = 5;

// MOTOR DELANTERO IZQUIERDO
int front_left_a = 4; 
int front_left_b = 2;
int front_left_velocity = 3;

int msg=0;

#define BT_RX A2
#define BT_TX A3

SoftwareSerial blue(BT_RX, BT_TX);   //Crea conexion al bluetooth - PIN 2 a TX y PIN 3 a RX


char NOMBRE[21]  = "Mauricio"; // Nombre de 20 caracteres maximo
char BPS         = '4';     // 1=1200 , 2=2400, 3=4800, 4=9600, 5=19200, 6=38400, 7=57600, 8=115200
char PASS[5]    = "1111";   // PIN O CLAVE de 4 caracteres numericos     
 

void setup() {
  Serial.begin(9600);
  blue.begin(9600);        // Inicializamos el puerto serie BT que hemos creado
  
   int pins[] = {1, 2, 3,
                4, 5, 6,
                6, 7, 8,
                9, 10, 11, 12, 13};
  for (int p : pins) pinMode(p, OUTPUT);
  // Serial.begin(9600);
  //pinMode (`, OUTPUT);
  //pinMode (front_right_b, OUTPUT);

  // pinMode(13,OUTPUT);
    // digitalWrite(13,HIGH); // Enciende el LED 13 durante 4s antes de configurar el Bluetooth
    // delay(4000);
    
    // digitalWrite(13,LOW); // Apaga el LED 13 para iniciar la programacion
    
    // blue.print("AT");  // Inicializa comando AT
    // delay(1000);
 
    // blue.print("AT+NAME"); // Configura el nuevo nombre 
    // blue.print(NOMBRE);
    // delay(1000);                  // espera 1 segundo
 
    // blue.print("AT+BAUD");  // Configura la nueva velocidad 
    // blue.print(BPS); 
    // delay(1000);
 
    // blue.print("AT+PIN");   // Configura el nuevo PIN
    // blue.print(PASS); 
    // delay(1000); 
   
}

void loop() {
  
  if (blue.available()) {
    char cmd = blue.read();
    Serial.print("Recibido: "); Serial.println(cmd);

    switch (cmd) {
      case 'u': forward(50); delay(1000); break;
      case 'd': backward(50); delay(1000); break;
      case 'l': forward(0);    break;
      default:  forward(0);    break;
    }
  }

  //  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  //  {
  //     blue.write("u");
  //  }
//   forward(0);
//   //backward(100);
// //forward(50);
//   while(blue.available()>0)
//   {
//   forward(50);
    
//     msg=blue.read();
//     if(msg=='u')
//     {
//       forward(50);
//     }  

//     if(msg=='d')
//     {
//       backward(50);
//     }

//     if(msg=='l')
//     {
//       forward(0);
//     }
    
//   }
}

void backward(int velocity){
  right_front_wheel(0,velocity);
  left_front_wheel(0,velocity);
  right_back_wheel(0, velocity);
  left_back_wheel(0,velocity);
}

void forward(int velocity){
  right_front_wheel(1,velocity);
  left_front_wheel(1,velocity);
  right_back_wheel(1, velocity);
  left_back_wheel(1,velocity);
}

void right_back_wheel(byte direction, int velocity){
  switch(direction){
    case 0:
      digitalWrite (tail_right_a, LOW);
      digitalWrite (tail_right_b, HIGH);      
    break;
    case 1:
      digitalWrite (tail_right_a, HIGH);
      digitalWrite (tail_right_b, LOW);      
  }
  analogWrite (tail_right_velocity, velocity);  
}

void right_front_wheel(byte direction, int velocity){
  switch(direction){
    case 0:
      digitalWrite (front_right_a, LOW);
      digitalWrite (front_right_b, HIGH);
    break;
    case 1:
      digitalWrite (front_right_a, HIGH);
      digitalWrite (front_right_b, LOW);      
  }
  analogWrite(front_right_velocity, velocity);  
}

void left_back_wheel(byte direction, int velocity){
  switch(direction){
    case 0:
      digitalWrite (tail_left_a, LOW);
      digitalWrite (tail_left_b, HIGH);
    break;
    case 1:
      digitalWrite (tail_left_a, HIGH);
      digitalWrite (tail_left_b, LOW);      
  }
  analogWrite (tail_left_velocity, velocity);  
}

void left_front_wheel(byte direction, int velocity){
  switch(direction){
    case 0:
      digitalWrite (front_left_a, LOW);
      digitalWrite (front_left_b, HIGH);
    break;
    case 1:
      digitalWrite (front_left_a, HIGH);
      digitalWrite (front_left_b, LOW);
  }
  analogWrite (front_left_velocity, velocity);  
}
