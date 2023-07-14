#include <iostream>
int** create_matr(int m, int n) {
	int** matr = new int* [m];
	for (int i = 0; i < m; ++i) {
		matr[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			std::cin >> matr[i][j];
		}
	}
	return matr;
}

// ������� ��������� ������ � inline assembly ���� �������� ��'��� �����,
// �� �������� ���� �������� ��������� � ����������� ����� ���� ���� � �������� �������.
// ���� ����� ��������� res := 0 �� ������������, �� ��������� ����, �� ������� �� ����� ������ �� ��� ���������

int main()
{
	int temp;
	int n; std::cin >> n;
	int** matr = create_matr(n, n);
	int res;
	__asm {
		mov res, 0
		mov ebx, matr						// ebx - ������ ������ ���������
		mov ecx, 0							// ecx - ������� ��������
		start:
		push ecx							// �������� ������ ecx, ��������� ���� � ����
			mov edi, [ebx + ecx * 4]		// edi - ������ ������ (�����)
			mov esi, 0						// �������� ��������
			start_inner :
			mov eax, [edi + esi * 4]		// �������� � ��� ������� ������� (�����)
			mov ecx, 3						// ������
			cdq
			div ecx
			cmp edx, 1						// ������� ������ � 1
			jne end_inner					// ���� EAXmod3 != 1 �� ���������� � ����� ��������
			mov eax, [edi + esi * 4]		// ����� �������� ������� ������� � ��� (�� ����� ��� ������)
			mov ecx, res					// �������� ��������� ������������ �������
			cmp eax, ecx					// ��������� ������� �������, ���� �������� �� ���� � ������ ��������� 
			jle end_inner					// ���� ������� ������-�����, �� ���������� � ����� ��������
			mov res, eax					// ���� ������� ������, �� ������������ ����������� ��������
			end_inner :
		inc esi
			cmp esi, n
			jl start_inner
			end :
		pop ecx		//�������� �������� ��������� � �����
			inc ecx
			cmp ecx, n
			jl start
			mov temp, edx
	}
	if (res == 0) {
		std::cout << "not found";
	}
	else {
		std::cout <<'\n'<< res;
	}
	return 0;
}