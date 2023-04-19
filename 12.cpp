#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Pizza {
    char name[15];
    int price;
    char *ingredients;
    int discount;

public:
    Pizza(const char *name = "", int price = 0, const char *ingredients = "", int discount = 0) : price(price),
                                                                                            discount(discount) {
        strcpy(this->name, name);
        this->ingredients = new char[strlen(ingredients) + 1];
        strcpy(this->ingredients, ingredients);
    }

    Pizza(const Pizza &other) : price(other.price), discount(other.discount) {
        strcpy(this->name, other.name);
        this->ingredients = new char[strlen(other.ingredients) + 1];
        strcpy(this->ingredients, other.ingredients);
    }

    Pizza &operator=(Pizza &other) {
        if (this != &other) {
            this->price = other.price;
            this->discount = other.discount;
            delete[] ingredients;
            strncpy(this->name, other.name, 15);
            this->ingredients = new char[strlen(other.ingredients) + 1];
            strcpy(this->ingredients, other.ingredients);

        }
        return *this;
    }

    ~Pizza() {
        delete[] ingredients;
    }

    const char *getName() const {
        return name;
    }

    void setName(const char *name) {
        strncpy(this->name, name, 15);
    };

    int getPrice() {
        return price;
    }

    void setPrice(int price) {
        Pizza::price = price;
    }

    const char *getIngredients() const {
        return ingredients;
    }

    void setIngredients(const char *ingredients) {
        delete[] this->ingredients; // free the previous memory allocation
        this->ingredients = new char[strlen(ingredients) + 1];
        strcpy(this->ingredients, ingredients);
    }

    int getDiscount() {
        return discount;
    }

    void setDiscount(int discount) {
        Pizza::discount = discount;
    }

    void print() {
        cout << name << " - " << ingredients << ", " << price;
    }

    bool samePizza(Pizza p) {
        return strcmp(ingredients, p.ingredients) == 0;
    }


};

class PizzaShop {
    char nameOfStore[15];
    Pizza *pizzas;
    int numberOfPizzas;

public:
    PizzaShop(const char *nameOfStore = "") {
        strncpy(this->nameOfStore, nameOfStore, 14);
        this->nameOfStore[14] = '\0';
        this->numberOfPizzas = 0;
        pizzas = NULL;
    }

    PizzaShop(const char *nameOfStore, Pizza *pizzas, int numberOfPizzas) : numberOfPizzas(numberOfPizzas) {
        strncpy(this->nameOfStore, nameOfStore, 14);
        this->nameOfStore[14] = 0;
        this->pizzas = new Pizza[numberOfPizzas];
        for (int i = 0; i < numberOfPizzas; ++i) {
            this->pizzas[i] = pizzas[i];
        }
    }

    PizzaShop(const PizzaShop &other) {
        strcpy(this->nameOfStore, other.nameOfStore);
        this->pizzas = new Pizza[other.numberOfPizzas];
        for (int i = 0; i < other.numberOfPizzas; ++i) {
            this->pizzas[i] = other.pizzas[i];
        }
    }

    PizzaShop &operator=(const PizzaShop &other) {
        if (this != &other) {
            strcpy(this->nameOfStore, other.nameOfStore);
            delete[] pizzas;
            this->pizzas = new Pizza[numberOfPizzas];
            for (int i = 0; i < numberOfPizzas; ++i) {
                this->pizzas[i] = other.pizzas[i];
            }
        }
        return *this;
    }

    ~PizzaShop() {
        delete[] pizzas;
    }

    const char *getNameOfStore() {
        return nameOfStore;
    }

    void setNameOfStore(const char *nameOfStore) {
        strncpy(this->nameOfStore, nameOfStore, 14);
        this->nameOfStore[14] = 0;
    }

    Pizza getPizzas(int n) const {
        return pizzas[n];
    }

    void setPizzas(Pizza *pizzas) {
        PizzaShop::pizzas = pizzas;
    }

    int getNumberOfPizzas() const {
        return numberOfPizzas;
    }

    void setNumberOfPizzas(int numberOfPizzas) {
        PizzaShop::numberOfPizzas = numberOfPizzas;
    }

    PizzaShop &operator+=(Pizza &p) {
        bool sameAvailable = false;
        for (int i = 0; i < numberOfPizzas; ++i) {
            if (pizzas[i].samePizza(p)) {
                sameAvailable = true;
            }
        }
        if (!sameAvailable) {
            Pizza *temp = new Pizza[numberOfPizzas + 1];
            for (int i = 0; i < numberOfPizzas; ++i) {
                temp[i] = pizzas[i];
            }
            temp[numberOfPizzas++] = p;
            delete[] pizzas;
            pizzas = temp;
        }
        return *this;
    }

    void PizzasOnPromotion() {
        for (int i = 0; i < numberOfPizzas; ++i) {
            if (pizzas[i].getDiscount() > 0 && pizzas[i].getDiscount() <= 100) {
                pizzas[i].print();
                int discount = 0;
                discount = pizzas[i].getPrice() - (pizzas[i].getPrice() / 100.0) * pizzas[i].getDiscount();
                cout << ", " << discount << endl;
            }
        }
    }
};

int main() {
    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    PizzaShop p1(ime);
    for (int i = 0; i < n; i++) {
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pizza p(imp, cena, sostojki, popust);
        p1 += p;
    }

    PizzaShop p2 = p1;
    cin >> ime;
    p2.setNameOfStore(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pizza p(imp, cena, sostojki, popust);
    p2 += p;

    cout << p1.getNameOfStore() << endl;
    cout << "Pici na promocija:" << endl;
    p1.PizzasOnPromotion();

    cout << p2.getNameOfStore() << endl;
    cout << "Pici na promocija:" << endl;
    p2.PizzasOnPromotion();

    return 0;
}