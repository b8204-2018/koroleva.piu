#include <iostream>
#include <string>

#include "Shop.h"
#include "Customers.h"

using namespace std;

int main() {

    /*ShoppingCart products;

    products.addProduct(TeaChooser().chooseHotBlackTeaWithSugar());
    products.addProduct(ChipsChooser().chooseSomeSaltSqareChips());
    products.addProduct(SodaChooser().chooseCucumberPepsiWitoutGas());

    cout << products;

    cout << "Products' price is " << products.getPrice();

    MoneyPress press;

    Converter converter;
    converter.addRate(rub, eur, 0.015);
    converter.addRate(jpy, rub, 3.2);
    converter.addRate(usd, rub, 60);

    Wallet myWallet;
    myWallet.addMoney(*press.printMoney(rub, 100));
    myWallet.addMoney(*press.printMoney(usd, 20));

    Money *testMoney = press.printMoney(jpy, 100);
    Money *converted = converter.convert(*testMoney, rub);

    myWallet.addMoney(*converted);

    cout << "Ура я могу печатать деньги" << endl;*/

    TeaChooser teaChooser;
    SodaChooser sodaChooser;
    ChipsChooser chipsChooser;

    MoneyPress press;

    Shop *FirstShop = new Shop (rub);
    FirstShop->addProductInAssortment(sodaChooser.chooseStandartFanta());
    FirstShop->addProductInAssortment(teaChooser.chooseColdGreenTeaWithoutSugar());
    FirstShop->addProductInAssortment(chipsChooser.chooseSomeSaltSqareChips());

    Shop *SecondShop = new Shop (jpy);
    SecondShop->addProductInAssortment(sodaChooser.chooseCucumberPepsiWitoutGas());
    SecondShop->addProductInAssortment(sodaChooser.chooseCucumberPepsiWitoutGas());

    Customer randomCustomer;
    randomCustomer.getWallet()->addMoney(*press.printMoney(rub, 500));
    //randomCustomer.getCart()->addProduct(FirstShop->getProductFromAssort(2));
    randomCustomer.getCart()->addProduct(FirstShop->getProductFromAssort(1));
    cout << randomCustomer.canBuyAll() << "  " << randomCustomer.isSatisfied() <<endl;

    Child child;
    child.getCart()->addProduct(FirstShop->getProductFromAssort(0));
    child.getCart()->addProduct(FirstShop->getProductFromAssort(2));
    cout << child.isSatisfied();

}
