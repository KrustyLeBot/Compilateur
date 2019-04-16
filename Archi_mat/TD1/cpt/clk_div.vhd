----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:01:46 04/11/2019 
-- Design Name: 
-- Module Name:    clk - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity clk is
	Port ( clk_lent : out  STD_LOGIC;
			 clk_rapide : in STD_LOGIC);
end clk;

architecture Behavioral of clk is

signal counter:INTEGER;
signal tmp: STD_LOGIC;

begin
	process
	begin
		wait until clk_rapide' event and clk_rapide='1';
		if counter=10000000 then
			counter<=0;
			tmp<=not tmp;
		else
			counter <=counter+1;
		end if;
	end process;
	clk_lent<=tmp;
	
end Behavioral;

