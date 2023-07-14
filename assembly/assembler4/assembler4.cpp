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

// Оскільки обрахунок остачі в inline assembly може видавати від'ємні числа,
// то програма буде коректно працювати з математичної точки зору лише з додатніми числами.
// Тому можна дозволити res := 0 по замовчуванню, як індикатор того, що елемент за даною умовою не був знайдений

int main()
{
	int temp;
	int n; std::cin >> n;
	int** matr = create_matr(n, n);
	int res;
	__asm {
		mov res, 0
		mov ebx, matr						// ebx - адреса масиву вказівників
		mov ecx, 0							// ecx - зовнішній лічильник
		start:
		push ecx							// звільнимо регістр ecx, засунувши його в стек
			mov edi, [ebx + ecx * 4]		// edi - адреса масиву (рядка)
			mov esi, 0						// внутрішній лічильник
			start_inner :
			mov eax, [edi + esi * 4]		// записуємо в еах елемент матриці (ділене)
			mov ecx, 3						// дільник
			cdq
			div ecx
			cmp edx, 1						// порівнємо остачу з 1
			jne end_inner					// якщо EAXmod3 != 1 то переходимо в кінець ітерації
			mov eax, [edi + esi * 4]		// знову записуємо елемент матриці в еах (бо зараз там частка)
			mov ecx, res					// записуємо попередній максимальний елемент
			cmp eax, ecx					// порівнюємо елемент матриці, який підзодить по умові з старим значенням 
			jle end_inner					// якщо елемент менший-рівний, то переходимо в кінець ітерації
			mov res, eax					// якшо елемент більший, то перезаписуємо максимальне значення
			end_inner :
		inc esi
			cmp esi, n
			jl start_inner
			end :
		pop ecx		//витягуємо значення лічильника зі стеку
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