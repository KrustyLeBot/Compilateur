--------------------------------------------------------------------------------
-- Company: 
-- Engineer: le Djo
--
-- Create Date:   14:31:32 05/20/2019
-- Design Name:   
-- Module Name:   /home/wowk/Documents/TP_automates_langages/El_Compilator/El_Processor/instru_mem_tb.vhd
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
 
ENTITY instru_mem_tb IS
END instru_mem_tb;
 
ARCHITECTURE behavior OF instru_mem_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT instr_memory
    PORT(
         sel : IN  std_logic_vector(15 downto 0);
         OP : OUT  std_logic_vector(3 downto 0);
         A : OUT  std_logic_vector(7 downto 0);
         B : OUT  std_logic_vector(7 downto 0);
         C : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal sel : std_logic_vector(15 downto 0) := (others => '0');

 	--Outputs
   signal OP : std_logic_vector(7 downto 0);
   signal A : std_logic_vector(7 downto 0);
   signal B : std_logic_vector(7 downto 0);
   signal C : std_logic_vector(7 downto 0);
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: instr_memory PORT MAP (
          sel => sel,
          OP => OP,
          A => A,
          B => B,
          C => C
        );


   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		sel <= x"0000";
		
		wait for 100 ns;	
		sel <= x"0001";
		
		wait for 100 ns;	
		sel <= x"0002";
		
		wait for 100 ns;	
		sel <= x"0003";
		
		

      -- insert stimulus here 

      wait;
   end process;

END;
