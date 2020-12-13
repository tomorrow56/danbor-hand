// File Name: ir_toshiba.h
#ifndef IR_TOSHIBA_H
#define IR_TOSHIBA_H

// Toshiba TV IR Remo-con code list
#define b_blue    0xA23D946B
#define b_red     0xA23D54AB
#define b_green   0xA23DD42B
#define b_yellow  0xA23D34CB
#define tenkey_01 0xA23D7986
#define tenkey_02 0xA23DE817
#define tenkey_03 0xA23DB946
#define tenkey_04 0xA23D19E6
#define tenkey_05 0xA23DC837
#define tenkey_06 0xA23D59A6
#define tenkey_07 0xA23D31CE
#define tenkey_08 0xA23D6897
#define tenkey_09 0xA23D11EE
#define tenkey_10 0xA23D21DE
#define tenkey_11 0xA23D9B64
#define tenkey_12 0xA23D01FE
#define b_kettei  0xA23D22DD
#define b_qmenu   0xA23DA25D
#define b_return  0xA23DD22D
#define b_up      0xA23D03FC
#define b_down    0xA23D13EC
#define b_right   0xA23D23DC
#define b_left    0xA23D33CC
#define b_up_j    0xA23D7887
#define b_down_j  0xA23DF807
#define b_right_j 0xA23DDA25
#define b_left_j  0xA23DAA55

// Ir receiver pin No.
#define RECV_PIN  A0

// Create object
IRrecv irrecv(RECV_PIN);

decode_results results;

#endif




