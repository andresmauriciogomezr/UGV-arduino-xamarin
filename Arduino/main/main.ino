

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
void setup() {
  
  Serial.begin(9600);
  //pinMode (`, OUTPUT);
  //pinMode (front_right_b, OUTPUT);
   
}

void loop() {
  forward(100);
  //backward(100);
//forward(50);
  // while(Serial.available()>0)
  // {
    
  //   msg=Serial.read();
  //   if(msg=='u')
  //   {
  //     forward(50);
  //   }  

  //   if(msg=='d')
  //   {
  //     backward(50);
  //   }

  //   if(msg=='l')
  //   {
  //     forward(0);
  //   }
    
  // }
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
