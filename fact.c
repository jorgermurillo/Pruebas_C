#include <stdio.h>
#include <stdlib.h>


int fact(int x);

int main(){

	int respuesta = fact(25);
	printf("%d \n",respuesta);
	printf("%d \n",fact(1));
	


}

int fact(int x){

	if(x==0 || x==1){
		return 1;	
	}else{
		return (x*fact(x-1));	
	}

	

}
