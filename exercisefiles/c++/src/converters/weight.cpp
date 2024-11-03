// WeightConversion.cpp
#include "weight.h"
#include <cstdio>
#include <iostream>
#include <iomanip> // Add this include
#include <unordered_map>


namespace /* private */ {
    std::string getWeightUnitSign(WeightUnit unit) {
        std::unordered_map<WeightUnit, std::string> unitSigns = {
            {WeightUnit::Kilograms, "kg"},
            {WeightUnit::Pounds, "lb"},
            {WeightUnit::Ounces, "oz"}
        };

        return unitSigns.at(unit);
    }
} // namespace private

namespace WeightConversion {

double kilosToPounds(double kilos) {
    return kilos * 2.20462;
}

double poundsToKilos(double pounds) {
    return pounds * 0.453592;
}

double kilosToOunces(double kilos) {
    return kilos * 35.274;
}

double ouncesToKilos(double ounces) {
    return ounces * 0.0283495;
}

double poundsToOunces(double pounds) {
    return pounds * 16;
}

double ouncesToPounds(double ounces) {
    return ounces / 16;
}

void startFlow() {
    int choice;
    double value, result;
    std::cout << "Select conversion type:\n";
    std::cout << "[1] Kilos to Pounds\n";
    std::cout << "[2] Pounds to Kilos\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter value in kilos: ";
        std::cin >> value;
        result = kilosToPounds(value);
        std::cout << value << " kilos is " << result << " pounds.\n";
    } else if (choice == 2) {
        std::cout << "Enter value in pounds: ";
        std::cin >> value;
        result = poundsToKilos(value);
        std::cout << value << " pounds is " << result << " kilos.\n";
    } else {
        std::cout << "Invalid choice.\n";
    }
}

double getSourceValue() {
    double value;
    std::cout << "Enter the value to be converted: ";
    std::cin >> value;
    return value;
}   

WeightUnit getWeightUnit(const std::string_view &sourceOrTarget) {
    int choice;
    std::cout << "Select " << sourceOrTarget << " weight unit:\n";
    std::cout << "[1] Kilograms\n";
    std::cout << "[2] Pounds\n";
    std::cout << "[3] Ounces\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            return WeightUnit::Kilograms;
        case 2:
            return WeightUnit::Pounds;
        case 3:
            return WeightUnit::Ounces;
        default:
            return WeightUnit::Kilograms;
    }

}   

//convert weight
double convertWeight(double value, WeightUnit from, WeightUnit to) {
    if (from == to) {
        return value;
    }

    if (from == WeightUnit::Kilograms) {
        if (to == WeightUnit::Pounds) {
            return kilosToPounds(value);
        } else if (to == WeightUnit::Ounces) {
            return kilosToOunces(value);
        }
    } else if (from == WeightUnit::Pounds) {
        if (to == WeightUnit::Kilograms) {
            return poundsToKilos(value);
        } else if (to == WeightUnit::Ounces) {
            return poundsToOunces(value);
        }
    } else if (from == WeightUnit::Ounces) {
        if (to == WeightUnit::Kilograms) {
            return ouncesToKilos(value);
        } else if (to == WeightUnit::Pounds) {
            return ouncesToPounds(value);
        }
    }

    return 0.0;
}

} // namespace WeightConversion