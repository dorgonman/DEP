#include "AIEngine.h"
#include "math.h"

typedef struct tagXYZ
{
    float X, Y, Z;
}XYZ;

float Magnitude(XYZ *Point1, XYZ *Point2 )
{
    static XYZ Vector;

    Vector.X = Point2->X - Point1->X;
    Vector.Y = Point2->Y - Point1->Y;
    Vector.Z = Point2->Z - Point1->Z;

    return (float)sqrt( Vector.X * Vector.X + Vector.Y * Vector.Y + Vector.Z * Vector.Z );
}

int DistancePointLine( XYZ *Point, XYZ *LineStart, XYZ *LineEnd, float *Distance ){
    float LineMag;
    float U;
    static XYZ Intersection;
 
    LineMag = Magnitude( LineEnd, LineStart );
 
    U = ( ( ( Point->X - LineStart->X ) * ( LineEnd->X - LineStart->X ) ) +
        ( ( Point->Y - LineStart->Y ) * ( LineEnd->Y - LineStart->Y ) ) +
        ( ( Point->Z - LineStart->Z ) * ( LineEnd->Z - LineStart->Z ) ) ) /
        ( LineMag * LineMag );
 
    if( U < 0.0f || U > 1.0f )
        return 0;   // closest point does not fall within the line segment
 
    Intersection.X = LineStart->X + U * ( LineEnd->X - LineStart->X );
    Intersection.Y = LineStart->Y + U * ( LineEnd->Y - LineStart->Y );
    Intersection.Z = LineStart->Z + U * ( LineEnd->Z - LineStart->Z );
 
    *Distance = Magnitude( Point, &Intersection );
 
    return 1;
}


bool AIEngine::distancePointLine(float pointX, float pointY, 
								 float LineStartX, float LineStartY,
								 float LineEndX, float LineEndY, float *distance){
	static XYZ p1;
	static XYZ p2;
	static XYZ p3;
	p1.X = pointX;
	p1.Y = pointY;
	p1.Z = 0;
	p2.X = LineStartX;
	p2.Y = LineStartY;
	p2.Z = 0;
	p3.X = LineEndX;
	p3.Y = LineEndY;
	p3.Z = 0;

	if(DistancePointLine(&p1, &p2, &p3, distance)){
		return true;//與直線垂直
	}else{
		return false;
	}

}