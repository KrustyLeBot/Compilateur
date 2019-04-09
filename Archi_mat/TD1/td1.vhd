----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:02:35 03/26/2019 
-- Design Name: 
-- Module Name:    td1 - Behavioral 
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

entity td1 is
    Port ( CK : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           SENS : in  STD_LOGIC;
           LOAD : in  STD_LOGIC;
           EN : in  STD_LOGIC;
           Din : in  STD_LOGIC_VECTOR (7 downto 0);
           Dout : out  STD_LOGIC_VECTOR (7 downto 0));
end td1;

architecture Behavioral of td1 is

	signal cnt:STD_LOGIC_VECTOR(7 downto 0);
	
begin
	process
	begin
		wait until rising_edge(CK);
			if RST='0' then
				cnt <= "00000000";

			elsif LOAD='1' then
				cnt <= Din;
			
			elsif LOAD='0' AND EN='0' then --enable actif=0
				if SENS='0' then
					cnt <= cnt - 1;
				elsif SENS='1' then
					cnt <= cnt + 1;
				end if;
			end if;

	end process;			
	Dout<=cnt;
	end Behavioral;

