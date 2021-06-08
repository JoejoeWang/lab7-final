#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <iostream>
#include <exception>
#include "color.h"
#include "vec2.h"
#include "shape.h"
using namespace std;

using std::invalid_argument;
using std::overflow_error;

/* simple data representation of an implicit ellipse */
class ellipse : public shape {
  public:
	ellipse(double cX, double cY, double r1, double r2, color C) : shape{C, 0}, 
		center(cX, cY), radii(r1, r2) {}
	ellipse(vec2 inC, double r1, double r2, double d, color C) : shape{C, d},
		 center(inC), radii(r1, r2) {}
	ellipse(vec2 inC, vec2 inR, double d, color C) : shape{C, d},
		 center(inC), radii(inR) {}
	ellipse(double cX, double cY, double r1, double r2, double d, color C) : shape{C, d},
		center(cX, cY), radii(r1, r2) {}

	bool eval(double x, double y) override {
		if( ((center.x()-x)*(center.x()-x))/(radii.x()*radii.x()) + 
				((center.y()-y)*(center.y()-y))/(radii.y()*radii.y()) - 1.0f < 0) {
			return true;
		}
		return false;
	}
	//note lifted getters

	// double division()
	// {
	// 	if(radii.x==0||radii.y==0)
	// 	{
	// 		cout << 
	// 	}
	// }
	void validate()  override
	{
		try
		{
			if(center.x()<0||center.y()<0)
			{
				this->setColor(color(0));
				throw invalid_argument("ellipse center less zero");
			}
		}
		catch (const invalid_argument& e)
		{
			cout << e.what() << "\n"; 
		}

		try
		{
			if(radii.x()<epsilon||radii.y()<epsilon)
			{
				if(radii.x()<epsilon)
				{
					radii.setX(2);
				}
				if(radii.y()<epsilon)
				{
					radii.setY(2);
				}
				this->setColor(color(255,0,0));
				throw overflow_error("ellipse divide zero");
			}
		}
		catch (const overflow_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	double getMaxR() {return fmax(radii.x(), radii.y());}
	vec2 getCenter() const { return center; }

	void setCenter(vec2 inCenter) { center = inCenter; }

	friend std::ostream& operator<<(std::ostream &out, const shape &theEllipse);

  private:
	vec2 center; //center point of ellipse
	vec2 radii; //radii of the ellipse
	//note lifted data
};


#endif
