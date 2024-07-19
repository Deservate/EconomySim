#include <iostream>
#include <vector>

class Culture {
    public:
        std::string name;
};

class Pop {
    public:
        Culture * culture;
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

    auto CreatePop = [](Culture * culture) {
        Pop newPop;
        newPop.culture = culture;
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
    std::vector<Province> provinces = {
        CreateProvince("Westfeld", {CreatePop(&ptrCultures->at(0)), CreatePop(&ptrCultures->at(1))})
        ,CreateProvince("Riverton", {CreatePop(&ptrCultures->at(0)), CreatePop(&ptrCultures->at(1))})
        ,CreateProvince("Hawkshire", {CreatePop(&ptrCultures->at(0)), CreatePop(&ptrCultures->at(1))})
    };

    countries.push_back(CreateCountry("Elmworth", provinces));

    return countries;
}

int main() {
    
    // create the game world
    std::vector<Culture> cultures = CreateCulturesList();

    std::vector<Country> countries = CreateCountriesList(&cultures);

    std::cout << countries[0].provinces[0].pops[0].culture->name << std::endl;
    std::cout << cultures[0].name << std::endl;

    cultures[0].name = "NEWNAME";

    std::cout << countries[0].provinces[0].pops[0].culture->name << std::endl;
    std::cout << cultures[0].name << std::endl;

    return 0;
}