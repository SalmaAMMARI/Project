#ifndef KUBERNETESCLUSTER_H
#define KUBERNETESCLUSTER_H
#include <vector>
#include <memory>
#include "Server.h"
#include "Pod.h"
class KubernetesCluster{
    private:
    std::vector<std::shared_ptr<Server>> nodes;
    std::vector<std::unique_ptr<Pod>> pods;
    public:
    void deployPod(std::unique_ptr<Pod> pod);
    void addNode(std::shared_ptr<Server> node);
    bool removePod(const std::string& name);
    bool schedulePod(Pod& pod);
Pod* getPod(const std::string& name);

std::string getMetrics() const;
friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);
};


#endif 