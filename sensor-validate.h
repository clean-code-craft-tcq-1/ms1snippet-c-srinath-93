/* Macros */
#define NO_DEVIATION_DETECTED 1
#define READINGS_DEVIATION_DETECTED 0
#define SOC 0
#define CURRENT 1
#define SOC_MAX_THRESHOLD (double)0.05
#define CURRENT_MAX_THRESHOLD (double)0.1
#define INVALID_PARAMETER_REQUESTED 0

/* Function Declarations */
int checkChargeFluctuations(double value, double nextValue, double maxDelta);

int validateChargeFluctuationStatus(double* inputParam, int numOfValues, int inputChargeType);

double identifyChargeTypeForValidation(int dataInputChargeType);
