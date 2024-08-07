/*realizar un programa que permita organizar una discografia, en donde se incluyan los datos 
del autor(nombre, fecha de nacimiento, origen) datos de la cancion(edicion, TITULO y album)
el programa debe permitir mostrar un menu que introduzca datos de autor y datos de cancion,
asi como mostrar los datos ingresados por autor y por cancion*/

#include <stdio.h>
#include <string.h>
#define MAX_AUTORES 10
#define MAX_CANCIONES 10
typedef struct {
    char nombre[20];
    char fecha_nacimiento[11];
    char origen[20];
} Autor;

typedef struct {
    char titulo[20];
    char album[20];
    char edicion[20];
    Autor autor;
} Cancion;

Autor autores[MAX_AUTORES];
Cancion canciones[MAX_CANCIONES];

int numero_autores = 0;
int numero_canciones = 0;

void agregarAutor();
void agregarCancion();
void buscarAutor();
void buscarCancion();

int main() {

    int opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Agregar Autor\n");
        printf("2. Agregar Cancion\n");
        printf("3. Buscar Autores\n");
        printf("4. Bucar Canciones\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                agregarAutor();
                break;
            case 2:
                agregarCancion();
                break;
            case 3:
                buscarAutor();
                break;
            case 4:
                buscarCancion();
                break;
            case 5:
                printf("Usted esta saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 5);
    return 0;
}
void agregarAutor() {
    if (numero_autores < MAX_AUTORES) {
        printf("Ingrese el nombre del autor: ");
        scanf(" %[^\n]", autores[numero_autores].nombre);
        printf("Ingrese la fecha de nacimiento [DD/MM/AAAA]: ");
        scanf(" %[^\n]", autores[numero_autores].fecha_nacimiento);
        printf("Ingrese el origen del autor: ");
        scanf(" %[^\n]", autores[numero_autores].origen);
        numero_autores++;
        printf("Autor agregado con exito.\n");
    } else {
        printf("Limite de autores alcanzado.\n");
    }
}
void agregarCancion() {
    if (numero_canciones < MAX_CANCIONES) {
        printf("Ingrese el titulo de la cancion: ");
        scanf(" %[^\n]", canciones[numero_canciones].titulo);
        printf("Ingrese el album: ");
        scanf(" %[^\n]", canciones[numero_canciones].album);
        printf("Ingrese la edicion: ");
        scanf(" %[^\n]", canciones[numero_canciones].edicion);

        printf("Seleccione el autor (0 a %d):\n", numero_autores - 1);
        for (int i = 0; i < numero_autores; i++) {
            printf("%d: %s\n", i, autores[i].nombre);
        }
        int autor_index;
        scanf("%d", &autor_index);
        if (autor_index >= 0 && autor_index < numero_autores) {
            canciones[numero_canciones].autor = autores[autor_index];
            numero_canciones++;
            printf("Cancion agregada con exito.\n");
        } else {
            printf("Indice de autor invalido.\n");
        }
    } else {
        printf("Limite de canciones alcanzado.\n");
    }
}
void buscarAutor() {
    char nombre[100];
    printf("Ingrese el nombre del autor a buscar: ");
    scanf(" %[^\n]", nombre);

    int encontrado = 0;
    for (int i = 0; i < numero_autores; i++) {
        if (strcmp(autores[i].nombre, nombre) == 0) {
            printf("Autor encontrado: Nombre: %s, Fecha de Nacimiento: %s, Origen: %s\n",
            autores[i].nombre, autores[i].fecha_nacimiento, autores[i].origen);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Autor no encontrado.\n");
    }
}
void buscarCancion() {
    char titulo[100];
    printf("Ingrese el titulo de la cancion a buscar: ");
    scanf(" %[^\n]", titulo);

    int encontrado = 0;
    for (int i = 0; i < numero_canciones; i++) {
        if (strcmp(canciones[i].titulo, titulo) == 0) {
            printf("Cancion encontrada: Titulo: %s, Album: %s, Edicion: %s, Autor: %s\n",
            canciones[i].titulo, canciones[i].album, canciones[i].edicion,
            canciones[i].autor.nombre);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Cancion no encontrada.\n");
    }
}
