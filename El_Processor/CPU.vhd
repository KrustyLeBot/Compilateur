----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:09:06 05/27/2019 
-- Design Name: 
-- Module Name:    CPU - Behavioral 
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

entity CPU is
    Port ( CPUin : in  STD_LOGIC_VECTOR(15 downto 0);
			  CLK : in STD_LOGIC;
           CPUout : out  STD_LOGIC);
end CPU;

architecture Behavioral of CPU is

	COMPONENT ALU
    PORT(
         A : IN  std_logic_vector(7 downto 0);
         B : IN  std_logic_vector(7 downto 0);
         OP : IN  std_logic_vector(3 downto 0);
         S : OUT  std_logic_vector(7 downto 0);
         C : OUT  std_logic;
         N : OUT  std_logic;
         Z : OUT  std_logic;
         V : OUT  std_logic
        );
    END COMPONENT;
	 
	 COMPONENT Banc_registres
    PORT(
         adrA : IN  std_logic_vector(3 downto 0);
         adrB : IN  std_logic_vector(3 downto 0);
         adrW : IN  std_logic_vector(3 downto 0);
         W : IN  std_logic;
         DATA : IN  std_logic_vector(7 downto 0);
         RST : IN  std_logic;
         CLK : IN  std_logic;
         QA : OUT  std_logic_vector(7 downto 0);
         QB : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
	 
	 COMPONENT Pipeline
    PORT(
         Ain : IN  std_logic_vector(7 downto 0);
         OPin : IN  std_logic_vector(3 downto 0);
         Bin : IN  std_logic_vector(7 downto 0);
         Cin : IN  std_logic_vector(7 downto 0);
			CLK : IN  std_logic;
         Aout : OUT  std_logic_vector(7 downto 0);
         OPout : OUT  std_logic_vector(3 downto 0);
         Bout : OUT  std_logic_vector(7 downto 0);
         Cout : OUT  std_logic_vector(7 downto 0)			
        );
    END COMPONENT;
	 
	 COMPONENT data_memory
    PORT(
         adr : IN  std_logic_vector(7 downto 0);
         INPUT : IN  std_logic_vector(7 downto 0);
         RW : IN  std_logic;
         RST : IN  std_logic;
         CLK : IN  std_logic;
         OUTPUT : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    
	 COMPONENT instr_memory
    PORT(
         sel : IN  std_logic_vector(15 downto 0);
         OP : OUT  std_logic_vector(3 downto 0);
         A : OUT  std_logic_vector(7 downto 0);
         B : OUT  std_logic_vector(7 downto 0);
         C : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
	 
	 COMPONENT MUX_banc_registres 
    PORT ( OP_DI : in  STD_LOGIC_VECTOR (3 downto 0);
           adrA_DI : in  STD_LOGIC_VECTOR (7 downto 0);
           QA_DI : in  STD_LOGIC_VECTOR (7 downto 0);
           B_DI : out  STD_LOGIC_VECTOR (7 downto 0)
			  );
	 END COMPONENT;
	 
	 COMPONENT MUX_ALU
    PORT ( B_EX : in  STD_LOGIC_VECTOR (7 downto 0);
           OP_EX : in  STD_LOGIC_VECTOR (3 downto 0);
           Sortie_ALU : in  STD_LOGIC_VECTOR (7 downto 0);
           B_EX_tmp : out  STD_LOGIC_VECTOR (7 downto 0));
	 END COMPONENT;
	
	 COMPONENT MUX_Sortie_Memoire 
    PORT ( output_memory : in  STD_LOGIC_VECTOR (7 downto 0);
           B_MEM : in  STD_LOGIC_VECTOR (7 downto 0);
           OP_MEM : in  STD_LOGIC_VECTOR (3 downto 0);
           B_MEM_tmp : out  STD_LOGIC_VECTOR (7 downto 0));
	 END COMPONENT;
	 
	 COMPONENT MUX_entree_memoire 
    PORT ( A_MEM : in  STD_LOGIC_VECTOR (7 downto 0);
           OP_MEM : in  STD_LOGIC_VECTOR (3 downto 0);
           B_MEM : in  STD_LOGIC_VECTOR (7 downto 0);
           adr_input_memory : out  STD_LOGIC_VECTOR (7 downto 0));
	 END COMPONENT;
	 
	 
	 signal sel :std_logic_vector(15 downto 0);
	 signal OP_LI :std_logic_vector(3 downto 0);
	 signal A_LI :std_logic_vector(7 downto 0);
	 signal B_LI :std_logic_vector(7 downto 0);
	 signal C_LI :std_logic_vector(7 downto 0);
	 
	 signal A_DI :std_logic_vector(7 downto 0);
	 signal OP_DI :std_logic_vector(3 downto 0);
	 signal B_DI :std_logic_vector(7 downto 0);
	 signal C_DI :std_logic_vector(7 downto 0);
	 
	 signal A_EX :std_logic_vector(7 downto 0);
	 signal OP_EX :std_logic_vector(3 downto 0);
	 signal B_EX :std_logic_vector(7 downto 0);
	 signal C_EX :std_logic_vector(7 downto 0);
	 
	 signal A_MEM :std_logic_vector(7 downto 0);
	 signal OP_MEM :std_logic_vector(3 downto 0);
	 signal B_MEM :std_logic_vector(7 downto 0);
	 signal C_MEM :std_logic_vector(7 downto 0);
	 
	 signal A_RE :std_logic_vector(7 downto 0);
	 signal OP_RE :std_logic_vector(3 downto 0);
	 signal B_RE :std_logic_vector(7 downto 0);
	 signal C_RE :std_logic_vector(7 downto 0);
	 
	 signal adrA :std_logic_vector(3 downto 0);
	 signal adrB :std_logic_vector(3 downto 0);
	 
	 signal RST : std_logic;
	
	 signal QA : std_logic_vector(7 downto 0);
    signal QB : std_logic_vector(7 downto 0);
	 
	 signal var : std_logic;
	 
    signal adrA_DI : STD_LOGIC_VECTOR (7 downto 0);
	 signal B_DI_tmp : STD_LOGIC_VECTOR (7 downto 0);
		
	 signal Ctrl_ALU : STD_LOGIC_VECTOR (3 downto 0);
	 signal Sortie_ALU : STD_LOGIC_VECTOR (7 downto 0);
	 
	 signal C,N,Z,V : STD_LOGIC;
	 
	 signal B_EX_tmp : STD_LOGIC_VECTOR (7 downto 0);
	 
	 signal RW : STD_LOGIC;
	 signal adr_input_memory : STD_LOGIC_VECTOR (7 downto 0);
	 signal output_memory : STD_LOGIC_VECTOR (7 downto 0);
	 
	 signal B_MEM_tmp : STD_LOGIC_VECTOR (7 downto 0);
	 

begin
	sel <= CPUin;
	
	Dec : instr_memory port map(sel,OP_LI,A_LI,B_LI,C_LI);

	LI_DI : Pipeline port map (A_LI,OP_LI,B_LI,C_LI,CLK,A_DI,OP_DI,B_DI,C_DI);
	
	MUX1 : MUX_banc_registres port map (OP_DI,B_DI,QA,B_DI_tmp);
	
	DI_EX : Pipeline port map (A_DI,OP_DI,B_DI_tmp,QB,CLK,A_EX,OP_EX,B_EX,C_EX);
	
	MUX2 : MUX_ALU port map (B_EX,OP_EX,Sortie_ALU,B_EX_tmp);
	
	EX_MEM : Pipeline port map (A_EX,OP_EX,B_EX_tmp,C_EX,CLK,A_MEM,OP_MEM,B_MEM,C_MEM);
	
	MUX3 : MUX_entree_memoire port map (A_MEM,OP_MEM,B_MEM,adr_input_memory);
	
	MUX4 : MUX_Sortie_Memoire port map (output_memory,B_MEM,OP_MEM,B_MEM_tmp);
	  
	MEM_RE : Pipeline port map (A_MEM,OP_MEM,B_MEM_tmp,C_MEM,CLK,A_RE,OP_RE,B_RE,C_RE);
	
	--Var pour savoir si on doit ecrire dans les registres
	var <= '1' when OP_RE = x"1" or OP_RE = x"2" or OP_RE = x"3" or OP_RE = x"4" or OP_RE = x"5" or OP_RE = x"6" or OP_RE = x"7" or OP_RE = x"9" or OP_RE = x"a" or OP_RE = x"b" or OP_RE = x"c" or OP_RE = x"d" else
			 '0' ;
		
	registres : Banc_registres port map (B_DI(3 downto 0),C_DI(3 downto 0),A_RE(3 downto 0),var,B_RE,RST,CLK,QA,QB);
	
	Ctrl_ALU <= OP_EX when OP_EX = x"1" or OP_EX = x"2" or OP_EX = x"3" or OP_EX = x"4" else --Si c est une operation ADD SOU MUL ou DIV
					x"1";																								  --Sinon on met une valeur par defaut
		
	UAL : ALU port map (B_EX,C_EX,Ctrl_ALU,Sortie_ALU,C,N,Z,V);
	
	RW <= '0' when OP_MEM  = x"8" else
		  '1';
	RST <= '0';
		  
	memoire : data_memory port map(adr_input_memory,B_MEM,RW,RST,CLK,output_memory);
	
	
end Behavioral;

