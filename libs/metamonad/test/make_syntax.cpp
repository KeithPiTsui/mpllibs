// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/make_syntax.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/plus.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/type_traits.hpp>

#include "common.hpp"

BOOST_AUTO_TEST_CASE(test_make_syntax)
{
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::make_syntax;
  using mpllibs::metamonad::returns;

  using boost::mpl::plus;

  using boost::is_same;

  // test_making_a_syntax
  BOOST_MPL_ASSERT((is_same<syntax<int13>, make_syntax<int13>::type>));

  // test_laziness_of_make_syntax
  BOOST_MPL_ASSERT((is_same<syntax<int13>,make_syntax<returns<int13> >::type>));
}


