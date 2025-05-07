#include <stdio.h>
#include <stdbool.h>

bool esPrimo(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void encontrarTerminosFibonacci(int K)
{
    //Arreglo para almacenar secuencia Fibonacci filtrada
    long long fib[100] = {0, 1, 1};
    int pos = 3;
    int fibIndex = 3;

    //ggenerar secuencia Fibonacci filtrada
    while (fib[fibIndex - 1] <= K)
    {
        if (!esPrimo(pos))
        {
            fib[fibIndex] = fib[fibIndex - 1] + fib[fibIndex - 2];
            fibIndex++;
        }
        pos++;
    }

    //encontrar la solución optima
    printf("Terminos utilizados:\n");
    int suma = 0;
    int terminos = 0;

    for (int i = fibIndex - 1; i >= 0; i--)
    {
        if (K >= fib[i])
        {
            printf("%lld\n", fib[i]);
            K -= fib[i];
            terminos++;
        }
    }

    printf("Total de terminos: %d\n", terminos);
}

int main(int argc, char *argv[])
{
    int dia = 17;//dia de nacimiento
    int mes = 01;//mes de nacimiento
    int anio = 93;//año de nacimiento (ultimos 2 digitos)

    int K = dia * 100 + mes * 10 + anio;

    printf("K = %d\n", K);
    printf("Solucion para encontrar terminos de Fibonacci que suman K:\n");
    encontrarTerminosFibonacci(K);

    return 0;
}