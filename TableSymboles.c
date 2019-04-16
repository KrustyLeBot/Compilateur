#include "TableSymboles.h"
#include <string.h>





int pop(struct element* tab, int pt_pas_pt){

	int porteelocale = tab[pt_pas_pt].portee;
	pt_pas_pt--;
	while((tab[pt_pas_pt].portee == porteelocale) && (pt_pas_pt >= 0)){
		pt_pas_pt --;
	}
	
	return pt_pas_pt;
}

int pop_unique(struct element* tab, int pt_pas_pt){
	int addr = tab[pt_pas_pt].addr;	
	return addr;
}


int push(struct element* tab, int pt_pas_pt, struct element truc_a_rajouter){
	pt_pas_pt++;
	tab[pt_pas_pt].nom = strndup(truc_a_rajouter.nom, 32);
	tab[pt_pas_pt].typeparam = truc_a_rajouter.typeparam;


	tab[pt_pas_pt].addr = truc_a_rajouter.addr;
	tab[pt_pas_pt].portee = truc_a_rajouter.portee;

	return pt_pas_pt;
}

int guete(struct element* tab, char* nom_var, int pt_pas_pt){
	for(int i=0; i<=pt_pas_pt; i++){
		if(strcmp(tab[i].nom, nom_var)==0) return i;
	}
	return -1;
}

//Ajout d'un element a la table des symboles
int ajout(char *nom,type typeparam,struct element *tab,int addr,int portee,int pointeur){
	printf("CREA VAR %s\n",nom);
	struct element elem = {nom,typeparam,addr,portee};
	//Ajout a la table des symboles
	push(tab, pointeur, elem);
	//Mise a jour de addr en fonction du type de la var ajoutee
	switch(typeparam){
		case INT:
			addr += 4;
			break;
	
	}
	return addr;
}






