/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <memory>

class A{ public: virtual ~A()=default;};
class Ab:public A{};
class Ac:public A{};
int main()
{
    	std::vector<std::unique_ptr<A>> list;
	list.push_back(std::make_unique<Ab>());
	list.push_back(std::make_unique<Ac>());

	for (const auto& item : list) {
	    if (dynamic_cast<Ab*>(item.get()) != nullptr) {
		std::cout << "This is Ab\n";
	    } else if (dynamic_cast<Ac*>(item.get()) != nullptr) {
		std::cout << "This is Ac\n";
	    } else {
		std::cout << "Unknown derived type\n";
	    }
	}


    return 0;
}
