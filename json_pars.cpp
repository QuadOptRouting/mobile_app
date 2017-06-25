#include "json_pars.h"

std::string json::prepare(const std::pair<double, double> coordinates, const std::vector<std::pair<unsigned, unsigned>> list){
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    writer.StartObject();
    writer.Key("Coordinates");std::string prepare(std::pair<double, double> coordinates, std::vector<std::pair<unsigned, unsigned>> list);
        writer.StartObject();
        writer.String("Longitude");
        writer.Double(std::get<0>(coordinates));
        writer.String("Latitude");
        writer.Double(std::get<1>(coordinates));
        writer.EndObject();


        writer.Key("List");
        writer.StartArray();// new array for list grugs
         // new object under key "list"
        for(auto it = list.begin(); it < list.end(); ++it)
        {
            writer.StartObject();
            writer.Key("Id");
            writer.Uint(std::get<0>(*it));
            writer.Key("Count");
            writer.Uint(std::get<1>(*it));
            writer.EndObject();
        }
        writer.EndArray();
//        writer.EndObject(); // end object "list"
    writer.EndObject();
    std::string json_list = buffer.GetString();

    return json_list;
}


double json::prep_time(const std::string json){
    double time = 0;
    rapidjson::Document json_doc;
    json_doc.SetObject();
    if(!json_doc.Parse(json.c_str()).HasParseError()){
       time = json_doc["Time"].GetDouble();
    }
    return time;
}
