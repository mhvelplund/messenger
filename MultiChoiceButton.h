#pragma once

// Include the Mono Framework
#include <vector>
#include <cassert>
#include <mono.h>
#include "IKeyContainer.h"

struct ButtonValue {
	mono::String show;
	char emit;
};

class MultiChoiceButton : public mono::ui::ButtonView {
	enum ButtonState { INACTIVE, ACTIVE };

	IKeyContainer *m_keyContainer;
	std::vector<ButtonValue> m_values; // Uninitialized!!!
	int8_t m_currentValue;
	ButtonState m_state;
	int8_t m_id;
	mono::String m_buttonText; // Uninitialized!!!

protected:
	void buttonClicked();
	void setCurrentButtonText();

public:
	MultiChoiceButton();

	void setColors(mono::display::Color bc, mono::display::Color bcp) {
		borderColor = bc;
		borderColorPressed = bcp;
	}

	int8_t getId() { 
		return m_id; 
	}

	void setId(int8_t id) {
		assert(id >= 0);
		m_id = id;
	}

	void setKeyContainer(IKeyContainer &keyContainer) {
		m_keyContainer = &keyContainer;
	}

	void setButtonValues(mono::String buttonText, std::vector<ButtonValue> values);

	void resetAndEmit();
};