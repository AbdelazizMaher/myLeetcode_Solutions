int reverse(int x){
    char reverseSTR[100];
    int remainder =0 ,i=0 ,maxValue=2147483647;
    double reverse=0;
     if(  x == -2147483648 )
        return 0;
    if( x<0 )
    {
        x*=(-1);
        reverseSTR[0]= '-';
        i++;
    }
    for ( ; x != 0 ; i++ )
     {
        remainder = x % 10;
        reverse = reverse * 10 + remainder;
        reverseSTR[i] = remainder +'0';
        x /= 10;
     }
     reverseSTR[i] = '\0';
     if( reverse >maxValue || reverse < -2147483648 )
        return 0;
     reverse = atoi(reverseSTR);
    
    return reverse;
}