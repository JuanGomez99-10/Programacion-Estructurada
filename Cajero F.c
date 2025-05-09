#include <stdio.h>
#include <stdlib.h>
#include "ATM.h"

int main(void)
{
    Cliente clientes[100] = {
    {0001,"Ulises Arreola", 1000.0, 9900},
    {0002,"Edwin Barajas", 3000.0, 4779},
    {0003,"Juan Gomez", 5400.0, 2015}
};

    int opcion, seguir = 1, cuentaSeleccionada;

    // Seleccion de ceuntas
    SeleccionarCuenta(&cuentaSeleccionada);
    printf("Has seleccionado la cuenta %d\n", cuentaSeleccionada);
    printf("Titular de la cuenta: %s\n\n", clientes[cuentaSeleccionada - 1].nombre);
    do
    {
        // Menú de opciones
        printf("Bienvenido a mi cajero\n\n");
        printf("1. Consultar Saldo\n");
        printf("2. Depositar dinero\n");
        printf("3. Retirar Dinero\n");
        printf("4. Crear Nueva Cuenta\n");
        printf("5. Salir\n\n");
        printf("Porfavor selecciona una opcion\n");
        scanf("%d", &opcion);

        LimpiarPantalla();

        switch (opcion)
        {
            case 1:  // Consulta de saldo
                seguir = PIN(clientes[cuentaSeleccionada - 1].pin);
                seguir = ConsultarSaldo(clientes[cuentaSeleccionada - 1].saldo);
                LimpiarPantalla();
                break;

            case 2:  // Depositar dinero
                seguir = PIN(clientes[cuentaSeleccionada - 1].pin);
                seguir = Depositardinero(&clientes[cuentaSeleccionada - 1].saldo);
                LimpiarPantalla();
                break;

            case 3:  // Retirar dinero
                seguir = PIN(clientes[cuentaSeleccionada - 1].pin);
                seguir = RetirarDinero(&clientes[cuentaSeleccionada - 1].saldo);
                LimpiarPantalla();
                break;

            case 4:  // Nueva Cuenta
                printf("Crear Cuenta\n");
                NuevaCuenta(clientes, &numClientes);
                LimpiarPantalla();
                break;

            case 5:  // Salir
                printf("Gracias por usar mi cajero\n");
                printf("Que tengas un buen dia\n");
                seguir = 0;
                LimpiarPantalla();
                break;

            default: // Ingresa número o caracter inválido
                printf("Acción no disponible\n");
                printf("Por favor selecciona una válida\n");
                seguir = 1;
                LimpiarPantalla();
                break;
        }
    } while (seguir != 0);

    return 0;
}
