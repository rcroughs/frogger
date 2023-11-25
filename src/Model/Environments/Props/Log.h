class Log {
private:
    float size;
    float center;
public:
    Log(float initPosition) : size{15}, center{initPosition} {};
    virtual bool contains(float playerPosition);
    virtual void moveRight();
    virtual void moveLeft();
};
