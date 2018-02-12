#include <iostream>
#include <string>
#include <unordered_map>

void PrintUnOrderedMap (std::unordered_map<std::string , double>& m) {
    std::cout << "mymap contains:" << std::endl;
    
    for ( auto it = m.begin(); it != m.end(); ++it )
        std::cout << " " << it->first << ":" << it->second << std::endl;
    
}



int main () {
    std::unordered_map<std::string , double> mymap = {
        {"mom" , 5.4} ,
        {"dad" , 6.1} ,
        {"bro" , 5.9} };
    
    PrintUnOrderedMap(mymap);
    
    std::string input;
    std::cout << "what do you want to find ?";
    getline (std::cin , input);
    
    std::unordered_map<std::string , double>::const_iterator got = mymap.find(input);
    // end成员返回指向容器尾元素的下一个位置的迭代器，也就是说end指示的是一个不存在的元素
    std::unordered_map<std::string , double>::const_iterator end = mymap.end();

    if (got == end) {
        std::cout << "not found";
    } else {
        std::cout << end.operator->();
        std::cout << got->first << " is " << got->second;
    }
    
    std::cout << std::endl;
}

