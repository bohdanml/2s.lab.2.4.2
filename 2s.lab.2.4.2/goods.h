#pragma once

#include <string>

class Goods {
private:
    int code;
    std::string name;
    double price;
    int quantity;
public:
    Goods();
    Goods(int code, std::string name, double price, int quantity);
    Goods(const Goods& other);

    int getCode() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;

    void setCode(int newCode);
    void setName(std::string newName);
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);

    double calculateTotalPrice() const;
};