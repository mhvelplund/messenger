#include "app_controller.h"

// Contructor
// You should init data here, since I/O is not setup yet.
AppController::AppController() {
	m_keyPad = new KeyPad();
}

AppController::~AppController() {
    delete m_keyPad;
}

void AppController::monoWakeFromReset()
{
    m_keyPad->show();
}

void AppController::monoWillGotoSleep()
{
    // Blank
}

void AppController::monoWakeFromSleep()
{
    // Due to a software bug in the wake-up routines, we need to reset here!
    // If not, Mono will go into an infinite loop!
    mono::IApplicationContext::SoftwareResetToApplication();
    // We never reach this point in the code, CPU has reset!

    // scheduleRepaint for all components
    m_keyPad->scheduleRepaint();
}