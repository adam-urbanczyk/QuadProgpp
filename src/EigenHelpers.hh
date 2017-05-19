// Copyright (C) 2017 Alexander Sherikov
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once

namespace QuadProgpp
{

template<typename T>
void print_matrix(const char* name, const QPPP_MATRIX(T)& A, int n = -1, int m = -1)
{
  if (n == -1)
    n = A.rows();
  if (m == -1)
    m = A.cols();

  std::cout << name << ": " << std::endl << " ";
  std::cout << A.block(0, 0, n, m) << std::endl;
}


template<typename T>
void print_vector(const char* name, const QPPP_VECTOR(T)& v, int n = -1)
{
  if (n == -1)
    n = v.rows();

  std::cout << name << ": " << std::endl << " ";
  std::cout << v.head(n) << std::endl;
}


// Utility functions for computing the Cholesky decomposition and solving
// linear systems
template<typename T>
class CholeskyDecomposition
{
    public:
        template<class t_Derived>
        CholeskyDecomposition(Eigen::PlainObjectBase<t_Derived>& A) : lltOfA(A)
        {
        }


        template<class t_Derived>
        void solve(Eigen::PlainObjectBase<t_Derived>& A, QPPP_VECTOR(T)& x, const QPPP_VECTOR(T)& b)
        {
            x = lltOfA.solve(b);
        }


        template<class t_Derived>
        void invert_upper(Eigen::PlainObjectBase<t_Derived>& A, QPPP_MATRIX(T)& J, QPPP_VECTOR(T)& z, QPPP_VECTOR(T)& d)
        {
            J.setIdentity();
            lltOfA.matrixU().solveInPlace( J );
        }

    private:
        Eigen::LLT< Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> > lltOfA;
};

} // namesace QuadProgpp
