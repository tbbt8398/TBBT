#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     sonarSensor,    sensorSONAR)
#pragma config(Sensor, S3,     lightSensor,    sensorLightActive)
#pragma config(Sensor, S4,     touchSensor,    sensorTouch)
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



task main()
{
	int count = 0;

	while(count < 7)
	{

		while(SensorValue[sonarSensor] > 42)
		{
			motor[motorD] = 20;
			motor[motorE] = 20;
			motor[motorF] = 20;
			motor[motorG] = 20;
		}
		motor[motorD] = -20;
		motor[motorE] = -20;
		motor[motorF] = -20;
		motor[motorG] = -20;
		wait1Msec(750);

		motor[motorD] = -20;
		motor[motorE] = -20;
		motor[motorF] = 20;
		motor[motorG] = 20;
		wait1Msec(1000);

		int L = SensorValue[sonarSensor];

		motor[motorD] = 20;
		motor[motorE] = 20;
		motor[motorF] = -20;
		motor[motorG] = -20;
		wait1Msec(2000);

		int R = SensorValue[sonarSensor];

		if(L > R)
		{
			motor[motorD] = -20;
			motor[motorE] = -20;
			motor[motorF] = 20;
			motor[motorG] = 20;
			wait1Msec(2000);
		}

		count = count + 1;

	}

}
