//#include <iostream>
#include <string>
#include "edn.hpp"
#include <boost/python.hpp>

using namespace std;
using edn::EdnNode;

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


    BOOST_PYTHON_MODULE(edn_py)
    {
        using namespace boost::python;

        enum_<edn::NodeType>("NodeType")
            .value("EdnNil", edn::EdnNil)
            .value("EdnSymbol", edn::EdnSymbol)
            .value("EdnKeyword", edn::EdnKeyword)
            .value("EdnBool", edn::EdnBool)
            .value("EdnInt", edn::EdnInt)
            .value("EdnFloat", edn::EdnFloat)
            .value("EdnString", edn::EdnString)
            .value("EdnChar", edn::EdnChar)
            .value("EdnList", edn::EdnList)
            .value("EdnVector", edn::EdnVector)
            .value("EdnMap", edn::EdnMap)
            .value("EdnSet", edn::EdnSet)
            .value("EdnDiscard", edn::EdnDiscard)
            .value("EdnTagged", edn::EdnTagged)
        ;

        /*class_<edn::EdnNode>("EdnNode")
            .add_property("type", edn::&EdnNode::type)
        ;*/
        def("read", read);
    }
}
