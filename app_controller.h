#pragma once

// Include the Mono Framework
#include <iostream>
#include <fstream>
#include <mono.h>
#include "KeyPad.h"

#ifdef SDFS
    #include <SDFileSystem.h>
#endif

// Import the mono and mono::ui namespaces into the context
// to avoid writing long type names, like mono::ui::TextLabel
using namespace mono;
using namespace mono::ui;

// The App main controller object.
// This template app will show a "hello" text in the screen
class AppController : public mono::IApplication {
	KeyPad *m_keyPad;
    std::ofstream m_log;

#ifdef SDFS
    SDFileSystem m_sdfs;
#endif
    
public:

    // The default constructor
    AppController();
    
    virtual ~AppController();

    // Called automaticlly by Mono on device reset
    void monoWakeFromReset();

    // Called automatically by Mono just before it enters sleep mode
    void monoWillGotoSleep();

    // Called automatically by Mono right after after it wakes from sleep
    void monoWakeFromSleep();
    
};