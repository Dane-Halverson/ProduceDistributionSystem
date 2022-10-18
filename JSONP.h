#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <nlohmann/json.hpp>


class JSONP {
private:
    std::string filename;
public:
    JSONP(const std::string fn) : filename(fn) {}
    ~JSONP() = default;
    void parce();
};
