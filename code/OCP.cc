//--shape.hh---------------------
enum ShapeType {circle, square};

struct Shape
{
   ShapeType itsType;
};

//--circle.hh---------------------
struct Circle
{
   ShapeType itsType;
   double itsRadius;
   Point itsCenter;
};

void DrawCircle(Circle*);

//--square.hh---------------------
struct Square
{
   ShapeType itsType;
   double itsSide;
   Point itsTopLeft;
};

void DrawSquare(Square*);


//--DrawAllShapes.cc---------------------
void DrawAllShapes(Shape* list[], int n)
{
   int i;
   for (i=0; i<n; i++)
   {
     Shape* s = list[i];
     switch (s->itsType)
     {
     case square:
       DrawSquare((struct Square*)s);
     break;
     case circle:
       DrawCircle((struct Circle*)s);
     break;
     }
   }
}
