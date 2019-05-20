register = [0,0,0,0,0]
tab_memory = []
for i in range(1000):
	tab_memory.append(0)

f = open("sortie.banane","rb")

liste_instr = []

line = f.read(1)
while (len(line)>0):
	print(line)
	liste_tmp = []

	if (ord(line) == 1): #ADD
		liste_tmp.append("ADD")


	if (ord(line) == 3): #SOU
		liste_tmp.append("SOU")


	if (ord(line) == 2): #MUL
		liste_tmp.append("MUL")

	if (ord(line) == 4): #DIV
		liste_tmp.append("DIV")

	if (ord(line) == 6): #AFC
		liste_tmp.append("AFC")

	if (ord(line) == 7): #LOAD
		liste_tmp.append("LOAD")

	if (ord(line) == 8): #STORE
		liste_tmp.append("STORE")

	if(ord(line) == 5): #MOV COP
		liste_tmp.append("MOV")

	if(ord(line) == 9): #EQU
		liste_tmp.append("EQU")

	if(ord(line) == 10): #INF
		liste_tmp.append("INF")

	if(ord(line) == 11): #INFE
		liste_tmp.append("INFE")

	if(ord(line) == 12): #SUP
		liste_tmp.append("SUP")

	if(ord(line) == 13): #SUPE
		liste_tmp.append("SUPE")

	if(ord(line) == 14): #JMP
		liste_tmp.append("JMP")
	if(ord(line) == 15): #JMPC
		liste_tmp.append("JMPC")
	if(ord(line) == 255): #Fin de fichier
		liste_tmp.append("END_FILE")

	A = ord(f.read(1))
	B = ord(f.read(1))
	C = ord(f.read(1))
	liste_tmp.append(A)
	liste_tmp.append(B)
	liste_tmp.append(C)

	liste_instr.append(liste_tmp)

	line = f.read(1)


f.close()
print(liste_instr)
pointeur = 0


while (pointeur < len(liste_instr)):
	if (liste_instr[pointeur][0] == "ADD"): #ADD
		R1 = liste_instr[pointeur][1]
		R2 = liste_instr[pointeur][2]
		register[R1] = register[R1] + register[R2]

	if (liste_instr[pointeur][0] == "SOU"): #SOU
		R1 = liste_instr[pointeur][1]
		R2 = liste_instr[pointeur][2]
		register[R1] = register[R1] - register[R2]

	if (liste_instr[pointeur][0] == "MUL"): #MUL
		R1 = liste_instr[pointeur][1]
		R2 = liste_instr[pointeur][2]
		register[R1] = register[R1] * register[R2]

	if (liste_instr[pointeur][0] == "DIV"): #DIV
		R1 = liste_instr[pointeur][1]
		R2 = liste_instr[pointeur][2]
		register[R1] = register[R1] / register[R2]
		

	if (liste_instr[pointeur][0] == "AFC"): #AFC
		R1 = liste_instr[pointeur][1]
		j = liste_instr[pointeur][2]
		register[R1] = j

	if (liste_instr[pointeur][0] == "LOAD"): #LOAD
		R1 = liste_instr[pointeur][1]
		addr2 = liste_instr[pointeur][2]
		addr1 = liste_instr[pointeur][3] <<8
		addr = addr1 + addr2

		register[R1] = tab_memory[addr]

	if (liste_instr[pointeur][0] == "STORE"): #STORE
		addr2 = liste_instr[pointeur][1]
		R1 = liste_instr[pointeur][2]
		addr1 = liste_instr[pointeur][3] <<8
		addr = addr1 + addr2
		tab_memory[addr] = register[R1]

	if(liste_instr[pointeur][0] == "MOV"): #MOV COP
		R1 = liste_instr[pointeur][1]
		R2 = liste_instr[pointeur][2]
		register[R1] = register[R2]

	if(liste_instr[pointeur][0] == "EQU"): #EQU
		R1 = liste_instr[pointeur][1]
		R2 = liste_instr[pointeur][2]
		print("R1: " + str(register[R1]))
		print("R2: " + str(register[R2]))
		if (register[R1] == register[R2]):
			register[R1] = 1
		else:
			register[R1] = 0

	if(liste_instr[pointeur][0] == "INF"): #INF
		R1 = liste_instr[pointeur][1]
		R2 = liste_instr[pointeur][2] 
		if (register[R1] < register[R2]):
			register[R1] = 1
		else:
			register[R1] = 0

	if(liste_instr[pointeur][0] == "INFE"): #INFE
		R1 = liste_instr[pointeur][1]
		R2 = liste_instr[pointeur][2] 
		if (register[R1] <= register[R2]):
			register[R1] = 1
		else:
			register[R1] = 0

	if(liste_instr[pointeur][0] == "SUP"): #SUP
		R1 = liste_instr[pointeur][1]
		R2 = liste_instr[pointeur][2] 
		if (register[R1] > register[R2]):
			register[R1] = 1
		else:
			register[R1] = 0

	if(liste_instr[pointeur][0] == "SUPE"): #SUPE
		R1 = liste_instr[pointeur][1]
		R2 = liste_instr[pointeur][2] 
		if (register[R1] >= register[R2]):
			register[R1] = 1
		else:
			register[R1] = 0

	if(liste_instr[pointeur][0] == "JMP"): #JMP
		addr2 = liste_instr[pointeur][1]
		addr1 = liste_instr[pointeur][3] << 8
		pointeur = addr1 + addr2 -1
	if(liste_instr[pointeur][0] == "JMPC"): #JMPC
		addr2 = liste_instr[pointeur][1]
		R1 = liste_instr[pointeur][2]
		addr1 = liste_instr[pointeur][3] << 8
		if (register[R1] == 0):
			pointeur = addr1 + addr2 -1

	if(liste_instr[pointeur][0] == "END_FILE"): #END OF FILE
		break

	print(liste_instr[pointeur][0] + " " + str(liste_instr[pointeur][1]) + " " + str(liste_instr[pointeur][2]) + " " + str(liste_instr[pointeur][3]))
	pointeur += 1
	print(register)
	print(register[R1])

print("@0: " + str(tab_memory[0]))
print("@4: " + str(tab_memory[4]))
print("@8: " + str(tab_memory[8]))
print("@12: " + str(tab_memory[12]))


