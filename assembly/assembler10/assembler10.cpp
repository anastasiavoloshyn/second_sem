#include <iostream>
char conjs[2][8] = {
	{ 1, 1, 0, 0, 0, 0, 1, 1 },
	{ 0, 1, 0, 1, 0, 1, 1, 1 }
};

int res = 0x0;

// edi - conjunctions
// edx - outer loop counter
// cl  - conjs element
// ebx - inner loop counter

int main() {
	char byte = 0x10101010;
	__asm {
		mov al, byte
		mov res, eax
	}
	std::cout << res;
	/*__asm {
		lea edi, conjs
		mov edx, 2
	start:
		mov cl, [edi]
		mov ebx, 8
		start_inner:
			mov al, byte
			
		end_inner:
			dec ebx
			test ebx, ebx
			jnz start_inner
	end:
		dec edx
		test edx, edx
		jnz start
	mov res, eax
	}
	std::cout << res;
	return 0;*/
}