#pragma once

class IKeyContainer {
public:
    virtual void keyPressed(int8_t id) = 0;
    virtual void emit(char emit) = 0;
};