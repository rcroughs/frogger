#ifndef _FROGGER_TEXT_INPUT_H_
#define _FROGGER_TEXT_INPUT_H_

#include <FL/Fl_PNG_Image.H>
#include <string>

class TextInput {
public:
  TextInput(int x, int y, std::string label);
  virtual Fl_PNG_Image *getImage() const;
  virtual void addChar(char c);
  virtual void removeChar();
  virtual std::string getInput();
  virtual void pasteString(std::string str);
  virtual bool isActive();
  virtual void changeActivity();
  virtual void resetActivity();
  virtual int getX() const { return _x; }
  virtual int getY() const { return _y; }
  virtual bool contains(int x, int y);
  virtual bool isEmpty();
  virtual std::string getLabel();


public:
  Fl_PNG_Image *image;
  std::string input;
  std::string label;
  int _x;
  int _y;
  bool _isActive;
};

#endif // _FROGGER_TEXT_INPUT_H_