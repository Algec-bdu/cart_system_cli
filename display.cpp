// display.cpp

#include "display.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

ProductList productList;
CustomerList customerList;

void Display::displayCustomerMenu() {
  system("clear");
  int op;
  cout << "*****Customer List*****" << endl;
  cout << "Select user:" << endl;
  for (int i=0; i<customerList.all_customer.size(); i++) {
    cout << "\t " << i+1 << " " << customerList.all_customer[i].getName() << endl;
  }
  cin >> op;
  switch (op) {
    case 1:
      displayPrimaryMenu(&customerList.all_customer[0]);
      break;
    case 2:
      displayPrimaryMenu(&customerList.all_customer[1]);
      break;
  }
}

void Display::displayPrimaryMenu(Customer *c) {
  int op;
  system("clear");
  cout << "*****Main Menu*****" << endl;
  cout << "1. Display Products" << endl;
  cout << "2. Cart" << endl;
  cout << "3. exit" << endl;
  cin >> op;
  if (op > 3 || op < 1) {
    cout << "Wrong option, please try again" << endl;
    displayPrimaryMenu(c);
  }
  switch (op) {
    case 1:
      displayProductList(c);
      break;
    case 2:
      displayCart(c);
      break;
  }
  cout << endl;
}

void Display::displayProductList(Customer *c) {
  system("clear");
  int op, id;
  cout << "*****Display Products*****" << endl;
  productList.display();
  while (true) {
    cout << "Enter id to add product to cart (Enter -1 to go cart): ";
    scanf("%d",&op);
    if (op == -1) {
      displayCart(c);
      return;
    }
    for (int i=0; i<productList.all_products.size(); i++) {
      if (productList.all_products[i].getID() == op) {
        c->addToCart(productList.all_products[i]);
        break;
      }
    }
    displayProductList(c);
  }
}

void Display::displayCart(Customer *c) {
  system("clear");
  cout << "*****Cart*****" << endl;
  float total = 0;
  int quantity;
  for (int i=0; i<c->getCart().added_product_list.size(); i++) {
    c->getCart().added_product_list[i].display();
    quantity = c->getCart().added_product_list[i].getQuantity();
    if (c->isPremium()) {
      cout << "Price per unit: " << c->getCart().added_product_list[i].getDiscountPrice() << endl;
      total += c->getCart().added_product_list[i].getDiscountPrice() * quantity;
    }
    else {
      cout << "Price per unit: " << c->getCart().added_product_list[i].getPrice() << endl;
      total += c->getCart().added_product_list[i].getPrice();
    }
    cout << endl;
  }
  cout << "Total Product Price: " << total << endl;
  if (c->isInsideDhaka()) {
    cout << "Shipping Charge: 60" << endl;
  }
  else {
    cout << "Shipping Charge: 120" << endl;
  }
  cout << endl;
}


