#pragma once

#include "goods.h"
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Receipt {
private:
    int receiptNumber;
    std::string creationDateTime;
    std::vector<Goods> items;
public:
    Receipt();
    Receipt(int number, std::string dateTime, std::vector<Goods> itemList);
    Receipt(const Receipt& other);

    int getReceiptNumber() const;
    std::string getCreationDateTime() const;
    std::vector<Goods> getItems() const;

    void setReceiptNumber(int newNumber);
    void setCreationDateTime(std::string newDateTime);
    void setItems(std::vector<Goods> newItemList);

    void addItem(const Goods& newItem);
    void changeItem(int index, const Goods& newItem);
    void removeItem(int index);

    Goods findItemByCode(int code) const;
    double calculateTotalAmount() const;

    const Goods& operator[](size_t index) const;
    Goods& operator[](size_t index);
};