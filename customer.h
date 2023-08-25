// customer.h

#include "cart.h"
#include <iostream>
using namespace std;

class Customer {
  protected:
    string name;
    string phone;
    string address;
    bool inside_dhaka;
    bool premium;
    Cart cart;
  public:
    Customer(string name, string phone, string address, bool inside_dhaka, bool premium);
    string getName();
    string getPhone();
    string getAddress();
    bool isInsideDhaka();
    bool isPremium();
    void addCart(Cart c);
    void addToCart(Product p);
    Cart getCart();
};

class CustomerList {
  public:
    vector<Customer> all_customer;
    CustomerList();
    void display();
};


