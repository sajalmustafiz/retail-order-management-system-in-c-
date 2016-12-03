#include "Product.cpp"
#include "Customer.cpp"
#include "Order.cpp"

class ManagementSystem {
public:
    ManagementSystem() {
        CustomerTracker = 0;
        ProductTracker = 0;
    }

    void ShowMenu() {
        int Option = 0;

        while(Option != 6) {
            cout << "1: Add Customer" << endl;
            cout << "2: Add Product" << endl;
            cout << "3: Show Customers List" << endl;
            cout << "4: Show Product List" << endl;
            cout << "5: Place Order" << endl;
            cout << "6: Exit" << endl;
            cout << "Enter 1 - 6 to select an option: ";
            cin >> Option;

            if(Option == 1) {
                AddCustomer();
            }
            else if(Option == 2) {
                AddProduct();
            }
            else if(Option == 3) {
                ShowCustomerList();
            }
            else if(Option == 4) {
                showProductsList();
            }
            else if(Option == 5) {
                PlaceOrder();
            }
        }
    }

private:
    void AddCustomer() {
        Customer tempCustomer;
        string inp;
        int idInp;

        cout << "Enter customer id: ";
        cin >> idInp;
        cin.ignore();
        tempCustomer.SetID(idInp);

        cout << "Enter customer name: ";
        getline(cin, inp);
        tempCustomer.SetName(inp);

        cout << "Enter customer address: ";
        getline(cin, inp);
        tempCustomer.SetAddress(inp);

        cout << "Enter contact number: ";
        getline(cin, inp);
        tempCustomer.SetContactNumber(inp);

        CustomerArray[CustomerTracker++] = tempCustomer;

        cout << "Customer Recorded!" << endl << endl;
    }

    void AddProduct() {
        string inp;
        int idInp;
        int qunatityInp;
        double productPrice;
        Product tempProduct;

        cout << "Enter ID: ";
        cin >> idInp;
        cin.ignore();
        tempProduct.SetProductIDNumber(idInp);

        cout << "Enter Product Name: ";
        getline(cin, inp);
        tempProduct.SetProductName(inp);

        cout << "Enter Product Price: ";
        cin >> productPrice;
        tempProduct.SetPrice(productPrice);

        cout << "Enter product quantity in stock: ";
        cin >> qunatityInp;
        tempProduct.SetQuantity(qunatityInp);

        ProductArray[ProductTracker++] = tempProduct;
        cout << "Product Recorded!" << endl << endl;
    }

    void ShowCustomerList() {
        for(int i = 0; i < CustomerTracker; i++) {
            cout << endl << endl << "Customer ID: " << CustomerArray[i].GetID() << endl;
            cout << "Customer Name: " << CustomerArray[i].GetName() << endl;
            cout << "Customer Address: " << CustomerArray[i].GetAddress() << endl;
            cout << "Customer Contact Number: " << CustomerArray[i].GetContactNumber() << endl << endl;
        }
    }

    void showProductsList() {
        for(int i = 0; i < ProductTracker; i++) {
            cout << endl << endl << "Product ID: " << ProductArray[i].GetProductIDNumber() << endl;
            cout << "Product Name: " << ProductArray[i].GetProductName() << endl;
            cout << "Product Price: " << ProductArray[i].GetPrice() << endl;
            cout << "Product Quantity in Stock: " << ProductArray[i].GetQuantity() << endl << endl;
        }
    }

    void PlaceOrder() {
        Order NewOrder;
        OrderItem NewOrderItem;
        Product p;
        Customer c;

        int OrderID = 0;
        int CustomerID = 0;
        int ProductID = 0;
        int ProductQuantity = 0;

        char addNewItem = 'Y';
        char proceedSale = 'Y';

        cout << "Enter Order ID: ";
        cin >> OrderID;
        NewOrder.SetOrderID(OrderID);

        ShowCustomerList();

        cout << endl << endl << "Insert Customer ID from the list to select: ";
        cin >> CustomerID;

        while(addNewItem == 'Y' || addNewItem == 'y') {
            showProductsList();

            cout << endl << endl << "Insert Product ID from the list to select: ";
            cin >> ProductID;
            p = GetProductByID(ProductID);

            cout << "Enter Order Quantity: ";
            while(cin >> ProductQuantity) {
                if(ProductQuantity > p.GetQuantity()) {
                    cout << "Invalid quantity, try again: ";
                }
                else {
                    break;
                }
            }

            NewOrderItem.SetOrderID(OrderID);
            NewOrder.SetCustomerID(CustomerID);
            NewOrderItem.SetProductID(ProductID);
            NewOrderItem.SetQuantity(ProductQuantity);
            NewOrderItem.SetTotalPrice(p.GetPrice() * ProductQuantity);
            NewOrder.AddOrderItem(NewOrderItem);

            cout << "Would you like to add another product[Y/y-N/n]: ";
            cin >> addNewItem;
        }

        NewOrder.ShowReport();
        cout << "Proceed With Purchase[Y/y-N/n]: ";
        cin >> proceedSale;

        if(proceedSale == 'Y' || proceedSale == 'y') {
            sale(NewOrder);
        }

        cout << endl << "Done" << endl;
    }

    Product GetProductByID(int ID) {
        for(int i = 0; i < ProductTracker; i++) {
            if(ProductArray[i].GetProductIDNumber() == ID) return ProductArray[i];
        }
    }

    Customer GetCustomerByID(int ID) {
        for(int i = 0; i < CustomerTracker; i++) {
            if(CustomerArray[i].GetID() == ID) return CustomerArray[i];
        }
    }

    void sale(Order ord) {
        for(int i = 0; i < ord.OrderTracker; i++) {
            int prodID = ord.OrderItemArray[i].GetProductID();

            for(int j = 0; j < ProductTracker; j++) {
                if(ProductArray[j].GetProductIDNumber() == prodID) {
                    ProductArray[j].SetQuantity(ProductArray[j].GetQuantity() - ord.OrderItemArray[i].GetQuantity());
                }
            }
        }
    }

private:
    Product ProductArray[100];
    Customer CustomerArray[100];
    int CustomerTracker;
    int ProductTracker;
};
