#include "ProduceFactory.h"

ProduceFactory::ProduceFactory(std::vector<std::string> data){
    int size = data.size();
    for (int i = 0; i<size; i++){
        for (int j = 0; j <valid_produce.size(); j++){
            if (data[i] == valid_produce[j]){
                std::cout << valid_produce[j] << std::endl;                 

            }
        }
            
    }
};
