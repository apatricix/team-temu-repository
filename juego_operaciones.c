//Team temu.
//• Alan Abel García Escobar
//• Iván Alejandro Castañón Chiquito
//• America Patricia Morales Avalos

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int EligeBien();
void SwitchFun(int opC);
void GeneraRandomSum(int Arr[N], int *ncMax, int Nc);
void GeneraRandomforMult(int *V, int *ncMax);
void Multiplicacion(int nc1, int nc2, int ncMax);
void suma(int ArrSum[N], int ncMax, int NumN);
void Resta(int nc1, int nc2, int ncMax);
void ShareYourPageNumber(int *NumP);
void PreguntaChistosa(int *Op);
void conjuntoSuma(int as[N], int np, int *may, int *ncm, int *resp);
void ConjuntoResta(int *mndo, int *stndo, int np, int *ncm, int *may);
void FuncEsp1(int *res);
void ConjuntoMultiplicacion(int *mltd, int *mltn, int np, int *may, int *ncm);
void Division(int nc1, int nc2, int ncMax);
void ConjuntoDivision(int *dividendo, int *divisor, int np, int *may, int *ncm);

void GeneraRandomforMult(int *V, int *ncMax) 
{
    int nc, i, min=1, max=1;
    printf("Selecciona el numero de cifras deseado (rango de 1 a 7)\n");
    do{
        scanf("%d", &nc);
        if(nc < 1 || nc > 7)
            printf("error al ingresar cifras requeridas\n");
    } while(nc < 1 || nc > 7);
    for(i = 0; i < nc - 1; i++)
        min *= 10;
    for(i = 0; i < nc; i++)
        max *= 10;
    *V = (rand() % (max-min+1)) + min;
    if(*ncMax < nc)
        *ncMax = nc;
}

void ShareYourPageNumber(int *NumP) 
{
    printf("Ingresa el numero de operaciones que quieres hacer\n");
    do{
        scanf("%d", NumP);
        if(*NumP < 0 || *NumP > N)
            printf("ups intenta de nuevo\n");
    } while(*NumP < 0 || *NumP > N);
}

void PreguntaChistosa(int *Op)
{
    printf("¿Deseas salir?\nSi = 0 o No = 1 (ponlo en numeros)\n");
    scanf("%d", Op);
}

void GeneraRandomSum(int Arr[N], int *ncMax, int Nc) 
{
    int nc, i, min, max, k;
    for(k = 0; k < Nc; k++)
    {
        min = 1; max = 1;
        printf("Selecciona el numero de cifras deseado (rango de 1 a 7)\n");
        do{
            scanf("%d", &nc);
            if(nc < 1 || nc > 7)
                printf("error al ingresar cifras requeridas\n");
        } while(nc < 1 || nc > 7);
        for(i = 0; i < nc - 1; i++)
            min *= 10;
        for(i = 0; i < nc; i++)
            max *= 10;
        Arr[k] = (rand() % (max-min+1)) + min;
        if(*ncMax < nc)
            *ncMax = nc;
    }
}

void Multiplicacion(int nc1, int nc2, int ncMax)
{
    int result, i;
    char Resp[N], Resp2[N], Resp3[N];
    strcpy(Resp2, "Correcto:)");
    strcpy(Resp3, "Incorrecto:(");
    do{
        printf(" %d\n", nc1);
        printf("*%d\n", nc2);
        for(i = 0; i <= ncMax; i++)
        {
            printf("-");
        }
        printf("\n");
        scanf("%d", &result);
        if(result == nc1*nc2)
        {
            printf("Correcto :)\n");
            strcpy(Resp, Resp2);
        }  
        else 
        {
            printf("Incorrecto :(\n");
            strcpy(Resp, Resp3);
        }
    } while(strcmp(Resp, Resp2) != 0);
}

void suma(int ArrSum[N], int ncMax, int NumN)
{
    int result, i, suma, k;
    char Resp[N], Resp2[N], Resp3[N];
    strcpy(Resp2, "Correcto:)");
    strcpy(Resp3, "Incorrecto:(");
    do{
        suma=0;
        printf(" %d\n", ArrSum[0]);
        for(k=1; k < NumN; k++)
        {
            printf("+%d\n", ArrSum[k]);
        }
        for(k=0; k < NumN; k++)
            suma += ArrSum[k];
        for(i=0; i <= ncMax; i++)
        {
            printf("__");
        }
        printf("\n");
        scanf("%d", &result);
        if(result==suma)
        {
            printf("Correcto :)\n");
            strcpy(Resp, Resp2);
        }
        else
        {
            printf("Incorrecto :(\n");
            strcpy(Resp, Resp3);
        }
    } while(strcmp(Resp, Resp2) != 0);
}

void Resta(int nc1, int nc2, int ncMax)
{
    int result, i;
    char Resp[N], Resp2[N], Resp3[N];
    strcpy(Resp2, "Correcto:)");
    strcpy(Resp3, "Incorrecto:(");
    do{
        printf(" %d\n", nc1);
        printf("-%d\n", nc2);
        for(i = 0; i <= ncMax + 1; i++)
        {
            printf("-");
        }
        printf("\n");
        scanf("%d", &result);
        if(result == (nc1-nc2))
        {
            printf("Correcto :)\n");
            strcpy(Resp, Resp2);
        }  
        else 
        {
            printf("Incorrecto :(\n");
            strcpy(Resp, Resp3);
        }
    } while(strcmp(Resp, Resp2) != 0);
}

void conjuntoSuma(int as[N], int np, int *may, int *ncm, int *resp)
{
    int i;
    for(i=0; i < np && *may != 0; i++)
    {
        printf("Dame la cantidad de numeros que deseas sumar de 1 a 4\n");
        FuncEsp1(resp);
        GeneraRandomSum(as, ncm, *resp);
        suma(as, *ncm, *resp);
        PreguntaChistosa(may);
    }
}

void FuncEsp1(int *resp)
{
    do {
        scanf("%d", resp);
    } while(*resp < 1 || *resp > 4);
}

void ConjuntoResta(int *mndo, int *stndo, int np, int *ncm, int *may)
{
    int aux, i;
    for(i=0; i < np && *may != 0; i++)
    {
        GeneraRandomforMult(mndo, ncm);
        GeneraRandomforMult(stndo, ncm);
        if(*mndo < *stndo)
        {
            aux = *mndo;
            *mndo = *stndo;
            *stndo = aux;
        }
        Resta(*mndo, *stndo, *ncm);
        PreguntaChistosa(may);
    }
}

void ConjuntoMultiplicacion(int *mltd, int *mltn, int np, int *may, int *ncm)
{
    int i;
    for(i=0; i < np && *may != 0; i++)
    {
        GeneraRandomforMult(mltd, ncm);
        GeneraRandomforMult(mltn, ncm);
        Multiplicacion(*mltd, *mltn, *ncm);
        PreguntaChistosa(may);
    }
}

void Division(int nc1, int nc2, int ncMax)
{
    int result, i;
    char Resp[N], Resp2[N], Resp3[N];
    strcpy(Resp2, "Correcto:)");
    strcpy(Resp3, "Incorrecto:(");
    if(nc2 == 0)
        nc2 = 1;
    do{
        printf(" %d\n", nc1);
        printf("/%d\n", nc2);
        for(i = 0; i <= ncMax; i++)
        {
            printf("-");
        }
        printf("\n");
        scanf("%d", &result);
        if(result == nc1 / nc2)
        {
            printf("Correcto :)\n");
            strcpy(Resp, Resp2);
        }
        else
        {
            printf("Incorrecto :(\n");
            strcpy(Resp, Resp3);
        }
    } while(strcmp(Resp, Resp2) != 0);
}

void ConjuntoDivision(int *dividendo, int *divisor, int np, int *may, int *ncm)
{
    int i;
    for(i = 0; i < np && *may != 0; i++)
    {
        GeneraRandomforMult(dividendo, ncm);
        GeneraRandomforMult(divisor, ncm);
        Division(*dividendo, *divisor, *ncm);
        PreguntaChistosa(may);
    }
}

int EligeBien()
{
    int opC;
    printf("Elige el tipo de operacion que deseas relizar\n");
    printf("1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\n");
    do{
        scanf("%d", &opC);
    } while(opC < 1 || opC > 4);
    return opC;
}

void SwitchFun(int opC)
{
    int NP=0, May=1, NCM=0;
    switch (opC)
    {
    case 1: printf("Suma\n");
        int arrS[N], res;
        ShareYourPageNumber(&NP);
        conjuntoSuma(arrS, NP, &May, &NCM, &res);
        break;
    case 2: printf("Resta\n");
        int Mnndo, Strndo;
        ShareYourPageNumber(&NP);
        ConjuntoResta(&Mnndo, &Strndo, NP, &NCM, &May);
        break;
    case 3: printf("Multiplicacion\n");
        int multdr, multcndo;
        ShareYourPageNumber(&NP);
        ConjuntoMultiplicacion(&multdr, &multcndo, NP, &May, &NCM);
        break;
    case 4: printf("Division\n");
        int divd, divs;
        ShareYourPageNumber(&NP);
        ConjuntoDivision(&divd, &divs, NP, &May, &NCM);
        break;
    default: printf("Adios\n");
        break;
    }
}

int main(int argc, char *argv[]) {
    int opc=0;
    srand(time(NULL));
    opc = EligeBien();
    SwitchFun(opc);
    return 0;
}
