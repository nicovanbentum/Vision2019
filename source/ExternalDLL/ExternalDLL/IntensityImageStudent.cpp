#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) 
{
	h = other.h;
	w = other.w;
	delete[] data;
	data = new Intensity[w * h];
	data = other.data;
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) 
{
	h = height;
	w = width;
	delete[] data;
	data = new Intensity[w * h];
}

IntensityImageStudent::~IntensityImageStudent() 
{
	delete[] data;
	data = nullptr;
}

void IntensityImageStudent::set(const int width, const int height) 
{
	IntensityImage::set(width, height);
	h = height;
	w = width;
	delete[] data;
	data = new Intensity[width * height];
}


void IntensityImageStudent::set(const IntensityImageStudent &other) 
{
	IntensityImage::set(other.getWidth(), other.getHeight());
	h = other.h;
	w = other.w;
	delete[] data;
	data = new Intensity[w * h];
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) 
{
	data[x + (w*y)] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) 
{
	data[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const 
{
	return data[x + (w*y)];
}

Intensity IntensityImageStudent::getPixel(int i) const 
{
	return data[i];
}