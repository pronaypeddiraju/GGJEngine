#include "Image.hpp"
#include "Engine/Renderer/Rgba.hpp"

#pragma warning( disable: 4100) //Unreferenced formal parameter
#define STB_IMAGE_IMPLEMENTATION
#include "ThirdParty/stb/stb_image.h"

Image::Image( const char* imageFilePath )
{
	int imageTexelSizeX = 0; // Filled in for us to indicate image width
	int imageTexelSizeY = 0; // Filled in for us to indicate image height
	int numComponents = 0; // Filled in for us to indicate how many color components the image had (e.g. 3=RGB=24bit, 4=RGBA=32bit)
	int numComponentsRequested = 0; // don't care; we support 3 (24-bit RGB) or 4 (32-bit RGBA)

	stbi_set_flip_vertically_on_load( 1 ); // We prefer uvTexCoords has origin (0,0) at BOTTOM LEFT
	unsigned char* imageData = stbi_load( imageFilePath, &imageTexelSizeX, &imageTexelSizeY, &numComponents, numComponentsRequested );

	//To-do: For loop through each of the imageData[] and get the RGB data from them
	m_dimensions.x = imageTexelSizeX;
	m_dimensions.y = imageTexelSizeY;

	int numTexels = imageTexelSizeX * imageTexelSizeY;	
	m_texelRepository.resize(numTexels);

	if(numComponents == 3)
	{
		//we have RGB data
		for(int texelIndex = 0; texelIndex < numTexels; texelIndex++)
		{
			int redByteIndex = texelIndex * numComponents;
			int greenByteIndex = redByteIndex + 1;
			int blueByteIndex = redByteIndex + 2;

			unsigned char redByte = imageData[redByteIndex];
			unsigned char greenByte = imageData[greenByteIndex];
			unsigned char blueByte = imageData[blueByteIndex];

			m_texelRepository[texelIndex].SetFromBytes(redByte, greenByte, blueByte);
		}
	}
	else
	{
		//WE have RGBA data
		for(int texelIndex = 0; texelIndex < numTexels; texelIndex++)
		{
			int redByteIndex = texelIndex * numComponents;
			int greenByteIndex = redByteIndex + 1;
			int blueByteIndex = redByteIndex + 2;
			int alphaByteIndex = redByteIndex + 3;

			unsigned char redByte = imageData[redByteIndex];
			unsigned char greenByte = imageData[greenByteIndex];
			unsigned char blueByte = imageData[blueByteIndex];
			unsigned char alphaByte = imageData[alphaByteIndex];

			m_texelRepository[texelIndex].SetFromBytes(redByte, greenByte, blueByte, alphaByte);
		}
	}

	stbi_image_free(imageData);
}

const Rgba& Image::GetTexelColor( const IntVec2& texelCoordinates ) const
{
	//Get index from the coordinates
	int texelIndex = texelCoordinates.x + texelCoordinates.y * m_dimensions.x;
	return m_texelRepository[texelIndex];	
}

const Rgba& Image::GetTexelColor(int xCoord, int yCoord) const
{
	int texelIndex = xCoord + yCoord * m_dimensions.x;
	return m_texelRepository[texelIndex];	
}

const IntVec2& Image::GetImageDimensions() const
{
	return m_dimensions;
}

const std::string& Image::GetImageFilePath()
{
	return m_imageFilePath;
}

void Image::SetTexelColor( int xCoord, int yCoord, const Rgba& setColor )
{
	int texelIndex = xCoord + yCoord * m_dimensions.x;
	m_texelRepository[texelIndex] = setColor;
}

void Image::SetTexelColor( const IntVec2& texelCoordinates, const Rgba& setColor )
{
	int texelIndex = texelCoordinates.x + texelCoordinates.y * m_dimensions.x;
	m_texelRepository[texelIndex] = setColor;
}

