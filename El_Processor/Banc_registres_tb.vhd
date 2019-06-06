--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:24:53 05/14/2019
-- Design Name:   
-- Module Name:   /home/wowk/Documents/TP_automates_langages/El_Compilator/El_Processor/Banc_registres_tb.vhd
-- Project Name:  El_Processor
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Banc_registres
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
 
ENTITY Banc_registres_tb IS
END Banc_registres_tb;
 
ARCHITECTURE behavior OF Banc_registres_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Banc_registres
    PORT(
         adrA : IN  std_logic_vector(3 downto 0);
         adrB : IN  std_logic_vector(3 downto 0);
         adrW : IN  std_logic_vector(3 downto 0);
         W : IN  std_logic;
         DATA : IN  std_logic_vector(7 downto 0);
         RST : IN  std_logic;
         CLK : IN  std_logic;
         QA : OUT  std_logic_vector(7 downto 0);
         QB : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal adrA : std_logic_vector(3 downto 0) := (others => '0');
   signal adrB : std_logic_vector(3 downto 0) := (others => '0');
   signal adrW : std_logic_vector(3 downto 0) := (others => '0');
   signal W : std_logic := '0';
   signal DATA : std_logic_vector(7 downto 0) := (others => '0');
   signal RST : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal QA : std_logic_vector(7 downto 0);
   signal QB : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Banc_registres PORT MAP (
          adrA => adrA,
          adrB => adrB,
          adrW => adrW,
          W => W,
          DATA => DATA,
          RST => RST,
          CLK => CLK,
          QA => QA,
          QB => QB
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
			adrA <= x"0";
         adrB <= x"0";
         adrW <= x"2";
         W <= '1';
         DATA <= x"05";
         RST  <= '0';
         --CLK  

		wait for 100 ns;
			adrA <= x"0";
         adrB <= x"2";
			adrW <= x"0";
         W <= '0';
         RST  <= '0';
			DATA <= x"00";
			
		wait for 100 ns;
      wait;
   end process;

END;
