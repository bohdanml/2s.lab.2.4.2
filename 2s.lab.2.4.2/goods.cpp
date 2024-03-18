#include "goods.h"

Goods::Goods() : code(0), name(""), price(0.0), quantity(0) {}
Goods::Goods(int code, std::string name, double price, int quantity) : code(code), name(name), price(price), quantity(quantity) {}
Goods::Goods(const Goods& other) : code(other.code), name(other.name), price(other.price), quantity(other.quantity) {}

int Goods::getCode() const { return code; }
std::string Goods::getName() const { return name; }
double Goods::getPrice() const { return price; }
int Goods::getQuantity() const { return quantity; }

void Goods::setCode(int newCode) { code = newCode; }
void Goods::setName(std::string newName) { name = newName; }
void Goods::setPrice(double newPrice) { price = newPrice; }
void Goods::setQuantity(int newQuantity) { quantity = newQuantity; }

double Goods::calculateTotalPrice() const { return price * quantity; }