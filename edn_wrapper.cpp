//#include <iostream>
#include <string>
#include "edn.hpp"
#include <boost/python.hpp>

using namespace std;

namespace wrapper
{
    // EdnNode edn_read(string edn)
    string read(string edn)
    {
        edn::EdnNode foo = edn::read(edn);
        //std::cout << edn::pprint(foo);
        return pprint(foo);
    }


    // string ppprint(EdnNode, int indent=1)

    // EdnNode class


    BOOST_PYTHON_MODULE(edn_wrapper)
    {
        using namespace boost::python;
        def("read", read);
    }
}
