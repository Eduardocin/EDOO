#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
    private:
        long barcode;
        std::string name;

    public:
        // Constructors
        Product();
        Product(long barcode = 0, std::string name = "");

        // Getters
        long getBarcode() const;
        std::string getName() const;

        // Setters
        void setBarcode(long& barcode);
        void setName(std::string name);

        // Methods
        void scanner();
        void printer() const;
};

class PrepackedFood : public Product {
    private:
        double unitPrice;

    public:
        // Constructors
        PrepackedFood(long barcode = 0, std::string name = "", double unitPrice = 0.0);

        // Getter and Setter
        double getUnitPrice() const;
        void setUnitPrice(double unitPrice);

        // Methods
        void printer() const;
};

class FreshFood : public Product {
    private:
        double weight;
        double pricePerKilo;

    public:
        // Constructors
        FreshFood(long barcode = 0, std::string name = "", double weight = 0.0, double pricePerKilo = 0.0);

        // Getters and Setters
        double getWeight() const;
        double getPricePerKilo() const;
        void setWeight(double weight);
        void setPricePerKilo(double pricePerKilo);

        // Methods
        double calculatePrice() const;
        void printer() const;
};

#endif
