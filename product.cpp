// product.cpp

#include "product.h"
#include <iostream>
#include <vector>
using namespace std;

Product::Product(string name, double price, double discount, string description) {
  this->id = ++counter;
  this->name = name;
  this->price = price;
  this->discount_price = price * (1-(discount/100));
  this->description = description;
}

Product::Product() {}

int Product::getID() const{
  return id;
}

void Product::setName(string name) {
  this->name = name;
}

string Product::getName() {
  return name;
}

void Product::setPrice(double price) {
  this->price = price;
  this->discount_price = price * (1-(discount_price/100));
}

double Product::getPrice() {
  return price;
}

double Product::getDiscountPrice() {
  return discount_price;
}

string Product::getDescription(){
  return description;
}

int Product::counter = 0;

void ProductList::addProduct(Product p) {
  all_products.push_back(p);
}

ProductList::ProductList() {
  all_products.push_back(Product("mango", 100, 2, "very good domestic mango"));
  all_products.push_back(Product("blackberry", 300, 15, "from wakanda, premium, jucy"));
  all_products.push_back(Product("lichi", 150, 5, "have a lot of nutritious insect inside"));
}

void Product::display() {
  cout << "ID: " << this->id << endl;
  cout << "Name: " << this->name << endl;
  cout << "Description: " << this->description << endl;
  cout << "Price: " << this->price << endl;
  cout << "Discount Price: " << this->discount_price << endl;
}
  
void ProductList::display() {
  for (int i=0; i<this->all_products.size(); i++) {
    all_products[i].display();
    cout << endl;
    if(i == this->all_products.size()-1) cout << endl;
  }
}


