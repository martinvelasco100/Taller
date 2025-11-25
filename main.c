#include <stdio.h>
#include "inventario.h"

int main() {
   
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int cantidad = 0;
    int opcion;
    
    printf("╔════════════════════════════════════════╗\n");
    printf("║  SISTEMA DE GESTIÓN DE INVENTARIO     ║\n");
    printf("╚════════════════════════════════════════╝\n");
    
    do {
        printf("\n┌──────────────────────────────────────┐\n");
        printf("│           MENÚ PRINCIPAL             │\n");
        printf("├──────────────────────────────────────┤\n");
        printf("│ 1. Ingresar productos                │\n");
        printf("│ 2. Mostrar inventario completo       │\n");
        printf("│ 3. Calcular precio total             │\n");
        printf("│ 4. Encontrar producto más caro       │\n");
        printf("│ 5. Encontrar producto más barato     │\n");
        printf("│ 6. Calcular precio promedio          │\n");
        printf("│ 7. Buscar producto por nombre        │\n");
        printf("│ 0. Salir                             │\n");
        printf("└──────────────────────────────────────┘\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                ingresarProductos(nombres, precios, &cantidad);
                break;
                
            case 2:
                mostrarInventario(nombres, precios, cantidad);
                break;
                
            case 3: {
                if (cantidad == 0) {
                    printf("\nNo hay productos en el inventario.\n");
                } else {
                    float total = calcularPrecioTotal(precios, cantidad);
                    printf("\n💰 PRECIO TOTAL DEL INVENTARIO: $%.2f\n", total);
                }
                break;
            }
            
            case 4: {
                int indice = encontrarMasCaro(precios, cantidad);
                if (indice == -1) {
                    printf("\nNo hay productos en el inventario.\n");
                } else {
                    printf("\n🔝 PRODUCTO MÁS CARO:\n");
                    printf("   Nombre: %s\n", nombres[indice]);
                    printf("   Precio: $%.2f\n", precios[indice]);
                }
                break;
            }
            
            case 5: {
                int indice = encontrarMasBarato(precios, cantidad);
                if (indice == -1) {
                    printf("\nNo hay productos en el inventario.\n");
                } else {
                    printf("\n PRODUCTO MÁS BARATO:\n");
                    printf("   Nombre: %s\n", nombres[indice]);
                    printf("   Precio: $%.2f\n", precios[indice]);
                }
                break;
            }
            
            case 6: {
                if (cantidad == 0) {
                    printf("\nNo hay productos en el inventario.\n");
                } else {
                    float promedio = calcularPromedio(precios, cantidad);
                    printf("\n PRECIO PROMEDIO: $%.2f\n", promedio);
                }
                break;
            }
            
            case 7: {
                if (cantidad == 0) {
                    printf("\nNo hay productos en el inventario.\n");
                } else {
                    char nombreBuscar[MAX_NOMBRE];
                    printf("\nIngrese el nombre del producto a buscar: ");
                    scanf(" %[^\n]", nombreBuscar);
                    
                    int indice = buscarProducto(nombres, cantidad, nombreBuscar);
                    
                    if (indice == -1) {
                        printf("\n Producto no encontrado.\n");
                    } else {
                        printf("\n PRODUCTO ENCONTRADO:\n");
                        printf("   Nombre: %s\n", nombres[indice]);
                        printf("   Precio: $%.2f\n", precios[indice]);
                    }
                }
                break;
            }
            
            case 0:
                printf("\n¡Gracias por usar el sistema de inventario!\n");
                printf("Hasta luego. \n\n");
                break;
                
            default:
                printf("\n Opción inválida. Intente nuevamente.\n");
        }
        
    } while(opcion != 0);
    
    return 0;
}
