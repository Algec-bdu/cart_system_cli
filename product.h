// product.h

#include <iostream>
#include <vector>
using namespace std;

class Product {
  protected:
    int id;
    static int counter;
    string name;
    double price;
    string description;
    double discount_price;
  public:
    Product(string name, double price, double discount, string description);
    Product();
    int getID() const;
    void setName(string name);
    string getName();
    void setPrice(double price);
    double getPrice();
    double getDiscountPrice();
    string getDescription();
    void display();
};

class ProductList {
  public:
    vector<Product> all_products;
    void addProduct(Product p);
    ProductList();
    void display();
};


