void sumcif(int n, int &s) {
    if(n / 10 == 0)
        s = n % 10;
    else {
        sumcif(n / 10, s); // s o sa ajunga pana la penultima
        s += n % 10; // asta e ultima cifra
    }
} 