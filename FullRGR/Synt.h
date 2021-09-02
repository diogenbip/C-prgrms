#include <iostream>
#include <map>
#include <vector>
#include <list>
#pragma once
#ifndef Synt_h
#define Synt_H
enum Symbols_st { DIM_V, SEM_SEM, SEM_LET, SEM_IF, SEM_L, SEM_NEXT, SEM_READ, SEM_WRITE, SEM_LAB, SEM_JUMP, SEM_SWITCH, SEM_TROW, SEM_REM, SEM_BREAK, SEM, INT_SEM, MSET_SEM, V_AS, V_SEM, V_COMMA, V_LET, V_IF, V_GOTO, V_L, V_TO, V_READ, V_WRITE, V_LAB, V_JUMP, V_SWITCH, V_RB, V_TROW, V_REM, V_EQ_EQUAL, V_NOT_EQUAL, V_MORE_EQUAL, V_LESS_EQUAL, V_LESS_, V_MORE_, V_PLUS, V_MINUS, V_MULTIPLY, V_DIV, V_MOD, COMMA_V, COMMA_LB, COMMA_C, COMMA_DIF, COMMA_SDIF, COMMA_CROSS, COMMA_UN, LET_V, IF_V, IF_LB, IF_C, IF_DIF, IF_SDIF, IF_CROSS, IF_UN, L_SEM, L_FOR, L_ELSE, READ_V, WRITE_V, WRITE_LB, WRITE_C, WRITE_DIF, WRITE_SDIF, WRITE_CROSS, WRITE_UN, LAB_L, JUMP_L, SWITCH_LB, LB_V, LB_LB, LB_C, LB_DIF, LB_SDIF, LB_CROSS, LB_UN, RB_SEM, RB_COMMA, RB_LET, RB_IF, RB_GOTO, RB_L, RB_TO, RB_READ, RB_WRITE, RB_LAB, RB_JUMP, RB_SWITCH, RB_RB, RB_TROW, RB_REM, RB_EQ_EQUAL, RB_NOT_EQUAL, RB_MORE_EQUAL, RB_LESS_EQUAL, RB_LESS_, RB_MORE_, RB_PLUS, RB_MINUS, RB_MULTIPLY, RB_DIV, RB_MOD, TROW_SEM, REM_SEM, REM_LET, REM_IF, REM_L, REM_READ, REM_WRITE, REM_LAB, REM_JUMP, REM_SWITCH, REM_TROW, REM_REM, CASE_C, C_SEM, C_COMMA, C_LET, C_IF, C_GOTO, C_L, C_TO, C_READ, C_WRITE, C_LAB, C_JUMP, C_SWITCH, C_RB, C_TROW, C_REM, C_EQ_EQUAL, C_NOT_EQUAL, C_MORE_EQUAL, C_LESS_EQUAL, C_LESS_, C_MORE_, C_PLUS, C_MINUS, C_MULTIPLY, C_DIV, C_MOD, EQ_EQUAL_V, EQ_EQUAL_LB, EQ_EQUAL_C, EQ_EQUAL_DIF, EQ_EQUAL_SDIF, EQ_EQUAL_CROSS, EQ_EQUAL_UN, NOT_EQUAL_V, NOT_EQUAL_LB, NOT_EQUAL_C, NOT_EQUAL_DIF, NOT_EQUAL_SDIF, NOT_EQUAL_CROSS, NOT_EQUAL_UN, MORE_EQUAL_V, MORE_EQUAL_LB, MORE_EQUAL_C, MORE_EQUAL_DIF, MORE_EQUAL_SDIF, MORE_EQUAL_CROSS, MORE_EQUAL_UN, LESS_EQUAL_V, LESS_EQUAL_LB, LESS_EQUAL_C, LESS_EQUAL_DIF, LESS_EQUAL_SDIF, LESS_EQUAL_CROSS, LESS_EQUAL_UN, LESS__V, LESS__LB, LESS__C, LESS__DIF, LESS__SDIF, LESS__CROSS, LESS__UN, MORE__V, MORE__LB, MORE__C, MORE__DIF, MORE__SDIF, MORE__CROSS, MORE__UN, ADDING_V, ADDING_LB, ADDING_C, ADDING_DIF, ADDING_SDIF, ADDING_CROSS, ADDING_UN, DIF_LB, SDIF_LB, CROSS_LB, UN_LB, PLUS_V, PLUS_LB, PLUS_C, PLUS_DIF, PLUS_SDIF, PLUS_CROSS, PLUS_UN, MINUS_V, MINUS_LB, MINUS_C, MINUS_DIF, MINUS_SDIF, MINUS_CROSS, MINUS_UN, MULTIPLY_V, MULTIPLY_LB, MULTIPLY_C, MULTIPLY_DIF, MULTIPLY_SDIF, MULTIPLY_CROSS, MULTIPLY_UN, DIV_V, DIV_LB, DIV_C, DIV_DIF, DIV_SDIF, DIV_CROSS, DIV_UN, MOD_V, MOD_LB, MOD_C, MOD_DIF, MOD_SDIF, MOD_CROSS, MOD_UN };
enum Term_st { T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49, T50, T51, T52, T53, T54, T55, T56, T57, T58, T59, T60, T61, T62, T63, T64, T65, T66, T67, T68, T69, T70, T71, T72, T73, T74, T75, T76, T77, T78, T79, T80, T81, T82, T83, T84, T85, T86, T87, T88, T89, T90, T91, T92, T93, T94, T95, T96, T97, T98, T99, T100, T101, T102, T103, T104, T105, T106, T107, T108, T109, T110, T111, T112, T113, T114, T115, T116, T117, T118, T119, T120, T121, T122, T123, T124, T125, T126, T127, T128, T129, DIM_T, AS_T, SEM_T, INT_T, MSET_T, V_T, COMMA_T, LET_T, EQUAL_T, L_T, FOR_T, TO_T, NEXT_T, IF_T, GOTO_T, READ_T, WRITE_T, LAB_T, RAB_T, JUMP_T, SWITCH_T, LB_T, RB_T, END_T, TROW_T, REM_T, CASE_T, C_T, COLON_T, BREAK_T, ELSE_T, EQ_EQUAL_T, NOT_EQUAL_T, MORE_EQUAL_T, LESS_EQUAL_T, LESS__T, MORE__T, ADDING_T, DIF_T, SDIF_T, CROSS_T, UN_T, PLUS_T, MINUS_T, MULTIPLY_T, DIV_T, MOD_T };

const int symbol_st = 233;
const int term_st = 160;

class Synt {
private:
	std::list<std::string> stack;
	std::map<std::string, Symbols_st> symb_id{
		{"dimv",DIM_V},
{"SEMSEM",SEM_SEM},
{"SEMlet",SEM_LET},
{"SEMif",SEM_IF},
{"SEML",SEM_L},
{"SEMnext",SEM_NEXT},
{"SEMread",SEM_READ},
{"SEMwrite",SEM_WRITE},
{"SEMlab",SEM_LAB},
{"SEMjump",SEM_JUMP},
{"SEMswitch",SEM_SWITCH},
{"SEMtrow",SEM_TROW},
{"SEMrem",SEM_REM},
{"SEMbreak",SEM_BREAK},
{"SEM",SEM},
{"intSEM",INT_SEM},
{"msetSEM",MSET_SEM},
{"vas",V_AS},
{"vSEM",V_SEM},
{"vCOMMA",V_COMMA},
{"vlet",V_LET},
{"vif",V_IF},
{"vgoto",V_GOTO},
{"vL",V_L},
{"vto",V_TO},
{"vread",V_READ},
{"vwrite",V_WRITE},
{"vlab",V_LAB},
{"vjump",V_JUMP},
{"vswitch",V_SWITCH},
{"vrb",V_RB},
{"vtrow",V_TROW},
{"vrem",V_REM},
{"vEq_Equal",V_EQ_EQUAL},
{"vNot_Equal",V_NOT_EQUAL},
{"vMore_Equal",V_MORE_EQUAL},
{"vLess_Equal",V_LESS_EQUAL},
{"vLess_",V_LESS_},
{"vMore_",V_MORE_},
{"vPlus",V_PLUS},
{"vMinus",V_MINUS},
{"vMultiply",V_MULTIPLY},
{"vDiv",V_DIV},
{"vMod",V_MOD},
{"COMMAv",COMMA_V},
{"COMMAlb",COMMA_LB},
{"COMMAc",COMMA_C},
{"COMMADif",COMMA_DIF},
{"COMMASDif",COMMA_SDIF},
{"COMMACross",COMMA_CROSS},
{"COMMAUn",COMMA_UN},
{"letv",LET_V},
{"ifv",IF_V},
{"iflb",IF_LB},
{"ifc",IF_C},
{"ifDif",IF_DIF},
{"ifSDif",IF_SDIF},
{"ifCross",IF_CROSS},
{"ifUn",IF_UN},
{"LSEM",L_SEM},
{"Lfor",L_FOR},
{"Lelse",L_ELSE},
{"readv",READ_V},
{"writev",WRITE_V},
{"writelb",WRITE_LB},
{"writec",WRITE_C},
{"writeDif",WRITE_DIF},
{"writeSDif",WRITE_SDIF},
{"writeCross",WRITE_CROSS},
{"writeUn",WRITE_UN},
{"labL",LAB_L},
{"jumpL",JUMP_L},
{"switchlb",SWITCH_LB},
{"lbv",LB_V},
{"lblb",LB_LB},
{"lbc",LB_C},
{"lbDif",LB_DIF},
{"lbSDif",LB_SDIF},
{"lbCross",LB_CROSS},
{"lbUn",LB_UN},
{"rbSEM",RB_SEM},
{"rbCOMMA",RB_COMMA},
{"rblet",RB_LET},
{"rbif",RB_IF},
{"rbgoto",RB_GOTO},
{"rbL",RB_L},
{"rbto",RB_TO},
{"rbread",RB_READ},
{"rbwrite",RB_WRITE},
{"rblab",RB_LAB},
{"rbjump",RB_JUMP},
{"rbswitch",RB_SWITCH},
{"rbrb",RB_RB},
{"rbtrow",RB_TROW},
{"rbrem",RB_REM},
{"rbEq_Equal",RB_EQ_EQUAL},
{"rbNot_Equal",RB_NOT_EQUAL},
{"rbMore_Equal",RB_MORE_EQUAL},
{"rbLess_Equal",RB_LESS_EQUAL},
{"rbLess_",RB_LESS_},
{"rbMore_",RB_MORE_},
{"rbPlus",RB_PLUS},
{"rbMinus",RB_MINUS},
{"rbMultiply",RB_MULTIPLY},
{"rbDiv",RB_DIV},
{"rbMod",RB_MOD},
{"trowSEM",TROW_SEM},
{"remSEM",REM_SEM},
{"remlet",REM_LET},
{"remif",REM_IF},
{"remL",REM_L},
{"remread",REM_READ},
{"remwrite",REM_WRITE},
{"remlab",REM_LAB},
{"remjump",REM_JUMP},
{"remswitch",REM_SWITCH},
{"remtrow",REM_TROW},
{"remrem",REM_REM},
{"casec",CASE_C},
{"cSEM",C_SEM},
{"cCOMMA",C_COMMA},
{"clet",C_LET},
{"cif",C_IF},
{"cgoto",C_GOTO},
{"cL",C_L},
{"cto",C_TO},
{"cread",C_READ},
{"cwrite",C_WRITE},
{"clab",C_LAB},
{"cjump",C_JUMP},
{"cswitch",C_SWITCH},
{"crb",C_RB},
{"ctrow",C_TROW},
{"crem",C_REM},
{"cEq_Equal",C_EQ_EQUAL},
{"cNot_Equal",C_NOT_EQUAL},
{"cMore_Equal",C_MORE_EQUAL},
{"cLess_Equal",C_LESS_EQUAL},
{"cLess_",C_LESS_},
{"cMore_",C_MORE_},
{"cPlus",C_PLUS},
{"cMinus",C_MINUS},
{"cMultiply",C_MULTIPLY},
{"cDiv",C_DIV},
{"cMod",C_MOD},
{"Eq_Equalv",EQ_EQUAL_V},
{"Eq_Equallb",EQ_EQUAL_LB},
{"Eq_Equalc",EQ_EQUAL_C},
{"Eq_EqualDif",EQ_EQUAL_DIF},
{"Eq_EqualSDif",EQ_EQUAL_SDIF},
{"Eq_EqualCross",EQ_EQUAL_CROSS},
{"Eq_EqualUn",EQ_EQUAL_UN},
{"Not_Equalv",NOT_EQUAL_V},
{"Not_Equallb",NOT_EQUAL_LB},
{"Not_Equalc",NOT_EQUAL_C},
{"Not_EqualDif",NOT_EQUAL_DIF},
{"Not_EqualSDif",NOT_EQUAL_SDIF},
{"Not_EqualCross",NOT_EQUAL_CROSS},
{"Not_EqualUn",NOT_EQUAL_UN},
{"More_Equalv",MORE_EQUAL_V},
{"More_Equallb",MORE_EQUAL_LB},
{"More_Equalc",MORE_EQUAL_C},
{"More_EqualDif",MORE_EQUAL_DIF},
{"More_EqualSDif",MORE_EQUAL_SDIF},
{"More_EqualCross",MORE_EQUAL_CROSS},
{"More_EqualUn",MORE_EQUAL_UN},
{"Less_Equalv",LESS_EQUAL_V},
{"Less_Equallb",LESS_EQUAL_LB},
{"Less_Equalc",LESS_EQUAL_C},
{"Less_EqualDif",LESS_EQUAL_DIF},
{"Less_EqualSDif",LESS_EQUAL_SDIF},
{"Less_EqualCross",LESS_EQUAL_CROSS},
{"Less_EqualUn",LESS_EQUAL_UN},
{"Less_v",LESS__V},
{"Less_lb",LESS__LB},
{"Less_c",LESS__C},
{"Less_Dif",LESS__DIF},
{"Less_SDif",LESS__SDIF},
{"Less_Cross",LESS__CROSS},
{"Less_Un",LESS__UN},
{"More_v",MORE__V},
{"More_lb",MORE__LB},
{"More_c",MORE__C},
{"More_Dif",MORE__DIF},
{"More_SDif",MORE__SDIF},
{"More_Cross",MORE__CROSS},
{"More_Un",MORE__UN},
{"addingv",ADDING_V},
{"addinglb",ADDING_LB},
{"addingc",ADDING_C},
{"addingDif",ADDING_DIF},
{"addingSDif",ADDING_SDIF},
{"addingCross",ADDING_CROSS},
{"addingUn",ADDING_UN},
{"Diflb",DIF_LB},
{"SDiflb",SDIF_LB},
{"Crosslb",CROSS_LB},
{"Unlb",UN_LB},
{"Plusv",PLUS_V},
{"Pluslb",PLUS_LB},
{"Plusc",PLUS_C},
{"PlusDif",PLUS_DIF},
{"PlusSDif",PLUS_SDIF},
{"PlusCross",PLUS_CROSS},
{"PlusUn",PLUS_UN},
{"Minusv",MINUS_V},
{"Minuslb",MINUS_LB},
{"Minusc",MINUS_C},
{"MinusDif",MINUS_DIF},
{"MinusSDif",MINUS_SDIF},
{"MinusCross",MINUS_CROSS},
{"MinusUn",MINUS_UN},
{"Multiplyv",MULTIPLY_V},
{"Multiplylb",MULTIPLY_LB},
{"Multiplyc",MULTIPLY_C},
{"MultiplyDif",MULTIPLY_DIF},
{"MultiplySDif",MULTIPLY_SDIF},
{"MultiplyCross",MULTIPLY_CROSS},
{"MultiplyUn",MULTIPLY_UN},
{"Divv",DIV_V},
{"Divlb",DIV_LB},
{"Divc",DIV_C},
{"DivDif",DIV_DIF},
{"DivSDif",DIV_SDIF},
{"DivCross",DIV_CROSS},
{"DivUn",DIV_UN},
{"Modv",MOD_V},
{"Modlb",MOD_LB},
{"Modc",MOD_C},
{"ModDif",MOD_DIF},
{"ModSDif",MOD_SDIF}
	};
	std::map<std::string, Term_st> tof_id{
		{"T0",T0},
{"T1",T1},
{"T2",T2},
{"T3",T3},
{"T4",T4},
{"T5",T5},
{"T6",T6},
{"T7",T7},
{"T8",T8},
{"T9",T9},
{"T10",T10},
{"T11",T11},
{"T12",T12},
{"T13",T13},
{"T14",T14},
{"T15",T15},
{"T16",T16},
{"T17",T17},
{"T18",T18},
{"T19",T19},
{"T20",T20},
{"T21",T21},
{"T22",T22},
{"T23",T23},
{"T24",T24},
{"T25",T25},
{"T26",T26},
{"T27",T27},
{"T28",T28},
{"T29",T29},
{"T30",T30},
{"T31",T31},
{"T32",T32},
{"T33",T33},
{"T34",T34},
{"T35",T35},
{"T36",T36},
{"T37",T37},
{"T38",T38},
{"T39",T39},
{"T40",T40},
{"T41",T41},
{"T42",T42},
{"T43",T43},
{"T44",T44},
{"T45",T45},
{"T46",T46},
{"T47",T47},
{"T48",T48},
{"T49",T49},
{"T50",T50},
{"T51",T51},
{"T52",T52},
{"T53",T53},
{"T54",T54},
{"T55",T55},
{"T56",T56},
{"T57",T57},
{"T58",T58},
{"T59",T59},
{"T60",T60},
{"T61",T61},
{"T62",T62},
{"T63",T63},
{"T64",T64},
{"T65",T65},
{"T66",T66},
{"T67",T67},
{"T68",T68},
{"T69",T69},
{"T70",T70},
{"T71",T71},
{"T72",T72},
{"T73",T73},
{"T74",T74},
{"T75",T75},
{"T76",T76},
{"T77",T77},
{"T78",T78},
{"T79",T79},
{"T80",T80},
{"T81",T81},
{"T82",T82},
{"T83",T83},
{"T84",T84},
{"T85",T85},
{"T86",T86},
{"T87",T87},
{"T88",T88},
{"T89",T89},
{"T90",T90},
{"T91",T91},
{"T92",T92},
{"T93",T93},
{"T94",T94},
{"T95",T95},
{"T96",T96},
{"T97",T97},
{"T98",T98},
{"T99",T99},
{"T100",T100},
{"T101",T101},
{"T102",T102},
{"T103",T103},
{"T104",T104},
{"T105",T105},
{"T106",T106},
{"T107",T107},
{"T108",T108},
{"T109",T109},
{"T110",T110},
{"T111",T111},
{"T112",T112},
{ "T113",T113 },
{ "T114",T114 },
{ "T115",T115 },
{ "T116",T116 },
{ "T117",T117 },
{ "T118",T118 },
{ "T119",T119 },
{ "T120",T120 },
{ "T121",T121 },
{ "T122",T122 },
{ "T123",T123 },
{ "T124",T124 },
{ "T125",T125 },
{ "T126",T126 },
{ "T127",T127 },
{ "T128",T128 },
{ "T129",T129 },
{ "dim",DIM_T },
{ "as",AS_T },
{ "SEM",SEM_T },
{ "int",INT_T },
{ "mset",MSET_T },
{ "v",V_T },
{ "COMMA",COMMA_T },
{ "let",LET_T },
{ "Equal",EQUAL_T },
{ "L",L_T },
{ "for",FOR_T },
{ "to",TO_T },
{ "next",NEXT_T },
{ "if",IF_T },
{ "goto",GOTO_T },
{ "read",READ_T },
{ "write",WRITE_T },
{ "lab",LAB_T },
{ "rab",RAB_T },
{ "jump",JUMP_T },
{ "switch",SWITCH_T },
{ "lb",LB_T },
{ "rb",RB_T },
{ "end",END_T },
{ "trow",TROW_T },
{ "rem",REM_T },
{ "case",CASE_T },
{ "c",C_T },
{ "COLON",COLON_T },
{ "break",BREAK_T },
{ "else",ELSE_T },
{ "Eq_Equal",EQ_EQUAL_T },
{ "Not_Equal",NOT_EQUAL_T },
{ "More_Equal",MORE_EQUAL_T },
{ "Less_Equal",LESS_EQUAL_T },
{ "Less_",LESS__T },
{ "More_",MORE__T },
{ "adding",ADDING_T },
{ "Dif",DIF_T },
{ "SDif",SDIF_T },
{ "Cross",CROSS_T },
{ "Un",UN_T },
{ "Plus",PLUS_T },
{ "Minus",MINUS_T },
{ "Multiply",MULTIPLY_T },
{ "Div",DIV_T },
{ "Mod",MOD_T }
	};
	typedef void (Synt::* function_pointer)();
	function_pointer table[symbol_st][term_st];



	std::vector<std::string> lexStack;
	std::string symbol[2];
	int i;
	public:
		Synt();
		~Synt();
		void Start(std::vector<std::string> lex_);

		void f1() {
			stack.pop_front();
			stack.push_front("T2");
			stack.push_front("T1");
		}
		void f2() {
			stack.pop_front();
			stack.push_front("SEM");
			stack.push_front("T4");
			stack.push_front("as");
			stack.push_front("T3");
			stack.push_front("dim");
		}
		void f3() {
			stack.pop_front();
			stack.push_front("T2");
			stack.push_front("T1");
		}
		void f4() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f5() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f6() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f7() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f8() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f9() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f10() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f11() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f12() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f13() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f14() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f15() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f16() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f17() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f18() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f19() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f20() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f21() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f22() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f23() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f24() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f25() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f26() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f27() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f28() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f29() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f30() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f31() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f32() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f33() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f34() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f35() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f36() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f37() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f38() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f39() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f40() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f41() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f42() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f43() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f44() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f45() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f46() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f47() {
			stack.pop_front();
			stack.push_front("T5");
		}
		void f48() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f49() {
			stack.pop_front();
			stack.push_front("T3");
			stack.push_front("COMMA");
			stack.push_front("v");
		}
		void f50() {
			stack.pop_front();
			stack.push_front("int");
		}
		void f51() {
			stack.pop_front();
			stack.push_front("mset");
		}
		void f52() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f53() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f54() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f55() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f56() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f57() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f58() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f59() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f60() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f61() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f62() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f63() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f64() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("T7");
			stack.push_front("Equal");
			stack.push_front("v");
			stack.push_front("let");
		}
		void f65() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("T11");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f66() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("T11");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f67() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("T11");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f68() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("T11");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f69() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("T11");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f70() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("T11");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f71() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("T11");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f72() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("L");
			stack.push_front("next");
			stack.push_front("T14");
			stack.push_front("T13");
			stack.push_front("to");
			stack.push_front("T12");
			stack.push_front("Equal");
			stack.push_front("v");
			stack.push_front("for");
			stack.push_front("L");
		}
		void f73() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("T15");
			stack.push_front("read");
		}
		void f74() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("write");
		}
		void f75() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("write");
		}
		void f76() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("write");
		}
		void f77() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("write");
		}
		void f78() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("write");
		}
		void f79() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("write");
		}
		void f80() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("write");
		}
		void f81() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rab");
			stack.push_front("L");
			stack.push_front("lab");
		}
		void f82() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("L");
			stack.push_front("jump");
		}
		void f83() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("switch");
			stack.push_front("end");
			stack.push_front("T19");
			stack.push_front("rb");
			stack.push_front("T18");
			stack.push_front("lb");
			stack.push_front("switch");
		}
		void f84() {
			stack.pop_front();
			stack.push_front("T6");
			stack.push_front("trow");
		}
		void f85() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rem");
		}
		void f86() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rem");
		}
		void f87() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rem");
		}
		void f88() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rem");
		}
		void f89() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rem");
		}
		void f90() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rem");
		}
		void f91() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rem");
		}
		void f92() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rem");
		}
		void f93() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rem");
		}
		void f94() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rem");
		}
		void f95() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("rem");
		}
		void f96() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("SEM");
		}
		void f97() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("SEM");
		}
		void f98() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("SEM");
		}
		void f99() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("SEM");
		}
		void f100() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("SEM");
		}
		void f101() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("SEM");
		}
		void f102() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("SEM");
		}
		void f103() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("SEM");
		}
		void f104() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("SEM");
		}
		void f105() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("SEM");
		}
		void f106() {
			stack.pop_front();
			stack.push_front("T5");
			stack.push_front("SEM");
		}
		void f107() {
			stack.pop_front();
			stack.push_front("SEM");
		}
		void f108() {
			stack.pop_front();
			stack.push_front("T20");
		}
		void f109() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T23");
		}
		void f110() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T23");
		}
		void f111() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T23");
		}
		void f112() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T23");
		}
		void f113() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T23");
		}
		void f114() {
			stack.pop_front();
			stack.push_front("T22");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f115() {
			stack.pop_front();
			stack.push_front("T22");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f116() {
			stack.pop_front();
			stack.push_front("T22");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f117() {
			stack.pop_front();
			stack.push_front("T22");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f118() {
			stack.pop_front();
			stack.push_front("T22");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f119() {
			stack.pop_front();
			stack.push_front("T22");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f120() {
			stack.pop_front();
			stack.push_front("T22");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f121() {
			stack.pop_front();
			stack.push_front("T20");
		}
		void f122() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T23");
		}
		void f123() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T23");
		}
		void f124() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T23");
		}
		void f125() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T23");
		}
		void f126() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T23");
		}
		void f127() {
			stack.pop_front();
			stack.push_front("T24");
		}
		void f128() {
			stack.pop_front();
			stack.push_front("T24");
		}
		void f129() {
			stack.pop_front();
			stack.push_front("T24");
		}
		void f130() {
			stack.pop_front();
			stack.push_front("T24");
		}
		void f131() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f132() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f133() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f134() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f135() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f136() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f137() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T28");
		}
		void f138() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T28");
		}
		void f139() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T28");
		}
		void f140() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T28");
		}
		void f141() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T28");
		}
		void f142() {
			stack.pop_front();
			stack.push_front("T27");
			stack.push_front("T26");
			stack.push_front("lb");
		}
		void f143() {
			stack.pop_front();
			stack.push_front("T27");
			stack.push_front("T26");
			stack.push_front("lb");
		}
		void f144() {
			stack.pop_front();
			stack.push_front("T27");
			stack.push_front("T26");
			stack.push_front("lb");
		}
		void f145() {
			stack.pop_front();
			stack.push_front("T27");
			stack.push_front("T26");
			stack.push_front("lb");
		}
		void f146() {
			stack.pop_front();
			stack.push_front("T27");
			stack.push_front("T26");
			stack.push_front("lb");
		}
		void f147() {
			stack.pop_front();
			stack.push_front("T27");
			stack.push_front("T26");
			stack.push_front("lb");
		}
		void f148() {
			stack.pop_front();
			stack.push_front("T27");
			stack.push_front("T26");
			stack.push_front("lb");
		}
		void f149() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f150() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f151() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f152() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f153() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f154() {
			stack.pop_front();
			stack.push_front("T25");
		}
		void f155() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T28");
		}
		void f156() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T28");
		}
		void f157() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T28");
		}
		void f158() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T28");
		}
		void f159() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T28");
		}
		void f160() {
			stack.pop_front();
			stack.push_front("T29");
		}
		void f161() {
			stack.pop_front();
			stack.push_front("T29");
		}
		void f162() {
			stack.pop_front();
			stack.push_front("T29");
		}
		void f163() {
			stack.pop_front();
			stack.push_front("T29");
		}
		void f164() {
			stack.pop_front();
			stack.push_front("Eq_Equal");
		}
		void f165() {
			stack.pop_front();
			stack.push_front("Eq_Equal");
		}
		void f166() {
			stack.pop_front();
			stack.push_front("Eq_Equal");
		}
		void f167() {
			stack.pop_front();
			stack.push_front("Eq_Equal");
		}
		void f168() {
			stack.pop_front();
			stack.push_front("Eq_Equal");
		}
		void f169() {
			stack.pop_front();
			stack.push_front("Eq_Equal");
		}
		void f170() {
			stack.pop_front();
			stack.push_front("Eq_Equal");
		}
		void f171() {
			stack.pop_front();
			stack.push_front("Not_Equal");
		}
		void f172() {
			stack.pop_front();
			stack.push_front("Not_Equal");
		}
		void f173() {
			stack.pop_front();
			stack.push_front("Not_Equal");
		}
		void f174() {
			stack.pop_front();
			stack.push_front("Not_Equal");
		}
		void f175() {
			stack.pop_front();
			stack.push_front("Not_Equal");
		}
		void f176() {
			stack.pop_front();
			stack.push_front("Not_Equal");
		}
		void f177() {
			stack.pop_front();
			stack.push_front("Not_Equal");
		}
		void f178() {
			stack.pop_front();
			stack.push_front("More_Equal");
		}
		void f179() {
			stack.pop_front();
			stack.push_front("More_Equal");
		}
		void f180() {
			stack.pop_front();
			stack.push_front("More_Equal");
		}
		void f181() {
			stack.pop_front();
			stack.push_front("More_Equal");
		}
		void f182() {
			stack.pop_front();
			stack.push_front("More_Equal");
		}
		void f183() {
			stack.pop_front();
			stack.push_front("More_Equal");
		}
		void f184() {
			stack.pop_front();
			stack.push_front("More_Equal");
		}
		void f185() {
			stack.pop_front();
			stack.push_front("Less_Equal");
		}
		void f186() {
			stack.pop_front();
			stack.push_front("Less_Equal");
		}
		void f187() {
			stack.pop_front();
			stack.push_front("Less_Equal");
		}
		void f188() {
			stack.pop_front();
			stack.push_front("Less_Equal");
		}
		void f189() {
			stack.pop_front();
			stack.push_front("Less_Equal");
		}
		void f190() {
			stack.pop_front();
			stack.push_front("Less_Equal");
		}
		void f191() {
			stack.pop_front();
			stack.push_front("Less_Equal");
		}
		void f192() {
			stack.pop_front();
			stack.push_front("Less_");
		}
		void f193() {
			stack.pop_front();
			stack.push_front("Less_");
		}
		void f194() {
			stack.pop_front();
			stack.push_front("Less_");
		}
		void f195() {
			stack.pop_front();
			stack.push_front("Less_");
		}
		void f196() {
			stack.pop_front();
			stack.push_front("Less_");
		}
		void f197() {
			stack.pop_front();
			stack.push_front("Less_");
		}
		void f198() {
			stack.pop_front();
			stack.push_front("Less_");
		}
		void f199() {
			stack.pop_front();
			stack.push_front("More_");
		}
		void f200() {
			stack.pop_front();
			stack.push_front("More_");
		}
		void f201() {
			stack.pop_front();
			stack.push_front("More_");
		}
		void f202() {
			stack.pop_front();
			stack.push_front("More_");
		}
		void f203() {
			stack.pop_front();
			stack.push_front("More_");
		}
		void f204() {
			stack.pop_front();
			stack.push_front("More_");
		}
		void f205() {
			stack.pop_front();
			stack.push_front("More_");
		}
		void f206() {
			stack.pop_front();
			stack.push_front("T30");
		}
		void f207() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T33");
		}
		void f208() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T33");
		}
		void f209() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T33");
		}
		void f210() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T33");
		}
		void f211() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T33");
		}
		void f212() {
			stack.pop_front();
			stack.push_front("T32");
			stack.push_front("T31");
			stack.push_front("lb");
		}
		void f213() {
			stack.pop_front();
			stack.push_front("T32");
			stack.push_front("T31");
			stack.push_front("lb");
		}
		void f214() {
			stack.pop_front();
			stack.push_front("T32");
			stack.push_front("T31");
			stack.push_front("lb");
		}
		void f215() {
			stack.pop_front();
			stack.push_front("T32");
			stack.push_front("T31");
			stack.push_front("lb");
		}
		void f216() {
			stack.pop_front();
			stack.push_front("T32");
			stack.push_front("T31");
			stack.push_front("lb");
		}
		void f217() {
			stack.pop_front();
			stack.push_front("T32");
			stack.push_front("T31");
			stack.push_front("lb");
		}
		void f218() {
			stack.pop_front();
			stack.push_front("T32");
			stack.push_front("T31");
			stack.push_front("lb");
		}
		void f219() {
			stack.pop_front();
			stack.push_front("T30");
		}
		void f220() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T33");
		}
		void f221() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T33");
		}
		void f222() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T33");
		}
		void f223() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T33");
		}
		void f224() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T33");
		}
		void f225() {
			stack.pop_front();
			stack.push_front("T34");
		}
		void f226() {
			stack.pop_front();
			stack.push_front("T34");
		}
		void f227() {
			stack.pop_front();
			stack.push_front("T34");
		}
		void f228() {
			stack.pop_front();
			stack.push_front("T34");
		}
		void f229() {
			stack.pop_front();
			stack.push_front("L");
		}
		void f230() {
			stack.pop_front();
			stack.push_front("L");
			stack.push_front("goto");
			stack.push_front("else");
			stack.push_front("L");
		}
		void f231() {
			stack.pop_front();
			stack.push_front("T35");
		}
		void f232() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T38");
		}
		void f233() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T38");
		}
		void f234() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T38");
		}
		void f235() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T38");
		}
		void f236() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T38");
		}
		void f237() {
			stack.pop_front();
			stack.push_front("T37");
			stack.push_front("T36");
			stack.push_front("lb");
		}
		void f238() {
			stack.pop_front();
			stack.push_front("T37");
			stack.push_front("T36");
			stack.push_front("lb");
		}
		void f239() {
			stack.pop_front();
			stack.push_front("T37");
			stack.push_front("T36");
			stack.push_front("lb");
		}
		void f240() {
			stack.pop_front();
			stack.push_front("T37");
			stack.push_front("T36");
			stack.push_front("lb");
		}
		void f241() {
			stack.pop_front();
			stack.push_front("T37");
			stack.push_front("T36");
			stack.push_front("lb");
		}
		void f242() {
			stack.pop_front();
			stack.push_front("T37");
			stack.push_front("T36");
			stack.push_front("lb");
		}
		void f243() {
			stack.pop_front();
			stack.push_front("T37");
			stack.push_front("T36");
			stack.push_front("lb");
		}
		void f244() {
			stack.pop_front();
			stack.push_front("T35");
		}
		void f245() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T38");
		}
		void f246() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T38");
		}
		void f247() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T38");
		}
		void f248() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T38");
		}
		void f249() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T38");
		}
		void f250() {
			stack.pop_front();
			stack.push_front("T39");
		}
		void f251() {
			stack.pop_front();
			stack.push_front("T39");
		}
		void f252() {
			stack.pop_front();
			stack.push_front("T39");
		}
		void f253() {
			stack.pop_front();
			stack.push_front("T39");
		}
		void f254() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f255() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f256() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f257() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f258() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f259() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f260() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f261() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f262() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f263() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f264() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f265() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f266() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f267() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f268() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f269() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f270() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f271() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f272() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f273() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f274() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f275() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f276() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f277() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f278() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f279() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f280() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f281() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f282() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f283() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f284() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f285() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f286() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f287() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f288() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f289() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f290() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f291() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f292() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f293() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("adding");
		}
		void f294() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("adding");
		}
		void f295() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("adding");
		}
		void f296() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("adding");
		}
		void f297() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("adding");
		}
		void f298() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("adding");
		}
		void f299() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("adding");
		}
		void f300() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f301() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f302() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f303() {
			stack.pop_front();
			stack.push_front("T40");
		}
		void f304() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f305() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f306() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f307() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f308() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f309() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f310() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f311() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f312() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f313() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f314() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f315() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f316() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("T42");
			stack.push_front("Equal");
			stack.push_front("v");
			stack.push_front("let");
		}
		void f317() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("T43");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f318() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("T43");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f319() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("T43");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f320() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("T43");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f321() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("T43");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f322() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("T43");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f323() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("T43");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f324() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("L");
			stack.push_front("next");
			stack.push_front("T14");
			stack.push_front("T13");
			stack.push_front("to");
			stack.push_front("T12");
			stack.push_front("Equal");
			stack.push_front("v");
			stack.push_front("for");
			stack.push_front("L");
		}
		void f325() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("T44");
			stack.push_front("read");
		}
		void f326() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("write");
		}
		void f327() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("write");
		}
		void f328() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("write");
		}
		void f329() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("write");
		}
		void f330() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("write");
		}
		void f331() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("write");
		}
		void f332() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("write");
		}
		void f333() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rab");
			stack.push_front("L");
			stack.push_front("lab");
		}
		void f334() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("L");
			stack.push_front("jump");
		}
		void f335() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("switch");
			stack.push_front("end");
			stack.push_front("T19");
			stack.push_front("rb");
			stack.push_front("T18");
			stack.push_front("lb");
			stack.push_front("switch");
		}
		void f336() {
			stack.pop_front();
			stack.push_front("T41");
			stack.push_front("trow");
		}
		void f337() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rem");
		}
		void f338() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rem");
		}
		void f339() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rem");
		}
		void f340() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rem");
		}
		void f341() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rem");
		}
		void f342() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rem");
		}
		void f343() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rem");
		}
		void f344() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rem");
		}
		void f345() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rem");
		}
		void f346() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rem");
		}
		void f347() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("rem");
		}
		void f348() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f349() {
			stack.pop_front();
			stack.push_front("T15");
			stack.push_front("COMMA");
			stack.push_front("v");
		}
		void f350() {
			stack.pop_front();
			stack.push_front("T47");
		}
		void f351() {
			stack.pop_front();
			stack.push_front("T47");
		}
		void f352() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T50");
		}
		void f353() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T50");
		}
		void f354() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T50");
		}
		void f355() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T50");
		}
		void f356() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T50");
		}
		void f357() {
			stack.pop_front();
			stack.push_front("T49");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f358() {
			stack.pop_front();
			stack.push_front("T49");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f359() {
			stack.pop_front();
			stack.push_front("T49");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f360() {
			stack.pop_front();
			stack.push_front("T49");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f361() {
			stack.pop_front();
			stack.push_front("T49");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f362() {
			stack.pop_front();
			stack.push_front("T49");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f363() {
			stack.pop_front();
			stack.push_front("T49");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f364() {
			stack.pop_front();
			stack.push_front("T47");
		}
		void f365() {
			stack.pop_front();
			stack.push_front("T47");
		}
		void f366() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T50");
		}
		void f367() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T50");
		}
		void f368() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T50");
		}
		void f369() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T50");
		}
		void f370() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T50");
		}
		void f371() {
			stack.pop_front();
			stack.push_front("T51");
		}
		void f372() {
			stack.pop_front();
			stack.push_front("T51");
		}
		void f373() {
			stack.pop_front();
			stack.push_front("T51");
		}
		void f374() {
			stack.pop_front();
			stack.push_front("T51");
		}
		void f375() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f376() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f377() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f378() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f379() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f380() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f381() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f382() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f383() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f384() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f385() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f386() {
			stack.pop_front();
			stack.push_front("T6");
		}
		void f387() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("COMMA");
		}
		void f388() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("COMMA");
		}
		void f389() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("COMMA");
		}
		void f390() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("COMMA");
		}
		void f391() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("COMMA");
		}
		void f392() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("COMMA");
		}
		void f393() {
			stack.pop_front();
			stack.push_front("T17");
			stack.push_front("T16");
			stack.push_front("COMMA");
		}
		void f394() {
			stack.pop_front();
			stack.push_front("T52");
		}
		void f395() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T55");
		}
		void f396() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T55");
		}
		void f397() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T55");
		}
		void f398() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T55");
		}
		void f399() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T55");
		}
		void f400() {
			stack.pop_front();
			stack.push_front("T54");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f401() {
			stack.pop_front();
			stack.push_front("T54");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f402() {
			stack.pop_front();
			stack.push_front("T54");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f403() {
			stack.pop_front();
			stack.push_front("T54");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f404() {
			stack.pop_front();
			stack.push_front("T54");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f405() {
			stack.pop_front();
			stack.push_front("T54");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f406() {
			stack.pop_front();
			stack.push_front("T54");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f407() {
			stack.pop_front();
			stack.push_front("T52");
		}
		void f408() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T55");
		}
		void f409() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T55");
		}
		void f410() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T55");
		}
		void f411() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T55");
		}
		void f412() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T55");
		}
		void f413() {
			stack.pop_front();
			stack.push_front("T56");
		}
		void f414() {
			stack.pop_front();
			stack.push_front("T56");
		}
		void f415() {
			stack.pop_front();
			stack.push_front("T56");
		}
		void f416() {
			stack.pop_front();
			stack.push_front("T56");
		}
		void f417() {
			stack.pop_front();
			stack.push_front("T19");
			stack.push_front("break");
			stack.push_front("T57");
			stack.push_front("COLON");
			stack.push_front("c");
			stack.push_front("case");
		}
		void f418() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f419() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f420() {
			stack.pop_front();
			stack.push_front("T58");
		}
		void f421() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T55");
		}
		void f422() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T55");
		}
		void f423() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T55");
		}
		void f424() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T55");
		}
		void f425() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T55");
		}
		void f426() {
			stack.pop_front();
			stack.push_front("T59");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f427() {
			stack.pop_front();
			stack.push_front("T59");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f428() {
			stack.pop_front();
			stack.push_front("T59");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f429() {
			stack.pop_front();
			stack.push_front("T59");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f430() {
			stack.pop_front();
			stack.push_front("T59");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f431() {
			stack.pop_front();
			stack.push_front("T59");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f432() {
			stack.pop_front();
			stack.push_front("T59");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f433() {
			stack.pop_front();
			stack.push_front("T58");
		}
		void f434() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T55");
		}
		void f435() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T55");
		}
		void f436() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T55");
		}
		void f437() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T55");
		}
		void f438() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T55");
		}
		void f439() {
			stack.pop_front();
			stack.push_front("T60");
		}
		void f440() {
			stack.pop_front();
			stack.push_front("T60");
		}
		void f441() {
			stack.pop_front();
			stack.push_front("T60");
		}
		void f442() {
			stack.pop_front();
			stack.push_front("T60");
		}
		void f443() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f444() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T61");
			stack.push_front("rb");
		}
		void f445() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T61");
			stack.push_front("rb");
		}
		void f446() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T62");
			stack.push_front("rb");
		}
		void f447() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T62");
			stack.push_front("rb");
		}
		void f448() {
			stack.pop_front();
			stack.push_front("T7");
			stack.push_front("T62");
			stack.push_front("rb");
		}
		void f449() {
			stack.pop_front();
			stack.push_front("T61");
			stack.push_front("T63");
		}
		void f450() {
			stack.pop_front();
			stack.push_front("T61");
			stack.push_front("T63");
		}
		void f451() {
			stack.pop_front();
			stack.push_front("T62");
			stack.push_front("T64");
		}
		void f452() {
			stack.pop_front();
			stack.push_front("T62");
			stack.push_front("T64");
		}
		void f453() {
			stack.pop_front();
			stack.push_front("T62");
			stack.push_front("T64");
		}
		void f454() {
			stack.pop_front();
			stack.push_front("T61");
			stack.push_front("T63");
		}
		void f455() {
			stack.pop_front();
			stack.push_front("T61");
			stack.push_front("T63");
		}
		void f456() {
			stack.pop_front();
			stack.push_front("T62");
			stack.push_front("T64");
		}
		void f457() {
			stack.pop_front();
			stack.push_front("T62");
			stack.push_front("T64");
		}
		void f458() {
			stack.pop_front();
			stack.push_front("T62");
			stack.push_front("T64");
		}
		void f459() {
			stack.pop_front();
			stack.push_front("T22");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f460() {
			stack.pop_front();
			stack.push_front("T22");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f461() {
			stack.pop_front();
			stack.push_front("T22");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f462() {
			stack.pop_front();
			stack.push_front("T22");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f463() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f464() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f465() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f466() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f467() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f468() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f469() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f470() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f471() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f472() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f473() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f474() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f475() {
			stack.pop_front();
			stack.push_front("T67");
		}
		void f476() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T55");
		}
		void f477() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T55");
		}
		void f478() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T55");
		}
		void f479() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T55");
		}
		void f480() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T55");
		}
		void f481() {
			stack.pop_front();
			stack.push_front("T68");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f482() {
			stack.pop_front();
			stack.push_front("T68");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f483() {
			stack.pop_front();
			stack.push_front("T68");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f484() {
			stack.pop_front();
			stack.push_front("T68");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f485() {
			stack.pop_front();
			stack.push_front("T68");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f486() {
			stack.pop_front();
			stack.push_front("T68");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f487() {
			stack.pop_front();
			stack.push_front("T68");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f488() {
			stack.pop_front();
			stack.push_front("T67");
		}
		void f489() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T55");
		}
		void f490() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T55");
		}
		void f491() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T55");
		}
		void f492() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T55");
		}
		void f493() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T55");
		}
		void f494() {
			stack.pop_front();
			stack.push_front("T69");
		}
		void f495() {
			stack.pop_front();
			stack.push_front("T69");
		}
		void f496() {
			stack.pop_front();
			stack.push_front("T69");
		}
		void f497() {
			stack.pop_front();
			stack.push_front("T69");
		}
		void f498() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f499() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f500() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f501() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f502() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f503() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f504() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T70");
			stack.push_front("rb");
		}
		void f505() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T70");
			stack.push_front("rb");
		}
		void f506() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T71");
			stack.push_front("rb");
		}
		void f507() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T71");
			stack.push_front("rb");
		}
		void f508() {
			stack.pop_front();
			stack.push_front("T8");
			stack.push_front("T71");
			stack.push_front("rb");
		}
		void f509() {
			stack.pop_front();
			stack.push_front("T70");
			stack.push_front("T63");
		}
		void f510() {
			stack.pop_front();
			stack.push_front("T70");
			stack.push_front("T63");
		}
		void f511() {
			stack.pop_front();
			stack.push_front("T71");
			stack.push_front("T64");
		}
		void f512() {
			stack.pop_front();
			stack.push_front("T71");
			stack.push_front("T64");
		}
		void f513() {
			stack.pop_front();
			stack.push_front("T71");
			stack.push_front("T64");
		}
		void f514() {
			stack.pop_front();
			stack.push_front("T70");
			stack.push_front("T63");
		}
		void f515() {
			stack.pop_front();
			stack.push_front("T70");
			stack.push_front("T63");
		}
		void f516() {
			stack.pop_front();
			stack.push_front("T71");
			stack.push_front("T64");
		}
		void f517() {
			stack.pop_front();
			stack.push_front("T71");
			stack.push_front("T64");
		}
		void f518() {
			stack.pop_front();
			stack.push_front("T71");
			stack.push_front("T64");
		}
		void f519() {
			stack.pop_front();
			stack.push_front("T27");
			stack.push_front("T26");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f520() {
			stack.pop_front();
			stack.push_front("T27");
			stack.push_front("T26");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f521() {
			stack.pop_front();
			stack.push_front("T27");
			stack.push_front("T26");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f522() {
			stack.pop_front();
			stack.push_front("T27");
			stack.push_front("T26");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f523() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f524() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f525() {
			stack.pop_front();
			stack.push_front("T72");
		}
		void f526() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T55");
		}
		void f527() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T55");
		}
		void f528() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T55");
		}
		void f529() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T55");
		}
		void f530() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T55");
		}
		void f531() {
			stack.pop_front();
			stack.push_front("T73");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f532() {
			stack.pop_front();
			stack.push_front("T73");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f533() {
			stack.pop_front();
			stack.push_front("T73");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f534() {
			stack.pop_front();
			stack.push_front("T73");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f535() {
			stack.pop_front();
			stack.push_front("T73");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f536() {
			stack.pop_front();
			stack.push_front("T73");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f537() {
			stack.pop_front();
			stack.push_front("T73");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f538() {
			stack.pop_front();
			stack.push_front("T72");
		}
		void f539() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T55");
		}
		void f540() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T55");
		}
		void f541() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T55");
		}
		void f542() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T55");
		}
		void f543() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T55");
		}
		void f544() {
			stack.pop_front();
			stack.push_front("T74");
		}
		void f545() {
			stack.pop_front();
			stack.push_front("T74");
		}
		void f546() {
			stack.pop_front();
			stack.push_front("T74");
		}
		void f547() {
			stack.pop_front();
			stack.push_front("T74");
		}
		void f548() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f549() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T75");
			stack.push_front("rb");
		}
		void f550() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T75");
			stack.push_front("rb");
		}
		void f551() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T76");
			stack.push_front("rb");
		}
		void f552() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T76");
			stack.push_front("rb");
		}
		void f553() {
			stack.pop_front();
			stack.push_front("T10");
			stack.push_front("T76");
			stack.push_front("rb");
		}
		void f554() {
			stack.pop_front();
			stack.push_front("T75");
			stack.push_front("T63");
		}
		void f555() {
			stack.pop_front();
			stack.push_front("T75");
			stack.push_front("T63");
		}
		void f556() {
			stack.pop_front();
			stack.push_front("T76");
			stack.push_front("T64");
		}
		void f557() {
			stack.pop_front();
			stack.push_front("T76");
			stack.push_front("T64");
		}
		void f558() {
			stack.pop_front();
			stack.push_front("T76");
			stack.push_front("T64");
		}
		void f559() {
			stack.pop_front();
			stack.push_front("T75");
			stack.push_front("T63");
		}
		void f560() {
			stack.pop_front();
			stack.push_front("T75");
			stack.push_front("T63");
		}
		void f561() {
			stack.pop_front();
			stack.push_front("T76");
			stack.push_front("T64");
		}
		void f562() {
			stack.pop_front();
			stack.push_front("T76");
			stack.push_front("T64");
		}
		void f563() {
			stack.pop_front();
			stack.push_front("T76");
			stack.push_front("T64");
		}
		void f564() {
			stack.pop_front();
			stack.push_front("T32");
			stack.push_front("T31");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f565() {
			stack.pop_front();
			stack.push_front("T32");
			stack.push_front("T31");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f566() {
			stack.pop_front();
			stack.push_front("T32");
			stack.push_front("T31");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f567() {
			stack.pop_front();
			stack.push_front("T32");
			stack.push_front("T31");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f568() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f569() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f570() {
			stack.pop_front();
			stack.push_front("T77");
		}
		void f571() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T55");
		}
		void f572() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T55");
		}
		void f573() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T55");
		}
		void f574() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T55");
		}
		void f575() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T55");
		}
		void f576() {
			stack.pop_front();
			stack.push_front("T78");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f577() {
			stack.pop_front();
			stack.push_front("T78");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f578() {
			stack.pop_front();
			stack.push_front("T78");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f579() {
			stack.pop_front();
			stack.push_front("T78");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f580() {
			stack.pop_front();
			stack.push_front("T78");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f581() {
			stack.pop_front();
			stack.push_front("T78");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f582() {
			stack.pop_front();
			stack.push_front("T78");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f583() {
			stack.pop_front();
			stack.push_front("T77");
		}
		void f584() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T55");
		}
		void f585() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T55");
		}
		void f586() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T55");
		}
		void f587() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T55");
		}
		void f588() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T55");
		}
		void f589() {
			stack.pop_front();
			stack.push_front("T79");
		}
		void f590() {
			stack.pop_front();
			stack.push_front("T79");
		}
		void f591() {
			stack.pop_front();
			stack.push_front("T79");
		}
		void f592() {
			stack.pop_front();
			stack.push_front("T79");
		}
		void f593() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f594() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T80");
			stack.push_front("rb");
		}
		void f595() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T80");
			stack.push_front("rb");
		}
		void f596() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T81");
			stack.push_front("rb");
		}
		void f597() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T81");
			stack.push_front("rb");
		}
		void f598() {
			stack.pop_front();
			stack.push_front("T12");
			stack.push_front("T81");
			stack.push_front("rb");
		}
		void f599() {
			stack.pop_front();
			stack.push_front("T80");
			stack.push_front("T63");
		}
		void f600() {
			stack.pop_front();
			stack.push_front("T80");
			stack.push_front("T63");
		}
		void f601() {
			stack.pop_front();
			stack.push_front("T81");
			stack.push_front("T64");
		}
		void f602() {
			stack.pop_front();
			stack.push_front("T81");
			stack.push_front("T64");
		}
		void f603() {
			stack.pop_front();
			stack.push_front("T81");
			stack.push_front("T64");
		}
		void f604() {
			stack.pop_front();
			stack.push_front("T80");
			stack.push_front("T63");
		}
		void f605() {
			stack.pop_front();
			stack.push_front("T80");
			stack.push_front("T63");
		}
		void f606() {
			stack.pop_front();
			stack.push_front("T81");
			stack.push_front("T64");
		}
		void f607() {
			stack.pop_front();
			stack.push_front("T81");
			stack.push_front("T64");
		}
		void f608() {
			stack.pop_front();
			stack.push_front("T81");
			stack.push_front("T64");
		}
		void f609() {
			stack.pop_front();
			stack.push_front("T37");
			stack.push_front("T36");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f610() {
			stack.pop_front();
			stack.push_front("T37");
			stack.push_front("T36");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f611() {
			stack.pop_front();
			stack.push_front("T37");
			stack.push_front("T36");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f612() {
			stack.pop_front();
			stack.push_front("T37");
			stack.push_front("T36");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f613() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f614() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f615() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f616() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f617() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f618() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f619() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f620() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f621() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f622() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f623() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f624() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T85");
		}
		void f625() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T85");
		}
		void f626() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T85");
		}
		void f627() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T85");
		}
		void f628() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T85");
		}
		void f629() {
			stack.pop_front();
			stack.push_front("T84");
			stack.push_front("T83");
			stack.push_front("lb");
		}
		void f630() {
			stack.pop_front();
			stack.push_front("T84");
			stack.push_front("T83");
			stack.push_front("lb");
		}
		void f631() {
			stack.pop_front();
			stack.push_front("T84");
			stack.push_front("T83");
			stack.push_front("lb");
		}
		void f632() {
			stack.pop_front();
			stack.push_front("T84");
			stack.push_front("T83");
			stack.push_front("lb");
		}
		void f633() {
			stack.pop_front();
			stack.push_front("T84");
			stack.push_front("T83");
			stack.push_front("lb");
		}
		void f634() {
			stack.pop_front();
			stack.push_front("T84");
			stack.push_front("T83");
			stack.push_front("lb");
		}
		void f635() {
			stack.pop_front();
			stack.push_front("T84");
			stack.push_front("T83");
			stack.push_front("lb");
		}
		void f636() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f637() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f638() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f639() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f640() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f641() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f642() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f643() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f644() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f645() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f646() {
			stack.pop_front();
			stack.push_front("T82");
		}
		void f647() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T85");
		}
		void f648() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T85");
		}
		void f649() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T85");
		}
		void f650() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T85");
		}
		void f651() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T85");
		}
		void f652() {
			stack.pop_front();
			stack.push_front("T86");
		}
		void f653() {
			stack.pop_front();
			stack.push_front("T86");
		}
		void f654() {
			stack.pop_front();
			stack.push_front("T86");
		}
		void f655() {
			stack.pop_front();
			stack.push_front("T86");
		}
		void f656() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("SEM");
		}
		void f657() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("SEM");
		}
		void f658() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("SEM");
		}
		void f659() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("SEM");
		}
		void f660() {
			stack.pop_front();
			stack.push_front("SEM");
		}
		void f661() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("SEM");
		}
		void f662() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("SEM");
		}
		void f663() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("SEM");
		}
		void f664() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("SEM");
		}
		void f665() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("SEM");
		}
		void f666() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("SEM");
		}
		void f667() {
			stack.pop_front();
			stack.push_front("T14");
			stack.push_front("SEM");
		}
		void f668() {
			stack.pop_front();
			stack.push_front("T87");
		}
		void f669() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T23");
		}
		void f670() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T23");
		}
		void f671() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T23");
		}
		void f672() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T23");
		}
		void f673() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T23");
		}
		void f674() {
			stack.pop_front();
			stack.push_front("T88");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f675() {
			stack.pop_front();
			stack.push_front("T88");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f676() {
			stack.pop_front();
			stack.push_front("T88");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f677() {
			stack.pop_front();
			stack.push_front("T88");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f678() {
			stack.pop_front();
			stack.push_front("T88");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f679() {
			stack.pop_front();
			stack.push_front("T88");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f680() {
			stack.pop_front();
			stack.push_front("T88");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f681() {
			stack.pop_front();
			stack.push_front("T87");
		}
		void f682() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T23");
		}
		void f683() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T23");
		}
		void f684() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T23");
		}
		void f685() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T23");
		}
		void f686() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T23");
		}
		void f687() {
			stack.pop_front();
			stack.push_front("T89");
		}
		void f688() {
			stack.pop_front();
			stack.push_front("T89");
		}
		void f689() {
			stack.pop_front();
			stack.push_front("T89");
		}
		void f690() {
			stack.pop_front();
			stack.push_front("T89");
		}
		void f691() {
			stack.pop_front();
			stack.push_front("L");
		}
		void f692() {
			stack.pop_front();
			stack.push_front("L");
			stack.push_front("goto");
			stack.push_front("else");
			stack.push_front("L");
		}
		void f693() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f694() {
			stack.pop_front();
			stack.push_front("T44");
			stack.push_front("COMMA");
			stack.push_front("v");
		}
		void f695() {
			stack.pop_front();
			stack.push_front("T90");
		}
		void f696() {
			stack.pop_front();
			stack.push_front("T90");
		}
		void f697() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T50");
		}
		void f698() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T50");
		}
		void f699() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T50");
		}
		void f700() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T50");
		}
		void f701() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T50");
		}
		void f702() {
			stack.pop_front();
			stack.push_front("T91");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f703() {
			stack.pop_front();
			stack.push_front("T91");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f704() {
			stack.pop_front();
			stack.push_front("T91");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f705() {
			stack.pop_front();
			stack.push_front("T91");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f706() {
			stack.pop_front();
			stack.push_front("T91");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f707() {
			stack.pop_front();
			stack.push_front("T91");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f708() {
			stack.pop_front();
			stack.push_front("T91");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f709() {
			stack.pop_front();
			stack.push_front("T90");
		}
		void f710() {
			stack.pop_front();
			stack.push_front("T90");
		}
		void f711() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T50");
		}
		void f712() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T50");
		}
		void f713() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T50");
		}
		void f714() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T50");
		}
		void f715() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T50");
		}
		void f716() {
			stack.pop_front();
			stack.push_front("T92");
		}
		void f717() {
			stack.pop_front();
			stack.push_front("T92");
		}
		void f718() {
			stack.pop_front();
			stack.push_front("T92");
		}
		void f719() {
			stack.pop_front();
			stack.push_front("T92");
		}
		void f720() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f721() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f722() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f723() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f724() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f725() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f726() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f727() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f728() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f729() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f730() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f731() {
			stack.pop_front();
			stack.push_front("T41");
		}
		void f732() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("COMMA");
		}
		void f733() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("COMMA");
		}
		void f734() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("COMMA");
		}
		void f735() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("COMMA");
		}
		void f736() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("COMMA");
		}
		void f737() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("COMMA");
		}
		void f738() {
			stack.pop_front();
			stack.push_front("T46");
			stack.push_front("T45");
			stack.push_front("COMMA");
		}
		void f739() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f740() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f741() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f742() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f743() {
			stack.pop_front();
			stack.push_front("T93");
		}
		void f744() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T55");
		}
		void f745() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T55");
		}
		void f746() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T55");
		}
		void f747() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T55");
		}
		void f748() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T55");
		}
		void f749() {
			stack.pop_front();
			stack.push_front("T94");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f750() {
			stack.pop_front();
			stack.push_front("T94");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f751() {
			stack.pop_front();
			stack.push_front("T94");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f752() {
			stack.pop_front();
			stack.push_front("T94");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f753() {
			stack.pop_front();
			stack.push_front("T94");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f754() {
			stack.pop_front();
			stack.push_front("T94");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f755() {
			stack.pop_front();
			stack.push_front("T94");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f756() {
			stack.pop_front();
			stack.push_front("T93");
		}
		void f757() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T55");
		}
		void f758() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T55");
		}
		void f759() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T55");
		}
		void f760() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T55");
		}
		void f761() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T55");
		}
		void f762() {
			stack.pop_front();
			stack.push_front("T95");
		}
		void f763() {
			stack.pop_front();
			stack.push_front("T95");
		}
		void f764() {
			stack.pop_front();
			stack.push_front("T95");
		}
		void f765() {
			stack.pop_front();
			stack.push_front("T95");
		}
		void f766() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f767() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f768() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T96");
			stack.push_front("rb");
		}
		void f769() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T96");
			stack.push_front("rb");
		}
		void f770() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T97");
			stack.push_front("rb");
		}
		void f771() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T97");
			stack.push_front("rb");
		}
		void f772() {
			stack.pop_front();
			stack.push_front("T16");
			stack.push_front("T97");
			stack.push_front("rb");
		}
		void f773() {
			stack.pop_front();
			stack.push_front("T96");
			stack.push_front("T63");
		}
		void f774() {
			stack.pop_front();
			stack.push_front("T96");
			stack.push_front("T63");
		}
		void f775() {
			stack.pop_front();
			stack.push_front("T97");
			stack.push_front("T64");
		}
		void f776() {
			stack.pop_front();
			stack.push_front("T97");
			stack.push_front("T64");
		}
		void f777() {
			stack.pop_front();
			stack.push_front("T97");
			stack.push_front("T64");
		}
		void f778() {
			stack.pop_front();
			stack.push_front("T96");
			stack.push_front("T63");
		}
		void f779() {
			stack.pop_front();
			stack.push_front("T96");
			stack.push_front("T63");
		}
		void f780() {
			stack.pop_front();
			stack.push_front("T97");
			stack.push_front("T64");
		}
		void f781() {
			stack.pop_front();
			stack.push_front("T97");
			stack.push_front("T64");
		}
		void f782() {
			stack.pop_front();
			stack.push_front("T97");
			stack.push_front("T64");
		}
		void f783() {
			stack.pop_front();
			stack.push_front("T49");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f784() {
			stack.pop_front();
			stack.push_front("T49");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f785() {
			stack.pop_front();
			stack.push_front("T49");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f786() {
			stack.pop_front();
			stack.push_front("T49");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f787() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f788() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f789() {
			stack.pop_front();
			stack.push_front("T98");
		}
		void f790() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T55");
		}
		void f791() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T55");
		}
		void f792() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T55");
		}
		void f793() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T55");
		}
		void f794() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T55");
		}
		void f795() {
			stack.pop_front();
			stack.push_front("T99");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f796() {
			stack.pop_front();
			stack.push_front("T99");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f797() {
			stack.pop_front();
			stack.push_front("T99");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f798() {
			stack.pop_front();
			stack.push_front("T99");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f799() {
			stack.pop_front();
			stack.push_front("T99");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f800() {
			stack.pop_front();
			stack.push_front("T99");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f801() {
			stack.pop_front();
			stack.push_front("T99");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f802() {
			stack.pop_front();
			stack.push_front("T98");
		}
		void f803() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T55");
		}
		void f804() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T55");
		}
		void f805() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T55");
		}
		void f806() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T55");
		}
		void f807() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T55");
		}
		void f808() {
			stack.pop_front();
			stack.push_front("T100");
		}
		void f809() {
			stack.pop_front();
			stack.push_front("T100");
		}
		void f810() {
			stack.pop_front();
			stack.push_front("T100");
		}
		void f811() {
			stack.pop_front();
			stack.push_front("T100");
		}
		void f812() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f813() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f814() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f815() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f816() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f817() {
			stack.pop_front();
			stack.push_front("T18");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f818() {
			stack.pop_front();
			stack.push_front("T101");
			stack.push_front("T63");
		}
		void f819() {
			stack.pop_front();
			stack.push_front("T101");
			stack.push_front("T63");
		}
		void f820() {
			stack.pop_front();
			stack.push_front("T102");
			stack.push_front("T64");
		}
		void f821() {
			stack.pop_front();
			stack.push_front("T102");
			stack.push_front("T64");
		}
		void f822() {
			stack.pop_front();
			stack.push_front("T102");
			stack.push_front("T64");
		}
		void f823() {
			stack.pop_front();
			stack.push_front("T101");
			stack.push_front("T63");
		}
		void f824() {
			stack.pop_front();
			stack.push_front("T101");
			stack.push_front("T63");
		}
		void f825() {
			stack.pop_front();
			stack.push_front("T102");
			stack.push_front("T64");
		}
		void f826() {
			stack.pop_front();
			stack.push_front("T102");
			stack.push_front("T64");
		}
		void f827() {
			stack.pop_front();
			stack.push_front("T102");
			stack.push_front("T64");
		}
		void f828() {
			stack.pop_front();
			stack.push_front("T54");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f829() {
			stack.pop_front();
			stack.push_front("T54");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f830() {
			stack.pop_front();
			stack.push_front("T54");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f831() {
			stack.pop_front();
			stack.push_front("T54");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f832() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f833() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f834() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f835() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f836() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f837() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f838() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f839() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f840() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f841() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f842() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f843() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f844() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("T104");
			stack.push_front("Equal");
			stack.push_front("v");
			stack.push_front("let");
		}
		void f845() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("T105");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f846() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("T105");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f847() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("T105");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f848() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("T105");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f849() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("T105");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f850() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("T105");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f851() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("T105");
			stack.push_front("goto");
			stack.push_front("T10");
			stack.push_front("T9");
			stack.push_front("T8");
			stack.push_front("if");
		}
		void f852() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("L");
			stack.push_front("next");
			stack.push_front("T14");
			stack.push_front("T13");
			stack.push_front("to");
			stack.push_front("T12");
			stack.push_front("Equal");
			stack.push_front("v");
			stack.push_front("for");
			stack.push_front("L");
		}
		void f853() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("T106");
			stack.push_front("read");
		}
		void f854() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("write");
		}
		void f855() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("write");
		}
		void f856() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("write");
		}
		void f857() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("write");
		}
		void f858() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("write");
		}
		void f859() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("write");
		}
		void f860() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("write");
		}
		void f861() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rab");
			stack.push_front("L");
			stack.push_front("lab");
		}
		void f862() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("L");
			stack.push_front("jump");
		}
		void f863() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("switch");
			stack.push_front("end");
			stack.push_front("T19");
			stack.push_front("rb");
			stack.push_front("T18");
			stack.push_front("lb");
			stack.push_front("switch");
		}
		void f864() {
			stack.pop_front();
			stack.push_front("T103");
			stack.push_front("trow");
		}
		void f865() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rem");
		}
		void f866() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rem");
		}
		void f867() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rem");
		}
		void f868() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rem");
		}
		void f869() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rem");
		}
		void f870() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rem");
		}
		void f871() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rem");
		}
		void f872() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rem");
		}
		void f873() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rem");
		}
		void f874() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rem");
		}
		void f875() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("rem");
		}
		void f876() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f877() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f878() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f879() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f880() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f881() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f882() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f883() {
			stack.pop_front();
			stack.push_front("T21");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f884() {
			stack.pop_front();
			stack.push_front("T59");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f885() {
			stack.pop_front();
			stack.push_front("T59");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f886() {
			stack.pop_front();
			stack.push_front("T59");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f887() {
			stack.pop_front();
			stack.push_front("T59");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f888() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f889() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f890() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f891() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f892() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f893() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f894() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f895() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f896() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f897() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f898() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f899() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f900() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f901() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f902() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f903() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f904() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f905() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f906() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f907() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f908() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f909() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f910() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f911() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f912() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f913() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f914() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f915() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f916() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f917() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f918() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f919() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f920() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f921() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f922() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f923() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f924() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f925() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f926() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f927() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f928() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f929() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f930() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f931() {
			stack.pop_front();
			stack.push_front("Dif");
		}
		void f932() {
			stack.pop_front();
			stack.push_front("SDif");
		}
		void f933() {
			stack.pop_front();
			stack.push_front("Cross");
		}
		void f934() {
			stack.pop_front();
			stack.push_front("Un");
		}
		void f935() {
			stack.pop_front();
			stack.push_front("T109");
		}
		void f936() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T112");
		}
		void f937() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T112");
		}
		void f938() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T112");
		}
		void f939() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T112");
		}
		void f940() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T112");
		}
		void f941() {
			stack.pop_front();
			stack.push_front("T111");
			stack.push_front("T110");
			stack.push_front("lb");
		}
		void f942() {
			stack.pop_front();
			stack.push_front("T111");
			stack.push_front("T110");
			stack.push_front("lb");
		}
		void f943() {
			stack.pop_front();
			stack.push_front("T111");
			stack.push_front("T110");
			stack.push_front("lb");
		}
		void f944() {
			stack.pop_front();
			stack.push_front("T111");
			stack.push_front("T110");
			stack.push_front("lb");
		}
		void f945() {
			stack.pop_front();
			stack.push_front("T111");
			stack.push_front("T110");
			stack.push_front("lb");
		}
		void f946() {
			stack.pop_front();
			stack.push_front("T111");
			stack.push_front("T110");
			stack.push_front("lb");
		}
		void f947() {
			stack.pop_front();
			stack.push_front("T111");
			stack.push_front("T110");
			stack.push_front("lb");
		}
		void f948() {
			stack.pop_front();
			stack.push_front("T109");
		}
		void f949() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T112");
		}
		void f950() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T112");
		}
		void f951() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T112");
		}
		void f952() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T112");
		}
		void f953() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T112");
		}
		void f954() {
			stack.pop_front();
			stack.push_front("T113");
		}
		void f955() {
			stack.pop_front();
			stack.push_front("T113");
		}
		void f956() {
			stack.pop_front();
			stack.push_front("T113");
		}
		void f957() {
			stack.pop_front();
			stack.push_front("T113");
		}
		void f958() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f959() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f960() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f961() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f962() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f963() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f964() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f965() {
			stack.pop_front();
			stack.push_front("T26");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f966() {
			stack.pop_front();
			stack.push_front("T68");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f967() {
			stack.pop_front();
			stack.push_front("T68");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f968() {
			stack.pop_front();
			stack.push_front("T68");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f969() {
			stack.pop_front();
			stack.push_front("T68");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f970() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f971() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f972() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f973() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f974() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f975() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f976() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f977() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f978() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f979() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f980() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f981() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f982() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f983() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f984() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f985() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f986() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f987() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f988() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f989() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f990() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f991() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f992() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f993() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f994() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f995() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f996() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f997() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f998() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f999() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1000() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1001() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1002() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1003() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1004() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1005() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1006() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1007() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1008() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1009() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1010() {
			stack.pop_front();
			stack.push_front("T31");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1011() {
			stack.pop_front();
			stack.push_front("T73");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1012() {
			stack.pop_front();
			stack.push_front("T73");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1013() {
			stack.pop_front();
			stack.push_front("T73");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1014() {
			stack.pop_front();
			stack.push_front("T73");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1015() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1016() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1017() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1018() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1019() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1020() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1021() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1022() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1023() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1024() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1025() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1026() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1027() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1028() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1029() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1030() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1031() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1032() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1033() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1034() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1035() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1036() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1037() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1038() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1039() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1040() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1041() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1042() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1043() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1044() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1045() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1046() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1047() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1048() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1049() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1050() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1051() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1052() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1053() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1054() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1055() {
			stack.pop_front();
			stack.push_front("T36");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1056() {
			stack.pop_front();
			stack.push_front("T78");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1057() {
			stack.pop_front();
			stack.push_front("T78");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1058() {
			stack.pop_front();
			stack.push_front("T78");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1059() {
			stack.pop_front();
			stack.push_front("T78");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1060() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1061() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1062() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1063() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1064() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1065() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1066() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1067() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1068() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1069() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1070() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1071() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1072() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1073() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1074() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1075() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1076() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1077() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1078() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1079() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1080() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1081() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1082() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1083() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1084() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1085() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1086() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1087() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1088() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1089() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1090() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1091() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1092() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1093() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1094() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1095() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1096() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1097() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1098() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1099() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1100() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1101() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1102() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1103() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1104() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1105() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1106() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1107() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1108() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1109() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1110() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1111() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1112() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1113() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1114() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1115() {
			stack.pop_front();
			stack.push_front("T114");
		}
		void f1116() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T55");
		}
		void f1117() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T55");
		}
		void f1118() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T55");
		}
		void f1119() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T55");
		}
		void f1120() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T55");
		}
		void f1121() {
			stack.pop_front();
			stack.push_front("T115");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1122() {
			stack.pop_front();
			stack.push_front("T115");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1123() {
			stack.pop_front();
			stack.push_front("T115");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1124() {
			stack.pop_front();
			stack.push_front("T115");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1125() {
			stack.pop_front();
			stack.push_front("T115");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1126() {
			stack.pop_front();
			stack.push_front("T115");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1127() {
			stack.pop_front();
			stack.push_front("T115");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1128() {
			stack.pop_front();
			stack.push_front("T114");
		}
		void f1129() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T55");
		}
		void f1130() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T55");
		}
		void f1131() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T55");
		}
		void f1132() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T55");
		}
		void f1133() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T55");
		}
		void f1134() {
			stack.pop_front();
			stack.push_front("T116");
		}
		void f1135() {
			stack.pop_front();
			stack.push_front("T116");
		}
		void f1136() {
			stack.pop_front();
			stack.push_front("T116");
		}
		void f1137() {
			stack.pop_front();
			stack.push_front("T116");
		}
		void f1138() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1139() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1140() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1141() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1142() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1143() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1144() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1145() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1146() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1147() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1148() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1149() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T117");
			stack.push_front("rb");
		}
		void f1150() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T117");
			stack.push_front("rb");
		}
		void f1151() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T118");
			stack.push_front("rb");
		}
		void f1152() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T118");
			stack.push_front("rb");
		}
		void f1153() {
			stack.pop_front();
			stack.push_front("T40");
			stack.push_front("T118");
			stack.push_front("rb");
		}
		void f1154() {
			stack.pop_front();
			stack.push_front("T117");
			stack.push_front("T63");
		}
		void f1155() {
			stack.pop_front();
			stack.push_front("T117");
			stack.push_front("T63");
		}
		void f1156() {
			stack.pop_front();
			stack.push_front("T118");
			stack.push_front("T64");
		}
		void f1157() {
			stack.pop_front();
			stack.push_front("T118");
			stack.push_front("T64");
		}
		void f1158() {
			stack.pop_front();
			stack.push_front("T118");
			stack.push_front("T64");
		}
		void f1159() {
			stack.pop_front();
			stack.push_front("T117");
			stack.push_front("T63");
		}
		void f1160() {
			stack.pop_front();
			stack.push_front("T117");
			stack.push_front("T63");
		}
		void f1161() {
			stack.pop_front();
			stack.push_front("T118");
			stack.push_front("T64");
		}
		void f1162() {
			stack.pop_front();
			stack.push_front("T118");
			stack.push_front("T64");
		}
		void f1163() {
			stack.pop_front();
			stack.push_front("T118");
			stack.push_front("T64");
		}
		void f1164() {
			stack.pop_front();
			stack.push_front("T84");
			stack.push_front("T83");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1165() {
			stack.pop_front();
			stack.push_front("T84");
			stack.push_front("T83");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1166() {
			stack.pop_front();
			stack.push_front("T84");
			stack.push_front("T83");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1167() {
			stack.pop_front();
			stack.push_front("T84");
			stack.push_front("T83");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1168() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1169() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1170() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1171() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T61");
			stack.push_front("rb");
		}
		void f1172() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T61");
			stack.push_front("rb");
		}
		void f1173() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T62");
			stack.push_front("rb");
		}
		void f1174() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T62");
			stack.push_front("rb");
		}
		void f1175() {
			stack.pop_front();
			stack.push_front("T42");
			stack.push_front("T62");
			stack.push_front("rb");
		}
		void f1176() {
			stack.pop_front();
			stack.push_front("T88");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1177() {
			stack.pop_front();
			stack.push_front("T88");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1178() {
			stack.pop_front();
			stack.push_front("T88");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1179() {
			stack.pop_front();
			stack.push_front("T88");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1180() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1181() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1182() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1183() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1184() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1185() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1186() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T96");
			stack.push_front("rb");
		}
		void f1187() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T96");
			stack.push_front("rb");
		}
		void f1188() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T97");
			stack.push_front("rb");
		}
		void f1189() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T97");
			stack.push_front("rb");
		}
		void f1190() {
			stack.pop_front();
			stack.push_front("T45");
			stack.push_front("T97");
			stack.push_front("rb");
		}
		void f1191() {
			stack.pop_front();
			stack.push_front("T91");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1192() {
			stack.pop_front();
			stack.push_front("T91");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1193() {
			stack.pop_front();
			stack.push_front("T91");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1194() {
			stack.pop_front();
			stack.push_front("T91");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1195() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1196() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1197() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1198() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1199() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1200() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1201() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1202() {
			stack.pop_front();
			stack.push_front("T48");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1203() {
			stack.pop_front();
			stack.push_front("T94");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1204() {
			stack.pop_front();
			stack.push_front("T94");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1205() {
			stack.pop_front();
			stack.push_front("T94");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1206() {
			stack.pop_front();
			stack.push_front("T94");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1207() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1208() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1209() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1210() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1211() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1212() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1213() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1214() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1215() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1216() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1217() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1218() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1219() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1220() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1221() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1222() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1223() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1224() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1225() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1226() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1227() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1228() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1229() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1230() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1231() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1232() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1233() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1234() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1235() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1236() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1237() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1238() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1239() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1240() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1241() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1242() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1243() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1244() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1245() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1246() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1247() {
			stack.pop_front();
			stack.push_front("T53");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1248() {
			stack.pop_front();
			stack.push_front("T99");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1249() {
			stack.pop_front();
			stack.push_front("T99");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1250() {
			stack.pop_front();
			stack.push_front("T99");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1251() {
			stack.pop_front();
			stack.push_front("T99");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1252() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1253() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1254() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1255() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1256() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1257() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1258() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1259() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1260() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1261() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1262() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1263() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1264() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1265() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1266() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1267() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1268() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1269() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1270() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1271() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1272() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1273() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1274() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1275() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1276() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1277() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1278() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1279() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1280() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1281() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1282() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1283() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1284() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1285() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("SEM");
		}
		void f1286() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("SEM");
		}
		void f1287() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("SEM");
		}
		void f1288() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("SEM");
		}
		void f1289() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("SEM");
		}
		void f1290() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("SEM");
		}
		void f1291() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("SEM");
		}
		void f1292() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("SEM");
		}
		void f1293() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("SEM");
		}
		void f1294() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("SEM");
		}
		void f1295() {
			stack.pop_front();
			stack.push_front("T57");
			stack.push_front("SEM");
		}
		void f1296() {
			stack.pop_front();
			stack.push_front("SEM");
		}
		void f1297() {
			stack.pop_front();
			stack.push_front("T119");
		}
		void f1298() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T23");
		}
		void f1299() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T23");
		}
		void f1300() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T23");
		}
		void f1301() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T23");
		}
		void f1302() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T23");
		}
		void f1303() {
			stack.pop_front();
			stack.push_front("T120");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f1304() {
			stack.pop_front();
			stack.push_front("T120");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f1305() {
			stack.pop_front();
			stack.push_front("T120");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f1306() {
			stack.pop_front();
			stack.push_front("T120");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f1307() {
			stack.pop_front();
			stack.push_front("T120");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f1308() {
			stack.pop_front();
			stack.push_front("T120");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f1309() {
			stack.pop_front();
			stack.push_front("T120");
			stack.push_front("T21");
			stack.push_front("lb");
		}
		void f1310() {
			stack.pop_front();
			stack.push_front("T119");
		}
		void f1311() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T23");
		}
		void f1312() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T23");
		}
		void f1313() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T23");
		}
		void f1314() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T23");
		}
		void f1315() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T23");
		}
		void f1316() {
			stack.pop_front();
			stack.push_front("T121");
		}
		void f1317() {
			stack.pop_front();
			stack.push_front("T121");
		}
		void f1318() {
			stack.pop_front();
			stack.push_front("T121");
		}
		void f1319() {
			stack.pop_front();
			stack.push_front("T121");
		}
		void f1320() {
			stack.pop_front();
			stack.push_front("L");
		}
		void f1321() {
			stack.pop_front();
			stack.push_front("L");
			stack.push_front("goto");
			stack.push_front("else");
			stack.push_front("L");
		}
		void f1322() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1323() {
			stack.pop_front();
			stack.push_front("T106");
			stack.push_front("COMMA");
			stack.push_front("v");
		}
		void f1324() {
			stack.pop_front();
			stack.push_front("T122");
		}
		void f1325() {
			stack.pop_front();
			stack.push_front("T122");
		}
		void f1326() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T50");
		}
		void f1327() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T50");
		}
		void f1328() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T50");
		}
		void f1329() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T50");
		}
		void f1330() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T50");
		}
		void f1331() {
			stack.pop_front();
			stack.push_front("T123");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f1332() {
			stack.pop_front();
			stack.push_front("T123");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f1333() {
			stack.pop_front();
			stack.push_front("T123");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f1334() {
			stack.pop_front();
			stack.push_front("T123");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f1335() {
			stack.pop_front();
			stack.push_front("T123");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f1336() {
			stack.pop_front();
			stack.push_front("T123");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f1337() {
			stack.pop_front();
			stack.push_front("T123");
			stack.push_front("T48");
			stack.push_front("lb");
		}
		void f1338() {
			stack.pop_front();
			stack.push_front("T122");
		}
		void f1339() {
			stack.pop_front();
			stack.push_front("T122");
		}
		void f1340() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T50");
		}
		void f1341() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T50");
		}
		void f1342() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T50");
		}
		void f1343() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T50");
		}
		void f1344() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T50");
		}
		void f1345() {
			stack.pop_front();
			stack.push_front("T124");
		}
		void f1346() {
			stack.pop_front();
			stack.push_front("T124");
		}
		void f1347() {
			stack.pop_front();
			stack.push_front("T124");
		}
		void f1348() {
			stack.pop_front();
			stack.push_front("T124");
		}
		void f1349() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1350() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1351() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1352() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1353() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1354() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1355() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1356() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1357() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1358() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1359() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1360() {
			stack.pop_front();
			stack.push_front("T103");
		}
		void f1361() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("COMMA");
		}
		void f1362() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("COMMA");
		}
		void f1363() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("COMMA");
		}
		void f1364() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("COMMA");
		}
		void f1365() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("COMMA");
		}
		void f1366() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("COMMA");
		}
		void f1367() {
			stack.pop_front();
			stack.push_front("T108");
			stack.push_front("T107");
			stack.push_front("COMMA");
		}
		void f1368() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1369() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1370() {
			stack.pop_front();
			stack.push_front("T125");
		}
		void f1371() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T55");
		}
		void f1372() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T55");
		}
		void f1373() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T55");
		}
		void f1374() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T55");
		}
		void f1375() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T55");
		}
		void f1376() {
			stack.pop_front();
			stack.push_front("T126");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1377() {
			stack.pop_front();
			stack.push_front("T126");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1378() {
			stack.pop_front();
			stack.push_front("T126");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1379() {
			stack.pop_front();
			stack.push_front("T126");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1380() {
			stack.pop_front();
			stack.push_front("T126");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1381() {
			stack.pop_front();
			stack.push_front("T126");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1382() {
			stack.pop_front();
			stack.push_front("T126");
			stack.push_front("T53");
			stack.push_front("lb");
		}
		void f1383() {
			stack.pop_front();
			stack.push_front("T125");
		}
		void f1384() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T55");
		}
		void f1385() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T55");
		}
		void f1386() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T55");
		}
		void f1387() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T55");
		}
		void f1388() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T55");
		}
		void f1389() {
			stack.pop_front();
			stack.push_front("T127");
		}
		void f1390() {
			stack.pop_front();
			stack.push_front("T127");
		}
		void f1391() {
			stack.pop_front();
			stack.push_front("T127");
		}
		void f1392() {
			stack.pop_front();
			stack.push_front("T127");
		}
		void f1393() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1394() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T128");
			stack.push_front("rb");
		}
		void f1395() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T128");
			stack.push_front("rb");
		}
		void f1396() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T129");
			stack.push_front("rb");
		}
		void f1397() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T129");
			stack.push_front("rb");
		}
		void f1398() {
			stack.pop_front();
			stack.push_front("T66");
			stack.push_front("T129");
			stack.push_front("rb");
		}
		void f1399() {
			stack.pop_front();
			stack.push_front("T128");
			stack.push_front("T63");
		}
		void f1400() {
			stack.pop_front();
			stack.push_front("T128");
			stack.push_front("T63");
		}
		void f1401() {
			stack.pop_front();
			stack.push_front("T129");
			stack.push_front("T64");
		}
		void f1402() {
			stack.pop_front();
			stack.push_front("T129");
			stack.push_front("T64");
		}
		void f1403() {
			stack.pop_front();
			stack.push_front("T129");
			stack.push_front("T64");
		}
		void f1404() {
			stack.pop_front();
			stack.push_front("T128");
			stack.push_front("T63");
		}
		void f1405() {
			stack.pop_front();
			stack.push_front("T128");
			stack.push_front("T63");
		}
		void f1406() {
			stack.pop_front();
			stack.push_front("T129");
			stack.push_front("T64");
		}
		void f1407() {
			stack.pop_front();
			stack.push_front("T129");
			stack.push_front("T64");
		}
		void f1408() {
			stack.pop_front();
			stack.push_front("T129");
			stack.push_front("T64");
		}
		void f1409() {
			stack.pop_front();
			stack.push_front("T111");
			stack.push_front("T110");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1410() {
			stack.pop_front();
			stack.push_front("T111");
			stack.push_front("T110");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1411() {
			stack.pop_front();
			stack.push_front("T111");
			stack.push_front("T110");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1412() {
			stack.pop_front();
			stack.push_front("T111");
			stack.push_front("T110");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1413() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1414() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1415() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1416() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1417() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1418() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1419() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1420() {
			stack.pop_front();
			stack.push_front("T83");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1421() {
			stack.pop_front();
			stack.push_front("T115");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1422() {
			stack.pop_front();
			stack.push_front("T115");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1423() {
			stack.pop_front();
			stack.push_front("T115");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1424() {
			stack.pop_front();
			stack.push_front("T115");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1425() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1426() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1427() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1428() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1429() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1430() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1431() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1432() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1433() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1434() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1435() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1436() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1437() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1438() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1439() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1440() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1441() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1442() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1443() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1444() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1445() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1446() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1447() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1448() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1449() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1450() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1451() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1452() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1453() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1454() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1455() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1456() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1457() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1458() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1459() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1460() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1461() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T61");
			stack.push_front("rb");
		}
		void f1462() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T61");
			stack.push_front("rb");
		}
		void f1463() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T62");
			stack.push_front("rb");
		}
		void f1464() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T62");
			stack.push_front("rb");
		}
		void f1465() {
			stack.pop_front();
			stack.push_front("T104");
			stack.push_front("T62");
			stack.push_front("rb");
		}
		void f1466() {
			stack.pop_front();
			stack.push_front("T120");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1467() {
			stack.pop_front();
			stack.push_front("T120");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1468() {
			stack.pop_front();
			stack.push_front("T120");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1469() {
			stack.pop_front();
			stack.push_front("T120");
			stack.push_front("T21");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1470() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1471() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1472() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1473() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1474() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1475() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1476() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T96");
			stack.push_front("rb");
		}
		void f1477() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T96");
			stack.push_front("rb");
		}
		void f1478() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T97");
			stack.push_front("rb");
		}
		void f1479() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T97");
			stack.push_front("rb");
		}
		void f1480() {
			stack.pop_front();
			stack.push_front("T107");
			stack.push_front("T97");
			stack.push_front("rb");
		}
		void f1481() {
			stack.pop_front();
			stack.push_front("T123");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1482() {
			stack.pop_front();
			stack.push_front("T123");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1483() {
			stack.pop_front();
			stack.push_front("T123");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1484() {
			stack.pop_front();
			stack.push_front("T123");
			stack.push_front("T48");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1485() {
			stack.pop_front();
			stack.push_front("v");
		}
		void f1486() {
			stack.pop_front();
			stack.push_front("c");
		}
		void f1487() {
			stack.pop_front();
			stack.push_front("rb");
		}
		void f1488() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1489() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T101");
			stack.push_front("rb");
		}
		void f1490() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1491() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1492() {
			stack.pop_front();
			stack.push_front("T110");
			stack.push_front("T102");
			stack.push_front("rb");
		}
		void f1493() {
			stack.pop_front();
			stack.push_front("T126");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1494() {
			stack.pop_front();
			stack.push_front("T126");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1495() {
			stack.pop_front();
			stack.push_front("T126");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1496() {
			stack.pop_front();
			stack.push_front("T126");
			stack.push_front("T53");
			stack.push_front("COMMA");
			stack.push_front("T66");
			stack.push_front("lb");
			stack.push_front("T65");
		}
		void f1497() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1498() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1499() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1500() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1501() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1502() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1503() {
			stack.pop_front();
			stack.push_front("Plus");
		}
		void f1504() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1505() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1506() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1507() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1508() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1509() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1510() {
			stack.pop_front();
			stack.push_front("Minus");
		}
		void f1511() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1512() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1513() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1514() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1515() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1516() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1517() {
			stack.pop_front();
			stack.push_front("Multiply");
		}
		void f1518() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1519() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1520() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1521() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1522() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1523() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1524() {
			stack.pop_front();
			stack.push_front("Div");
		}
		void f1525() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1526() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1527() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1528() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1529() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1530() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1531() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1532() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1533() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1534() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1535() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1536() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1537() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1538() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1539() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1540() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1541() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1542() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1543() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1544() {
			stack.pop_front();
			stack.push_front("Mod");
		}
		void f1545() {
			stack.pop_front();
			stack.push_front("Mod");
		}



		void pop() {
			stack.pop_front();
			symbol[0] = push_b(lexStack, i);
			i++;
			symbol[1] = push_b(lexStack, i);

		}

		void Error1() {
			throw std::exception("false in operate table");
		}

		std::string push_b(std::vector<std::string> lexStack, int i);

};

#endif