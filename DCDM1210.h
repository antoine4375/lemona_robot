/*
  DCDM1210.cpp - Library for interfacing with NT-S-DCDM1210 (2 motor driver controller)
  Created by Gim Tae Hwan (Antoine)
  Released into the public domain.
*/

#ifndef DCDM1210_h
#define DCDM1210_h

#include "CM900.h"

// Serial Baud rate define
#define BAUD_RATE_4800      1
#define BAUD_RATE_9600      2
#define BAUD_RATE_19200     3
#define BAUD_RATE_38400     4
#define BAUD_RATE_57600     5
#define BAUD_RATE_115200    6

// Serial
#define SERIAL_1             1
#define SERIAL_2             2
#define SERIAL_3             3
#define SERIAL_4             4

#define FORWARD             1
#define BACKWARD            0

#define RIGHT               1
#define LEFT                2


class DCDM1210
{
    public:
        void Serial_connect(byte Serial_choice,int baud);
        void Send_data(byte *data);
        void Reset_data(void);
        int Moter_control(int which, int direction ,int duty);
        int Moter_control(int which_1, int direction_1 ,int duty_1,int which_2, int direction_2 ,int duty_2);
        int Deadband(int duty);
        int Setting_RS232C_baud(int baud);
        int Low_voltage_warning(int voltage);
        void Joystick_calibration(void);
        void Command_reset(void);
        void Moter_delay(int usec);
        int Answer_PWM(int *R_direction,int *R_PWM,int *L_direction,int *L_PWM);
        int Answer_voltage(int *voltage);
        int DCDM1210::Answer_current(double *R_current,double *L_current);

    private:
        byte _Serial_choice;
        byte _data[20];
        int _baud;

};
#endif

