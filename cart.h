// cart.h

#include "product.h"
#include <iostream>
using namespace std;

class ProductInCart: public Product {
  protected:
    int quantity = 1;
  public:
    int getQuantity();
    void addQuantity();
    void removeQuantity();
    void setValuesFromProduct(Product p);
    void display();
};

class Cart {
  public:
    vector<ProductInCart> added_product_list;
    void addProduct(Product p);
    void removeProduct(Product p);
    void display();
};



