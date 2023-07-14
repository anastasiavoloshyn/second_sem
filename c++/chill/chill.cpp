#include <iostream>
#include <string>

// базовий клас продукту
template <typename T>
class Product {
public:
    virtual void display() = 0;
    virtual T get_price() = 0;
};

template <typename T>
class Book : public Product<T> {
private:
    std::string title;
    std::string author;
    T price;
public:
    Book(std::string title, std::string author, T price) : title(title), author(author), price(price) {}
    void display() {
        std::cout << "Book: " << title << " by " << author << std::endl;
    }
    T get_price() {
        return price;
    }
};

template <typename T>
class Movie : public Product<T> {
private:
    std::string title;
    std::string director;
    T price;
public:
    Movie(std::string title, T price, std::string director) : title(title), price(price), director(director) {}
    void display() {
        std::cout << "Movie: " << title << " by " << director << std::endl;
    }
    T get_price() {
        return price;
    }
};

template <typename T>
class Store {
private:
    Product<T>** products;
    int count;
public:
    Store() : products(nullptr), count(0) {}
    void add_product(Product<T>* product) {
        Product<T>** tmp = new Product<T> * [count + 1];
        for (int i = 0; i < count; i++) {
            tmp[i] = products[i];
        }
        tmp[count] = product;
        count++;
        if (products != nullptr) {
            delete[] products;
        }
        products = tmp;
    }
    void display_products() {
        for (int i = 0; i < count; i++) {
            products[i]->display();
        }
    }
    T get_total_price() {
        T total = 0;
        for (int i = 0; i < count; i++) {
            total += products[i]->get_price();
        }
        return total;
    }
};
int main() {
    Store<int> store;


    Product<int>* book = new Book<int>("The Great Gatsby", "F. Scott Fitzgerald", 10);
    Product<int>* movie = new Movie<int>("The Godfather",  15, "Francis Ford Coppola");
    store.add_product(book);
    store.add_product(movie);


    store.display_products();
    std::cout << "Total price: " << store.get_total_price() << std::endl;

    return 0;
}