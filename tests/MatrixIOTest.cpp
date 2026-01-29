#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(OpenData)
{
  const int      expectedMatrixSize{3};
  const MatrixXd expectedMatrix = (MatrixXd(3, 3) << 0.680375, 0.59688, -0.329554,
                                   -0.211234, 0.823295, 0.536459,
                                   0.566198, -0.604897, -0.444451)
                                      .finished();

  MatrixXd matrix = matrixIO::openData("../data/m3.csv", expectedMatrixSize);

  BOOST_TEST(matrix.rows() == expectedMatrix.rows());
  BOOST_TEST(matrix.cols() == expectedMatrix.cols());
  BOOST_TEST(matrix(0, 0) == expectedMatrix(0, 0));
  BOOST_TEST(matrix(1, 1) == expectedMatrix(1, 1));
  BOOST_TEST(matrix(2, 2) == expectedMatrix(2, 2));
}

BOOST_AUTO_TEST_SUITE_END()