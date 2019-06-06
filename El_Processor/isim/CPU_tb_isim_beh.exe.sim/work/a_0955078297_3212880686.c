/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x8ddf5b5d */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/wowk/Documents/TP_automates_langages/El_Compilator/El_Processor/MUX_ALU.vhd";



static void work_a_0955078297_3212880686_p_0(char *t0)
{
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned char t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned char t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned char t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;

LAB0:    xsi_set_current_line(43, ng0);
    t4 = (t0 + 1192U);
    t5 = *((char **)t4);
    t4 = (t0 + 4980);
    t7 = 1;
    if (4U == 4U)
        goto LAB14;

LAB15:    t7 = 0;

LAB16:    if (t7 == 1)
        goto LAB11;

LAB12:    t11 = (t0 + 1192U);
    t12 = *((char **)t11);
    t11 = (t0 + 4984);
    t14 = 1;
    if (4U == 4U)
        goto LAB20;

LAB21:    t14 = 0;

LAB22:    t3 = t14;

LAB13:    if (t3 == 1)
        goto LAB8;

LAB9:    t18 = (t0 + 1192U);
    t19 = *((char **)t18);
    t18 = (t0 + 4988);
    t21 = 1;
    if (4U == 4U)
        goto LAB26;

LAB27:    t21 = 0;

LAB28:    t2 = t21;

LAB10:    if (t2 == 1)
        goto LAB5;

LAB6:    t25 = (t0 + 1192U);
    t26 = *((char **)t25);
    t25 = (t0 + 4992);
    t28 = 1;
    if (4U == 4U)
        goto LAB32;

LAB33:    t28 = 0;

LAB34:    t1 = t28;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB38:    t38 = (t0 + 1032U);
    t39 = *((char **)t38);
    t38 = (t0 + 3064);
    t40 = (t38 + 56U);
    t41 = *((char **)t40);
    t42 = (t41 + 56U);
    t43 = *((char **)t42);
    memcpy(t43, t39, 8U);
    xsi_driver_first_trans_fast_port(t38);

LAB2:    t44 = (t0 + 2984);
    *((int *)t44) = 1;

LAB1:    return;
LAB3:    t32 = (t0 + 1352U);
    t33 = *((char **)t32);
    t32 = (t0 + 3064);
    t34 = (t32 + 56U);
    t35 = *((char **)t34);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    memcpy(t37, t33, 8U);
    xsi_driver_first_trans_fast_port(t32);
    goto LAB2;

LAB5:    t1 = (unsigned char)1;
    goto LAB7;

LAB8:    t2 = (unsigned char)1;
    goto LAB10;

LAB11:    t3 = (unsigned char)1;
    goto LAB13;

LAB14:    t8 = 0;

LAB17:    if (t8 < 4U)
        goto LAB18;
    else
        goto LAB16;

LAB18:    t9 = (t5 + t8);
    t10 = (t4 + t8);
    if (*((unsigned char *)t9) != *((unsigned char *)t10))
        goto LAB15;

LAB19:    t8 = (t8 + 1);
    goto LAB17;

LAB20:    t15 = 0;

LAB23:    if (t15 < 4U)
        goto LAB24;
    else
        goto LAB22;

LAB24:    t16 = (t12 + t15);
    t17 = (t11 + t15);
    if (*((unsigned char *)t16) != *((unsigned char *)t17))
        goto LAB21;

LAB25:    t15 = (t15 + 1);
    goto LAB23;

LAB26:    t22 = 0;

LAB29:    if (t22 < 4U)
        goto LAB30;
    else
        goto LAB28;

LAB30:    t23 = (t19 + t22);
    t24 = (t18 + t22);
    if (*((unsigned char *)t23) != *((unsigned char *)t24))
        goto LAB27;

LAB31:    t22 = (t22 + 1);
    goto LAB29;

LAB32:    t29 = 0;

LAB35:    if (t29 < 4U)
        goto LAB36;
    else
        goto LAB34;

LAB36:    t30 = (t26 + t29);
    t31 = (t25 + t29);
    if (*((unsigned char *)t30) != *((unsigned char *)t31))
        goto LAB33;

LAB37:    t29 = (t29 + 1);
    goto LAB35;

LAB39:    goto LAB2;

}


extern void work_a_0955078297_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0955078297_3212880686_p_0};
	xsi_register_didat("work_a_0955078297_3212880686", "isim/CPU_tb_isim_beh.exe.sim/work/a_0955078297_3212880686.didat");
	xsi_register_executes(pe);
}
