// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "frc/geometry/struct/Twist2dStruct.h"

namespace {
constexpr size_t kDxOff = 0;
constexpr size_t kDyOff = kDxOff + 8;
constexpr size_t kDthetaOff = kDyOff + 8;
}  // namespace

using StructType = wpi::Struct<frc::Twist2d>;

frc::Twist2d StructType::Unpack(std::span<const uint8_t, kSize> data) {
  return frc::Twist2d{
      units::meter_t{wpi::UnpackStruct<double, kDxOff>(data)},
      units::meter_t{wpi::UnpackStruct<double, kDyOff>(data)},
      units::radian_t{wpi::UnpackStruct<double, kDthetaOff>(data)},
  };
}

void StructType::Pack(std::span<uint8_t, kSize> data,
                      const frc::Twist2d& value) {
  wpi::PackStruct<kDxOff>(data, value.dx.value());
  wpi::PackStruct<kDyOff>(data, value.dy.value());
  wpi::PackStruct<kDthetaOff>(data, value.dtheta.value());
}
