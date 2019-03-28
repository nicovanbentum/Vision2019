#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include <cmath>


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const
{
	auto intensity_img = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
	
	for (unsigned int i = 0; i < image.getHeight() * image.getWidth(); i++)
	{
		auto pixel = image.getPixel(i);
		Intensity i_pixel = sqrt( (pow(pixel.r, 2) * .241) 
									+ (pow(pixel.g, 2) * .691) 
										+ (pow(pixel.b, 2) * .068) );

		intensity_img->setPixel(i, i_pixel);
	}
	return intensity_img;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}