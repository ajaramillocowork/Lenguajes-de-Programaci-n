#include<stdio.h>

void main(){
	int numero;
	int ciclo= 0;
	int resultado=0;
	int resto=0;
	
	printf("Ingrese un numero entero");
	scanf("%i",&numero);
	
	resultado=numero/1000;
	for(ciclo=0;ciclo<resultado;ciclo++){
		printf("M");
	}
	resto=numero%1000;
	numero=resto;
	resultado=numero/500;
	for(ciclo=0;ciclo<resultado;ciclo++){
		printf("D");
	}
	resto=numero%500;
	numero=resto;
	resultado=numero/100;
	if(resultado==4){
		printf("CD");
	}else{
		for(ciclo=0;ciclo<resultado;ciclo++){
		printf("C");
		}
	}
	resto=numero%100;
	numero=resto;
	resultado=numero/50;
	for(ciclo=0;ciclo<resultado;ciclo++){
		printf("L");
	}
	resto=numero%50;
	numero=resto;
	resultado=numero/10;
	if(resultado==4){
		printf("XL");
	}else{
		for(ciclo=0;ciclo<resultado;ciclo++){
			printf("X");
		}
	}	
	resto=numero%10;
	numero=resto;
	resultado=numero/5;
	for(ciclo=0;ciclo<resultado;ciclo++){
		printf("V");
	}
	resto=numero%5;
	numero=resto;
	if(numero==4){
		printf("IV");
	}else{
		for(ciclo=0;ciclo<numero;ciclo++){
			printf("I");
		}
	}	
}

