typedef struct element {
	char *nom;
	char *type;
	int addr;
	int portee;
};


int pop(struct element* tab, int pt_pas_pt);
int push(struct element* tab, int pt_pas_pt, struct element truc_a_rajouter);

int guete(struct element* tab, char* nom_var, int pt_pas_pt);
