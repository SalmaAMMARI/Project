#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

void filtrer(std::vector<int> vecteur , std::function<bool(int)> fct){
    for (auto it:vecteur){
        if (fct(it)){
            std::cout<<it<<" ";
        }
    }
};
 int main(){
    auto filtre = [](int i)-> bool{
        if (i%2==0){
            return true;
        }else{
            return false;
        }
    };
    std::vector<int> test{1,2,3,4,5};
    filtrer(test,filtre);
    return 0;

 }