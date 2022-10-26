#include "JSONOut.h"

JSONOut::JSONOut() {

}

void JSONOut::OUT() {
    ProdJSON ["produce"] = prodVec;
    madefile << ProdJSON.dump(4);
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

