#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

const int n = 5;
int N=5;
const float _1 = 1;
const float _2 = 2;
const float _3 = 3;
const float _4 = 4;
float a[n];
float c, d;
float res[n];

void enteringData()
{
	cout << " Input a : ";
	for (int i = 0; i < N; ++i)
	{
		cout << " a[" << i << "] = ";
		cin >> a[i];
	}
	cout << " Input c : ";
	cin >> c;
	cout << " Input d : ";
	cin >> d;
	
}

void printRes(const char* sym)
{
	cout << " Calculate in " << sym <<'\n';
	for (int i = 0; i < n; ++i)
	{
		cout << " result: [" << i + 1 << "] = " << res[i] << '\n';
	}
}
void calculateCpp()
{
	for (int i = 0; i < n; i++)
	{
		res[i] = (2.0 * c - log((a[i] + d) / c)) / ((c / 3.0) - 1);
	}
}


void calculateASM()
{
	__asm {
		lea esi, a
		lea edi, res
		mov ecx, N
		finit
		start :
		fld c
			fmul _2
			fld _1
			fld[esi]
			fadd d
			fdiv c
			fyl2x
			fldln2
			fmul
			fsub
			fld c
			fdiv _3
			fsub _1
			fdiv
			fstp[edi]
			add esi, _4
			add edi, _4
			end:
			dec ecx
			cmp ecx,0
			jg start
	}
	
}

int main()
{
	enteringData();
	calculateASM();
	printRes("ASM");
	//calculateCpp();
	//printRes("C++");
	system("pause");
	return 0;
}






