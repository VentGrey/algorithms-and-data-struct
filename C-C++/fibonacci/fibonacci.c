#include<stdio.h>

void fibonacci(int a, int b, int n);

int main(int argc, char *argv[])
{
        fibonacci(20, 20, 20);
        return 0;
}

void fibonacci(int a, int b, int n) {
        if (n < 1) {
                printf("%d", a);
                return;
        }

        fibonacci(b, a + b, n - 1);
}
