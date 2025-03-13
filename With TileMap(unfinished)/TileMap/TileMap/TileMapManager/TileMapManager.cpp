#include "TileMapManager.h"
#include <cassert>
//#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
//#include "../Sprite/Sprite.h"

TileMapManager* TileMapManager::sharedInstance = nullptr;

TileMapManager* TileMapManager::getInstance() {
    if (sharedInstance == nullptr) {
        sharedInstance = new TileMapManager();
    }

    return sharedInstance;
}


//void TileMapManager::ReadTileMap(std::string fileName, std::vector<TileData*>& spriteList) {
//    FILE* file;
//    fopen_s(&file, fileName.c_str(), "rb");
//    assert(file != nullptr);
//
//
//    char readBuffer[65536];
//    rapidjson::FileReadStream is(file, readBuffer, sizeof(readBuffer));
//    rapidjson::Document doc;
//
//    doc.ParseStream(is);
//
//    fclose(file);
//
//    parseData(doc, spriteList);
//
//}

//void TileMapManager::parseData(rapidjson::Document& doc, std::vector<TileData*>& tileList) {
//    rapidjson::Value::MemberIterator frames = doc.FindMember("frames");
//
//    //rapidjson::GenericObject<true, rapidjson::Value> test = frames->value.GetObject();
//
//    for (rapidjson::GenericMember<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<>>& object : frames->value.GetObject()) {
//
//        if (!object.value.IsObject()) {
//            continue;
//        }
//
//        std::string name = object.name.GetString();
//        int start = name.find("-"), end = name.find("_");
//        if (start != std::string::npos && end != std::string::npos) {
//            name = name.substr(start + 1, end - start - 1);
//        }
//
//        std::vector<int> frameTemp;
//        frameTemp.reserve(4);
//        if (object.value["frame"].IsObject()) {
//            const rapidjson::Value& frame = object.value["frame"];
//            frameTemp.push_back(frame["x"].GetInt());
//            frameTemp.push_back(frame["y"].GetInt());
//            frameTemp.push_back(frame["w"].GetInt());
//            frameTemp.push_back(frame["h"].GetInt());
//        }
//
//        bool rotated = object.value["rotated"].GetBool();
//        bool trimmed = object.value["trimmed"].GetBool();
//
//        std::vector<int> spriteSourceSizeTemp;
//        spriteSourceSizeTemp.reserve(4);
//        if (object.value["spriteSourceSize"].IsObject()) {
//            const rapidjson::Value& frame = object.value["spriteSourceSize"];
//            spriteSourceSizeTemp.push_back(frame["x"].GetInt());
//            spriteSourceSizeTemp.push_back(frame["y"].GetInt());
//            spriteSourceSizeTemp.push_back(frame["w"].GetInt());
//            spriteSourceSizeTemp.push_back(frame["h"].GetInt());
//        }
//
//        std::vector<int> sourceSizeTemp;
//        sourceSizeTemp.reserve(2);
//        if (object.value["sourceSize"].IsObject()) {
//            const rapidjson::Value& frame = object.value["sourceSize"];
//            sourceSizeTemp.push_back(frame["w"].GetInt());
//            sourceSizeTemp.push_back(frame["h"].GetInt());
//        }
//
//        TileData* tileData = new TileData(name, &frameTemp, rotated, trimmed, &spriteSourceSizeTemp, &sourceSizeTemp);
//        tileList.push_back(tileData);
//    }
//}
