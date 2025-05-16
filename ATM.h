#ifndef ATM_H_INCLUDED
#define ATM_H_INCLUDED

typedef struct {
    int  numClientes;
    char nombre[50];
    float saldo;
    int pin;
} Cliente;

// Funcion para verificar la cantidad ingresada
int verificacion(float X)
{
    if (X > 0) // Cantidades válidas o positivas
    {
        return 1;
    }
    else if (X == 0) // Cantidad invalida (0)
    {
        printf("ERROR\n");
        printf("La cantidad es 0.\n");
        return 0;
    }
    else // Cantidad invalida (Negativa)
    {
        printf("ERROR: La cantidad ingresada es NEGATIVA \n");
        printf("Ingresa un numero POSITIVO");
        return 0;
    }
}

// Funcion para preguntar si quiere hacer otra operacion o salir
int OtraOperacion(void)
{
    int opcion;
    printf("Hay algo mas que podamos hacer por ti?\n");
    printf("1. Si, volver al menu\n");
    printf("2. No, salir.\n");
    scanf("%d", &opcion);
    switch (opcion)
    {
        case 1:
            return 1;
        case 2:
            printf("Gracias por usar mi cajero\n");
            printf("Que tengas un buen dia\n");
            return 0;
        default: // Ingresa número o caracter invalido
            printf("Acción no disponible\n");
            printf("Por favor selecciona una válida\n");
            return OtraOperacion();
    }
}

// Funcion Del Pin para ingresar
int PIN(int pinCorrecto)
{
    int pinIngresado;

    for (int intento = 0; intento < 3; intento++)
    {
        printf("Para continuar, ingresa tu PIN:\n");
        scanf("%d", &pinIngresado);

        if (pinIngresado == pinCorrecto)
        {
            printf("Bienvenido\n");
            return 1;
        }
        else
        {
            printf("Error, el PIN ingresado es incorrecto.\n");
            printf("Intentos restantes: %d\n", 2 - intento);
        }
    }

    printf("Has superado el límite de intentos\n");
    exit(0);
}

// Funcion para limpiar pantalla
void LimpiarPantalla(void)
{
    #ifdef _WIN32
        system("cls");  // Para Windows
    #else
        system("clear");  // Para Linux y macOS
    #endif
}



// Funcion para mostrar el menú de selección de cuentas
int SeleccionarCuenta(int *opcionCuenta)
{
    printf("Selecciona una cuenta (1-3):\n");
    printf("1. Ulises Arreola\n");
    printf("2. Edwin Barajas\n");
    printf("3. Juan Gomez\n");
    scanf("%d", opcionCuenta);

    if (*opcionCuenta < 1 || *opcionCuenta > 3)
    {
        printf("Opción no válida. Por favor selecciona una cuenta entre 1 y 3.\n");
        return SeleccionarCuenta(opcionCuenta);
    }

    return 0;
}

// Funcion Consulta de saldo
int ConsultarSaldo(float saldo)
{
    printf("El saldo de tu cuenta es: $ %.2f\n", saldo);
    return OtraOperacion();
}

// Depositar dinero
int Depositardinero(float *saldo)
{
    float cantidad;
    int v;

    printf("Ingresa el monto que deseas depositar: $");
    scanf("%f", &cantidad);

    v = verificacion(cantidad);

    while (v != 1)
    {
        scanf("%f", &cantidad);
        v = verificacion(cantidad);
    }

    *saldo = *saldo + cantidad;
    printf("Su nuevo saldo es: $ %.2f\n", *saldo);

    return OtraOperacion();
}

// Retirar Dinero
int RetirarDinero(float *saldo)
{
    float cantidad;
    int v;

    printf("Ingresa el monto que deseas retirar: $");
    scanf("%f", &cantidad);

    v = verificacion(cantidad);

    while (v != 1 || cantidad > *saldo)
    {
        if (cantidad <= 0)
        {
            printf("La cantidad debe ser mayor a 0. Intenta de nuevo: $");
        }
        else if (cantidad > *saldo)
        {
            printf("No puedes retirar un monto mayor al de tu saldo\n");
            printf("Tu saldo actual es: $%.2f\n", *saldo);
            printf("Intenta de nuevo\n");
        }

        scanf("%f", &cantidad);
        v = verificacion(cantidad);
    }

    *saldo = *saldo - cantidad;
    printf("Retiro realizado con EXITO\n");
    printf("Su nuevo saldo es: $ %.2f\n", *saldo);
    return OtraOperacion();
}

//Buscar Cuenta
int Buscar(Cliente clientes[], int numClientes, const char *nombreBuscado) {
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].nombre, nombreBuscado) == 0) {
            return i;
        }
    }
    return -1;
}

//Crear Cuenta
int NuevaCuenta(Cliente clientes[], int *numClientes)
{
    if (*numClientes >= 100)
    {
        printf("Se ha alcanzado el limite de clientes (100).\n");
        return 0;
    }

    char nombre[50];
    int pin, confPin;
    float deposito;

    printf("Bienvenido\n\n");

    printf("Ingresa Nombre y Apellido:\n");
    getchar(); // Limpiar buffer
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar salto de línea

    do {
        printf("Crea un NIP de 4 digitos: ");
        scanf("%d", &pin);

        printf("Confirmar NIP: ");
        scanf("%d", &confPin);

        if (pin != confPin) {
            printf("Los NIPs no coinciden. Intenta de nuevo.\n");
        }
    } while (pin != confPin);

    do {
        printf("Por favor, para continuar deposita al menos $300: ");
        scanf("%f", &deposito);
        if (deposito < 300.0) {
            printf("El deposito minimo es $300. Intenta de nuevo.\n");
        }
    } while (deposito < 300.0);

    // Registrar cliente en el arreglo
    clientes[*numClientes].numClientes = *numClientes + 1;
    strcpy(clientes[*numClientes].nombre, nombre);
    clientes[*numClientes].pin = pin;
    clientes[*numClientes].saldo = deposito;

    printf("\nCuenta creada con exito.\n");
    printf("Bienvenido, %s!\n", nombre);
    printf("Tu numero de cuenta es: %03d\n", clientes[*numClientes].numClientes);

    (*numClientes)++; // Incrementar contador de clientes

    return OtraOperacion(); // Preguntar si quiere hacer otra operación
}


#endif // ATM_H_INCLUDED
