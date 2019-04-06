//Programa del UMDA enfocado al OneMax.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float onemax();
//--------------------------------------------------------------------
static int comp(const void* p1, const void* p2)
{
  int * arr1 = (int *)p1;
  int * arr2 = (int *)p2;
  int diff1 = arr1[0] - arr2[0];
  return diff1;
}
//--------------------------------------------------------------------
int main()
{
    srand(time(NULL));
    int M, N, gen, mues;

    printf("Introduzca el número de individuos de la población: \n");
    scanf("%d", &M);
    printf("Introduzca el tamaño de cada individuo: \n");
    scanf("%d", &N);

    printf("\n");

    int P = N + 1;
    int ppl[M][P];

    //Establecer matriz y casilla para el fitness.
    for (int i = 0; i < M; i ++)
    {
        ppl[i][0] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 1; j < P; j++)
        {
            if (onemax() < (0.5))
            {
                ppl[i][j] = 1;
            }
            else
            {
                ppl[i][j] = 0;
            }
        }
    }

    //Establecer el puntero para ppl.
    int *ptr;
    ptr = &ppl[0][0];

    for (int i = 0; i < M; i++)
    {
        for (int j = 1; j < P; j++)
        {
            printf("%d ", *(ptr + i*(P) + j));
        }
        printf("\n");
    }

    printf("\n");

    int sum[M]; //Ésta parte es para sacar el fitness. :3

    for (int i = 0; i < M; i ++)
        {
            sum[i] = 0;
        }

    for (int i = 0; i < M; i++)
        {
            for (int j = 1; j < P; j ++)
            {
                sum[i] += ppl[i][j];
            }
        }

    for (int i = 0; i < M; i ++) //Se asigna el fitness a la primera casilla.
    {
        ppl[i][0] = sum[i]; //Aquí. ---^
    } 
     for (int i = 0; i < M; i++)
    {
        printf("%d  ", ppl[i][0]); //Imprimir 
        for (int j = 1; j < P; j++)//Los valores de 
        {
            printf("%d ", ppl[i][j]);//La matriz 
        }
        printf("\n");//Con el fitness al lado. 
    } 
    printf("\n"); 
    
    
    //----------------Ordenar------------------------------
    /*Ordenar*/ qsort(ppl, M, ((N + 1)*(sizeof(int))), comp); /*Ordenar. */

    for (int i = 0; i < M; i++)
    {
        for (int j = 1; j < P; j++)//Imprimir
        {
            printf("%d ", ppl[i][j]);//Ordenamiento. 
        }
        printf("\n");
    }
    

    //------------------Establecer Generciones y muestreo----------------
    printf("Introduzca el número de las generaciones que quiere. \n");
    scanf("%d", &gen);
    printf("Introduzca número de individuos para muestreo: ");
    scanf("%d", &mues);


    //int vec; 
    //El vecsum es un pseudo-valor del vector probabilidad.
    //musa es el valor de vecsum. 
    //El vecprob es el vector probabilidad. 
    //hllysht es el valor que va en el vector probabilidad. 
    float vecsum[P], musa = 0, hllysht = 0, vecprob[P];   
    for (int k = 0; k < gen; k ++ ) //For para sacar generaciones. 
    {
        //-----------------Nuevo Proceso-------------------:3 
        for (int c = 0; c < mues; c ++) 
        {
            //-------Nuevo 'for' para el muestreo-----------
            for (int i = (M - (mues + 1)); i < M; i ++)
            {
                for (int j = 0; j < P; j ++) 
                {
                    if ((i == (M - (mues + 1)))||(j == 0)) 
                    {
                        //Declarar los valores de [0][0] y [0][1] == 0. 
                        musa = 0; 
                        vecsum[j] = musa; 
                    }
                    else 
                    {
                        //Declara los demás valores con la suma de las columnas. 
                        musa = ppl[i][j]; 
                        vecsum[j] += musa; 
                    }
                }
            }
        } 
        
        for (int j = 0; j < P; j ++) 
        {
            hllysht = (vecsum[j] / (float)mues); 
            vecprob[j] = hllysht; 
        }
        
        //Imprimir el vecsum. 
        /*for (int j = 1; j < P; j ++) 
        {
            printf("%.2f  ", vecprob[j]); 
        }*/
        
        /*for (int i = 0; i < M; i ++) 
        {
            for (int j = 0; i < N; j ++) 
            {
                if (onemax() < vecprob[j]) 
                {
                    ppl[i][j] = 0; 
                }
                else 
                {
                    ppl[i][j] = 1; 
                }
            }
        }*/
        
        /*printf("\n"); 
        printf("Matriz antigua. \n"); 
        
        //Para imprimir la matriz chafa. 
        for (int i = 0; i < M; i ++) 
        { 
            for (int j = 0; j < P; j ++) 
            {
                if (j == 0)
                {
                    printf("0  \t");
                } 
                else 
                {
                    printf("%d  ", ppl[i][j]); 
                }
            }
            printf("\n"); 
        }*/
        
        printf("\n"); 
        printf("Nueva Matriz \n"); 
        //Para generar la nueva población. 
        printf("Matriz %d \n", (k + 1)); 
        for (int i = 0; i < M; i ++) 
        {
            for (int j = 1; j < P; j ++) 
            {
                if (onemax() < vecprob[j]) 
                {
                    ppl[i][j] = 1; 
                } 
                else 
                {
                    ppl[i][j] = 0; 
                }
            }
        } 
        
        //Imprimir la nueva matriz. 
        for (int i = 0; i < M; i ++) 
        {
            for (int j = 1; j < P; j ++) 
            {
                printf("%d  ", ppl[i][j]); 
            }
            printf("\n"); 
        } 
        
        printf("\n"); 
        
        
        //------------------------No sé------------------------
        /*float vp[M - (mues + 1)][P], vec[P];

        for (int i = 0; i < M; i ++) 
        {
            vec[i] = 0;
        }

        for (int i = ((M - mues) - 1); i < M ; i ++)
        {
            for (int j = 1; j < P; j++) 
            {
                vec[j - 1] += ppl[j][i]; 
                //vp[i][j] = (vec[j]/(float)mues);
            }
        }//Lo que sigue es para imprimir la matriz resultante de hace rato. 
        /*for (int i = (M - 1); i > (M - mues - 1); i --)
        {
            //for (int j = 0; j < N; j++) 
            //{
                printf("%d", vec[i]);
            //}
            printf("\n");
        }*/

        //for (int i = 0; i < M; i ++)
        //{
            //vp[i] = (vec[i]/mues);
        //}//Lo que sigue es para imprimir lo de hace rato. Por favor, que salga. :'v 
        /*for (int i = (M - 1); i > (M - mues - 1); i --)
        {
            for (int j = 1; j < P; j++) 
            {
                printf("%.2f  |", vec[j]);
            }
            printf("\n");
        }

        //for (int i = 0; i < M; i ++)
        //{
            //for (int j = 0; j < N; j ++)
            //{
                //if (onemax() < vp[i])
                //{
                    //ppl[i][j] = 1;
                //}
                //else
                //{
                    //ppl[i][j] = 0;
                //}
            //}
        //}

        printf("Generación %d \n", (k + 1));---------------------------
        for (int i = 0; i < M; i ++)
        {
            for (int j = 0; j < N; j ++)
            {
                printf("%d", ppl[i][j]);
            }
            printf("\n");
        } 
        printf("\n");*/ 
        printf("\n"); 
    } 
}
//----------------------------------------------------------------------
float onemax()
{
    return (float)rand()/(float)RAND_MAX;
}






