#include "KeyPad.h"

KeyPad::KeyPad(
		mono::geo::Rect rect,
		mono::display::Color borderColor, 
		mono::display::Color borderColorPressed) : 
		mono::ui::View(rect),
		m_borderColor { borderColor }, 
		m_borderColorPressed { borderColorPressed } 
{
	uint8_t id = 0;
	for (MultiChoiceButton &mcb : m_buttons) {
		mcb.setKeyContainer(*this);
		mcb.setId(id++);
		mcb.setColors(borderColor, borderColorPressed);
	}

	m_buttons[0].setRect(mono::geo::Rect(0,0,50,50));
	m_buttons[1].setRect(mono::geo::Rect(55,0,50,50));
	m_buttons[2].setRect(mono::geo::Rect(110,0,50,50));
	m_buttons[3].setRect(mono::geo::Rect(0,55,50,50));
	m_buttons[4].setRect(mono::geo::Rect(55,55,50,50));
	m_buttons[5].setRect(mono::geo::Rect(110,55,50,50));
	m_buttons[6].setRect(mono::geo::Rect(0,110,50,50));
	m_buttons[7].setRect(mono::geo::Rect(55,110,50,50));
	m_buttons[8].setRect(mono::geo::Rect(110,110,50,50));
	m_buttons[9].setRect(mono::geo::Rect(0,165,50,50));
	m_buttons[10].setRect(mono::geo::Rect(55,165,50,50));
	m_buttons[11].setRect(mono::geo::Rect(110,165,50,50));

	m_buttons[0].setButtonValues("Send", std::vector<ButtonValue> {
		ButtonValue {"-->", '>'},
		ButtonValue {"1", '1'}
	});

	m_buttons[1].setButtonValues("ABC", std::vector<ButtonValue> {
		ButtonValue {"A", 'A'},
		ButtonValue {"B", 'B'},
		ButtonValue {"C", 'C'},
		ButtonValue {"2", '2'}
	});

	m_buttons[2].setButtonValues("DEF", std::vector<ButtonValue> {
		ButtonValue {"D", 'D'},
		ButtonValue {"E", 'E'},
		ButtonValue {"F", 'F'},
		ButtonValue {"3", '3'}
	});

	m_buttons[3].setButtonValues("GHI", std::vector<ButtonValue> {
		ButtonValue {"G", 'G'},
		ButtonValue {"H", 'H'},
		ButtonValue {"I", 'I'},
		ButtonValue {"4", '4'}
	});

	m_buttons[4].setButtonValues("JKL", std::vector<ButtonValue> {
		ButtonValue {"J", 'J'},
		ButtonValue {"K", 'K'},
		ButtonValue {"L", 'L'},
		ButtonValue {"5", '5'}
	});

	m_buttons[5].setButtonValues("MNO", std::vector<ButtonValue> {
		ButtonValue {"M", 'M'},
		ButtonValue {"N", 'N'},
		ButtonValue {"O", 'O'},
		ButtonValue {"6", '6'}
	});

	m_buttons[6].setButtonValues("PQRS", std::vector<ButtonValue> {
		ButtonValue {"P", 'P'},
		ButtonValue {"Q", 'Q'},
		ButtonValue {"R", 'R'},
		ButtonValue {"S", 'S'},
		ButtonValue {"7", '7'}
	});

	m_buttons[7].setButtonValues("TUV", std::vector<ButtonValue> {
		ButtonValue {"T", 'T'},
		ButtonValue {"U", 'U'},
		ButtonValue {"V", 'V'},
		ButtonValue {"8", '8'}
	});

	m_buttons[8].setButtonValues("WXYZ", std::vector<ButtonValue> {
		ButtonValue {"W", 'W'},
		ButtonValue {"X", 'X'},
		ButtonValue {"Y", 'Y'},
		ButtonValue {"Z", 'Z'},
		ButtonValue {"9", '9'}
	});

	m_buttons[9].setButtonValues("*", std::vector<ButtonValue> {
		ButtonValue {"*", '*'},
		ButtonValue {"+", '+'}
	});

	m_buttons[10].setButtonValues("_", std::vector<ButtonValue> {
		ButtonValue {"_", ' '},
		ButtonValue {".", '.'},
		ButtonValue {"0", '0'}
	});

	m_buttons[11].setButtonValues("#", std::vector<ButtonValue> {
		ButtonValue {"#", '#'},
		ButtonValue {"^", '^'}
	});
}

void KeyPad::keyPressed(int8_t id) {
	assert(id >= 0);

	for (MultiChoiceButton &mcb : m_buttons) {
		if (mcb.getId() != id) {
			mcb.resetAndEmit();
		}
	}
}

void KeyPad::emit(char emit) {
	// TODO: Tell listeners
}

void KeyPad::repaint() {
	for (MultiChoiceButton &mcb : m_buttons) {
		mcb.repaint();
	}
}

void KeyPad::show() {
	for (MultiChoiceButton &mcb : m_buttons) {
		mcb.show();
	}
}

void KeyPad::hide() {
	for (MultiChoiceButton &mcb : m_buttons) {
		mcb.hide();
	}
}