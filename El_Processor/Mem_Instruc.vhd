----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:23:00 05/20/2019 
-- Design Name: 
-- Module Name:    Mem_Instruc - Behavioral 
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

entity Mem_Instruc is
    Port ( adr : in  STD_LOGIC_VECTOR (0 downto 0);
           CLK : in  STD_LOGIC;
           COUT : out  STD_LOGIC_VECTOR (0 downto 0));
end Mem_Instruc;

architecture Behavioral of Mem_Instruc is

begin


end Behavioral;

