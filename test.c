main(){int a = 2;int b = 3;b = a;}
main(){int a = 2;}
main(){int a = 2;int b = 3;int c = a+ b;}
main(){int a = 2;int b = 3;int c = a+b;}
main(){int a = 2;int b = 3;int c = a* 2;}

main(){int a = 2;int b = 2 ;b = -2*a+b;}

main(){int a = 1;if(a==1){a=2;}int c=99;}

main(){int a = 2;int b = 2;int c = 1;if(c<=1){a=100;}else{a=99;}b=4;}
main(){int a = 2;int b = 2;int c = 1;if(c==1){a=100;}else if(c==2){a=90;}else{a=80;}b=4;}	

main(){int a = 0;int b = 100;while(b>0){a=a+2;b=b-1;}}

main(){int a = 0;int b = 0;int c = (a&&b);}  // c=0
main(){int a = 0;int b = 1;int c = (a&&b);}  // c=0
main(){int a = 1;int b = 0;int c = (a&&b);}  // c=0
main(){int a = 1;int b = 1;int c = (a&&b);}  // c=1

main(){int a = 0;int b = 0;int c = (a||b);}  // c=0
main(){int a = 0;int b = 1;int c = (a||b);}  // c=1
main(){int a = 1;int b = 0;int c = (a||b);}  // c=1
main(){int a = 1;int b = 1;int c = (a||b);}  // c=1

main(){int a = 2;int b = 4;int* c = &a; *c = 10;c=&b;*c=20;}

main(){int a=2;int b = ((a==2)?10:20);int c = 3;}
main(){int a=2;int b = (a==3)?10:20;}

main(){/*ce programme ne sert a rien*/int a=2;int b = (a==3)?10:20;}

main(){int a = 2;int b = 3;idiot b = a; b=4;}
