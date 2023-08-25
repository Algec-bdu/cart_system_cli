// customer.cpp

#include "customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string name, string phone, string address, bool inside_dhaka, bool premium) {
  this->name = name;
  this->phone = phone;
  this->address = address;
  this->inside_dhaka = inside_dhaka;
  this->premium = premium;
}

void Customer::addCart(Cart c) {
  this->cart = c;
}

string Customer::getName() {return name;}
string Customer::getPhone() {return phone;}
string Customer::getAddress() {return address;}
bool Customer::isInsideDhaka() {return inside_dhaka;}
bool Customer::isPremium() {return premium;}
Cart Customer::getCart() {return cart;}
void Customer::addToCart(Product p) {cart.addProduct(p);}


CustomerList::CustomerList() {
  all_customer.push_back(Customer("Ahmmad Jobayer", "0162516664", "Kaliakoir", false, true));
  all_customer.push_back(Customer("Naim Hamim", "01326876516", "Mirpur", true, false));
}


