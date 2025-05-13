#include<string>
#include<iostream>
#include "Ressource.h"
#include "Server.h"
Server::Server(std::string id, double cpu, double memory):Resource(id , cpu , memory){};
bool Server::allocate(double cpu , double memory){
    if (available_cpu>=cpu && available_memory>=memory){
        available_cpu-=cpu;
        available_memory-=memory;
        return true ;
    }
    return false;

}
void Server::start(){
    active=true;
}
void Server::stop(){
    active=false;
}
std::string Server::getMetrics() const {
    return "[Server: "+id+" , CPU: "+std::to_string(cpu) +" Memory: " +std::to_string(memory) +" Available: "+std::to_string(available_cpu)+ "CPU ," +std::to_string(available_memory) +" Memory ]";

}
std::ostream& operator<<(std::ostream& os , const Server & s ){
    os<<s.getMetrics();
    return os;

}
bool Server::can_allocate(double cpu , double memory){
    if (available_cpu>=cpu && available_memory>=memory){
        return true;
    }else{
        return false;
        
    }
}