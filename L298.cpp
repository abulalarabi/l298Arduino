//#include "Arduino.h"
#include "L298.h"


// drive function
void L298::drive((int leftMotorSpeed, int rightMotorSpeed)
{

	// trim values between -255 and +255 for safety (8 bit)
	leftMotorSpeed = leftMotorSpeed > 255 ? 255 : leftMotorSpeed;
	leftMotorSpeed = leftMotorSpeed < -255 ? -255 : leftMotorSpeed;

	rightMotorSpeed = rightMotorSpeed > 255 ? 255 : rightMotorSpeed;
	rightMotorSpeed = rightMotorSpeed < -255 ? -255 : rightMotorSpeed;

	// left motor control
	if(leftMotorSpeed==0)			// left motor off
	{
		digitalWrite(IN1, 0);
		analogWrite(IN2, 0);
	}

	else if(leftMotorSpeed>0)		// left motor forward
	{
		digitalWrite(IN1, 0);
		analogWrite(IN2, leftMotorSpeed);
		leftDir = false;
	}

	else							// left motor reverse
	{
		digitalWrite(IN1, 1);
		analogWrite(IN2, 255 + leftMotorSpeed);
		leftDir = true;
	}


	// right motor control
	if(rightMotorSpeed==0)		// right motor off
	{
		digitalWrite(IN3, 0);
		analogWrite(IN4, 0);
	}

	else if(rightMotorSpeed>0)	// right motor forward
	{
		digitalWrite(IN3, 0);
		analogWrite(IN4, rightMotorSpeed);
		rightDir = false;
	}

	else						// right motor reverse
	{
		digitalWrite(IN3, 0);
		analogWrite(IN4, 255 + rightMotorSpeed);
		rightDir = true;
	}
  
}

// brake function
void L298::brake(unsigned int duration=20)
{
	// braking left motor
	digitalWrite(IN1, !leftDir);
	analogWrite(IN2, 128);

	// braking right motor
	digitalWrite(IN3, !leftDir);
	analogWrite(IN4, 128);

	delay(duration);

	// release motors
	drive(0,0);
}