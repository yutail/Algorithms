int count_ones1(unsigned int n) {
    int counter = 0;
    while (n != 0) {
        n = n & (n-1);
        counter++;
    }    
    return counter;
}

int count_ones2(unsigned int n) {
    
    unsigned int BitSetTable256[256];
    BitSetTable256[0] = 0;
    
    for (int i=0; i<256; i++)
        BitSetTable256[i] = (i&1) + BitSetTable256[i/2];
    
    return (BitSetTable256[n & 0xff] + 
            BitSetTable256[(n>>8) & 0xff] +
            BitSetTable256[(n>>16) & 0xff] +
            BitSetTable256[(n>>24) & 0xff]);    
    
}



