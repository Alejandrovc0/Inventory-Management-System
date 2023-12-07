#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
    private:
        std::string name;
        int quantity;
        double price;

    public:
        Item();
        Item(const std::string &name, int quantity, double price);

        std::string getName() const;
        int getQuantity() const;
        double getPrice() const;

        void setName(const std::string &name);
        void setQuantity(int quantity);
        void setPrice(double price);

        void displayItem() const;
};

#endif