typedef struct
{
    char* str;
    char** anagrams;
    int anagramCount;
    int anagramCapacity;
}sAnagram;

int compare(const void* a, const void* b)
{
    return ( *(char*)a - *(char*)b );
}

char* sortString(char* str)
{
    char* sorted = malloc(strlen(str) + 1);
    strcpy(sorted, str);

    qsort(sorted, strlen(sorted), sizeof(char), compare);
    return sorted;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    int mpCapacity = 100;
    int keys = 0;

    sAnagram* mp = (sAnagram*)malloc(mpCapacity * sizeof(sAnagram));

    for( int i = 0 ; i < strsSize ; ++i )
    {
        char*sortedStr = sortString(strs[i]);

        int found = 0;
        for( int j = 0 ; j < keys ; ++j )
        {
            if( strcmp(sortedStr, mp[j].str) == 0 )
            {
                 found = 1;

                 if( mp[j].anagramCount == mp[j].anagramCapacity ) 
                 {
                    mp[j].anagramCapacity *= 2;
                    mp[j].anagrams = realloc(mp[j].anagrams, mp[j].anagramCapacity * sizeof(char*)); 
                 }
                 mp[j].anagrams[mp[j].anagramCount++] = strs[i];
                 break;
            }
        }

        if( !found )
        {
            if( keys == mpCapacity )
            {
                mpCapacity *= 2;
                mp = realloc(mp, mpCapacity * sizeof(sAnagram));                 
            }
            mp[keys].str = sortedStr;
            mp[keys].anagramCapacity = 10;
            mp[keys].anagramCount = 1;
            mp[keys].anagrams = (char**)malloc(mp[keys].anagramCapacity * sizeof(char*));
            mp[keys].anagrams[0] = strs[i];

            keys++;
        }
        else
            free(sortedStr);
    }

    char*** groupAnagrams = (char***)malloc(keys * sizeof(char**));
    *returnColumnSizes = (int*)malloc(keys * sizeof(int));
    *returnSize = keys;

    for( int k = 0 ; k < keys ; ++k )
    {
        groupAnagrams[k] = mp[k].anagrams;
        (*returnColumnSizes)[k] = mp[k].anagramCount;
        free(mp[k].str);
    }

    free(mp);
    return groupAnagrams;
}