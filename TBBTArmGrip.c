#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     sonarSensor,    sensorSONAR)
#pragma config(Sensor, S3,     lightSensor,    sensorLightActive)
#pragma config(Sensor, S4,     touchSensor,    sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C3_1,    armServo,             tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    gripServo,            tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){
	int driveSpeed = 20;
	int turnSpeed = driveSpeed/2;

	playSoundFile("Bang.rso");
	wait1Msec(1000);
	servo[armServo] = 226;
	wait1Msec(2000);
	servo[gripServo] = 255;
	wait1Msec(2000);
	//setup
	motor[motorD] = driveSpeed;
	motor[motorE] = driveSpeed;
	motor[motorF] = driveSpeed;
	motor[motorG] = driveSpeed;
	wait1Msec(2000);
	//moveToCup
	motor[motorD] = 0;
	motor[motorE] = 0;
	motor[motorF] = 0;
	motor[motorG] = 0;
	wait1Msec(1000);
	int temp = 220;
	while(SensorValue[touchSensor] > 200){
		servo[gripServo] = temp - 1;
		temp = temp - 1;
	}
	//close Grip
	servo[armServo] = 0;
	wait1Msec(4000);
	//lift arm
	motor[motorD] = driveSpeed;
	motor[motorE] = driveSpeed;
	motor[motorF] = driveSpeed;
	motor[motorG] = driveSpeed;
	wait1Msec(1500);
	//move to bucket
	while(SensorValue[touchSensor] < 200){
		servo[gripServo] = temp + 1;
		temp = temp + 1;
	}
	//release cup
	motor[motorD] = -driveSpeed;
	motor[motorE] = -driveSpeed;
	motor[motorF] = -driveSpeed;
	motor[motorG] = -driveSpeed;
	wait1Msec(2000);
	//move back!
}
