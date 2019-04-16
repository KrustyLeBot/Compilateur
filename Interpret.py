register = [0,0,0,0,0]
tab_memory = []
for i in range(1000):
	tab_memory.append(0)

f = open("sortie2.banane","rb")
 
line = f.read(1)
while (len(line)>0):
	print(line)
	if (ord(line) == 1): #ADD
		print("ADD")
		R1 = ord(f.read(1))
		R2 = ord(f.read(1))
		f.read(1)  #Enleve padding
		register[R1] = register[R1] + register[R2]

	if (ord(line) == 2): #SOU
		print("SOU")
		R1 = ord(f.read(1))
		R2 = ord(f.read(1))
		f.read(1)  #Enleve padding
		register[R1] = register[R1] - register[R2]

	if (ord(line) == 3): #MUL
		print("MUL")
		R1 = ord(f.read(1))
		R2 = ord(f.read(1))
		f.read(1)  #Enleve padding
		register[R1] = register[R1] * register[R2]

	if (ord(line) == 4): #DIV
		print("DIV")
		R1 = ord(f.read(1))
		R2 = ord(f.read(1))
		f.read(1)  #Enleve padding
		if (register[2] == 0):print("division par 0")
		register[R1] = register[R1] / register[R2]

	if (ord(line) == 6): #AFC
		print("AFC")
		R1 = ord(f.read(1))
		j = ord(f.read(1))
		f.read(1)  #Enleve padding
		register[R1] = j

	if (ord(line) == 7): #LOAD
		print("LOAD")
		R1 = ord(f.read(1))
		addr2 = ord(f.read(1))
		addr1 = ord(f.read(1)) <<8
		addr = addr1 + addr2
		register[R1] = tab_memory[addr]

	if (ord(line) == 8): #STORE
		print("STORE")
		addr2 = ord(f.read(1))
		R1 = ord(f.read(1))
		addr1 = ord(f.read(1)) <<8
		addr = addr1 + addr2
		tab_memory[addr] = register[R1]

	if(ord(line) == 5): #MOV COP
		print("MOV")
		R1 = ord(f.read(1))
		R2 = ord(f.read(1))
		f.read(1)  #Enleve padding
		register[R1] = register[R2]

	line = f.read(1)

print("ok")
print("a = " + str(tab_memory[404]))
print("b = " + str(tab_memory[408]))



f.close()