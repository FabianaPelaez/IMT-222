#include <EEPROM.h>

#define BOTON1      2    
#define BOTON2      3    
#define TIME        1000
#define BAUDRATE    9600 
#define I_EEPROMP   0    // EEPROM para almacenar el volumen
#define MAXVOL      100  
#define MINVOL      0    


uint8_t volumen = EEPROM.read(I_EEPROMP);  
bool flagMas = false;        
bool flagMenos = false;      
bool flagReset = false;          

unsigned long lasttime1 = 0;
unsigned long lasttime2 = 0;
const unsigned long debounceDelay = 60;    // tiempo de antirrebote

void setup() {
    pinMode(BOTON1, INPUT_PULLUP); 
    pinMode(BOTON2, INPUT_PULLUP);
    
    attachInterrupt(digitalPinToInterrupt(BOTON1),Aumentar, FALLING);
    attachInterrupt(digitalPinToInterrupt(BOTON2),Disminuir, FALLING);

    Serial.begin(BAUDRATE);
    Serial.print("Volumen inicial: ");
    Serial.println(volumen);
}

void loop() {
    static unsigned long previousMillis = 0;
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis >= TIME) {
        Serial.print("Volumen actual: ");
        Serial.println(volumen);
        previousMillis = currentMillis;
    }

    // bandera aumento de volumen
    if (flagAumentar) {
        if (millis() - lasttime1 > debounceDelay) { // antirrebote
            if (volumen < MAXVOL) {
                volumen++;
                EEPROM.write(I_EEPROMP, volumen); // volumen guardado en la EEPROM
                Serial.print("VOLUMEN(+): ");
                Serial.println(volumen);
            }
            lasttime1 = millis();
        }
        flagAumentar = false; // bandera restablecida
    }

    // bandera disminución de volumen
    if (flagDisminuir) {
        if (millis() - lasttime2 > debounceDelay) { // antirrebote
            if (volumen > MINVOL) {
                volumen--;
                EEPROM.write(I_EEPROMP, volumen); // volumen guardado en la EEPROM
                Serial.print("VOLUMEN(-): ");
                Serial.println(volumen);
            }
            lasttime2 = millis();
        }
        flagDisminuir = false; // bandera restablecida
    }

    // bandera para restablecer el volumen
    if (flagReset) {
        volumen = 0;
        EEPROM.write(I_EEPROMP, volumen); // volumen guardado en la EEPROM
        Serial.println("Volumen en 0");
        flagReset = false; // bandera restablecida 
    }

    // ambos botones presionados, activar la bandera de reset
    if (digitalRead(BOTON1) == LOW && digitalRead(BOTON2) == LOW) {
        flagReset = true;
        delay(500);
    }
}

// interrupción para aumentar el volumen
void Aumentar() {
    flagAumentar = true; //  bandera activa para aumentar el volumen
}

// interrupción para disminuir el volumen
void Disminuir() {
    flagDisminuir = true; // bandera activa para disminuir el volumen
}

