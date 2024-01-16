int nr_cif_zero(int n) {
    if(n / 10 == 0) // daca suntem la ultima cifra
        if(n % 10 == 0) // daca ultima cifra este 0
            return 1;
        else
            return 0; // daca nu este 0 atunci nu schimbam suma
    else {
        if(n % 10 == 0)
            return 1 + nr_cif_zero(n / 10); // daca cifra este 0 atunci 1 + restul sumei
        else
            return nr_cif_zero(n / 10); // daca nu, atunci restul sumei
    }
}