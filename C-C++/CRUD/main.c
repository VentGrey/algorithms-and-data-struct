// -- Inclusión de cabeceras
#include <stdio.h>
#include <stdlib.h>


// -- Estrucuras
// Es una herejía usar el typedef aquí, pero por cuestiones de tiempo y
// maleabilidad será mejor.
typedef struct{
        int id;
        char latitud[20];
        char longitud[20];
        char tipo[20];
        char fecha[30];
}Alojamiento;

typedef struct{
        int id;
        double precio;
        int calificacion;
        char fecha[30];
}Historico;

// -- Prototipo de menú
void menu();

// -- Prototipos de alojamiento
void AltaAlojs();
void BajaAlojs();
void ModifAlojs();
void ListadoAlojs();

// -- Prototipos de histórico
void AltaHist();
void BajaHist();
void ModifHist();
void ListadoHist();

// -- Función main
int main()
{
        menu();
        return 0;
}

void menu()
{
        int opcion,opcion2;
        do {
                printf("---------------HOSPEDATE--------------\n");
                printf("--------------------------------------\n");
                printf("           1) Alojamientos            \n");
                printf("           2) Histórico               \n");
                printf("           3) Salir                   \n");
                printf("--------------------------------------\n");
                printf("--------------------------------------\n");
                scanf("%d",&opcion);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("---------------HOSPEDATE--------------\n");
                printf("--------------------------------------\n");
                printf("           1) Alta                    \n");
                printf("           2) Baja                    \n");
                printf("           3) Modificación            \n");
                printf("           4) Listado                 \n");
                printf("           5) Volver al Menú          \n");
                printf("--------------------------------------\n");
                printf(" -------------------------------------\n");
                scanf("%d",&opcion2);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n");

                switch (opcion) {
                case 1:
                        switch(opcion2) {
                        case 1:
                                AltaAlojs();
                                break;
                        case 2:
                                BajaAlojs();
                                break;
                        case 3:
                                ModifAlojs();
                                break;
                        case 4:
                                ListadoAlojs();
                                break;
                        case 5:
                                menu();
                                break;
                        }
                        break;
                case 2:
                        switch(opcion2){
                        case 1:
                                AltaHist();
                                break;
                        case 2:
                                BajaHist();
                                break;
                        case 3:
                                ModifHist();
                                break;
                        case 4:
                                ListadoHist();
                                break;
                        case 5:
                                menu();
                                break;
                        }
                        break;
                case 3:
                        break;
                }
        }while (opcion!=5);
}

// ------------ INICIO DE CRUD ALOJAMIENTOS --------------------------

void AltaAlojs()
{
        FILE *pf;
        Alojamiento stay;
        pf = fopen("Alojamientos.dat","ab");

        printf("Ingrese el id del alojamiento\n");
        scanf("%i" ,&stay.id);

        printf("Ingrese la latitud del lugar\n");
        scanf("%s", &stay.latitud);

        printf("Ingrese la longitud\n");
        scanf("%s", &stay.longitud);

        printf("Ingrese el tipo de alojamiento\
 (Casa, Departamento, Cuarto, etc)\n");
        scanf("%s", &stay.tipo);

        printf("Ingrese la fecha en la que el alojamiento será realizado\n");
        scanf("%s", &stay.fecha);

        fseek(pf, 0L, SEEK_END);
        fwrite(&stay, sizeof(Alojamiento), 1, pf);
        fclose(pf);
        // -- Imprimir vergos de newlines para "simular" un clearscreen;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        menu();
}

void ListadoAlojs()
{
        FILE *pf;
        Alojamiento stay;
        pf = fopen("Alojamientos.dat","rb");
        fread(&stay, sizeof(Alojamiento), 1, pf);
        while (!feof(pf)) {
                printf("%i ; %s ; %s ; %s ; %s\n",stay.id,stay.latitud,
                       stay.longitud,stay.tipo,stay.fecha);
                fread(&stay, sizeof(Alojamiento), 1, pf);
        }
        fclose(pf);
}

void ModifAlojs()
{
        FILE *pf,*pfaux;
        Alojamiento stay;
        int codigoaux;

        pf = fopen("Alojamientos.dat","rb");
        pfaux = fopen("Alojamientosaux.dat","ab");

        printf("Ingrese Código\n");
        scanf("%i",&codigoaux);
        fread(&stay, sizeof(Alojamiento), 1, pf);

        while (!feof(pf)) {
                if (stay.id != codigoaux) {
                        fseek(pfaux,0l,SEEK_END);
                        fwrite(&stay,sizeof(Alojamiento),1,pfaux);
                } else {
                        printf("Ingrese la latitud\n");
                        scanf("%s",stay.latitud);
                        printf("Ingrese la longitud\n");
                        scanf("%s",&stay.longitud);
                        printf("Ingrese el tipo\n");
                        scanf("%s",&stay.tipo);
                        printf("Ingrese la fecha\n");
                        scanf("%s",stay.fecha);
                        fseek(pfaux, 0l, SEEK_END);
                        fwrite(&stay, sizeof(Alojamiento), 1, pfaux);
                }
                fread(&stay,sizeof(Alojamiento),1,pf);
        }
        fclose(pf);
        fclose(pfaux);
        remove("Alojamientos.dat");
        rename("Alojamientosaux.dat","Alojamientos.dat");
}

void BajaAlojs()
{
        FILE *pf,*pfaux;
        Alojamiento stay;
        int codigoaux;

        pf = fopen("Alojamientos.dat","rb");
        pfaux = fopen("Alojamientosaux.dat","ab");

        printf("Ingrese el ID a buscar\n");
        scanf("%i",&codigoaux);

        fread(&stay, sizeof(Alojamiento), 1, pf);
        while (!feof(pf)) {
                if (stay.id != codigoaux) {
                        fseek(pfaux, 0l, SEEK_END);
                        fwrite(&stay, sizeof(Alojamiento), 1, pfaux);
                }
                fread(&stay,sizeof(Alojamiento),1,pf);
        }

        fclose(pf);
        fclose(pfaux);
        remove("Alojamientos.dat");
        rename("Alojamientosaux.dat","Alojamientos.dat");
}

// ------------ FIN DE CRUD ALOJAMIENTOS --------------------------


// ------------ INICIO DE CRUD HISTÓRICO --------------------------
void AltaHist()
{
        FILE *pf;
        Historico hist;

        pf = fopen("historico.dat","ab");

        printf("Ingrese el id del historico\n");
        scanf("%i" ,&hist.id);

        printf("Ingrese el precio de la estancia\n");
        scanf("%lf", &hist.precio);

        printf("Ingrese la calificación del lugar (1 - 5)\n");
        scanf("%i", &hist.calificacion);

        // Revisar que el usuario no se salga de la calificación
        if (hist.calificacion > 5 || hist.calificacion <= 0) {
                printf("La calificación ingresada es errónea");
                return;
        }

        printf("Ingrese la fecha en la que el alojamiento fue realizado\n");
        scanf("%s", &hist.fecha);

        fseek(pf, 0L, SEEK_END);
        fwrite(&hist, sizeof(Historico), 1, pf);
        fclose(pf);
        // -- Imprimir vergos de newlines para "simular" un clearscreen;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        menu();
}

void ListadoHist()
{
        FILE *pf;
        Historico hist;

        pf = fopen("Alojamientos.dat","rb");
        fread(&hist, sizeof(Historico), 1, pf);

        while (!feof(pf)) {
                printf("%i ; %lf ; %i ; %s ;\n",hist.id, hist.precio,
                       hist.calificacion,  hist.fecha);
                fread(&hist,sizeof(Historico), 1, pf);
        }
        fclose(pf);
}

void ModifHist()
{
        FILE *pf,*pfaux;
        Historico hist;
        int codigoaux;

        pf = fopen("Alojamientos.dat","rb");
        pfaux = fopen("Alojamientosaux.dat","ab");

        printf("Ingrese Código\n");
        scanf("%i",&codigoaux);
        fread(&hist, sizeof(Historico), 1, pf);

        while (!feof(pf)) {
                if (hist.id != codigoaux) {
                        fseek(pfaux, 0l, SEEK_END);
                        fwrite(&hist, sizeof(Historico), 1, pfaux);
                } else {
                        printf("Ingrese el precio\n");
                        scanf("%lf",&hist.precio);
                        printf("Ingrese la calificacion del alojamiento\n");
                        scanf("%i",&hist.calificacion);
                        printf("Ingrese la fecha\n");
                        scanf("%s",&hist.fecha);
                        fseek(pfaux,0l,SEEK_END);
                        fwrite(&hist,sizeof(Historico),1,pfaux);
                }
                fread(&hist,sizeof(Historico),1,pf);
        }
        fclose(pf);
        fclose(pfaux);
        remove("Historicos.dat");
        rename("Historicosaux.dat","Historicos.dat");
}

void BajaHist()
{
        FILE *pf,*pfaux;
        Historico hist;
        int codigoaux;

        pf = fopen("Historicos.dat","rb");
        pfaux = fopen("Historicosaux.dat","ab");

        printf("Ingrese el ID a buscar\n");
        scanf("%i",&codigoaux);

        fread(&hist, sizeof(Historico), 1, pf);
        while (!feof(pf)) {
                if (hist.id != codigoaux) {
                        fseek(pfaux, 0l, SEEK_END);
                        fwrite(&hist, sizeof(Historico), 1, pfaux);
                }
                fread(&hist,sizeof(Historico),1,pf);
        }
        fclose(pf);
        fclose(pfaux);
        remove("Historicos.dat");
        rename("Historicosaux.dat","HIstoricos.dat");
}

// ------------ FIN DE CRUD HISTÓRICO --------------------------
