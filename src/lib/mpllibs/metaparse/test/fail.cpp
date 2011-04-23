// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/fail.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>

#include <mpllibs/metaparse/util/define_data.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::TestSuite;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::fail;
using mpllibs::metaparse::start;

using boost::mpl::apply;

namespace
{
  const TestSuite suite("fail");

  MPLLIBS_METAPARSE_DEFINE_DATA(test_error);

  typedef
    is_error<apply<fail<test_error>, str_hello, start> >
    test_fail_for_non_empty_string;
}

MPLLIBS_ADD_TEST(suite, test_fail_for_non_empty_string)


