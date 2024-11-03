//test cases for distance function
#include "distance.h"
#include <gtest/gtest.h>

const double TOLERANCE = 1e-6;


TEST(DistanceConverterTest, MetersToFeet) {
  double result = DistanceConversion::convertDistance(1, DistanceUnit::Meters, DistanceUnit::Feet);
  ASSERT_DOUBLE_EQ(result, 3.28084);
}

TEST(DistanceConverterTest, MetersToYards) {
  double result = DistanceConversion::convertDistance(1, DistanceUnit::Meters, DistanceUnit::Yards);
  ASSERT_DOUBLE_EQ(result, 1.09361);
}

TEST(DistanceConverterTest, FeetToMeters) {
  double result = DistanceConversion::convertDistance(1, DistanceUnit::Feet, DistanceUnit::Meters);
  ASSERT_NEAR(result, 0.3048, TOLERANCE);
}

TEST(DistanceConverterTest, FeetToYards) {
  double result = DistanceConversion::convertDistance(1, DistanceUnit::Feet, DistanceUnit::Yards);
  ASSERT_DOUBLE_EQ(result, 0.3333333333333333);
}

TEST(DistanceConverterTest, YardsToMeters) {
    double result = DistanceConversion::convertDistance(1, DistanceUnit::Yards, DistanceUnit::Meters);
    ASSERT_NEAR(result, 0.9144, 9.9999999999999995e-08);
}

TEST(DistanceConverterTest, YardsToFeet) {
    double result = DistanceConversion::convertDistance(1, DistanceUnit::Yards, DistanceUnit::Feet);
    ASSERT_NEAR(result, 3.0, TOLERANCE);
}
