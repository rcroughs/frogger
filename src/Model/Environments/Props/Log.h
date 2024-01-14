#include "../../Game.h"
#include "../../Position.h"
#include "FL/Fl.H"
#include "Prop.h"

class Log : public Prop {
public:
  Log(float size, float initPosition, float speed);
  ~Log() = default;
  
  // Getters
  [[nodiscard]] virtual float getPosition() const override;
  [[nodiscard]] virtual float getRightCorner() const override;
  [[nodiscard]] virtual Fl_Color getColor() const override;
  [[nodiscard]] virtual float getSize() const override;
  [[nodiscard]] virtual bool contains(float playerPosition) const override;
  [[nodiscard]] virtual bool hasImage() const override;
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const override;
  [[nodiscard]] virtual bool isVisible() const override;

  // Move a prop
  virtual void move() override;
  // Handle game
  virtual void handleGame(Game *currentGame) override;
  // Update prop position
  virtual void update() override;

private:
  float _size;
  float _leftCorner;
  float _speed;
  Fl_Color _color;
};
