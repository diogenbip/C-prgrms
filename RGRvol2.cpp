/*
Новые ключевые слова: un,in,dif,sd,pw,el

работа с новыми ключевыми словами:
для слов: un, in, dif, sd

push имя_переменной(это имя не должно встречаться вместь с pop)
push имя_переменной(это имя не должно встречаться вместь с pop)
ключевое_слово

Пример:
1. push x
2. push y
3. un
выводит un(x,y)

для слова pw

push имя_переменной(это имя не должно встречаться вместь с pop)
pw

выводит pw(имя_переменной)

для слова el

1.push константа
2.pop переменная 
3.push имя_переменной(это имя не должно встречаться вместь с pop)
4.ключевое_слово

выводит el(имя_переменной, константа)

*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include<algorithm>
#include <Windows.h>
using namespace std;





enum SymbolicTokenClass { Alpha, Digit, AR_OP, Bool, Space, LF, Sem,  Error, EndOfFile, Read, Write, PUSH, POP, JMP, JI,Un,In,Dif,SD,Pw,El};

enum States { s_A1, s_A2, s_B1, s_C1, s_D1, s_E1, s_E2, s_E3, s_E4, s_E5, s_E6, s_E7, s_E8, s_E9, s_F1, s_F2, s_F3, s_F4, s_F5, s_F6, s_G1, s_H1, s_I1, s_I2, s_J1, s_K1, s_K2, s_L1, s_L2, s_Stop };

struct LexemToken
{
    SymbolicTokenClass token_class; // Класс лексемы.
    int reg_dig;//Регистр ч-ла
    string reg_bool;//Регистр отношения
    string reg_var;//Регистр переменной
    int reg_det;//Регистр обнаружения
    string reg_string_token;//Регистр лексемы
    string reg_str_token;// лексема
    int reg_str_num=1;//номер строки

    list<string>::iterator push_pop_var;//указатель на переменную для push&pop

    

    void clear()
    {
        reg_dig = NULL;
        reg_bool.clear();
        reg_var.clear();
        reg_det = NULL;
        reg_string_token.clear();
        reg_str_token.clear();
    }
};



// Размеры таблицы автомата.
const int state_number = 29; // Число состояний (без s_Stop).
const int class_number = 9; // Число символов входного алфавита.(без Read, Write, PUSH, POP, JMP, JI,Un,In,Dif,SD,Pw,El)



class Lexical_analyzer
{
public:
    list<LexemToken> lexems; //список лексем
    list<int> consts;//список констант 
    list<string> var;//список переменных
    list<LexemToken> error;//ошибка

    friend ostream& operator<<(ostream& os, Lexical_analyzer& p)//печать таблицы
    {
        if (p.error.empty())
        {
            auto it1 = p.lexems.begin();
            p.lexems.pop_back();
            auto it2 = p.consts.begin();
            auto it3 = p.var.begin();
            os << "\t" << "Table of lexemes" << "\n" << endl;
            os << "line" << "\t" << "lexeme" << "\t" << "value" << endl;
            for (; it1 != p.lexems.end(); it1++)
            {
                if (it1->push_pop_var != p.var.end())
                    os << it1->reg_str_num << "\t" << it1->reg_string_token << "\t" << *(it1->push_pop_var) << endl;
                else
                    os << it1->reg_str_num << "\t" << it1->reg_string_token << "\t" << it1->reg_str_token << endl;

            }

            os << "\n\t" << "Table of constants and variables" << "\n" << endl;

            for (; it2 != p.consts.end() && it3 != p.var.end(); it2++, it3++)
            {
                os << *it2 << "\t" << *it3 << endl;
            }
            if (it2 != p.consts.end())
                for (; it2 != p.consts.end(); it2++)
                {
                    os << *it2 << endl;
                }
            else if (it3 != p.var.end())
                for (; it3 != p.var.end(); it3++)
                {
                    os << "\t" << *it3 << endl;
                }
        }
        else { os << "line: " << p.error.begin()->reg_str_num << "\t" << p.error.begin()->reg_string_token << endl; }
        return os;
    }

    
};

// Класс лексического анализатора.
class Parser
{
    LexemToken s;
    Lexical_analyzer q;
    int ch;                                         //текущий символ.
    typedef int (Parser::* function_pointer)();

    friend ostream& operator<<(ostream& os, Parser& p)
    {
        os << p.q;
        return os;
    }

    bool contain()
    {
        if (find(q.var.begin(), q.var.end(), s.reg_var) != q.var.end())
            return true;
        return false;
    }
    //list<LexemToken> lexems; //список лексем
    //list<int> consts;//список констант 
    //list<string> var;//список переменных
    //list<LexemToken> error;//ошибка

    

    function_pointer table[state_number][class_number]; // Таблица указателей на процедуры автомата.
   
   

    SymbolicTokenClass identification(int c)//идентификация входного символа
    {
        ch = c;
        s.push_pop_var = q.var.end();
        if((ch >= 192 && ch <= 255)) { return Alpha; }
        else if (isalpha(ch)) { return Alpha; }
        else if (isdigit(ch)) { return Digit; }
        else if (ch=='+'|| ch == '-' || ch == '/' || ch == '%' || ch == '*') { return AR_OP; }
        else if (ch == '>' || ch == '<' || ch == '=' || ch == '!') { return Bool; }
        else if (ch==' ') { return Space; }
        else if (ch=='\n') { return LF; }
        else if (ch==';') { return Sem; }
        else if (ch==EOF) { return EndOfFile; }
        else { return Error; }
            
    }

    // Процедуры автомата.
    int A1()
    {
        return s_A1;
    }

    int A2()
    {
        s.reg_str_num++;
        return s_A2;
    }

    int C1()
    {
        return s_C1;
    }

    int J1()
    {
        return s_J1;
    }

    int I1()
    {
        return s_I1;
    }

    int I2()
    {
        return s_I2;
    }

    int F1()
    {
        return s_F1;
    }

    int F2()
    {
        return s_F2;
    }

    int F3()
    {
        return s_F3;
    }

    int F4()
    {
        return s_F4;
    }

    int F5()
    {
        return s_F5;
    }

    int F6()
    {
        return s_F6;
    }

    int A1a()
    {
        q.lexems.push_back(s);
        s.clear();
        s.reg_str_num++;
        return s_A1;
    }

    int A1b()
    {
        s.reg_str_num++;
        return s_A1;
    }

    int A2a()
    {
        s.reg_str_num++;
        return s_A2;
    }

    int A2b()
    {
        q.lexems.push_back(s);
        s.clear();
        s.reg_str_num++;
        return s_A2;
    }

    int A2c()
    {
        q.consts.push_back(s.reg_dig);
        s.reg_str_token +=to_string(s.reg_dig);
        q.lexems.push_back(s);
        s.clear();
        s.reg_str_num++;
        return s_A2;
    }

    int A2d()
    {
        if (!contain()) { q.var.push_back(s.reg_var); }
        //s.reg_str_token += " " + s.reg_var;
        s.push_pop_var = find(q.var.begin(), q.var.end(), s.reg_var);
        q.lexems.push_back(s);
        s.clear();
        s.reg_str_num++;
        return s_A2;
    }

    int A2e()
    {
        if (s.reg_bool == "!") { return Error; }
        q.lexems.push_back(s);
        s.clear();
        s.reg_str_num++;
        return s_A2;
    }

    int A2f()
    {
        s.token_class = Error;
        s.reg_string_token = "Error";
        q.error.push_back(s);
        s.clear();
        return s_Stop;
    }

    int B1a()//начальный вектор таблицы обнаружения
    {
        if (ch == 'd')
        {
            s.reg_det = 1;
        }
        else if (ch == 'e')
        {
            s.reg_det = 3;
        }
        else if (ch == 'i')
        {
            s.reg_det = 5;
        }
        else if (ch == 'j')
        {
            s.reg_det = 6;
        }
        else if (ch == 'p')
        {
            s.reg_det = 7;
        }
        else if (ch == 's')
        {
            s.reg_det = 14;
        }
        else if (ch == 'u')
        {
            s.reg_det = 15;
        }
        else if (ch == 'w')
        {
            s.reg_det = 16;
        }
        else if (ch == 'r')
        {
            s.reg_det = 22;
        }
        else
        {
            s.reg_det = 0;
        }
        return s_B1;
    }

    int B1b()
    {
        s.reg_det++;
        return s_B1;
    }

    int C1a()
    {
        s.token_class = AR_OP;
        s.reg_string_token = "AR_OP";
        s.reg_str_token = ch;
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1b()
    {
        s.token_class = EndOfFile;
        s.reg_string_token = "End";
        s.reg_str_token = "end";
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1c()
    {
        s.token_class = Read;
        s.reg_string_token = "Read";
        s.reg_str_token = "read";
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1d()
    {
        s.token_class = Write;
        s.reg_string_token = "Write";
        s.reg_str_token = "write";
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1e()
    {
        q.consts.push_back(s.reg_dig);
        s.reg_str_token += to_string(s.reg_dig);
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1f()
    {
        if (!contain()) { q.var.push_back(s.reg_var); }
        s.push_pop_var = find(q.var.begin(), q.var.end(), s.reg_var);
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1g()
    {
        if (s.reg_bool == "!") { return Error; }
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1h()
    {

        if (ch == '=')
            s.reg_str_token += ch;
        else
            return Error;
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1i()
    {
        s.token_class = Un;
        s.reg_string_token = "Un";
        s.reg_str_token = "un";
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1j()
    {
        s.token_class = In;
        s.reg_string_token = "In";
        s.reg_str_token = "in";
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1k()
    {
        s.token_class = Dif;
        s.reg_string_token = "Dif";
        s.reg_str_token = "dif";
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1l()
    {
        s.token_class = SD;
        s.reg_string_token = "SD";
        s.reg_str_token = "sd";
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1m()
    {
        s.token_class = Pw;
        s.reg_string_token = "Pw";
        s.reg_str_token = "pw";
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int C1n()
    {
        s.token_class = El;
        s.reg_string_token = "El";
        s.reg_str_token = "el";
        q.lexems.push_back(s);
        s.clear();
        return s_C1;
    }

    int D1a()
    {
        s.token_class = Bool;
        s.reg_string_token = "Bool";
        s.reg_bool += ch;
        s.reg_str_token += ch;
        return s_D1;
    }

    int E1a()
    {
        s.token_class = PUSH;
        s.reg_string_token = "PUSH";
        return s_E1;
    }

    int E2a()
    {
        s.token_class = JI;
        s.reg_string_token = "JI";
        return s_E2;
    }

    int E2b()
    {
        s.token_class = JMP;
        s.reg_string_token = "JMP";
        return s_E2;
    }

    int E3a()
    {
        s.token_class = POP;
        s.reg_string_token = "POP";
        return s_E3;
    }

    int G1a()
    {
        s.reg_dig = ch - '0';
        return s_G1;
    }

    int G1b()
    {
        s.reg_dig = 10 * s.reg_dig + (ch - '0');
        return s_G1;
    }

    int H1a()
    {
        s.reg_var = ch;
        return s_H1;
    }

    int H1b()
    {
        s.reg_var += ch;
        return s_H1;
    }

    int I1a()
    {
        s.token_class = Sem;
        return s_I1;
    }

    int I2a()
    {
        s.token_class = Sem;
        s.reg_string_token = "Sem";
        s.reg_str_token = ";";
        return s_I2;
    }

    int I2b()
    {
        q.consts.push_back(s.reg_dig);
        s.reg_str_token = to_string(s.reg_dig);
        q.lexems.push_back(s);
        s.clear();
        s.token_class = Sem;
        s.reg_string_token = "Sem";
        s.reg_str_token = ";";
        return s_I2;
    }

    int I2c()
    {
        if (!contain()) { q.var.push_back(s.reg_var); }
        s.push_pop_var = find(q.var.begin(), q.var.end(), s.reg_var);
        q.lexems.push_back(s);
        s.clear();
        s.token_class = Sem;
        s.reg_string_token = "Sem";
        s.reg_str_token = ";";
        return s_I2;
    }

    int I2d()
    {
        if (s.reg_bool == "!") { return Error; }
        q.lexems.push_back(s);
        s.clear();
        s.token_class = Sem;
        s.reg_string_token = "Sem";
        s.reg_str_token = ";";
        return s_I2;
    }


    int M1()//таблица обнаружения
    {
        char reg[24] = { 'i','f','n', 'd', 'n', 'i', 'o', 'p', 'u', 's', 'h', 'w', 'l', 'd', 'n','r','i','t','e','m','p','e','a','d'};
        bool check = false;
        if (s.reg_det == 0)
        {
            return Error;
        }
        if (reg[s.reg_det-1] == ch)
        {
            check = true;

        }
        else if (s.reg_det == 3 && ch == reg[13-1])
        {
            s.reg_det = 13;
            check = true;
        }
        else if (s.reg_det == 6 && ch == reg[20-1])
        {
            s.reg_det = 20;
            check = true;
        }
        else if (s.reg_det == 7 && ch == reg[9-1])
        {
            s.reg_det = 9;
            check = true;
        }
        else if (s.reg_det == 7 && ch == reg[12-1])
        {
            s.reg_det = 12;
            check = true;
        }
        if (check == true)
        {
            if (s.reg_det == 1 || s.reg_det == 3 || s.reg_det == 7  || s.reg_det == 9  || s.reg_det == 10  || s.reg_det == 16  || s.reg_det == 17  || s.reg_det == 18  || s.reg_det == 20 || s.reg_det == 22 || s.reg_det == 23) { return B1b(); }

            else if (s.reg_det == 6 ) { return E2a(); }
            else if (s.reg_det == 8 ) { return E3a(); }
            else if (s.reg_det == 11 ) { return E1a(); }
            else if (s.reg_det == 21 ) { return E2b(); }

            else if (s.reg_det == 4 ) { return C1b(); }
            else if (s.reg_det == 24) { return C1c(); }
            else if (s.reg_det == 19 ) { return C1d(); }
            else if (s.reg_det == 2) { return C1k(); }
            else if (s.reg_det == 5) { return C1j(); }
            else if (s.reg_det == 12) { return C1m(); }
            else if (s.reg_det == 13) { return C1n(); }
            else if (s.reg_det == 14) { return C1l(); }
            else if (s.reg_det == 15) { return C1i(); }
        }
    }

    int Ex1()
    {
        s.token_class = EndOfFile;
        s.reg_string_token = "EndOfFile";
        q.lexems.push_back(s);
        s.clear();
        return s_Stop;
    }

    int Ex2()
    {
        if (s.reg_bool == "!") { s.token_class = Error; }
        q.lexems.push_back(s);
        s.clear();
        s.token_class = EndOfFile;
        s.reg_string_token = "EndOfFile";
        q.lexems.push_back(s);
        s.clear();
        return s_Stop;
    }

    int Ex3()
    {
        q.consts.push_back(s.reg_dig);
        s.reg_str_token = to_string(s.reg_dig);
        q.lexems.push_back(s);
        s.clear();
        s.token_class = EndOfFile;
        s.reg_string_token = "EndOfFile";
        q.lexems.push_back(s);
        s.clear();
        return s_Stop;
    }

    int Ex4()
    {
        if (!contain()) { q.var.push_back(s.reg_var); }
        s.push_pop_var = find(q.var.begin(), q.var.end(), s.reg_var);
        q.lexems.push_back(s);
        s.clear();
        s.token_class = EndOfFile;
        s.reg_string_token = "EndOfFile";
        q.lexems.push_back(s);
        s.clear();
        return s_Stop;
    }


    int Error1()
    {
        s.token_class = Error;
        s.reg_string_token = "Error";
        q.error.push_back(s);
        s.clear();
        return s_Stop;
    }


public:
    // Конструктор инициализирует таблицу указателей на процедуры автомата.
    Parser()
    {
        // Сначала во все ячейки заносится указатель на процедуру обработки ошибок.
        for (int i = 0; i < state_number; i++)
        {
            for (int j = 0; j < class_number; j++)
            {
                table[i][j] = &Parser::Error1;
            }
        }
        // Далее заполняются ячейки для обработки стекового языка.
        table[s_A1][Alpha] = &Parser::B1a; table[s_F1][Digit] = &Parser::G1a; table[s_A1][AR_OP] = &Parser::C1a; table[s_A1][Bool] = &Parser::D1a; table[s_A1][Space] = &Parser::A1;  table[s_A1][LF] = &Parser::A1b;  table[s_A1][Sem] = &Parser::I1a;  table[s_I1][Error] = &Parser::I1;  table[s_A2][EndOfFile] = &Parser::Ex1;
        table[s_A2][Alpha] = &Parser::B1a; table[s_F2][Digit] = &Parser::G1a; table[s_A2][AR_OP] = &Parser::C1a; table[s_A2][Bool] = &Parser::D1a; table[s_A2][Space] = &Parser::A2;  table[s_A2][LF] = &Parser::A2a;  table[s_A2][Sem] = &Parser::I2a;  table[s_I2][Error] = &Parser::I2;  table[s_C1][EndOfFile] = &Parser::Ex1;
        table[s_B1][Alpha] = &Parser::M1;  table[s_G1][Digit] = &Parser::G1b; table[s_I1][AR_OP] = &Parser::I1;  table[s_D1][Bool] = &Parser::C1h; table[s_C1][Space] = &Parser::C1;  table[s_B1][LF] = &Parser::A2f;  table[s_C1][Sem] = &Parser::I2a;  table[s_J1][Error] = &Parser::J1;  table[s_D1][EndOfFile] = &Parser::Ex2;
        table[s_F1][Alpha] = &Parser::H1a; table[s_H1][Digit] = &Parser::H1b; table[s_I2][AR_OP] = &Parser::I2;  table[s_I1][Bool] = &Parser::I1;  table[s_D1][Space] = &Parser::C1g; table[s_C1][LF] = &Parser::A2;   table[s_D1][Sem] = &Parser::I2d;                                     table[s_G1][EndOfFile] = &Parser::Ex3;
        table[s_F3][Alpha] = &Parser::H1a; table[s_I1][Digit] = &Parser::I1;  table[s_J1][AR_OP] = &Parser::J1;  table[s_I2][Bool] = &Parser::I2;  table[s_E1][Space] = &Parser::F1;  table[s_D1][LF] = &Parser::A2e;  table[s_G1][Sem] = &Parser::I2b;                                     table[s_H1][EndOfFile] = &Parser::Ex4;
        table[s_H1][Alpha] = &Parser::H1b; table[s_I2][Digit] = &Parser::I2;                                     table[s_J1][Bool] = &Parser::J1;  table[s_E2][Space] = &Parser::F2;  table[s_E1][LF] = &Parser::A2f;  table[s_H1][Sem] = &Parser::I2c;                                     table[s_I2][EndOfFile] = &Parser::Ex1;
        table[s_I1][Alpha] = &Parser::I1;  table[s_J1][Digit] = &Parser::J1;                                                                       table[s_E3][Space] = &Parser::F3;  table[s_E2][LF] = &Parser::A2f;  table[s_I1][Sem] = &Parser::I1;                                      table[s_J1][EndOfFile] = &Parser::Ex1;
        table[s_I2][Alpha] = &Parser::I2;                                                                                                          table[s_F1][Space] = &Parser::F1;  table[s_E3][LF] = &Parser::A2f;  table[s_I2][Sem] = &Parser::I2;
        table[s_J1][Alpha] = &Parser::J1;                                                                                                          table[s_F2][Space] = &Parser::F2;  table[s_F1][LF] = &Parser::A2f;  table[s_J1][Sem] = &Parser::J1;
                                                                                                                                                   table[s_F3][Space] = &Parser::F3;  table[s_F2][LF] = &Parser::A2f;
                                                                                                                                                   table[s_G1][Space] = &Parser::C1e; table[s_F3][LF] = &Parser::A2f;
                                                                                                                                                   table[s_H1][Space] = &Parser::C1f; table[s_G1][LF] = &Parser::A2c;
                                                                                                                                                   table[s_I1][Space] = &Parser::I1;  table[s_H1][LF] = &Parser::A2d;
                                                                                                                                                   table[s_I2][Space] = &Parser::I2;  table[s_I1][LF] = &Parser::A1a;
                                                                                                                                                   table[s_J1][Space] = &Parser::J1;  table[s_I2][LF] = &Parser::A2b;
                                                                                                                                                                                      table[s_J1][LF] = &Parser::A2a;

    }

    class Exceptions {
        int datastate;
    public:
        Exceptions(int datast)
        {
            datastate = datast;
        }
        int getData() { return datastate; }
        void What()
        {
            if (datastate == 1)
                cout << "false stack" << endl;
            else if (datastate == 2)
                cout << "false jmp" << endl;
            else if (datastate == 3)
                cout << "false push" << endl;
        }

    };

    class Interpretator
    {

        Lexical_analyzer lex;
        list<int> stack;
        list<string>vstack;
        map<string, int>varb;

    public:
        Interpretator() {}
        Interpretator(Lexical_analyzer& j)
        {
            lex.lexems = j.lexems;
            lex.consts = j.consts;
            lex.var = j.var;
            lex.error = j.error;
        }

        int penult()
        {
            auto it = stack.begin();
            for (int i = 0; i < stack.size() - 2; i++, it++)
                ;
            return *it;
        }
        auto spenult()
        {
            auto it = vstack.begin();
            for (int i = 0; i < vstack.size() - 2; i++, it++)
                ;
            return *it;
        }
        

        void Analysis()
        {
            cout << "=================Interpretator=================" << endl;
            for (auto it1 = lex.lexems.begin(); it1 != lex.lexems.end(); )
            {
                if (it1->token_class == PUSH)
                {
                    if (it1->reg_str_token.empty())
                    {
                        if (!varb.empty() && varb.find(*it1->push_pop_var) != varb.end())
                        {
                            stack.push_back(varb.find(*it1->push_pop_var)->second);
                        }
                        else
                        {
                            vstack.push_back(*it1->push_pop_var);
                        }
                    }
                    else
                    {
                        stack.push_back(stoi(it1->reg_str_token));
                    }
                    it1++;
                }
                else if (it1->token_class == POP)
                {
                    if(stack.empty())
                    {
                        throw Exceptions(1);
                    }
                    else if(varb.find(*it1->push_pop_var)!=varb.end())
                    {
                        varb.find(*it1->push_pop_var)->second = stack.back();
                        stack.pop_back();
                    }
                    else
                    {
                        varb.emplace(make_pair(*it1->push_pop_var, stack.back()));
                        stack.pop_back();
                    }
                    it1++;
                }
                else if (it1->token_class == AR_OP)
                {
                    if (stack.size() >= 2)
                    {
                        if (it1->reg_str_token == "+")
                        {
                            int i = stack.back();
                            stack.pop_back();
                            int j = stack.back();
                            stack.pop_back();
                            stack.push_back(i+j);
                        }
                        else if (it1->reg_str_token == "-")
                        {
                            int i = stack.back();
                            stack.pop_back();
                            int j = stack.back();
                            stack.pop_back();
                            stack.push_back(i - j);
                        }
                        else if (it1->reg_str_token == "*")
                        {
                            int i = stack.back();
                            stack.pop_back();
                            int j = stack.back();
                            stack.pop_back();
                            stack.push_back(i * j);
                        }
                        else if (it1->reg_str_token == "/")
                        {
                            int i = stack.back();
                            stack.pop_back();
                            int j = stack.back();
                            stack.pop_back();
                            stack.push_back(i / j);
                        }
                        else if (it1->reg_str_token == "%")
                        {
                            int i = stack.back();
                            stack.pop_back();
                            int j = stack.back();
                            stack.pop_back();
                            stack.push_back(j % i);
                        }
                        it1++;
                    }
                    else
                    {
                        throw Exceptions(1);
                    }
                }
                else if (it1->token_class == Bool)
                {
                    if (stack.size() >= 2)
                    {
                        if (it1->reg_str_token == ">")
                        {
                            if (penult()> stack.back()) { stack.push_back(1); }
                            else { stack.push_back(0); }
                        }
                        else if (it1->reg_str_token == "<")
                        {
                            if (penult() < stack.back()) { stack.push_back(1); }
                            else { stack.push_back(0); }
                        }
                        else if (it1->reg_str_token == ">=")
                        {
                            if (penult() >= stack.back()) { stack.push_back(1); }
                            else { stack.push_back(0); }
                        }
                        else if (it1->reg_str_token == "<=")
                        {
                            if (penult() <= stack.back()) { stack.push_back(1); }
                            else { stack.push_back(0); }
                        }
                        else if (it1->reg_str_token == "=")
                        {
                            if (penult() == stack.back()) { stack.push_back(1); }
                            else { stack.push_back(0); }
                        }
                        else if (it1->reg_str_token == "!=")
                        {
                            if (penult() != stack.back()) { stack.push_back(1); }
                            else { stack.push_back(0); }
                        }
                        it1++;
                    }
                    else
                    {
                        throw Exceptions(1);
                    }
                }
                else if (it1->token_class == JMP)
                {
                    if (lex.lexems.back().reg_str_num >= stoi(it1->reg_str_token))
                    {
                        int j = stoi(it1->reg_str_token);
                        it1 = lex.lexems.begin();
                        for (int i = 1; i < j; i++, it1++);
                    }
                    else
                    {
                        throw Exceptions(2);
                    }
                }
                else if (it1->token_class == JI)
                {
                    if (stack.size() > 0)
                    {
                        if (stack.back() == 1)
                        {
                            if (lex.lexems.back().reg_str_num >= stoi(it1->reg_str_token))
                            {
                                int j = stoi(it1->reg_str_token);
                                it1 = lex.lexems.begin();
                                for (int i = 1; i < j; i++, it1++);
                            }
                            else
                            {
                                throw Exceptions(2);
                            }
                        }
                        else
                        {
                            it1++;
                        }
                    }
                    else
                    {
                        throw Exceptions(1);
                    }
                }
                else if (it1->token_class == Read)
                {
                cout << "Enter: ";
                int i;
                cin >> i;
                stack.push_back(i);
                it1++;
                }
                else if (it1->token_class == Write)
                {
                if (stack.size() > 0)
                {
                    cout << "Write: " << stack.back()<<endl;
                    stack.pop_back();
                    it1++;
                }
                else { throw Exceptions(1); }
                }
                else if (it1->token_class == Sem)
                {
                it1++;
                }
                else if (it1->token_class == EndOfFile)
                {
                break;
                }
                else if (it1->token_class == Un || it1->token_class == In|| it1->token_class == Dif|| it1->token_class == SD)
                {
                    if (vstack.size() >= 2)
                    {
                        cout << it1->reg_str_token << "(" << vstack.back() << "," << spenult()<<")"<<endl;
                        it1++;
                    }
                    else
                    {
                        throw Exceptions(1);
                    }
                }
                else if (it1->token_class == Pw)
                {
                    if (vstack.size() >= 1)
                    {
                       cout << it1->reg_str_token << "(" << vstack.back()<< ")" << endl;
                       it1++;
                    }
                    else
                    {
                    throw Exceptions(1);
                    }
                }
                else if (it1->token_class == El)
                {
                if (vstack.size() >= 1&&stack.size()>=1)
                {
                    cout << it1->reg_str_token << "(" << vstack.back()<< "," <<stack.back()<< ")" << endl;
                    it1++;
                }
                else
                {
                    throw Exceptions(1);
                }
                }

            }
            cout << "===============================================" << endl;
        }


    };
    // Основная функция анализа. Функция запускает конечный автомат на тексте из файла filename.
    void parse(const char* filename)
    {
        ifstream in(filename);
        if (!in)
        {
            cout << "Не удалось открыть файл " << filename << endl;
            return;
        }

        int ch;             // Входной символ.
        int state = s_A1;   // Текущее состояние автомата.
        while (state != s_Stop)
        {
            // s_Stop - техническое состояние. Когда автомат попадает в s_Stop, цикл останавливается.
            ch = in.get();
            state = (this->*table[state][identification(ch)])();
        }
        Interpretator erp(q);
        try 
        {
            erp.Analysis();
        }
        catch (Exceptions& ex)
        {
            ex.What();
        }

        in.close();
    }
};




/*
Новые ключевые слова: un,in,dif,sd,pw,el
записывается в виде: имя_функции
*/

// Вызов программы имеет вид ./имя-исполняемого-файла имя-входного-файла.
int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (argc != 2)
    {
        cout << "Формат: ./имя-исполняемого-файла имя-входного-файла" << endl;
        return 1;
    }

    Parser p;
    p.parse(argv[1]);
    cout << p;

    return 0;
}
