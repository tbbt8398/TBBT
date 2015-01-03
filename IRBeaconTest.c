#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S2,     HTIRS2,         sensorI2CCustomFastSkipStates)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
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

#include "C:\Program Files (x86)\Robomatter Inc\ROBOTC Development Environment 4.X\Sample Programs\NXT\3rdPartyDriverLibrary\include\hitechnic-irseeker-v2.h"

task main()
{
int _dirAC = 0;
int acS1, acS2, acS3, acS4, acS5 = 0;
int maxSig = 0; // the max signal strength from the seeker.
int val = 0; // the translated directional value.
// we are going to set DSP mode to 1200 Hz.
 tHTIRS2DSPMode _mode = DSP_1200;
 // attempt to set to DSP mode.
 if (HTIRS2setDSPMode(HTIRS2, _mode) == 0)
 {
 // unsuccessful at setting the mode.
 // display error message.
 eraseDisplay();
 displayCenteredTextLine(0, "ERROR!");
 displayCenteredTextLine(2, "Init failed!");
 displayCenteredTextLine(3, "Connect sensor");
 displayCenteredTextLine(4, "to Port 1.");
 // make a noise to get their attention.
 playSound(soundBeepBeep);
 // wait so user can read message, then leave main task.
 wait1Msec(3000);
 return;
 }
 eraseDisplay();
 // loop continuously and read from the sensor.
 while(maxSig < 130)
 {
 // read the current modulated signal direction
 _dirAC = HTIRS2readACDir(HTIRS2);
 if (_dirAC < 0){
 // error! - write to debug stream and then break.
 writeDebugStreamLine("Read dir ERROR!");
 break;
 }
 // Get the AC signal strength values.
 if (!HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS5 ))
 {
 // error! - write to debug stream and then break.
 writeDebugStreamLine("Read sig ERROR!");
 break;
 } else {
 // find the max signal strength of all detectors.
 maxSig = (acS1 > acS2) ? acS1 : acS2;
 maxSig = (maxSig > acS3) ? maxSig : acS3;
 maxSig = (maxSig > acS4) ? maxSig : acS4;
 maxSig = (maxSig > acS5) ? maxSig : acS5;
 }
 // display info
 displayCenteredBigTextLine(1, "Dir=%d", _dirAC);
 displayCenteredBigTextLine(4, "Sig=%d", maxSig);
 // figure out which direction to go...
 // a value of zero means the signal is not found.
 // 1 corresponds to the far left (approx. 8 o'clock position).
 // 5 corresponds to straight ahead.
 // 9 corresponds to far right.
 // first translate directional index so 0 is straight ahead.
 val = _dirAC - 5;

 // calculate left and right motor speeds.
 motor[motorD] = 10 - 10 * val;
 motor[motorG] = 10 + 10 * val;
 // wait a little before resuming.
 wait1Msec(20);
 }
}
