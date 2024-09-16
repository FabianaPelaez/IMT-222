#define LED1 13
#define LED2 12
#define BTN 2
#define TIME 5000
bool flag = false;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BTN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BTN),interrumpir, FALLING);
}

void loop() {
  digitalWrite(LED1, 1);
  delay(TIME);
  digitalWrite(LED1, 0);
  delay(TIME);
}
void interrumpir(){
  flag=!flag;//con el signo se niega
  digitalWrite(LED2, flag);