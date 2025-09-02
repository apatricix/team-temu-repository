#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 100
/*Prototipo*/

void GeneraRandom(int *V);
void GeneraRandomforMult(int *V, int *ncMax);
void Multiplicacion(int nc1, int nc2, int ncMax);
void suma(int n1, int n2,int ncMAX);
void ShareYourPageNumber(int*NumP);
void PreguntaChistosa(int *Op);


/*Funciones*/

//Funcion de generar numeros randoms de acuerdo a sus cifras

void GeneraRandom(int *V) //donde V es el valor y nc es el numero de cifras
{
	int nc, i, min=1, max=1;
	printf("Selecciona el numero de cifras deseado (rango de 0 a 7)\n");
	do{
		scanf("%d", &nc);
		if(nc < 0 && nc > 7)
			printf("error al ingresar cifras requeridas");
	} while(nc < 0 && nc > 7);
	if(nc == 0)
		return;
	else
	{
		for(i = 0; i < nc - 1; i++)
		    min *= 10;
	    for(i = 0; i < nc; i++)
		    max *= 10;
	    *V = (rand() % (max-min+1)) + min;
	}
}

//Funcion para Ingresar paginas

void ShareYourPageNumber(int*NumP) 
{
	printf("Ingresa el numero de operaciones que quieres hacer\n");
	do{
		scanf("%d", NumP);
		if(*NumP < 0 && *NumP >N)
			printf("ups intenta de nuevo\n");
	} while(*NumP < 0 && *NumP > N);
}

//Funcion preguntar si quieres salir

void PreguntaChistosa(int *Op)
{
	printf("¿Deseas salir\nSi = 0 o No = 1, (ponlo en numeros)?\n");
	scanf("%d", Op);
}

//Genera para multiplicacion 

void GeneraRandom(int *V, int *ncMax) //donde V es el valor y nc es el numero de cifras
{
	int nc, i, min=1, max=1;
	printf("Selecciona el numero de cifras deseado (rango de 1 a 7)\n");
	do{
		scanf("%d", &nc);
		if(nc < 1 && nc > 7)
			printf("error al ingresar cifras requeridas");
	} while(nc < 1 && nc > 7);
	for(i = 0; i < nc - 1; i++)
		min *= 10;
	for(i = 0; i < nc; i++)
		max *= 10;
	*V = (rand() % (max-min+1)) + min;
	if(*ncMax < nc)
		*ncMax = nc;
}

//Funcion de Multiplicacion

void Multiplicacion(int nc1, int nc2, int ncMax)
{
	int result, i;
	char Resp[N], Resp2[N], Resp3[N];
	strcat(Resp2, "Correcto:)");
	strcat(Resp3, "Incorrecto:(");
	do{
		printf(" %d\n", nc1);
	    printf("*%d\n", nc2);
	    for(i=0; i <= ncMax; i++)
	    {
			printf("-");
	    }
	    printf("\n");
	    scanf("%d", &result);
	    if(result == nc1*nc2)
	    {
		    printf("correcto :)\n");
			strcpy(Resp, Resp2);
	    }  
	    else 
	    {
		    printf("Incorrecto:(\n");
			strcpy(Resp, Resp3);
	    }
	} while(strcmp(Resp, Resp2) != 0);
}

void suma( int n1,int n2, int ncMax)
{
    int result, i;
    char Resp[N], Resp[N], Resp[N];
    strcpy(Resp2, "correcto");
	strcpy(Resp3, "incorrecto");

	do{
		printf("%d?\n", n1);
		printf("%d?\n", n2);
		for(int i=0; i<=ncMax; i++)
		{
			printf("__");
		}
		printf("\n");
		scanf("%d", &result);

		if(result==n1+n2)
		{
		printf("correcto\n");
		strcpy(Resp, Resp2);
		}
		else
		{
         printf("incorrecto\n")
		 strcpy(Resp, Resp3);
		}
}
		while(strcmp(Resp, Resp2) !=0);
}








//Funcion Principal

int main(int argc, char *argv[]) {
	int opc=0;
	int NP;
	srand(time(NULL));
	printf("Elige el tipo de operacion que deseas relizar\n");
	printf("1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\n");
	int multdr, multcndo, NCM=0, i, May; //Donde NCM es el numero de cifras maximas y May es la resp del usuario
	ShareYourPageNumber(&NP);
	for(i=0; i < NP && May != 0; i++)
	{
		GeneraRandomforMult(&multdr, &NCM);
	    GeneraRandomforMult(&multcndo, &NCM);
	    Multiplicacion(multdr, multcndo, NCM);
	    PreguntaChistosa(&May);
	}
	
	do{
		scanf("%d", &opc);
		switch (opc)
		{
		case 1: 
		printf("Suma\n");
		GeneraRandomforMult(&multdr, &NCM);
		GeneraRandomforMult(&multcndo, &NCM);
		suma(multdr, multdr, multcndo, NCM);
		break;
		case 2: printf("Resta\n");
		
		break;
		case 3: printf("Multiplicacion\n");
		int multdr, multcndo, NCM=0, i, May; //Donde NCM es el numero de cifras maximas y May es la resp del usuario
		ShareYourPageNumber(&NP);
		for(i=0; i < NP && May != 0; i++)
		{
			GeneraRandomforMult(&multdr, &NCM);
			GeneraRandomforMult(&multcndo, &NCM);
			Multiplicacion(multdr, multcndo, NCM);
			PreguntaChistosa(&May);
		}
		break;
		case 4: printf("Division\n");
		
		break;
		default: printf("Ingresa de nuevo tu eleccion\n");
		
		break;
		}
	} while(opc < 1 && opc > 4);
	return 0;
}