#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#include <string>
#include "opcodes.h"
using namespace std;

//added opcode table

string hexToBinary(string s)
{
    int n = s.length();

    // Convert hexadecimal string to integer
    unsigned int intValue;
    stringstream ss;
    ss << hex << s;
    ss >> intValue;

    // Calculate the number of bits needed based on the length of the hexadecimal string
    int numBits = s.length() * 4; // Each hexadecimal digit represents 4 bits

    // Convert integer to binary 
    bitset<32> binaryValue(intValue);
    return binaryValue.to_string().substr(32 - numBits);
}

bool checkValidReg(int a)
{
    vector<int> registers = {0, 1, 2, 3, 4, 5};
    auto it = std::find(registers.begin(), registers.end(), a);
    if (it != registers.end())
        return true;
    else
        return false;
}

void case1(string s, map<string, string> m)
{
    string a = hexToBinary(s);
    string op = a.substr(0, 8);
    int valid=true;
    if ((m.find(op) == m.end()))
    {
        cout << "Invalid Instruction :Opcode not found" << endl;
        valid = false;
    }

    if (valid)
        cout << "Valid Instruction" << endl;
    // n==2 1 byte
}
void case2(string s, map<string, string> m)
{
    // n==4 && 2 byte && string length 16 char
    string a = hexToBinary(s);
    string op=a.substr(0,8);
    int valid=true;
    if ((m.find(op) == m.end()))
    {
        cout << "Invalid Instruction :Opcode not found" << endl;
        valid = false;
    }

    int r1 = s[2] - 48;
    int r2 = s[3] - 48;
    cout << r1 << " " << r2 << endl;
    if (!(checkValidReg(r1) && checkValidReg(r2))){
        cout << "Invalid Instruction :Registers with such number not found" << endl;
        valid=false;
    }

    if (valid)
        cout << "Valid Instruction" << endl;
}

void case3(string s, map<string, string> m)
{
    // n==6 3 byte
    string a = hexToBinary(s);
    string op = a.substr(0, 6);
    int valid = true;
    if ((m.find(op) == m.end()))
    {
        cout << "Invalid Instruction :Opcode not found" << endl;
        valid = false;
    }
    a = a.substr(6);
    
    int n = a[0]-48;
    int i = a[1]-48;
    int x = a[2]-48;
    int b = a[3]-48;
    int p = a[4]-48;
    int e = a[5]-48;
    // cout <<" "<< n << " " << i <<" "<<x<< " " << b<< " " <<p<< " "  << e <<  endl;
    if ((n || i) == 0)
    {
        valid=true;
    }
    else
    {
        if (e == 1){
            cout << "Invalid Instruction :e flag should be set 0 for 3 byte instruction" << endl;
            valid=false;
        }
        if (((n ^ i) == 1) && (x == 1)){
            cout << "Invalid Instruction :Index registers cant be used with immediate or indirect addressing" << endl;
            valid = false;
        }
        if (b == 1 && p == 1){
            cout << "Invalid Instruction :Both pc and base relative addressing cant be used simultaneously" << endl;
            valid = false;
        }
    }

    // cout << valid ;
    if(valid)
        cout << "Valid Instruction" << endl;

    
}
void case4(string s,map<string,string> m)
{
    // n==8 4 byte
    string a = hexToBinary(s);
    int valid = true;
    string op = a.substr(0, 6);
    if ((m.find(op) == m.end())){
        cout << "Invalid Instruction :Opcode not found" << endl;
        valid = false;
    }
    a = a.substr(6);
    
    int n = a[0]-48;
    int i = a[1]-48;
    int x = a[2]-48;
    int b = a[3]-48;
    int p = a[4]-48;
    int e = a[5]-48;
    // cout << " " << n << " " << i << " " << x << " " << b << " " << p << " " << e << endl;
    if ((n || i) == 0){
        cout << "Invalid Instruction :It is a Sic instruction and should be of 3 bytes" << endl;
        valid=false;
    }
    
    if (e == 0){
        cout << "Invalid Instruction :e flag should be set 1 for 4 byte instruction" << endl;
        valid = false;
    }
    if (b == 1 || p == 1){
        cout << "Invalid Instruction :Format 4 dont support base relative or pc relative addressing" << endl;
        valid = false;
    }
    if (((n ^ i) == 1) && (x == 1)){
        cout << "Invalid Instruction :Index registers cant be used with immediate or indirect addressing" << endl;
        valid = false;
    }

    if (valid)
        cout << "Valid Instruction" << endl;

    
}

int binToDecimal(string a)
{
    int n = a.length();
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        b += (1 << (n - i - 1));
    }

    return b;
}

int main()
{
    // int t;
    // cin >> t;
    // while(t--){
    string s;
    cin >> s;
    int n = s.length();
    Opcodes opcodes;
    map<string,string> f1=opcodes.f1;
    map<string,string> f2=opcodes.f2;
    map<string,string> f3=opcodes.f3;
    map<string,string> f4=opcodes.f3;

    // cout << a << " " << endl;
    // cout << endl;
    switch (n)
    {
    case 2:
        case1(s,f1);
        break;
    case 4:
        case2(s,f2);
        break;
    case 6:
        case3(s,f3);
        break;
    case 8:
        case4(s,f4);
        break;
    default:
        cout << "Not a valid instruction format of SIC/SIC-XE";
        break;
    }
    cout << endl;
    // }

    return 0;
}