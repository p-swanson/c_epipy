
#include <pybind11/pybind11.h>

#include "episol.cpp"

namespace py = pybind11;

int call_episol(char * args){
    StringNS::string sl[200];
    int nw = analysis_word_line(args, sl, 200, true);
    char * sz[200];
    for (int i=0; i<nw&&i<=200; i++) sz[i] = sl[i].text;

    return main(nw, sz);
}

PYBIND11_MODULE(call_episol, m, py::mod_gil_not_used()) {
    m.doc() = "EPISOL"; // optional module docstring
    m.def("call_episol", &call_episol, "Python entrypoint for EPISOL",
          py::arg("episol -h"));
}
