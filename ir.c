#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S2,     ,               sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
I fixed the original problem. 
It was that I was reading from sensor port 1 
Now itreads from S2

*/



task main()
{
	int values[5] = {100,100,100,100,100};
	motor[motorD] = 50;
	motor[motorE] = 50;
	motor[motorF] = -50;
	motor[motorG] = -50;
	bool isTurning = true;
	char readSensor[3] = {2, 0x10, 0x4C};
	char sensor[2];
	int average;
	while (isTurning == true)
	{
		wait1Msec(50);
		sendI2CMsg(S2, readSensor, 2);
		wait1Msec(10);
		readI2CReply(S2, sensor , 2);
		writeDebugStreamLine("%d", sensor);
		for(int i = 4; i > 0; i--)
		{
			values[i] = values[i-1];
			average += values[i];
		}
		values[0] = sensor;
		average /= 5;
		writeDebugStream("%d", average);
		if(sensor < average +2)
		{
			isTurning = false;
		}
	}
}
