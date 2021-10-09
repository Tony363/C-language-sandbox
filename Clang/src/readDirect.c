#include <stdio.h>

int main()
{
    FILE *fh = fopen("../Texts/fraction.txt", "r");
    int a, b, pos;
    if (fh == NULL)
    {
        perror("Unable to read file\n");
        return (1);
    }
    printf("enter index:");
    scanf("%d", &pos);
    fseek(fh, (pos - 1) * 4, SEEK_SET);

    printf("ftell: %d\n", ftell(fh));
    fscanf(fh, "%d/%d", &a, &b);
    printf("%d/%d", a, b);

    fclose(fh);

    return (0);
}