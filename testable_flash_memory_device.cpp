#include "flash_memory_device.h"

class TestableFlashMemoryDevice : public FlashMemoryDevice
{
public:
  TestableFlashMemoryDevice()
  {
  }

  unsigned char read(long address)
  {
  }
  void write(long address, unsigned char data) = 0;
private:
  char memory[0xFF] = { 0xFF, };
};