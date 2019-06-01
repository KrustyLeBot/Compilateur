#include "Fonctions.h"
#include <string.h>

int get_start_line(struct fonc* tab, int size, char * nom_var){
	for(int i=0; i<size; i++){
		if(strcmp(tab[i].nom, nom_var)==0) return tab[i].start_line;
	}
	return -1;
}

int get_param_addr(struct fonc* tab, int size, char * nom_var){
	for(int i=0; i<size; i++){
		if(strcmp(tab[i].nom, nom_var)==0) return tab[i].start_addr_param;
	}
	return -1;
}

int get_param(struct fonc* tab, int size, char * nom_var){
	for(int i=0; i<size; i++){
		if(strcmp(tab[i].nom, nom_var)==0) return tab[i].parameters;
	}
	return -1;
}

int get_context(struct fonc* tab, int size, char * nom_var){
	for(int i=0; i<size; i++){
		if(strcmp(tab[i].nom, nom_var)==0) return tab[i].context;
	}
	return -1;
}

int exist(struct fonc* tab, int size, char * nom_var){
	if(size==0) {return 0;}
	for(int i=0; i<size; i++){
		if(strcmp(tab[i].nom, nom_var)==0) return 1;
	}
	return 0;
}

void add_fct(struct fonc* tab, int parameters, char * nom_var, int line, int start_line, int context, int start_addr_param){
	struct fonc tmp = {nom_var,parameters,start_line,context,start_addr_param};
	tab[line] = tmp;
}
