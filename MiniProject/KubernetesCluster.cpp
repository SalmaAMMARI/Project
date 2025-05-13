#include <vector>
#include <memory>
#include "Server.h"
#include "Pod.h"
#include <iostream>
#include "KubernetesCluster.h"
void KubernetesCluster::addNode(std::shared_ptr<Server> node){
    nodes.push_back(node);
}
bool KubernetesCluster::removePod(const std::string& name){
    for (auto it=pods.begin() ; it!=pods.end() ; it++){
        if ((*it)->getName()==name){
            pods.erase(it);
            return true;
        }
    }
    return false;

}
 void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod){
    (*pod).deploy();
    pods.push_back(std::move(pod));


 }
 bool KubernetesCluster::schedulePod(Pod& pod){
    //get the total memory of pod 
    double memory = pod.getMemory();
    double cpu = pod.getCPU();
    for (auto it:nodes){
        if ((*it).can_allocate(cpu , memory)){
            return true;
        }
    }
    return false;

 }
 Pod* KubernetesCluster::getPod(const std::string& name){
    for(auto& it: pods){
        if ((*it).getName()==name){
            return it.get();
        }
        
    }
    return nullptr;
 }
 std::string KubernetesCluster::getMetrics()const{
    std::string metrics= "[KubernetesCluster: ]\n";
    for (auto& it : nodes){
        metrics+= (*it).getMetrics()+"\n";
    }
    for (auto& it:pods){
        metrics+=(*it).getMetrics()+"\n";
    }
    return metrics;

 }
  std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c){
    os<<c.getMetrics();
    return os;
  };