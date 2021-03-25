#include "sensor-validate.h"

int checkChargeFluctuations(double value, double nextValue, double maxDelta) 
{
  if(nextValue - value > maxDelta) 
  {
    return READINGS_DEVIATION_DETECTED;
  }
  return NO_DEVIATION_DETECTED;
}

int validateChargeFluctuationStatus(double* values, int numOfValues, int inputChargeType) 
{
  double retMaxThreshold;
  int lastButOneIndex = numOfValues - 1;
  retMaxThreshold = identifyChargeTypeForValidation(inputChargeType);
  for(int i = 0; i < lastButOneIndex; i++) 
  {
    if(!checkChargeFluctuations(values[i], values[i + 1], retMaxThreshold)) 
    {
      return READINGS_DEVIATION_DETECTED;
    }
  }
  return NO_DEVIATION_DETECTED;
}

double identifyChargeTypeForValidation(int dataInputChargeType) 
{
  double retMaxThreshold = 0.0;
  switch(inputChargeType)
  {
    case SOC: retMaxThreshold = SOC_MAX_THRESHOLD; break;
    case CURRENT: retMaxThreshold = CURRENT_MAX_THRESHOLD; break;
    default: printf("Wrong input charge type requested\n"); break;
  }
  return retMaxThreshold;
}
