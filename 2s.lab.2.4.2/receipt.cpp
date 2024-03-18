#include "receipt.h"

Receipt::Receipt() : receiptNumber(0), creationDateTime(""), items(std::vector<Goods>()) {}
Receipt::Receipt(int number, std::string dateTime, std::vector<Goods> itemList) : receiptNumber(number), creationDateTime(dateTime), items(itemList) {}
Receipt::Receipt(const Receipt& other) : receiptNumber(other.receiptNumber), creationDateTime(other.creationDateTime), items(other.items) {}

int Receipt::getReceiptNumber() const { return receiptNumber; }
std::string Receipt::getCreationDateTime() const { return creationDateTime; }
std::vector<Goods> Receipt::getItems() const { return items; }

void Receipt::setReceiptNumber(int newNumber) { receiptNumber = newNumber; }
void Receipt::setCreationDateTime(std::string newDateTime) { creationDateTime = newDateTime; }
void Receipt::setItems(std::vector<Goods> newItemList) { items = newItemList; }

void Receipt::addItem(const Goods& newItem) { items.push_back(newItem); }
void Receipt::changeItem(int index, const Goods& newItem) { items[index] = newItem; }
void Receipt::removeItem(int index) { items.erase(items.begin() + index); }

Goods Receipt::findItemByCode(int code) const {
    for (const Goods& item : items) {
        if (item.getCode() == code)
            return item;
    }
    return Goods(); // Return empty Goods object if not found
}

double Receipt::calculateTotalAmount() const {
    double totalAmount = 0.0;
    for (const Goods& item : items) {
        totalAmount += item.calculateTotalPrice();
    }
    return totalAmount;
}
const Goods& Receipt::operator[](size_t index) const {
    if (index < items.size())
        return items[index];
    throw std::out_of_range("Index out of range");
}

Goods& Receipt::operator[](size_t index) {
    if (index < items.size())
        return items[index];
    throw std::out_of_range("Index out of range");
}