#include <iostream>
using namespace std;

class Product {
public:
    Product() {
        ProductIDNumber = 0;
        ProductName = "";
        Price = 0.0;
        Quantity = 0;
    }

    void SetProductIDNumber(int idNumber) {
        ProductIDNumber = idNumber;
    }

    void SetProductName(string name) {
        ProductName = name;
    }

    void SetPrice(double p) {
        Price = p;
    }

    void SetQuantity(int Q) {
        Quantity = Q;
    }

    int GetProductIDNumber() {
        return ProductIDNumber;
    }

    string GetProductName() {
        return ProductName;
    }

    double GetPrice() {
        return Price;
    }

    int GetQuantity() {
        return Quantity;
    }

private:
    int ProductIDNumber;
    string ProductName;
    double Price;
    int Quantity;
};
