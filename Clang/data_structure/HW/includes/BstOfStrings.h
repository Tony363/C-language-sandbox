typedef struct _StrBSTNode
{
    char *s;
    struct _StrBSTNode *left, *right;
} StrBSTNode;

typedef struct _StrBST
{
    StrBSTNode *root;
} StrBST;

typedef void (*value_handler)(const char *value, int depth);

StrBST *createStrBST();
void addValueSB(StrBST *bst, const char *value);
void toSortedList(StrBST *bst, value_handler handler);