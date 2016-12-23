#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {

	char *nombre;
	int edad;
		
	
}Persona;


int main(){


	int N =30;

	char array[N];
	
	Persona per;
	per.nombre = "Jorge";
	per.edad = 85;
		
	printf("%s \n", per.nombre);		
	
	Persona per2 ={"Edu", 56};
	printf("%s \n", per2.nombre);
	printf("%d \n", per2.edad);

	Persona *perP = &per2;

	(*perP).nombre = "Jose";
	(*perP).edad = 178;
	
	
	
	printf("%s \n", per2.nombre);
	printf("%d \n", per2.edad);

	perP->nombre = "Panita";
	perP->edad = 456;

	printf("%s \n", per2.nombre);
	printf("%d \n", per2.edad);	

}


