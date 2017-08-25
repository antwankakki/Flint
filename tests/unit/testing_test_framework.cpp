//
// Created by Antwan Gaggi on 8/7/17.
//
#include <flint/application/application.h>

#define BOOST_TEST_MODULE Application
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/dataset.hpp>
#include <boost/test/data/test_case.hpp>

/**
 * @brief This test case clamps all floats to a negative range. That is, all
 * floats passed will be mapped to the range below:
 *              [0, numeric_limits<float>::max()]
 */
BOOST_AUTO_TEST_CASE(applicationStartTest)
{
    flint::application::Application app;
    BOOST_CHECK_EQUAL(app.start() == true, true);
}