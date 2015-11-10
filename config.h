#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include <memory>
namespace configNM{

class config{
   public:

     config(const std::string & filename);
     config(){};

     std::string getConfFileName()const{return _confFilename;};
   private:
      std::string _confFilename;
   protected:

};

class configColumnHeaders:public config{
   private:
   static bool registered;
   configColumnHeaders(){};
   configColumnHeaders(const std::string & filename):config(filename){std::cout << "configColumnHeaders" << std::endl;};


   protected:

   public:
   static std::unique_ptr<config> create(std::string in){
      std::cout << "creating configColumnHeaders" << std::endl;
      std::unique_ptr<configColumnHeaders> MyPtr(new configColumnHeaders(in));
      return std::move(MyPtr);
   };
};

class configColumnsNoHeaders:public config{
   private:
   
   configColumnsNoHeaders(){};
   configColumnsNoHeaders(const std::string & filename):config(filename){std::cout << "configColumnsNoHeaders" << std::endl;};
   static bool registered;
   protected:

   public:

   static std::unique_ptr<config> create(std::string in){
      std::unique_ptr<configColumnsNoHeaders> MyPtr(new configColumnsNoHeaders(in));
      return std::move(MyPtr);
   };

};

class configFixed:public config{
   private:
   configFixed(){};
   configFixed(const std::string & filename):config(filename){std::cout << "configFixed" << std::endl;};
   static bool registered;
   protected:
   static std::unique_ptr<config> create(std::string in){
      std::unique_ptr<configFixed> MyPtr(new configFixed(in));
      return std::move(MyPtr);
   };

   public:
};

class configFactory{
public:
  typedef std::unique_ptr<config> (*configCreateFunction)(std::string);
  std::map<std::string,configCreateFunction> registeredConfigs;

  static configFactory* instance(){
          static configFactory factory;
         return &factory;
      }

  bool registerConfig(const std::string & name,std::unique_ptr<config> (createFunction)(std::string)){
   registeredConfigs.insert(std::make_pair(name,createFunction));
   return true;
  }
  std::unique_ptr<config> createConfig(const std::string& name, std::string filename)
  {
      return registeredConfigs[name](filename);
  }

   
};

}
#endif
