// https://www.pbinfo.ro/probleme/2014/canguri

#include <iostream>
#include <fstream>
#include <algorithm>

std::ifstream in("canguri.in");
std::ofstream out("canguri.out");

struct Cangur{
    int Nr;
    int Lun;
} c[3];

int main() {
    int Lun_Pista = 800;

    in >> c[0].Nr >> c[0].Lun;
    in >> c[1].Nr >> c[1].Lun;
    in >> c[2].Nr >> c[2].Lun;

    int L_max = std::max(c[0].Lun, std::max(c[1].Lun, c[2].Lun));

    if(L_max == c[0].Lun) {
        out << c[0].Nr << std::endl;
        if(Lun_Pista % c[0].Lun == 0)
            out << Lun_Pista / c[0].Lun;
        else
            out << Lun_Pista / c[0].Lun + 1;
    }
    else if(L_max == c[1].Lun) {
        out << c[1].Nr << std::endl;
        if(Lun_Pista % c[1].Lun == 0)
            out << Lun_Pista / c[1].Lun;
        else
            out << Lun_Pista / c[1].Lun + 1;
    }
    else if(L_max == c[2].Lun) {
        out << c[2].Nr << std::endl;
        if(Lun_Pista % c[2].Lun == 0)
            out << Lun_Pista / c[2].Lun;
        else
            out << Lun_Pista / c[2].Lun + 1;
    }
}