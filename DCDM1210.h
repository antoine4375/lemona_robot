/*
  DCDM1210.h - Library for interfacing with DCDM1210 (2 motor driver controller) from www.ntrex.co.kr
  Created by TaeYeong Kim, 4, Aug, 2013.
*/

#ifndef DCDM1210_h
#define DCDM1210_h

#include "Arduino.h"

    #define KEY1 < // key used in critical commands
    #define KEY2 > // key used in critical commands


    #define QUERY 0
    #define COMMAND 1

    #define SET_VEL_R               R       //0~999(duty)
    #define SET_VEL_L               L       //0~999(duty)
        #define DIRECTION_CW        1
        #define DIRECTION_CCW       0
    #define SET_LOW_VOLATAGE_ALERT  W       //15~36(volt)
    #define SET_DEAD_BAND           D       //0~500(duty)
    #define SET_BAUD_RATE           U       /*
                                                0 4800 bps
                                                1 9600 bps
                                                2 19200 bps
                                                3 38400 bps
                                                4 57600bps
                                                5 115200bps
                                            */
    #define SET_ACC_DELAY           E       //0~100(100usec)
    #define CALIB_JOYSTICK          C
    #define SET_RESET               r

    #define GET_VOLTAGE             V
    #define GET_CURRENT             C
    #define GET_PWN                 M



class DCDM1210
{
  public:

        //setup routines
        void serial_connect(byte dcdmAddress, byte port, byte baudrate);
        void set_speed(byte set_l, byte direction_l, int duty_l, byte set_r, byte direction_r, int duty_r);

        void set_baud_rate(byte baudrate);
        void set_reset();
    ////GRAVEYARD
        //void set_dead_band(int duty);     
        //void calibration_joystick();


        void get_valtage();
        void get_current();
        void get_pwm();

  private:
        byte _dcdmAddress;
        void serialRequestData(byte adreessValue, byte command);
        void serialSendData(byte addressValue, byte command, byte buffer[], byte numBytes);
};
#endif


