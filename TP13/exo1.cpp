#include <iostream>
#include<vector>
#include <algorithm>

//additionner fonctuer va ajputer un valeur fixe à chaque nmbre argument
class additionner{
    private:
    int valeur;
    public:
    additionner(int valeur) : valeur(valeur){};
    void operator()(int x){
     x+=valeur;

    }
};
int main(){
    std::vector<int> test {9,10,11,12,13};
    additionner somme(2);
    std::for_each(test.begin(), test.end() , somme);
   
 
    return 0;
}