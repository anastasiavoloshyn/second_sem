#include <iostream>

int hours;
int minutes;
int angle;
int a = 30; // 1 ������ = 30 �������
int b = 2;  // ���� ��� ���������� ������
char HOURS[] = "hours";
char MINUTES[] = "minutes";
char FORMAT[] = "%d %s %d %s \n";
int main() {

	std::cin >> angle;
	_asm {
		mov ebx,a 
		mov ecx, b   // ������� ���� � �������, ��� ���������� ������������ � �������
		mov eax,angle
		cdq // �������� �������� ������� ��� ���� ��� ���� �������� ������ � �������� ������ � ������
		div ebx
		mov hours,eax  // ������� ������(������) � ����� hours
		mov eax,edx  // ������� ������ � ������ eax, ��� ���� �������� �������
		mul ecx
		mov minutes,eax //������� ��������� ��������� �� �������� ������ �� 2 � ����� minutes
	
		mov eax,offset MINUTES
		push eax
		mov eax,minutes
		push eax
		mov eax,offset HOURS
		push eax                  //������� ������� ��������� ����� ����� ��������
		mov eax,hours
		push eax
		mov eax,offset FORMAT
		push eax
		mov edi,printf
		call edi
		pop eax
		pop eax
		pop eax
		pop eax
		pop eax
	}
	//std::cout<< hours << " hours " << minutes<<" minutes\n";
	return 0;
}
