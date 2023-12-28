#ifndef _FROGGER_LEVEL_SELECTOR_DISPLAY_H_
#define _FROGGER_LEVEL_SELECTOR_DISPLAY_H_

#include <memory>
#include "View.h"
#include "../Components/LevelSelector.h"
#include "../Components/AddMapMenu.h"

class LevelSelectorDisplay : public View {
public:
  LevelSelectorDisplay(std::shared_ptr<LevelSelector> levelSelector);
  void draw() override;

private:
  std::shared_ptr<LevelSelector> _levelSelector;
};

#endif // _FROGGER_LEVEL_SELECTOR_DISPLAY_H_