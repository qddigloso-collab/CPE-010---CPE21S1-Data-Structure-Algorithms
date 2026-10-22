#include <iostream>
#include <string>

class GroceryItem {
private:
    std::string itemName;
    double itemPrice;
    int itemQuantity;
    std::string itemType;

public:
    GroceryItem(std::string newName = "Unknown", int newQuantity = 0, double newPrice = 0.0, std::string newType = "Item") {
        itemName = std::move(newName);
        itemPrice = newPrice;
        itemQuantity = newQuantity;
        itemType = std::move(newType);
        std::cout << "Constructor Called." << std::endl;
    }

    virtual ~GroceryItem() {
        std::cout << "Destructor Called." << std::endl;
    }

    GroceryItem(const GroceryItem& copyItem) {
        std::cout << "Copy Constructor Called" << std::endl;
        itemName = copyItem.itemName;
        itemPrice = copyItem.itemPrice;
        itemQuantity = copyItem.itemQuantity;
        itemType = copyItem.itemType;
    }

    GroceryItem& operator=(const GroceryItem& copyItem) {
        std::cout << "Copy Assignment Operator Called" << std::endl;
        if (this != &copyItem) {
            itemName = copyItem.itemName;
            itemPrice = copyItem.itemPrice;
            itemQuantity = copyItem.itemQuantity;
            itemType = copyItem.itemType;
        }
        return *this;
    }

    double calculateSum() {
        return this->itemPrice * this->itemQuantity;
    }

    void printDetails() {
        std::cout << this->itemName << " (" << this->itemType << ") - PHP " 
        << this->itemPrice << " x" << this->itemQuantity << " | Subtotal: PHP " << this->calculateSum() << std::endl;
    }

    std::string getName() {
        return this->itemName;
    }
};

class Fruit : public GroceryItem {
public:
    Fruit(std::string newName, double newPrice, int newQuantity)
        : GroceryItem(newName, newQuantity, newPrice, "Fruit") {}

    ~Fruit() override {
        std::cout << "Fruit Destructor Called." << std::endl;
    }
};

class Vegetable : public GroceryItem {
public:
    Vegetable(std::string newName, double newPrice, int newQuantity)
        : GroceryItem(newName, newQuantity, newPrice, "Vegetable") {}

    ~Vegetable() override {
        std::cout << "Vegetable Destructor Called." << std::endl;
    }
};

double TotalSum(GroceryItem* list[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        if (list[i] != nullptr) {
            total += list[i]->calculateSum();
        }
    }
    return total;
}

int main() {
    const size_t j = 4;
    std::string productRemove;
    GroceryItem* groceryList[j] = {};

    groceryList[0] = new Fruit("Apple", 10.0, 7);
    groceryList[1] = new Fruit("Banana", 10.0, 8);
    groceryList[2] = new Vegetable("Broccoli", 60.0, 12);
    groceryList[3] = new Vegetable("Lettuce", 50.0, 10);

    std::cout << " " << std::endl;
    std::cout << "Grocery List Details ---------------------------------" << std::endl;
    for (size_t i = 0; i < j; i++) {
        if (groceryList[i] != nullptr) {
            groceryList[i]->printDetails();
        }
    }

    std::cout << " " << std::endl;
    std::cout << "Total Bill: PHP " << TotalSum(groceryList, j) << std::endl << std::endl;

    std::cout << "Enter a product to remove: ";
    std::cin >> productRemove;
    std::cout << "Product Remove: " << productRemove << std::endl;
    std::cout << " " << std::endl;
    for (size_t i = 0; i < j; i++) {
        if (groceryList[i] != nullptr && groceryList[i]->getName() == productRemove) {
            delete groceryList[i];
            groceryList[i] = nullptr;
            break;
        }
    }

    std::cout << " " << std::endl;
    std::cout << "Updated Total Bill: PHP " << TotalSum(groceryList, j) << std::endl << std::endl;

    for (size_t i = 0; i < j; i++) {
        if (groceryList[i] != nullptr) {
            delete groceryList[i];
        }
    }

    return 0;
}