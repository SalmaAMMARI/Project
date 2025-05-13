#ifndef SERVER_H
#define SERVER_H
#include <string>
#include<iostream>
#include"Ressource.h"

class Server: public Resource{
    private:
    double available_cpu ;
    double available_memory;
    public:
    Server(std::string id, double cpu, double memory);
    bool allocate(double cpu, double memory);

    void start() override;
    void stop() override;
std::string getMetrics() const override;
friend std::ostream& operator<<(std::ostream& os, const Server& s);
bool can_allocate(double cpu , double memory);

};

#endif 