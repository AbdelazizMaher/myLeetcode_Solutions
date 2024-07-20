char* longestCommonPrefix(char** strs, int strsSize) {
    if( strsSize == 1 ) return strs[0];

    int minLength = strlen(strs[0]);
    for( int  i = 1 ; i < strsSize ; ++i )
    {
        int tempLength = strlen(strs[i]);
        if( minLength < tempLength )
            minLength = tempLength;
    }

    char* commPrefix = (char*)malloc((minLength+1) * sizeof(char));
    memset(commPrefix, 0, minLength+1);

    int prefixLength = 0;
    for( int i = 0 ; i < minLength ; ++i )
    {
        char currentChar = strs[0][i];
        for ( int j = 1 ; j < strsSize ; ++j )
        {
            if( strs[j][i] != currentChar )
                return commPrefix;
        }
        commPrefix[prefixLength++] = currentChar;
    }
    return commPrefix;
}