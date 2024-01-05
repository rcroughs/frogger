#ifndef FROGGER_VIEW_H
#define FROGGER_VIEW_H

/*
 * Interface of the view of the game
 */
class View {
public:
  virtual void draw() const = 0;
};

#endif // FROGGER_VIEW_H
