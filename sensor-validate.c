#include <cstddef>
#include "sensor-validate.h"

int checkChargeFluctuations(double value, double nextValue, double maxDelta) 
{
  int retFluctuationStatus = NO_DEVIATION_DETECTED;
  if((nextValue - value) > maxDelta) 
  {
    retFluctuationStatus = READINGS_DEVIATION_DETECTED;
  }
  return retFluctuationStatus;
}

int validateChargeFluctuationStatus(double* inputParam, int numOfValues, int inputChargeType) 
{
  int retFluctuationStatus = NO_DEVIATION_DETECTED;
  double retMaxThreshold = 0.0;
  int lastButOneIndex = numOfValues - 1;
  if(NULL == inputParam)
  {
	  retFluctuationStatus = INVALID_PARAMETER_REQUESTED;
	  return retFluctuationStatus;
  }
  retMaxThreshold = identifyChargeTypeForValidation(inputChargeType);
  for(int i = 0; i < lastButOneIndex; i++) 
  {
    retFluctuationStatus = checkChargeFluctuations(inputParam[i], inputParam[i + 1], retMaxThreshold);
  }
  return retFluctuationStatus;
}

double identifyChargeTypeForValidation(int dataInputChargeType) 
{
  double retMaxThreshold;
  if(dataInputChargeType == SOC)
  {
	  retMaxThreshold = SOC_MAX_THRESHOLD;
  }
  else
  {
	  retMaxThreshold = CURRENT_MAX_THRESHOLD;
  }
  return retMaxThreshold;
}
