#include <iostream>

int hours;
int minutes;
int angle;
int a = 30; // 1 година = 30 градусів
int b = 2;  // зміна для обчислення хвилин
char HOURS[] = "hours";
char MINUTES[] = "minutes";
char FORMAT[] = "%d %s %d %s \n";
int main() {

	std::cin >> angle;
	_asm {
		mov ebx,a 
		mov ecx, b   // записую змінні в регістри, для подальшого використання в програмі
		mov eax,angle
		cdq // розширюю значення регістру для того щоб потім виконати ділення і записати остачу і частку
		div ebx
		mov hours,eax  // зберігаю частку(години) в змінну hours
		mov eax,edx  // зберігаю остачу в регістр eax, щоб потім дізнатись хвилини
		mul ecx
		mov minutes,eax //зберігаю отриманий результат від множення остачі на 2 в змінну minutes
	
		mov eax,offset MINUTES
		push eax
		mov eax,minutes
		push eax
		mov eax,offset HOURS
		push eax                  //вирішила зробити виведення також через асемблер
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
