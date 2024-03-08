#include <bits/stdc++.h>
using namespace std;
class Opcodes
{
public:
    map<string, string> f1;
    map<string, string> f2;
    map<string, string> f3;
    map<string, string> f4;

    map<string, string> reg;

public:
    Opcodes();
    ~Opcodes();
};

Opcodes::Opcodes()
{
    f1["11000100"] = "FIX";
    f1["11000000"] = "FLOAT";
    f1["11110100"] = "HIO";
    f1["11001000"] = "NORM";
    f1["11110000"] = "SIO";
    f1["11111000"] = "TIO";

    f2["10010000"] = "ADDR";
    f2["10100000"] = "COMPR";
    f2["10110100"] = "CLEAR";
    f2["10011100"] = "DIVR";
    f2["10011000"] = "MULR";
    f2["10101100"] = "RMO";
    f2["10100100"] = "SHIFTL";
    f2["10101000"] = "SHIFTR";
    f2["10010100"] = "SUBR";
    f2["10110000"] = "SVC";
    f2["10111000"] = "TIXR";

    f3["000110"] = "ADD";
    f3["010110"] = "ADDF";
    f3["001000"] = "AND";
    f3["001010"] = "COMP";
    f3["100010"] = "COMPF";
    f3["001001"] = "DIV";
    f3["011001"] = "DIVF";
    f3["001111"] = "J";
    f3["001100"] = "JEQ";
    f3["001101"] = "JGT";
    f3["001110"] = "JLT";
    f3["010010"] = "JSUB";
    f3["000000"] = "LDA";
    f3["011010"] = "LDB";
    f3["010100"] = "LDCH";
    f3["011100"] = "LDF";
    f3["000010"] = "LDL";
    f3["011011"] = "LDS";
    f3["000001"] = "LDX";
    f3["110100"] = "LDX";
    f3["001000"] = "MUL";
    f3["011000"] = "MULF";
    f3["010001"] = "OR";
    f3["110110"] = "RD";
    f3["010011"] = "RSUB";
    f3["101001"] = "SHIFTL";
    f3["101010"] = "SHIFTR";
    f3["110010"] = "SSK";
    f3["000011"] = "STA";
    f3["011110"] = "STB";
    f3["010101"] = "STCH";
    f3["100000"] = "STF";
    f3["110101"] = "STI";
    f3["000101"] = "STL";
    f3["011111"] = "STS";
    f3["111010"] = "STSW";
    f3["100001"] = "STT";
    f3["001000"] = "STX";
    f3["000111"] = "SUB";
    f3["010111"] = "SUBF";
    f3["111000"] = "TD";
    f3["001011"] = "TIX";
    f3["110111"] = "WD";

    reg["0"] = "A";
    reg["1"] = "X";
    reg["2"] = "L";
    reg["3"] = "B";
    reg["4"] = "S";
    reg["5"] = "T";
    reg["6"] = "F";
    reg["8"] = "PC";
    reg["9"] = "SW";
}
Opcodes::~Opcodes()
{
}
