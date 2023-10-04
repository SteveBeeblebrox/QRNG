// (c) Trin Wasinger 2023
// Code for an Arduino QRNG

namespace Quantum {
    const int LASER_DIODE_PIN = 12, VERTICAL_PIN = A0, HORIZONTAL_PIN = A1;
    const int DELAY = 125; // Adjust as needed
    void init() {
        pinMode(LASER_DIODE_PIN, OUTPUT);
    }

    byte rand_bit() {
        float v, h;
        while(true) {
            digitalWrite(LASER_DIODE_PIN, HIGH);
            delay(DELAY);
            
            v = analogRead(VERTICAL_PIN);
            h = analogRead(HORIZONTAL_PIN);

            delay(DELAY);
            digitalWrite(LASER_DIODE_PIN, LOW);

            // Vertical -> 0, Horizontal -> 1
            if(v > h) {
                return 0;
            } else if(h > v) {
                return 1;
            } else {
                continue;
            }
        }
    }

    template<typename T>
    T rand() {
        T t = T();
        for(size_t i = 0; i < sizeof(T)*8; i++) {
            t<<=1;
            t|=rand_bit();
        }
        return t;
    }
    
    template<>
    bool rand() {
        return rand_bit();
    }

}

void setup() {
    Serial.begin(9600);
    while(!Serial);
    Quantum::init();
}

void loop() {
    Serial.print(Quantum::rand_bit());
    delay(1000);
}