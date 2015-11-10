#include "config.h"
using namespace configNM;
int main(void){
   config myConfig("columnHeaders.json");
//   auto myConfigPtr = configFactory::create("columnHeaders.json");
   auto myPtr = configFactory::instance()->createConfig("column_headers","parameter");
   auto myPtr2 = configFactory::instance()->createConfig("columns_no_headers","parameter");
   auto myPtr3 = configFactory::instance()->createConfig("fixed","parameter");
   return 0;
}
