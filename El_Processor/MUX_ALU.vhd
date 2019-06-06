----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:02:31 05/29/2019 
-- Design Name: 
-- Module Name:    MUX_ALU - Behavioral 
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

entity MUX_ALU is
    Port ( B_EX : in  STD_LOGIC_VECTOR (7 downto 0);
           OP_EX : in  STD_LOGIC_VECTOR (3 downto 0);
           Sortie_ALU : in  STD_LOGIC_VECTOR (7 downto 0);
           B_EX_tmp : out  STD_LOGIC_VECTOR (7 downto 0));
end MUX_ALU;

architecture Behavioral of MUX_ALU is

begin
	B_EX_tmp <= Sortie_ALU  when OP_EX = x"1" or OP_EX = x"2" or OP_EX = x"3" or OP_EX = x"4" else
					B_EX;

end Behavioral;

