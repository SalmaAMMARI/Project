#ifndef POD_H
#define POD_H
#include "Container.h"
#include <string>
#include <memory>
#include<unordered_map>
#include <vector>
class Pod{
    private:
    std::string name;
    std::vector<std::unique_ptr<container>> containers;
    std::unordered_map<std::string ,std::string > labels;
    public:
    Pod(std::string name, std::unordered_map<std::string, std::string> labels
= {});
void addContainer(std::unique_ptr<container> container);
bool removeContainer(const std::string& id);
void deploy();
std::string getMetrics() const;
friend std::ostream& operator<<(std::ostream& os, const Pod& p);
const std::vector<std::unique_ptr<container>> & getContainers() const;
std::string getId()const;
std::string getName()const;
double getMemory()const;
double getCPU()const;
    

};


#endif