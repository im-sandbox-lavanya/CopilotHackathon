// WeightConversion.h
#ifndef WEIGHT_H
#define WEIGHT_H

#include "types.h"
#include <string>

enum class WeightUnit
{
  Kilograms,
  Pounds,
  Ounces
};

namespace WeightConversion
{
  void startFlow();
  double getSourceValue();
  WeightUnit getWeightUnit(const std::string_view &sourceOrTarget);
  double convertWeight(double value, WeightUnit from, WeightUnit to);
}

#endif