
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name cpt -dir "/home/wowk/Documents/TP_automates_langages/El_Compilator/Archi_mat/TD1/cpt/planAhead_run_1" -part xc6slx16csg324-3
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "td1.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {../td1.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set_property top td1 $srcset
add_files [list {td1.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc6slx16csg324-3
