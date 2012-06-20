TBBIntro
========

A pragmatic introduction to the C++ Open Source Library "Intel Threading Building Blocks"


LICENSE
-------

This talk and all affiliated code is published under the creative commons BY licence 3.0. For details, see http://creativecommons.org/licenses/.
All contained material was created by the author or obtained from creative common licensed sources (as indicated). For questions, concerns, criticism and improvements, contact: Peter.Steinbach@tu-dresden.de.

DEPENDENCIES
------------
The talk requires a recent pdflatex installation as well as the beamer styles available.

In order to make the example code compile, the BOOST_LIB and BOOST_INC environment variables (the same for TBB) must point to your distributions custom install directories of boost and intel threading building blocks.
Since the 64-bit version of the mersenne twister algorithm is used, at least boost 1.48 is required.