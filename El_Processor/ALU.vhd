----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:11:44 04/18/2019 
-- Design Name: 
-- Module Name:    ALU - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ALU is
    Port ( A : in  STD_LOGIC_VECTOR(7 downto 0);
           B : in  STD_LOGIC_VECTOR(7 downto 0);
           OP : in  STD_LOGIC_VECTOR(3 downto 0);
           Flag : out  STD_LOGIC_VECTOR(3 downto 0);
           S : out  STD_LOGIC_VECTOR(7 downto 0));
end ALU;


architecture Behavioral of ALU is
	signal Sadd : std_logic_vector(8 downto 0);
	signal Ssou : std_logic_vector(8 downto 0);
	signal Smul : std_logic_vector(15 downto 0);
	signal Stmp : std_logic_vector(7 downto 0);
	
begin
	Sadd <= ('0'&A) + ('0'&B);
	Ssou <= ('0'&A) - ('0'&B);
	Smul <=  A * B;

	Stmp <= Sadd(7 downto 0) when op = x"01" else
			  Ssou(7 downto 0) when op = x"03" else
			  Smul(7 downto 0) when op = x"02"; 
	
	S <= Stmp;
		  
	Flag(3) <= Sadd(8) when op = x"01" else
				  Ssou(8) when op = x"03" else
				  '0';
		  
	
end Behavioral;





