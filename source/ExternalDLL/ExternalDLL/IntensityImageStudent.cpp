#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) 
{
	//Create a copy from the other object
	h = other.h;
	w = other.w;
	delete[] data;
	data = new Intensity[w * h];
	data = other.data;
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) 
{
	//Initialize pixel storage
	h = height;
	w = width;
	delete[] data;
	data = new Intensity[w * h];
}

IntensityImageStudent::~IntensityImageStudent() 
{
	//delete allocated objects
	delete[] data;
	data = nullptr;
}

void IntensityImageStudent::set(const int width, const int height) 
{
	IntensityImage::set(width, height);
	//resize or create a new pixel storage
	h = height;
	w = width;
	delete[] data;
	data = new Intensity[width * height];
}


void IntensityImageStudent::set(const IntensityImageStudent &other) 
{
	IntensityImage::set(other.getWidth(), other.getHeight());
	//resize or create a new pixel storage and copy the object
	h = other.h;
	w = other.w;
	delete[] data;
	data = new Intensity[w * h];
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) 
{
	//grab x + (w*y) to grab the correct element from flat data layout
	*(data + (x + (w*y))) = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) 
{
	/* set pixel i in "Row-Major Order"*/
	*(data + i) = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const 
{
	//grab x + (w*y) to grab the correct element from flat data layout
	return *(data + (x + (w*y)));
}

Intensity IntensityImageStudent::getPixel(int i) const 
{
	return *(data + i);
}