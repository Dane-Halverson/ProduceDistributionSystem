#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    cout << "enter the name of the produce: \n";
    string type;
    cin >> type;
    cout << "enter the life of " << type << ":\n";
    string life;
    cin >> life;
    string date;
    cout << "enter the date:\n";
    cin >> date;
    ofstream ProduceFile(type + ".h");

    string fileContent = "#pragma once\n\n";
    fileContent += "#include \"../ProduceInterface.h\"\n";
    fileContent += "#include \"../Date.h\"\n\n";
    fileContent += "/**\n* @author Dane Halverson\n* @file " + type + ".h\n* @date " + date + "\n";
    fileContent += "*/\n\n";
    fileContent += "class " + type + " : public Produce\n";
    fileContent += "{\n";
    fileContent += "private:\n";
    fileContent += "    int life = ";
    fileContent += life;
    fileContent += ";\n\n";
    fileContent += "public:\n";
    fileContent += "   " + type + "(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price);\n";
    fileContent += "};\n\n";
    fileContent += type + "::" + type + "(int n, std::string date, int daysSincePick, std::string nameOfFarm, double price)\n";
    fileContent += ": Produce(n, date, daysSincePick, nameOfFarm, price)\n";
    fileContent += "{}\n\n\n";

    ProduceFile << fileContent;

    ofstream includes("includes.txt", std::ios_base::app);
    includes << "#include \"Produce/" << type << ".h\"\n";

    string lower = type;
    for (int i = 0; i < type.size(); ++i) {
        lower[i] = tolower(type[i]);
    }

    ofstream factory("ifelse.txt", std::ios_base::app);
    factory << "else if ( type == " << type << " || type == " << lower << " ) {\n"
            << "    item = std::make_shared<" << type << ">(n, date, daysSincePick, nameOfFarm);\n"
            << "}\n";
}
