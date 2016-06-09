#include <iostream>
#include "app_controller.h"

#ifdef SDFS
	AppController::AppController() :  m_sdfs(SD_SPI_MOSI, SD_SPI_MISO, SD_SPI_CLK, SD_SPI_CS, "sd") {
		m_keyPad = new KeyPad();
	}
#else
	AppController::AppController() {
		m_keyPad = new KeyPad();
	}
#endif

AppController::~AppController() {
    delete m_keyPad;
}

void AppController::monoWakeFromReset()
{
    m_keyPad->show();
	m_log.open("/sd/app.log");
	m_log << "monoWakeFromReset()" << std::endl;
}

void AppController::monoWillGotoSleep()
{
	m_log << "monoWillGotoSleep()" << std::endl;
	m_log.close();
}

void AppController::monoWakeFromSleep()
{
    mono::IApplicationContext::SoftwareResetToApplication();
    monoWakeFromReset();
}