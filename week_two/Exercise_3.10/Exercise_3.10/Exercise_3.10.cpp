/*
* script: Exercise_3.10.cpp
* action: This program creates a class called invoice that can be utilized in
*         in a hardware store
* author: D.M
* date: 29JAN25
*/

#include <iostream>
#include <string>
#include "Invoice.h.cpp"

using namespace std;



int main()
{
    // create Invoice object

    Invoice testInvoice("12345", "Wrench", 5, 18);
    Invoice myInvoice("24689", "Nail", -10, 2);
    

    cout << "The part number is: " << testInvoice.getPartNumber() << endl;
    cout << "The part description is: " << testInvoice.getDescription() << endl;
    cout << "The quantity bought: " << testInvoice.getQuantity() << endl;
    cout << "The item price is $" << testInvoice.getCost() << endl;
    cout << "The total cost is $" << testInvoice.getInvoiceAmount() << endl;

    // revises test invoice to test getters and setters and logic

    testInvoice.setPartNumber("67890");
    testInvoice.setDescription("Mallet");
    testInvoice.setQuantity(3);
    testInvoice.setPrice(-22);

    cout << "\nThe revised invoice below\n";

    cout << "\nThe part number is: " << testInvoice.getPartNumber() << endl;
    cout << "The part description is: " << testInvoice.getDescription() << endl;
    cout << "The quantity bought: " << testInvoice.getQuantity() << endl;
    cout << "The item price is $" << testInvoice.getCost() << endl;

    cout << "The total cost is $" << testInvoice.getInvoiceAmount() << endl;

    // myInvoice display
    cout << "\nInvoice Two\n";

    cout << "\nThe part number is: " << myInvoice.getPartNumber() << endl;
    cout << "The part description is: " << myInvoice.getDescription() << endl;
    cout << "The quantity bought: " << myInvoice.getQuantity() << endl;
    cout << "The item price is $" << myInvoice.getCost() << endl;

    cout << "The total cost is $" << myInvoice.getInvoiceAmount() << endl;


    return 0;
}

