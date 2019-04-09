
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name TD1 -dir "/home/wowk/Documents/TP_automates_langages/El_Compilator/Archi_mat/TD1/planAhead_run_2" -part xc6slx16csg324-3
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "/home/wowk/Documents/TP_automates_langages/El_Compilator/Archi_mat/TD1/td1.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {/home/wowk/Documents/TP_automates_langages/El_Compilator/Archi_mat/TD1} }
set_property target_constrs_file "td1.ucf" [current_fileset -constrset]
add_files [list {td1.ucf}] -fileset [get_property constrset [current_run]]
open_netlist_design
