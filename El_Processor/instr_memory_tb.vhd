--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:04:45 05/20/2019
-- Design Name:   
-- Module Name:   /home/wowk/Documents/TP_automates_langages/El_Compilator/El_Processor/instr_memory_tb.vhd
-- Project Name:  El_Processor
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: instr_memory
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
 
ENTITY instr_memory_tb IS
END instr_memory_tb;
 
ARCHITECTURE behavior OF instr_memory_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT instr_memory
    PORT(
         sel : IN  std_logic_vector(15 downto 0);
         q : OUT  std_logic_vector(31 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal sel : std_logic_vector(15 downto 0) := (others => '0');

 	--Outputs
   signal q : std_logic_vector(31 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: instr_memory PORT MAP (
          sel => sel,
          q => q
        );


   -- Stimulus process
   stim_proc: process
   begin		
      wait for 10	ms;	
		sel <= x"0000";
		
		wait for 10 ms;	
		sel <= x"0001";
		
		wait for 10 ms;	
		sel <= x"0002";
		
		wait for 10 ms;	
		sel <= x"0003";

      -- insert stimulus here 

      wait;
   end process;

END;
