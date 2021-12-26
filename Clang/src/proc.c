#include <stdio.h>

void proc(int a[], int n, int *min_p, int *max_p, double *avg_p)
{
    int min, max, avg, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            min = max = a[i];
        }
        else
        {
            if (a[i] < min)
            {
                min = a[i];
            }
            if (a[i] > max)
            {
                max = a[i];
            }
        }
        sum += a[i];
    }
    *avg_p = (double)sum / (double)n;
    *min_p = min;
    *max_p = max;
}

int main(int argc, char **argv)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int min, max;
    double avg;
    proc(a, n, &min, &max, &avg);
    printf("min: %d, max: %d, avg: %f\n", min, max, avg);
    return 0;
}