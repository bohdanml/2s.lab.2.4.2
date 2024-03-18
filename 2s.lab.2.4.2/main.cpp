#include <iostream>
#include <vector>
#include "goods.h"
#include "receipt.h"

int main() {
    int receiptNumber;
    std::string creationDateTime;
    std::vector<Goods> items;

    // Введення номера чеку
    std::cout << "Enter receipt number: ";
    std::cin >> receiptNumber;

    // Введення дати і часу створення чеку
    std::cout << "Enter creation date and time (YYYY-MM-DD HH:MM:SS): ";
    std::cin.ignore(); // Ігноруємо символ нового рядка після попереднього введення
    std::getline(std::cin, creationDateTime);

    // Введення товарів
    int numItems;
    std::cout << "Enter number of items: ";
    std::cin >> numItems;

    for (int i = 0; i < numItems; ++i) {
        int code, quantity;
        double price;
        std::string name;

        std::cout << "\nEnter details for item " << i + 1 << ":" << std::endl;
        std::cout << "Code: ";
        std::cin >> code;
        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Price: ";
        std::cin >> price;
        std::cout << "Quantity: ";
        std::cin >> quantity;

        items.push_back(Goods(code, name, price, quantity));
    }

    // Створення об'єкту чеку
    Receipt receipt(receiptNumber, creationDateTime, items);

    // Вивід інформації
    std::cout << "\nReceipt Information:" << std::endl;
    std::cout << "Receipt Number: " << receipt.getReceiptNumber() << std::endl;
    std::cout << "Creation Date and Time: " << receipt.getCreationDateTime() << std::endl;
    std::cout << "Items:" << std::endl;
    for (const Goods& item : receipt.getItems()) {
        std::cout << "Code: " << item.getCode() << ", Name: " << item.getName() << ", Price: " << item.getPrice() << ", Quantity: " << item.getQuantity() << std::endl;
    }
    std::cout << "Total Amount: " << receipt.calculateTotalAmount() << std::endl;

    // Додавання нового товару
    int option;
    std::cout << "\nOptions:\n1. Add Item\n2. Change Item\n3. Remove Item\n4. Search Item by Code\nEnter option: ";
    std::cin >> option;

    switch (option) {
    case 1: {
        int code, quantity;
        double price;
        std::string name;

        std::cout << "\nEnter details for new item:" << std::endl;
        std::cout << "Code: ";
        std::cin >> code;
        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Price: ";
        std::cin >> price;
        std::cout << "Quantity: ";
        std::cin >> quantity;

        receipt.addItem(Goods(code, name, price, quantity));
        break;
    }
    case 2: {
        int index, code, quantity;
        double price;
        std::string name;

        std::cout << "Enter index of item to change: ";
        std::cin >> index;
        std::cout << "Enter new details for item:" << std::endl;
        std::cout << "Code: ";
        std::cin >> code;
        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Price: ";
        std::cin >> price;
        std::cout << "Quantity: ";
        std::cin >> quantity;

        receipt.changeItem(index, Goods(code, name, price, quantity));
        break;
    }
    case 3: {
        int index;
        std::cout << "Enter index of item to remove: ";
        std::cin >> index;
        receipt.removeItem(index);
        break;
    }
    case 4: {
        int code;
        std::cout << "Enter code of item to search: ";
        std::cin >> code;
        Goods foundItem = receipt.findItemByCode(code);
        if (foundItem.getCode() != 0) {
            std::cout << "Item found: Code: " << foundItem.getCode() << ", Name: " << foundItem.getName() << ", Price: " << foundItem.getPrice() << ", Quantity: " << foundItem.getQuantity() << std::endl;
        }
        else {
            std::cout << "Item with code " << code << " not found." << std::endl;
        }
        break;
    }
    default:
        std::cout << "Invalid option!" << std::endl;
    }

    // Оновлена інформація про чек
    std::cout << "\nUpdated Receipt Information:" << std::endl;
    std::cout << "Receipt Number: " << receipt.getReceiptNumber() << std::endl;
    std::cout << "Creation Date and Time: " << receipt.getCreationDateTime() << std::endl;
    std::cout << "Items:" << std::endl;
    for (const Goods& item : receipt.getItems()) {
        std::cout << "Code: " << item.getCode() << ", Name: " << item.getName() << ", Price: " << item.getPrice() << ", Quantity: " << item.getQuantity() << std::endl;
    }
    std::cout << "Total Amount: " << receipt.calculateTotalAmount() << std::endl;

    return 0;
}
