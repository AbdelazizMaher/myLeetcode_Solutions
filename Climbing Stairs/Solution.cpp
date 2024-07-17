int climbStairs(int n) {
    int a = 1 , b = 1 , c;

    if( n == 1 || n == 0 )
        return 1;
    for( int i = 1 ; i < n ; ++i)
    {
        c = a + b;
        b = a;
        a = c;
    }
    return c;
}