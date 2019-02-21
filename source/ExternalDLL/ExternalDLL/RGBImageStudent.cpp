#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() 
{
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	//TODO: Create a copy from the other object
	for (uint8_t i = 0; i < other.data.size()-1; i++) data.push_back(RGB());
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) 
{
	//TODO: Initialize pixel storage
	for (uint8_t i = 0; i < width*height; i++) data.push_back(RGB());
}

RGBImageStudent::~RGBImageStudent() 
{
	//TODO: delete allocated objects
	data.clear();
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
	data.clear();
	for (uint8_t i = 0; i < width*height; i++) data.push_back(RGB());
	
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	data.clear();
	data = other.data;
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) 
{
	data[x*y] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	/*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
	data[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return data[x*y];
}

RGB RGBImageStudent::getPixel(int i) const {
	return data[i];
}