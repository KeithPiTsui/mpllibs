// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/do_c.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/apply.hpp>
#include <mpllibs/metamonad/return_.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/type_traits/is_same.hpp>

#include "common.hpp"

BOOST_AUTO_TEST_CASE(test_exception)
{
  using boost::is_same;
  
  using boost::mpl::equal_to;
  using boost::mpl::tag;
  using boost::mpl::not_;
  
  using mpllibs::metamonad::exception;
  using mpllibs::metamonad::exception_tag;
  using mpllibs::metamonad::return_;
  using mpllibs::metamonad::do_c;
  using mpllibs::metamonad::set;
  using mpllibs::metamonad::do_return;
  using mpllibs::metamonad::lambda_c;
  using mpllibs::metamonad::_;
  using mpllibs::metamonad::apply;

  using mpllibs::metamonad::name::x;

  typedef exception<int13> e;

  // test_monadic_no_exception
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      do_c<exception_tag,
        do_return<int13>
      >::type
    >
  ));

  // test_monadic_exception
  BOOST_MPL_ASSERT((
    equal_to<
      exception<int13>,
      do_c<exception_tag, apply<lambda_c<_, e>, int1> >::type
    >
  ));

  // test_exception_propagation
  BOOST_MPL_ASSERT((
    equal_to<
      exception<int13>,
      do_c<exception_tag,
        apply<lambda_c<_, e>, int1>,
        do_return<int13>
      >::type
    >
  ));

  // test_return_value
  BOOST_MPL_ASSERT((is_same<int13, return_<exception_tag, int13>::type>));

  // test_return_with_1_element_do
  BOOST_MPL_ASSERT((
    is_same<
      int11,
      do_c<exception_tag,
        do_return<int11>
      >::type
    >
  ));

  // test_execution_sequence
  BOOST_MPL_ASSERT((
    equal_to<
      int11,
      do_c<exception_tag,
        do_return<int13>,
        do_return<int11>
      >::type
    >
  ));
  
  // test_exception_in_set
  BOOST_MPL_ASSERT((
    equal_to<
      exception<int13>,
      do_c<exception_tag,
        set<x, apply<lambda_c<_, e>, int1> >,
        do_return<int13>
      >::type
    >
  ));

  // test_compare_equal_exceptions
  BOOST_MPL_ASSERT((equal_to<exception<int13>, exception<int13> >));

  // test_compare_not_equal_exceptions
  BOOST_MPL_ASSERT((not_<equal_to<exception<int11>, exception<int13> > >));
}

