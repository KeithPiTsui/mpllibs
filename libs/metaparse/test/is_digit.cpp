// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_digit.hpp>

#include "common.hpp"

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_util_is_digit)
{
  using mpllibs::metaparse::util::is_digit;
  
  using boost::mpl::apply_wrap1;
  using boost::mpl::not_;

  // test_digit
  BOOST_MPL_ASSERT((apply_wrap1<is_digit<>, char_7>));
  
  // test_non_digit
  BOOST_MPL_ASSERT((not_<apply_wrap1<is_digit<>, char_a> >));
}


