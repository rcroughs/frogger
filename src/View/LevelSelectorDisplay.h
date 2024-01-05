#ifndef _FROGGER_LEVEL_SELECTOR_DISPLAY_H_
#define _FROGGER_LEVEL_SELECTOR_DISPLAY_H_

#include "../Components/LevelSelector.h"
#include "View.h"
#include <memory>

class LevelSelectorDisplay : public View {
public:
  LevelSelectorDisplay(std::shared_ptr<LevelSelector> levelSelector);
  void draw() const override;

private:
  std::shared_ptr<LevelSelector> _levelSelector;
};

#endif // _FROGGER_LEVEL_SELECTOR_DISPLAY_H_