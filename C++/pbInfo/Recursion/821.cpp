int cmmdc(int x, int y) {
    if(y == 0)
        return x;
    else
        return cmmdc(y, x % y); // Definitie Euclid cu impartiri
}
