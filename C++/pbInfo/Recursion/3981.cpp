int DivImpRec(int n) {
    if(n % 2 != 0 ) // daca nu e par, este rezultatul
        return n;
    else
        return DivImpRec(n/2); // impartim prin 2 pana dam de divizorul impar cel mai mare (cele impare raman ele insasi ca fiind cel mai mare div impar)
}