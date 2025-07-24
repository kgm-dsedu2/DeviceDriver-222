#include "device_driver.h"

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{
}

int DeviceDriver::read(long address)
{
  int ret = 0;

  ret = (int)(m_hardware->read(address));
  postConditionCheck(ret, address);

  return ret;
}

void DeviceDriver::postConditionCheck(int ret, long address)
{
  int prev = 0;
  for (int i = 0; i < 4; i++)
  {
    prev = ret;
    ret = (int)(m_hardware->read(address));
    if (ret != prev)
    {
      throw ReadFailException();
    }
  }
}

void DeviceDriver::write(long address, int data)
{
  int readData = (int)(m_hardware->read(address));
  if (readData != 0xFF)
  {
    throw WriteFailException();
  }

  m_hardware->write(address, (unsigned char)data);
}