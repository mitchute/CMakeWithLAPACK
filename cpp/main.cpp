#include <iostream>
#include <vector>

// LAPACK Vector copy
extern "C" void dcopy_(int *n, double *x, int *incx, double *y, int *incy);

// BLAS double precision dot product
extern "C" double ddot_(int *n, double *x, int *incx, double *y, int *incy);

int main() {
  std::cout << "Hello LAPACK"
            << "\n";

  std::vector<double> v1{1, 2, 3};
  std::vector<double> v2{4, 5, 6};
  double dotRetVal;

  int n = 3;
  int incr = 1;

  dcopy_(&n, v1.data(), &incr, v2.data(), &incr);
  dotRetVal = ddot_(&n, v1.data(), &incr, v2.data(), &incr);

  std::cout << dotRetVal << "\n";

  return 0;
}
