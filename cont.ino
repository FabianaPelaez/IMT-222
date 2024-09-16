#define PULS 2 
#define PASO 1
int a = 5;
int b = 6;
int c = 7;
int d = 8;
int e = 9;
int f = 11;
int g = 10;
unsigned int cont= ;
volatile int contador = 1;
void setup(){
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(2, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(3), interrupcion, FALLING);
  
    pinMode(PULS, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(PULS), interrumpir, FALLING);

}
void loop(){
     for (int i = contador; i <= 9; i++) {
    showNumber(i);
  }
}
void showNumber(int num) {
  switch(num) {
    case 0:
      digitalWrite(a, 1); digitalWrite(b, 1); digitalWrite(c, 1); digitalWrite(d, 1); 
      digitalWrite(e, 1); digitalWrite(f, 1); digitalWrite(g, 0);
      break;
    case 1:
      digitalWrite(a, 0); digitalWrite(b, 1); digitalWrite(c, 1); digitalWrite(d, 0); 
      digitalWrite(e, 0); digitalWrite(f, 0); digitalWrite(g, 0);
      break;
    case 2:
      digitalWrite(a, 1); digitalWrite(b, 1); digitalWrite(c, 0); digitalWrite(d, 1); 
      digitalWrite(e, 1); digitalWrite(f, 0); digitalWrite(g, 1);
      break;
    case 3:
      digitalWrite(a, 1); digitalWrite(b, 1); digitalWrite(c, 1); digitalWrite(d, 1); 
      digitalWrite(e, 0); digitalWrite(f, 0); digitalWrite(g, 1);
      break;
    case 4:
      digitalWrite(a, 0); digitalWrite(b, 1); digitalWrite(c, 1); digitalWrite(d, 0); 
      digitalWrite(e, 0); digitalWrite(f, 1); digitalWrite(g, 1);
      break;
    case 5:
      digitalWrite(a, 1); digitalWrite(b, 0); digitalWrite(c, 1); digitalWrite(d, 1); 
      digitalWrite(e, 0); digitalWrite(f, 1); digitalWrite(g, 1);
      break;
    case 6:
      digitalWrite(a, 1); digitalWrite(b, 0); digitalWrite(c, 1); digitalWrite(d, 1); 
      digitalWrite(e, 1); digitalWrite(f, 1); digitalWrite(g, 1);
      break;
    case 7:
      digitalWrite(a, 1); digitalWrite(b, 1); digitalWrite(c, 1); digitalWrite(d, 0); 
      digitalWrite(e, 0); digitalWrite(f, 0); digitalWrite(g, 0);
      break;
    case 8:
      digitalWrite(a, 1); digitalWrite(b, 1); digitalWrite(c, 1); digitalWrite(d, 1); 
      digitalWrite(e, 1); digitalWrite(f, 1); digitalWrite(g, 1);
      break;
    case 9:
      digitalWrite(a, 1); digitalWrite(b, 1); digitalWrite(c, 1); digitalWrite(d, 1); 
      digitalWrite(e, 0); digitalWrite(f, 1); digitalWrite(g, 1);
      break;
  }
  delay(1000);
}

void interrumpir(){
    //cont=cont +1
    cont+=PASO;
}
void interrupcion() {
  contador = 1;
}