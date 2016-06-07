#pragma once

// Include the Mono Framework
#include <mono.h>
#include "IKeyContainer.h"
#include "MultiChoiceButton.h"

class KeyPad : public virtual IKeyContainer, public mono::ui::View {
	MultiChoiceButton m_buttons[12];
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