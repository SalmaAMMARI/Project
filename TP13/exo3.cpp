#include<iostream>
#include<vector>
#include<algorithm>
int main(){
    auto ajouter=[](int i)->int{
         return i+5;
    };
    std::vector<int> test {10,12,15,17};
    std::transform(test.begin() , test.end() , test.begin(), ajouter);
    for (auto it:test){
        std::cout<<it<<" ";
    };
    return 0;

}