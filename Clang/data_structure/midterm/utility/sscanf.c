#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void tester(const char *data)
{
    char word1[20], word2[32], word3[64];
    int n = sscanf(data, "%19s %31[^, ] %*[,]%63s", word1, word2, word3);
    printf("Test data: <<%s>>\n", data);
    printf("n = %d; w1 = <<%s>>, w2 = <<%s>>, w3 = <<%s>>\n", n, word1, word2, word3);
}

int main()
{
    char sentence[] = "Rudolph is 12 years old";
    char *str = (char *)malloc(sizeof(char) * 10);
    int f_ref, offset = 0;

    while (1 == sscanf(sentence + offset, "%s%n", str, &f_ref))
    {
        printf("%s ", str);
        offset += f_ref;
    };
    printf("\n");
    free(str);

    int day, year;
    char weekday[20], month[20], dtm[100];

    strcpy(dtm, "Saturday March 25 1989");
    int parsed_n = sscanf(dtm, "%s %s %d  %d", weekday, month, &day, &year);

    printf("%s %d, %d = %s; parsed strings = %d\n", month, day, year, weekday, parsed_n);

    const char *data[] =
        {
            "word1 word2 , word3",
            "word1 word2 ,word3",
            "word1 word2, word3",
            "word1 word2,word3",
            "word1 word2       ,       word3",
        };
    enum
    {
        DATA_SIZE = sizeof(data) / sizeof(data[0])
    };
    size_t i;
    for (i = 0; i < DATA_SIZE; i++)
        tester(data[i]);
    return 0;
}