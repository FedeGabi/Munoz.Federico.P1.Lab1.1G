#include "fecha.h"






int cargarFecha(eFecha* fecha)
{
    int retorno=0;
    int seguir=1;
    int auxDia;
    int auxMes;
    int auxAnio;
    do
    {
        printf("\n ingrese dia: ");
        scanf("%d", &auxDia);
        printf("\n ingrese mes: ");
        scanf("%d", &auxMes);
        printf("\n ingrese anio: ");
        scanf("%d", &auxAnio);
        if(auxDia > 0 && auxDia <=31 && auxMes >0 && auxMes <=12 && auxAnio >2021 && auxAnio <2023)
        {
            fecha->dia=auxDia;
            fecha->mes=auxMes;
            fecha->anio=auxAnio;
            retorno=1;
            seguir=0;
        }
        else
        {
            seguir=confirmar("\n valores incorrectos. Desea reingresar? (s o n): ");
        }
    }
    while(seguir==1);
    return retorno;
}
