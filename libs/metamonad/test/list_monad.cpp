// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/assert.hpp>

using boost::mpl::list;

using mpllibs::metamonad::lambda_c;
using namespace mpllibs::metamonad::name;

namespace
{
  typedef lambda_c<t, list<t, t> > twice;
}

BOOST_AUTO_TEST_CASE(test_list_monad)
{
  using mpllibs::metamonad::return_;
  using mpllibs::metamonad::bind;
  using mpllibs::metamonad::list_tag;
  
  using boost::mpl::equal;
  
  // test_return
  BOOST_MPL_ASSERT((equal<return_<list_tag, int13>, list<int13> >));

  // test_bind
  BOOST_MPL_ASSERT((
    equal<
      bind<list_tag, list<int13, int11>, twice>::type,
      list<int13, int13, int11, int11>
    >
  ));
}

