#include "ProduceFactory.h"

ProduceFactory::ProduceFactory(std::vector<std::string> data){
    int size = data.size();
    for (int i = 0; i<size; i++){
        std::cout << data[i] << std::endl;
    };
}