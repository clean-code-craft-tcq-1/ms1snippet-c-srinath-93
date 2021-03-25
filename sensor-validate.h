/* Macros */
#define NO_DEVIATION_DETECTED 1
#define READINGS_DEVIATION_DETECTED 0

/* Function Declarations */
int checkChargeFluctuations(double value, double nextValue, double maxDelta);

int validateSOCreadings(double* values, int numOfValues);

int validateCurrentreadings(double* values, int numOfValues);
