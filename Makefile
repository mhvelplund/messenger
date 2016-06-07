# Makefile created by monomake, Fri Jun  3 09:35:12 CEST 2016
# Project: messenger

MONO_PATH=/usr/local/openmono
include $(MONO_PATH)/predefines.mk

TARGET=messenger

include $(MONO_PATH)/mono.mk

ONLY_CPP_FLAGS += -std=c++11

# DO NOT DELETE

KeyPad.o: KeyPad.h IKeyContainer.h MultiChoiceButton.h
MultiChoiceButton.o: MultiChoiceButton.h IKeyContainer.h
app_controller.o: app_controller.h KeyPad.h IKeyContainer.h
app_controller.o: MultiChoiceButton.h
