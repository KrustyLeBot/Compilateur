#include "TSonga.h"
#include <string.h>





int pop(struct element* tab, int pt_pas_pt){

	int porteelocale = tab[pt_pas_pt].portee;
	pt_pas_pt--;
	while((tab[pt_pas_pt].portee == porteelocale) && (pt_pas_pt >= 0)){
		pt_pas_pt --;
	}
	return pt_pas_pt;
}


int push(struct element* tab, int pt_pas_pt, struct element truc_a_rajouter){
	pt_pas_pt++;
	tab[pt_pas_pt].nom = strdup(truc_a_rajouter.nom);
	tab[pt_pas_pt].type = strdup(truc_a_rajouter.type);

	printf("var:   %s\n", tab[pt_pas_pt].nom);

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
