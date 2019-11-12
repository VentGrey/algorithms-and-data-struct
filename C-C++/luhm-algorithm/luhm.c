/* A program for Luhm algorithm or mod 10 algorithm
   instead of strings uses only numbers and also is very inefficient */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 16

int main () {

        unsigned long credit_card;
        int split_cc[N], odd = 0, even = 0;

        printf("Enter a credit card number: ");
        if ( scanf("%lu", &credit_card) != 0 ) {
                if ( floor(log10(credit_card) + 1) == 16 ) {
                        int i = (N - 1);
                        while (credit_card > 0) {
                                split_cc[i] = credit_card % 10;
                                credit_card /= 10;

                                i--;
                        }
                        for (int j = 0; j < N; j++) {
                                if (j % 2 == 0) {
                                        split_cc[j] = split_cc[j] * 2;
                                        if (split_cc[j] > 9)
                                                split_cc[j] = split_cc[j] - 9;

                                        odd = odd + split_cc[j];

                                } 
                                else
                                        even = even + split_cc[j];
                        }

                        int sum = odd + even;
                        printf("The credit card is: %s\n", ((sum % 10 == 0) ? "ok" : "not ok"));
                }
                else {
                        fprintf(stderr, "Invalid credit card size.\n");
                        return (EXIT_FAILURE);
                }
        }
        else {
                fprintf(stderr, "Error invalid credit card number.\n");\
                return (EXIT_FAILURE);
        }

        return 0;
}