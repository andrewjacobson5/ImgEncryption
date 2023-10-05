// Copyright Andrew Jacobson 2023

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(testOverloadOut) {
// based on example from
// https://valelab4.ucsf.edu/svn/3rdpartypublic/boost-versions/boost_1_77_0/libs/test/doc/html/boost_test/testing_tools/output_stream_testing.html

  FibLFSR l3("1011011000110110");
  // initilize new obj
  boost::test_tools::output_test_stream out;
  // boost output_test_stream obj
  out << l3;
  // output l3
  BOOST_TEST(!out.is_empty(false));
  // makes sure output is not empty
  BOOST_TEST(out.check_length(17, false));
  // tests output to make sure output is 17 in length, 17 becasue the newline
  BOOST_TEST(out.is_equal("1011011000110110\n"));
  // tests if the output of l3 is equal to what it is supposed to be
}

BOOST_AUTO_TEST_CASE(testStepInstr3) {
// testing the generate function

  int res = 0;
  // result of generate function
  FibLFSR l4("1011011000110110");
  // initialize new obj
  for (int i = 0; i < 7; i++) {
  // for loop to call generate 7 times
    res = l4.generate(5);
    // set res to the return value of the generate function
  }
  BOOST_REQUIRE_EQUAL(res, 28);
  // checks if the result of the for loop is equal to 28
}
