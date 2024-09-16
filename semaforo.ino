int ledRojo     = 7,
    ledAmarillo = 8,
    ledVerde    = 9,     
    LED_ACTUAL  = 0; 
#define       BTN 2

bool botonPresionado = false;

void setup() {
  pinMode (BTN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN), peaton, FALLING);//RISING CHANGE EN VEZ DE FALLING TAMBIEN PUEDE SER USADO
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  if (botonPresionado){
    botonPresionado=false;
  } 
  cambiaA(ledRojo);
  delay(3000);
  cambiaA(ledAmarillo);
  delay(1000);
  cambiaA(ledVerde);
  delay(3000);
}

void peaton(){
  botonPresionado = true;
}

void cambiaA(int nuevoLed) {
  if(LED_ACTUAL != 0) digitalWrite(LED_ACTUAL, LOW);
  LED_ACTUAL = nuevoLed;
  digitalWrite(LED_ACTUAL, HIGH);
}