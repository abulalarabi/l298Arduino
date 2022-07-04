#include "Arduino.h"
#ifndef L298_H
#define L298_H
#endif

class L298{
    private:
        //bool SIXPIN = false;
        byte IN1, IN2, IN3, IN4;

    public:
        //void init6(byte enA, byte in1, byte in2, byte in3, byte in4, byte enB);
        void init(byte in1, byte in2, byte in3, byte in4);

}