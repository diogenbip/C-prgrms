#include"Syntax.h"
void SyntAuto::translate(E_TL& lexem)
{
	switch (lexem._class)
	{
	case 1:cur = 0; break;
	case 2:cur = 1; break;
	case 4:cur = 2; break;
	case 5:cur = 3; break;
	case 6:cur = 4; break;
	case 7:cur = 5; break;
	case 8:cur = 6; break;
	case 9:cur = 7; break;
	case 10:cur = 8; break;
	case 11:cur = 9; break;
	case 12:cur = 10; break;
	case 13:cur = 11; break;
	case 14:cur = 12; break;
	case 15:cur = 13; break;
	case 16:cur = 14; break;
	case 17:cur = 15; break;
	case 3:
	{
						switch (lexem.value)
						{
						case 1: cur = 16; break;
						case 2: cur = 17; break;
						case 3:cur = 18; break;
						case 4: cur = 19; break;
						case 5: cur = 20; break;
						}
						break;
	}
	case 18:cur = 21; break;
	case 19:cur = 22; break;
	}

}
SyntAuto::atom SyntAuto::createAtom(int type, int a1, int a2, int a3, int a4)
{
	atom a;
	a.type = type;
	a.atribute1 = a1;
	a.atribute2 = a2;
	a.atribute3 = a3;
	a.atribute4 = a4;
	TA.push_back(a);
	return a;
}
void SyntAuto::startsynt(std::string name)
{
	startlexer(name);
	if (!correct)
	{
		std::cout << "Программа содержит ошибки" << std::endl;
		return;
	}
	HOBT= NTO;
	HOBTAM = 500;
	while(poz < NTL&&shop.gethead())
	{
		translate(TL[poz]);
		try{	(this->*transit[shop.top()][cur])();	}
		catch (Error er)
		{
			correct = 0;
			cout << er.getType();
			break;
		}
	}
}
void SyntAuto::f1()
{
	shop.pop();
	shop.push(15);
	shop.push(1);
	strNum = TL[poz].value;
	atom a = createAtom(2, strNum, -1, -1,-1);		 
	poz++;
}
void SyntAuto::f2()
{
	shop.pop();
}
void SyntAuto::f3()
{
	shop.pop();
	shop.push(1);
	strNum = TL[poz].value;
	atom a = createAtom(2, strNum, -1, -1,-1);		 
	poz++;
}
void SyntAuto::f4()
{
	shop.pop();
	shop.push(3);
	shop.push(0);
	shop.push(TL[poz].value);
	shop.push(18);
	shop.push(3);
	shop.push(4);	
	poz++;
}
void SyntAuto::f5()
{
	shop.pop();
	shop.push(3);
	atom a = createAtom(4, TL[poz].value, -1, -1,-1);	 
	poz++;
}
void SyntAuto::f6()
{
	shop.pop();
	shop.push(3);
	shop.push(0);
	shop.push(0);
	shop.push(0);
	shop.push(0);
	shop.push(19);
	shop.push(5);
	shop.push(13);
	shop.push(5);
	shop.push(4);
	shop.push(8);
	shop.push(11);
	shop.push(8);
	shop.push(4);
	poz++;
}
void SyntAuto::f7()
{
	shop.pop();
	shop.push(3);
	atom a = createAtom(5, TL[poz].value, -1, -1, -1);	 
	poz++;
}
void SyntAuto::f8()
{
	shop.pop();
	shop.push(3);
	atom a = createAtom(6, -1, -1, -1, -1);	 
	poz++;
}
void SyntAuto::f9()
{
	shop.pop();
	shop.push(3);
	shop.push(HOBTAM + 1);
	shop.push(21);
	shop.push(HOBTAM);
	shop.push(25);
	shop.push(HOBT + 1);
	shop.push(TL[poz].value);
	shop.push(24);
	shop.push(strNum);
	shop.push(0);
	shop.push(TL[poz].value);
	shop.push(23);
	shop.push(3);
	shop.push(12);
	shop.push(3);
	shop.push(HOBTAM + 1);
	shop.push(HOBT + 1);
	shop.push(HOBT);
	shop.push(TL[poz].value);
	shop.push(22);
	shop.push(HOBTAM);
	shop.push(21);
	shop.push(HOBT + 1);
	shop.push(0);
	shop.push(20);
	shop.push(2);
	shop.push(2);
	shop.push(HOBT);
	shop.push(0);
	shop.push(20);
	shop.push(2);
	shop.push(4);
	shop.push(16);
	shop.push(0);
	shop.push(TL[poz].value);
	shop.push(18);
	shop.push(3);
	shop.push(4);
	TO[HOBT] = 1;
	HOBTAM=HOBTAM+2;
	HOBT = HOBT + 2;
	poz++;
}
void SyntAuto::f10()
{
	shop.pop();
	shop.push(4);
	poz++;
}
void SyntAuto::f11()
{
	shop.pop();
	shop.replace(shop.top(), 0);
	shop.pop();
}
void SyntAuto::f12()
{
	shop.pop();
	shop.push(3);
	poz++;
}
void SyntAuto::f13()
{
	shop.pop();
	shop.push(1);
	strNum = TL[poz].value;
	atom a = createAtom(2, strNum, -1, -1, -1);	 
	poz++;

}
void SyntAuto::f14()
{
	shop.pop();
	shop.push(0);
	shop.push(8);
	shop.push(2);
	shop.push(5);
}
void SyntAuto::f15()
{
	shop.pop();
	shop.push(HOBT);
	shop.push(8);
	shop.push(HOBT);
	shop.push(0);
	shop.push(31);
	shop.push(2);
	shop.push(5);
	TO[HOBT]=0;
	HOBT++;
	poz++;
}
void SyntAuto::f16()
{
	shop.pop();
	shop.push(HOBT);
	shop.push(8);
	shop.push(HOBT);
	shop.push(0);
	shop.push(32);
	shop.push(2);
	shop.push(5);
	TO[HOBT]=0;
	HOBT++;
	poz++;
}
void SyntAuto::f17()
{
	shop.pop();
	int v = shop.pop();
	shop.push(HOBT);
	shop.push(8);
	shop.push(HOBT);
	shop.push(0);
	shop.push(v);
	shop.push(26);
	shop.push(3);
	shop.push(5);
	TO[HOBT]=0;
	HOBT++;
	poz++;
}
void SyntAuto::f18()
{
	shop.pop();
	int v = shop.pop();
	shop.push(HOBT);
	shop.push(8);
	shop.push(HOBT);
	shop.push(0);
	shop.push(v);
	shop.push(27);
	shop.push(3);
	shop.push(5);
	TO[HOBT]=0;
	HOBT++;
	poz++;
}
void SyntAuto::f19()
{
	shop.pop();
	int v = shop.top();
	shop.pop();
	shop.replace(shop.top(), v);
	shop.pop();

}
void SyntAuto::f20()
{
	shop.pop();
	shop.push(0);
	shop.push(9);
	shop.push(2);
	shop.push(6);
}
void SyntAuto::f21()
{
	shop.pop();
	int v = shop.pop();
	shop.push(HOBT);
	shop.push(9);
	shop.push(HOBT);
	shop.push(0);
	shop.push(v);
	shop.push(28);
	shop.push(3);
	shop.push(6);
	TO[HOBT]=0;
	HOBT++;
	poz++;
}
void SyntAuto::f22()
{
	shop.pop();
	int v = shop.pop();
	shop.push(HOBT);
	shop.push(9);
	shop.push(HOBT);
	shop.push(0);
	shop.push(v);
	shop.push(29);
	shop.push(3);
	shop.push(6);
	TO[HOBT]=0;
	HOBT++;
	poz++;

}
void SyntAuto::f23()
{
	shop.pop();
	int v = shop.top();
	shop.pop();
	shop.replace(shop.top(), v);
	shop.pop();
}
void SyntAuto::f24()
{
	shop.pop();
	shop.push(0);
	shop.push(10);
	shop.push(2);
	shop.push(7);
}
void SyntAuto::f25()
{
	shop.pop();
	int v = shop.pop();
	shop.push(HOBT);
	shop.push(10);
	shop.push(HOBT);
	shop.push(0);
	shop.push(v);
	shop.push(30);
	shop.push(3);
	shop.push(7);
	TO[HOBT]=0;
	HOBT++;
	poz++;
}
void SyntAuto::f26()
{
	shop.pop();
	int v = shop.top();
	shop.pop();
	shop.replace(shop.top(),v);
	shop.pop();

}
void SyntAuto::f27()
{
	shop.pop();
	int v = shop.pop();
	shop.push(14);
	shop.push(v+1);
	shop.push(4);
	poz++;
}
void SyntAuto::f28()
{
	shop.pop();
	shop.replace(shop.top(), TL[poz].value);
	shop.pop();
	poz++;
}
void SyntAuto::a()
{
	shop.pop();
	poz++;
}
void SyntAuto::b()
{
	shop.pop();
	shop.replace(shop.top(), TL[poz].value);
	shop.pop();
	poz++;
}
void SyntAuto::c()
{
	atom a = createAtom(1, -1, -1, -1, -1);
	 
	shop.pop();
}
void SyntAuto::d()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	atom a = createAtom(3, p, q, -1, -1);	 
}
void SyntAuto::e()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	int r = shop.top();
	shop.pop();
	int s = shop.top();
	shop.pop();
	atom a = createAtom(7, p, q, r, s);	 
}
void SyntAuto::f()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	atom a = createAtom(8, p, q, -1, -1);	 
}
void SyntAuto::g()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	atom a = createAtom(9, p, -1, -1, -1);	 
}
void SyntAuto::h()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	int r = shop.top();
	shop.pop();
	int v = shop.top();
	shop.pop();
	atom a = createAtom(10, p, q, r, v);	 
}
void SyntAuto::i()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	if (q != p)
		cout << "Переменная NEXT-оператора отлична от переменной FOR-оператора. " <<shop.top()<<" - предполагаемая переменная"<< endl;
	shop.pop();
}
void SyntAuto::j()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	atom a = createAtom(11, p, q, -1, -1);	 
}
void SyntAuto::k()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	atom a = createAtom(4, p, -1, -1, -1);	 

}
void SyntAuto::l()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	int r = shop.top();
	shop.pop();
	atom a = createAtom(12, p, q, r, -1);	 
}
void SyntAuto::m()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	int r = shop.top();
	shop.pop();
	atom a = createAtom(13, p, q, r, -1);	 
}
void SyntAuto::n()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	int r = shop.top();
	shop.pop();
	atom a = createAtom(14, p, q, r, -1);	 
}
void SyntAuto::o()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	int r = shop.top();
	shop.pop();
	atom a = createAtom(15, p, q, r, -1);	 
}
void SyntAuto::p()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	int r = shop.top();
	shop.pop();
	atom a = createAtom(16, p, q, r, -1);	 
}
void SyntAuto::q()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	atom a = createAtom(17, p, q, -1, -1);	 
}
void SyntAuto::r()
{
	shop.pop();
	int p = shop.top();
	shop.pop();
	int q = shop.top();
	shop.pop();
	atom a = createAtom(18, p, q, -1, -1);	 
}