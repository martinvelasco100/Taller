#ifndef INVENTARIO_H
#define INVENTARIO_H

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

void ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int *cantidad);

float calcularPrecioTotal(float precios[], int cantidad);

int encontrarMasCaro(float precios[], int cantidad);

int encontrarMasBarato(float precios[], int cantidad);

float calcularPromedio(float precios[], int cantidad);

int buscarProducto(char nombres[][MAX_NOMBRE], int cantidad, char nombreBuscado[]);

void mostrarInventario(char nombres[][MAX_NOMBRE], float precios[], int cantidad);

void ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int *cantidad) {
    int n;
    printf("\n=== INGRESO DE PRODUCTOS ===\n");
    printf("¿Cuántos productos desea ingresar? (máximo %d): ", MAX_PRODUCTOS);
    scanf("%d", &n);
    
    if (n < 1 || n > MAX_PRODUCTOS) {
        printf("Cantidad inválida. Se ingresarán 0 productos.\n");
        *cantidad = 0;
        return;
    }
    
    *cantidad = n;
    
    for (int i = 0; i < n; i++) {
        printf("\nProducto %d:\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", nombres[i]);
        
        printf("Precio: $");
        scanf("%f", &precios[i]);
        
        while (precios[i] < 0) {
            printf("El precio no puede ser negativo. Ingrese nuevamente: $");
            scanf("%f", &precios[i]);
        }
    }
    
    printf("\n¡Productos ingresados correctamente!\n");
}

float calcularPrecioTotal(float precios[], int cantidad) {
    float total = 0.0;
    
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    
    return total;
}

int encontrarMasCaro(float precios[], int cantidad) {
    if (cantidad == 0) return -1;
    
    int indiceMasCaro = 0;
    
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[indiceMasCaro]) {
            indiceMasCaro = i;
        }
    }
    
    return indiceMasCaro;
}

int encontrarMasBarato(float precios[], int cantidad) {
    if (cantidad == 0) return -1;
    
    int indiceMasBarato = 0;
    
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < precios[indiceMasBarato]) {
            indiceMasBarato = i;
        }
    }
    
    return indiceMasBarato;
}

float calcularPromedio(float precios[], int cantidad) {
    if (cantidad == 0) return 0.0;
    
    float total = calcularPrecioTotal(precios, cantidad);
    return total / cantidad;
}

int buscarProducto(char nombres[][MAX_NOMBRE], int cantidad, char nombreBuscado[]) {
    for (int i = 0; i < cantidad; i++) {

        int j = 0, iguales = 1;
        
        while (nombres[i][j] != '\0' || nombreBuscado[j] != '\0') {
            if (nombres[i][j] != nombreBuscado[j]) {
                iguales = 0;
                break;
            }
            j++;
        }
        
        if (iguales) {
            return i;
        }
    }
    
    return -1; 

void mostrarInventario(char nombres[][MAX_NOMBRE], float precios[], int cantidad) {
    if (cantidad == 0) {
        printf("\nEl inventario está vacío.\n");
        return;
    }
    
    printf("\n=== INVENTARIO COMPLETO ===\n");
    printf("%-5s %-30s %s\n", "No.", "Producto", "Precio");
    printf("-------------------------------------------\n");
    
    for (int i = 0; i < cantidad; i++) {
        printf("%-5d %-30s $%.2f\n", i + 1, nombres[i], precios[i]);
    }
}

#endif