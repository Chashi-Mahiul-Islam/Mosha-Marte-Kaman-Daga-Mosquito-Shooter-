#include "texture.h"

texture smurfTexture;
texture fly2;
texture Bomb;

void textureInit()
{
	smurfTexture.Create("image//canonbash.bmp");
fly2.Create("image//Fly2.bmp");
	Bomb.Create("image//bomb.bmp");
}