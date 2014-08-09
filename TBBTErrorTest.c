#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int runATest(int testTime, int power){
	int i = 0;
	nMotorEncoder[motorA] = 0;
	motor[motorD] = power;
	int enValue;
	while(i<=(testTime*20)){
		enValue = nMotorEncoder[motorA];
		//WriteShort(Handle, Result, enValue);         // write 'sMessageToWrite' to the file
		//WriteByte(Handle, Result, CR);                      // write 'CR' to the file (carriage return)
		//WriteByte(Handle, Result, LF);                      // write 'LF' to the file (line feed)
		i += 1;
		wait1Msec(50);
		writeDebugStreamLine("%d", enValue);
	}
	writeDebugStreamLine("End of test with %d power and %d time", power, testTime);
	motor[motorD] = 0;
	wait1Msec(1000);
	return enValue;
}

task main()
{
	//TFileHandle   Handle;              // will keep track of our file
	//TFileIOResult Result;                // will store our IO results
	//string Name = "test.txt";   // the name of our file
	//short Size = 100;          // will store our file size
	//byte CR = 0x13;   // define CR (carriage return)
	//byte LF = 0x10;   // define LF (line feed)
	//Delete("test.txt", Result);
	//OpenWrite(Handle, Result, Name, Size);
int tr1, tr2, tr3, tr4, tr5, fin;
clearDebugStream();
nMotorEncoder[motorA] = 0;
wait1Msec(1000);
writeDebugStreamLine("Beginning tests");
	tr1 = runATest(60, 25);
	tr2 = runATest(60, 25);
	tr3 = runATest(60, 25);
	tr4 = runATest(60, 25);
	tr5 = runATest(60, 25);
	fin = (tr1+tr2+tr3+tr4+tr5)/5;
	writeDebugStreamLine("Trials: %d %d %d %d %d and Average: %d", tr1, tr2, tr3, tr4, tr5, fin);
	//runATest(30, 50);
	//runATest(30, 75);
	//runATest(60, 25);
	//runATest(60, 50);
	//runATest(60, 75);
	//runATest(120, 25);
	//runATest(120, 50);
	//runATest(120, 75);

	//Close(Handle, Result);                              // close the file (DON'T FORGET THIS STEP!)
}
