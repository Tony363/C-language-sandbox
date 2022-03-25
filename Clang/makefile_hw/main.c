#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "aggs.h"
/*
This assignment is for practicing the automation of the
project building process by a Makefile.The C or C++ programreads
the input numbers (separated by white spaces or newlines) from
the standard input streamprint the average and the standard deviation
to the standard output in separate linesprint a newlineprint the
smallest 5 numbers in ascending order, in a single line, and two
numbers are separated by a single white spaceThe organization of
the filesat the top-level project directory: the source file that
defines the main() functionin the src sub-directory: all the other
header files and source files The Makefiledefined at the top-level
project directorydefault target "all" builds the target program
"summary"target "libmylib.a" builds the library that includes
the definitions from the src sub-directorytarget "summary"
builds the program by compiling the main object file and then
links with libmylib.aall the generated files (object files,
executable file, and library file) are located in the build
sub-directorytarget "doc" builds the API document in HTML an
put the results in the doc sub-directorytarget "clean" removes
all the generated files in the project directoryUpload your project
folderas a single zip filecontains only necessary source files (no generated files)
 */

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Error: cannot open file %s\n", argv[1]);
        return 1;
    }
    int arr[20];
    char line[25];
    int i = 0;
    while (fgets(line, 25, input_file))
    {
        char word[10];
        int n_chars, offset = 0;
        line[strlen(line)] = '\0';
        while (1 == sscanf(line + offset, "%s%n", word, &n_chars))
        {
            arr[i] = atoi(word);
            offset += n_chars;
            i++;
        }
    }
    double avg = getAvg(arr, 10);
    double std = getStd(arr, 10);
    printf("%lf\n", avg);
    printf("%lf\n", std);
    printf("\n");
    qsort(arr, 10, sizeof(int), cmpfunc);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}