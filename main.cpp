#include <iostream>
#include <vector>

class Province {
    public:
        std::string name;
};

class Country {
    public:
        std::string name;
        std::vector<Province> provinces;
};

Country CreateCountry(std::string name, std::vector<std::string> provinceNames) {
    Country newCountry;
    newCountry.name = name;

    std::vector<Province> newProvinceList;
    
    for (int i = 0; i < provinceNames.size(); i++) {
        Province newProvince;
        newProvince.name = provinceNames[i];
        newProvinceList.push_back(newProvince);
    }
    newCountry.provinces = newProvinceList;

    return newCountry;
}

int main() {

    std::vector<std::string> provinceNames = {"Aberworth", "Bennedit", "Comberwhile"};

    Country country1 = CreateCountry("Countristan", provinceNames);
    std::cout << "Hello World!";
    std::cout << "Hello World!" << country1.provinces[0].name << std::endl;

    return 0;
}