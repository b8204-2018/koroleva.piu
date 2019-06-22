//
// Created by polina on 27.04.19.
//

#ifndef SHOP_CART_H
#define SHOP_CART_H

#include <string>
#include <vector>
#include "Money.h"

using namespace std;


class Product;

class SodaChooser;

class TeaChooser;

class ChipsChooser;

class Product {
public:
    virtual string getName() = 0;

    virtual unsigned int getPrice() = 0;

    virtual string getType() = 0;

};

//продукты

class Soda : public Product {

protected:
    enum brand {
        Cola, Fanta, Pepsi
    };
    string brandString[3]{"Cola", "Fanta", "Pepsi"};
    enum flavour {
        orange, tomato, cucumber
    };
    string flavourString[3]{"orange", "tomato", "cucumber"};

private:
    brand sodaBrand;
    flavour sodaFlavour;
    bool isGas;

public:

    Soda(brand sodaBrand, flavour sodaFlavour, bool isGas);

    string getName() override;

    unsigned int getPrice() override;

    string getType() override;

    friend SodaChooser;

};

class Tea : public Product {

protected:
    enum color {
        black, green, red, fruit
    };

    string colorString[4]{"black", "green", "red", "fruit"};

private:
    color teaColor;
    bool hot;
    bool withIce;
    unsigned int sugarCount;

public:

    Tea(bool hot, color teaColor, bool withIce, unsigned int sugarCount);

    string getName() override;

    unsigned int getPrice() override;

    string getType() override;

    friend TeaChooser;

};

class Chips : public Product {
protected:
    enum flavour {
        chili, paprika, salt
    };
    string flavourString[4]{"chili", "paprika", "salt"};
    enum form {
        round, sqare
    };
    string formString[2]{"round", "sqare"};

private:
    flavour chipFlavour;
    form chipForm;
    unsigned int chipsCount;

public:
    Chips(flavour chipFlavour, form chipForm, unsigned int chipCount);

    string getName() override;

    unsigned int getPrice() override;

    string getType() override;

    friend ChipsChooser;
};

typedef pair<Product *, unsigned int> goods;


class ShoppingCart {
    vector<goods> products;
public:

    vector<goods>* getProductList();

    void addProduct(goods *g);

    unsigned int getPriceInCurrency(unsigned int currency);

    friend ostream &operator<<(ostream &out, const ShoppingCart &s);

    friend class Customer;
};

class AbstractChooser {

};

class TeaChooser : AbstractChooser {
public:
    TeaChooser() = default;

    Tea *chooseHotBlackTeaWithSugar();

    Tea *chooseColdGreenTeaWithoutSugar();

    Tea *chooseColdBlactTeaWithSugarAndIce();
};

class ChipsChooser : AbstractChooser {
public:

    ChipsChooser() = default;

    Chips *chooseMuchHotRoundChips();

    Chips *chooseSomeSaltSqareChips();
};

class SodaChooser : AbstractChooser {
public:

    SodaChooser() = default;

    Soda *chooseTomatoCola();

    Soda *chooseStandartFanta();

    Soda *chooseCucumberPepsiWitoutGas();
};


class Shop {

    unsigned int usableMoneyCurrency;

    vector<Product*> productAssortment;

public:

    Shop(unsigned int money);

    void addProductInAssortment(Product *p);

    goods *getProductFromAssort(unsigned int index);

    vector <Product*> *getAssortment();


};

#endif //SHOP_CART_H
