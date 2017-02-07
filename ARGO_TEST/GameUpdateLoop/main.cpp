#include <iostream>
#include <Windows.h>
#include "GameTime.h"
#include "rapidjson\document.h"
#include "rapidjson\filereadstream.h"
#include <string>
#include <vector>
using namespace std;

const float TRIGGER = 0.2f;
using namespace rapidjson;
int main(void)
{
	char* filename = "media/json/test.json";
	FILE* fp = fopen(filename, "rb"); // non-Windows use "r"
	Document d;
	if (fp != NULL)
	{
		char readBuffer[65536];
		FileReadStream is(fp, readBuffer, sizeof(readBuffer));		
		d.ParseStream(is);
	}
	else
	{
		std::cout << "ERROR LOADING : " << filename << std::endl;
		system("PAUSE");
		exit(0);
	}
	fclose(fp);

	const Value& layerArray = d["layers"];
	const Value& layer = layerArray[0u];
	const Value& dataArray = layer["data"];

	int layerWidth = layer["width"].GetInt();
	int layerHeight = layer["height"].GetInt();

	const Value& tilesetsArray = d["tilesets"];
	const Value& tilesets = tilesetsArray[0u];
	const char* textureName = tilesets["name"].GetString();
	int tileWidth = tilesets["tilewidth"].GetInt();
	int tileHeight = tilesets["tileheight"].GetInt();

	for (int y = 0; y < layerHeight; y++)
	{
		for (int x = 0; x < layerWidth; x++)
		{
			
		}
	}

	float last = 0.0f;
	float current = 0.0f;
	GameTime* gameTime = GameTime::getInstance();
	last = gameTime->running();
	//Main Game Loop
	while(true)
	{
		current = gameTime->running();
		if((current - last) > TRIGGER)
		{
			std::cout << "updating...." << std::endl;
			last = current;
		}
		Sleep(500);//main process sleeps
	}
	system("PAUSE");
}