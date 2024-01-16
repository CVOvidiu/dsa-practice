int sumcif(int n) {
    if(n / 10 == 0)
        return n % 10;
    else
        return n % 10 + sumcif(n / 10);  
} 