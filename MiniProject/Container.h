#include "Ressource.h"
#ifndef CONTAINER_H
#define CONTAINER_H
class container:public Resource{
    private:
std::string image;
public:
container(std::string id , std::string image , double cpu , double memory);
void start() override;
void stop() override ;
std::string getMetrics() const override;
friend std::ostream& operator<<(std::ostream& os , const container& c );
double getCPU()const;
std::string getId()const;
double getMemory()const;

};

#endif 