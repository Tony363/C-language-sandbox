
#include <stdio.h>

void input()
{
    int counter = 0, input, c = -1, target, i;
    int arr[10];
    while (scanf("%d", &input) && counter < 9)
    {
        arr[counter] = input;
        counter++;
    }
    scanf("%d", &target);
    for (i = 0; i < counter; i++)
    {
        if (arr[i] == target)
            c = i;
    }
    printf("%d", c);
}

int main(void)
{
    input();
    return 0;
}
