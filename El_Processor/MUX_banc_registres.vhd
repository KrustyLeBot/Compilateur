----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:20:53 05/29/2019 
-- Design Name: 
-- Module Name:    MUX_banc_registres - Behavioral 
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

entity MUX_banc_registres is
    Port ( OP_DI : in  STD_LOGIC_VECTOR (3 downto 0);
           adrA_DI : in  STD_LOGIC_VECTOR (7 downto 0);
           QA_DI : in  STD_LOGIC_VECTOR (7 downto 0);
           B_DI : out  STD_LOGIC_VECTOR (7 downto 0));
end MUX_banc_registres;

architecture Behavioral of MUX_banc_registres is
	
begin
	B_DI <= adrA_DI when OP_DI = x"6" or OP_DI = x"7" else
			  QA_DI;

end Behavioral;

