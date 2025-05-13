#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
class Livre{
    int pages;
    std::string title;
    public:
    Livre(std::string title,int pages ):pages(pages), title(title){

    };
    std::string getTitle(){
        return title;

    };
    int getpages(){
        return pages;
    };
    friend std::ostream& operator<<(std::ostream& os , const Livre& livre){
        os<<livre.title<<" - "<<livre.pages<<" pages."<<std::endl;
        return os;
    };

};
int main(){
    std::vector<Livre> livres{Livre("C++" , 100) , Livre("C++" , 2000) , Livre("html" , 2)};
    //avant de trier
    for (auto it:livres){
        std::cout<<it<<std::endl;

    };
    //trier par titre
    std::sort(livres.begin() , livres.end(),[](Livre& a , Livre& b ){
        if (a.getTitle()==b.getTitle()){
            return a.getpages()>b.getpages();
        }else{
            return a.getTitle()<b.getTitle();
        }
    });
    for (auto it:livres){
        std::cout<<it<<std::endl;

    };

    
}