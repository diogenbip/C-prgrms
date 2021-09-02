#include <string>
#include <list>
#pragma once
enum SymbolicTokenClass { Alpha, Digit, AR_OP, Bool, Comma, Space, LF, Sem, Error1, EndOF, LB, RB, Colon };
enum LexemClass { KeyWrd, Ar_Op, BOOL, Ident, Equal, Semm, lab, rab, lb, rb, comma, Const, COLON };
enum States { A1, B1, B2, C1, D1, D2, E1, I1, I2, J1, J2, V1, s_Stop };

const int state_number = 12; // Число состояний (без s_Stop).
const int class_number = 14;

struct SymbolicToken
{

    int reg_vec;
    int reg_bool;
    char ch;
    std::string val;
    SymbolicTokenClass token_class_;
};

struct Lexem
{
    LexemClass token_class;             // Класс лексемы.
    std::string value;                      // Значение лексемы.
};

struct LexemTable
{
    std::list<Lexem> lexems;
};

class Parser {
private:
    SymbolicToken s;
    Lexem l;
    int st_bl;
    typedef int (Parser::* function_pointer)();
    function_pointer table[state_number][class_number];
public:
    Parser();
    void parse(std::string filename);

    LexemTable lt;

    int a1()
    {
        return A1;
    }
    int a1a()
    {
        l.token_class = Ident;
        l.value = s.val;
        lt.lexems.push_back(l);
        s.val.clear();
        return A1;
    }
    int a1k()
    {
        l.token_class = lb;
        l.value = '(';
        lt.lexems.push_back(l);
        return A1;
    }

    int a1b()
    {
        l.token_class = Ar_Op;
        l.value = s.ch;
        lt.lexems.push_back(l);
        return A1;
    }
    int a1h()
    {
        l.token_class = Semm;
        l.value = ';';
        lt.lexems.push_back(l);
        return A1;
    }
    int a1l()
    {
        l.token_class = rb;
        l.value = ')';
        lt.lexems.push_back(l);
        return A1;
    }
    int a1con()
    {
        l.token_class = Const;
        l.value = s.val;
        s.val.clear();
        lt.lexems.push_back(l);
        return A1;
    }
    int a1colon()
    {
        l.token_class = Const;
        l.value = s.val;
        lt.lexems.push_back(l);
        s.val.clear();
        l.token_class = COLON;
        l.value = ':';
        lt.lexems.push_back(l);
        return A1;
    }
    int a1tk()
    {
        lt.lexems.push_back(l);
        s.val.clear();
        return A1;
    }
    int i2a()
    {
        lt.lexems.push_back(l);
        s.val.clear();
        return I2;
    }
    int i2()
    {
        return I2;
    }
    int a1cm()
    {
        l.token_class = Const;
        l.value = s.val;
        lt.lexems.push_back(l);
        s.val.clear();
        l.token_class = comma;
        l.value = ',';
        lt.lexems.push_back(l);
        return A1;
    }




    int b1a()
    {
        s.val += s.ch;
        char vec[26] = { 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v','w','x','y','z' };
        for (int i = 0; i < 26; ++i)
            if (s.ch == vec[i])
            {
                if (i == 0)
                    s.reg_vec = 2;
                else if (i == 1)
                    s.reg_vec = 50;
                else if (i == 2)
                    s.reg_vec = 47;
                else if (i == 3)
                    s.reg_vec = 0;
                else if (i == 4)
                    s.reg_vec = 25;
                else if (i == 5)
                    s.reg_vec = 10;
                else if (i == 6)
                    s.reg_vec = 22;
                else if (i == 8)
                    s.reg_vec = 3;
                else if (i == 9)
                    s.reg_vec = 35;
                else if (i == 11)
                    s.reg_vec = 8;
                else if (i == 12)
                    s.reg_vec = 5;
                else if (i == 13)
                    s.reg_vec = 18;
                else if (i == 17)
                    s.reg_vec = 28;
                else if (i == 18)
                    s.reg_vec = 42;
                else if (i == 19)
                    s.reg_vec = 31;
                else if (i == 20)
                    s.reg_vec = 64;
                else if (i == 22)
                    s.reg_vec = 38;
                return B1;
            }

    }
    int b1b()
    {
        s.reg_vec++;
        return B1;
    }
    int b2a()
    {
        if (s.ch == '=')
            s.reg_bool = 0;
        else if (s.ch == '!')
            s.reg_bool = 1;
        else if (s.ch == '>')
            s.reg_bool = 2;
        else if (s.ch == '<')
            s.reg_bool = 3;
        return B2;
    }

    int c1a()
    {
        s.val += s.ch;
        return C1;
    }

    int e1a() {
        l.token_class = KeyWrd;
        l.value = "dim";
        return E1;
    }
    int e1b() {
        l.token_class = KeyWrd;
        l.value = "as";
        return E1;
    }
    int e1c() {
        l.token_class = KeyWrd;
        l.value = "int";
        return E1;
    }
    int e1d() {
        l.token_class = KeyWrd;
        l.value = "mset";
        return E1;
    }
    int e1e() {
        l.token_class = KeyWrd;
        l.value = "let";
        return E1;
    }
    int e1f() {
        l.token_class = KeyWrd;
        l.value = "for";
        return E1;
    }
    int e1u() {
        l.token_class = KeyWrd;
        l.value = "to";
        return E1;
    }
    int e1g() {
        l.token_class = KeyWrd;
        l.value = "adding";
        return E1;
    }
    int e1h() {
        l.token_class = KeyWrd;
        l.value = "next";
        return E1;
    }
    int e1i() {
        l.token_class = KeyWrd;
        l.value = "if";
        return E1;
    }
    int e1j() {
        l.token_class = KeyWrd;
        l.value = "goto";
        return E1;
    }
    int e1k() {
        l.token_class = KeyWrd;
        l.value = "else";
        return E1;
    }
    int e1l() {
        l.token_class = KeyWrd;
        l.value = "read";
        return E1;
    }
    int e1m() {
        l.token_class = KeyWrd;
        l.value = "trow";
        return E1;
    }
    int i1a() {
        l.token_class = KeyWrd;
        l.value = "rem";
        return I1;
    }
    int e1o() {
        l.token_class = KeyWrd;
        l.value = "jump";
        return E1;
    }
    int e1t() {
        l.token_class = KeyWrd;
        l.value = "write";
        return E1;
    }
    int e1p() {
        l.token_class = KeyWrd;
        l.value = "switch";
        return E1;
    }
    int e1q() {
        l.token_class = KeyWrd;
        l.value = "case";
        return E1;
    }
    int e1r() {
        l.token_class = KeyWrd;
        l.value = "break";
        return E1;
    }
    int e1s() {
        l.token_class = KeyWrd;
        l.value = "end";
        return E1;
    }
    int e1Dif() {
        l.token_class = KeyWrd;
        l.value = "dif";
        return E1;
    }
    int e1Sdif() {
        l.token_class = KeyWrd;
        l.value = "sdif";
        return E1;
    }
    int e1Un() {
        l.token_class = KeyWrd;
        l.value = "un";
        return E1;
    }
    int e1Cross() {
        l.token_class = KeyWrd;
        l.value = "cross";
        return E1;
    }




    int m1()
    {
        s.val += s.ch;
        char reg[65] = { 'i','m','s','n','t','s','e','t','e','t','o','r','o','d','d','i','n','g','e','x','t','f','o','t','o','l','s','e','e','a','d','r','o','w','m','u','m','p','r','i','t','e','w','i','t','c','h','a','s','e','r','e','a','k','n','d','f','d','i','f','r','o','s','s','n' };
        bool check = false;
        if (reg[s.reg_vec] == s.ch)
        {
            check = true;
        }
        else if (s.reg_vec == 1 && reg[56] == s.ch)
        {
            s.reg_vec = 56;
            check = true;
        }
        else if (s.reg_vec == 2 && reg[13] == s.ch)
        {
            s.reg_vec = 13;
            check = true;
        }
        else if (s.reg_vec == 3 && reg[21] == s.ch)
        {
            s.reg_vec = 21;
            check = true;
        }
        else if (s.reg_vec == 25 && reg[53] == s.ch)
        {
            s.reg_vec = 53;
            check = true;
        }
        else if (s.reg_vec == 29 && reg[34] == s.ch)
        {
            s.reg_vec = 34;
            check = true;
        }
        else if (s.reg_vec == 31 && reg[12] == s.ch)
        {
            s.reg_vec = 12;
            check = true;
        }
        else if (s.reg_vec == 42 && reg[57] == s.ch)
        {
            s.reg_vec = 57;
            check = true;
        }
        else if (s.reg_vec == 47 && reg[60] == s.ch)
        {
            s.reg_vec = 60;
            check = true;
        }
        else
        {
            return V1;
        }

        if (check == true)
        {

            if (s.reg_vec == 1)
                return e1a();
            else if (s.reg_vec == 2)
                return e1b();
            else if (s.reg_vec == 4)
                return e1c();
            else if (s.reg_vec == 7)
                return e1d();
            else if (s.reg_vec == 9)
                return e1e();
            else if (s.reg_vec == 11)
                return e1f();
            else if (s.reg_vec == 12)
                return e1u();
            else if (s.reg_vec == 17)
                return e1g();
            else if (s.reg_vec == 20)
                return e1h();
            else if (s.reg_vec == 21)
                return e1i();
            else if (s.reg_vec == 24)
                return e1j();
            else if (s.reg_vec == 27)
                return e1k();
            else if (s.reg_vec == 30)
                return e1l();
            else if (s.reg_vec == 33)
                return e1m();
            else if (s.reg_vec == 34)
                return i1a();
            else if (s.reg_vec == 37)
                return e1o();
            else if (s.reg_vec == 41)
                return e1t();
            else if (s.reg_vec == 46)
                return e1p();
            else if (s.reg_vec == 49)
                return e1q();
            else if (s.reg_vec == 53)
                return e1r();
            else if (s.reg_vec == 55)
                return e1s();
            else if (s.reg_vec == 56)
                return e1Dif();
            else if (s.reg_vec == 59)
                return e1Sdif();
            else if (s.reg_vec == 63)
                return e1Cross();
            else if (s.reg_vec == 64)
                return e1Un();
            else
                return b1b();

        }


    }

    int m2a() {
        if (s.reg_bool == 0)
        {
            l.token_class = Equal;
            l.value = '=';
            lt.lexems.push_back(l);
            return A1;
        }
        else if (s.reg_bool == 1)
        {
            return Error1;
        }
        else if (s.reg_bool == 2)
        {
            l.token_class = BOOL;
            l.value = '>';
            lt.lexems.push_back(l);
            return A1;
        }
        else if (s.reg_bool == 3)
        {
            l.token_class = BOOL;
            l.value = '<';
            lt.lexems.push_back(l);
            return A1;
        }
    }
    int m2b()
    {
        if (s.ch == '=')
        {
            if (s.reg_bool == 0)
            {
                l.token_class = BOOL;
                l.value = "==";
                lt.lexems.push_back(l);
                return A1;
            }
            else if (s.reg_bool == 1)
            {
                l.token_class = BOOL;
                l.value = '!=';
                lt.lexems.push_back(l);
                return A1;
            }
            else if (s.reg_bool == 2)
            {
                l.token_class = BOOL;
                l.value = ">=";
                lt.lexems.push_back(l);
                return A1;
            }
            else if (s.reg_bool == 3)
            {
                l.token_class = BOOL;
                l.value = "<=";
                lt.lexems.push_back(l);
                return A1;
            }
        }
        else if (s.ch == '<')
        {
            if (s.reg_bool == 3)
            {
                l.token_class = lab;
                l.value = "<<";
                lt.lexems.push_back(l);
                return A1;
            }
            else
            {
                return Error1;
            }
        }
        else if (s.ch == '>')
        {
            if (s.reg_bool == 2)
            {
                l.token_class = rab;
                l.value = ">>";
                lt.lexems.push_back(l);
                return A1;
            }
            else
            {
                return Error1;
            }
        }
        else
        {
            Error1;
        }
    }

    int v1a()
    {
        s.val += s.ch;
        return V1;
    }

    int Exit()
    {
        return s_Stop;
    }
    int Error()
    {
        std::cout << "osh";
        return s_Stop;
    }
};