// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <gtest/gtest.h>

#include "frc/controller/DifferentialDriveWheelVoltages.h"

using namespace frc;

namespace {

using StructType = wpi::Struct<frc::DifferentialDriveWheelVoltages>;
const DifferentialDriveWheelVoltages kExpectedData{
    DifferentialDriveWheelVoltages{0.174_V, 0.191_V}};
}  // namespace

TEST(DifferentialDriveWheelVoltagesStructTest, Roundtrip) {
  uint8_t buffer[StructType::kSize];
  std::memset(buffer, 0, StructType::kSize);
  StructType::Pack(buffer, kExpectedData);

  DifferentialDriveWheelVoltages unpacked_data = StructType::Unpack(buffer);

  EXPECT_EQ(kExpectedData.left.value(), unpacked_data.left.value());
  EXPECT_EQ(kExpectedData.right.value(), unpacked_data.right.value());
}
