//1
#include <stdio.h>
#include <string.h>

//2
struct Estudiante
{

     char nombre[50];

      int edad;

     float promedio;

     char grado;

};

//3
void imprimir(struct Estudiante info)
{
    printf("Nombre: %s\n",info.nombre);
    printf("Edad: %d\n",info.edad);
    printf("Promedio: %.2f\n",info.promedio);
    printf("Grado: %c\n",info.grado);

};

//4
void ModificaPromGrad (struct Estudiante  *dato)
{
    float NuevoProm;
    char NuevoGrad;

    printf("Nuevo promedio del estudiante:");
    scanf("%f",&NuevoProm);
    dato->promedio = NuevoProm ;

    printf("Nuevo grado del estudiante:");
    scanf(" %c",&NuevoGrad);
    dato->grado = NuevoGrad ;


};

struct Materia
{
   char Materia[25];
   float Calificacion;
   int Creditos;
};

void ImprMateria (struct Materia info)
{
    printf("Materia: %s\n", info.Materia);
    printf("Calificacion: %.2f\n", info.Calificacion);
    printf("Creditos: %d\n", info.Creditos);
};


float PromeGeneral(struct Materia m1, struct Materia m2, struct Materia m3) {

    float sumaCalificaciones = m1.Calificacion + m2.Calificacion + m3.Calificacion;
    return sumaCalificaciones / 3;
}

//5
int main()
{

struct Estudiante ana = {"Ana Garcia", 19, 9.5, 'A'}; //Inicialización

imprimir(ana);
printf("%d\n\n",ana);

printf("MODIFICACION DE PROMEDIO\n\n");

ModificaPromGrad(&ana);
printf("\n\n");

printf("LOS DATOS ACTUALIZADOS SON:\n");
imprimir(ana);

printf("\n\n\n\n");



struct Materia segundo[3]=
{
    {"Programacion Estructurada",40.8,8},
    {"Calculo",96.4,6},
    {"Matematicas Discretas",78.4,4},
};

printf("Informacion de las materias:\n");
    for (int i = 0; i < 3; i++) {
        ImprMateria(segundo[i]);
        printf("\n");
    }

 float promedioGeneral = PromeGeneral(segundo[0], segundo[1], segundo[2]);
    printf("El promedio general es: %.2f\n", promedioGeneral);


return 0;

}
