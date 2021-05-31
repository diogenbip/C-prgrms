#ifndef SH
#define SH
#include"Lexer.h"
#include"MyStack.h"
class SyntAuto :public LexAuto
{
	struct atom
	{
		int type;
		int atribute1;
		int atribute2;
		int atribute3;
		int atribute4;
		friend std::ostream& operator<<(std::ostream& out, atom& a)
		{
			out << a.type << " " << a.atribute1 << " " << a.atribute2 << " " << a.atribute3 << " " << a.atribute4 << std::endl;
			return out;
		}
	};
	MyStack<int>shop;
	int cur;
	int strNum;
	int poz;
	static const int nsize = 34;
	static const int msize = 23;
	typedef void(SyntAuto::*func)();
	func transit[nsize][msize];
protected:
	int HOBT;
	int HOBTAM;
	vector<atom>TA;
public:
	SyntAuto() :LexAuto()
	{
		shop.push(17);
		shop.push(0);
		poz = 0;
		for (int i = 0; i < 23; i++)
		{
			transit[0][i] = &SyntAuto::A;
			transit[1][i] = &SyntAuto::B;
			transit[2][i] = &SyntAuto::G1;
			transit[3][i] = &SyntAuto::D;
			transit[4][i] = transit[5][i] = transit[6][i] = transit[7][i] = &SyntAuto::K4;
			transit[8][i] = transit[9][i] = transit[12][i] = transit[15][i] = &SyntAuto::O;
			transit[10][i] = &SyntAuto::f26;
			transit[11][i] = &SyntAuto::E1;
			transit[13][i] = &SyntAuto::M1;
			transit[14][i] = &SyntAuto::H1;
			transit[16][i] = &SyntAuto::P1;
			transit[17][i] = &SyntAuto::R;
			transit[18][i] = &SyntAuto::d;
			transit[19][i] = &SyntAuto::e;
			transit[20][i] = &SyntAuto::f;
			transit[21][i] = &SyntAuto::g;
			transit[22][i] = &SyntAuto::h;
			transit[23][i] = &SyntAuto::i;
			transit[24][i] = &SyntAuto::j;
			transit[25][i] = &SyntAuto::k;
			transit[26][i] = &SyntAuto::l;
			transit[27][i] = &SyntAuto::m;
			transit[28][i] = &SyntAuto::n;
			transit[29][i] = &SyntAuto::o;
			transit[30][i] = &SyntAuto::p;
			transit[31][i] = &SyntAuto::q;
			transit[32][i] = &SyntAuto::r;
		}
		transit[0][0] = &SyntAuto::f1;
		transit[0][21] = &SyntAuto::C;
		transit[0][22] = &SyntAuto::T1;
		transit[1][0] = &SyntAuto::f3;
		transit[1][3] = transit[1][12] = &SyntAuto::f2;
		transit[1][4] = &SyntAuto::f4;
		transit[1][5] = &SyntAuto::f9;
		transit[1][6] = &SyntAuto::f5;
		transit[1][7] = &SyntAuto::f7;
		transit[1][10] = &SyntAuto::f6;
		transit[1][11] = &SyntAuto::f8;
		transit[1][15] = &SyntAuto::f12;
		transit[1][21] = &SyntAuto::C;
		transit[1][22] = &SyntAuto::T2;
		transit[2][0] = &SyntAuto::f11;
		transit[2][9] = &SyntAuto::G2;
		transit[2][14] = &SyntAuto::f10;
		transit[2][21] = &SyntAuto::C;
		transit[2][22] = &SyntAuto::T2;
		transit[3][0] = &SyntAuto::f13;
		transit[3][21] = &SyntAuto::C;
		transit[3][22] = &SyntAuto::T2;
		transit[4][0] = &SyntAuto::K2;
		transit[4][1] = transit[4][8] = &SyntAuto::f14;
		transit[4][2] = transit[4][6] = transit[4][13] = transit[4][14] = &SyntAuto::K1;
		transit[4][9] = &SyntAuto::K3;
		transit[4][16] = &SyntAuto::f15;
		transit[4][17] = &SyntAuto::f16;
		transit[4][18] = transit[4][19] = transit[4][20] = &SyntAuto::K5;
		transit[4][21] = &SyntAuto::C;
		transit[4][22] = &SyntAuto::T3;
		transit[5][0] = &SyntAuto::K2;
		transit[5][1] = transit[5][8] = &SyntAuto::f20;
		transit[5][2] = transit[5][6] = transit[5][13] = transit[5][14] = &SyntAuto::K1;
		transit[5][9] = &SyntAuto::K3;
		transit[5][16] = transit[5][17] = transit[5][18] = transit[5][19] = transit[5][20] = &SyntAuto::K6;
		transit[5][21] = &SyntAuto::C;
		transit[5][22] = &SyntAuto::T3;
		transit[6][0] = &SyntAuto::K2;
		transit[6][1] = transit[6][8] = &SyntAuto::f24;
		transit[6][2] = transit[6][6] = transit[6][13] = transit[6][14] = &SyntAuto::K1;
		transit[6][9] = &SyntAuto::K3;
		transit[6][16] = transit[6][17] = transit[6][18] = transit[6][19] = transit[6][20] = &SyntAuto::K6;
		transit[6][21] = &SyntAuto::C;
		transit[6][22] = &SyntAuto::T3;
		transit[7][0] = &SyntAuto::K2;
		transit[7][1] = &SyntAuto::f28;
		transit[7][8] = &SyntAuto::f27;
		transit[7][2] = transit[7][6] = transit[7][13] = transit[7][14] = &SyntAuto::K1;
		transit[7][9] = &SyntAuto::K3;
		transit[7][16] = transit[7][17] = transit[7][18] = transit[7][19] = transit[7][20] = &SyntAuto::K6;
		transit[7][21] = &SyntAuto::C;
		transit[7][22] = &SyntAuto::T3;
		transit[8][1] = transit[8][8] = &SyntAuto::K7;
		transit[8][0] = transit[8][2] = transit[8][6] = transit[8][9] = transit[8][13] = transit[8][14] = &SyntAuto::f19;
		transit[8][16] = &SyntAuto::f17;
		transit[8][17] = &SyntAuto::f18;
		transit[9][1] = transit[8][8] = &SyntAuto::K7;
		transit[9][0] = transit[9][2] = transit[9][6] = transit[9][9] = transit[9][13] = transit[9][14] = transit[9][16] = transit[9][17] = &SyntAuto::f23;
		transit[9][18] = &SyntAuto::f21;
		transit[9][19] = &SyntAuto::f22;
		transit[10][1] = transit[10][8] = &SyntAuto::K7;
		transit[10][3] = transit[10][4] = transit[10][5] = transit[10][7] = transit[10][10] = transit[10][11] = transit[10][12] = transit[10][15] = &SyntAuto::K4;
		transit[10][20] = &SyntAuto::f25;
		transit[10][21] = &SyntAuto::C;
		transit[10][22] = &SyntAuto::T2;
		transit[11][1] = &SyntAuto::E2;
		transit[11][2] = &SyntAuto::b;
		transit[11][9] = &SyntAuto::E3;
		transit[11][21] = &SyntAuto::C;
		transit[11][22] = &SyntAuto::T3;
		transit[12][3] = &SyntAuto::b;
		transit[12][12] = &SyntAuto::L;
		transit[13][6] = &SyntAuto::b;
		transit[13][0] = &SyntAuto::M2;
		transit[13][2] = &SyntAuto::M3;
		transit[13][8] = &SyntAuto::M4;
		transit[13][21] = &SyntAuto::C;
		transit[13][22] = &SyntAuto::T3;
		transit[14][0] = &SyntAuto::H2;
		transit[14][9] = &SyntAuto::a;
		transit[14][21] = &SyntAuto::C;
		transit[14][22] = &SyntAuto::T3;
		transit[15][3] = &SyntAuto::K;
		transit[15][12] = &SyntAuto::a;
		transit[16][0] = &SyntAuto::P2;
		transit[16][9] = &SyntAuto::P3;
		transit[16][13] = &SyntAuto::a;
		transit[16][14] = &SyntAuto::P4;
		transit[16][21] = &SyntAuto::C;
		transit[16][22] = &SyntAuto::T3;
		transit[17][21] = &SyntAuto::C;
		transit[17][22] = &SyntAuto::c;

	}
	atom createAtom(int type, int a1, int a2, int a3, int a4);
	void translate(E_TL& lexem);
	void showTA(ostream&out){ for (std::vector<atom>::iterator i = TA.begin(); 	i != TA.end(); ++i) out << *i << std::endl;	}
	void startsynt(std::string name);
	void f1();
	void f2();
	void f3();
	void f4();
	void f5();
	void f6();
	void f7();
	void f8();
	void f9();
	void f10();
	void f11();
	void f12();
	void f13();
	void f14();
	void f15();
	void f16();
	void f17();
	void f18();
	void f19();
	void f20();
	void f21();
	void f22();
	void f23();
	void f24();
	void f25();
	void f26();
	void f27();
	void f28();
	void a();
	void b();
	void c();
	void d();
	void e();
	void f();
	void g();
	void h();
	void i();
	void j();
	void k();
	void l();
	void m();
	void n();
	void o();
	void p();
	void q();
	void r();
	void A(){ Error er(0, "Программа начинается неверно\n"); throw er; }
	void B(){ Error er(0, "Оператор начинается неверно\n"); throw er; }
	void G1(){ std::string str = "Неожиданный " + (cur + '0'); str += " в конце FOR - оператора\n"; Error er(0, str); throw er; }
	void G2(){ Error er(0, "Лишняя правая скобка в выражении после TO\n"); throw er; }
	void D(){ std::string str = "Неожиданный " + (cur + '0'); str += " после окончания оператора\n"; 	Error er(0, str); throw er; }
	void K1(){ Error er(0, "Выражение незакончено - нет операнда\n"); throw er; }
	void K2(){ Error er(0, "Оператор незакончен\n"); throw er; }
	void K3(){ Error er(0, "В выражении пропущен операнд\n"); throw er; }
	void K4(){ std::string str = "Неожиданный " + (cur + '0'); str += " после выражения\n"; Error er(0, str); throw er; }
	void K5(){ std::string str = "Выражение начинается с " + (cur + '0'); Error er(0, str); throw er; }
	void K6(){ Error er(0, "Два знака операции подряд в выражении\n"); throw er; }
	void K7(){ Error er(0, "В выражении пропущен знак операции\n"); throw er; }
	void E1(){ std::string str = "Неожиданный " + (cur + '0'); str += " в IF операторе\n"; Error er(0, str); throw er; }
	void E2(){ Error er(0, "IF оператор незакончен\n"); throw er; }
	void E3(){ Error er(0, "Лишняя правая скобка в выражении после IF\n"); throw er; }
	void L(){ Error er(0, "FOR операторы вложены неправильно, пропущено NEXT\n"); throw er; }
	void M1(){ std::string str = "Неожиданный " + (cur + '0'); str += " в IF операторе\n"; Error er(0, str); throw er; }
	void M2(){ Error er(0, "IF оператор незакончен\n"); throw er; }
	void M3(){ Error er(0, "Два знака отношения в IF операторе\n"); throw er; }
	void M4(){ Error er(0, "Лишняя правая скобка в выражении после знака отношения\n"); throw er; }
	void H1(){ std::string str = "Пропущена правая скобка перед " + (cur + '0'); Error er(0, str); throw er; }
	void H2(){ Error er(0, "Пропущена правая скобка в конце строки\n"); throw er; }
	void K(){ Error er(0, "FOR-операторы вложены неправильно - лишнее NEXT\n"); throw er; }
	void P1(){ std::string str = "Неожиданный " + (cur + '0'); str += " в FOR операторе\n"; Error er(0, str); throw er; }
	void P2(){ Error er(0, "FOR оператор незакончен\n"); throw er; }
	void P3(){ Error er(0, "Лишняя правая скобка в выражении после -\n"); throw er; }
	void P4(){ Error er(0, "TO пропущено или не на своём месте в FOR операторе\n"); throw er; }
	void R(){ Error er(0, "Программа продолжается после END-оператора\n"); throw er; }
	void C(){ Error er(0, " "); throw er; }
	void T1(){ Error er(0, "Нет программы\n"); throw er; }
	void T2(){ Error er(0, "Пропущен END-оператор\n"); throw er; }
	void T3(){ Error er(0, "Программа кончается посреди оператора\n"); throw er; }
	void O(){ Error er(0, "Ошибка компилятора\n"); throw er; }
};
#endif SH