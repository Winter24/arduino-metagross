#include <Arduino.h>
#include <PCA9685.h>

#define F_LEFT  1
#define F_RIGHT 2
#define B_LEFT  3
#define B_RIGHT 4
#define PWM_MIN  150
#define PWM_MAX  600

//Define leg
//Each leg has 3 joints. Each joint is a channel
struct leg {
    int coxa;
    int femur;
    int tibia;
};

struct leg legs[4];
PCA9685 pwm(0x40);

void servoWrite(uint8_t channel, int deg) {
    uint16_t pulselen = map(deg, 0, 180, PWM_MIN, PWM_MAX);
    pwm.setPWM(channel, pulselen);
    Serial.println(deg);
    delay(200);
}

void setup() {
    Serial.begin(9600);
    Wire.begin();
    pwm.begin();
    pwm.setFrequency(50);
    
    //Set up channels
    for (int i = 0; i < 4; i++) {
        legs[i].tibia = 3*i;
        legs[i].femur = 3*i + 1;
        legs[i].coxa  = 3*i + 2;
    }
    
    // servoWrite(legs[0].tibia, 0);
    // servoWrite(legs[0].femur, 0);
    // servoWrite(legs[0].coxa,  0);
}

void loop() {
    servoWrite(legs[0].tibia, 170);
    servoWrite(legs[0].femur, 20);
    servoWrite(legs[1].tibia, 10);
    servoWrite(legs[1].femur, 150);
    servoWrite(legs[2].tibia, 10);
    servoWrite(legs[2].femur, 150);
    servoWrite(legs[3].tibia, 170);
    servoWrite(legs[3].femur, 40);

    delay(2000);

    // servoWrite(legs[0].tibia, 80);
    // servoWrite(legs[0].femur, 80);
    // servoWrite(legs[1].tibia, 90);
    // servoWrite(legs[1].femur, 90);
    // servoWrite(legs[2].tibia, 80);
    // servoWrite(legs[2].femur, 80);
    // servoWrite(legs[3].tibia, 90);
    // servoWrite(legs[3].femur, 90);

    delay(1000);

    // servoWrite(legs[0].femur, 110);
    // servoWrite(legs[1].femur, 60);

    // servoWrite(legs[2].femur, 60);
    // servoWrite(legs[3].femur, 110);

}
