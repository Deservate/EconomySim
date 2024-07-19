#include <iostream>
#include <vector>

class Culture {
    public:
        std::string name;
};

class Pop {
    public:
        Culture * culture;
        std::vector<int> menPerAge;
        std::vector<int> womanPerAge;
};

class Province {
    public:
        std::string name;
        std::vector<Pop> pops;
};

class Country {
    public:
        std::string name;
        std::vector<Province> provinces;
};

std::vector<Culture> CreateCulturesList() {

    auto CreateCulture = [](std::string name) {
        Culture newCulture;
        newCulture.name = name;
        return newCulture;
    };

    std::vector<Culture> cultures;
    cultures.push_back(CreateCulture("Elmworthian"));
    cultures.push_back(CreateCulture("Tashkavian"));

    return cultures;
}

std::vector<Country> CreateCountriesList(std::vector<Culture> * ptrCultures) { 

    auto CreatePop = [](Culture * culture, std::vector<int> menPerAge, std::vector<int> womenPerAge) {
        Pop newPop;
        newPop.culture = culture;
        newPop.menPerAge = menPerAge;
        newPop.womanPerAge = womenPerAge;
        return newPop;
    };

    auto CreateProvince = [](std::string name, std::vector<Pop> pops) {
        Province newProvince;
        newProvince.name = name;
        newProvince.pops = pops;
        return newProvince;
    };

    auto CreateCountry = [](std::string name, std::vector<Province> provinces) {
        Country newCountry;
        newCountry.name = name;
        newCountry.provinces = provinces;
        return newCountry;
    };

    std::vector<Country> countries;

    // ==== Elmworth ====
    std::vector<int> popVec(100, 1e4);
    std::vector<Province> provinces = {
        CreateProvince("Westfeld", {CreatePop(&ptrCultures->at(0), popVec, popVec), CreatePop(&ptrCultures->at(1), popVec, popVec)})
        ,CreateProvince("Riverton", {CreatePop(&ptrCultures->at(0), popVec, popVec), CreatePop(&ptrCultures->at(1), popVec, popVec)})
    };

    countries.push_back(CreateCountry("Elmworth", provinces));

    return countries;
}

void DrawInterface(std::string bodyText){
    
    std::cout << std::string(80,'-') << std::endl;
    std::cout << bodyText << std::endl;
    std::cout << std::string(80,'-') << std::endl;
}

int main() {
    
    // create the game world
    std::vector<Culture> cultures = CreateCulturesList();
    std::vector<Country> countries = CreateCountriesList(&cultures);

    DrawInterface("This is the body text of the scene");

    return 0;
}