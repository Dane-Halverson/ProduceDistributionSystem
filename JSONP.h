#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include "ProduceInterface.h"

class JSONP {
private:

public:
    JSONP(std::string filename);
    ~JSONP();
};
