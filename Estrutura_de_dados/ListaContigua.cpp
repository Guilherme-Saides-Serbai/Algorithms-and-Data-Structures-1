#include <iostream>
#include <stdexcept>

class Vetor {
private:
    int* array;
    int capacity;
    int size;

    void gerenciaCapacidade() {
        if (size == capacity) {
            // Dobrar a capacidade
            capacity = capacity == 0 ? 1 : capacity * 2;
            int* newArray = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        } else if (size <= capacity / 4 && capacity > 1) {
            // Reduzir a capacidade pela metade
            capacity /= 2;
            int* newArray = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    }

public:
    Vetor() : array(nullptr), capacity(0), size(0) {}

    ~Vetor() {
        delete[] array;
    }

    bool push_back(int e) {
        gerenciaCapacidade();
        array[size++] = e;
        return true;
    }

    bool push_front(int e) {
        gerenciaCapacidade();
        for (int i = size; i > 0; --i) {
            array[i] = array[i - 1];
        }
        array[0] = e;
        ++size;
        return true;
    }

    bool insert(int pos, int e) {
        if (pos < 0 || pos > size) return false;
        gerenciaCapacidade();
        for (int i = size; i > pos; --i) {
            array[i] = array[i - 1];
        }
        array[pos] = e;
        ++size;
        return true;
    }

    int pop_back() {
        if (size == 0) throw std::out_of_range("Vetor is empty");
        return array[--size];
    }

    int pop_front() {
        if (size == 0) throw std::out_of_range("Vetor is empty");
        int value = array[0];
        for (int i = 0; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        --size;
        return value;
    }

    int erase(int pos) {
        if (pos < 0 || pos >= size) throw std::out_of_range("Index out of range");
        int value = array[pos];
        for (int i = pos; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        --size;
        gerenciaCapacidade();
        return value;
    }

    int front() const {
        if (size == 0) throw std::out_of_range("Vetor is empty");
        return array[0];
    }

    int back() const {
        if (size == 0) throw std::out_of_range("Vetor is empty");
        return array[size - 1];
    }

    int at(int pos) const {
        if (pos < 0 || pos >= size) throw std::out_of_range("Index out of range");
        return array[pos];
    }

    void clear() {
        size = 0;
        gerenciaCapacidade(); // Reduz a capacidade se necessário
    }

    bool empty() const {
        return size == 0;
    }

    int size() const {
        return size;
    }

    bool replace(int pos, int e) {
        if (pos < 0 || pos >= size) return false;
        array[pos] = e;
        return true;
    }

    void print() const {
        std::cout << "[";
        for (int i = 0; i < size; ++i) {
            std::cout << array[i];
            if (i < size - 1) std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    Vetor v;
    v.push_back(1);
    v.push_back(2);
    v.push_front(0);
    v.insert(2, 5);
    v.print(); // Output: [0,1,5,2]

    v.pop_back();
    v.pop_front();
    v.erase(1);
    v.print(); // Output: [1]

    return 0;
}
