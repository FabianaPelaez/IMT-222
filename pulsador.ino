#define LED 2
#define PUL 4
void setup  (){
    pinMode(LED,OUTPUT);
    pinMode(PUL,INPUT);
}
void loop () {
    if(digitalRead(PUL)){
        digitalWrite(LED,55);

    } else{
        digitalWrite(LED,0);
    }
}