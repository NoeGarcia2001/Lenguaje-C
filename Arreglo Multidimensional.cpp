// Programa que llena un arreglo tridimensional de 2×2×2 con valores secuenciales en el eje "alto" y luego 
//imprime los elementos organizados para representar las "unidades" de un cubo en un formato estructurado.
#include<stdio.h>

int main(){
	
	int ancho,largo,alto;
	int matriz[2][2][2];
	
	printf("Esto es un array que representa un cubo\n");
	
	  for(ancho=0; ancho<2; ancho++){
		   for(largo=0; largo<2;largo++){
			  for(alto=0; alto<2;alto++){
				
				matriz[ancho][largo][alto]=alto+1;
				printf("Unidad: %d\t",matriz[ancho][largo][alto]);
			  }
		    
			printf("\n\t");
		   }
		 
		 printf("\n\t");	
	  }
	  
	return 0;
}
