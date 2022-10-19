#include "ProduceFactory.h"
#include "Produce/tomatoes.h"
#include "Produce/apple.h"
#include "Produce/lettuce.h"
#include "Produce/carrots.h"
#include "Produce/onions.h"
#include "Produce/squash.h"


std::shared_ptr<Produce> ProduceFactory::makeProduce(std::string type, int n, std::string date, int daysSincePick, std::string nameOfFarm, double price){
    std::shared_ptr<Produce> NewProduce;
    if (type == "tomatoes"){
        NewProduce = std::make_shared<Produce>(tomatoes(n, date, daysSincePick, nameOfFarm, price));
    }
    else if (type == "lettuce"){
        NewProduce = std::make_shared<Produce>(lettuce(n, date, daysSincePick, nameOfFarm, price));
    }
    else if (type == "carrots"){
        NewProduce = std::make_shared<Produce>(carrots(n, date, daysSincePick, nameOfFarm, price));
    }
    else if (type == "apple"){
        NewProduce = std::make_shared<Produce>(apple(n, date, daysSincePick, nameOfFarm, price));
    }
    else if (type == "onions"){
        NewProduce = std::make_shared<Produce>(onions(n, date, daysSincePick, nameOfFarm, price));
    }
    else if (type == "squash"){
        NewProduce = std::make_shared<Produce>(squash(n, date, daysSincePick, nameOfFarm, price));
    }
    return NewProduce; 
};
