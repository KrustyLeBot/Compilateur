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
extern char *STD_TEXTIO;
static const char *ng1 = "file_ptr";
extern char *IEEE_P_2592010699;
extern char *STD_STANDARD;
extern char *IEEE_P_3564397177;

void ieee_p_3564397177_sub_2863978933202788330_91900896(char *, char *, char *, char *, char *);


char *work_p_2188849903_sub_3884759664929755126_1032961590(char *t1, char *t2, char *t3)
{
    char t4[448];
    char t5[24];
    char t15[32];
    char t24[2097152];
    char t36[16];
    char t42[32];
    char t49[8];
    char *t0;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    char *t12;
    unsigned char t13;
    unsigned int t14;
    char *t16;
    char *t17;
    int t18;
    unsigned int t19;
    char *t20;
    int t21;
    char *t22;
    char *t23;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t37;
    char *t38;
    int t39;
    char *t40;
    char *t41;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t50;
    char *t51;
    char *t52;
    unsigned char t53;
    char *t54;
    char *t55;
    char *t56;
    unsigned int t57;

LAB0:    t6 = ((STD_TEXTIO) + 3400);
    t7 = (t4 + 4U);
    t8 = xsi_create_file_variable_in_buffer(0, ng1, t6, 0, 0, 1);
    *((char **)t7) = t8;
    t9 = xsi_get_transient_memory(2097152U);
    memset(t9, 0, 2097152U);
    t10 = t9;
    t11 = (32U * 1U);
    t12 = t10;
    memset(t12, (unsigned char)3, t11);
    t13 = (t11 != 0);
    if (t13 == 1)
        goto LAB2;

LAB3:    t16 = (t15 + 0U);
    t17 = (t16 + 0U);
    *((int *)t17) = 0;
    t17 = (t16 + 4U);
    *((int *)t17) = 65535;
    t17 = (t16 + 8U);
    *((int *)t17) = 1;
    t18 = (65535 - 0);
    t19 = (t18 * 1);
    t19 = (t19 + 1);
    t17 = (t16 + 12U);
    *((unsigned int *)t17) = t19;
    t17 = (t15 + 16U);
    t20 = (t17 + 0U);
    *((int *)t20) = 31;
    t20 = (t17 + 4U);
    *((int *)t20) = 0;
    t20 = (t17 + 8U);
    *((int *)t20) = -1;
    t21 = (0 - 31);
    t19 = (t21 * -1);
    t19 = (t19 + 1);
    t20 = (t17 + 12U);
    *((unsigned int *)t20) = t19;
    t20 = (t4 + 12U);
    t22 = (t1 + 2808);
    t23 = (t20 + 88U);
    *((char **)t23) = t22;
    t25 = (t20 + 56U);
    *((char **)t25) = t24;
    memcpy(t24, t9, 2097152U);
    t26 = (t20 + 64U);
    t27 = (t22 + 72U);
    t28 = *((char **)t27);
    *((char **)t26) = t28;
    t29 = (t20 + 80U);
    *((unsigned int *)t29) = 2097152U;
    t30 = (t4 + 132U);
    t31 = ((STD_TEXTIO) + 3248);
    t32 = (t30 + 56U);
    *((char **)t32) = t31;
    t33 = (t30 + 40U);
    *((char **)t33) = 0;
    t34 = (t30 + 64U);
    *((int *)t34) = 1;
    t35 = (t30 + 48U);
    *((char **)t35) = 0;
    t37 = (t36 + 0U);
    t38 = (t37 + 0U);
    *((int *)t38) = 31;
    t38 = (t37 + 4U);
    *((int *)t38) = 0;
    t38 = (t37 + 8U);
    *((int *)t38) = -1;
    t39 = (0 - 31);
    t19 = (t39 * -1);
    t19 = (t19 + 1);
    t38 = (t37 + 12U);
    *((unsigned int *)t38) = t19;
    t38 = (t4 + 204U);
    t40 = ((IEEE_P_2592010699) + 4000);
    t41 = (t38 + 88U);
    *((char **)t41) = t40;
    t43 = (t38 + 56U);
    *((char **)t43) = t42;
    xsi_type_set_default_value(t40, t42, t36);
    t44 = (t38 + 64U);
    *((char **)t44) = t36;
    t45 = (t38 + 80U);
    *((unsigned int *)t45) = 32U;
    t46 = (t4 + 324U);
    t47 = ((STD_STANDARD) + 384);
    t48 = (t46 + 88U);
    *((char **)t48) = t47;
    t50 = (t46 + 56U);
    *((char **)t50) = t49;
    *((int *)t49) = 0;
    t51 = (t46 + 80U);
    *((unsigned int *)t51) = 4U;
    t52 = (t5 + 4U);
    t53 = (t2 != 0);
    if (t53 == 1)
        goto LAB5;

LAB4:    t54 = (t5 + 12U);
    *((char **)t54) = t3;
    t55 = (t4 + 4U);
    t56 = *((char **)t55);
    std_textio_file_open1(t56, t2, t3, (unsigned char)0);

LAB6:    t6 = (t4 + 4U);
    t7 = *((char **)t6);
    t13 = std_textio_endfile(t7);
    t53 = (!(t13));
    if (t53 != 0)
        goto LAB7;

LAB9:    t6 = (t4 + 4U);
    t7 = *((char **)t6);
    std_textio_file_close(t7);
    t6 = (t20 + 56U);
    t7 = *((char **)t6);
    t13 = (2097152U != 2097152U);
    if (t13 == 1)
        goto LAB10;

LAB11:    t0 = xsi_get_transient_memory(2097152U);
    memcpy(t0, t7, 2097152U);

LAB1:    xsi_access_variable_delete(t30);
    t6 = (t4 + 4U);
    t7 = *((char **)t6);
    xsi_delete_file_variable(t7);
    return t0;
LAB2:    t14 = (2097152U / t11);
    xsi_mem_set_data(t10, t10, t11, t14);
    goto LAB3;

LAB5:    *((char **)t52) = t2;
    goto LAB4;

LAB7:    t8 = (t4 + 4U);
    t9 = *((char **)t8);
    std_textio_readline(STD_TEXTIO, (char *)0, t9, t30);
    t6 = (t38 + 56U);
    t7 = *((char **)t6);
    ieee_p_3564397177_sub_2863978933202788330_91900896(IEEE_P_3564397177, (char *)0, t30, t7, t36);
    t6 = (t38 + 56U);
    t7 = *((char **)t6);
    t6 = (t20 + 56U);
    t8 = *((char **)t6);
    t6 = (t46 + 56U);
    t9 = *((char **)t6);
    t18 = *((int *)t9);
    t21 = (t18 - 0);
    t11 = (t21 * 1);
    xsi_vhdl_check_range_of_index(0, 65535, 1, t18);
    t14 = (32U * t11);
    t19 = (0 + t14);
    t6 = (t8 + t19);
    t10 = (t36 + 12U);
    t57 = *((unsigned int *)t10);
    t57 = (t57 * 1U);
    memcpy(t6, t7, t57);
    t6 = (t46 + 56U);
    t7 = *((char **)t6);
    t18 = *((int *)t7);
    t21 = (t18 + 1);
    t6 = (t46 + 56U);
    t8 = *((char **)t6);
    t6 = (t8 + 0);
    *((int *)t6) = t21;
    goto LAB6;

LAB8:;
LAB10:    xsi_size_not_matching(2097152U, 2097152U, 0);
    goto LAB11;

LAB12:;
}


extern void work_p_2188849903_init()
{
	static char *se[] = {(void *)work_p_2188849903_sub_3884759664929755126_1032961590};
	xsi_register_didat("work_p_2188849903", "isim/CPU_tb_isim_beh.exe.sim/work/p_2188849903.didat");
	xsi_register_subprogram_executes(se);
}
