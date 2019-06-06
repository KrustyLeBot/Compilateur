//Structure tab fonctions
struct fonc{
	char * nom;
	int parameters;
	int start_line;
	int context;
	int start_addr_param;
};

int get_start_line(struct fonc* tab, int size, char * nom_var);
int get_param(struct fonc* tab, int size, char * nom_var);
int get_param_addr(struct fonc* tab, int size, char * nom_var);
int get_context(struct fonc* tab, int size, char * nom_var);
int exist(struct fonc* tab, int size, char * nom_var);
void add_fct(struct fonc* tab, int parameters, char * nom_var, int line, int start_line, int context, int start_addr_param);
