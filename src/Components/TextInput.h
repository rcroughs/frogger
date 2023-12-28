#ifndef _FROGGER_TEXT_INPUT_H_
#define _FROGGER_TEXT_INPUT_H_

#include <FL/Fl_PNG_Image.H>
#include <string>

class TextInput {
public:
  TextInput(int x, int y);
  virtual Fl_PNG_Image *getImage() const;
  virtual void addChar(char c);
  virtual void removeChar();
  virtual std::string getInput();
  virtual void pasteString(std::string str);
  virtual bool isActive();
  virtual void changeActivity();
  virtual int getX() const { return _x; }
  virtual int getY() const { return _y; }
  virtual bool contains(int x, int y);

public:
  Fl_PNG_Image *image;
  std::string input;
  int _x;
  int _y;
  bool _isActive;
};

#endif // _FROGGER_TEXT_INPUT_H_