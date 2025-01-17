// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <gtest/gtest.h>

#include "frc/kinematics/MecanumDriveWheelSpeeds.h"

using namespace frc;

namespace {

using StructType = wpi::Struct<frc::MecanumDriveWheelSpeeds>;
const MecanumDriveWheelSpeeds kExpectedData{
    MecanumDriveWheelSpeeds{2.29_mps, 17.4_mps, 4.4_mps, 0.229_mps}};
}  // namespace

TEST(MecanumDriveWheelSpeedsStructTest, Roundtrip) {
  uint8_t buffer[StructType::kSize];
  std::memset(buffer, 0, StructType::kSize);
  StructType::Pack(buffer, kExpectedData);

  MecanumDriveWheelSpeeds unpacked_data = StructType::Unpack(buffer);

  EXPECT_EQ(kExpectedData.frontLeft.value(), unpacked_data.frontLeft.value());
  EXPECT_EQ(kExpectedData.frontRight.value(), unpacked_data.frontRight.value());
  EXPECT_EQ(kExpectedData.rearLeft.value(), unpacked_data.rearLeft.value());
  EXPECT_EQ(kExpectedData.rearRight.value(), unpacked_data.rearRight.value());
}
