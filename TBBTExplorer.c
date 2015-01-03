#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     sonarSensor,    sensorSONAR)
#pragma config(Sensor, S3,     lightSensor,    sensorLightActive)
#pragma config(Sensor, S4,     touchSensor,    sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int driveSpeed = 20;
	int turnSpeed = driveSpeed/2;


	int count = 0;

	while(count < 7)
	{

		while(SensorValue[sonarSensor] > 30)
		{
			motor[motorD] = driveSpeed;
			motor[motorE] = driveSpeed;
			motor[motorF] = driveSpeed;
			motor[motorG] = driveSpeed;
		}
		motor[motorD] = -driveSpeed;
		motor[motorE] = -driveSpeed;
		motor[motorF] = -driveSpeed;
		motor[motorG] = -driveSpeed;
		wait1Msec(500);

		motor[motorD] = -turnSpeed;
		motor[motorE] = -turnSpeed;
		motor[motorF] = turnSpeed;
		motor[motorG] = turnSpeed;
		wait1Msec(1000);

		int L = SensorValue[sonarSensor];

		motor[motorD] = turnSpeed;
		motor[motorE] = turnSpeed;
		motor[motorF] = -turnSpeed;
		motor[motorG] = -turnSpeed;
		wait1Msec(2000);

		int R = SensorValue[sonarSensor];

		if(L > R)
		{
			motor[motorD] = -turnSpeed;
			motor[motorE] = -turnSpeed;
			motor[motorF] = turnSpeed;
			motor[motorG] = turnSpeed;
			wait1Msec(2000);
		}

		count = count + 1;

	}

}
