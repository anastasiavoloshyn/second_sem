#include <iostream>

using namespace std;

class BitSet {
    int set[8] = { 0 };

public:
    void Add(char new_el) {
        int idx = new_el / 32;
        int bitmask = 1 << (new_el % 32);
        set[idx] |= bitmask;
        
    }
    void remove(char el) {
        int idx = el / 32;
        int bitmask = 1 << (el % 32);
        set[idx] &= (~bitmask);
    }
    bool In(char element) {
        int idx = element / 32;
        int bitmask = 1 << (element % 32);
        return set[idx] & bitmask;
    }

    BitSet Intersect(BitSet other) {
        BitSet result;
        for (int i = 0; i < 8; i++) {
            result.set[i] = this->set[i] & other.set[i];
        }
        return result;
    }

    BitSet Union(BitSet other) {
        BitSet result;
        for (int i = 0; i < 8; i++) {
            result.set[i] = this->set[i] | other.set[i];
        }
        return result;
    }

    BitSet operator -(const BitSet& other) const {
        BitSet result;
        for (int i = 0; i < 8; i++) {
            result.set[i] = this->set[i] & ~other.set[i];
        }
        return result;
    }
    friend std::ostream& operator<<(std::ostream& os, const BitSet& b) {
        for (int i = 7; i >= 0; i--) {
            for (int j = 31; j >= 0; j--) {
                os << ((b.set[i] & (1 << j)) ? '1' : '0');
            }
        }
        return os;
    }
 

};



void tests() {
    BitSet set1;
    BitSet set2;
    BitSet set3;

    if (set1.In('-')) cout << "test 1 failed\n";
    else cout << "test 1 passed;\n"; 
    set1.Add('-');
    if (!set1.In('-')) cout << "test 2 failed\n";
    else cout << "test 2 passed;\n"; 
    set2.Add('w');
    set2.Add('o');
    set2.Add('-');
    set3 = set1.Union(set2);
    if (!set3.In('-') || !set3.In('w') || !set3.In('o')) cout << "test 3 failed\n";
    else cout << "test 3 passed;\n"; 
    set3 = set1.Intersect(set2);
    if (!set3.In('-') || set3.In('w') || set3.In('o')) cout << "test 4 failed\n";
    else cout << "test 4 passed;\n"; 
    set3 = set2 - set1;
    if (set3.In('-')&&(!set3.In('w')||!set3.In('o'))) cout << "test 5 failed\n";
    else cout << "test 5 passed;\n";
    std::cout << '\n' << set3;
}


int main() {
    tests();
}