#include <boost/python.hpp>

#include "javarandom.h"

BOOST_PYTHON_MODULE(javarandom)
{
  using namespace boost::python;
  class_<JavaRandom>("JavaRandom", init<int64_t>())
    .def(init<>())
    .def("setSeed", &JavaRandom::setSeed)
    .def("next", &JavaRandom::next)
    .def("nextInt", (int32_t (JavaRandom::*)())&JavaRandom::nextInt)
    .def("nextInt", (int32_t (JavaRandom::*)( int32_t ))&JavaRandom::nextInt)
  ;
}

// vim: ts=2 sw=2 et:
