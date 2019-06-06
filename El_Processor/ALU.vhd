----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Le Djo
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
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
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
			  S : out  STD_LOGIC_VECTOR(7 downto 0);
			  C, N, Z, V: out STD_LOGIC
			  );
			  
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

	Stmp <= Sadd(7 downto 0) when op = x"1" else
			  Ssou(7 downto 0) when op = x"3" else
			  Smul(7 downto 0) when op = x"2" else
			  (others => '0'); 
	
	-- Flag Z resultat nul
	Z <= '1' when Stmp=x"00" else
		  '0';
		  
	-- Flag C carry
	C <= Sadd(8) ;
		  
	-- Flag N signe
	N <= '1' when Stmp(7) = '1' else 
		  '0';
		  
	-- Flag V overflow
	V <= '1' when op = x"1" and A(7) = '0' and B(7) = '0' and Stmp(7) = '1' else -- pos + pos = neg
		  '1' when op = x"1" and A(7) = '1' and B(7) = '1' and Stmp(7) = '0' else -- neg + neg = pos
		  '1' when op = x"3" and A(7) = '0' and B(7) = '1' and Stmp(7) = '1' else -- pos - neg = neg
		  '1' when op = x"3" and A(7) = '1' and B(7) = '0' and Stmp(7) = '0' else -- neg - pos = pos
		  '1' when op = x"2" and Smul(15 downto 8) /= x"00" else
		  '0';
	
	
	S <= Stmp;
	
end Behavioral;





