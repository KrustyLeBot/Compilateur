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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *IEEE_P_2592010699;
char *STD_STANDARD;
char *WORK_P_2188849903;
char *IEEE_P_3564397177;
char *IEEE_P_1242562249;
char *STD_TEXTIO;
char *IEEE_P_3499444699;
char *IEEE_P_3620187407;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    ieee_p_1242562249_init();
    std_textio_init();
    ieee_p_3564397177_init();
    work_p_2188849903_init();
    ieee_p_3499444699_init();
    ieee_p_3620187407_init();
    work_a_0854387488_0318166943_init();
    work_a_3650175700_3212880686_init();
    work_a_3181452207_3212880686_init();
    work_a_0955078297_3212880686_init();
    work_a_1576586384_3212880686_init();
    work_a_0472035331_3212880686_init();
    work_a_1439684516_3212880686_init();
    work_a_0832606739_3212880686_init();
    work_a_1632567566_3212880686_init();
    work_a_1415465652_3212880686_init();
    work_a_1912994691_2372691052_init();


    xsi_register_tops("work_a_1912994691_2372691052");

    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    WORK_P_2188849903 = xsi_get_engine_memory("work_p_2188849903");
    IEEE_P_3564397177 = xsi_get_engine_memory("ieee_p_3564397177");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    STD_TEXTIO = xsi_get_engine_memory("std_textio");
    IEEE_P_3499444699 = xsi_get_engine_memory("ieee_p_3499444699");
    IEEE_P_3620187407 = xsi_get_engine_memory("ieee_p_3620187407");

    return xsi_run_simulation(argc, argv);

}
