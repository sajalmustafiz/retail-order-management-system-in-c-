#include "OrderItem.cpp"

class Order {
public:
    Order() {
        OrderTracker = 0;
        OrderID = 0;
        CustomerID = 0;
    }

    void SetOrderID(int id) {
        OrderID = id;
    }

    int GetOrderID() {
        return OrderID;
    }

    void SetCustomerID(int id) {
        CustomerID = id;
    }

    int GetCustomerID() {
        return CustomerID;
    }

    void AddOrderItem(OrderItem OI) {
        OrderItemArray[OrderTracker++] = OI;
    }

    void ShowReport() {
        double GrandTotal = 0.0;

        for(int i = 0; i < OrderTracker; i++) {
            cout << "Product ID: " << OrderItemArray[i].GetProductID() << endl;
            cout << "Quantity: " << OrderItemArray[i].GetQuantity() << endl;
            cout << "Total Price: " << OrderItemArray[i].GetTotalPrice() << endl << endl;

            GrandTotal += OrderItemArray[i].GetTotalPrice();
        }

        cout << "Grand Total: " << GrandTotal << endl;
    }

public:
    OrderItem OrderItemArray[100];
    int OrderTracker;

private:
    int OrderID;
    int CustomerID;
};
