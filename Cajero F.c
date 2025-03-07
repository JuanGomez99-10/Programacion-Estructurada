#include <stdio.h>
#include <stdlib.h>
#include "ATM.h"

int main(void)
{
    float saldos[3] = {1000, 3000, 5400};  // Saldo de 3 cuentas
    int opcion, seguir = 1, cuentaSeleccionada;

    // Seleccion de ceuntas
    SeleccionarCuenta(&cuentaSeleccionada);
    printf("Has seleccionado la cuenta %d\n", cuentaSeleccionada);

    do
    {
        // Menú de opciones
        printf("Bienvenido al cajero del Juan\n\n");
        printf("1. Consultar Saldo\n");
        printf("2. Depositar dinero\n");
        printf("3. Retirar Dinero\n");
        printf("4. Salir\n\n");
        printf("Porfavor selecciona una opcion\n");
        scanf("%d", &opcion);

        LimpiarPantalla();

        switch (opcion)
        {
            case 1:  // Consulta de saldo
                seguir = PIN();
                seguir = ConsultarSaldo(saldos[cuentaSeleccionada - 1]);
                LimpiarPantalla();
                break;

            case 2:  // Depositar dinero
                seguir = PIN();
                seguir = Depositardinero(&saldos[cuentaSeleccionada - 1]);
                LimpiarPantalla();
                break;

            case 3:  // Retirar dinero
                seguir = PIN();
                seguir = RetirarDinero(&saldos[cuentaSeleccionada - 1]);
                LimpiarPantalla();
                break;

            case 4:  // Salir
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
