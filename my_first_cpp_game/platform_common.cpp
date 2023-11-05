struct Button_State {
	bool is_down;
	bool changed;
};

enum {
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_9,
	BUTTON_6,
	BUTTON_Q,
	BUTTON_A,
	BUTTON_SPACE,
	BUTTON_COUNT, //should be the last item
};

struct Input {
	Button_State buttons[BUTTON_COUNT];
};

