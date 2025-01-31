#include <iostream>
#include <string>

class Invoice {
public:

    // constructor to initialize the data members
    explicit Invoice(std::string partNumber, std::string desc, int quant, int cost)
        : partNum{ partNumber }, description{ desc },
        quantity{ quant }, itemCost{ cost } {

        // checks to see if a negative has been entered
        if (itemCost <= 0) {
            std::cout << "Cost cannot be negative";
            itemCost = 0;
        }

        // checks to see if a negative has been entered
        if (quantity <= 0) {
            std::cout << "Quantity cant be negative";
            quantity = 0;
        }

    }

    // sets and gets the part number received
    void setPartNumber(std::string partNumber) {
        partNum = partNumber;
    }

    std::string getPartNumber() const {
        return partNum;
    }

    // sets and gets the part description received
    void setDescription(std::string desc) {
        description = desc;
    }

    std::string getDescription() const {
        return description;
    }

    // sets and gets the quantity of the item purchased
    void setQuantity(int quant) {

        // if the quantity is less than zero, set quantity to 0
        if (quant > 0) {
            quantity = quant;
        }
        else {
            quantity = 0;
        }
    }

    int getQuantity() const {
        return quantity;
    }

    // sets and gets the price of the item purchased
    void setPrice(int cost) {

        // if the price is less than zero, set it to 0
        if (cost > 0) {
            itemCost = cost;
        }
        else {
            itemCost = 0;
        }
    }

    int getCost() const {
        return itemCost;
    }

    // this method retrieves the calculated invoice amount
    int getInvoiceAmount() const {

        // calculates the invoice total
        int invoiceTotal = quantity * itemCost;

        return invoiceTotal;
    }
private:
    std::string partNum;
    std::string description;
    int quantity;
    int itemCost;
};