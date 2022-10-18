#include "ProduceFactory.h"
#include "Produce/tomatoes.h"
#include "Produce/apple.h"
#include "Produce/lettuce.h"
#include "Produce/carrots.h"
#include "Produce/onions.h"
#include "Produce/squash.h"


ProduceFactory::ProduceFactory(std::vector<std::string> data){
    int size = data.size();
    std::string date = "10/17/2022";
    int weight = stoi(data[1]);
    double cost = stod(data[2]);
    for (int j = 0; j <valid_produce.size(); j++){
        if (data[0] == valid_produce[j]){
            std::cout << valid_produce[j] << std::endl;
            if (valid_produce[j] == "tomatoes"){
                //Produce *ptr = new tomatoes();
                tomatoes(weight, date, 1, data[3], cost);
            }
            else if (valid_produce[j] == "lettuce"){
                lettuce(weight, date, 1, data[3], cost);
            }
            else if (valid_produce[j] == "carrots"){
                carrots(weight, date, 1, data[3], cost);
            }
            else if (valid_produce[j] == "apple"){
                apple(weight, date, 1, data[3], cost);
            }
            else if (valid_produce[j] == "onions"){
                onions(weight, date, 1, data[3], cost);
            }
            else if (valid_produce[j] == "squash"){
                squash(weight, date, 1, data[3], cost);
            }
        }
    }
}

