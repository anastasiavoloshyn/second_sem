#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Product {
protected:
	string name;
	double price;
	int amount;
public:
	Product(string name="", double price = 0, int amount = 0):name(name),price(price),amount(amount){ }
	string getName() {
		return name;
	}
	double getPrice() {
		return price;
	}
	int getAmount() {
		return amount;
	}
	friend istream& operator>>(std::istream& is, Product& p) {
		p.read(is);
		return is;
	}
	friend ostream& operator <<(std::ostream& os, const Product& p) {
		p.print(os);
		return os;
	}
	virtual void print(std::ostream& os)const {
		os << "P: " << name << " " << price << " " << amount;
	}
	virtual void read(std::istream& is) {
		is >> name >> price >> amount;
	}
	virtual int getSale() {
		return 0.0;
	}
	virtual void setSale(int sale) {
		
	}

};

class SaleProduct: public Product{
private:
	int sale;
public:
	SaleProduct(string name = "", double price = 0, int amount = 0,int sale=0): Product(name,price,amount),sale(sale){ }
	friend istream& operator>>(istream& is, SaleProduct& s) {
		s.read(is);
		return is;
	}
	friend ostream& operator<<(ostream& os, const SaleProduct& s) {
		s.print(os);
		return os;
	}
	void read(std::istream& is) {
		is >>name >> price >> amount >>sale;
	}
	void print(std::ostream& os)const override {
		os <<"S"<< " " << name << " " << price << " " << amount << " " << sale;
	}
	int getSale()override {
		return sale;
	}
	void setSale(int sale_)override {
		sale = sale_;
	}
};

void sort(Product** arr,int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j]->getName() > arr[j + 1]->getName()) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}


int main()
{	

	ifstream fin("data.txt");
	int size;
	fin >> size;
	char type;

	Product** arr = new Product* [size];
	for (int i = 0; i < size; i++) {
		fin >> type;
		if (type == 'p') {
			arr[i] = new Product;
			arr[i]->read(fin);
		}
		if (type == 's') {
			arr[i] = new SaleProduct;
			arr[i]->read(fin);
		}
		
	}

	sort(arr, size);
	ofstream fout("data1.txt");
	fout << size << "\n";
	for (int i = 0; i < size; i++) {
		
		arr[i]->print(fout);
		fout << "\n";
	}



	std::cout << "array:\n";
	for (int i = 0; i < size; i++) {
		arr[i]->print(std::cout);
		std::cout << "\n";
	}
	double sum = 0;
	for (int i = 0; i < size; i++) {
		if (dynamic_cast<SaleProduct*>(arr[i]) != nullptr) {
			sum += arr[i]->getPrice();
		}
	}
	std::cout <<"Sum price of sale product:  " << sum << "\n";
	Product* maxPrice=arr[0];

	for (int i = 0; i < size; i++) {
		if (arr[i]->getPrice() > maxPrice->getPrice()) {
			maxPrice = arr[i];
			if ((dynamic_cast<SaleProduct*>(arr[i])) != nullptr) {
				maxPrice->setSale(maxPrice->getSale() + 5);
			}
			else {
				maxPrice = new SaleProduct(arr[i]->getName(), arr[i]->getPrice(), arr[i]->getAmount(), 20);
			}
		}
	}
	std::cout << "changed product with maxprice: ";
	maxPrice->print(std::cout);
	std::cout << "\n";
	



	std::cout << "sorted by name array\n";
	for (int i = 0; i < size; i++) {
		arr[i]->print(std::cout);
		std::cout << "\n";
	}
	


	
}