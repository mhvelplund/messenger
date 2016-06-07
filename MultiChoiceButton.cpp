#include "MultiChoiceButton.h"
#include <cassert>
/*
	Knappen har 2 tilstande: ACTIVE og INACTIVE
	i INACTIVE viser den sin normale button text
	i ACTIVE viser den currentChoice

	når man klikker på en INACTIVE knap ...
	... bliver den den ACTIVE
	... currentChoice bliver sat til første mulighed
	... der bliver startet en timer

	når man klikker på en ACTIVE knap ...
	... currentChoice bliver sat til næste mulighed
	... timeren bliver reset og genstartet 

	når timeren ticker
	... bliver currentChoice sendt til parent
	... knappen bliver INACTIVE

	når man klikker på en knap bliver parent notificeret (så andre aktive knapper kan blive deaktiveret)
*/

MultiChoiceButton::MultiChoiceButton() {
	setClickCallback<MultiChoiceButton>(this, &MultiChoiceButton::buttonClicked);
}

void MultiChoiceButton::buttonClicked() {
	assert(m_keyContainer);
	assert(m_currentValue != -1);

	if (m_state == INACTIVE) {
		m_keyContainer->keyPressed(m_id);
		m_state = ACTIVE;
		// TODO: Start timer
		setCurrentButtonText();
	} else {
		// TODO: reset timer
		m_currentValue += 1;
		if (static_cast<uint8_t>(m_currentValue) == m_values.size()) {
			m_currentValue = 0;
		}
		setCurrentButtonText();
	}
}

void MultiChoiceButton::setCurrentButtonText() {
	mono::String buttonText = m_values.at(m_currentValue).show;
	setText(buttonText);
}

void MultiChoiceButton::setButtonValues(mono::String buttonText, std::vector<ButtonValue> values) {
	assert(values.size());
	assert(buttonText.Length());
	m_values = values;
	m_currentValue = 0;
	m_buttonText = buttonText;
	setText(buttonText);
}

void MultiChoiceButton::resetAndEmit() {
	assert (m_state == ACTIVE);

	// TODO: Cancel remaining timer
	char emit = m_values.at(m_currentValue).emit;
	m_keyContainer->emit(emit);
	m_currentValue = 0;
	setText(m_buttonText);
	m_state = INACTIVE;
}
