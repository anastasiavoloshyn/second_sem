#include <iostream>

class Vector {
	int* array;
	int n;
public:
	Vector(int* array = {}, int size=0): n(size), array(new int[n]){
		this->n = size;
		this->array = new int[n];
		for (int i = 0; i < n; i++) {
			this->array[i] = array[i];
		}
	}
	Vector(const Vector& v) {
		n=v.n;
		array = new int[n];
		for (int i = 0; i < n; i++) {
			 array[i]=v.array[i];
		}
	}
	Vector operator+(const Vector& v)const {
		Vector result;
		result.n = v.n;
		for (int i = 0; i < n; i++) {
			result.array[i] = this->array[i] + v.array[i];
		}
		return result;
	}
	Vector operator-(const Vector&v)const{
	Vector result;
	result.n=v.n;
	for(int i=0; i<v.n; i++){
		result.array[i]=this->array[i]-v.array[i];
	}
	return result;
	}
	
	Vector operator*(const Vector& v) const{
	
	Vector result;
	result.n=v.n;
	for(int i=0; i<v.n; i++){
		result.array[i]=this->array[i]*v.array[i];
	}
	return result;
	}
	Vector(Vector&v1, Vector&v2){
		 Vector result(v1.n);
        for(int i=0; i<v1.n;i++){
            result.array[i] = 0;
            result.array[i] += v1.array[i]*v2.array[i];
        }
        return result;
	}
	
	void Print() {
		for (int i = 0; i < n; i++) {
			std::cout << array[i] << " ";
		}
	}
};
int main() {
	int a[3] = { 1,2,3 };
	int b[3] = { 1,2,3 };
	Vector v1(a,3);
	Vector v2(b,3);
	Vector v3 = v1 + v2;
	Vector v4=v1-v2;
	Vector v5=v1*v2;
	v3.Print();
	v4.Print();
	v5.Print();
}
