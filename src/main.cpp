#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <Eigen/Dense>
#include <satoa/satoa.h>

namespace py = pybind11;
using namespace pybind11::literals;

PYBIND11_MODULE(_core, m) {
    m.doc() = R"pbdoc(
        Wrappers for C++ core algorithms for satoa.
        -----------------------

        .. currentmodule:: _core

        .. autosummary::
           :toctree: _generate

           foo
    )pbdoc";

    m.def(
        "foo",
        &satoa::foo,
        R"pbdoc(
            Dummy function.
        )pbdoc",
        "x"_a,
        "k"_a
    );
};

