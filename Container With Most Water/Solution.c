int maxArea(int* height, int heightSize) {
    int MaxArea = 0 , LastMaxArea = 0;
    int i = 0; 
    int ContainerSize = heightSize - 1;

    while( i != ContainerSize )
    {
        if( height[i] <= height[ContainerSize] )
        {
            MaxArea = height[i] * ( ContainerSize - i );
            i++;
        }
        else 
        {
            MaxArea = height[ContainerSize] * ( ContainerSize - i );
            ContainerSize--;
        }       

        if( LastMaxArea <= MaxArea)
        {
             LastMaxArea = MaxArea;
        }      

    }
    return LastMaxArea;
}