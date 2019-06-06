--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:46:51 05/27/2019
-- Design Name:   
-- Module Name:   /home/wowk/Documents/TP_automates_langages/El_Compilator/El_Processor/CPU_tb.vhd
-- Project Name:  El_Processor
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: CPU
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
 
ENTITY CPU_tb IS
END CPU_tb;
 
ARCHITECTURE behavior OF CPU_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT CPU
    PORT(
         CPUin : IN  std_logic_vector(15 downto 0);
			CLK : IN std_logic;
         CPUout : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CPUin : std_logic_vector(15 downto 0);
	signal CLK : std_logic := '0';
 
 	--Outputs
   signal CPUout : std_logic;
 
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: CPU PORT MAP (
          CPUin => CPUin,
			 CLK => CLK,
          CPUout => CPUout
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		CPUin <= x"0000";
		
		wait for 100 ns;
		CPUin <= x"0001";
		
		wait for 100 ns;
		CPUin <= x"0002";
		
		wait for 100 ns;
		CPUin <= x"0003";
		
		wait for 100 ns;
		CPUin <= x"0004";
		
		wait for 100 ns;
		CPUin <= x"0005";

      -- insert stimulus here 

      wait;
   end process;

END;
