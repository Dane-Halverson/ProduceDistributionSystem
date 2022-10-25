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
        NewProduce = std::make_shared<tomatoes>(n, date, daysSincePick, nameOfFarm, price);
    }
    else if (type == "lettuce"){
        NewProduce = std::make_shared<lettuce>(n, date, daysSincePick, nameOfFarm, price);
    }
    else if (type == "carrots"){
        NewProduce = std::make_shared<carrots>(n, date, daysSincePick, nameOfFarm, price);
    }
    else if (type == "apples"){
        NewProduce = std::make_shared<apple>(n, date, daysSincePick, nameOfFarm, price);
    }
    else if (type == "onions"){
        NewProduce = std::make_shared<onions>(n, date, daysSincePick, nameOfFarm, price);
    }
    else if (type == "squash"){
        NewProduce = std::make_shared<squash>(n, date, daysSincePick, nameOfFarm, price);
    }
    return NewProduce; 
};
