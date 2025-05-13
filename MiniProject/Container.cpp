#include "Container.h"
#include <iostream>
#include <string>
container::container(std::string id , std::string image , double cpu , double memory):Resource(id, cpu,memory), image(image){}
void container::start(){
    active=true;
}
void container::stop(){
    active=false;

}
std::string container::getMetrics()const{
    return "[Container: "+id+" CPU: "+std::to_string(cpu) +",Memory: "+ std::to_string(memory)+" Image:"+image + " ]";
}
std::ostream& operator<<(std::ostream& os , const container& c ){

    os<<c.getMetrics()<<std::endl;
    return os;
}
double container::getCPU()const{
    return cpu;
}
std::string container::getId()const{
    return id;
}
double container::getMemory()const{
    return memory;
}