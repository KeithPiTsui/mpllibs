// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/accept_when.h>
#include <mpllibs/parser/one_char.h>

#include "common.h"

#include <mpllibs/util/is_digit.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("accept_when");

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::accept_when<
        mpllibs::parser::one_char,
        mpllibs::util::is_digit
      >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    TestWithText;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::accept_when<
        mpllibs::parser::one_char,
        mpllibs::util::is_digit
      >::apply<str_1983>::type::first,
      char_1
    >
    TestWithNumber;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::accept_when<
        mpllibs::parser::one_char,
        mpllibs::util::is_digit
      >::apply<str_>::type,
      mpllibs::parser::nothing
    >
    TestWithEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestWithText)
MPLLIBS_ADD_TEST(suite, TestWithNumber)
MPLLIBS_ADD_TEST(suite, TestWithEmptyString)

