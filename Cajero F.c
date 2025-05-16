#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ATM.h"

int main(void)
{
    Cliente clientes[100] = {
        {1, "Ulises Arreola", 1000.0, 9900},
        {2, "Edwin Barajas", 3000.0, 4779},
        {3, "Juan Gomez", 5400.0, 2015}
    };

    int numClientes = 3;
    int opcionPrincipal, opcion, seguir = 1, cuentaSeleccionada, clienteExiste = 0;

    do
    {
        printf("Bienvenido\n");
        printf("1. Iniciar sesion (cuenta existente)\n");
        printf("2. Crear nueva cuenta\n");
        printf("3. Buscar numero de cuenta por nombre\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcionPrincipal);
        LimpiarPantalla();

        switch (opcionPrincipal)
        {
            case 1:
                printf("Ingresa tu numero de cliente: ");
                scanf("%d", &cuentaSeleccionada);

                for (int i = 0; i < numClientes; i++)
                {
                    if (clientes[i].numClientes == cuentaSeleccionada)
                    {
                        clienteExiste = 1;
                        seguir = PIN(clientes[i].pin);
                        if (seguir)
                        {
                            printf("Has seleccionado la cuenta de %s\n", clientes[i].nombre);
                            break;
                        }
                    }
                }

                if (!clienteExiste)
                {
                    printf("No existe una cuenta con ese numero de cliente.\n");
                    seguir = 0;
                }

                if (seguir) {
                    do
                    {
                        printf("Bienvenido a mi cajero\n\n");
                        printf("1. Consultar saldo\n");
                        printf("2. Depositar dinero\n");
                        printf("3. Retirar dinero\n");
                        printf("4. Cerrar sesion\n\n");
                        printf("Por favor selecciona una opcion\n");
                        scanf("%d", &opcion);
                        LimpiarPantalla();

                        switch (opcion)
                        {
                            case 1:
                                printf("Saldo disponible: %.2f\n", clientes[cuentaSeleccionada - 1].saldo);
                                seguir = ConsultarSaldo(clientes[cuentaSeleccionada - 1].saldo);
                                break;

                            case 2:
                                seguir = Depositardinero(&clientes[cuentaSeleccionada - 1].saldo);
                                break;

                            case 3:
                                seguir = RetirarDinero(&clientes[cuentaSeleccionada - 1].saldo);
                                break;

                            case 4:
                                printf("Sesion cerrada. Regresando al menu principal...\n");
                                seguir = 0;
                                break;

                            default:
                                printf("Opcion no valida. Intenta de nuevo.\n");
                                break;
                        }
                        LimpiarPantalla();
                    } while (seguir != 0);
                }
                break;

            case 2:
                NuevaCuenta(clientes, &numClientes);
                break;

            case 3:
                {
                    char nombre[100];
                    printf("Ingresa el nombre del cliente: ");
                    getchar();
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = '\0';
                    int indice = Buscar(clientes, numClientes, nombre);
                    if (indice == -1) {
                        printf("No se encontro un cliente con ese nombre.\n");
                    } else {
                        printf("El numero de cuenta de %s es: %d\n", clientes[indice].nombre, clientes[indice].numClientes);
                    }
                }
                break;

            case 4:
                printf("Gracias por usar mi cajero\n");
                printf("Que tengas un buen dia\n");
                exit(0);
                break;

            default:
                printf("Opcion no valida. Intenta de nuevo.\n");
                break;
        }

    } while (1);

    return 0;
}
