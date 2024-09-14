#include <EEPROM.h>
#define BOTON1      2 //Buenas prácticas de programación: escribir todos los define en mayúsculas
#define BOTON2      3 //Los pines 2 y 3 son para interrupciones
#define TIME        5000
#define BAUDRATE    9600 
#define I_EEPROMP   0
#define MAXVOL      100
#define MINVOL      0

unint8__t volumen=EEPROM.read(I_EEPROMP);

volatile unsigned long lasttime=0;
volatile unsigned long debounce=60;
volatile unsigned long lasttime2=0;

void setup(){
    pinmode(BOTON1, INPUT_PULLUP); //INPUT_PULLUP es para usar la resistencia de la placa
    pinmode(BOTON2, INPUT_PULLUP);
    attatchInterrupt(digitalPinToInterrupt(BOTON1), up, FALLING); //FALLING detecta el flanco de bajada
    attatchInterrupt(digitalPinToInterrupt(BOTON2), down, FALLING);
}

void loop(){//PARA LA PRÁCTICA 2 USAR BANDERAS Y TRABAJAR AQUÍ
    delay(TIME)
}

void up(){
    if(millis()-lasttime>debounce){ //millis es un tipo de temporizador(reloj)

        if(volumen<MAXVOL){
            volumen++;
            serial.println"VOLUMEN(+): ";
            serial.println (volumen);
            EEPROM.write(I_EEPROMP,value)
        }
        lasttime=millis();//podemos llamar a millis las veces que queremos porque nos retornará al reloj
    }
}

void down(){
   if(millis()-lasttime<debounce){
        if(volumen>MINVOL){
            volumen--;
            serial.println"VOLUMEN(+): ";
            serial.println (volumen);
        }
    lasttime=millis();
   }
}