enum StepDirection{LEFT, RIGHT};

void LedInit(void);
void LedOn(unsigned char ucLedIndeks);
void LedStep(enum StepDirection eStepDirection);
void LedStepLeft(void);
void LedStepRight(void);
