#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 100

/*Prototipo*/
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

/*Funciones*/

// Funcion de generar numeros randoms de acuerdo a sus cifras
void GeneraRandomforMult(int *V, int *ncMax)
{
    int nc, i, min = 1, max = 1;
    printf("Selecciona el numero de cifras deseado (rango de 1 a 7)\n");
    do {
        scanf("%d", &nc);
        if (nc < 1 || nc > 7)
            printf("error al ingresar cifras requeridas\n");
    } while (nc < 1 || nc > 7);

    for (i = 0; i < nc - 1; i++)
        min *= 10;
    for (i = 0; i < nc; i++)
        max *= 10;

    *V = (rand() % (max - min)) + min;
    if (*ncMax < nc)
        *ncMax = nc;
}

// Funcion para Ingresar paginas
void ShareYourPageNumber(int *NumP)
{
    printf("Ingresa el numero de operaciones que quieres hacer\n");
    do {
        scanf("%d", NumP);
        if (*NumP < 0 || *NumP > N)
            printf("ups intenta de nuevo\n");
    } while (*NumP < 0 || *NumP > N);
}

// Funcion preguntar si quieres salir
void PreguntaChistosa(int *Op)
{
    printf("¿Deseas salir?\nSi = 0 o No = 1, (ponlo en numeros)\n");
    scanf("%d", Op);
}

// Funcion genera random para suma y resta
void GeneraRandomSum(int Arr[N], int *ncMax, int Nc)
{
    int nc, i, k;
    for (k = 0; k < Nc; k++) {
        int min = 1, max = 1; // reiniciar en cada vuelta
        printf("Selecciona el numero de cifras deseado (rango de 1 a 7)\n");
        do {
            scanf("%d", &nc);
            if (nc < 1 || nc > 7)
                printf("error al ingresar cifras requeridas\n");
        } while (nc < 1 || nc > 7);

        for (i = 0; i < nc - 1; i++)
            min *= 10;
        for (i = 0; i < nc; i++)
            max *= 10;

        Arr[k] = (rand() % (max - min)) + min;
        if (*ncMax < nc)
            *ncMax = nc;
    }
}

// Funcion de Multiplicacion
void Multiplicacion(int nc1, int nc2, int ncMax)
{
    int result, i;
    char Resp[N], Resp2[N], Resp3[N];
    strcpy(Resp2, "Correcto:)");
    strcpy(Resp3, "Incorrecto:(");

    do {
        printf(" %d\n", nc1);
        printf("*%d\n", nc2);
        for (i = 0; i <= ncMax; i++) {
            printf("-");
        }
        printf("\n");
        scanf("%d", &result);

        if (result == nc1 * nc2) {
            printf("correcto :)\n");
            strcpy(Resp, Resp2);
        } else {
            printf("Incorrecto:(\n");
            strcpy(Resp, Resp3);
        }
    } while (strcmp(Resp, Resp2) != 0);
}

// Funcion suma
void suma(int ArrSum[N], int ncMax, int NumN)
{
    int result, i, suma, k;
    char Resp[N], Resp2[N], Resp3[N];
    strcpy(Resp2, "Correcto:)");
    strcpy(Resp3, "Incorrecto:(");

    do {
        suma = 0;
        printf(" %d\n", ArrSum[0]);
        for (k = 1; k < NumN; k++) { // corregido
            printf("+%d\n", ArrSum[k]);
        }

        for (k = 0; k < NumN; k++)
            suma += ArrSum[k];

        // contar cifras del mayor número y del resultado
        int temp, cifras, maxCifras = 0;
        for (k = 0; k < NumN; k++) {
            temp = ArrSum[k];
            cifras = 0;
            if (temp == 0) cifras = 1;
            if (temp < 0) temp = -temp;
            while (temp > 0) { temp /= 10; cifras++; }
            if (cifras > maxCifras) maxCifras = cifras;
        }
        temp = suma;
        cifras = 0;
        if (temp == 0) cifras = 1;
        if (temp < 0) temp = -temp;
        while (temp > 0) { temp /= 10; cifras++; }
        if (cifras > maxCifras) maxCifras = cifras;

        for (i = 0; i < maxCifras; i++) {
            printf("__");
        }
        printf("\n");

        scanf("%d", &result);

        if (result == suma) {
            printf("Correcto :)\n");
            strcpy(Resp, Resp2);
        } else {
            printf("Incorrecto :(\n");
            strcpy(Resp, Resp3);
        }
    } while (strcmp(Resp, Resp2) != 0);
}

// Funcion resta
void Resta(int nc1, int nc2, int ncMax)
{
    int result, i;
    char Resp[N], Resp2[N], Resp3[N];
    strcpy(Resp2, "Correcto:)");
    strcpy(Resp3, "Incorrecto:(");

    do {
        printf(" %d\n", nc1);
        printf("-%d\n", nc2);
        for (i = 0; i <= ncMax + 1; i++) {
            printf("-");
        }
        printf("\n");
        scanf("%d", &result);

        if (result == (nc1 - nc2)) {
            printf("correcto :)\n");
            strcpy(Resp, Resp2);
        } else {
            printf("Incorrecto:(\n");
            strcpy(Resp, Resp3);
        }
    } while (strcmp(Resp, Resp2) != 0);
}

void conjuntoSuma(int as[N], int np, int *may, int *ncm, int *resp)
{
    int i;
    for (i = 0; i < np && *may != 0; i++) {
        printf("Dame la cantidad de numeros que deseas sumar de 2 a 4\n");
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
    } while (*resp < 2 || *resp > 4);
}

void ConjuntoResta(int *mndo, int *stndo, int np, int *ncm, int *may)
{
    int aux, i;
    for (i = 0; i < np && *may != 0; i++) {
        GeneraRandomforMult(mndo, ncm);
        GeneraRandomforMult(stndo, ncm);
        if (*mndo < *stndo) {
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
    for (i = 0; i < np && *may != 0; i++) {
        GeneraRandomforMult(mltd, ncm);
        GeneraRandomforMult(mltn, ncm);
        Multiplicacion(*mltd, *mltn, *ncm);
        PreguntaChistosa(may);
    }
}

// Eleccion principal
int EligeBien()
{
    int opC;
    printf("Elige el tipo de operacion que deseas relizar\n");
    printf("1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\n");
    do {
        scanf("%d", &opC);
    } while (opC < 1 || opC > 4);
    return opC;
}

// Funcion switch
void SwitchFun(int opC)
{
    int NP = 0, May = 1, NCM = 0;
    switch (opC) {
    case 1: {
        printf("Suma\n");
        int arrS[N], res;
        ShareYourPageNumber(&NP);
        conjuntoSuma(arrS, NP, &May, &NCM, &res);
        break;
    }
    case 2: {
        printf("Resta\n");
        int Mnndo, Strndo;
        ShareYourPageNumber(&NP);
        ConjuntoResta(&Mnndo, &Strndo, NP, &NCM, &May);
        break;
    }
    case 3: {
        printf("Multiplicacion\n");
        int multdr, multcndo;
        ShareYourPageNumber(&NP);
        ConjuntoMultiplicacion(&multdr, &multcndo, NP, &May, &NCM);
        break;
    }
    case 4:
        printf("Division (pendiente)\n");
        break;
    default:
        printf("Adios\n");
        break;
    }
}

// Funcion Principal
int main(int argc, char *argv[]) {
    int opc = 0;
    srand(time(NULL));
    opc = EligeBien();
    SwitchFun(opc);
    return 0;
}
