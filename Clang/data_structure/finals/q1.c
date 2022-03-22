#include <stdio.h>

void trav(const char *tree_data)
{
    if (!tree_data)
        return;
    if (tree_data[0] == '@')
        return;
    trav(tree_data + 1);
    printf("%c\n", tree_data[0]);
    // trav(tree_data + 1);
    return;
}

int main(int argc, char **argv)
{
    char s[4] = "ABC@";
    trav(s);
    return 0;
}