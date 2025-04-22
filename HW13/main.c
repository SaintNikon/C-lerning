#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void printArray(float *p, int n)
{
    for(int i = 0; i < n; i++){
        printf(" %f", p[i]);
    }
    printf("\n");
}

int main()
{
    int num;
    srand(time(NULL));
    printf("Razmernost massiva:");
    scanf("%d", &num);
    float *signal = calloc(num, sizeof(float));
    float *noisy_signal = calloc(num, sizeof(float));
    for (int i = 0; i < num; i++)
    {
        signal[i] = 5 * sin(M_PI  * i / 10);
        noisy_signal[i] = signal[i] + 5.0 * rand() / RAND_MAX - 1.0;
    }
    printArray(signal, num);
    printArray(noisy_signal, num);
    FILE *data_file = fopen("signal_data.txt", "w");
    for(int i = 0; i < num; i++)
    {
        fprintf(data_file, "%d %.4f %.4f\n", i, signal[i], noisy_signal[i]);
    }
    fclose(data_file);
    FILE *gnuplot_script = fopen("plot_signal.gp", "w");
    fprintf(gnuplot_script, "set title 'Гармонический сигнал с шумом'\n"
        "set xlabel 'Время (отсчёты)'\n"
        "set ylabel 'Амплитуда'\n"
        "plot 'signal_data.txt' using 1:2 with lines title 'Чистый сигнал', \\\n"
        "     'signal_data.txt' using 1:3 with lines title 'Зашумлённый сигнал'\n"
        "pause -1\n"
    );
    fclose(gnuplot_script);
    system("gnuplot plot_signal.gp");
    free(signal);
    free(noisy_signal);

    return 0;
}
