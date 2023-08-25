// cart.cpp

#include "cart.h"
#include <iostream>
using namespace std;

void ProductInCart::setValuesFromProduct(Product p) {
  this->id = p.getID();
  this->name = p.getName();
  this->price = p.getPrice();
  this->discount_price = p.getDiscountPrice();
  this->description = p.getDescription();
}

int ProductInCart::getQuantity() {
  return quantity;
}

void ProductInCart::addQuantity(){
  quantity++;
}

void ProductInCart::removeQuantity(){
  quantity--;
}

void Cart::addProduct(Product p) {
  for (int i=0; i<added_product_list.size(); i++) {
    if (added_product_list[i].getID() == p.getID()) {
      added_product_list[i].addQuantity();
      return;
    }
  }
  ProductInCart temp;
  temp.setValuesFromProduct(p);
  added_product_list.push_back(temp);
}

void Cart::removeProduct(Product p) {
  for (int i=0; i<added_product_list.size(); i++) {
    if (added_product_list[i].getID() == p.getID()){
      if(added_product_list[i].getQuantity() == 1){
        added_product_list.erase(added_product_list.begin()+i);
      }
      else {
        added_product_list[i].removeQuantity();
      }
      return;
    }
  }
}

void Cart::display() {
  for (int i=0; i<added_product_list.size(); i++) {
    cout << "Product name: " << added_product_list[i].getName() << endl;
    cout << "Product description: " << added_product_list[i].getDescription() << endl;
    cout << "from display of cart" << endl;
    cout << "Quantity: " << added_product_list[i].getQuantity() << endl;
  }
}

void ProductInCart::display() {
  Product::display();
  cout << "Quantity: " << quantity << endl;
}


