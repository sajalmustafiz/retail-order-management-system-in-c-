
class OrderItem {
public:
    OrderItem() {
        ProductID = 0;
        OrderID = 0;
        Quantity = 0;
        TotalpPrice = 0;
    }

    void SetProductID(int pid) {
        ProductID = pid;
    }

    int GetProductID() {
        return ProductID;
    }

    void SetOrderID(int oid) {
        OrderID = oid;
    }

    int GetOrderID() {
        return OrderID;
    }

    void SetQuantity(int qty) {
        Quantity = qty;
    }

    int GetQuantity() {
        return Quantity;
    }

    void SetTotalPrice(double price) {
        TotalpPrice = price;
    }

    double GetTotalPrice() {
        return TotalpPrice;
    }

private:
    int ProductID;
    int OrderID;
    int Quantity;
    double TotalpPrice;
};
