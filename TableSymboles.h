typedef enum type {
	INT,
	CHAR,
	PTR,
}type;


struct element {
	char *nom;
	type typeparam;
	int addr;
	int portee;
	int context;
};


int pop(struct element* tab, int pt_pas_pt, int portee, int context);
int push(struct element* tab, int pt_pas_pt, struct element truc_a_rajouter);

int guete(struct element* tab, char* nom_var, int pt_pas_pt, int context);
int ajout_var(char *nom,type typeparam,struct element *tab,int addr,int portee,int pointeur,int context);
int pop_unique(struct element* tab, int pt_pas_pt);
