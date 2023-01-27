/*
MIT License

Copyright (c) 2023 Abul Al Arabi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Arduino.h"
#ifndef L298_H
#define L298_H
#endif

class L298{
    private:
        //bool SIXPIN = false;
        byte IN1, IN2, IN3, IN4;
        bool leftDir = false;
        bool rightDir = false;
        bool esp;

    public:
        L298(byte in1, byte in2, byte in3, byte in4, bool esp = false)
        {
            IN1 = in1;
            IN2 = in2;
            IN3 = in3;
            IN4 = in4;
            
            pinMode(IN1, OUTPUT);
            digitalWrite(IN1, LOW);
            pinMode(IN3, OUTPUT);
            digitalWrite(IN3, Low);
            
            /*
            if(esp){

                ledcAttachPin(IN2, 0);
                ledcSetup(0, 1000, 8);

                ledcAttachPin(IN4, 1);
                ledcSetup(1, 1000, 8);
            }
            */
        }
        //void init6(byte enA, byte in1, byte in2, byte in3, byte in4, byte enB);
        //void init(byte in1, byte in2, byte in3, byte in4, bool esp = false);
        void drive(int leftMotorSpeed, int rightMotorSpeed);
        void brake(unsigned int duration=20);
}