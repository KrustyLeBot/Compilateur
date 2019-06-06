----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Le Djo
-- 
-- Create Date:    14:11:22 05/10/2019 
-- Design Name: 
-- Module Name:    Banc_registres - Behavioral 
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

entity Banc_registres is
    Port ( adrA : in  STD_LOGIC_VECTOR (3 downto 0);
           adrB : in  STD_LOGIC_VECTOR (3 downto 0);
           adrW : in  STD_LOGIC_VECTOR (3 downto 0);
           W : in  STD_LOGIC;
           DATA : in  STD_LOGIC_VECTOR (7 downto 0);
           RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           QA : out  STD_LOGIC_VECTOR (7 downto 0);
           QB : out  STD_LOGIC_VECTOR (7 downto 0));
end Banc_registres;

architecture Behavioral of Banc_registres is
	type typeTAB is array(0 to 15) of STD_LOGIC_VECTOR(7 downto 0);
	signal registers: typeTAB;
	
begin
	--Syntaxe acces au tableau de registres
	--A <= registers(to_integer(unsigned(adrA)));
	--registers(to_integer(unsigned(adrA))) <= 
	
	--Reset
	
	
	process
		begin		
			--On attend un tik d'horloge pour ecrire
			wait until CLK'event and CLK='1';
				if RST = '1' then
					registers <= (others => (others => '0'));		--Remise a zeros des registres
				elsif W = '1' then
					registers(to_integer(unsigned(adrW))) <= DATA;		--ecriture dans un registre
				end if;
	
	end process;
	QA <= DATA when adrA = adrW and W = '1' else		--Si addr sortie A = addr entree W
			registers(to_integer(unsigned(adrA)));		--Sinon lecture du registre correspondant
			
	QB <= DATA when adrB = adrW and W = '1' else		--Si addr sortie B = addr entree W
			registers(to_integer(unsigned(adrB)));		--Sinon lecture du registre correspondant
	

end Behavioral;

