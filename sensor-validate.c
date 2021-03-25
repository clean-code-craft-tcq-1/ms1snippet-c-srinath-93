#include "sensor-validate.h"

int checkChargeFluctuations(double value, double nextValue, double maxDelta) 
{
  if(nextValue - value > maxDelta) 
  {
    return READINGS_DEVIATION_DETECTED;
  }
  return NO_DEVIATION_DETECTED;
}

int validateChargeFluctuationStatus(double* inputParam, int numOfValues, int inputChargeType) 
{
  int retFluctuationStatus = NO_DEVIATION_DETECTED;
  double retMaxThreshold = 0.0;
  int lastButOneIndex = numOfValues - 1;
  if(NULL == inputParam)
	{
		retFluctuationStatus = INVALID_PARAMETER_REQUESTED;
	}
  else
  {
  retMaxThreshold = identifyChargeTypeForValidation(inputChargeType);
  for(int i = 0; i < lastButOneIndex; i++) 
  {
    if(!checkChargeFluctuations(values[i], inputParam[i + 1], retMaxThreshold)) 
    {
      retFluctuationStatus = READINGS_DEVIATION_DETECTED;
    }
  }
  }
  return retFluctuationStatus;
}

double identifyChargeTypeForValidation(int dataInputChargeType) 
{
  double retMaxThreshold = 0.0;
  switch(dataInputChargeType)
  {
    case SOC: retMaxThreshold = SOC_MAX_THRESHOLD; break;
    case CURRENT: retMaxThreshold = CURRENT_MAX_THRESHOLD; break;
    default: /* Wrong input charge type requested */; break;
  }
  return retMaxThreshold;
}
