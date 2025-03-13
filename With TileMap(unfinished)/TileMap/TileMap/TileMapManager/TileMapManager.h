#pragma once
#include "rapidjson/document.h"
#include "../../TextureManager/TextureManager.h"
#include "../TileMap/TileMap.h"

class TileMapManager {
public:
	static TileMapManager* getInstance();
	//void ReadTileMap(std::string, std::vector<TileData*>&);

private:
	TileMapManager() {};
	TileMapManager(TileMapManager const&) {}
	TileMapManager& operator=(TileMapManager const&) {};
	static TileMapManager* sharedInstance;


	//void parseData(rapidjson::Document&, std::vector<TileData*>&);
};