//--Rectangle.hh----------------------------------------
enum GeoType { Rectangle, Square };

class Rectangle
{
  public:
    virtual void SetWidth(double w)  {itsWidth=w;}
    virtual void SetHeight(double h) {itsHeight=h;}
    double       GetHeight() const   {return itsHeight;}
    double       GetWidth() const    {return itsWidth;}
    GeoType itsType;
  private:
    double itsHeight;
    double itsWidth;

};

//--Square.hh----------------------------------------
class Square : public Rectangle
{
  public:
  virtual void SetWidth(double w);
  virtual void SetHeight(double h);
};

void Square::SetWidth(double w)
{
  Rectangle::SetWidth(w);
  Rectangle::SetHeight(w);
}

void Square::SetHeight(double h)
{
  Rectangle::SetHeight(h);
  Rectangle::SetWidth(h);
}

