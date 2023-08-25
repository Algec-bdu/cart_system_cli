// display.h

#include "customer.h"
#include <iostream>
using namespace std;

class Display {
  public:
    void displayCustomerMenu();
    void displayPrimaryMenu(Customer *c);
    void displayProductList(Customer *c);
    void displayCart(Customer *c);
};


