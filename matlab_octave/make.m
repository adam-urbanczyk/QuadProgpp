% ------------------------------------------------------------
% compilation
% ------------------------------------------------------------

copyfile('config.hh', '../src')
mex -v -I../src/   quadprogpp_interface.cpp  ../src/Array.cc ../src/QuadProg++.cc

%%%EOF
