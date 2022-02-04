#ifndef SEGMENT_HPP
#define SEGMENT_HPP

class Segment{
    public:
    Segment* end;
    Segment(int x,int y,int dir);
    ~Segment(void);  
    int getX();
    int getY();
    int getDir();
    void setX(int x);
    void setY(int y);
    void setDir(int direction);

    private:
    int x;
    int y;
    int dir;

};


#endif