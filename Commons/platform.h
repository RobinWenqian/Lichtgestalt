#ifndef PLATFORM_H
#define PLATFORM_H

/******Board Version*****/
#define BOARD_LICHTBRD_V1 1

/******Air Frame*****/
#define AIRFRAME_LICHT160 1
#if AIRFRAME_F450
	#define THRCMDRATIO 1
	#define VEHICLE_MASS 1300//g
	#define ROTOR_DIST 450//mm
	#define D2_SQRT2 636//(2*D)/SQRT2_2D
	#define FORCE_TORQUE_RATIO 15//torq=c*f
	#define CROSS 1
	#define MOTOR_POWER 310
#elif AIRFRAME_XINSONG
	#define THRCMDRATIO 1
	#define VEHICLE_MASS 1200//g
	#define ROTOR_DIST 450//mm
	#define D2_SQRT2 636//(2*D)/SQRT2_2D
	#define FORCE_TORQUE_RATIO 15//torq=c*f
	#define CROSS 1
	#define MOTOR_POWER 410
#elif AIRFRAME_F330
	#define THRCMDRATIO 1
	#define VEHICLE_MASS 1100//actually 920g
	#define ROTOR_DIST 330//mm
	#define D2_SQRT2 467//(2*D)/SQRT2_2D
	#define FORCE_TORQUE_RATIO 15
	#define CROSS 1
	#define MOTOR_POWER 300
#elif AIRFRAME_F240
	#define THRCMDRATIO 1
	#define VEHICLE_MASS 720
	#define ROTOR_DIST 240//mm
	#define D2_SQRT2 339//(2*D)/SQRT2_2D
	#define FORCE_TORQUE_RATIO 15
	#define PLUS 1
	#define MOTOR_POWER 120
#elif AIRFRAME_LICHT160
	#define THRCMDRATIO 1
	#define VEHICLE_MASS 220
	#define ROTOR_DIST 160//mm
	#define ONE_2_ROTOR_DIST 0.003125f//1/(2*d)
	#define D2_SQRT2 226//(2*D)/SQRT2_2D
	#define FORCE_TORQUE_RATIO 15
	#define ONE_4_F_T_RATIO 0.01667f
	#define PLUS 1
	#define MOTOR_POWER 310
#endif
/******Sensors Used*****/
#define IMU_MPU6000 1
#define GPS_M8N 1
#define GPS_LEA6H 0

#define COMPASS_HMC 1

#define BARO_I2C 1
#define BARO_SPI 0

/******Driver Options*****/

/******Devices Options*****/
#define XBEE_API 1
#define XBEE_TRANS 0
#define CMD_SBUS 1
#define CMD_PPM 0
#define CMD_XBEE 0
/******Algorithm Options*****/
#define ATT_COMP 0
#define ATT_EKF 0
#define ATT_MADGWICK 1


/******Flight Modes*****/
#define INDOOR 1
#define OUTDOOR 0
#define ON_FLIGHT 1
#define OFF_FLIGHT 0
#define WAIT_GPS 0

#define FREQ_1000HZ 1

#define MAX_ATT_MANUEL 0.698f//11437 40deg,0.698rad
#define MAX_YAW_RATE 0.698f//14303 50.0
#define MAX_YAW_RATE_MANEUL 0.698f
#define YAWRATE_DEADZONE 0.17f
#define BAT_WARNING 3500
#endif
