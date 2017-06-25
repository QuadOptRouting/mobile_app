#ifndef JSON_PARS_H
#define JSON_PARS_H

#include <iostream>
#include <string>
#include <vector>
#include <utility> // std::pair
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

namespace json {
enum { max_length = 1024 };

std::string prepare(const std::pair<double, double> coordinates, const std::vector<std::pair<unsigned, unsigned>> list);

double prep_time(const std::string jsosn);
}

#endif // JSON_PARS_H
