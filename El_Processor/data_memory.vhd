----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:44:11 05/20/2019 
-- Design Name: 
-- Module Name:    data_memory - Behavioral 
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
use IEEE.numeric_std.ALL; 

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity data_memory is
    Port ( adr : in  STD_LOGIC_VECTOR (7 downto 0);
           INPUT : in  STD_LOGIC_VECTOR (7 downto 0);
           RW : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           OUTPUT : out  STD_LOGIC_VECTOR (7 downto 0));
end data_memory;

architecture Behavioral of data_memory is
	type typeTAB is array(0 to 255) of STD_LOGIC_VECTOR(7 downto 0);
	signal memory: typeTAB;


begin

	process
		begin		
			--On attend un tik d'horloge pour ecrire
			wait until CLK'event and CLK='1';
				if RST = '1' then
					--reset
					memory <= (others => (others => '0'));		--Remise a zeros de la memoire
				elsif RW = '1' then
					--lecture
					OUTPUT <= memory(to_integer(unsigned(adr)));		--lecture dans la memoire
				elsif RW = '0' then
					--ecriture
					memory(to_integer(unsigned(adr))) <= INPUT;		--ecriture dans la memoire
				end if;
	
	end process;
	

end Behavioral;

