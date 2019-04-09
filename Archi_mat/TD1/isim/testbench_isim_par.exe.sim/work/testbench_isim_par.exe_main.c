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
char *STD_TEXTIO;
char *STD_STANDARD;
char *SIMPRIM_P_4208868169;
char *IEEE_P_1367372525;
char *SIMPRIM_P_0947159679;
char *IEEE_P_2717149903;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    std_textio_init();
    ieee_p_2717149903_init();
    simprim_p_0947159679_init();
    ieee_p_1367372525_init();
    simprim_p_4208868169_init();
    simprim_a_2118406211_3300903326_3346948913_init();
    simprim_a_2880286190_2413300256_1520479962_init();
    simprim_a_2880286190_2413300256_1491472515_init();
    simprim_a_2480746270_2000130859_1520479962_init();
    simprim_a_3828473913_2000130859_1520479962_init();
    simprim_a_0173862651_2000130859_1520479962_init();
    simprim_a_0020794411_2000130859_1520479962_init();
    simprim_a_0099139518_2000130859_1491472515_init();
    simprim_a_3838428600_2000130859_1491472515_init();
    simprim_a_1710237154_2000130859_1491472515_init();
    simprim_a_0173862651_2000130859_1491472515_init();
    simprim_a_1367255764_2000130859_1740670826_init();
    simprim_a_3225382535_2000130859_1740670826_init();
    simprim_a_3647767699_1970351474_1520479962_init();
    simprim_a_1411459015_1970351474_1520479962_init();
    simprim_a_0787437086_1970351474_1520479962_init();
    simprim_a_3647767699_1970351474_1491472515_init();
    simprim_a_1411459015_1970351474_1491472515_init();
    simprim_a_2866304254_1478103974_1520479962_init();
    simprim_a_2866304254_1478103974_1491472515_init();
    simprim_a_3156740924_4150518722_2649829668_init();
    simprim_a_3156740924_4150518722_2679607165_init();
    simprim_a_3156740924_4150518722_2498480192_init();
    simprim_a_3156740924_4150518722_3277448089_init();
    simprim_a_3156740924_4150518722_2599983608_init();
    simprim_a_3156740924_4150518722_2562598817_init();
    simprim_a_3156740924_4150518722_0743943973_init();
    simprim_a_3156740924_4150518722_2620611347_init();
    simprim_a_3221717806_2431929443_4252805745_init();
    simprim_a_3221717806_2431929443_2575060374_init();
    simprim_a_3221717806_2431929443_0880553409_init();
    simprim_a_3221717806_2431929443_1059089148_init();
    simprim_a_3221717806_2431929443_2604331983_init();
    simprim_a_3221717806_2431929443_1054998731_init();
    simprim_a_3221717806_2431929443_0596022442_init();
    simprim_a_3221717806_2431929443_0574946973_init();
    simprim_a_3221717806_2431929443_0537018564_init();
    simprim_a_3221717806_2431929443_0566242035_init();
    simprim_a_3221717806_2431929443_0613366902_init();
    simprim_a_3221717806_2431929443_0650740271_init();
    simprim_a_3221717806_2431929443_0764790034_init();
    simprim_a_3221717806_2431929443_0433961640_init();
    simprim_a_2906262002_2082082460_init();
    simprim_a_4130118134_1564065396_2390294557_init();
    simprim_a_4130118134_1564065396_3004770733_init();
    simprim_a_3395610110_2220797900_0433961640_init();
    simprim_a_1509725169_3980060181_0433961640_init();
    simprim_a_4181367278_3380326129_0433961640_init();
    simprim_a_2155285624_1178295121_0433961640_init();
    work_a_2124998757_0632001823_init();
    work_a_1949178628_2372691052_init();


    xsi_register_tops("work_a_1949178628_2372691052");

    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_TEXTIO = xsi_get_engine_memory("std_textio");
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    SIMPRIM_P_4208868169 = xsi_get_engine_memory("simprim_p_4208868169");
    IEEE_P_1367372525 = xsi_get_engine_memory("ieee_p_1367372525");
    SIMPRIM_P_0947159679 = xsi_get_engine_memory("simprim_p_0947159679");
    IEEE_P_2717149903 = xsi_get_engine_memory("ieee_p_2717149903");

    return xsi_run_simulation(argc, argv);

}
