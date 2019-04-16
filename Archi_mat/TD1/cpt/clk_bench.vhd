--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   12:11:13 04/11/2019
-- Design Name:   
-- Module Name:   /home/wowk/Documents/TP_automates_langages/El_Compilator/Archi_mat/TD1/cpt/clk_bench.vhd
-- Project Name:  cpt
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: clk
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY clk_bench IS
END clk_bench;
 
ARCHITECTURE behavior OF clk_bench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT clk
    PORT(
         clk_lent : OUT  std_logic;
         clk_rapide : IN  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk_rapide : std_logic := '0';

 	--Outputs
   signal clk_lent : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant clk_rapide_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: clk PORT MAP (
          clk_lent => clk_lent,
          clk_rapide => clk_rapide
        );

   -- Clock process definitions
   clk_rapide_process :process
   begin
		clk_rapide <= '0';
		wait for clk_rapide_period/2;
		clk_rapide <= '1';
		wait for clk_rapide_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_rapide_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
