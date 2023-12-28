#ifndef _FROGGER_INT_INPUT_H_
#define _FROGGER_INT_INPUT_H_

#include "TextInput.h"

class IntInput : public TextInput {
public:
    IntInput(int x, int y);
    void addChar(char c) override;
};


#endif // _FROGGER_INT_INPUT_H_