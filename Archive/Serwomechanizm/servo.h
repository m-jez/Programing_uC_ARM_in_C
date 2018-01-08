enum DecetorState {ACTIVE, INACTIVE};
enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo
{
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesirePosition;
};

static struct Servo eServo;

void ServoGoTo(unsigned int uiPosition);
void ServoInit(unsigned int uiServoFrequency);
void ServoCallib(void);