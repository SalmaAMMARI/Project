#ifndef CLOUD_UTIL
#define CLOUD_UTIL
#include "KubernetesCluster.h"
#include<iostream>
void display(const KubernetesCluster& cluster){
    //use the overloaded operator <<
    std::cout<<cluster<<std::endl;
};

void deployPods(KubernetesCluster &cluster, std::vector<std::unique_ptr<Pod>> &pods) {
    for (auto &pod : pods) {
        std::cout << "-> Déploiement du Pod " << *pod;
        if (cluster.schedulePod(*pod)) {
            cluster.deployPod(std::move(pod));
        } else {
            std::cout << "Échec du déploiement du pod [Pod: " << pod->getName() << "]\n";
            std::cout << pod->getMetrics();
            std::cout << ": ressources insuffisantes.\n";
        }

    }
};

#endif
