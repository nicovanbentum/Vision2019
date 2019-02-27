#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) 
	: RGBImage(other.getWidth(), other.getHeight()) 
{
	h = other.h;
	w = other.w;
	delete[] data;
	data = new RGB[w * h];
	data = other.data;
}


RGBImageStudent::RGBImageStudent(const int width, const int height)
	: RGBImage(width, height) 
{
	h = height;
	w = width;
	delete[] data;
	data = new RGB[w * h];
}

RGBImageStudent::~RGBImageStudent() 
{
	delete[] data;
	data = nullptr;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	
	h = height;
	w = width;
	delete[] data;
	data = new RGB[width * height];
	
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	
	h = other.h;
	w = other.w;
	delete[] data;
	data = new RGB[w * h];
	data = other.data;

}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) 
{
	data[x + (w*y)] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) 
{
	data[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const 
{
	return data[x + (w*y)];
}

RGB RGBImageStudent::getPixel(int i) const 
{
	return data[i];
}