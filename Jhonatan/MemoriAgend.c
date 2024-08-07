#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int id;
    char nombre[10];
    char telefono[10];
}Contacto;

void AgregarContacto(Contacto *agenda ,int index){
    printf("ingresa tu Id ");
    scanf("%d",&agenda[index].id);
    printf("ingresa tu nombre: ");
    scanf("%s",agenda[index].nombre);
    printf("ingrese su telefono: ");
    scanf("%s",&agenda[index].telefono);
}

void mostrarContacto(Contacto contacto) {
    printf("ID: %d, Nombre: %s, Teléfono: %s\n", contacto.id, contacto.nombre, contacto.telefono);
}

void mostrarAgenda(Contacto *agenda, int numContactos) {
    printf("\nContactos ingresados:\n");
    for (int i = 0; i < numContactos; i++) {
        mostrarContacto(agenda[i]);
    }
}


int main(){
    int numContactos;
    printf("cuantos contactos quieres guardar: ");
    scanf("%d",&numContactos);

     Contacto *agenda = (Contacto *)malloc(numContactos * sizeof(Contacto));

     for (int i = 0; i < numContactos; i++) {
        printf("\nContacto %d:\n", i + 1);
        AgregarContacto(agenda, i);
    }
    mostrarAgenda(agenda, numContactos);
    free(agenda);
    return 0;    
}


