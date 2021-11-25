#include "Biblioteca.h"

int IngresarNumeroEnteroDeMaximoAMinimo(char mensaje[], int max, int min)
{
    char numeroIngresado [51];
    int isNaN;
    int numeroValidado;
    int flag = 1;
    do
    {
        if(flag==0)
        {
            printf("Error.");
        }

        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]",numeroIngresado);
        isNaN = ValidarNumeroEntero(numeroIngresado);

        while(isNaN ==-1)
        {
        printf("Error. %s", mensaje);
        fflush(stdin);
        scanf("%[^\n]",numeroIngresado);
        isNaN = ValidarNumeroEntero(numeroIngresado);
        }

        numeroValidado = atoi(numeroIngresado);
    flag=0;
    }while (numeroValidado < min || numeroValidado > max);

    return numeroValidado;
}
void IngresarCadena (char mensaje[], char cadenaIngresada[])
{
    int isString;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadenaIngresada);

    isString = ValidarCadena (cadenaIngresada);
    while(isString == -1)
    {
    printf(" %s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadenaIngresada);
    isString = ValidarCadena (cadenaIngresada);

    }

    NormalizarCadena(cadenaIngresada);

}

float IngresarNumeroFlotante (char mensaje[])
{
    char numeroIngresado [51];
    int isNaN;
    float numeroValidado;
    int flag = 1;
    do
    {
        if(flag==0)
        {
            printf("Error.");
        }
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]",numeroIngresado);
        isNaN = ValidarNumeroFlotante(numeroIngresado);

        while(isNaN ==-1)
        {
        printf("Error. %s", mensaje);
        fflush(stdin);
        scanf("%[^\n]",numeroIngresado);
        isNaN = ValidarNumeroFlotante(numeroIngresado);
        }

        numeroValidado = atof(numeroIngresado);
        flag = 0;
    }while (numeroValidado <= 0);

    return numeroValidado;
}

int ValidarNumeroEntero(char numeroIngresado[])
{
    int numeroValidado =0;
    for(int i=0; i < strlen(numeroIngresado); i++)
    {
        if ((isdigit(numeroIngresado[i])==0))
        {
        numeroValidado = -1;
        break;
        }
    }
 return numeroValidado;
}

int ValidarCadena(char cadenaIngresada[])
{
    int cadenaValidada = 0;
    for(int i=0; i < strlen(cadenaIngresada); i++)
    {
         if (cadenaIngresada[0] == ' ')
        {
            cadenaValidada = -1;
            printf("No se admiten espacios en primera instancia.");
            break;
        }
        else if (isalpha(cadenaIngresada[i])==0 && cadenaIngresada[i] != ' ')
        {
        cadenaValidada = -1;
        printf("No se admiten numeros/signos.");
        break;
        }
        else if (cadenaIngresada[i] == ' ' && cadenaIngresada[i+1] == ' ')
        {
            cadenaValidada = -1;
            printf("No se admiten mas de dos espacios seguidos.");
        }
    }
    return cadenaValidada;
}

int ValidarNumeroFlotante(char numeroIngresado[])
{
    int numeroValidado = 0;
    int flag=1;

    for(int i = 0; i< strlen(numeroIngresado); i++)
    {
        if (flag && numeroIngresado[i] == '.')
        {
                flag = 0;
        }else if(isdigit(numeroIngresado[i])==0)
            {
                numeroValidado = -1;
                break;
            }

    }
    return numeroValidado;
}

void NormalizarCadena(char cadenaIngresada[])
{

    int flagNormalizar = 1;
    for(int i=0;i<strlen(cadenaIngresada);i++)
    {
        if(cadenaIngresada[i]== ' ')
        {
        flagNormalizar = 1;
        }

         else if (flagNormalizar && cadenaIngresada)
        {
            cadenaIngresada[i] = toupper(cadenaIngresada[i]);
            flagNormalizar = 0;
        }

        else
        {
        cadenaIngresada[i] = tolower(cadenaIngresada[i]);
        }

    }
}
