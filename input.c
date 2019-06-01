int add(int a, int b){
	return a+b;
}

int sub(int a, int b){
	return a-b;
}

int mul(int a, int b){
	return a*b;
}

main(){
	int a = 5;
	int b = 10;	
	int c = add(a,b);
	int d = sub(a,b);
	int e = mul(a,b);
	int f = 0;
	int g = 0;
	int h = 0;
	
	for(int i=0;i<a;i=i+1){
		f=f+1;
	}

	while(g<b){
		g=g+1;
	}
	
	if((f==a) && (g==b)){
		h=99;
	}	
	else{
		h=88;
	}
}
