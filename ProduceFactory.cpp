#include "ProduceFactory.h"

ProPtr ProduceFactory::MakeProd(std::string type, int n, std::string date, int daysSincePick, std::string nameOfFarm, double price) {
    ProPtr item;
    if (type == "Tomato" || type == "tomatos") {
        item = std::make_shared<Tomato>(n, date, daysSincePick, nameOfFarm, price);
    }
    return item;
}
