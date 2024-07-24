typedef struct
{
    char* name;
    int height;
}sPerson;

int compare(const void* a, const void* b)
{
    sPerson* pPerson1 = (sPerson*)a;
    sPerson* pPerson2 = (sPerson*)b;

    return pPerson2->height - pPerson1->height;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    sPerson* pPeople = (sPerson*)malloc(namesSize * sizeof(sPerson));

    for( int i = 0 ; i < namesSize ; ++i )
    {
        pPeople[i].name = names[i];
        pPeople[i].height = heights[i];
    }

    qsort(pPeople, namesSize, sizeof(sPerson), compare);

    char** sortedNames = (char**)malloc(namesSize * sizeof(char*));

    for( int i = 0 ; i < namesSize ; ++i )
        sortedNames[i] = pPeople[i].name;

    *returnSize = namesSize;
    free(pPeople);

    return sortedNames;
}