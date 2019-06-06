----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:41:09 05/29/2019 
-- Design Name: 
-- Module Name:    MUX_Sortie_Memoire - Behavioral 
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

entity MUX_Sortie_Memoire is
    Port ( output_memory : in  STD_LOGIC_VECTOR (7 downto 0);
           B_MEM : in  STD_LOGIC_VECTOR (7 downto 0);
           OP_MEM : in  STD_LOGIC_VECTOR (3 downto 0);
           B_MEM_tmp : out  STD_LOGIC_VECTOR (7 downto 0));
end MUX_Sortie_Memoire;

architecture Behavioral of MUX_Sortie_Memoire is

begin
	B_MEM_tmp <= output_memory when OP_MEM = x"7" else
					 B_MEM;

end Behavioral;

