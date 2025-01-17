// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <gtest/gtest.h>

#include "frc/kinematics/DifferentialDriveWheelSpeeds.h"

using namespace frc;

namespace {

using StructType = wpi::Struct<frc::DifferentialDriveWheelSpeeds>;
const DifferentialDriveWheelSpeeds kExpectedData{
    DifferentialDriveWheelSpeeds{1.74_mps, 35.04_mps}};
}  // namespace

TEST(DifferentialDriveWheelSpeedsStructTest, Roundtrip) {
  uint8_t buffer[StructType::kSize];
  std::memset(buffer, 0, StructType::kSize);
  StructType::Pack(buffer, kExpectedData);

  DifferentialDriveWheelSpeeds unpacked_data = StructType::Unpack(buffer);

  EXPECT_EQ(kExpectedData.left.value(), unpacked_data.left.value());
  EXPECT_EQ(kExpectedData.right.value(), unpacked_data.right.value());
}
