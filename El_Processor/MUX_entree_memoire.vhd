----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:54:10 05/29/2019 
-- Design Name: 
-- Module Name:    MUX_entree_memoire - Behavioral 
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

entity MUX_entree_memoire is
    Port ( A_MEM : in  STD_LOGIC_VECTOR (7 downto 0);
           OP_MEM : in  STD_LOGIC_VECTOR (3 downto 0);
           B_MEM : in  STD_LOGIC_VECTOR (7 downto 0);
           adr_input_memory : out  STD_LOGIC_VECTOR (7 downto 0));
end MUX_entree_memoire;

architecture Behavioral of MUX_entree_memoire is

begin
	adr_input_memory <= A_MEM when OP_MEM = x"8" else
							  B_MEM;

end Behavioral;

