#include "config.h"
using namespace configNM;

config::config(const std::string & filename){
   _confFilename=filename;
}

bool configColumnHeaders::registered = configFactory::instance()->registerConfig("column_headers", configColumnHeaders::create);
bool configColumnsNoHeaders::registered = configFactory::instance()->registerConfig("columns_no_headers", configColumnsNoHeaders::create);
bool configFixed::registered = configFactory::instance()->registerConfig("fixed", configFixed::create);

