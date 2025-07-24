#pragma once
#include "flash_memory_device.h"
#include <string>
#include <stdexcept>

class ReadFailException : public std::exception
{
public:
  char const* what() const override
  {
    return "Read Fail Exception!";
  }
};

class DeviceDriver
{
public:
  DeviceDriver(FlashMemoryDevice* hardware);
  int read(long address);
  void postConditionCheck(int ret, long address);
  void write(long address, int data);

protected:
  FlashMemoryDevice* m_hardware;
};