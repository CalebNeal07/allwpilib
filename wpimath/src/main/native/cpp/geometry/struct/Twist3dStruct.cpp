// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "frc/geometry/struct/Twist3dStruct.h"

namespace {
constexpr size_t kDxOff = 0;
constexpr size_t kDyOff = kDxOff + 8;
constexpr size_t kDzOff = kDyOff + 8;
constexpr size_t kRxOff = kDzOff + 8;
constexpr size_t kRyOff = kRxOff + 8;
constexpr size_t kRzOff = kRyOff + 8;
}  // namespace

using StructType = wpi::Struct<frc::Twist3d>;

frc::Twist3d StructType::Unpack(std::span<const uint8_t, kSize> data) {
  return frc::Twist3d{
      units::meter_t{wpi::UnpackStruct<double, kDxOff>(data)},
      units::meter_t{wpi::UnpackStruct<double, kDyOff>(data)},
      units::meter_t{wpi::UnpackStruct<double, kDzOff>(data)},
      units::radian_t{wpi::UnpackStruct<double, kRxOff>(data)},
      units::radian_t{wpi::UnpackStruct<double, kRyOff>(data)},
      units::radian_t{wpi::UnpackStruct<double, kRzOff>(data)},
  };
}

void StructType::Pack(std::span<uint8_t, kSize> data,
                      const frc::Twist3d& value) {
  wpi::PackStruct<kDxOff>(data, value.dx.value());
  wpi::PackStruct<kDyOff>(data, value.dy.value());
  wpi::PackStruct<kDzOff>(data, value.dz.value());
  wpi::PackStruct<kRxOff>(data, value.rx.value());
  wpi::PackStruct<kRyOff>(data, value.ry.value());
  wpi::PackStruct<kRzOff>(data, value.rz.value());
}
