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

void setType(std::string s) {
    ProduceJ["type"] = s;
}

void setWeight(int w) {
    ProduceJ["weight"] = w;
}

void setCost(float f) {
    ProduceJ["cost"] = f;
}

void setFarm(std::string s) {
    ProduceJ["farm"] = s;
}

void setDoP(std::string s) {
    ProduceJ["dateOfPick"] = s;
}

