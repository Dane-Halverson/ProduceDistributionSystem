#include "JSONOut.h"
#include <iostream>

JSONOut::JSONOut(std::string date) {
    madefileProd.open("ProduceOutput" + date + ".json", std::ofstream::out);
    madefileSch.open("SchoolsOut" + date + ".json", std::ofstream::out);
}

JSONOut::~JSONOut() {
    madefileProd.close();
    madefileSch.close();
}

void JSONOut::OUT() {
    ProdJSON ["produce"] = prodVec;
    madefileProd << ProdJSON.dump(4);
    madefileSch << schoolsJSON.dump(4);
}

void JSONOut::vecPush() {
    prodVec.push_back(ProduceJ);
}

void JSONOut::setDate(std::string s) {
    ProdJSON["date"] = s;
}

void JSONOut::setType(std::string s) {
    ProduceJ["type"] = s;
}

void JSONOut::setWeight(int w) {
    ProduceJ["weight"] = w;
}

void JSONOut::setCost(float f) {
    ProduceJ["cost"] = f;
}

void JSONOut::setFarm(std::string s) {
    ProduceJ["farm"] = s;
}

void JSONOut::setDoP(std::string s) {
    ProduceJ["dateOfPick"] = s;
}

void JSONOut::setSchool(std::string type, std::string name, float budget, int i) {
    schoolsJSON[i]["type"] = type;
    schoolsJSON[i]["name"] = name;
    schoolsJSON[i]["budget"] = budget;
}


