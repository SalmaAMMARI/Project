#include "Pod.h"
#include <vector>
#include <iostream>
#include<memory>
Pod::Pod(std::string name, std::unordered_map<std::string, std::string> labels):name(name) , labels(labels){};
void Pod::addContainer(std::unique_ptr<container> container){
    containers.push_back(std::move(container));
};
bool Pod::removeContainer(const std::string& id){
    for (auto it=containers.begin() ;it!=containers.end() ; it++){
        if ((*it)->getId()==id){
            containers.erase(it);
            return true;
        }
        
    }
    return false;

}
void Pod::deploy(){
    for (auto& it : containers){
        it->start();
    }
}
std::string Pod::getMetrics()const {
    std::string metrics= "[Pod:"+ name +"]\n";
    for (auto& it :containers){
        metrics+=it->getMetrics()+"\n"
;    };
return metrics;


}
std::ostream& operator<<(std::ostream& os , const Pod& p ){
    os <<p.getMetrics()<<std::endl;
    return os ;
}

const std::vector<std::unique_ptr<container>>& Pod::getContainers()const {
    //return the reference of the vector not a copy of it 
    return containers;
}

std::string Pod::getName()const{
    return name;
};

double Pod::getMemory()const{
    int total=0;
    for (auto it =containers.begin(); it!=containers.end();it++){
        total+=(*it)->getMemory();


    };
    return total;
};
double Pod::getCPU()const{
    int total=0;
    for (auto it =containers.begin(); it!=containers.end();it++){
        total+=(*it)->getCPU();


    };
    return total;
};