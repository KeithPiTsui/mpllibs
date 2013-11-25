// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/empty.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_empty)
{
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::empty;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;
 
  typedef empty<int13> empty13;

  // test_accept_empty
  BOOST_MPL_ASSERT((
    equal_to<get_result<apply_wrap2<empty13, str_, start> >::type, int13>
  ));

  // test_reject_non_empty
  BOOST_MPL_ASSERT((is_error<apply_wrap2<empty13, str_a, start> >));
}

