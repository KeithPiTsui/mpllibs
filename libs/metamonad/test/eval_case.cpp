// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/box.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/var.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"

using mpllibs::metamonad::tmp_value;

namespace
{
  template <class A, class B>
  struct some_template : tmp_value<some_template<A, B> > {};

  template <class A, class B>
  struct some_other_template : tmp_value<some_other_template<A, B> > {};
}

BOOST_AUTO_TEST_CASE(test_eval_case)
{
  using mpllibs::metamonad::eval_case;
  using mpllibs::metamonad::matches;
  using mpllibs::metamonad::matches_c;
  using mpllibs::metamonad::exception;
  using mpllibs::metamonad::no_case_matched;
  using mpllibs::metamonad::var;
  using mpllibs::metamonad::returns;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::box;

  using boost::is_same;

  using boost::mpl::equal_to;

  // test_no_matches
  BOOST_MPL_ASSERT((
    is_same<
      exception<no_case_matched<box<int> > >,
      eval_case< box<int>,
        matches<syntax<box<double> >, syntax<float> >
      >::type
    >
  ));

  // test_match
  BOOST_MPL_ASSERT((
    is_same<
      float,
      eval_case< box<int>,
        matches<syntax<box<int> >, syntax<returns<float> > >
      >::type
    >
  ));

  // test_first_matches
  BOOST_MPL_ASSERT((
    is_same<
      float,
      eval_case< box<int>,
        matches<syntax<box<int> >, syntax<returns<float> > >,
        matches<syntax<box<double> >, syntax<char> >
      >::type
    >
  ));

  // test_second_matches
  BOOST_MPL_ASSERT((
    is_same<
      float,
      eval_case< box<int>,
        matches<syntax<box<double> >, syntax<char> >,
        matches<syntax<box<int> >, syntax<returns<float> > >
      >::type
    >
  ));

  // test_vars_in_pattern
  BOOST_MPL_ASSERT((
    is_same<
      some_other_template<int, double>,
      eval_case< returns<some_template<int, double> >,
        matches<syntax<some_template<x, y> >,
          syntax<returns<some_other_template<x, y> > >
        >
      >::type
    >
  ));

  // test_nested_case
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      eval_case< int11,
        matches<syntax<x>,
          syntax<eval_case<int2, matches_c<y, boost::mpl::plus<x, y> > > >
        >
      >::type
    >
  ));
}


