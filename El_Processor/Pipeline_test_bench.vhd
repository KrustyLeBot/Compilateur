--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   12:50:36 05/20/2019
-- Design Name:   
-- Module Name:   /home/wowk/Documents/TP_automates_langages/El_Compilator/El_Processor/Pipeline_test_bench.vhd
-- Project Name:  El_Processor
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Pipeline
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
 
ENTITY Pipeline_test_bench IS
END Pipeline_test_bench;
 
ARCHITECTURE behavior OF Pipeline_test_bench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Pipeline
    PORT(
         Ain : IN  std_logic_vector(7 downto 0);
         OPin : IN  std_logic_vector(3 downto 0);
         Bin : IN  std_logic_vector(7 downto 0);
         Cin : IN  std_logic_vector(7 downto 0);
			CLK : IN  std_logic;
         Aout : OUT  std_logic_vector(7 downto 0);
         OPout : OUT  std_logic_vector(3 downto 0);
         Bout : OUT  std_logic_vector(7 downto 0);
         Cout : OUT  std_logic_vector(7 downto 0)			
        );
    END COMPONENT;
    

   --Inputs
   signal Ain : std_logic_vector(7 downto 0) := (others => '0');
   signal OPin : std_logic_vector(3 downto 0) := (others => '0');
   signal Bin : std_logic_vector(7 downto 0) := (others => '0');
   signal Cin : std_logic_vector(7 downto 0) := (others => '0');
	signal CLK : std_logic := '0';
 	--Outputs
   signal Aout : std_logic_vector(7 downto 0);
   signal OPout : std_logic_vector(3 downto 0);
   signal Bout : std_logic_vector(7 downto 0);
   signal Cout : std_logic_vector(7 downto 0);
 
 
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Pipeline PORT MAP (
          Ain => Ain,
          OPin => OPin,
          Bin => Bin,
          Cin => Cin,
			 CLK => CLK,
          Aout => Aout,
          OPout => OPout,
          Bout => Bout,
          Cout => Cout
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
		Ain <= x"02";
		Bin <= x"05";
		OPin <=x"2";
		Cin <= x"15";
      wait;
   end process;

END;
