library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.common.all;


entity instr_memory is
	generic(
		LEN_SEL: natural := 16;
		LEN_INSTR: natural := 32
	);
	port(
		sel: in std_logic_vector(LEN_SEL-1 downto 0);
		OP : OUT  std_logic_vector(3 downto 0);
		A : OUT  std_logic_vector(7 downto 0);
		B : OUT  std_logic_vector(7 downto 0);
		C : OUT  std_logic_vector(7 downto 0)
	);
end entity;


architecture beh of instr_memory is

	--signal instr_memory: instrArray := init_rom(filename => "<path_to_your_code>");
	signal q : std_logic_vector(31 downto 0);
	signal instr_memory: instrArray := (
		0 => x"06010400",  --AFC R1 4
		1 => x"06020500",  --AFC R2 5
		2 => x"08040100",  --STORE @4 R1
		3 => x"080C0200",	 --STORE @12 R2
		4 => x"01030102",  --ADD R3 R1 R2
		5 => x"07040400",	 --LOAD R4 @4
		others => x"FFFFFFFF"
	);

begin

	q <= instr_memory(to_integer(unsigned(sel)));
	OP <= q(27 downto 24);
	A <= q(23 downto 16);
	B <= q(15 downto 8);
	C <= q(7 downto 0);
end architecture;

