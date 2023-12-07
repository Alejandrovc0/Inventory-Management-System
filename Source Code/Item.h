#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
    private:
        int serialNumber;
        std::string name;
        int quantity;
        double price;

    public:
        Item();
        Item(int serialNumber, const std::string &name, int quantity, double price);

        int getSerialNumber() const;
        std::string getName() const;
        int getQuantity() const;
        double getPrice() const;

        void setSerialNumber(int serialNumber);
        void setName(const std::string &name);
        void setQuantity(int quantity);
        void setPrice(double price);

        void displayItem() const;
};

#endif