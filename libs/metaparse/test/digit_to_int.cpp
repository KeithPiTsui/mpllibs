// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/digit_to_int.hpp>

#include "common.hpp"

#include <mpllibs/metatest/has_type.hpp>

#include <mpllibs/metamonad/do_try.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

namespace
{
  struct x;
}

BOOST_AUTO_TEST_CASE(test_digit_to_int)
{
  using mpllibs::metatest::has_type;
  using mpllibs::metatest::meta_require;
  
  using mpllibs::metaparse::util::digit_to_int;
  using mpllibs::metaparse::error_tag;
  
  using mpllibs::metamonad::do_try;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap1;

  meta_require<has_type<digit_to_int> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal_to<apply_wrap1<digit_to_int, char_0>::type, int0>
  >(MPLLIBS_HERE, "test0");

  meta_require<
    equal_to<apply_wrap1<digit_to_int, char_9>::type, int9>
  >(MPLLIBS_HERE, "test9");
  
  meta_require<
    equal_to<
      do_try<
        apply_wrap1<digit_to_int, char_x>
      >
      ::catch_<error_tag, x>::apply<int13>
      ::type,
      int13
    >
  >(MPLLIBS_HERE, "test_error");
}

