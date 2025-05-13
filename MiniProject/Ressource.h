#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>


class Resource{
    protected:
    std::string id;
    double cpu ;
    double memory;
    bool active;
    public:
    Resource(std::string id , double cpu , double memory);
    virtual void start()=0;
    virtual void stop()=0;
    virtual std::string getMetrics() const =0;
    virtual  ~Resource()=default;

};


#endif 