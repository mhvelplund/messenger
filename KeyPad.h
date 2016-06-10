#pragma once

// Include the Mono Framework
#include <mono.h>
#include "IKeyContainer.h"
#include "MultiChoiceButton.h"

class KeyPad : public virtual IKeyContainer, public mono::ui::View {
	const static uint8_t BUTTON_COUNT = 12;
	MultiChoiceButton m_buttons[BUTTON_COUNT];
	mono::display::Color m_borderColor;
	mono::display::Color m_borderColorPressed;

protected:
	virtual void repaint();

public:
    virtual void keyPressed(int8_t id);
    virtual void emit(char emit);
    virtual void show();
    virtual void hide();

	KeyPad(
		mono::geo::Rect rect = mono::geo::Rect(0, 0, mono::ui::View::DisplayWidth(), mono::ui::View::DisplayHeight()), 
		mono::display::Color borderColor = mono::ui::View::StandardBorderColor, 
		mono::display::Color borderColorPressed = mono::ui::View::StandardHighlightColor
	);

	virtual ~KeyPad() {}

};