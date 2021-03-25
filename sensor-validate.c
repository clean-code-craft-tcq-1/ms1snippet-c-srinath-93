#include "sensor-validate.h"

int checkChargeFluctuations(double value, double nextValue, double maxDelta) 
{
  if(nextValue - value > maxDelta) 
  {
    return READINGS_DEVIATION_DETECTED;
  }
  return NO_DEVIATION_DETECTED;
}

int validateSOCreadings(double* values, int numOfValues) 
{
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) 
  {
    if(!checkChargeFluctuations(values[i], values[i + 1], 0.05)) 
    {
      return READINGS_DEVIATION_DETECTED;
    }
  }
  return NO_DEVIATION_DETECTED;
}

int validateCurrentreadings(double* values, int numOfValues) 
{
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) 
  {
    if(!checkChargeFluctuations(values[i], values[i + 1], 0.1)) 
    {
      return READINGS_DEVIATION_DETECTED;
    }
  }
  return NO_DEVIATION_DETECTED;
}
